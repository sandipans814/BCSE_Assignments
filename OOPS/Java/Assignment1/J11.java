import java.util.Scanner;
class Instructor{
	String name;
	long phn;
	Instructor(){
		name = "";
		phn = 000;
	}
	public void setData()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter name of faculty : ");
		name = sc.nextLine();
		System.out.print("Enter phone number : ");
		phn = sc.nextLong();
	}
	public void getData()
	{
		System.out.println("Name = "+name);
		System.out.println("Phone number = "+phn);
	}
}
class TextBook{
	String name;
	String author;
	String publisher;
	public void setData()
	{
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter name of book : ");
		name = sc.nextLine();
		System.out.print("Enter name of author : ");
		author = sc.nextLine();
		System.out.print("Enter name of publisher : ");
		publisher = sc.nextLine();
	}
	public void getData()
	{
		System.out.println("Name = "+name);	
		System.out.println("Author = "+author);
		System.out.println("Publisher = "+publisher);
	}
}
class Course
{
	TextBook tb = new TextBook();
	Instructor ins = new Instructor();
	String name;
	public void setData()
	{
		System.out.print("Enter course name = ");
		Scanner sc = new Scanner(System.in);
		name = sc.nextLine();
		tb.setData();
		ins.setData();
	}
	public void getData()
	{
		System.out.println("Course name = "+name);
		tb.getData();
		ins.getData();
	}
}
public class J11
{
	public static void main(String args[])
	{
		Course cb = new Course();
		cb.setData();
		cb.getData();
	}
}
