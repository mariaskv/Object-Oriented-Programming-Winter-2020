#include <iostream>
#include <cstring>
#include "list_lists.h"
using namespace std;

int main(int argc, char* argv[]){
    int K = atoi(argv[1]);
    int L = atoi(argv[2]);
    float Tquiet;
    sscanf(argv[3],"%f",&Tquiet);
    float Tmessy;
    sscanf(argv[4],"%f",&Tmessy);

    // int N = 57;
    // int M;

    // if(N % 2 == 0)
    //     M = N/2;
    // else
    //     M = N/2 + 1;

    // char* name;
    // char buffer[1000];
    // int classroom;
    // int gender;

    // Kid** kids = new Kid*[N]; 
    // for(int i = 0; i < N; i++){
    //     cin >> buffer >> classroom >> gender;
    //     name = new char[strlen(buffer) + 1];
    //     strcpy(name, buffer);
    //     kids[i] = new Kid(name, gender, classroom);
    //     delete[] name;
    // }


    // List_Lists* list_lists = new List_Lists(M);
    // list_lists->set_values(kids, N, K);

    // list_lists->display(list_lists->gethead());

    // for(int i = 0; i < L; i++){
    //     list_lists->kids_choice(kids, N, M);
    // }

    // list_lists->display(list_lists->gethead());
    // list_lists->noise_print(Tquiet, Tmessy, K);

    // delete list_lists;

    // delete[] kids;

    Kid k = Kid();

    return 0;
}