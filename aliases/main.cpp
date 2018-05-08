#include <iostream>

using A = double (*)();
typedef double (*B)();

double f() {
    return 0.5;
}

using AliasedStruct = struct TheStruct {
    int a;
};

int main () {
    constexpr A x = f;
    constexpr B y = f;
    static_assert(std::is_same<decltype(x), decltype(y)>::value);
    static_assert(std::is_function<decltype(f)>::value);
    static_assert(std::is_pointer<decltype(x)>::value);
    static_assert(std::is_pointer<decltype(y)>::value);

    AliasedStruct aliased {.a = 0};
    struct TheStruct the_struct {.a = 0};
    static_assert(std::is_same<decltype(aliased), decltype(the_struct)>::value);

    return 0;
}
