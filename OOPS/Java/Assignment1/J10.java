import java.util.Scanner;

 class Metric{
 	public double KmtoMile(double km)
 	{
 		return (km/1.5);
 	}
 	public double MiletoKm(double mile)
 	{
 		return (mile*1.5);
 	}
 }
 public class J10{
 	public static void main(String args[])
 	{
 		Scanner sc = new Scanner(System.in);
 		Metric mt = new Metric();
 		double km,mile;
 		System.out.print("Enter distance in kilometer : ");
 		km = sc.nextDouble();
 		mile = mt.KmtoMile(km);
 		System.out.println("Equivalent distance in mile : "+mile);
 		System.out.print("Enter distance in mile : ");
 		mile = sc.nextDouble();
 		km = mt.MiletoKm(mile);
 		System.out.println("Equivalent distance in km : "+km);
 		
 	}
 }
 
