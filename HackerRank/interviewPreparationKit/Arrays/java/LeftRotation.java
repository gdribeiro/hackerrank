import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

        public static int[] arrayLeftRotation(int[] a, int n, int k) {
                for(int i=0; i < k; i++){
                        int transfer = a[0];
                        for(int it=0; it < n-1; it++){
                                a[it] = a[it+1];
                        }
                        a[n-1] = transfer;
                }  
                return a;
        }

        public static void main(String[] args) {
                Scanner in = new Scanner(System.in);
                int n = in.nextInt();
                int k = in.nextInt();
                int a[] = new int[n];
                for(int a_i=0; a_i < n; a_i++){
                        a[a_i] = in.nextInt();
                }

                int[] output = new int[n];
                output = arrayLeftRotation(a, n, k);
                for(int i = 0; i < n; i++)
                        System.out.print(output[i] + " ");

                System.out.println();

        }
}
