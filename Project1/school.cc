#include <iostream>
#include <cstring>
using namespace std;

#define OUT_OF_SCHOOL -1
#define CORR 0
#define YARD 1
#define STAIRS 2
#define FLOOR 3
#define CLASS 4


class Student{
    private:
        char* name; //name 
        int class_id, floor_id; //classroom and floor id
        int student_position; //current position
    public:
        Student(const char* init_name = "Name", const int c_init = 0, const int f_init = 0, int pos_init = OUT_OF_SCHOOL){
            if(strcmp(init_name,"Name") != 0)
                cout << "A new student has been created " << endl;
            name = new char[strlen(init_name) + 1];
            strcpy(name, init_name);
            class_id = c_init;
            floor_id = f_init;
            student_position = pos_init;
        }

        ~Student(){
            // cout << "A student is about to be destroyed" << endl;
            delete[] this->name;
        }

        int getClass_id(void){
            return this->class_id;
        }

        int getFloor_id(void){
            return this->floor_id;
        }

        char* get_name(void){
            return this->name;
        }

        int getPos_id(void){
            return this->student_position;
        }

        void print(void){
            cout << "Student: " << this->name << endl;
        }

        void set(int i){
            this->student_position = i;
        }
};

class Teacher{
    private:
        char* name; //name
        int class_id, floor_id; //class id
        bool flag_teacher; //is it or not in the class
    public:
        Teacher(const char* init_name = "Name", const int c_init = 0, const int f_init = 0, bool flag_init = false){
            if(strcmp(init_name,"Name") != 0)
                cout << "A new teacher has been created" << endl;
            name = new char[strlen(init_name) + 1];
            strcpy(name, init_name);
            class_id = c_init;
            floor_id = f_init;
            flag_teacher = flag_init;
        }

        ~Teacher(){
            // cout << "A teacher is about to be destroyed" << endl;
            delete[] this->name;
        }

        void print(void){
        if(strcmp(this->name,"Name") != 0)            
            cout << "The teacher is:" <<  this->name << endl;
        else
            cout << "There is no teacher in this classroom" << endl;
        }

        char* get_name(void){
            return this->name;
        }

        int get_class_id(void){
            return this->class_id;
        }

        int get_floor_id(void){
            return this->floor_id;
        }

        bool get_flag(void){
            return this->flag_teacher;
        }

        void place(void){
            this->flag_teacher = true;
        }
};

class Classroom{
    private:
        Teacher* teacher;
        Student** students_classroom; 
        int size; //how many students are in the classroom
        int capacity; //max capacity of the classroom
    public:
        Classroom(const int c_init = 0){
            this->teacher = new Teacher();
            cout << "A new class has been created!" << endl;
            this->students_classroom = new Student*[c_init];
            for(int i = 0; i < c_init; i++){
                this->students_classroom[i] = NULL;
            }
            this->size = 0;
            this->capacity = c_init;
        }   

        ~Classroom(){
            delete this->teacher;
            this->teacher = NULL;
            // cout << "A classroom is about to be destroyed" << endl;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_classroom[i] == NULL)
                    continue;
                delete this->students_classroom[i];
                this->students_classroom[i] = NULL;
            }
                delete[] students_classroom;
        } 

        void set_teacher(Teacher& teacher){
            delete this->teacher;
            if(&teacher == NULL)
                return;
            this->teacher = &teacher;
        }

        void print(void){
            this->teacher->print();            
            if(size == 0){
                cout << "The classroom is empty " << endl; 
                return;
            }
            cout << "People in class" << " " << "are:" << endl;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_classroom[i] != NULL)
                    this->students_classroom[i]->print();
            }
        }

        void place(void){
            this->teacher->place();
        }

        bool enter(Student& student){
            if(&student == NULL)
                return false;
            bool flag = this->teacher->get_flag();
            if(this->size < this->capacity && flag == false){
                for(int i = 0; i < this->capacity; i++){
                    if(this->students_classroom[i] == NULL){
                        this->students_classroom[i] = &student;
                        this->students_classroom[i]->set(CLASS);
                        break;
                    }
                    if(this->students_classroom[i] == &student){
                        cout << "Already here" << endl;
                        return true;
                    }
                }
                this->size ++;
                return true;                
            }
            else
                cout << "There is no more space in this classroom or the teacher is already in" << endl;
                return false;
        }

        Student* exit(char* name){
            Student* student;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_classroom[i] == NULL)
                    continue;
                if(strcmp(name, this->students_classroom[i]->get_name()) == 0){
                    student = this->students_classroom[i];
                    this->students_classroom[i] = NULL;
                    this->size --;
                    return student;
                }
            }
            cout << "There is not such a student here" << endl;
            return NULL;
        }
};

