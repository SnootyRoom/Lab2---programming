#include <iostream>

using namespace std;

enum Day {
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6,
    Sunday = 7
};

struct Weather {
    Day day;
    int temperature;
    bool precipitation;
};

string getDayName(int day) {
    switch (day) {
        case Monday:    return "Monday";
        case Tuesday:   return "Tuesday";
        case Wednesday: return "Wednesday";
        case Thursday:  return "Thursday";
        case Friday:    return "Friday";
        case Saturday:  return "Saturday";
        case Sunday:    return "Sunday";
    }
}

Weather searchWarmDay(Weather weather[]){
    int warmDayIndex = 0;
    for (int i = 0; i < 7; i++) {
        if (weather[warmDayIndex].temperature < weather[i].temperature) warmDayIndex = i;
    }
    return weather[warmDayIndex];
}

int main(int, char**){
    Weather weather[7];
    Weather warmDay;
    string dayName;


    for(int i = 1; i < 8; i++){
        weather[i - 1].day = static_cast<Day>(i);
        dayName = getDayName(weather[i - 1].day);
        cout<<"Input the tempreture on "<<dayName<<endl;
        cin>>weather[i - 1].temperature;
        cout<<"Input 0 if no  precipitation else 1 on "<<dayName<<endl;
        cin>>weather[i - 1].precipitation;
        
    }

    warmDay = searchWarmDay(weather);

    cout<<"The warmest day"<<endl;
    cout<<getDayName(warmDay.day)<<endl;
    cout<<"Temperature: "<<warmDay.temperature<<endl;
    cout<<"Precipitation: "<<(warmDay.precipitation ? "Yes": "No")<<endl;

    delete weather;
    
    return 0;
}