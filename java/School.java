import java.util.ArrayList;

public class School{
    Yard yard;
    Stairs stairs;
    Floor floor1;
    Floor floor2;
    Floor floor3;

    public School(int c_init){
        System.out.println("A new school has been created");
        yard = new Yard(1);
        stairs = new Stairs(1);
        floor1 = new Floor(c_init);
        floor2 = new Floor(c_init);
        floor3 = new Floor(c_init);
    }
    
    public void set_teacher(Teacher teacher){
        int floor = teacher.get_floor_id();
        if(floor == 1)
            floor1.set_teacher(teacher);
        if(floor == 2)
            floor2.set_teacher(teacher);
        if(floor == 3)
            floor3.set_teacher(teacher);
    }

    public void print(){
        System.out.println("School life consists of: ");
        System.out.println("Floor 1 contains: ");
        floor1.print();
        System.out.println("Floor 2 contains: ");
        floor2.print();
        System.out.println("Floor 3 contains: ");
        floor3.print();
    }

    public void place(Teacher teacher){
        System.out.println("Teacher: " + teacher.get_name() + " enters classroom");
        teacher.place();
    }

    boolean enter(Student student, int dest){
        boolean flag = false;
        if(dest == Globals.YARD)
            flag = yard.enter(student);
        else if(dest == Globals.STAIRS)
            flag = stairs.enter(student);    
        else if(dest == Globals.FLOOR || dest == Globals.CORR){
            int floor = student.get_floor_id();
            if(floor == 1)
                flag = floor1.enter(student, Globals.CORR);
            if(floor == 2)
                flag = floor2.enter(student, Globals.CORR);
            if(floor == 3)
                flag = floor3.enter(student, Globals.CORR);
        }
        else if(dest == Globals.CLASSROOM){
            int floor = student.get_floor_id();
            int classroom = student.get_class_id();
            if(floor == 1)
                flag = floor1.enter(student, classroom);
            if(floor == 2)
                flag = floor2.enter(student, classroom);
            if(floor == 3)
                flag = floor3.enter(student, classroom);        
        }
        if(flag == true){
            if(dest == Globals.CLASSROOM)
                student.set_classroom(true);    
            student.set_position(dest);
            return flag;
        }
        else{
            System.out.println("Error student returns back");
            if(student.get_position() == Globals.OUT_OF_SCHOOL){
                System.out.println("There is no more space at the school");
                return flag;
            }
            else if(student.get_position() == Globals.YARD){
                System.out.println("Student is already at the yard");
                return flag;               
            }
            else{
                System.out.println(student.get_position());
                enter(student, student.get_position());
                return flag;
            }
        }
    }

    public Student exit(Student student){
        Student flag = null;
        int pos = student.get_position();
        if(pos == Globals.OUT_OF_SCHOOL)   
            return flag;
        else if(pos == Globals.YARD)
            flag = yard.exit(student);
        else if(pos == Globals.STAIRS)
            flag = stairs.exit(student);
        else if(pos == Globals.FLOOR || pos == Globals.CORR){
            int floor = student.get_floor_id();
            if(floor == 1)
                flag = floor1.exit(student, Globals.CORR);
            if(floor == 2)
                flag = floor2.exit(student, Globals.CORR);
            if(floor == 3)
                flag = floor3.exit(student, Globals.CORR);
        }
        else if(pos == Globals.CLASSROOM){
            int floor = student.get_floor_id();
            int classroom = student.get_class_id();
            if(floor == 1)
                flag = floor1.exit(student, classroom);
            if(floor == 2)
                flag = floor2.exit(student, classroom);
            if(floor == 3)
                flag = floor3.exit(student, classroom);
        }
        return flag;
    }

    public void operate(int Lj, int Ls, int Lt){
        floor1.operate(Lj, Ls, Lt);
        floor2.operate(Lj, Ls, Lt);
        floor3.operate(Lj, Ls, Lt);
    }

    public void remove(ArrayList<Student> s){
        while(s.size() > 0){
            Student st = s.get(s.size() - 1);
            System.out.println(st.get_name() + " starts exiting!");
            exit(st);
            enter(st, Globals.CORR);
            exit(st);
            enter(st, Globals.STAIRS);
            exit(st);
            enter(st, Globals.YARD);
            exit(st);
        }
    }

    public void empty(){
        ArrayList<Student> s;
        System.out.println("School stars empting");
        s = floor1.get_students(1);
        remove(s);
        s = floor1.get_students(2);
        remove(s);
        s = floor1.get_students(3);
        remove(s);
        s = floor1.get_students(4);
        remove(s);
        s = floor1.get_students(5);
        remove(s);
        s = floor1.get_students(6);
        remove(s);
        s = floor2.get_students(1);
        remove(s);
        s = floor2.get_students(2);
        remove(s);
        s = floor2.get_students(3);
        remove(s);
        s = floor2.get_students(4);
        remove(s);
        s = floor2.get_students(5);
        remove(s);
        s = floor2.get_students(6);
        remove(s);
        s = floor3.get_students(1);
        remove(s);
        s = floor3.get_students(2);
        remove(s);
        s = floor3.get_students(3);
        remove(s);
        s = floor3.get_students(4);
        remove(s);
        s = floor3.get_students(5);
        remove(s);
        s = floor3.get_students(6);
        remove(s);

        floor1.remove_teacher(1);
        floor1.remove_teacher(2);
        floor1.remove_teacher(3);
        floor1.remove_teacher(4);
        floor1.remove_teacher(5);
        floor1.remove_teacher(6);

        floor2.remove_teacher(1);
        floor2.remove_teacher(2);
        floor2.remove_teacher(3);
        floor2.remove_teacher(4);
        floor2.remove_teacher(5);
        floor2.remove_teacher(6);

        floor3.remove_teacher(1);
        floor3.remove_teacher(2);
        floor3.remove_teacher(3);
        floor3.remove_teacher(4);
        floor3.remove_teacher(5);
        floor3.remove_teacher(6);
    }

}
