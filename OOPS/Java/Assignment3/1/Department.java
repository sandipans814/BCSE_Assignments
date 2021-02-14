class Department
{
    int dept_code;
    String dept_name;
    String location;

    void setDeptCode(int dept_code){ this.dept_code = dept_code; }
    void setDeptName(String dept_name){ this.dept_name = dept_name; }
    void setDeptLocation(String location){ this.location = location; }

    int getDeptCode(){ return dept_code; }
    String getDeptName() { return dept_name; }
    String getLocation() { return location; }

    Department(int dept_code, String dept_name, String location)
    {
        setDeptCode(dept_code);
        setDeptName(dept_name);
        setDeptLocation(location);
    }

    void display()
    {
        System.out.println("---------------------------------------");
        System.out.println("DEPT CODE : " + dept_code);
        System.out.println("NAME : " + dept_name);
        System.out.println("LOCATION : " + location);
        System.out.println("---------------------------------------");
    }
}