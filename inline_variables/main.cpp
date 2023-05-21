#include <iostream>

struct FirstStruct {
    static inline const char *msg = "Hello world";
};

struct SecondStruct {
    static const char *msg;
};

inline const char *SecondStruct::msg = "Hello world";

int main() {
    struct FirstStruct s1, s2;
    std::cout << "s1 == s2: " << (&s1.msg == &s2.msg) << "." << std::endl;
    struct SecondStruct s3, s4;
    std::cout << "s3 == s4: " << (&s3.msg == &s4.msg) << "." << std::endl;

    return 0;
}
