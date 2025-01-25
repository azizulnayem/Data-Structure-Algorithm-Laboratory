#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool canFormPalindrome(const string& s) {
    unordered_map<char, int> charFreq;

    // Count the frequency of each character
    for (char c : s) {
        charFreq[c]++;
    }

    int oddCount = 0;

    // Count the number of characters with odd frequency
    for (const auto& entry : charFreq) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }

    // It's possible to form a palindrome if oddCount is 0 or 1
    return oddCount <= 1;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (canFormPalindrome(s)) {
        cout << "It's possible to rearrange the letters to form a palindrome.\n";
    } else {
        cout << "It's not possible to rearrange the letters to form a palindrome.\n";
    }

    return 0;
}
