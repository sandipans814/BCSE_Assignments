import java.util.*;

class bankAccount{
	long customerID;
	String name;
	double loanAmount = 0.0, currLoan, availLoan;
	long phone;

	boolean type = false;
	static double creditLimit = 10000;
	static double creditLimit_p = 10500;

	Scanner scanner = new Scanner(System.in);

	public void setData(){
		System.out.print("Enter your id: ");
		customerID = scanner.nextLong();
		scanner.nextLine();
		System.out.print("Enter your name: ");
		name = scanner.nextLine();
		System.out.print("Enter your current loan: ");
		currLoan = scanner.nextDouble();
		System.out.print("Enter your phone number: ");
		phone = scanner.nextLong();
		System.out.print("IS privileged(true/false): ");
		type = scanner.nextBoolean();
	}

	public double setAvailLoan(double amount ){

		if (type == true){
			if(currLoan + amount > creditLimit_p) return 0.0;
			availLoan = creditLimit_p - currLoan - amount;
			currLoan += amount;
		}
		else{
			if(currLoan + amount > creditLimit) return 0.0;
			availLoan = creditLimit - currLoan - amount;
			currLoan += amount;
		}
		return availLoan;
	}

	public void setLoan(double loanAmount){
		double flag = setAvailLoan(loanAmount);
		if(flag == 0){
			System.out.println("Credit Limit Exceeded.");
		}
		else{
			this.loanAmount = loanAmount;
			System.out.println("Loan Guarrented.");
		}
	}

	public void updateData(){
		System.out.print("Enter your updated name: ");
		name = scanner.nextLine();
		
		System.out.print("Enter your updated phone number: ");
		phone = scanner.nextLong();

	}

	public void getData(){
		System.out.println("Customer ID: " + customerID);
		scanner.nextLine();
		System.out.println("Name: " + name);
		System.out.println("Contact: " + phone);
		System.out.println("Current Loan: " + currLoan);
		System.out.println("Available Loan: " + availLoan);
		System.out.println("Is privileged?: " + type);
		if (type == true){
			System.out.println("Credit Limit: " + creditLimit_p);
		}
		else{
			System.out.println("Credit Limit: " + creditLimit);
		}
	}
}

class J1{
	public static void main(String args[]){

		double loanAmount;

		Scanner scanner = new Scanner(System.in);

		bankAccount ob = new bankAccount();
		ob.setData();
		System.out.print("Enter the loan amount: ");
		loanAmount = scanner.nextDouble();
		ob.setLoan(loanAmount);
		ob.getData();
		System.out.println("Now enter updated name and phone number: ");
		ob.updateData();
		ob.getData();

	}
}
