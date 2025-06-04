#include <iostream>
#include <array>
#include <span>
#include <vector>
#include <cstdint>


//Generic types --> abstract - T kullanmazsak farklı türler için aşağıdaki gibi sürekli function overload yapmamız gerekiyor.
void print_container(std::span<std::int32_t> span)
{
    for(const auto val : span)
    {
        std::cout << "Val: " << val << std::endl;
    }
}

//Copy paste code !! againts to DRY: Don't Repat Yourself princible
//span ayrı bir dünya: view of collection , verinin sahibi degil !  --> vector , array , c-style arrays hepsiyle cagirabiliriz
template<typename T>
void print_container_span(std::span<T> span)
{
    for(const auto val : span)
    {
        std::cout << "Val: " << val << std::endl;
    }

    std::cout << std::endl;

}

//Template function --> prints a container element values
//Compiler type'ı otamatik olarak atıyor fonksiyon çağrıldıgında
template<typename T>
void print_container_template(std::vector<T> vector)
{
    for(const auto val : vector)
    {
      std::cout << "Val: " << val << std::endl;
    }

    std::cout << std::endl;
}

//STL: Standart Template Library --> burda tanımlanan containerların hepsi template olarak tanımlanmış !!
// Farklı türler ile çalışma templateleri kullan !!!
int templates()
{

    //std::vector<std::uint16_t> buffer{1,2,3};
    auto buffer = std::vector<std::uint16_t>{1,2,3};

    //std::vector<std::int32_t> buffer2{11,22,33};
    auto buffer2 = std::vector<std::int32_t>{11,22,33};

    //template T --> typenı belirterek veya belirtmeden cagirabiliriz
    print_container_template<std::uint16_t>(buffer);
    print_container_template(buffer2);
    print_container_span<std::uint16_t>(buffer);
    print_container_span<std::int32_t>(buffer2);

    return 0;
}
