package MemberList;
import java.util.*;
public class MemberList {
    ArrayList<Member> ML;
    public MemberList(){
        ML = new ArrayList<Member>();
    }
    public void addNewMember(){
        Member m = new Member();
        System.out.println("\nENTER MEMBER DETAILS\n");
        m.getDetails();
        for(Member i: ML){
            if(i.returnMemberID().equals(m.returnMemberID())){
                System.out.println("\nMember ID already exists !! \n");
                return;
            }
        }
        ML.add(m);
    }
    public void showDetails(){
        for(Member m: ML){
            m.showDetails();
            System.out.println();
        }
    }
    public Member search(String ID){
        for(Member m: ML){
            if(m.returnMemberID().equals(ID)){
                return m;
            }
        }
        return null;
    }
    public void showDetails(String ID){
        for(Member m: ML){
            if(m.returnMemberID().equals(ID)){
                m.showDetails();
                return;
            }
        }
        System.out.println("Invalid Member ID\n");
    }
}