import java.util.Scanner;

public class j5{
    public static void main(String[] args) {
        String s1, s2;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first string: ");
        s1 = scanner.nextLine();

        s2 = s1;

        System.out.println("Here is the second string: " + s2);
        if(s2==s1)
          System.out.println("");
    }
}
