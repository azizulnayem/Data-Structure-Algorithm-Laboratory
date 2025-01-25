package com.company;

/* Problem-02 */

import static com.company.Inversion.A;


class Inversion{
    static int[] A=new int[] {1, 9, 6, 4, 5};
    static int Count(int c){
        int inversion_count=0;
        for(int i=0; i<c-1; i++){
            for(int j=i+1; j<c; j++){
                if(A[i]>A[j]){
                    inversion_count++;
                }
            }
        }
        return inversion_count;
    }
}
public class Problem2 {
    public static void main(String[] args) {

        System.out.println("The inversion count of A is : "+ Inversion.Count(A.length));
    }
}
