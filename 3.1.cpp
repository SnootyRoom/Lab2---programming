#include <iostream>

using namespace std;

int getIndexOfWarmDay(int *temperatures, const int &N){
    int maxTemperatureIndex = 0;
    for (int i = 0; i < N; i++) {
        if(temperatures[maxTemperatureIndex] < temperatures[i]) maxTemperatureIndex = i;
    }
    return maxTemperatureIndex;
}


int main(int, char**){
    const int N = 7;
    string nameDays[] = {"Monday", "Tuesday", "Wednesday",
         "Thursday", "Friday", "Saturday", "Sunday"};
    
    int *temperatures = new int[N];
    bool *precipitations = new bool[N];
    int indexWarmDay;

    for(int i = 0; i < N; i++){
        cout<<"Input the tempreture on "<<nameDays[i]<<endl;
        cin>>temperatures[i];
        cout<<"Input 0 if no  precipitation else 1 on "<<nameDays[i]<<endl;
        cin>>precipitations[i];
    }

    indexWarmDay = getIndexOfWarmDay(temperatures, N);

    cout<<"The warmest day"<<endl;
    cout<<nameDays[indexWarmDay]<<endl;
    cout<<"Temperature: "<<temperatures[indexWarmDay]<<endl;
    cout<<"Precipitation: "<<(precipitations[indexWarmDay] ? "Yes": "No")<<endl;


    delete temperatures;
    delete precipitations;

    return 0;
}