package MemberList;

public class Member
{
    static int LIMIT = 10;

    String member_id;
    String name;
    String dob;
    int issued;

    void setMemberId(String member_id){ this.member_id = member_id; }
    void setName(String name){ this.name = name; }
    void setDob(String dob){ this.dob = dob; }
    public void setIssued(int issued){ if (issued <= LIMIT) this.issued = issued; else System.out.println("[ERROR] BOOK LIMIT EXCEEDED"); }

    public String getMemberId(){ return member_id; }
    String getName(){ return name; }
    String getDob(){ return dob; }
    public int getIssued(){ return issued; }

    Member(String member_id, String name, String dob)
    {
        setMemberId(member_id);
        setName(name);
        setDob(dob);
        setIssued(0);        
    }

    public boolean isEligible() { return issued < LIMIT; }

    void showDetails()
    {
        System.out.println("--------------------------------------------");
        System.out.println("MEMBER ID : " + member_id);
        System.out.println("NAME : " + name);
        System.out.println("DATE OF BIRTH : " + dob);
        System.out.println("ISSUED : " + issued);
        System.out.println("--------------------------------------------");
    }

}