class Corr{
    private:
        Student** students_corr;
        int size;
        int capacity;
    public:
        Corr(const int c_init = 0){
            cout << "A new corridor has been created!" << endl;
            this->students_corr = new Student*[c_init];
            for(int i = 0; i < c_init; i++){
                this->students_corr[i] = NULL;
            }
            this->size = 0;
            this->capacity = c_init;
        }      
        
        ~Corr(){
            // cout << "A corr is about to be destroyed" << endl;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_corr[i] == NULL)
                    continue;
                delete this->students_corr[i];
                this->students_corr[i] = NULL;
            }
                delete[] students_corr;
        } 

        void print(void){
            cout << "People in corridor are:" << endl;
            if(size == 0){
                cout << "The corridor is empty" << endl; 
                return;
            }
            for(int i = 0; i < this->capacity; i++){
                if(this->students_corr[i] != NULL)
                    this->students_corr[i]->print();
            }           
        }

        bool enter(Student& student){
            if(&student == NULL)
                return false;
            if(this->size < this->capacity){
                for(int i = 0; i < this->capacity; i++){
                    if(this->students_corr[i] == NULL){
                        this->students_corr[i] = &student;
                        this->students_corr[i]->set(CORR);
                        break;
                    }
                    if(this->students_corr[i] == &student){
                        cout << "Already here" << endl;
                        return true;
                    }
                }
                this->size ++;                
                return true;
            }
            else
                cout << "There is no more space in this corr" << endl;
                return false;
        }

        Student* exit(char* name){
            Student* student;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_corr[i] == NULL)
                    continue;
                if(strcmp(name, this->students_corr[i]->get_name()) == 0){
                    student = this->students_corr[i];
                    this->students_corr[i] = NULL;
                    this->size --;
                    return student;
                }
            }
            cout << "There is not such a student here" << endl;
            return NULL;
        }
};

class Floor{
    private:
        Corr* corr_of_the_floor;
        Classroom* class1;
        Classroom* class2;
        Classroom* class3;
        Classroom* class4;
        Classroom* class5;
        Classroom* class6;
    public:
        Floor(int class_capacity = 0, int corr_capacity = 0){
            cout << "A new floor has been created!" << endl;
            this->corr_of_the_floor  = new Corr(corr_capacity);
            this->class1 = new Classroom(class_capacity);
            this->class2 = new Classroom(class_capacity);
            this->class3 = new Classroom(class_capacity);
            this->class4 = new Classroom(class_capacity);
            this->class5 = new Classroom(class_capacity);
            this->class6 = new Classroom(class_capacity);
        }

        ~Floor(){
            // cout << "A floor is about to be destroyed" << endl;
            delete this->class1;
            delete this->class2;
            delete this->class3;
            delete this->class4;
            delete this->class5;
            delete this->class6;
            delete this->corr_of_the_floor;
        }

        void print(void){
            cout << "Floor number" << " " <<  "contains:" << endl;
            this->corr_of_the_floor->print();
            this->class1->print();
            this->class2->print();
            this->class3->print();
            this->class4->print();
            this->class5->print();
            this->class6->print();
        }

