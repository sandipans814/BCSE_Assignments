import java.io.*;
import java.util.*;
public class J5{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter the file/directory path :");
    String str = sc.nextLine();
    File f = new File(str);
    System.out.print("Enter the number of objects to read ");
    int n = sc.nextInt();
    //Serialize
    try
    {
      FileOutputStream fos = new FileOutputStream(f);
      ObjectOutputStream oos = new ObjectOutputStream(fos);
      for(int i=0;i<n;i++){
        Student s1 = new Student();
        s1.setData();
        oos.writeObject(s1);
        oos.flush();
      }
      oos.close();
      fos.close();
      System.out.println("Data written successfully");
    }
    catch(Exception e)
    {
      System.out.println("Exception during serialization: " + e);
      System.exit(0);
    }
    //Deserialize
    try{
      System.out.println("Reading Data :\n");
      FileInputStream fis = new FileInputStream(f);
      ObjectInputStream ois = new ObjectInputStream(fis);
      for(int i=0;i<n;i++){
        Student std = (Student)ois.readObject();
        System.out.println(std);
      }
      ois.close();
      fis.close();
    }catch(Exception e)
    {
      System.out.println("Exception during deserialization: " + e);
      System.exit(0);
    }
  }
}
class Student implements Serializable{
  private String first_name;
  private String last_name;
  private int roll;
  private float score;
  public Student(String fname, String lname, int roll,float score){
      this.first_name = fname;
      this.last_name  = lname;
      this.roll       = roll;
      this.score      = score;
  }
  public Student()
  {
    this.first_name = null;
    this.last_name  = null;
    this.roll       = 0;
    this.score      = 0;
  }
  public void setData()
  {
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter first_name : ");
    first_name = sc.nextLine();
    System.out.print("Enter last_name : ");
    last_name = sc.nextLine();
    System.out.print("Enter roll : ");
    roll = sc.nextInt();
    System.out.print("Enter score : ");
    score = sc.nextFloat();
  }
  @Override
  public String toString(){
    return "Name= "+first_name+" "+last_name+" roll= "+roll+" score= "+score+"\n";
  }
}
