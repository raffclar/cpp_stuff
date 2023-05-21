#include <variant>
#include <iostream>

int main() {
    auto p1 = [=] (auto msg, bool state) {
        std::cout << std::boolalpha << msg << state << "." << std::endl;
    };

    auto p2 = [=] (auto vx, auto msg, auto expect) {
        auto val = std::get_if<decltype(expect)>(&vx);
        p1(msg, val != nullptr && *val == expect);
    };

    // First variant example
    std::variant<int, double> v1;

    v1 = 0;
    auto n1 = std::get<int>(v1);
    static_assert(std::is_same<decltype(n1), int>::value);

    v1 = static_cast<double>(5);
    auto n2 = std::get<double>(v1);
    static_assert(std::is_same<decltype(n2), double>::value);

    // Second variant example
    std::variant<int, unsigned int, bool> v2, v3;

    v2 = 10;
    auto n3 = std::get<int>(v2);
    static_assert(std::is_same<decltype(n3), int>::value);

    v2 = static_cast<unsigned int>(15);
    auto n4 = std::get<unsigned int>(v2);
    static_assert(std::is_same<decltype(n4), unsigned int>::value);

    v2 = true;
    auto n5 = std::get<bool>(v2);
    static_assert(std::is_same<decltype(n5), bool>::value);

    v3 = true;
    p1("v2 == v3: ", v2 == v3);

    v2 = 10;
    p1("v2 == v3: ", v2 == v3);

    // Using get_if
    unsigned int n6 = 15;
    v2 = n6;
    p2(v2, "v2 == unsigned int: ", n6);

    int n7 = 20;
    v2 = n7;
    p2(v2, "v2 == int: ", n7);
    p2(v2, "v2 == unsigned int: ", n6);

    return 0;
}