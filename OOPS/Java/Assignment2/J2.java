import java.util.*;

class person{
	String name;
	long premiseNum;
	String street, city, state;
	long pin;
	long phone;
	String email;

	Scanner scanner = new Scanner(System.in);

	public void setData(){
		System.out.print("Enter the name:");
		name = scanner.nextLine();
		System.out.print("Enter premise number: ");
		premiseNum = scanner.nextLong();
		scanner.nextLine();
		System.out.print("Enter the street: ");
		street = scanner.nextLine();
		System.out.print("Enter the city: ");
		city = scanner.nextLine();
		System.out.print("Enter the state: ");
		state = scanner.nextLine();
		System.out.print("Enter the pin: ");
		pin = scanner.nextLong();
		scanner.nextLine();
		System.out.println("Enter the E-Mail: ");
		email = scanner.nextLine();
		System.out.println("");
		System.out.println("");
	}

	public void updatePremise(){
		System.out.print("Enter the updated premise: ");
		premiseNum = scanner.nextLong();
	}

	public void updatePin(){
		System.out.print("Enter the updated pin: ");
		pin = scanner.nextLong();
	}

	public void updateStreet(){
		System.out.print("Enter the updated street: ");
		street = scanner.nextLine();
	}

	public void updateCity(){
		System.out.print("Enter the updated city: ");
		city = scanner.nextLine();
	}

	public void updateState(){
		System.out.print("Enter the updated state: ");
		state = scanner.nextLine();
	}

	public void updateAdd(){
		System.out.print("Enter the updated premise: ");
		premiseNum = scanner.nextLong();
		scanner.nextLine();
		System.out.print("Enter the updated pin: ");
		pin = scanner.nextLong();
		scanner.nextLine();

		System.out.print("Enter the updated street: ");
		street = scanner.nextLine();
		scanner.nextLine();

		System.out.print("Enter the updated city: ");
		city = scanner.nextLine();

		System.out.print("Enter the updated state: ");
		state = scanner.nextLine();

	}

	public void getData(){
		System.out.println("-----------------------------------------------------------");
		System.out.println("Name: " + name);
		System.out.println("Premise: " + premiseNum);
		System.out.println("Street: " + street);
		System.out.println("City: " + city);
		System.out.println("State: " + state);
		System.out.println("Pin: " + pin);
		System.out.println("Phone: " + phone);
		System.out.println("Email: " + email);

	}
}

class student extends person{
	int roll;
	String course;

	Scanner scanner = new Scanner(System.in);

	public void setStudent(){
		System.out.print("Enter the roll: ");
		roll = scanner.nextInt();
		scanner.nextLine();
		System.out.print("Enter the course name: ");
		course = scanner.nextLine();
	}

	public void getStudent(){
		System.out.println("Roll: " + roll);
		System.out.println("Course: " + course);
		System.out.println("-----------------------------------------------------");
	}
}

class faculty extends person{
	long id;
	String dept, specialisation;

	Scanner scanner = new Scanner(System.in);

	public void setFaculty(){
		System.out.print("Enter the id: ");
		id = scanner.nextLong();
		scanner.nextLine();
		System.out.print("Enter the specialisation: ");
		specialisation = scanner.nextLine();
		System.out.print("Enter the department: ");
		dept = scanner.nextLine();
	}

	public void getFaculty(){
		System.out.println("ID: " + id);
		System.out.println("Department: " + dept);
		System.out.println("Specialisation: " + specialisation);
		System.out.println("-----------------------------------------------------");
	}
}

class J2{
	public static void main(String args[]){
		student sob = new student();
		faculty fob = new faculty();

		sob.setData();
		sob.setStudent();
		sob.getData();
		sob.getStudent();
		sob.updateState();
		sob.getData();
		sob.getStudent();

		fob.setData();
		fob.setFaculty();
		fob.getData();
		fob.getFaculty();
		fob.updatePremise();
		fob.updatePin();
		fob.getData();
		fob.getFaculty();
	}
}
