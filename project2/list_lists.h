#include "list.h"

#define UNKNOWN -1
#define BOY 0
#define GIRL 1

class nodel{
    public:
        List* value;
        nodel* next;
        ~nodel();
};

class List_Lists{
    private:
        nodel* head;
        nodel* tail;
        Pair** pairs;
        int size;
    public:
        List_Lists(int);
        ~List_Lists();
        void add_node(List*);
        nodel* gethead();
        void display(nodel*);
        List* get_value(nodel*);
        nodel* element(nodel*, int);
        void set_values(Kid**, int, int);
        void swap(Pair*, int, int);
        void swap_not_in_line(Pair*, int, int);
        void swap_in_line(Pair*, int);
        void noise_kids(Kid**, int);
        void kids_choice(Kid**, int, int);
        void noise_kids_not_in_line(Kid**, int);
        void noise_kids_in_line(Kid**, int);
        void noise_print(float, float, int);
};
