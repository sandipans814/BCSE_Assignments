package apple;

import java.util.Scanner;
import java.util.StringTokenizer;

public class J7 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String string;
        int i;
        int count_a = 0;
        int count_and = 0;

        //String and = "and";

        System.out.print("Enter a string containing multiple words: ");
        string = scanner.nextLine();

        for(i=0; i<string.length(); i++){
            if(string.charAt(i) == 'a')
                count_a += 1;
        }

        System.out.println("Total number of times 'a' appears in the string is : " + count_a);

        String temp[] = string.split(" ");
        for(i=0; i<temp.length; i++){
            if(temp[i].equals("and"))
                count_and += 1;
        }

        System.out.println("Total number of times 'and' appears in the string is: " + count_and);

        if(temp[0].equals("The"))
            System.out.println("The given string starts with the word 'The'.");
        else
            System.out.println("The given string does not start with the word 'The'.");

        char array[] = new char[string.length()];
         for(i=0; i<string.length(); i++){
             array[i] = string.charAt(i);
         }

         for(i=0; i<string.length(); i++){
             System.out.println(i + "th element in the array is: " + array[i]);
         }

        StringTokenizer test = new StringTokenizer(string, " .@");
        while (test.hasMoreTokens())
        {
            System.out.println(test.nextToken());
        }
    }
}
