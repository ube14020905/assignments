
package sorting;
import java.util.Scanner;
public class BubbleSort {

	public static void main(String[] args) {
        int n;
		System.out.println("Enter the size of array:");
		Scanner s=new Scanner(System.in);
		n=s.nextInt();
		int[] arr=new int[n];
		System.out.println("Enter Array elements:");
		for(int i=0;i<n;i++) {
			arr[i]=s.nextInt();
		}
		bubbleSort(arr);
        System.out.println("Sorted array:");
        for (int value : arr) {
            System.out.print(value + " ");
        }
    }

    public static void bubbleSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }


	}
