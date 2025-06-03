#include <iostream>
#include <cstdint>
#include <array>

int main()
{


    auto my_age = std::uint8_t{27U};
    std::uint8_t* ptr = &my_age;
    std::cout << "Memory address of variable my_age:" << ptr << std::endl;

    return 0;
}
