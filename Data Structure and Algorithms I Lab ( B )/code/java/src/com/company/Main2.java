package com.company;

import java.util.Scanner;

//Bubble Sort
public class Main2 {
    public static void main(String[] args) {
        int n = 0;
        Scanner input=new Scanner(System.in);
        System.out.print("n: ");
        n=input.nextInt();
        int[] arr=new int[n];
        for (int i=0; i<n; i++){
            arr[i]=input.nextInt();
        }
        System.out.println("Unsorted");
        for (int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
        int count=1;
        while (count<n-1){
            for (int i=0; i<n-count; i++){
                if(arr[i]>arr[i+1]){
                    int temp=arr[i];
                    arr[i]=arr[i+1];
                    arr[i+1]=temp;
                }
            }
            count++;
        }
        System.out.println("Sorted");
        for (int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
