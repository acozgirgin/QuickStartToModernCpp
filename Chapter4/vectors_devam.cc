
#include <iostream>
#include <array>
#include <span>
#include <vector>
#include <cstdint>
#include <string>

static std::int32_t INDEX_COUNT = 0 ;
static std::int32_t COPY_CONSTRUCTOR_HIT_COUNT = 0;
static std::size_t LAST_LENGTH = 0;
static std::size_t PERSON_CAPACITY = 1000;

struct Person
{
    std::string pName;
    std::uint32_t pAge;

    Person(std::string name , std::uint32_t age): pName{name} , pAge{age} {}

    Person(const Person& other)
    {
        std::cout <<"Copy ctor worked ! " << std::endl;
        ++COPY_CONSTRUCTOR_HIT_COUNT;
        this->pName = other.pName;
        this->pAge = other.pAge;
    }

};



template<typename T>
void print_vector_memory_addreses(const std::vector<T>& vec)
{
    //std::vector container'ı hafızayı contigious (sıralı) olarak allocate etti --> özelliği bu eleman erişimi O(1) complexity
    INDEX_COUNT = 0;
    for(const auto& val : vec)
    {
        std::cout << "vec["<< INDEX_COUNT << "] memory address:" <<&val << std::endl;
        INDEX_COUNT+=1;

    }
}

void print_person_info(const std::vector<Person>& persons)
{
    for(const auto& person : persons)
    {
        std::cout << person.pName << std::endl;
    }
}

//Vector size kontrolü gereksiz memory allocation ve veri kopyalama onlemek icin özel add methodu
void try_add_person(std::vector<Person>& persons , Person& person)
{
    ++LAST_LENGTH;
    persons.emplace_back(person.pName , person.pAge);
}


int vectors2()
{
    //10 tane aynı elemanla init ettik person vector --> Person object copied 10 times !!
    //push_back() ile vectore ekleme yaptıgımızdada copy constructor calısıyor --> gereksiz kopyalama var !
    //auto pDb = std::vector<Person>(10, Person("Abidin",27U));
    //for(int i=0; i<10; ++i) pDb.push_back(Person("Abidin",27U));
    //std::cout<<"Copied data count: " << COPY_CONSTRUCTOR_HIT_COUNT << std::endl;

    //NOTE: Optimim std::vector kullanımı !
    //emplace_back() ile ekleme yaparsan gereksiz kopyalama yapmıyor !!!
    //reserve() fonksiyonu ile gereksiz memory allocation ve copy constructor çağrısını engellemek için bir alan belirle ornegin 20
    //Constructor paremetrelerini direkt input olarak emplace_back methoduna verebiliyoruz !!!
    COPY_CONSTRUCTOR_HIT_COUNT=0;
    auto pDb2 = std::vector<Person>{};
    pDb2.reserve(PERSON_CAPACITY);
    auto defaultPerson = Person{"Abidin",27U};
    for(size_t i=0; i<PERSON_CAPACITY + 100; i+=1) try_add_person(pDb2 , defaultPerson);
    std::cout<<"Copied data count: " << COPY_CONSTRUCTOR_HIT_COUNT << std::endl;


    //Zero initialize N:10 vector initialize edilen vectordeki elemanların memory addreslerini print et
    //auto buffer = std::vector<std::uint32_t>(10,0);
    //print_vector_memory_addreses(buffer);

    //Sona bir eleman ekle ve memory addresine bak !
    //buffer.push_back(std::uint32_t{13U});
    //print_vector_memory_addreses(buffer);



}
