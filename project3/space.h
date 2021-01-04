
#include <iostream>
#include <cstring> 
#include "person.h"
using namespace std;

class Space{
    private:
        Student** students;
        int size;
        int capacity;
    public:
        Space(const int c_init = 0);
        virtual ~Space() = 0;
        virtual void print(void);
        virtual bool enter(Student&);
        virtual Student* exit(Student&);
        Student** get_students(void);
        int get_capacity(void);
};

class Classroom:public Space{
    private:
        Teacher* teacher;
    public:
        Classroom(const int c_init = 0);
        ~Classroom();
        void set_teacher(Teacher&);
        void print(void);
        bool enter(Student&);
        Student* exit(Student&);
        void operate(const int, const int);
};

class Corr:public Space{
    public:
        Corr(const int c_init = 0);
        ~Corr();
        bool enter(Student&);
        Student* exit(Student&);
};

class Stairs:public Space{
    public:
        Stairs(const int c_init = 0);
        ~Stairs();
        bool enter(Student&);
        Student* exit(Student&);
};

class Yard:public Space{
    public:
        Yard(const int c_init = 0);
        ~Yard();
        bool enter(Student&);
        Student* exit(Student&);
};

class Floor{
    private:
        Classroom* class1;
        Classroom* class2;
        Classroom* class3;
        Classroom* class4;
        Classroom* class5;
        Classroom* class6;
        Corr* corr_of_the_floor;
    public:
        Floor(const int c_init = 0);
        ~Floor();
        void set_teacher(Teacher*);
        void print(void);
        bool enter(Student&, const int id = CORR);
        Student* exit(Student&, const int id = CORR);
        void operate(const int, const int, const int);
};
