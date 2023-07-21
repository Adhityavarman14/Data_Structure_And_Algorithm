import java.util.*;

public class StrinClass {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		
		String s = sc.nextLine();
		System.out.println(s);
		char demo0;
		char text [] = s.toCharArray();
		char demotext[] = s.toCharArray();
	
		int left = 0, right = left+1;
		
		do {
//			it leaves the white spaces but in some cases it won't work
			/*if (text[left] == ' ' || text[right ]==' ') {
				if(text.length%2 == 0) {
				left +=1;
				right = left+1;}
				else {
					left+=2;
					right = left+1;
				}
			}*/
//			swap the string
			demo0 = text[left];
			text[left] = text[right];
			text[right] = demo0;
			
			left += 2;
			right = left+1;
		}while(left < right && right<text.length);
		
		
		for(char i : text) {
			System.out.print(i);
		}
			
		//		ascci value
		int demo[] = new int[text.length];
		
		for(int i = 0;i<text.length;i++) {
			demo[i] = (int)text[i];
			System.out.print("\n"+demo[i]+" ");
		}System.out.println("");
		
		for(int i =0;i<text.length;i++){
			System.out.print(text[i]+""+demo[i]+"");
		}
		System.out.println();
		
//		SUM OF THE VALUES
		left = 0;right = left+1;
		int sum[] = new int[demo.length/2], i =0;
		
		do {
			sum[i] = demo[left]+demo[right];
			i++;
			left+=2;right=left+1;
		}while(left<right && right < demo.length);
		int o =0;
		for(int j = 0;j<text.length;j++) {
			System.out.print(text[j]+"");
			if(j%2 == 1) {
					System.out.print(sum[o]+" ");
					o++;
			}
		}
		
	}
}
