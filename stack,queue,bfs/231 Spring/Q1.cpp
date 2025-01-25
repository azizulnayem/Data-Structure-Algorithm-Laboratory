#include <iostream>
#include <unordered_map>

bool canFormPalindrome(const std::string& str) {
    std::unordered_map<char, int> charFrequency;

    // Count the frequency of each character in the string.
    for (char ch : str) {
        charFrequency[ch]++;
    }

    int oddCount = 0;
    // Check the frequency count of each character.
    for (const auto& entry : charFrequency) {
        if (entry.second % 2 != 0) {
            oddCount++;
        }
    }

    // For a palindrome, at most one character can have an odd frequency.
    return oddCount <= 1;
}

int main() {
    std::string input;
    std::cin >> input;

    if (canFormPalindrome(input)) {
        std::cout << "Palindrome\n";
    } else {
        std::cout << "Not palindrome\n";
    }

    return 0;
}
