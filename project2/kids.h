#include <iostream>
#include <cstring>
using namespace std;

class Pair;

class Kid{
    private:
        char* name;
        int gender;
        int classroom;
        Pair* owner;
    public:
        Kid(const char*, const int, const int);
        ~Kid();
        void print(void);
        int get_gender(void);
        int get_classroom(void);
        void set_owner(Pair*);
        Pair* get_owner(void);
};

class Pair{
    private:
        Kid* male;
        Kid* female;
    public:
        Pair();
        ~Pair();
        void set_male(Kid*);
        void set_female(Kid*);
        Kid* get_male(void);
        Kid* get_female(void);
        void swap(int, Pair*);
        void print(void);
        int get_classroom(void);
};
