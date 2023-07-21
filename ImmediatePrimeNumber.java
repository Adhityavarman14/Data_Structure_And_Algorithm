package Training;
import java.util.*;

public class ImmediatePrimeNumber {
	
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
		
		int left = num -1;
		
		while(true) {
			if(Prime(left)) {
				System.out.println(left);
				break;
			}
			left--;
		}
		
		int right = num+1;
		while(true) {
			if(Prime(right)) {
				System.out.println(right);break;
			}
			right++;
		}
	}
}