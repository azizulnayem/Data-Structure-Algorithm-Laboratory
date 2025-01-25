#include <stdio.h>
#define HEAP_CAPACITY 10
#define SUCCESS_VAL 99999
#define FAIL_VAL -99999

int size = 0;

int heap[HEAP_CAPACITY];

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(int i)
{
    if (size == 1)
    {
        return;

    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < size && heap[l] > heap[largest])
          largest = l;

        if (r < size && heap[r] > heap[largest])
          largest = r;

        if (largest != i)
        {
          swap(&heap[i], &heap[largest]);
          heapify(largest);
        }

    }
}


int insert(int newNum)
{
      if (size == 0)
      {
        heap[0] = newNum;
        size += 1;
        return SUCCESS_VAL;
      }
      else if (size<HEAP_CAPACITY)
      {
        heap[size] = newNum;
        size += 1;

        for (int i = (size-1)/2; i >= 0; i--)
        {
            heapify(i);
        }

        return SUCCESS_VAL;
      }
      else
      {
          printf("Heap Capacity reached. Insert Failed\n");
          return FAIL_VAL;
      }
}


int delete(int num)
{
      int i, idx=-1;

      if(size<=0){
            printf("empty heap\n");
            return FAIL_VAL;
        }

      for (i = 0; i < size; i++)
      {
        if (num == heap[i])
        {
            idx=i;
            break;
        }
      }

      if (idx==-1){
            printf("Key not found\n");
            return FAIL_VAL;
      }

      swap(&heap[i], &heap[size - 1]);
      size -= 1;

      for (int i = (size- 1)/2; i >= 0; i--)
      {
        heapify(i);
      }

      return SUCCESS_VAL;
}

int extractMax()
{
    if(size<=0){
        printf("empty heap\n");
        return FAIL_VAL;
    }

    int i;
    int max= heap[0];
    swap(&heap[0], &heap[size - 1]);
    size -= 1;

    heapify(0);

    return max;
}

int getMax()
{
    if(size<=0){
        printf("empty heap\n");
        return FAIL_VAL;
    }
    return heap[0];
}

void printHeap()
{
  for (int i = 0; i < size; ++i){
        if(i==0)
            printf("%d(root) ", heap[i]);
        else
            printf("%d(%d's child) ", heap[i], heap[(i-1)/2]);
  }

  printf("\n");
}

int increaseKey(int num, int increment)
{
      int i, idx=-1;
      for (i = 0; i < size; i++)
      {
        if (num == heap[i])
        {
            idx=i;
            heap[i]+=increment;
            break;
        }
      }
      if (idx==-1){
            printf("Key not found\n");
            return FAIL_VAL;
      }

      for (int i = (idx- 1)/2; i >= 0; i--)
      {
        heapify(i);
      }
      return SUCCESS_VAL;
}

int decreaseKey(int num, int decrement)
{
        int i, idx=-1;
      for (i = 0; i < size; i++)
      {
        if (num == heap[i])
        {
            idx=i;
            heap[i]-=decrement;
            break;
        }
      }
      if (idx==-1){
            printf("Key not found\n");
            return FAIL_VAL;
      }

      heapify(idx);
      return SUCCESS_VAL;

}
int heapSort(int arr[], int size)
{
    int i;

    for(i=0;i<size;i++){
            insert(arr[i]);
    }

    for(i=0;i<size;i++){
            int key= extractMax();
            arr[i]=key;
    }

}

int main()
{

    while(1)
    {
        printf("*******************************************************************\n");
        printf("1. Insert new Key. 2. Delete Key. 3. Extract max. 4. Get max.  \n");
        printf("5. Increase Key. 6. Decrease Key. 7. Print Heap. 8. Heap Sort. 9. exit.\n");
        printf("*******************************************************************\n");

        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("give an item to insert: ");
            int item;
            scanf("%d", &item);
            int res=insert(item);
            if(res==SUCCESS_VAL)
                printf("inserted successfully\n");
        }
        else if(choice==2)
        {
            printf("give an item to delete: ");
            int item;
            scanf("%d", &item);
            int res=delete(item);
            if(res==SUCCESS_VAL)
                printf("deleted successfully\n");
        }
        else if(choice==3)
        {
            int res=extractMax();

            if(res!=FAIL_VAL) printf("The max key is: %d.\n", res);
        }
        else if(choice==4)
        {
            int res=getMax();

            if(res!=FAIL_VAL) printf("The max key is: %d.\n", res);
        }
        else if(choice==5)
        {
            printf("give an item to increment: ");
            int item;
            scanf("%d", &item);

            printf("increment by : ");
            int inc;
            scanf("%d", &inc);

            int res=increaseKey(item, inc);
            if(res==SUCCESS_VAL)
                printf("Increased successfully\n");
        }
        else if(choice==6)
        {
            printf("give an item to decrement: ");
            int item;
            scanf("%d", &item);

            printf("decrement by : ");
            int dec;
            scanf("%d", &dec);

            int res=decreaseKey(item, dec);
            if(res==SUCCESS_VAL)
                printf("Decreased successfully\n");
        }
        else if(choice==7)
        {
            printHeap();
        }
         else if(choice==8)
        {
            printf("size of the array: ");
            int len,i ;
            scanf("%d", &len);

            printf("Enter %d numbers : ",len);
            int arr[len];
            for(i=0;i<len;i++)
                scanf("%d", &arr[i]);
            int res=heapSort(arr, len);
            printf("After Sorting : \n");
            for(i=0;i<len;i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
        else if(choice==9)
        {
            break;
        }
    }

}
