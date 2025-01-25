package com.company;

/* Problem-03 */

import java.lang.reflect.Array;
import java.util.Arrays;

class Sort{
    static void printArray(int[] array, int x){
        Arrays.sort(array);
        for(int i=0; i<x/2; i++){
            System.out.print(array[i]+" ");
        }
        for (int j=x-1; j>=x/2; j--){
            System.out.print(array[j]+" ");
        }
    }
}
public class Problem3 {
    public static void main(String[] args) {


        int[] array={50,40,60,20,10,30,90,70,80};
        int x=array.length;
        Sort.printArray(array,x);
    }
}
