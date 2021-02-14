package MemberList;

import java.util.Scanner;

public class MemberList
{
    static int CAPACITY = 10000;
    static Scanner sc = new Scanner(System.in);
    
    int size;
    Member members[];

    public MemberList()
    {
        size = 0;
        members = new Member[CAPACITY];
    }

    private boolean checkMemberId(String member_id)
    {
        for (int i = 0; i < size; i++)
        {
            if(members[i].getMemberId().equals(member_id))
                return false;
        }
        return true;
    }

    public Member getMemberFromList(String member_id)
    {
        for (int i = 0; i < size; i++)
        {
            if (members[i].getMemberId().equals(member_id))
                return members[i];
        }
        return null;
    }

    public void addMember()
    {
        System.out.print("ENTER THE MEMBER ID : "); String member_id = sc.nextLine();
        System.out.print("ENTER THE NAME : "); String name = sc.nextLine();
        System.out.print("ENTER THE DATE OF BIRTH : "); String dob = sc.nextLine();
        if (checkMemberId(member_id))
        {
            Member member = new Member(member_id, name, dob);
            if (size <= CAPACITY)
                members[size++] = member;
            else
                System.out.println("[ERROR] : CAPACITY EXCEEDED");
        }
        else
            System.out.println("[ERROR] : MEMBER_ID MUST BE UNIQUE");
    }

    public void showMemberDetails(String member_id)
    {
        Member member = getMemberFromList(member_id);
        if (member != null)
            member.showDetails();
        else
            System.out.println("[ERROR] : NO SUCH MEMBER EXISTS");
    }

    public void showAllMemberDetails()
    {
        for (int i = 0; i < size; i++)
            members[i].showDetails();
    }
}