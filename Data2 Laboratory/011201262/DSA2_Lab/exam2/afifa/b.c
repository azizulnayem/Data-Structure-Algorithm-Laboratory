#include <stdio.h>
int main() {
    int n, marks[100];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    int max = -1;
    int max_index = -1;

    for (int i = 0; i < n; i++) {
        if (marks[i] % 2 == 0 && marks[i] > max) {
            max = marks[i];
            max_index = i;
        }
    }

    if (max_index == -1)
        printf("No even number\n");
     else
        printf("Maximum of even numbers = %d at index %d.\n", max, max_index);
    return 0;
}

