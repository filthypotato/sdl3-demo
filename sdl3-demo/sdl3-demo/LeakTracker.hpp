// LeakTracker.hpp
#pragma once
#include <cstdlib>
#include <new>
#include <iostream>
#include <unordered_map>
#include <mutex>
#include <string>

struct LeakTracker {
    static std::unordered_map<void*, std::string>& allocations() {
        static std::unordered_map<void*, std::string> a;
        return a;
    }

    static std::mutex& lock() {
        static std::mutex m;
        return m;
    }

    static void add(void* p, const char* file, int line) {
        std::lock_guard<std::mutex> g(lock());
        allocations()[p] = std::string(file) + ":" + std::to_string(line);
    }

    static void remove(void* p) {
        std::lock_guard<std::mutex> g(lock());
        allocations().erase(p);
    }

    static void report() {
        std::lock_guard<std::mutex> g(lock());
        if (allocations().empty()) {
            std::cout << "[LeakTracker] No leaks 🎉\n";
            return;
        }
        std::cout << "[LeakTracker] Leaks detected:\n";
        for (auto& [ptr, where] : allocations()) {
            std::cout << "  " << ptr << " allocated at " << where << "\n";
        }
    }
};

// runs at program exit
struct LeakReporter {
    ~LeakReporter() {
        LeakTracker::report();
    }
};
static LeakReporter g_leakReporter;

// override global new/delete
inline void* operator new(std::size_t sz) {
    void* p = std::malloc(sz);
    if (!p) throw std::bad_alloc{};
    LeakTracker::add(p, "unknown", 0);
    return p;
}

inline void* operator new(std::size_t sz, const char* file, int line) {
    void* p = std::malloc(sz);
    if (!p) throw std::bad_alloc{};
    LeakTracker::add(p, file, line);
    return p;
}

inline void operator delete(void* p) noexcept {
    if (p) {
        LeakTracker::remove(p);
        std::free(p);
    }
}

// so you can do NEW Foo() and see file/line
#define NEW new(__FILE__, __LINE__)
