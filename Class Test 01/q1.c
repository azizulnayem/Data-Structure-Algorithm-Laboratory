#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* commonPrefixUtil(const char* str1, const char* str2) {
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    int i;
    for (i = 0; i < n1 && i < n2; i++) {
        if (str1[i] != str2[i]) {
            break;
        }
    }
    char* prefix = (char*)malloc((i + 1) * sizeof(char));
    strncpy(prefix, str1, i);
    prefix[i] = '\0';
    return prefix;
}
char* longestCommonPrefix(char* arr[], int low, int high) {
    if (low == high) {
        char* singleStringPrefix = (char*)malloc((strlen(arr[low]) + 1) * sizeof(char));
        strcpy(singleStringPrefix, arr[low]);
        return singleStringPrefix;
    }
    int mid = (low + high) / 2;

    char* leftLCP = longestCommonPrefix(arr, low, mid);

    char* rightLCP = longestCommonPrefix(arr, mid + 1, high);

    char* finalLCP = commonPrefixUtil(leftLCP, rightLCP);

    free(leftLCP);
    free(rightLCP);

    return finalLCP;
}

int main() {

    char* arr1[] = {"Algolab", "Algorithms", "Algeria"};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    char* result1 = longestCommonPrefix(arr1, 0, n1 - 1);
    if (strlen(result1) > 0) {
        printf("Output: %s\n", result1);
    } else {
        printf("Output: None\n");
    }
    free(result1);


    char* arr2[] = {"Algolab", "Algorithms", "Bulgeria"};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    char* result2 = longestCommonPrefix(arr2, 0, n2 - 1);
    if (strlen(result2) > 0) {
        printf("Output: %s\n", result2);
    } else {
        printf("Output: None\n");
    }
    free(result2);

    return 0;
}
