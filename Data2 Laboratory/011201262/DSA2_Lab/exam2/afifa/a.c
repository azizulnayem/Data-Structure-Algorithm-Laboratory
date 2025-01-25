#include <stdio.h>
#include <math.h>

int main() {
    int n, term;


     int k;

     scanf("%d",&k);
     int sum = 0;

    for (n = 1; n <= k; n++) {
        term = 4 * pow(n, 2) - 7 * n + 3;
        printf("%d, ", term);
        sum+=term;
    }

    printf("Sum = %d", sum);

    return 0;
}
