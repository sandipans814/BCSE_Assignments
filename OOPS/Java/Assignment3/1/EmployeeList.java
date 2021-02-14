import java.util.Collections;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.Scanner;

class BasicDesc implements Comparator<Employee>
{
	@Override
	public int compare(Employee e1, Employee e2) {
		if(e1.getBasic() < e2.getBasic()){
			return 1;
        } 
        else {
			return -1;
		}
	}
}

class DeptCodeAsc implements Comparator<Employee>
{
	@Override
	public int compare(Employee e1, Employee e2) {
		if(e1.getDeptCode() > e2.getDeptCode()){
			return 1;
        } 
        else {
			return -1;
		}
	}
}

class EmpCodeAsc implements Comparator<Employee>
{
	@Override
	public int compare(Employee e1, Employee e2) {
		if(e1.getEmpCode() > e2.getEmpCode()){
			return 1;
        } 
        else {
			return -1;
		}
	}
}

class EmployeeList
{
    ArrayList<Employee> EL;
    DepartmentList DL;

    static Scanner sc = new Scanner(System.in);

    EmployeeList(DepartmentList DL)
    {
        EL = new ArrayList<Employee>();
        this.DL = DL;
    }

    Employee getEmployee(int emp_code)
    {
        for (Employee E: EL)
        {
            if (E.emp_code == emp_code)
                return E;
        }
        return null;
    }

    private boolean codeExists(int emp_code)
    {
        for (Employee E: EL)
        {
            if (E.emp_code == emp_code)
                return true;
        }
        return false;
    }

    void addEmployee()
    {
        System.out.print("ENTER THE EMPLOYEE CODE : "); int emp_code = sc.nextInt(); sc.nextLine();
        System.out.print("ENTER THE NAME : "); String emp_name = sc.nextLine();
        System.out.print("ENTER THE BASIC : INR "); float basic = sc.nextFloat(); sc.nextLine();
        System.out.print("ENTER THE DEPARTMENT CODE : "); int dept_code = sc.nextInt(); sc.nextLine();

        if (!codeExists(emp_code) && DL.codeExists(dept_code))
        {
            Employee E = new Employee(emp_code, emp_name, basic, dept_code);
            EL.add(E);
        }
        else if (!DL.codeExists(dept_code))
        {
            System.out.print("[ERROR] Department code does not exist.");
        }        
        else
        {
            System.out.print("[ERROR] Employee does not exist.");
        }
    }

    void displayEmployeeDetails(int emp_code)
    {
        Employee E = getEmployee(emp_code);
        if (E != null)
        {
            E.display();
            DL.displayDepartmentDetails(E.dept_code); 
        }
        else
            System.out.println("[ERROR] Employee does not exist.");
    }

    void displayAllEmployeeDetails()
    {
        for (Employee E: EL)
            E.display();
    }

    void totalBasicPay(int dept_code)
    {
        float basic = 0f;

        if (!DL.codeExists(dept_code))
        {
            System.out.println("[ERROR] Department does not exist.");
            return;
        }

        for (Employee E: EL)
        {
            if (E.dept_code == dept_code)
            {
                basic += E.getBasic();
            }
        }
        if (basic != 0)
            System.out.println("[INFO] TOTAL BASIC : " + basic);
    }

    void removeEmployee(int emp_code)
    {
        if (codeExists(emp_code) == true)
        {
            for (Employee E: EL)
            {
                if (E.emp_code == emp_code)
                {
                    EL.remove(E);
                    System.out.println("[INFO] Successfully removed Employee.");
                    break;
                }
            }
        }
        else
        {
            System.out.println("[ERROR] Employee does not exist.");
        }
    }

    void modifyBasic(int emp_code, float basic)
    {
        if (codeExists(emp_code))
        {
            for (Employee E: EL)
            {
                if (E.emp_code == emp_code)
                {
                    E.setBasic(basic);
                    break;
                }
            }
        }
        else
        {
            System.out.println("[ERROR] Employee does not exist.");
        }
    }

    void sortList(int choice)
    {
        if (choice == 1)
            Collections.sort(EL, new BasicDesc());
        else if (choice == 2)
            Collections.sort(EL, new DeptCodeAsc());
        else if (choice == 3)
            Collections.sort(EL, new EmpCodeAsc());

    }
}