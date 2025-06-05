#include <iostream>
#include <array>
#include <span>
#include <vector>
#include <cstdint>
#include <string>
#include <span> // comes with C++20

using namespace std;

void print_container(const std::vector<int32_t>& vec)
{
    for(const auto& value : vec)
    {
        std::cout << value << std::endl;
    }
}

template<size_t N>
void print_container(const std::array<int32_t,N>& arr)
{
    for(const auto& value : arr)
    {
        std::cout << value << std::endl;
    }
}


//NOTE1: std::span --> light weight container reads memory
//NOTE2: pan --> başka bir containerin contigious (sıralı) memory addreslerine referans verebilen bir tür !!!
//NOTE3: containerin lenght'ini ve başlangıç addresini tutuyor sadece !
//NOTE4: Herhangi bir (contigious container) ile kullanılabilir
void print_span(const std::span<int32_t>& span)
{
    for(auto& value : span)
    {
        std::cout << value << std::endl;
    }
}

//NOTE:const olmayan lvalue referansı verilmiyor !!! --> Calısmaz
/*
std::span hafif bir kopyalanabilir görünüm nesnesidir

Veriyi kopyalamaz, sadece gösterir

std::span fonksiyona value olarak geçirilebilir — bu sadece pointer + size’ın kopyalanmasıdır ve çok ucuzdur

Referans ile veri paylaşımı yapar, bu yüzden span içindeki veriler değiştirildiğinde orijinal veri etkilenir
*/
void edit_with_span(std::span<int32_t> span)
{
    for(auto& val: span)
    {
        val*=2;
    }
}

int span()
{
    //NOTE:std::span ile std::vector , std::array gibi contigious veri yapılarının referansı tutulabilir
    auto vec = std::vector<int32_t>(10,1);
    print_container(vec);
    print_span(vec);

    constexpr auto len = 5U;
    auto arr = std::array<int32_t,len>{11,22,33,44,55};
    print_container(arr);
    print_span(arr);

    //NOTE: std::span ile contigious containerlardaki verileri değiştirebilir miyiz ? :EVET
    edit_with_span(arr);
    print_span(arr);

    return 0;
}
