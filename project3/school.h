#include "space.h"
#include <iostream>
#include <cstring> 
using namespace std;

class School{
    private:
        Yard* yard;
        Stairs* stairs;
        Floor* floor1;
        Floor* floor2;
        Floor* floor3;
    public:
        School(const int c_init = 0);
        ~School();
        void set_teacher(Teacher*);
        void print(void);
        void place(Teacher*);
        bool enter(Student*, const int dest = YARD);
        Student* exit(Student*);
        void operate(const int, const int, const int);
};