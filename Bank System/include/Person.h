#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person{
protected:
    int ID;
    string Name,Password;
public:
    //constructor :
    Person(){
    ID = 0;
    }
    Person(int ID, string Name, string Password){
    this->ID = ID;
    this->Name = Name;
    this->Password = Password;
    }

    //setters :
    void setID(int ID){
    this->ID = ID;
    }
    void setName(string Name){
        ValidName(Name);
        this->Name = Name;
    }
    void setPassword(string Password){
        ValidPassword(Password);
        this->Password = Password;
    }

    //getters :
    int getID(){
    return this->ID;
    }
    string getName(){
    return this->Name;
    }
    string getPassword(){
    return this->Password;
    }

    //methods :
    void ValidName(string Name){
        if(Name.size()>=5&&Name.size()<=20){
            for(int i =0;i<Name.size();i++){
                if(Name[i]>='0'&&Name[i]<='9'){
                    cout<<"Name must be 5 to 20 characters only "<<endl;
                    break;
                }
            }
        }
    }
    void ValidPassword(string Password){
        if(Password.size()<8&&Password.size()>20){
            cout<<"Password must be 8 to 20 characters or numbers "<<endl;
        }
    }

    virtual void PrintINFO()=0;

};

#endif // PERSON_H
