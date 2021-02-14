package memberList;

//import mypackage;
import java.util.Scanner;

public class member {
    String name;
    String dob;
    long memId = 0;
    long issued;
    static long limit = 5;
    long available;


    Scanner scanner = new Scanner(System.in);
    public void setData(){
        System.out.print("Enter your name: ");
        name = scanner.nextLine();
        System.out.print("Enter your Member ID: ");
        memId = scanner.nextLong();
        System.out.print("Enter your Date Of Birth: ");
        dob = scanner.nextLine();
        System.out.print("How many books have you issued?: ");
        issued = scanner.nextLong();
        available = limit - issued;
    }

    public void getData(){
        System.out.println("Name: " + name);
        System.out.println("Member ID: " + memId);
        System.out.println("Number of books issued: " + issued);
        System.out.println("Total number of books you can issue: " + limit);
        System.out.println("Total number of more books you can issue: " + available);
    }
}

class memberList{
    private member[] memberOb = new member[5];
    private int i;
    int count;
    int flag;
    Scanner scanner = new Scanner(System.in);
    memberList(){
        for(i=0; i<memberOb.length; i++)
            memberOb[i] = new member();
    }

    private int availablePlace(){
        for(i=0; i<memberOb.length; i++){
            if(memberOb[i].memId == 0) return i;
        }
        return -1;
    }

    public void memberAdd(){
        System.out.println("How many members you want to add?: ");
        count = scanner.nextInt();
        flag = availablePlace();
        if(flag == -1){
            System.out.println("No space available.");
            return ;
        }
        for(i=flag; i<flag+count; i++){
            memberOb[i] = new member();
            memberOb[i].setData();
        }
    }

    int isPresent(long id){
        for(i=0; i<memberOb.length; i++){
            if(memberOb[i].memId == id) return i;
        }
        return -1;
    }

    public void showOne(long id){
        if(isPresent(id) != 1){
            memberOb[isPresent(id)].setData();
        }
        else{
            System.out.println("Invalid Member ID.");
        }
    }

    public void showAll(){
        for(i=0; i<memberOb.length; i++)
            memberOb[i].getData();
    }
}

class J32{
    public static void main(String[] args) {

    }
}