        void put(Teacher &teacher, int c_id){
            if(c_id == 1)
                this->class1->set_teacher(teacher);
            if(c_id == 2)
                this->class2->set_teacher(teacher);
            if(c_id == 3)
                this->class3->set_teacher(teacher);
            if(c_id == 4)
                this->class4->set_teacher(teacher);
            if(c_id == 5)
                this->class5->set_teacher(teacher);
            if(c_id == 6)
                this->class6->set_teacher(teacher);
        }

        bool enter(Student& student, int id = CORR){
            bool flag = false;
            if(id == 0)
                flag = this->corr_of_the_floor->enter(student);
            else if(id ==1)
                flag = this->class1->enter(student);
            else if(id == 2)
                flag = this->class2->enter(student);
            else if(id == 3)
                flag = this->class3->enter(student);
            else if(id == 4)
                flag = this->class4->enter(student);
            else if(id == 5)
                flag = this->class5->enter(student);
            else if(id == 6)
                flag = this->class6->enter(student);
            return flag;
        }

        Student* exit(int id, char* name){
            Student* student = NULL;
            if(id == 0)
                student = this->corr_of_the_floor->exit(name);
            else if(id ==1)
                 student = this->class1->exit(name);
            else if(id == 2)
                student = this->class2->exit(name);
            else if(id == 3)
                student = this->class3->exit(name);
            else if(id == 4)
                student = this->class4->exit(name);
            else if(id == 5)
                student = this->class5->exit(name);
            else if(id == 6)
                student = this->class6->exit(name);

            return student;
        }

        void place(int classroom){
            if(classroom == 1)
                this->class1->place();
            else if(classroom == 2)
                this->class2->place();
            else if(classroom == 3)
                this->class3->place();
            else if(classroom == 4)
                this->class4->place();
            else if(classroom == 5)
                this->class5->place();
            else
                this->class6->place();
        }
};

class Stair{
    private:
        Student** students_stair;
        int size;
        int capacity;
    public:
        Stair(const int c_init = 0){
            cout << "A new stair has been created!" << endl;
            this->students_stair = new Student*[c_init];
            for(int i = 0; i < c_init; i++){
                this->students_stair[i] = NULL;
            }
            this->size = 0;
            this->capacity = c_init;
        }

        ~Stair(){
            // cout << "Stairs is about to be destroyed" << endl;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_stair[i] == NULL)
                    continue;
                delete this->students_stair[i];
                this->students_stair[i] = NULL;
            }
                delete[] students_stair;
        }        

        void print(){
            cout << "People in stairs are:" << endl;
            if(this->size == 0){
                cout << "The stairs are empty" << endl;
                return;
            }
            for(int i = 0; i < this->capacity; i++){
                if(students_stair[i] != NULL){
                    students_stair[i]->print();
                }
            }
        }

        bool enter(Student& student){
            if(&student == NULL)
                return false;;
            if(this->size < this->capacity){
                for(int i = 0; i < this->capacity; i++){
                    if(this->students_stair[i] == NULL){
                        this->students_stair[i] = &student;
                        this->students_stair[i]->set(STAIRS);
                        break;
                    }
                    if(this->students_stair[i] == &student){
                        cout << "Already here" << endl;
                        return true;
                    }
                }
                this->size ++; 
                return true;               
            }
            else
                cout << "There is no more space in this stair" << endl;
                return false;
        }

        Student* exit(char* name){
            Student* student;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_stair[i] == NULL)
                    continue;
                if(strcmp(name, this->students_stair[i]->get_name()) == 0){
                    student = this->students_stair[i];
                    this->students_stair[i] = NULL;
                    this->size --;
                    return student;
                }
            }
            cout << "There is not such a student here" << endl;
            return NULL;
        }
};

class Yard{
    private:
        Student** students_yard;
        int size;
        int capacity;
    public:
        Yard(const int c_init = 0){
            cout << "A new yard has been created!" << endl;
            this->students_yard = new Student*[c_init];
            for(int i = 0; i < c_init; i++){
                // this->students_yard[i] = new Student();
                this->students_yard[i] = NULL;
            }
            this->size = 0;
            this->capacity = c_init;
        }

