#include "school.h"

School::School(const int c_init){
    cout << "A new school has been created" << endl;
    this->yard = new Yard(1);
    this->stairs = new Stairs(1);
    this->floor1 = new Floor(c_init);
    this->floor2 = new Floor(c_init);
    this->floor3 = new Floor(c_init);
}

School::~School(){
    cout << "A school is to be destroyed" << endl;
    delete this->yard;
    delete this->stairs;
    delete this->floor1;
    delete this->floor2;
    delete this->floor3;
}

void School::set_teacher(Teacher* teacher){
    int floor = teacher->get_floor_id();
    if(floor == 1)
        floor1->set_teacher(teacher);
    if(floor == 2)
        floor2->set_teacher(teacher);
    if(floor == 3)
        floor3->set_teacher(teacher);
}

void School::print(void){
    cout << "School life consists of: " << endl;
    cout << "Floor 1 contains: " << endl;
    this->floor1->print();
    cout << "Floor 2 contains: " << endl;
    this->floor2->print();
    cout << "Floor 3 contains: " << endl;
    this->floor3->print();
}

void School::place(Teacher* teacher){
    cout << "Teacher: " << teacher->get_name() << " enters the classroom" << endl;
    teacher->place();
}

bool School::enter(Student* student, int dest){
    bool flag;
    if(dest == YARD){
        flag = this->yard->enter(*student);
    }
    if(dest == STAIRS){
        flag = this->stairs->enter(*student);
    }
    if(dest == CORR || dest == FLOOR){
        dest = CORR;
        int floor = student->get_floor_id();
        if(floor == 1)
            flag = this->floor1->enter(*student, CORR);
        if(floor == 2)
            flag = this->floor2->enter(*student, CORR);
        if(floor == 3)
            flag = this->floor3->enter(*student, CORR);
    }
    if(dest == CLASSROOM){
        int floor = student->get_floor_id();
        int classroom = student->get_class_id();
        if(floor == 1)
            flag = floor1->enter(*student, classroom);
        if(floor == 2)
            flag = floor2->enter(*student, classroom);
        if(floor == 3)
            flag = floor3->enter(*student, classroom);
    }
    if(flag == true){
        student->set_position(dest);
        if(dest == CLASSROOM)
            student->set_classroom(true);
    }
    if(flag == false){
        cout << "Error student returns back" << endl;
        if(student->get_position() == OUT_OF_SCHOOL){
            cout << "There is no more space at the school" << endl;
            return flag;
        }
        if(student->get_position() == YARD){
            cout << "Student is already at the yard" << endl;
            return flag;
        }       
        this->enter(student, student->get_position());
    }
    return flag;
}

Student* School::exit(Student* student){
    Student* flag = NULL;
    int pos = student->get_position();
    if(pos == OUT_OF_SCHOOL)
        return flag;
    if(pos == YARD){
        flag = this->yard->exit(*student);
    }
    if(pos == STAIRS){
        flag = this->stairs->exit(*student);
    }
    if(pos == FLOOR || pos == CORR){
        int floor = student->get_floor_id();
        if(floor == 1)
            flag = this->floor1->exit(*student, CORR);
        if(floor == 2)
            flag = this->floor2->exit(*student, CORR);
        if(floor == 3)
            flag = this->floor3->exit(*student, CORR);
    }
    return flag;
}

void School::operate(const int Lj, const int Ls, const int Lt){
    this->floor1->operate(Lj, Ls, Lt);
    this->floor2->operate(Lj, Ls, Lt);
    this->floor3->operate(Lj, Ls, Lt);
}