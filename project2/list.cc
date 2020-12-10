// #include "kids.h"
#include "list.h"
#include <iostream>
using namespace std;

node::~node(){
    delete this->value;
}

List::List(){
    this->head = NULL;
    this->tail = NULL;
    this->noise = 0;
    this->size = 0;
    this->classroom = 0;
}

List::~List(){
    node* start = this->gethead();
    while(start != NULL){
        node* nextNode = start->next;
        delete start;
        start = nextNode;
    }
}

int List::get_size(void){
    return this->size;
}

void List::add_node(Pair* pair){
    node* temp = new node;
    temp->value = pair;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = tail->next;
    }
    this->size++;
    if(this->size == 1){
        int classroom = pair->get_classroom();
        this->set_classroom(classroom);
    }
}

node* List::gethead(void){
    return this->head;
}

Pair* List::get_value(node* temp){
    return temp->value;
}

void List::display(node* head){
    while(head != NULL){
        Pair* temp = head->value;
        temp->print();
        head = head->next;
    }
}

node* List::element(node* head, int counter){
    int i = 1;
    while(head != NULL){
        if (i == counter)
            return head;
        Pair* temp = head->value;
        // temp->print();
        head = head->next;
        i++;
    }
    return head;
}

void List::add_noise(int i){
    this->noise += i;
}

int List::get_noise(void){
    return this->noise;
}

void List::set_classroom(int class_init){
    this->classroom = class_init;
}

int List::get_classroom(void){
    return this->classroom;
}

int List::swap(Pair* a, int gender, int classroom){
    srand(time(NULL));
    int temp = rand() % (this->size) + 1;
    Pair* b = this->element(this->gethead(), temp)->value;
    while(b == NULL){
        temp = rand() % (this->size) + 1;
        b = this->element(this->gethead(), temp)->value;     
    }
    this->add_noise(1);
    a->swap(gender, b);
    return b->get_classroom();
}