#include <iostream>
#include <array>
#include <span>
#include <vector>
#include <cstdint>

//NOTES: APPLICATION STL VECTORS
//Vector: most improtant class in STL : dynamic data container --> size can be changed at run-time
//Heap arraylerini kullanmamıza gerek yok cpp std::vector bu implementasyonu sağlıyor.
//dynamic array(sıralı memory address - contigious) veri yapısıyla implement edilmiş --> eleman erişimi my_vec[1] complexity O(1) çok hızlı !!!
//STL librarydeki containerler Template class library olarak tasarlanmış -> bu sayede tüm veri türleri ile çalışabiliyoruz.

template<typename T>
void ranged_for_loop_cpp_const(const std::vector<T>& vector)
{
    //NOTES:
    //begin , end iterator kullan !!!!
    //C++ ranged for loop, value == my_vec[i];
    //const oldugu icin value üzerinde degisiklik yapamıyoruz !

    //sadece veri okuyacaksak const auto& kullanabiliriz fakat std::int32_t gibi kücük veri yapıları icin pointer olusturmak daha fazla memory harcar burada gerek yok !
    //aşağıdaki loopun local-copy olusturmasına izin verdik cunku daha memory harcayacak uint32_t gibi kücük bir veri yapısı üzerinde iterasyon yapacağımız için
    for(const auto value : vector)
    {
        std::cout <<"C++ ranged for loop with iterators: " << value << std::endl;
    }
}

template<typename T>
void ranged_for_loop_cpp_with_reference(std::vector<T>& vector)
{
    //NOTES:
    //begin , end iterator kullan !!!!
    //C++ ranged for loop, value == my_vec[i];
    //non-const reference oldugu icin value üzerinde degisiklik yapabiliriz !

    //burada container içindeki veriyi değiştireceğimiz için auto& kullandık
    //Veri üzerinde değişiklik yapılacak referans ile ranged-loop çevirmekten baska şansımız yok
    //Aynı zamanda local copy olusmadı --> bunun yerine memoryde 64-bitlik alan kaplayan pointerlar olustu (OS'im 64-bit)
    for(auto& value : vector)
    {
        value*=2;
        std::cout <<"C++ ranged for loop with iterators: " << value << std::endl;
    }
}

//Yukardaki ranged-based loopları kullan bu sekilde iteratorler uzerındende kullanabiliriz sadece gostermek icin.
//iteratorlar STL container'ların içindeki verileri dolaşmak için kullanılan, pointer gibi davranan ama sınıf objesi olan yapılardır.
//begin() ve end() fonksiyonları listenin başını ve sonunu gosteren pointerlar gibi calısan iterator objesi return eder !
//for (const auto& value : vector) asagıdaki methodun sadeleşmiş hali aynı işi yapıyorlar !
template<typename T>
void for_loop_vector_iterators(std::vector<T>& vector)
{
    //NOTES:
    //begin , end iterator kullan !!!!
    //C++ ranged for loop, value == my_vec[i];
    //non-const reference oldugu icin value üzerinde degisiklik yapabiliriz !
    for(auto i = vector.begin(); i!=vector.end(); ++i)
    {
        std::cout << "Vector loop with begin() and end() iterators: " << *i << std::endl;
    }
}


int vectors()
{
    //NOTES: APPLICATION STL VECTORS
    //Empty initliazation yapılabilir --> veriler run-time'da eklenir.
    //Size compile-time'da belliyse std::array kullan değilse std::vector

    //size 0 on allocation
    auto my_vec_empty = std::vector<std::uint32_t>{};

    //size 5 on allocation
    auto my_vec = std::vector<std::uint32_t>{1,2,3,4,5};

    //begin() ve end() kullanımı loop icinde
    for_loop_vector_iterators(my_vec);

    //Ranged-loop usage in Cpp using const reference
    ranged_for_loop_cpp_const(my_vec);

    //Ranged-loop usage in Cpp using non-const reference --> veriyi degistirebiliriz
    ranged_for_loop_cpp_with_reference(my_vec);

    //C-style loop for value lookup --> verinin degistigini kontrol et
    //Very fast complexity: O(1)
    //std::vector containerının başına ve sonuna veri eklemek hızlı !
    //std::vector containerının ortasından veri silmek veya eklemek okadar hızlı değil !
    //Cunku ortaya bir yere bir eleman eklediğinde tüm vectorun index olarak kaydırılması ve yeniden oluşturulması gerekiyor.
    //std::vector sıralı memory addresleri ile oluşturuluyor.
    for(std::size_t i=0; i < my_vec.size(); ++i)
    {
        std::cout <<"C-style for with indexes loop my_vec[" << i << "]:" << my_vec[i] << std::endl;
    }


    //NOTE: begin(): vectoredeki ilk elemanın saklandıgı memory addresini gösterir
    auto it_begin = my_vec.begin(); // vectordeki ilk elamanı gösteren pointer

    //NOTE: döngü icerisinde i!=my_vec.end() gibi bir kullanım yapıyoruz cünkü my_vec.end() aslında listenin sonundan bir sonraki adresi tutar
    auto it_end = my_vec.end(); // vectordaki son elemandan bir sonraki addresi gösteriyor !!

    //NOTE:vectorde ilk veya son olmayan bir indexe eleman eklemek icin insert() methodu kullanılır
    //3. elemana 55 degerini koyduk --> cok iyi bir kullanım degil başa veya sona ekleme hızı çok daha fazla bu veri yapısında dynamic array(contigious) !
    my_vec.insert(my_vec.begin() + 2 , std::uint32_t{55});
    ranged_for_loop_cpp_const(my_vec);

    std::cout << std::endl;



    return 0;
}