        ~Yard(){
            // cout << "A yard is about to be destroyed" << endl;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_yard[i] == NULL)
                    continue;
                delete this->students_yard[i];
                this->students_yard[i] = NULL;
            }
                delete[] students_yard;
        } 

        void print(void){
            cout << "People in schoolyard are:" << endl;
            for(int i = 0; i < this->capacity; i++){
                if(students_yard[i] != NULL){
                    students_yard[i]->print();
                }
            }                
        }

        bool enter(Student& student){
            if(&student == NULL)
                return false;
            if(this->size < this->capacity){
                for(int i = 0; i < this->capacity; i++){
                    if(this->students_yard[i] == NULL){
                        this->students_yard[i] = &student;
                        this->students_yard[i]->set(YARD);
                        break;
                    }
                    if(this->students_yard[i] == &student){
                        cout << "Already here" << endl;
                        return true;
                    }
                }
                this->size ++;                
                return true;
            }
            else
                cout << "There is no more space in this corr" << endl;
                return false;
        }

        Student* exit(char* name){
            Student* student;
            for(int i = 0; i < this->capacity; i++){
                if(this->students_yard[i] == NULL)
                    continue;
                if(strcmp(name, this->students_yard[i]->get_name()) == 0){
                    student = this->students_yard[i];
                    this->students_yard[i] = NULL;
                    this->size --;
                    return student;
                }
                else
                    continue;
            }
            cout << "There is not such a student here" << endl;
            return NULL;
        }
};

class School{
    private:
        Stair *stairs;
        Yard *yard;
        Floor *floor1;
        Floor *floor2;
        Floor *floor3;
    public:
        School(int class_capacity, int corr_capacity, int yard_capacity, int stairs_capacity){
            cout << "A new School has been created!" << endl;
            this->stairs = new Stair(stairs_capacity);
            this->yard = new Yard(yard_capacity);
            this->floor1 = new Floor(class_capacity, corr_capacity);
            this->floor2 = new Floor(class_capacity, corr_capacity);
            this->floor3 = new Floor(class_capacity, corr_capacity);
        }

        ~School(){
            // cout << "A school is about to be destroyed" << endl;
            delete this->stairs;
            delete this->yard;
            delete this->floor1;           
            delete this->floor2;            
            delete this->floor3;            
        }

        void print(void){
          cout << "School life consists of:" << endl;
          this->yard->print();

          this->stairs->print(); 

          this->floor1->print();

          this->floor2->print();

          this->floor3->print();
        }
 
        bool enter(Student* student, int dest = YARD){ 
            int current_pos = student->getPos_id();
            bool flag;
            if(dest == 1){
                flag = this->yard->enter(*student); 
            }
            else if(dest == 2){
                flag = this->stairs->enter(*student);
            }
            else if(dest == 3 || dest == 0){ //floor
                int f_id = student->getFloor_id();
                if(f_id == 1){
                    flag = this->floor1->enter(*student, CORR);
                }
                if(f_id == 2){
                    flag = this->floor2->enter(*student, CORR);
                }
                if(f_id == 3){
                    flag = this->floor3->enter(*student, CORR);
                }
            }
            else if(dest == 4){
                int f_id = student->getFloor_id();
                int c_id = student->getClass_id();
                if(f_id == 1){
                    flag = this->floor1->enter(*student, c_id);
                }
                if(f_id == 2){
                    flag = this->floor2->enter(*student, c_id);
                }
                if(f_id == 3){
                    flag = this->floor3->enter(*student, c_id);
                }
            }
            if(flag == false){
                cout << "Error student returns back" << endl;
                if(student->getPos_id() == -1){
                    cout << "There is no space at school for that student" << endl;
                    return true;
                }
                this->enter(student, student->getPos_id());
                return false;
            }
            return true;
        }

