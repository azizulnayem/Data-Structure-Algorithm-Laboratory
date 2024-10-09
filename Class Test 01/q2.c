#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* commonSuffix(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = len1 - 1, j = len2 - 1;
    int k = 0;

    while (i >= 0 && j >= 0 && str1[i] == str2[j]) {
        i--;
        j--;
        k++;
    }

    char* suffix = (char*)malloc((k + 1) * sizeof(char));

    for (int l = 0; l < k; l++) {
        suffix[l] = str1[len1 - k + l];
    }
    suffix[k] = '\0';

    return suffix;
}

char* findLCS(char* strings[], int left, int right) {
    if (left == right) {
        return strings[left];
    }

    int mid = (left + right) / 2;
    char* lcsLeft = findLCS(strings, left, mid);
    char* lcsRight = findLCS(strings, mid + 1, right);
    char* lcs = commonSuffix(lcsLeft, lcsRight);

    if (lcsLeft != strings[left]) {
        free(lcsLeft);
    }
    if (lcsRight != strings[mid + 1]) {
        free(lcsRight);
    }

    return lcs;
}

int main() {

    char* strings1[] = {"Programmer", "Developer", "Engineer"};
    int n1 = sizeof(strings1) / sizeof(strings1[0]);
    char* result1 = findLCS(strings1, 0, n1 - 1);
    if (strlen(result1) > 0) {
        printf("Output: %s\n", result1);
    } else {
        printf("Output: None\n");
    }
    free(result1);


    char* strings2[] = {"Algolab", "Algorithms", "Bulgeria"};
    int n2 = sizeof(strings2) / sizeof(strings2[0]);
    char* result2 = findLCS(strings2, 0, n2 - 1);
    if (strlen(result2) > 0) {
        printf("Output: %s\n", result2);
    } else {
        printf("Output: None\n");
    }
    free(result2);

    return 0;
}
