#include<iostream>
#include<string>
using namespace std

class WeatherSensor
{
public:
    virtual void readData()=0
    virtual void displayReport()=0
    virtual~WeatherSensor(){}
}

class Thermometer:public WeatherSensor
{
private:
    double temperature
public:
    void readData()
    {
        temperature=25.5
    }
    void displayReport()
    {
        cout<<"Thermometer Reading:"<<temperature<<" C"<<endl
    }
}

class Barometer:public WeatherSensor
{
private:
    double pressure
public:
    void readData()
    {
        pressure=1019
    }
    void displayReport()
    {
        cout<<"Barometer Reading:"<<pressure<<" hPa"<<endl
    }
}

int main()
{
    WeatherSensor*sensor1=new Thermometer
    WeatherSensor*sensor2=new Barometer
    sensor1->readData()
    sensor1->displayReport()
    cout<<endl
    sensor2->readData()
    sensor2->displayReport()
    delete sensor1
    delete sensor2
    return 0
}
