import java.util.*;
class App{
    public static void main(String[] args){
        int T = 18;
        int S = 36;

        int Lj = Integer.parseInt(args[0]);
        int Ls = Integer.parseInt(args[1]);
        int Lt = Integer.parseInt(args[2]);
        int L = Integer.parseInt(args[3]);

        Scanner scanner = new Scanner(System.in);
        ArrayList<Teacher> teachers = new ArrayList<Teacher>(T);
        ArrayList<Student> students =  new ArrayList<Student>(S);
        School school = new School(2);
        Random rand = new Random();
        for(int i = 0; i < T; i++){
            String input = scanner.nextLine();
            String[] parts = input.split(" ");
            Teacher teacher = new Teacher(parts[0], Integer.parseInt(parts[2]), Integer.parseInt(parts[1]));
            teachers.add(teacher);
            school.set_teacher(teacher);
            school.place(teacher);
        }
        for(int i = 0; i < S; i++){
            String input = scanner.nextLine();
            String[] parts = input.split(" ");
            Student student = new Student(parts[0], Integer.parseInt(parts[2]), Integer.parseInt(parts[1]));
            students.add(student);
        }
        while(students.size() > 0){
            int j = rand.nextInt(students.size());
            Student s = students.get(j);
            school.enter(s, Globals.YARD);
            school.exit(s);
            school.enter(s, Globals.STAIRS);
            school.exit(s);
            school.enter(s, Globals.CORR);
            school.exit(s);
            boolean flag = school.enter(s, Globals.CLASSROOM);
            if(flag == true)
                students.remove(s);
        }
        for(int i = 0; i < L; i++){
            school.operate(Lj, Ls, Lt);
        }
        school.print();
        school.empty();
        school.print();
    }
}

