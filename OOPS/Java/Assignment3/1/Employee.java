class Employee
{
    int emp_code;
    String emp_name;
    float basic;
    int dept_code;

    void setEmpCode(int emp_code){ this.emp_code = emp_code; }
    void setEmpName(String emp_name){ this.emp_name = emp_name; }
    void setBasic(float basic){ this.basic = basic; }
    void setDeptCode(int dept_code){ this.dept_code = dept_code; }

    int getEmpCode(){ return emp_code; }
    String getEmpName() { return emp_name; }
    float getBasic() { return basic; }
    int getDeptCode(){ return dept_code; } 

    Employee(int emp_code, String emp_name, float basic, int dept_code)
    {
        setEmpCode(emp_code);
        setEmpName(emp_name);
        setBasic(basic);
        setDeptCode(dept_code);
    }

    void display()
    {
        System.out.println("---------------------------------------");
        System.out.println("EMPLOYEE CODE : " + emp_code);
        System.out.println("NAME : " + emp_name);
        System.out.println("BASIC : INR " + basic);
        System.out.println("DEPT CODE : " + dept_code);
        System.out.println("---------------------------------------");
    }
}