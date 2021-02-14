import java.util.Scanner;

public class j1 {

    public static void main(String[] args) {
        short a, b;
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the first number: ");
        a = scanner.nextShort();
        System.out.print("Enter the second number: ");
        b = scanner.nextShort();
        System.out.println("The sum of the two numbers is = "+ (a+b));
    }

}
