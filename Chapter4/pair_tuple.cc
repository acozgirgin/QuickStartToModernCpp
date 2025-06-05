#include <iostream>
#include <cstdint>
#include <utility> // std::pair burada tanımlı
#include <tuple> //std::tuple burada tanımlı
#include <string>

using namespace std;

struct Person
{
    uint32_t id;
    std::string name;
};


//NOTE: Bazı durumlarda bir function'dan birden cok turde veri dondurmek isteyebiliriz
// Use tuple --> std::make_tuple()
std::tuple<uint32_t , float , std::string> return_tuple(int32_t input)
{
    return std::make_tuple(10U, static_cast<float>(input) , "ACO");
}

int pair_tuple()
{
    //NOTE: std::pair ile sadece 2 veri yapısı kullanılabiliyor !
    //NOTE:  id - value pair olusturulabilir ornegin
    auto my_pair = std::pair<uint32_t , float>{1, 42.15F};

    // NOTE: accessing std::pair element .first , .second
    std::cout << my_pair.first <<"\n";
    std::cout << my_pair.second <<"\n";

    //NOTE:  id - name pairi olusturulabilir
    auto my_pair2 = std::pair<uint32_t, std::string>{10 , "Abidin"};

    //NOTE: tupleda 2 veri kısıtlaması yok !
    auto my_tuple = std::tuple<uint32_t , float , std::string>{1U , 42.15F , "Abidin"};

    //NOTE: accessing std::tuple elements --> std::get<index> indexler ve std::get kullanarak erişebiliyoruz
    std::cout << std::get<0U>(my_tuple) <<"\n";
    std::cout << std::get<1U>(my_tuple) <<"\n";
    std::cout << std::get<2U>(my_tuple) <<"\n";

    auto my_tuple2 = std::tuple<uint32_t , Person>{135U , Person{.id = 1 , .name="Abidin"}};

    //NOTE: Birden fazla return edilecek tür oldugu caselerde tuple donduren fonksiyonlar yazılabilir !
    auto my_tuple3 = return_tuple(15);


    return 0;
}
