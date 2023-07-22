package Training;
import java.util.*;

public class SumOfDigits {
	static int Sum(int n)
	{
		int sum =0;
		while(n>0){
			int r = n%10;
			sum += r;
			n /=10;
		}
		int count = 0,sum1 = sum;
		while(sum1>0) {
			count++;
			sum1 /= 10;
		}
		int ans = 0;
		if(count>1) {
			while(sum>0) {
				int r = sum%10;
				ans += r;
				sum /= 10;
			}
			return ans;
		}
		else
			return sum;
	}
	
	public static void main(String [] args) {
		int a =Sum(1234567);
		System.out.println(a);
	}
}
