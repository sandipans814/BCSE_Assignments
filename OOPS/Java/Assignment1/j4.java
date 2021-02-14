import java.util.Scanner;

public class j4 {
    public static void main(String[] args) {
       final float PI = 3.14F;
       double radius;

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the radius of the circle: ");
        radius = scanner.nextDouble();

        System.out.println("The area of the circle is = "+ PI * Math.pow(radius, 2));

    }
}
