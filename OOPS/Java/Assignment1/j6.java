class Display{
	public void show(int num){
		System.out.println("The passed argument is: "+num);
	}
	
	public void show(double num){
		System.out.println("The passed argument is: "+num);
	}
}


public class j6{
	public static void main(String args[]){
	
		short num1 = 5;
		double num2 = 10.2365;
		Display ob1 = new Display();
		ob1.show(num1);
		ob1.show(num2);
	
	}
}
