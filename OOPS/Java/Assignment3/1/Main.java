import java.util.Scanner;

class Main
{
    public static void main(String[] args) {
        int ch = 0;
        DepartmentList DL = new DepartmentList();
        EmployeeList EL = new EmployeeList(DL);

        Scanner sc = new Scanner(System.in);

        do {
            System.out.println("ENTER 1 : TO ADD A DEPARTMENT");
            System.out.println("ENTER 2 : TO ADD AN EMPLOYEE");
            System.out.println("ENTER 3 : TO DISPLAY THE DETAILS OF AN EMPLOYEE");
            System.out.println("ENTER 4 : TO DISPLAY THE DETAILS OF ALL EMPLOYEES");
            System.out.println("ENTER 5 : TO FIND THE TOTAL BASIC PAY OF A DEPARTMENT");
            System.out.println("ENTER 6 : TO REMOVE AN EMPLOYEE");
            System.out.println("ENTER 7 : TO MODIFY THE BASIC OF AN EMPLOYEE");
            System.out.println("ENTER 8 : TO SORT THE EMPLOYEE LIST BASED ON DESCENDING BASIC");
            System.out.println("ENTER 9 : TO SORT THE EMPLOYEE LIST BASED ON ASCENDING DEPT CODE");
            System.out.println("ENTER 10 : TO SORT THE EMPLOYEE LIST BASED ON ASCENDING EMP CODE");
            System.out.println("ENTER 0 : TO QUIT");
            System.out.print("CHOICE : "); ch = sc.nextInt(); sc.nextLine();

            if (ch == 1)
            {
                DL.addDepartment();
            }
            else if (ch == 2)
            {
                EL.addEmployee();
            }
            else if (ch == 3)
            {
                System.out.print("ENTER THE EMPLOYEE CODE : "); int emp_code = sc.nextInt(); sc.nextLine();
                EL.displayEmployeeDetails(emp_code);
            }
            else if (ch == 4)
            {
                EL.displayAllEmployeeDetails();
            }
            else if (ch == 5)
            {
                System.out.print("ENTER THE DEPARTMENT CODE : "); int dept_code = sc.nextInt(); sc.nextLine();
                EL.totalBasicPay(dept_code);
            }
            else if (ch == 6)
            {
                System.out.print("ENTER THE EMPLOYEE CODE : "); int emp_code = sc.nextInt(); sc.nextLine();
                EL.removeEmployee(emp_code);
            }
            else if (ch == 7)
            {
                System.out.print("ENTER THE EMPLOYEE CODE : "); int emp_code = sc.nextInt(); sc.nextLine();
                System.out.print("ENTER THE NEW BASIC INR : "); float basic = sc.nextFloat(); sc.nextLine();
                EL.modifyBasic(emp_code, basic);
            }
            else if (ch == 8)
            {
                EL.sortList(1);
            }
            else if (ch == 9)
            {
                EL.sortList(2);
            }
            else if (ch == 10)
            {
                EL.sortList(3);
            }
        }while(ch != 0);
    }
}