#include "space.h"

Space::Space(const int c_init){
    // cout << "A new space has been created" << endl;
    this->students = new Student*[c_init];
    for(int i = 0; i < c_init; i++){
        this->students[i] = NULL;
    }
    this->size = 0;
    this->capacity = c_init;
}

Space::~Space(){
    // cout << "A space is about to be destroyed" << endl;
    for(int i = 0; i < this->capacity; i++){
        if(this->students[i] == NULL) //if there is no student at this position do not do nothing
            continue;
        delete this->students[i]; //else delete this student and set this memory block to 0
        this->students[i] = NULL;
    }
    delete[] this->students;
}

void Space::print(void){
    for(int i = 0; i < this->capacity; i++){
        if(students[i] == NULL)
            continue;
        students[i]->print();
    }
}

bool Space::enter(Student& student){
    if(&student == NULL)
        return false;
    if(this->size < this->capacity){
        for(int i = 0; i < this->capacity; i++){
            if(this->students[i] == &student){
                cout << "That students is already in" << endl;
                return false;
            }
            if(this->students[i] == NULL){
                this->students[i] = &student;
                break;
            }
        }
        this->size++;
        return true;
    }
    else{
        cout << "There is no more space in that space" << endl;
        return false;
    }
    return false;
}

Student* Space::exit(Student& student){
    Student* stu = NULL;
    for(int i = 0; i < this->capacity; i++){
        if(this->students[i] == NULL)
            continue;
        if(&student == this->students[i]){
            stu = this->students[i];
            this->students[i] = NULL;
            this->size--;
            return stu;
        }
    }
    cout << "There is no such a student here" << endl;
    return stu;
} 

Student** Space::get_students(void){
    return this->students;
}

int Space::get_capacity(void){
    return this->capacity;
}

Classroom::Classroom(const int c_init):Space(c_init){
    cout << "A new classroom has been created" << endl;
    this->teacher = new Teacher();
}

Classroom::~Classroom(){
    cout << "A classroom is about to be destroyed" << endl;
    delete this->teacher;
}

void Classroom::set_teacher(Teacher& teacher){
    if(&teacher == NULL)
        return;
    delete this->teacher;
    this->teacher = &teacher;
}

void Classroom::print(void){
    this->teacher->print();
    cout << "Students are: " << endl;
    Space::print();
}

bool Classroom::enter(Student& student){
    cout << "A student with name: " << student.get_name() << " enters classroom" << endl;
    bool flag = Space::enter(student);
    return flag;
}

Student* Classroom::exit(Student& student){
    cout << "A student with name: " << student.get_name() << " exits classroom" << endl;
    Student* student_return = Space::exit(student);
    return student_return;
} 

void Classroom::operate(const int  i, const int j){
    this->teacher->add_tiredness(j);
    int capacity = Space::get_capacity();
    Student** students = Space::get_students();
    for(int j = 0; j < capacity; j++){
        if(students[j] == NULL){
            continue;
        }
        students[j]->add_tiredness(i);
    }
}

Corr::Corr(const int c_init):Space(c_init){
    cout << "A new corridor has been created" << endl;
}

Corr::~Corr(){
    cout << "A corridor is about to be destroyed" << endl;
}

bool Corr::enter(Student& student){
    cout << "A student with name: " << student.get_name() << " enters corridor" << endl;
    bool flag = Space::enter(student);
    return flag;
}

Student* Corr::exit(Student& student){
    cout << "A student with name: " << student.get_name() << " exits corridor" << endl;
    Student* student_return = Space::exit(student);
    return student_return;
} 

Stairs::Stairs(const int c_init):Space(c_init){
    cout << "A new stair has been created" << endl;
}

Stairs::~Stairs(){
    cout << "A stair is about to be destroyed" << endl;
}

bool Stairs::enter(Student& student){
    cout << "A student with name: " << student.get_name() << " enters stairs" << endl;
    bool flag = Space::enter(student);
    return flag;
}

Student* Stairs::exit(Student& student){
    cout << "A student with name: " << student.get_name() << " exits stairs" << endl;
    Student* student_return = Space::exit(student);
    return student_return;
} 

Yard::Yard(const int c_init):Space(c_init){
    cout << "A new schoolyard has been created" << endl;
}

Yard::~Yard(){
    cout << "A schoolyard is about to be destroyed" << endl;
}

bool Yard::enter(Student& student){
    cout << "A student with name: " << student.get_name() << " enters yard" << endl;
    bool flag = Space::enter(student);
    return flag;
}

Student* Yard::exit(Student& student){
    cout << "A student with name: " << student.get_name() << " exits yard" << endl;
    Student* student_return = Space::exit(student);
    return student_return;
} 

Floor::Floor(const int c_init){
    cout << "A new floor has been created" << endl;
    this->class1 = new Classroom(c_init);
    this->class2 = new Classroom(c_init);
    this->class3 = new Classroom(c_init);
    this->class4 = new Classroom(c_init);
    this->class5 = new Classroom(c_init);
    this->class6 = new Classroom(c_init);
    this->corr_of_the_floor = new Corr(1);
}

Floor::~Floor(){
    cout << "A floor is about to be destroyed" << endl;
    delete this->class1;
    delete this->class2;
    delete this->class3;
    delete this->class4;
    delete this->class5;
    delete this->class6;
    delete this->corr_of_the_floor;
}

void Floor::set_teacher(Teacher* teacher){
    int id = teacher->get_class_id();
    if(id == 1)
        this->class1->set_teacher(*teacher);
    if(id == 2)
        this->class2->set_teacher(*teacher);
    if(id == 3)
        this->class3->set_teacher(*teacher);
    if(id == 4)
        this->class4->set_teacher(*teacher);
    if(id == 5)
        this->class5->set_teacher(*teacher);
    if(id == 6)
        this->class6->set_teacher(*teacher);
}

void Floor::print(void){
    cout << "People in class 1 are: " << endl;
    class1->print();
    cout << "People in class 2 are: " << endl;
    class2->print();
    cout << "People in class 3 are: " << endl;
    class3->print();
    cout << "People in class 4 are: " << endl;
    class4->print();
    cout << "People in class 5 are: " << endl;
    class5->print();
    cout << "People in class 6 are: " << endl;
    class6->print();
}

bool Floor::enter(Student& student, const int id){
    bool flag;
    if(id == CORR)
        flag = this->corr_of_the_floor->enter(student);
    else if(id == 1)
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

Student* Floor::exit(Student& student, const int id){
    Student* flag = NULL;
    if(id == 0)
        flag = this->corr_of_the_floor->exit(student);
    else if(id ==1)
        flag = this->class1->exit(student);
    else if(id == 2)
         flag = this->class2->exit(student);
    else if(id == 3)
        flag = this->class3->exit(student);
    else if(id == 4)
        flag = this->class4->exit(student);
    else if(id == 5)
        flag = this->class5->exit(student);
    else if(id == 6)
        flag = this->class6->exit(student);
    return flag;
}

void Floor::operate(const int Lj, const int Ls, const int Lt){
    this->class1->operate(Lj, Lt);
    this->class2->operate(Lj, Lt);
    this->class3->operate(Lj, Lt);
    this->class4->operate(Ls, Lt);
    this->class5->operate(Ls, Lt);
    this->class6->operate(Ls, Lt);
}