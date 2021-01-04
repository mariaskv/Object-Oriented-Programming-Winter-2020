public class Person{
    String name;
    int class_id;
    int floor_id;
    boolean classroom;
    int tiredness;
    int position;

    public Person(String name_init, int floor, int classroom_id){
        name = name_init;
        class_id = classroom_id;
        floor_id = floor;
        classroom = false;
        tiredness = 0;
        position = Globals.OUT_OF_SCHOOL;
        // System.out.println("A new person has been created with name: " + name);    
    }

    public String toString(){
        return String.format(name + ", " + tiredness);
    }

    public String get_name(){
        return name;
    }

    public int get_class_id(){
        return class_id;
    }

    public int get_floor_id(){
        return floor_id;
    }

    public void set_classroom(boolean pos){
        classroom = pos;
    }

    public void add_tiredness(int i){
        tiredness = tiredness + i;
    }

    public int get_tiredhess(){
        return tiredness;
    }

    public void print(){
        System.out.println(name + " "  + tiredness);
    }

    public void set_position(int pos){
        position = pos;
    }

    public int get_position(){
        return position;
    }

}

class Student extends Person{
    public Student(String name_init, int floor_init, int class_init){
        super(name_init, floor_init, class_init);
        if(name != "Nothing")
            System.out.println("A new student has been created with name: " + name + ", class id: " + class_id + ", floor id: " + floor_id);    
    }
    
    public void print(){
        super.print();
    }
}

class Teacher extends Person{
    public Teacher(String name_init, int floor_init, int class_init){
        super(name_init, floor_init, class_init);
        if(name != "Nothing")
            System.out.println("A new teacher has been created with name: " + name + ", class id: " + class_id + ", floor id: " + floor_id); 
    }

    public void print(){
        super.print();
    }

    public void place(){
        super.set_classroom(true);
    }
}






