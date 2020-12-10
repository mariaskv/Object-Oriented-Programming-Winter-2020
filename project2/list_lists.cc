#include "list_lists.h"
#include <iostream>
using namespace std;

nodel::~nodel(){
    delete this->value;
}

List_Lists::List_Lists(int M = 0){
    head = NULL;
    tail = NULL;

    this->pairs = new Pair*[M];
    for(int i = 0; i < M; i++){
        this->pairs[i] = new Pair();
    }

    this->size = 0;
}

List_Lists::~List_Lists(){
    nodel* start = this->gethead();
    while(start != NULL){
        nodel* nextNode = start->next;
        delete start;
        start = nextNode;
    }
    delete[] this->pairs;
}

void List_Lists::set_values(Kid** kids, int N, int K){
    //N number of students
    //K number of different classes
    List** list = new List*[K];
    for(int i = 0; i < K; i++){
        list[i] = new List();
        this->add_node(list[i]);
    }

    int classroom = -1;
    int kids_in_pairs = 0;
    int i = 0, k = 0, j, boy, girl;
    bool flag_boy = false;
    bool flag_girl = false;

    while((kids_in_pairs < N) && (i < N)){
        for(j = i; j < N; j++){  
            if( kids[j]->get_owner() != NULL){
                continue;
            }
            if((kids[j]->get_gender() == GIRL) && (flag_girl == false)){
                if(classroom == -1){
                    classroom = kids[j]->get_classroom();
                }
                if(classroom == kids[j]->get_classroom()){
                    girl = j;
                    flag_girl = true;
                }
            }   
            if((kids[j]->get_gender() == BOY) && (flag_boy == false)){
                if(classroom == -1){
                    classroom = kids[j]->get_classroom();
                }            
                if(classroom == kids[j]->get_classroom()){
                    boy = j;
                    flag_boy = true;
                }
            }  
            if((flag_boy == true) && (flag_girl == true)){
                if(flag_girl == true)
                    pairs[k]->set_female(kids[girl]);
                if(flag_boy == true)
                    pairs[k]->set_male(kids[boy]);
                list[classroom - 1]->add_node(pairs[k]); 
                kids_in_pairs+=2;
                classroom = -1;
                flag_boy = false;
                flag_girl = false;
                k++;
                i++;
                j = 0;
                break;
            } 
        }
        if((j == N) && ((flag_boy == false) || (flag_girl == false))){
            flag_boy = false;
            flag_girl = false; 
            classroom = -1;
            i++;
            continue;
        }

    }

    int classroom1 = -1;
    int classroom2 = -1;
    int Minclassroom = -1;
    flag_boy = false;
    flag_girl = false;
    i = 0;

    while((kids_in_pairs < N) && (i < N)){
        for(j = i; j < N; j++){  
            if(kids[j]->get_owner() != NULL){
                continue;
            }
            if((kids[j]->get_gender() == GIRL) && (flag_girl == false)){
                if(classroom1 == -1){
                    classroom1 = kids[j]->get_classroom();
                }
                    girl = j;
                    flag_girl = true;
            }   
            if((kids[j]->get_gender() == BOY) && (flag_boy == false)){
                if(classroom2 == -1){
                    classroom2 = kids[j]->get_classroom();
                }            
                    boy = j;
                    flag_boy = true;
            }  
            if((flag_boy == true) && (flag_girl == true)){
                if(classroom1 < classroom2)
                    Minclassroom = classroom1;
                if(classroom1 > classroom2)
                    Minclassroom = classroom2;
                if(flag_girl == true)
                    pairs[k]->set_female(kids[girl]);
                if(flag_boy == true)
                    pairs[k]->set_male(kids[boy]);
                list[Minclassroom - 1]->add_node(pairs[k]); 
                classroom1 = -1;
                classroom2 = -1;
                flag_boy = false;
                flag_girl = false;
                kids_in_pairs+=2;
                k++;
                j = 0;
                i++;
                break;
            } 
        }
        if((j == N) && ((flag_boy == false) || (flag_girl == false))){
            flag_boy = false;
            flag_girl = false;          
            i++;
            classroom1 = -1;
            classroom2 = -1;
            continue;
        }
    }
    flag_boy = false;
    flag_girl = false;
    classroom = -1;
    i = 0;

    while((kids_in_pairs < N) && (i < N)){
        for(j = i; j < N; j++){  
            if(kids[j]->get_owner() != NULL){
                continue;
            }
            if((kids[j]->get_gender() == GIRL) && (flag_girl == false)){
                if(classroom == -1){
                    classroom = kids[j]->get_classroom();
                }
                    kids_in_pairs++;
                    girl = j;
                    flag_girl = true;
            }   
            if((kids[j]->get_gender() == BOY) && (flag_boy == false)){
                if(classroom == -1){
                    classroom = kids[j]->get_classroom();
                }            
                    kids_in_pairs++;
                    boy = j;
                    flag_boy = true;
            }  
            if((flag_boy == true) || (flag_girl == true)){
                if(flag_girl == true)
                    pairs[k]->set_female(kids[girl]);
                if(flag_boy == true)
                    pairs[k]->set_male(kids[boy]);
                list[classroom - 1]->add_node(pairs[k]); 
                classroom = -1;
                flag_boy = false;
                flag_girl = false;
                k++;
                j = 0;
                i++;
                break;
            } 
        }
        if((j == N) && ((flag_boy == false) || (flag_girl == false))){
            if(flag_boy == true){
                flag_boy = false;
                kids_in_pairs--;
            }
            if(flag_girl == true){
                flag_girl = false;
                kids_in_pairs--;
            }            
            i++;
            classroom = -1;
            kids_in_pairs++;
            continue;
        }
    }

}

