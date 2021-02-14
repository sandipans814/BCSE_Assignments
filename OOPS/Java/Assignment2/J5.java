import java.util.*;
class ScoreException extends Exception{
	int score;
	public ScoreException(int score)
	{
		this.score = score;
	}
	public void verdict()
	{
		System.out.println("Enter correct score ");
	}
}
class Student{
	int roll;
	int score;
	String name;
	Scanner sc = new Scanner(System.in);
	public void setData()
	{
		System.out.print("Enter name : ");
		name = sc.nextLine();
		System.out.print("Enter roll : ");
		roll = sc.nextInt();
		sc.nextLine();
	}
	public void setScore()
	{
		try{
			System.out.print("Enter score : ");
			score = sc.nextInt();
			if(score<0 || score >100){
			score = 0;
				throw new ScoreException(score);
			}	
		}
		catch(ScoreException e)
		{
			e.verdict();
		}
	}
	public void showData()
	{
		System.out.println("Name = "+name);
		System.out.println("ROll = "+roll);
		System.out.println("Score = "+score);
	}
}
public class J5{

	public static void main(String args[])
	{
		Student st = new Student();
		st.setData();
		st.setScore();
		st.showData();
	}
}
	 
