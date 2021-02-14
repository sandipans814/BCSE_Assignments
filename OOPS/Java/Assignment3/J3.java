import java.io.File;
import java.util.Scanner;
public class J3{
  public static void main(String args[])
  {
    Scanner sc =  new Scanner(System.in);
    String str = new String();
    System.out.print("Enter the file/directory path :");
    str = sc.nextLine();
    File f = new File(str);
    if(f.exists())
    {
      if(f.isDirectory())
      {
        System.out.println("Directory of "+str);
        String list[] = f.list();
        System.out.print("List of files : ");
        for(int i=0;i<list.length;i++)
          System.out.println(list[i]);
      }
      else
      {
        System.out.println(f.getName() + " is not a directory.");
        System.out.println(f.canRead() ? f.getName() + " is Readable" : f.getName() +" is not Readable");
        System.out.println(f.canWrite() ? f.getName() + " is Writable" : f.getName() +" is not Writable");
      }
    }
    else
    {
      System.out.println("File/directory doesn't exists.Please check your path.");
    }
  }
}
