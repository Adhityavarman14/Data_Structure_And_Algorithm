import java.util.Scanner;

public class AA {
	public static void main(String[] args) {
		// TODO Auto-generated method stub\
		Scanner sc = new Scanner(System.in);
		String a = sc.nextLine();
		
		char arr[] = a.toCharArray();
		int len = arr.length,even = 0, odd = 0;
		char even1[] = new char[len],odd1[] = new char[len];int j = 0,k = 0;
		
		for(int i = 0;i< len;i++) {
			if(arr[i]%2 == 0) {
				even1[j]=arr[i];
				j++;
				even++;
				continue;
		}
			odd1[k]=arr[i];
			k++;
			odd++;
		}
		System.out.println(even+" "+odd);
		for(int i = 0;i < even1.length;i++) {
			System.out.println("even "+"odd");
			System.out.println(" "+even1[i]+"     "+odd1[i]);
		}
	}
}
