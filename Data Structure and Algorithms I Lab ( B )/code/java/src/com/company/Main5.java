package com.company;

import java.util.Scanner;

//Insertion Sort
class InserSort{
    void Sort(int[] arr){
        int n=arr.length;
        for(int i=1; i<n; i++){
            int key=arr[i];
            int j=i-1;
            while (j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j=j-1;
            }
            arr[j+1]=key;
        }
    }
    void Input(int[] arr){
        int n=arr.length;
        Scanner input=new Scanner(System.in);
        for(int i=0; i<n; i++){
            arr[i]=input.nextInt();
        }

    }
    void PrintArray(int[] arr){
        int n=arr.length;
        for (int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
public class Main5 {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.print("n: ");
        int n=in.nextInt();

        InserSort is=new InserSort();
        int[] arr = new int[n];
        is.Input(arr);
        is.Sort(arr);
        System.out.println("Sorted");
        is.PrintArray(arr);
    }
}
