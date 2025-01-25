package com.company;
//Insertion Sort

class InsertionSort{
    void sort(int[] arr){
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
    void printArray(int[] arr){
        int n=arr.length;
        for (int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
public class Main4 {
    public static void main(String[] args) {

        InsertionSort ob=new InsertionSort();
        int[] arr={64,25,12,22,11};
        System.out.println("Unsorted Array");
        ob.printArray(arr);
        ob.sort(arr);
        System.out.println("Sorted Array");
        ob.printArray(arr);
    }
}
