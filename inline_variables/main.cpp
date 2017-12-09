#include <string>
#include <iostream>
#include <vector>

struct A {
    static constexpr int x = 123;
};

struct B {
    static inline constexpr int x = 123;
};

// First method
struct C {
    static inline std::string const msg = "Hello world"; // NOLINT
};

// Second method
struct D {
    static std::string const msg;
};

inline std::string const D::msg = "Hello world"; // NOLINT

int main() {
    std::cout << A::x << std::endl;
    std::cout << B::x << std::endl;
    std::cout << C::msg << std::endl;
    std::cout << D::msg << std::endl;

    struct C s1, s2;
    std::cout << "s1 == s2: " << (&s1.msg == &s2.msg) << "." << std::endl;
    struct D s3, s4;
    std::cout << "s3 == s4: " << (&s3.msg == &s4.msg) << "." << std::endl;
    std::cout << "s1 == s3: " << (&s1.msg == &s3.msg) << "." << std::endl;

    return 0;
}

