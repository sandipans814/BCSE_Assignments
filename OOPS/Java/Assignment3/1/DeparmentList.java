import java.util.ArrayList;
import java.util.Scanner;

class DepartmentList
{
    ArrayList<Department> DL;

    static Scanner sc = new Scanner(System.in);

    DepartmentList()
    {
        DL = new ArrayList<Department>();
    }

    boolean codeExists(int dept_code)
    {
        for (Department D: DL)
        {
            if (D.dept_code == dept_code)
                return true;
        }
        return false;
    }

    Department getDepartment(int dept_code)
    {
        for (Department D: DL)
        {
            if (D.dept_code == dept_code)
                return D;
        }
        return null;
    }

    void displayDepartmentDetails(int dept_code)
    {
        Department D = getDepartment(dept_code);
        if (D != null)
        {
            D.display();
        }
        else
        {
            System.out.println("[ERROR] Department does not exist.");
        }
    }

    void addDepartment()
    {
        System.out.print("ENTER THE DEPARTMENT CODE : ");
        int dept_code = sc.nextInt(); sc.nextLine();
        System.out.print("ENTER THE NAME : "); String dept_name = sc.nextLine();
        System.out.print("ENTER THE LOCATION : "); String location = sc.nextLine();

        if (!codeExists(dept_code))
        {
            Department D = new Department(dept_code, dept_name, location);
            DL.add(D);
        }
        else
        {
            System.out.print("[ERROR] Department code not unique.");
        }        
    }

}