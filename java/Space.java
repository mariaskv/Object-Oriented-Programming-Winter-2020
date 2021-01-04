import java.util.*;

public class Space{
    ArrayList<Student> v;
    int size;
    int capacity;
    public Space(int c_init){
        // System.out.println("A new space has been created");
        v = new ArrayList<Student>(c_init);
        size = v.size();
        capacity = c_init;
    }

    public void print(){
        System.out.println(v);
    }

    public boolean enter(Student student){
        if(student == null)
            return false;
        if(v.size() < capacity){
            for(int i = 0; i < v.size(); i ++){
                Student s = v.get(i);
                if(s == student){
                    System.out.println("That student is already in");
                    return false;
                }
            }
            this.v.add(student);
            return true;
        }
        else{
            System.out.println("There is no more space here");
            return false;
        }
    }

    public Student exit(Student student){
        Student stu = null;
        for(int i = 0; i < v.size(); i++){
            Student st = v.get(i);
            if(st == student){
                stu = st;
                v.remove(i);
                return stu;
            }
        }
        System.out.println("There is no such a student here");
        return stu;
    }

    public int get_capacity(){
        return capacity;
    }

    public ArrayList<Student> get_students(){
        return v;
    }
}

class Classroom extends Space{
    Teacher teacher;

    public Classroom(int c_init){
        super(c_init);
        System.out.println("A new classroom has been created");
        teacher = new Teacher("Nothing", 0, 0);
    }

    public void set_teacher(Teacher teacher_init){
        if(teacher_init == null)
            return;
        teacher = teacher_init;
    }

    public void remove_teacher(){
        teacher = null;
    }

    public void print(){
        System.out.println("Teacher: ");
        if(teacher != null)
            teacher.print();
        else
            System.out.println("null");
        System.out.println("Students: ");
        super.print();
    }

    public boolean enter(Student student){
        System.out.println("A student with name: " + student.get_name() + " enters classroom");
        boolean flag = super.enter(student);
        return flag;
    }

    public Student exit(Student student){
        System.out.println("A student with name: " + student.get_name() + " exits classroom");    
        Student s_return = super.exit(student);
        return s_return;
    }

    public void operate(int Lst, int Lt){
        teacher.add_tiredness(Lt);
        for(int k = 0; k < v.size(); k++){
            v.get(k).add_tiredness(Lst);
        }
    }

    public ArrayList<Student> get_students(){
        return super.get_students();
    }
}

class Corr extends Space{

    public Corr(int c_init){
        super(c_init);
        System.out.println("A new corridor has been created");
    }

    public boolean enter(Student student){
        System.out.println("A student with name: " + student.get_name() + " enters corridor");
        boolean flag = super.enter(student);
        return flag;
    }

    public Student exit(Student student){
        System.out.println("A student with name: " + student.get_name() + " exits corridor");    
        Student s_return = super.exit(student);
        return s_return;
    }

}

class Stairs extends Space{

    public Stairs(int c_init){
        super(c_init);
        System.out.println("A new stair has been created");
    }

    public boolean enter(Student student){
        System.out.println("A student with name: " + student.get_name() + " enters stairs");
        boolean flag = super.enter(student);
        return flag;
    }

    public Student exit(Student student){
        System.out.println("A student with name: " + student.get_name() + " exits stairs");    
        Student s_return = super.exit(student);
        return s_return;
    }

}

class Yard extends Space{

    public Yard(int c_init){
        super(c_init);
        System.out.println("A new yard has been created");
    }

    public boolean enter(Student student){
        System.out.println("A student with name: " + student.get_name() + " enters yard");
        boolean flag = super.enter(student);
        return flag;
    }

    public Student exit(Student student){
        System.out.println("A student with name: " + student.get_name() + " exits yard");    
        Student s_return = super.exit(student);
        return s_return;
    }

}