        void exit(Student* stu){
            int id_exit = stu->getPos_id();
            char* name = stu->get_name();
            if(id_exit == 1){
                this->yard->exit(name);
            }
            else if(id_exit == 2){
                this->stairs->exit(name);
            }
            else if(id_exit == 3 || id_exit == 0){
                int pos = stu->getPos_id();
                int floor_id = stu->getFloor_id();
                if(floor_id ==1){
                    // int class_pos = stu->getClass_id();
                    this->floor1->exit(pos, name);
                    return;
                }
                else if(floor_id ==2){
                    // int class_pos = stu->getClass_id();
                    this->floor2->exit(pos, name);
                    return;
                }
                else if(floor_id ==3){
                    // int class_pos = stu->getClass_id();
                    this->floor3->exit(pos, name);
                    return;
                }
            }
            else if(id_exit == 4){
                int pos = stu->getPos_id();
                int floor_id = stu->getFloor_id();
                if(floor_id ==1){
                    this->floor1->exit(0, name);
                    return;
                }
                if(floor_id ==2){
                    this->floor2->exit(0, name);
                    return;
                }
                if(floor_id ==3){
                    this->floor3->exit(0, name);
                    return;
                }
            }
        }
        void place(Teacher* teacher){
            int floor = teacher->get_floor_id();
            int classroom = teacher->get_class_id();
            if(floor == 1)
                this->floor1->place(classroom);
            else if(floor == 2)
                this->floor2->place(classroom);
            else if(floor == 3)
                this->floor3->place(classroom);
        }

        void put_teacher(Teacher* teacher){
            int f_id = teacher->get_floor_id();
            int c_id = teacher->get_class_id();
            if(f_id == 1)
                this->floor1->put(*teacher, c_id);
            if(f_id == 2)
                this->floor2->put(*teacher, c_id);
            if(f_id == 3)
                this->floor3->put(*teacher, c_id);                
        }

};

int main(int argc, char* argv[]){

    int Cclass = atoi(argv[1]);
    int Cyard = atoi(argv[2]);
    int Cstair = atoi(argv[3]);
    int Ccorr = atoi(argv[4]);
    int N = Cyard;
    if(N < Cclass)  
        N = Cclass;
    if(N < Cstair)
        N = Cstair;
    if(N < Ccorr)
        N = Ccorr;

    char* name;
    char buffer[1000];
    int classroom;
    int floor;

    School* school = new School(Cclass, Ccorr, Cstair, Cyard);

    Teacher** teachers = new Teacher*[18];
    for(int i = 0; i < 18; i++){
        cin >> buffer >> classroom >> floor;
        name = new char[strlen(buffer) + 1];
        strcpy(name, buffer);
        teachers[i] = new Teacher(name, classroom, floor);
        school->put_teacher(teachers[i]);
        delete name;
    }

    Student** students = new Student*[N];
    for(int i = 0; i < N; i++){
        cin >> buffer >> classroom >> floor;
        name = new char[strlen(buffer) + 1];
        strcpy(name, buffer);
        students[i] = new Student(name, classroom, floor);
        delete name;
    }

    bool flag;

    for(int i = 0; i < Cyard; i++){
        flag = school->enter(students[i], YARD);
        if(flag == false && Cyard > N)
            break;
    }

    for(int i = 0; i < Cstair; i++){
        school->exit(students[i]);
        flag = school->enter(students[i], STAIRS);
        if(flag == false && Cstair > N)
            break;      
    }

    for(int i = 0; i < Ccorr; i++){
        school->exit(students[i]);
        flag = school->enter(students[i], FLOOR);
        if(flag == false && Ccorr > N)
            break;      
    }

    school->place(teachers[0]);
    school->place(teachers[1]);
    school->place(teachers[3]);
    school->place(teachers[5]);
    school->place(teachers[7]);


    for(int i = 0; i < Cclass; i++){
        school->exit(students[i]);
        flag = school->enter(students[i], CLASS);
        // cout << flag << endl;
        if(flag == false && Cclass > N)
            break;       
    }

    school->print();

    delete school;
    delete[] teachers;
    delete[] students;
 
    return 0;
}