// Author: Khalid Hassan
import java.util.Scanner;

class Student{
    private String name;
    private int roll;
    private int score;

    public Student(){
        name = new String("No Name");
        roll = -1;
        score = -1;
    }

    public Student(int rollStudent){
        name = new String("No Name");
        roll = rollStudent;
        score = -1;
    }

    public Student(String nameStudent, int rollStudent){
        name = new String(nameStudent);
        roll = rollStudent;
        score = -1;
    }

    public Student(String nameStudent, int rollStudent, int scoreStudent){
        name = new String(nameStudent);
        roll = rollStudent;
        score = scoreStudent;
    }

    public Student(Student studentArg){
        name = new String(studentArg.name);

        // This prints deep copy status
        // System.out.println("Deep Copy: " + (!(name == studentArg.name)  && name.equals(studentArg.name)));
        roll = studentArg.roll;
        score = studentArg.score;
    }

    public boolean deepCopy(Student studentArg){
        boolean deepCopyFlag = (studentArg.roll == roll) && (studentArg.score == score) && (!(name == studentArg.name)  && name.equals(studentArg.name));
        return deepCopyFlag;
        // System.out.println("Deep Copy: " + deepCopyFlag);
    }

    public void setName(String nameStudent){
        name = new String(nameStudent);
    }

    public void setRoll(int rollStudent){
        roll = rollStudent;
    }

    public void setScore(int scoreStudent){
        score = scoreStudent;
    }

    public void display(){
        System.out.println("Name: " + name);
        System.out.println("Roll: " + roll);
        System.out.println("Score: " + score);
    }
}

public class J8
{
    public static void main(String[] args){
        Scanner iStream = new Scanner(System.in);

        String n;
        System.out.print("Enter name of the stduent: ");
        n = iStream.nextLine();

        Student s = new Student(n, 19, 100);

        Student copyS = new Student(s);
        
		s.display();
		copyS.display();
        System.out.println("Deep copy: " + copyS.deepCopy(s));
    }
}
