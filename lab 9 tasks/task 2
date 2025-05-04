#include<iostream>
#include<string>
using namespace std

class MenuItem
{
protected:
    string dishName
    double price
public:
    MenuItem(string name,double p):dishName(name),price(p){}
    virtual void showDetails()=0
    virtual void prepare()=0
    virtual~MenuItem(){}
}

class Appetizer:public MenuItem
{
public:
    Appetizer(string name,double p):MenuItem(name,p){}
    void showDetails()
    {
        cout<<"Appetizer:"<<dishName<<endl
        cout<<"Price:"<<price<<endl
    }
    void prepare()
    {
        cout<<"Preparing appetizer:"<<dishName<<endl
    }
}

class MainCourse:public MenuItem
{
public:
    MainCourse(string name,double p):MenuItem(name,p){}
    void showDetails()
    {
        cout<<"Main Course:"<<dishName<<endl
        cout<<"Price:"<<price<<endl
    }
    void prepare()
    {
        cout<<"Cooking main course:"<<dishName<<endl
    }
}

int main()
{
    MenuItem*item1=new Appetizer("Nuggets",500)
    MenuItem*item2=new MainCourse("Chicken Karahi",5000)
    item1->showDetails()
    item1->prepare()
    cout<<endl
    item2->showDetails()
    item2->prepare()
    delete item1
    delete item2
    return 0
}
