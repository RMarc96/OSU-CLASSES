import java.util.Scanner;

public class intFun {
	public static void main(String[] args) {
		int val = getNum();
		int[] arr = makeArr(val);
		inArr(arr, val);

		print(arr, val);

	}
	public static int getNum() {
		int x;
		Scanner input = new Scanner(System.in);
		System.out.println("enter int: ");
		x = input.nextInt();
		return x;
	}
	
		
	public static int[] makeArr(int x) {
		int[] array = new int[x];
		return array;
	}

	public static int[] inArr(int[] array, int x) {
		int k;
		for(k = 0; k < x; k++) {
			array[k] = k+1;
		}
		return array;
	}
		
	public static void print(int[] array, int x) {
		int j;
		for(j = 0; j < x; j++) {	
			System.out.print(array[j] + " " );
		}	
		System.out.print("\n");
	}	

}
