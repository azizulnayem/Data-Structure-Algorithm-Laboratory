#include <stdio.h>

typedef struct {
    int even_count;
    int odd_count;
} Counts;

Counts count_evens_odds(int arr[], int start, int end) {
    Counts counts;
    if (start == end) {
        if (arr[start] % 2 == 0) {
            counts.even_count = 1;
            counts.odd_count = 0;
        } else {
            counts.even_count = 0;
            counts.odd_count = 1;
        }
    } else {
        int mid = (start + end) / 2;
        Counts left_counts = count_evens_odds(arr, start, mid);
        Counts right_counts = count_evens_odds(arr, mid + 1, end);
        counts.even_count = left_counts.even_count + right_counts.even_count;
        counts.odd_count = left_counts.odd_count + right_counts.odd_count;
    }
    return counts;
}

const char* declare_winner(int arr[], int n) {
    Counts counts = count_evens_odds(arr, 0, n - 1);
    if (counts.even_count > counts.odd_count) {
        return "EVEN";
    } else if (counts.odd_count > counts.even_count) {
        return "ODD";
    } else {
        return "DRAW";
    }
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    const char* winner = declare_winner(arr, n);
    printf("%s\n", winner);

    return 0;
}
