#include <iostream>
#include <cstring> 
using namespace std;

#define OUT_OF_SCHOOL -1
#define YARD 1
#define STAIRS 2
#define FLOOR 3
#define CORR 0
#define CLASSROOM 5

class Person{
    private:
        string name;
        int class_id;
        int floor_id;
        bool classroom;
        int tiredness;
        int position;
    public:
        Person(const string name = "Nothing", const int floor = 0, const int classroom = 0);
        virtual ~Person() = 0;
        string get_name(void);
        int get_class_id(void);
        int get_floor_id(void);
        void set_classroom(const bool pos = true);
        void set_position(const int);
        int get_position(void);
        void add_tiredness(const int);
        virtual void print(void);
        int get_tiredness(void);
};

class Student:public Person{
    public:
        Student(const string name_init = "Nothing", const int floor = 0, const int classroom = 0);
        ~Student();
        void print(void);
};   

class Teacher:public Person{
    public:
        Teacher(const string name_init = "Nothing", const int floor = 0, const int classroom = 0);
        ~Teacher();
        void print(void);
        void place(void);
};  