import java.util.*;
public class Floor{
    Classroom class1;
    Classroom class2;
    Classroom class3;
    Classroom class4;
    Classroom class5;
    Classroom class6;
    Corr corr_of_the_floor;

    public Floor(int c_init){
        System.out.println("A new floor has been created");
        class1 = new Classroom(c_init);
        class2 = new Classroom(c_init);
        class3 = new Classroom(c_init);
        class4 = new Classroom(c_init);
        class5 = new Classroom(c_init);
        class6 = new Classroom(c_init);
        corr_of_the_floor = new Corr(1);
    }

    public void print(){
        System.out.println("People in class 1 are: ");
        class1.print();
        System.out.println("People in class 2 are: ");
        class2.print();
        System.out.println("People in class 3 are: ");
        class3.print();
        System.out.println("People in class 4 are: ");
        class4.print();
        System.out.println("People in class 5 are: ");
        class5.print();
        System.out.println("People in class 6 are: ");
        class6.print();
    }

    public boolean enter(Student student, int id){
        boolean flag = false;
        if(id == Globals.CORR)
            flag = corr_of_the_floor.enter(student);
        else if(id == 1)
            flag = class1.enter(student);
        else if(id == 2)
            flag = class2.enter(student);
        else if(id == 3)
            flag = class3.enter(student);
        else if(id == 4)
            flag = class4.enter(student);
        else if(id == 5)
            flag = class5.enter(student);
        else if(id == 6)
            flag = class6.enter(student);
        return flag;
    }

    public Student exit(Student student, int id){
        Student flag = null;
        if(id == 0)
            flag = corr_of_the_floor.exit(student);
        else if(id == 1)
            flag = class1.exit(student);
        else if(id == 2)
            flag = class2.exit(student);
        else if(id == 3)
            flag = class3.exit(student);    
        else if(id == 4)
            flag = class4.exit(student);
        else if(id == 5)
            flag = class5.exit(student);
        else if(id == 6)
            flag = class6.exit(student);
        return flag;
    }

    public void operate(int Lj, int Ls, int Lt){
        class1.operate(Lj, Lt);
        class2.operate(Lj, Lt);
        class3.operate(Lj, Lt);
        class4.operate(Ls, Lt);
        class5.operate(Ls, Lt);
        class6.operate(Ls, Lt);
    }

    public void set_teacher(Teacher teacher){
        int id = teacher.get_class_id();
        if(id == 1)
            class1.set_teacher(teacher);
        if(id == 2)
            class2.set_teacher(teacher);
        if(id == 3)
            class3.set_teacher(teacher);
        if(id == 4)
            class4.set_teacher(teacher);
        if(id == 5)
            class5.set_teacher(teacher);
        if(id == 6)
            class6.set_teacher(teacher);
    }

    void remove_teacher(int id){
        if(id == 1)
            class1.remove_teacher();
        if(id == 2)
            class2.remove_teacher();
        if(id == 3)
            class3.remove_teacher();
        if(id == 4)
            class4.remove_teacher();
        if(id == 5)
            class5.remove_teacher();
        if(id == 6)
            class6.remove_teacher();       
    }

    public ArrayList<Student> get_students(int i){
        if(i == 1){
            return class1.get_students();
        }
        if(i == 2){
            return class2.get_students();
        }
        if(i == 3){
            return class3.get_students();
        }
        if(i == 4){
            return class4.get_students();
        }
        if(i == 5){
            return class5.get_students();
        }
        if(i == 6){
            return class6.get_students();
        }
        return null;
    }

}