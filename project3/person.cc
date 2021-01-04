#include "person.h"

Person::Person(const string name, const int floor, const int classroom){
    // cout << "A person with name: " << name << " has been created" << endl;
    this->name = name;
    this->floor_id = floor;
    this->class_id = classroom;
    this->classroom = false;
    this->tiredness = 0;
    this->position = OUT_OF_SCHOOL;
}

Person::~Person(){
    // cout << "A person with name " << this->name << " is about to be destroyed" << endl;
}

string Person::get_name(){
    return this->name;
}

int Person::get_class_id(){
    return this->class_id;
}

int Person::get_floor_id(){
    return this->floor_id;
}

void Person::set_classroom(const bool pos){
    this->classroom = pos;
}

void Person::set_position(const int pos){
    this->position = pos;
}

int Person::get_position(void){
    return this->position;
}

void Person::add_tiredness(const int i){
    this->tiredness += i;
}

void Person::print(void){
    cout << this->name << ", " << this->tiredness << endl;
}

int Person::get_tiredness(void){
    return this->tiredness;
}

Student::Student(const string name_init, const int floor, const int classroom):Person(name_init, floor, classroom){
    cout << "A new student with name: " << name_init << " ,class id: " << classroom << " and floor id: " << floor  <<" has been created" << endl;
}

Student::~Student(){
    cout << "A student with name " << Person::get_name() << " is about to be destroyed" << endl;
}

void Student::print(void){
    Person::print();
}

Teacher::Teacher(const string name_init, const int floor, const int classroom):Person(name_init, floor, classroom){
    if(name_init != "Nothing")
        cout << "A new teacher with name: " << name_init << " ,class id: " << classroom << " and floor id: " << floor  <<" has been created" << endl;
}

Teacher::~Teacher(){
    if(Person::get_name() != "Nothing")
        cout << "A teacher with name: " << Person::get_name() << " is about to be destroyed" << endl;
}

void Teacher::print(void){
    cout << "Teacher: "<< endl;
    Person::print();
}

void Teacher::place(void){
    Person::set_classroom(true);
}