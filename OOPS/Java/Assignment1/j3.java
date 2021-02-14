import java.util.Scanner;

public class j3 {
    public static void main(String[] args) {
        int height;
        double inch;
        double feet;

        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the height(int): ");
        height = scanner.nextInt();

        feet = (double)height / 30.5;
        inch = (double)height / 2.54;

        System.out.println("Height in feet is = "+feet);
        System.out.println("Height in inches is = "+inch);
    }
}
