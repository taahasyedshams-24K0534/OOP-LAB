#include<iostream>
#include<string>
using namespace std

class Shipment
{
protected:
    string trackingNumber
    double weight
public:
    Shipment(string tn,double w):trackingNumber(tn),weight(w){}
    virtual void estimateDeliveryTime()=0
    virtual void showDetails()=0
    virtual~Shipment(){}
}

class AirFreight:public Shipment
{
public:
    AirFreight(string tn,double w):Shipment(tn,w){}
    void estimateDeliveryTime()
    {
        cout<<"Air Freight Estimated Delivery: 1-2 days"<<endl
    }
    void showDetails()
    {
        cout<<"Air Freight"<<endl
        cout<<"Tracking Number:"<<trackingNumber<<endl
        cout<<"Weight:"<<weight<<" kg"<<endl
    }
}

class GroundShipment:public Shipment
{
public:
    GroundShipment(string tn,double w):Shipment(tn,w){}
    void estimateDeliveryTime()
    {
        cout<<"Ground Shipment Estimated Delivery: 3-5 days"<<endl
    }
    void showDetails()
    {
        cout<<"Ground Shipment"<<endl
        cout<<"Tracking Number:"<<trackingNumber<<endl
        cout<<"Weight:"<<weight<<" kg"<<endl
    }
}

int main()
{
    Shipment*s1=new AirFreight("A1",16)
    Shipment*s2=new GroundShipment("G1",23)
    s1->showDetails()
    s1->estimateDeliveryTime()
    cout<<endl
    s2->showDetails()
    s2->estimateDeliveryTime()
    delete s1
    delete s2
    return 0
}
