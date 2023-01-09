package arrays;
import java.util.*;

public class BubbleSort {
    static void bubbleSoert(int[] a,int n){
        int i,j;
        int temp = 0;
        for(i=0;i<n;i++){
            for (j=i+1;j<n;j++){
                if (a[i]>a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the length of the array: ");
        n = sc.nextInt();
        int[] a = new int[n];
        System.out.println("Enter the elements of the array");
        for(int i = 0;i<n;i++){
            a[i] = sc.nextInt();
        }
        System.out.print("unsorted array: ");
        for(int i = 0;i<n;i++){
            System.out.print(a[i]+" ");
        }   
        bubbleSoert(a, n);
        System.out.print("\nsorted array: ");
        for(int i = 0;i<n;i++){
            System.out.print(a[i]+" ");
        } 
        System.out.println("\n");
    }
}
