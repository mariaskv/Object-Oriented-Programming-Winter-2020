#include <iostream>
#include <cstring>
#include "kids.h"
using namespace std;

#define UNKNOWN -1
#define BOY 0
#define GIRL 1


Kid::Kid(const char* name_init = "Name", const int gender_init = UNKNOWN, const int classroom_init = -1){
    this->name = new char[strlen(name_init)+1];
    strcpy(this->name, name_init);
    this->gender = gender_init;
    this->classroom = classroom_init;
    // this->owner = new Pair();
    this->owner = NULL;
}
        
Kid::~Kid(){
    delete[] this->name;
}

void Kid::print(void){
    if(this == NULL)
        return;
    cout << this->name << " " << this->gender << " " << this->classroom << endl;
}

int Kid::get_gender(void){
    return this->gender;
}

int Kid::get_classroom(void){
    if(this == NULL)
        return -1;
    return this->classroom;
}

void Kid::set_owner(Pair* temp){
    this->owner = temp;
}

Pair* Kid::get_owner(void){
    if(this->owner == NULL)
        return NULL;
    return this->owner;
}

Pair::Pair(){
    this->male = NULL;
    this->female = NULL;
}

Pair::~Pair(){
        delete this->male;

        delete this->female;
}

void Pair::set_male(Kid* kid1){
    // delete this->male;
    this->male = kid1;
    kid1->set_owner(this);
}

void Pair::set_female(Kid* kid1){
    // delete this->female;
    this->female = kid1;
    kid1->set_owner(this);
}

Kid* Pair::get_male(void){
    return this->male;
}

Kid* Pair::get_female(void){
    return this->female;
}

void Pair::swap(int gender, Pair* pair){
    if(gender == BOY){
        Kid* temp = this->male;
        this->male = pair->male;
        pair->male = temp;
    }
    else if(gender == GIRL){
        Kid* temp = this->female;
        this->female = pair->female;
        pair->female = temp;
    }
}

void Pair::print(void){
    cout << "pair" << endl;
    if(this->male != NULL)
        this->male->print();
    else
        cout << "NULL" << endl;
    if(this->female != NULL)
        this->female->print();
    else
        cout << "NULL" << endl;
}

int Pair::get_classroom(void){
    if(this->male != NULL)
        return this->male->get_classroom();
    return this->female->get_classroom();
}


