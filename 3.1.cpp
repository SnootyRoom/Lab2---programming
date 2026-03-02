#include <iostream>

using namespace std;

int getIndexOfWarmDay(int temperatures[]){
    int maxTemperatureIndex = 0;
    for (int i = 0; i < 7; i++) {
        if(temperatures[maxTemperatureIndex] < temperatures[i]) maxTemperatureIndex = i;
    }
    return maxTemperatureIndex;
}


int main(int, char**){
    string nameDays[] = {"Monday", "Tuesday", "Wednesday",
         "Thursday", "Friday", "Saturday", "Sunday"};
    
    int temperatures[7];
    bool precipitations[7];
    int indexWarmDay;

    for(int i = 0; i < 7; i++){
        cout<<"Input the tempreture on "<<nameDays[i]<<endl;
        cin>>temperatures[i];
        cout<<"Input 0 if no  precipitation else 1 on "<<nameDays[i]<<endl;
        cin>>precipitations[i];
    }

    indexWarmDay = getIndexOfWarmDay(temperatures);

    cout<<"The warmest day"<<endl;
    cout<<nameDays[indexWarmDay]<<endl;
    cout<<"Temperature: "<<temperatures[indexWarmDay]<<endl;
    cout<<"Precipitation: "<<(precipitations[indexWarmDay] ? "Yes": "No")<<endl;


    delete nameDays;
    delete temperatures;
    delete precipitations;

    return 0;
}