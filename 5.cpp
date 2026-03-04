#include <iostream>
#include <string>
#include <ctime>

using namespace std;

enum VechicleType {
    Car,
    Truck,
    Motorcycle
};

struct Engine {
    int power;
    double volume;
};

struct Vechicle {
    VechicleType vechicleType;
    string model;
    Engine engine;
};

struct FlatVehicle {
    int type;
    string model;
    int power;
    double volume;
};

int getPower(const Vechicle& vechicle) { return vechicle.engine.power; }

int getPower(const FlatVehicle& vechicle) { return vechicle.power; }

template <typename T>
T* mergeVechicleByPower(T* left, const int &N, T* right, const int &M) {
    T *mergedVechicle = new T[N + M];
    int i = 0, j = 0;

    while(i < N && j < M) {
        if(getPower(left[i]) < getPower(right[j])) {
            mergedVechicle[i + j] = left[i];
            i++;
        }
        else {
            mergedVechicle[i + j] = right[j];
            j++;
        }
    }

    while (i < N) {
        mergedVechicle[i + j] = left[i];
        i++;
    }

    while (j < M) {
        mergedVechicle[i + j] = right[j];
        j++;
    }
    return mergedVechicle;
}

template <typename T>
T* mergeSortVechicleByPower(T* vechicles, const int &N) {
    if (N <= 1) return vechicles;

    int mid = N / 2;
    T *left = new T[mid];

    for (int i = 0; i < mid; i++) left[i] = vechicles[i];

    T *right = new T[N - mid]; 

    for (int i = mid; i < N; i++) right[i - mid] = vechicles[i];

    left = mergeSortVechicleByPower(left, mid);
    right = mergeSortVechicleByPower(right, N - mid);

    return mergeVechicleByPower(left, mid, right, N - mid);
}

string getVechicleType(int id) {
    switch (id) {
        case Car:    return "Car";
        case Truck:   return "Truck";
        case Motorcycle: return "Motorcycle";
    }
}

void inputVechicle(Vechicle &vechicle) {
    int idVechicleType;
    cout<<"Input vechicle type: 0 - Car, 1 - Truck, 2 - Motorcycle"<<endl;
    cin>>idVechicleType;
    vechicle.vechicleType = static_cast<VechicleType>(idVechicleType);
    cout<<"Input model of vechicle"<<endl;
    getline(cin>>ws, vechicle.model);
    cout<<"Input info about engine"<<endl;
    cout<<"Input power"<<endl;
    cin>>vechicle.engine.power;
    cout<<"Input volume"<<endl;
    cin>>vechicle.engine.volume;
}

void printVechicle(Vechicle &vechicle) {
    cout<<endl;
    cout<<"Info about vechicle"<<endl;
    cout<<"Type: "<<getVechicleType(vechicle.vechicleType)<<endl;
    cout<<"Model: "<<vechicle.model<<endl;
    cout<<"Info about engine"<<endl;
    cout<<"Power: "<<vechicle.engine.power<<endl;
    cout<<"Volume: "<<vechicle.engine.volume<<endl;
}


int main(int, char**) {
    const int N = 5;
    Vechicle *vechicles = new Vechicle[N];
    Vechicle *sortedVechicles = new Vechicle[N];

    for (int i = 0; i < N; i++) inputVechicle(vechicles[i]);

    sortedVechicles = mergeSortVechicleByPower(vechicles, N);

    cout<<"Cars: ";
    for (int i = 0; i < N; i++){
       if (sortedVechicles[i].vechicleType == Car) printVechicle(sortedVechicles[i]);
    } 

    cout<<"Trucks: ";
    for (int i = 0; i < N; i++){
       if (sortedVechicles[i].vechicleType == Truck) printVechicle(sortedVechicles[i]);
    } 

    cout<<"Motorcycles: ";
    for (int i = 0; i < N; i++){
       if (sortedVechicles[i].vechicleType == Motorcycle) printVechicle(sortedVechicles[i]);
    } 


    const int M = 100;
    Vechicle *nestedVechicle = new Vechicle[M];
    FlatVehicle *flatVechicle = new FlatVehicle[M];;

    for (int i = 0; i < N; i++) {
        int p = rand() % 500;
        nestedVechicle[i] = {Car, "Model", {p, 2.0}};
        flatVechicle[i] = {0, "Model", p, 2.0};
    }


    clock_t start = clock();
    for(int i = 0; i < 1000; i++){
        mergeSortVechicleByPower(nestedVechicle, M);
    }
    clock_t end = clock();
    double timeNested = double(end - start) / CLOCKS_PER_SEC;

    start = clock();
    for(int i = 0; i < 1000; i++){
        mergeSortVechicleByPower(flatVechicle, M);
    }
        
    end = clock();
    double timeFlat = double(end - start) / CLOCKS_PER_SEC;

    cout<<endl<<"Compare Efficiency"<<endl;
    cout<<"Nested struct: "<<timeNested<< " sec"<<endl;
    cout<<"Flat struct:   "<<timeFlat<< " sec"<<endl;

    delete vechicles;
    delete sortedVechicles;
    delete nestedVechicle;
    delete flatVechicle;

    return 0;
}