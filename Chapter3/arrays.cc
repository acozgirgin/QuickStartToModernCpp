#include <iostream>
#include <cstdint>
#include <array>

void print_array_elements(std::int32_t array[] , const std::size_t len) // array input
{
    //C-style array problem: --> input array is just points the first element of the array
    //Length is not defined when passing c-style arrays to a function its a problem
    //Length'i functiona her zaman input olarak ve tam olarak vermek zorundayız !!
    for(size_t i = 0 ; i <len ; ++i)
    {

      std::cout << "Array value at idx:" << i << " value: " <<  array[i] << std::endl;

    }

}

//Same syntax with the above example
void print_array_elements_pointer(std::int32_t* array , const std::size_t len) // array input
{
    //C-style array problem: --> input array is just points the first element of the array
    for(size_t i = 0 ; i <len ; ++i)
    {
      std::cout << "Array value at idx:" << i << " value: " <<  array[i] << std::endl;
    }

}

//c++ style arrays -> Use std::array --> loop with predifened size() --> template N to call with predifined length
//Burada template kullanarak input arrayin lengthini verebiliriz !!
//Lenght'ini template olarak verip compiler'ın otomatik olarak çağırılarda atamasını sağlayabiliriz.
template <std::size_t N>
void print_array_values2(const std::array<std::int32_t,N> my_array)
{
    for(size_t i=0; i < my_array.size(); i+=1)
    {
        std::cout << "Array value at idx:" << i << " value: " <<  my_array[i] << std::endl;
    }

}

void arrays() {

    constexpr auto len = std::uint32_t{5U};

    //C-style array --> initiliaze with uniform/bracelet/list inilazer
    std::int32_t my_array[len] = {1,2,3,4,5};
    print_array_elements(my_array , len);
    print_array_elements_pointer(my_array , len);

    //C++ array: --> std::array size yine compile-time'da bilinmek zorunda, c-style array mantıgında
    constexpr auto array_len = std::size_t{3U}; //AAA : almost always auto
    auto std_array = std::array<std::int32_t,array_len>{6,7,8}; //AAA : almost always auto
    print_array_values2<array_len>(std_array);

    //C++ array + template --> başka boyutlarda arrayler ile template function çağırabiliriz
    constexpr auto std_array2 = std::array<std::int32_t,4U>{9,10,11,12}; //AAA : almost always auto
    print_array_values2<std_array2.size()>(std_array2);

    return;
}
