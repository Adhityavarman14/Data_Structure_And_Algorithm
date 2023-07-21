package Training;
import java.util.*;

public class ImmediatePrimeNumber {
	// it checks whether the number is prime or not.  if it is prime then it returns true;otherwise, returns false.
	static boolean Prime(int num) {
		if(num<=1)
			return false;
		for(int j = 2;j<=num/2;j++) {
			if(num%j==0)
				return false;
		}	
		return true;
	}
	
	public static void main(String [] as) {
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		// it checks immediate prime number to the left
		int left = num -1;
		
		while(true) {
			if(Prime(left)) {
				System.out.println(left);
				break;
			}
			left--;
		}
		// it checks immediate prime number to the right
		int right = num+1;
		while(true) {
			if(Prime(right)) {
				System.out.println(right);break;
			}
			right++;
		}
	}
}
