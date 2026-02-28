#include <iostream>

using namespace std;

enum Status {
    Excellent = 5,
    Good = 4,
    Satisfactory = 3,
    Unsatisfactory = 2
};

struct Student {
    int id;
    string name;
    Status status;
};

int main(int, char**){
    Student student;
    int statusChoice;

    cout<<"Input id of Student"<<endl;
    cin>>student.id;

    cout<<"Input name of Student"<<endl;
    cin>>student.name;

    cout<<"Input status of student (5 - Excellent, 4 - Good, 3 - Satisfactory, 2 - Unsatisfactory)"<<endl;
    cin>>statusChoice;

    student.status = static_cast<Status>(statusChoice);
    
    cout<<"Student info"<<endl;
    cout<<"id: "<<student.id<<endl;
    cout<<"name: "<<student.name<<endl;
    cout<<"status: "<<student.status<<endl;

    int array[4];

    cout<<"Comparison array and struct"<<endl;
    cout<<"array: "<<sizeof(array)<<endl;
    cout<<"struct: "<<sizeof(student)<<endl;

    delete array;

    return 0;
}
