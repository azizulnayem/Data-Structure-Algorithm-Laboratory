#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print_optimal_bst(int** root, int i, int j, int level, double keys[]) {
    if (i <= j) {
        int r = root[i][j];
        printf("%*sL:%d\n", level, "", r);
        print_optimal_bst(root, i, r - 1, level + 2, keys);
        print_optimal_bst(root, r + 1, j, level + 2, keys);
    } else {
        printf("%*sR:dummy\n", level, "");
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double p[n + 1];
    double q[n + 2];

    double keys[n + 1];

    for (int i = 1; i <= n; ++i) {
        double key, prob;
        printf("Key %d: ", i);
        scanf("%lf %lf", &key, &prob);
        keys[i] = key;
        p[i] = prob;
    }

    for (int i = 0; i <= n; ++i) {
        double low = (i == 0) ? 0 : keys[i];
        double high = (i == n) ? keys[n] : keys[i + 1];
        printf("D%d (", i);
        if (i == 0) {
            printf("<%.0lf", high);
        } else if (i == n) {
            printf(">%.0lf", low);
        } else {
            printf("%.0lf-%.0lf", low, high);
        }
        printf("): ");
        scanf("%lf", &q[i]);
    }

    double e[n + 2][n + 1];
    double w[n + 2][n + 1];
    int** root = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; ++i) {
        root[i] = (int*)malloc((n + 1) * sizeof(int));
    }

    for (int i = 1; i <= n + 2; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; ++r) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Cost = %.2f\n", e[1][n]);
    print_optimal_bst(root, 1, n, 0, keys);

    // Free allocated memory
    for (int i = 0; i <= n; ++i) {
        free(root[i]);
    }
    free(root);

    return 0;
}
