#include <iostream>
#include <string>

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

string getStatus(int status) {
    switch (status) {
        case Excellent:    return "Excellent";
        case Good:   return "Good";
        case Satisfactory: return "Satisfactory";
        case Unsatisfactory:  return "Unsatisfactory";
    }
}

int main(int, char**){
    const int N = 4;
    Student student;
    int statusChoice;
    int *array = new int[N];

    for(int i = 0; i < N; i++) array[i] = 0;

    cout<<"Input id of Student"<<endl;
    cin>>student.id;


    cout<<"Input name of Student"<<endl;    
    getline(cin>>ws, student.name);

    cout<<"Input status of student (5 - Excellent, 4 - Good, 3 - Satisfactory, 2 - Unsatisfactory)"<<endl;
    cin>>statusChoice;

    student.status = static_cast<Status>(statusChoice);
    
    cout<<"Student info"<<endl;
    cout<<"id: "<<student.id<<endl;
    cout<<"name: "<<student.name<<endl;
    cout<<"status: "<<getStatus(student.status)<<endl;

    cout<<"Comparison array and struct"<<endl;
    cout<<"array: "<<sizeof(array)<<endl;
    cout<<"struct: "<<sizeof(student)<<endl;

    delete array;

    return 0;
}
