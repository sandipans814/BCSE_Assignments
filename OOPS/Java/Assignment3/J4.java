import java.io.*;
import java.util.*;
public class J4{
  public static void main(String args[]) throws Exception
  {
    Scanner sc =  new Scanner(System.in);
    String str = new String();
    System.out.print("Enter the file/directory path :");
    str = sc.nextLine();
    File f = new File(str);
    FileWriter f0 = new FileWriter(f);
    BufferedReader br = new BufferedReader(new FileReader(f));
    System.out.print("Enter number of names to list : ");
    int n = sc.nextInt();
    sc.nextLine();
    for(int i=0;i<n;i++)
    {
      System.out.print("Enter name : ");
      String s = sc.nextLine();
      f0.write(s+"\n");
    }
    f0.close();
    System.out.println("Data wrote into file successfully");
    System.out.println("Reading data from file");
    String st;
    while ((st = br.readLine()) != null)
      System.out.println(st);
  }
}
