import java.util.Scanner;
class Student{
	int roll;
	String name;
	double score;
	public void setData(int roll, String str,double score)
	{
		this.roll= roll;
		name= str;
		this.score= score;
	}
	public void getData()
	{
		System.out.println("Name : "+name);
		System.out.println("Roll Number : "+roll);
		System.out.println("Score : "+score);
	}
	public void copy(Student s)
	{
		s.name= name;
		s.roll= roll;
		s.score= score;
	}
};
public class J7
{
	public static void main(String []args)
	{
		Student s1= new Student();
		Student s2= new Student();
		String name;
		int roll;
		double score;
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter name: ");
		name= sc.nextLine();
		System.out.println("Enter roll: ");
		roll= sc.nextInt();
		System.out.println("Enter score: ");
		score= sc.nextDouble();
		s1.setData(roll,name,score);
		s1.getData();
		s1.copy(s2);
		s2.getData();
	}
	
};
