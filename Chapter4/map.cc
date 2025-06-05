#include <iostream>
#include <cstdint>
#include <string>
#include <map> // --> C# ve Pythondaki dictionary dediğimiz veri yapısının C++ implementasyonu

using namespace std;

struct Product
{
    uint64_t product_id;
    std::string product_name;
    static std::string to_string(const Product& product){
        return "Product name: " + product.product_name + "\n";
    }
};

//NOTE: Key-Value pairleri üzerinde iterasyon yapmak icin ranged-based loop kullabiliriz !
void print_products(const std::map<uint64_t ,Product>& products)
{
    for(const auto& [key,val] : products)
    {
        std::cout << "Key:" << key << "  Value:" << Product::to_string(val) <<std::endl;
    }
}

int main()
{
    //NOTE: En sevdiğim Dictionary C# :) --> Key : Value pairs
    //NOTE: Diğer türlerde olduğu gibi keyler unique olacak !
    auto products = std::map<uint64_t , Product>{};

    products[0x6435U] = Product{.product_id =135U , .product_name="Gofret"};
    products[0x6436U] = Product{.product_id =136U , .product_name="Kalem"};
    products[0x6437U] = Product{.product_id =137U , .product_name="Tepsi"};

    print_products(products);

    //NOTE: C++20 feature --> key check contains()
    //NOTE: Alttaki kullanımın modern hali her ikisininde time complexity O(log(N)) --> Balanced Binary Search Tree (Red-Black Tree veri yapısıyla implement edilmiş)
    constexpr auto key_to_find = std::uint64_t{0x6435U};
    if(products.contains(key_to_find))
    {
        std::cout << "Specific key exist in the map ! " << std::endl;
        auto specific_product = products[key_to_find];
        std::cout<<"Found id:" << key_to_find << "  Found product: " << Product::to_string(specific_product) << std::endl;
    }

    //NOTE: std::map icinde belirli bir keyi arama !
    //NOTE: Pratikte yukardakiyle hic bir farkı yok sadece contains() methodu it_find != products.end() degil ise bool true doner !!!
    //NOTE: her ikisininde time complexity O(log(N)) --> Balanced Binary Search Tree (Red-Black Tree veri yapısıyla implement edilmiş)
    const auto it_find = products.find(key_to_find);
    if(it_find == products.end())
    {
        std::cout << "Specific key not found !" << std::endl;
    }

    if(it_find != products.end())
    {
        std::cout << "Specific key found !" << std::endl;
        auto& [id,product] = *it_find;
        std::cout<<"Found id:" << id << "  Found product: " << Product::to_string(product) << std::endl;
    }

    return 0;
}
