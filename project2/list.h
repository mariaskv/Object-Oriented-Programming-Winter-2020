#include "kids.h"
class node{
    public:
        Pair* value;
        node* next;
        ~node();
};

class List{
    private:
        node* head;
        node* tail;
        int noise;
        int classroom;
        int size;
    public:
        List();
        ~List();
        void add_node(Pair*);
        node* gethead();
        void display(node*);
        Pair* get_value(node*);
        node* element(node*, int);
        void add_noise(int);
        void set_classroom(int);
        int get_classroom(void);
        int get_noise(void);
        int swap(Pair*, int, int);
        int get_size(void);
};