#include "school.h"

int main(int argc, char* argv[]){

    int Cclass = atoi(argv[1]);
    int Lj = atoi(argv[2]);
    int Ls = atoi(argv[3]);
    int Lt = atoi(argv[4]);
    int N = atoi(argv[5]);

    int T = 18;
    int S = Cclass*18;
    // int S = Cclass;

    School* school = new School(Cclass);

    char* name;
    char buffer[1000];
    int classroom;
    int floor;

    Teacher** teachers = new Teacher*[T];
    for(int i = 0; i < T; i++){
        cin >> buffer >> classroom >> floor;
        name = new char[strlen(buffer) + 1];
        strcpy(name, buffer);
        teachers[i] = new Teacher(name, floor, classroom);
        school->set_teacher(teachers[i]);
        delete[] name;
    }

    Student** students = new Student*[S];
    for(int i = 0; i < S; i++){
        cin >> buffer >> classroom >> floor;
        name = new char[strlen(buffer) + 1];
        strcpy(name, buffer);
        students[i] = new Student(name, floor, classroom);
        delete[] name;
    }

    srand(time(NULL));
    int size = S;
    // for(int i = 0; i < S; i++){
    //     school->enter(students[i], YARD);
    //     school->exit(students[i]);
    //     school->enter(students[i], STAIRS);
    //     school->exit(students[i]);
    //     school->enter(students[i], CORR);
    //     school->exit(students[i]);
    //     school->enter(students[i], CLASSROOM);
    // }
    while(size > 0){
        int j = rand() % S;
        if(students[j]->get_position() == CLASSROOM)
            continue;
        school->enter(students[j], YARD);
        school->exit(students[j]);
        school->enter(students[j], STAIRS);
        school->exit(students[j]);
        school->enter(students[j], CORR);
        school->exit(students[j]);
        bool flag = school->enter(students[j], CLASSROOM);
        if(flag == true){
            size--;
        }
    }

    for(int i = 0; i < T; i++){
        school->place(teachers[i]);
    }

    for(int i = 0; i < N; i++){
        school->operate(Lj, Ls, Lt);
    }

    school->print();

    delete school;
    delete[] teachers;
    delete[] students;

    return 0;
}
