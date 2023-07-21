package dsa;

import java.util.Scanner;

public class day2 {
	static Scanner sc = new Scanner(System.in);
	  void PositiveNegativeZero(){
	    int num = sc.nextInt();
	    if(num>0) 
	    	System.out.println("Positive");
	    else if(num<0) 
	    	System.out.println("Negative");
	    else 
	    	System.out.println("Zero");
	  }
	  void Greatestoftwo(){
	    int num1 = sc.nextInt();
	    int num2 = sc.nextInt();
	    if(num1>num2)
	    	System.out.println(num1+" is greater");
	    else
	    	System.out.println(num2+" is greater");
	  }
	  static void OddorEven(){
	    int num = sc.nextInt();
	    if(num%2==0) 
	    	System.out.println(num+" is even"); 
	    else 
	    	System.out.println(num+" is odd");
	  }
	  static void SumisOddorEven(){
	    int num1 = sc.nextInt();
	    int num2 = sc.nextInt();
	    if((num1+num2)%2!=0) 
	    	System.out.println("Sum is odd");
	    else 
	    	System.out.println("Sum is even");
	  }
	  void onetohundred(){
		  System.out.println("");
	    for (int i=0;i<=100;i++) 
	    	System.out.print(i+" ");
	  }
	  void onetohundredalt(){
		  System.out.println("");
	    for (int i=1;i<=100;i+=2) 
	    	System.out.print(i+" ");
	  }
	  void hundredtoone(){
		  System.out.println("");
	    for(int i=100;i>0;i--) 
	    	System.out.print(i+" ");
	  }
	  void hundredtoonealt2(){
		  System.out.println("");
	    for (int i=100;i>0;i-=3)
	    	System.out.print(i+" ");
	  }
	  public static void main(String[] args) {
		  day2 d = new day2();
	    OddorEven();
	    d.hundredtoone();//Sample function call
	  }
}
