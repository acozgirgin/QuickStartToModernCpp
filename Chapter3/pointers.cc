#include <iostream>
#include <cstdint>
#include <array>

int pointers()
{
    auto my_age = std::uint32_t{27U};
    std::uint32_t* ptr = &my_age;


    //my_age variable addres using & operator
    std::cout << "Memory address of variable {my_age} using &:" << &my_age << std::endl;

    //my_age değişkenin adresi ptr pointer'ı içinde saklanır
    std::cout << "Memory address of variable {my_age} using ptr: " << ptr << std::endl;

    //Pointerda hafızada tutulan bir değişken gibi yer kaplar --> değer olarak point ettiği memory adresindeki değeri gösterir
    std::cout << "Memory addres of pointer {ptr}: " << &ptr << std::endl;

    //64-bit / 8 byte memory addersleri kullanıyor OS o yüzden 8 bytelık yer kaplıyor.
    std::cout << "Size of {ptr} in memory: " << sizeof(ptr) << std::endl;

    //Pointer ptr'nin işaret ettiği memory addresinde tutulan değer
    std::cout<< "Value stored at {ptr} is point to: " << *ptr << std::endl;

    return 0;
}
