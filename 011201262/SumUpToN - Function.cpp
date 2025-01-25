#include<stdio.h>
int summationUpToN(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum = sum + i;
    }
    return sum;
}

int summationUpToNFormula(int n)
{
    return (n*(n+1))/2;
}
int main()
{
    int n;
    scanf("%d", &n);
    int sum = summationUpToNFormula(n);
    printf("%d\n", sum);
    return 0;
}
