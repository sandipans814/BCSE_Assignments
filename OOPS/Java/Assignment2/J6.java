class Main
{
	public static void main(String args[])
	{
		Integer myInt = new Integer(5); // Basic Type to Object
		int mI = myInt; // Object to Basic Type
		System.out.println("Basic Type to String : " + Integer.toString(5));
		System.out.println("Object to String : " + myInt.toString());
		String I = "5";
		int Iint = Integer.parseInt(I);
		System.out.println("String to Integer : " + Iint);
	}
}
