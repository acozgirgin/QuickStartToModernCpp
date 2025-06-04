#include <iostream>
#include <cstdint>

int pointers()
{

    //Stackte tanımlanan değişkenlerin memoryde kaplayacağı alan önceden bilinmeli !!
    // size_t: unsigned long long --> 8 byte memoryde alan kaplayacı compiler tarafından onceden biliniyor. !
    constexpr auto len = std::size_t{5};

    //Fixed-size c-style array , length known in compile-time !
    //Created on stack.
    std::int16_t my_array[len]{};

    //Heapte userdan aldıgım length kadarlık uin32_t arrayi icin memory allocate edilecek !
    auto len2 = std::size_t{};
    std::cout << "Determine a size for heap array: ";
    std::cin >>len2;

    //OS bizim icin memoryi heapte allocate edecek !
    //Modern cpp'de neden pointerlara ihtiyacımız var ? : heap allocationları reference kullanarak yapamayız
    std::uint32_t* heap_arr = new std::uint32_t[len2];
    std::cout << "First element address of heap_arr: " << heap_arr << std::endl;

    //Print all element addresses : some random values are stored in uninitialized heap_arr
    if(heap_arr != nullptr)
    {
        for(size_t i=0; i<len2 ; i+=1)
        {
            std::cout << "heap_arr[" << i << "] " << "value stored: " << *(heap_arr+i) << std::endl;
            std::cout << "heap_arr[" << i << "] " << "memory address: " << heap_arr+i << std::endl;
            std::cout <<std::endl;
        }
    }


    //Deallocate memory after program stops --> avoid memory leaks
    //Fre the allocated memory on heap !
    //Kullanılan memoryi OS'ye geri vererek, ona bu memoryi başka allocationlar için kullanabilirsin demiş oluyoruz.
    //Saatlerce calısan bir programda ödünç alınan memoryi release etmezsek bu bir süre sonra programın çökmesine neden olur !.
    //delete operatorunu cagırdıktan sonra o iş için kullandıgmız pointer'ı nullptr olarak atarız: artık bu pointer valid bir addrese point etmiyor !
    delete[] heap_arr;
    heap_arr = nullptr;


    return 0;
}
