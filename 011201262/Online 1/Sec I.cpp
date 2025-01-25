#include<stdio.h>
struct Customer
{
    char name[50];
    char phoneNumber[11];
    int membershipNumber;
    int totalPoints;
};
typedef struct Customer Customer;

void menu()
{
    printf("1. Show the information of the customer\n");
    printf("2. Kth most valuable customer\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int findIndex(Customer arr[], int n, int membershipNumber)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i].membershipNumber==membershipNumber)
            return i;
    }
    return -1;
}

void sortCustomersPoints(Customer arr[], int n)
{
    /// Insertion Sort
    for(int i=1; i<n; i++)
    {
        Customer key = arr[i];
        int candidateIndex = i;
        while(candidateIndex>0 && arr[candidateIndex-1].totalPoints<key.totalPoints)
        {
            arr[candidateIndex] = arr[candidateIndex-1];
            candidateIndex--;
        }
        arr[candidateIndex] = key;
    }
    return;
}

int main()
{
    int n;
    printf("Enter the number of the customer: ");
    scanf("%d", &n);
    Customer arr[n];
    for(int i=0; i<n; i++)
    {
        getchar();
        printf("Information of customer %d\nName: ", i+1);
        gets(arr[i].name);
        printf("Phone Number: ");
        gets(arr[i].phoneNumber);
        printf("Membership Number: ");
        scanf("%d", &arr[i].membershipNumber);
        printf("Total Points: ");
        scanf("%d", &arr[i].totalPoints);
    }

    /// applying sorting algorithm to sort the customers based on their total points
    sortCustomersPoints(arr, n);

    while(true)
    {
        menu();
        int option;
        scanf("%d", &option);
        switch(option)
        {
        case 1:
        {
            printf("Enter the membership number of the customer: ");
            int membershipNumber;
            scanf("%d", &membershipNumber);
            int index = findIndex(arr, n, membershipNumber);
            if(index==-1)
                printf("[NOT FOUND] The membership number is not available in the customer list\n");
            else
            {
                printf("Name: %s, Phone Number: %s, Total Points: %d\n",arr[index].name, arr[index].phoneNumber, arr[index].totalPoints);
            }
            break;
        }
        case 2:
        {
            printf("Enter the position (K): ");
            int K;
            scanf("%d", &K);
            printf("The information of K th most valuable customer....\n");
            printf("Name: %s, Phone Number: %s, Membership Number: %d, Total Points: %d\n",arr[K-1].name, arr[K-1].phoneNumber, arr[K-1].membershipNumber, arr[K-1].totalPoints);
            break;
        }
        case 3:
        {
            printf("Terminating the program.....");
            return 0;
            break;
        }
        }
    }

    return 0;
}