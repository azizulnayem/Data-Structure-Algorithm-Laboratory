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

        if (l < size && heap[l] < heap[largest])
          largest = l;

        if (r < size && heap[r] < heap[largest])
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
int changeKey(int old, int new)
{
        int i, idx=-1;
      for (i = 0; i < size; i++)
      {
        if (old == heap[i])
        {
            idx=i;
            heap[i]-=new;
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
int main()
{

    while(1)
    {
        printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
        printf("1. Insert new Key. 2. Replace Key. 3. Print Heap. 4. Exit. \n");
        printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");

        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Insert: ");
            int item;
            scanf("%d", &item);
            int res=insert(item);
            if(res==SUCCESS_VAL)
                printf("Inserted successfully\n");
        }

        else if(choice==2)
        {
            printf("give an item to replace: ");
            int item;
            scanf("%d", &item);

            printf("replaced by : ");
            int rep;
            scanf("%d", &rep);

            int res=changeKey(item, rep);
            if(res==SUCCESS_VAL)
                printf("Replaced successfully\n");
        }
        else if(choice==3)
        {
            printHeap();
        }
        else if(choice==4)
        {
            break;
        }
    }

}
