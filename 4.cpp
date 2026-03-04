#include <iostream>
#include <string>

using namespace std;

struct Address{
    string street;
    int numberOfHouse;
    int numberOfFlat;
};

struct Person {
    string fullName;
    int age;
    Address address;
};

struct FlatPerson {
    string fullName;
    int age;
    string street;
    int house;
    int flat;
};


void inputPerson(Person &person){
    cout<<"Input info about person"<<endl;
    cout<<"Input fullname"<<endl;
    getline(cin >> ws, person.fullName);
    cout<<"Input age"<<endl;
    cin>>person.age;
    cout<<"Input info about address"<<endl;
    cout<<"Input street"<<endl;
    getline(cin >> ws, person.address.street);
    cout<<"Input number of house"<<endl;
    cin>>person.address.numberOfHouse;
    cout<<"Input number of flat"<<endl;
    cin>>person.address.numberOfFlat;
}

void printPerson(Person &person){
    cout<<endl;
    cout<<"Info about person"<<endl;
    cout<<"Fullname: "<<person.fullName<<endl;
    cout<<"Age: "<<person.age<<endl;
    cout<<"Address"<<endl;
    cout<<"street: "<<person.address.street<<endl;
    cout<<"Number of house: "<<person.address.numberOfHouse<<endl;
    cout<<"Number of flat: "<<person.address.numberOfFlat<<endl;
}

Person findPersonByStreet(Person *&persons, const int &N, string street){
    
    for(int i = 0; i < N; i++) {
        if(persons[i].address.street == street) return persons[i];
    }
    return {};
}


int main(int, char**) {
    const int N = 3;
    Person *persons = new Person[N];
    Person person;
    string targetStreet;

    
    for (int i = 0; i < N; i++) inputPerson(persons[i]);

    for (int i = 0; i < N; i++) printPerson(persons[i]);

    cout<<endl<<"Input street to find person"<<endl;
    getline(cin >> ws, targetStreet);
    person = findPersonByStreet(persons, N, targetStreet);

    cout<<"Info about person"<<endl;
    printPerson(person);

    cout<<"Compare Person and FlatPerson"<<endl;
    cout<<"Size of Person: "<<sizeof(person)<<endl;
    cout<<"Size of FlatPerson: "<<sizeof(FlatPerson)<<endl;

    delete persons;

    return 0;
}