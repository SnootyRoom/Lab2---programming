#include <iostream>

using namespace std;

struct Address{
    string street;
    int house;
    int flat;
};

struct Person {
    string fullname;
    int age;
    Address address;
};



int main(int, char**) {
    const int N = 3;
    Person *persons = new Person[N];


    return 0;
}