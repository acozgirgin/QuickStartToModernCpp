#include <iostream>
#include <string>
#include <array>
#include <cstdint>

void strings()
{
    //strings --> run time size changed or the first size is known at compile-time (arrays)
    //C-style char arrays
    char single_character = 'a'; // ASCII --> decimal 97
    char my_text[] = "Abidin"; // '\0':end of the string karakteri compiler tarafından otomatik ekleniyor !!!
    char my_text2[] ={'A','b','i','d','i','n'};
    auto my_text3 = std::array<char,7>{"Abidin"}; // 6 karakter + otomatik \0 atılıyor o yüzden 7 size'lık

    //Her zaman fixed size calısamayız
    //Bunun yerine standart library string classını kullanabiliriz --> ama daha yavaş dynamic memory allocation !!!!
    //"Abidin": string literal known at compile-time
    auto my_text5 = std::string{"Abidin"};
    std::cout << "String len: " << my_text5.length() << std::endl;

    //append method
    my_text5.append("Can");
    std::cout << my_text5;
    my_text5.append("Ozgirgin");
    std:: cout<< my_text5;


    //Whats used in modern C++ ?
    //my_text: char my_text[] = "Abidin";
    //my_text5: my_text5 = std::string{"Abidin"};

    return;
}