void List_Lists::add_node(List* list){
    nodel* temp = new nodel;
    temp->value = list;
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

}

nodel* List_Lists::gethead(void){
    return this->head;
}

List* List_Lists::get_value(nodel* temp){
    return temp->value;
}

void List_Lists::display(nodel* head){
    while(head != NULL){
        cout << "list" << endl;
        List* temp = head->value;
        temp->display(temp->gethead());
        head = head->next;
    }
}

nodel* List_Lists::element(nodel* head, int counter){
    int i = 1;
    while(head != NULL){
        if (i == counter)
            return head;
        List* temp = head->value;
        head = head->next;
        i++;
    }
    return head;
}

void List_Lists::kids_choice(Kid** kids, int N, int M){
    //N->number of students
    //M->number of pairs
    srand(time(NULL));
    int temp = rand() % 2;
    if(temp == 0){
        //take kids alone
        int L = (rand() % N) + 1;
        Kid** kid_noise = new Kid*[L];
        for(int i = 0; i < L; i++){
            int j = rand() % N;
            kid_noise[i] = kids[j];
        }
        this->noise_kids(kid_noise, L);
        delete[] kid_noise;
    }
    else{
        //take pairs
        int K = (rand() % M) + 1;
        Pair** pair_noise = new Pair*[K];
        for(int i = 0; i < K; i++){
            int j = rand() % M;
            pair_noise[i] = this->pairs[j];
        }
        if(K <= 2){
            Kid** kid_noise = new Kid*[K*2];
            int y = 0;
            for(int i = 0; i < K*2; i += 2){
                kid_noise[i] = pair_noise[y]->get_male();
                kid_noise[i+1] = pair_noise[y]->get_female();
                y++;
            } 
            this->noise_kids(kid_noise, K*2);
            delete[] kid_noise;
        }
        else{
            bool flag = true;
            int classroom = pair_noise[0]->get_classroom();
            for(int i = 0; i < K; i++){
                if(pair_noise[i]->get_classroom() != classroom){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                //diadoxika
                Kid** kid_noise = new Kid*[K*2];
                int y = 0;
                for(int i = 0; i < K*2; i += 2){
                    kid_noise[i] = pair_noise[y]->get_male();
                    kid_noise[i+1] = pair_noise[y]->get_female();
                    y++;
                }
                this->noise_kids_in_line(kid_noise, K*2); 
                delete[] kid_noise;
            }
            else{
                //mi diadoxika
                Kid** kid_noise = new Kid*[K*2];
                int y = 0;
                for(int i = 0; i < K*2; i += 2){
                    kid_noise[i] = pair_noise[y]->get_male();
                    kid_noise[i+1] = pair_noise[y]->get_female();
                    y++;
                }
                this->noise_kids_not_in_line(kid_noise, K*2); 
                delete[] kid_noise;
            }
        }
    }
}

void List_Lists::swap(Pair* a, int classroom, int gender){
    List* list = this->element(this->gethead(), classroom)->value;
    if(list->get_size() == 0)
        return;
    list->add_noise(1);
    int b = list->swap(a, gender, classroom);
    List* l = this->element(this->gethead(), b)->value;
    cout << "Sequences that changed" << endl;
    cout << "First" << endl;
    list->display(list->gethead());
    cout << "Second" << endl;
    l->display(l->gethead());
}

void List_Lists::swap_not_in_line(Pair* a, int classroom, int gender){
    if(classroom == 6)
        classroom = 1;
    else
        classroom++;
    List* list = this->element(this->gethead(), classroom)->value;
    if(list->get_size() == 0)
        return;
    list->add_noise(2);
    int b = list->swap(a, gender, classroom);
    List* l = this->element(this->gethead(), b)->value;
    cout << "Sequences that changed" << endl;
    cout << "First" << endl;
    list->display(list->gethead());
    cout << "Second" << endl;
    l->display(l->gethead());
}

void List_Lists::swap_in_line(Pair* a, int gender){
    int classroom = rand() % this->size;
    List* list = this->element(this->gethead(), classroom + 1)->value;
    if(list->get_size() == 0)
        return;
    list->add_noise(2);
    int b = list->swap(a, gender, classroom);
    List* l = this->element(this->gethead(), b)->value;
    cout << "Sequences that changed" << endl;
    cout << "First" << endl;
    list->display(list->gethead());
    cout << "Second" << endl;
    l->display(l->gethead());
}

void List_Lists::noise_kids(Kid** kids, int N){
    // if(N <= 2){
        for(int i = 0; i < N; i++){
            if(kids[i] == NULL)
                continue;
            Pair* pair = kids[i]->get_owner();
            if(pair == NULL)
                continue;
            int classroom = kids[i]->get_classroom(); 
            int gender = kids[i]->get_gender();
            this->swap(pair, classroom, gender);
        }
    // }
}

void List_Lists::noise_kids_not_in_line(Kid** kids, int N){
    // if(N <= 2){
        for(int i = 0; i < N; i++){
            if(kids[i] == NULL)
                continue;
            Pair* pair = kids[i]->get_owner();
            if(pair == NULL)
                continue;
            int classroom = kids[i]->get_classroom(); 
            int gender = kids[i]->get_gender();
            this->swap_not_in_line(pair, classroom, gender);
        }
    // }
}

void List_Lists::noise_kids_in_line(Kid** kids, int N){
    // if(N <= 2){
        for(int i = 0; i < N; i++){
            if(kids[i] == NULL)
                continue;
            Pair* pair = kids[i]->get_owner();
            if(pair == NULL)
                continue;
            // int classroom = rand() % this->size; 
            int gender = kids[i]->get_gender();
            this->swap_in_line(pair, gender);
        }
}

void List_Lists::noise_print(float Tquiet, float Tmessy, int K){
    for(int i = 1; i <= K; i++){
        List* list = this->element(this->gethead(), i)->value;
        int sound = list->get_noise();
        if(sound == 0){
            cout << "Classroom" << i << endl;
            cout << "Please, be quiet!" << endl;
            continue;
        }
        float noise;
        int N = list->get_size();
        if(sound != 0)
            noise = (1.0)*N/sound;
        cout << "Classroom" << i << endl;
        if(noise <= Tquiet)
            cout << "What a quiet class" << endl;
        else if(noise >= Tmessy)
            cout << "What a mess" << endl;
        else
            cout << "Please, be quiet!" << endl;
    }
}
