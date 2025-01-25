package com.company;
//Selection Sort
class SelectionSort{
    void sort(int arr[]){
        int n=arr.length;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(arr[j]<arr[i]){
                    int temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                }
            }
        }
    }
    void printArray(int arr[]){
        int n=arr.length;
        for (int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
public class Main3 {
    public static void main(String[] args) {

        SelectionSort ob=new SelectionSort();
        int arr[]={64,25,12,22,11};
        System.out.println("Unsorted Array");
        ob.printArray(arr);
        ob.sort(arr);
        System.out.println("Sorted Array");
        ob.printArray(arr);
    }
}
