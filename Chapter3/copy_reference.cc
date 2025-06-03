
#include <iostream>
#include <cstdint>
#include <array>

//Pass by reference: local my_arraye kopyalanmadan sadece referansıyla gondeririz
//Use references to avoid copies !!!
template <std::size_t N>
void print_array_by_reference(const std::array<std::int32_t,N>& my_array)
{
    std::cout << "Memory addres from print_array_by_reference function:" << &my_array << std::endl;

    for(size_t i=0; i < my_array.size(); i+=1)
    {
        std::cout << "Array value at idx:" << i << " value: " <<  my_array[i] << std::endl;
    }

}

//my_array locally copied to another memory address !!
template <std::size_t N>
void print_array_by_copy(const std::array<std::int32_t,N> my_array)
{
    std::cout << "Memory addres from print_array_by_copy function:" << &my_array << std::endl;

    for(size_t i=0; i < my_array.size(); i+=1)
    {
        std::cout << "Array value at idx:" << i << " value: " <<  my_array[i] << std::endl;
    }
}

//Burada memoryde az yer kaplayacak veri türlerini reference olarka gondermeye gerek yok !!
//64-bit işletim sisteminde bir pointer 8-byte yer kaplıyor, fazladan memory usage yaratırız !!
template <std::size_t N>
void multiply_array_values(std::array<std::int32_t,N>& my_array , std::int32_t factor)
{
    for(size_t i=0; i < my_array.size(); i+=1)
    {
        my_array[i] *= factor;
    }

}

int references()
{
    auto test_array = std::array<std::int32_t,5U>{1,2,3,4,5};
    std::cout << "Memory addres from main function:" << &test_array << std::endl;
    print_array_by_reference(test_array);

    //Pass by value --> memory test_array copied !!
    print_array_by_copy(test_array);

    //Pass by reference and modify test_array without copying !!
    multiply_array_values(test_array , 5);
    print_array_by_reference(test_array);

    return 0;

}
