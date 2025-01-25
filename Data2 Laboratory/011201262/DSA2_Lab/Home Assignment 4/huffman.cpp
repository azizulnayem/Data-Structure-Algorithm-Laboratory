#include<bits/stdc++.h>

using namespace std;


struct HuffmanNode {
    char data;
    int freq;
    HuffmanNode* left;
    HuffmanNode* right;
    HuffmanNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
    HuffmanNode(char data, int freq, HuffmanNode* left, HuffmanNode* right) {
        this->data = data;
        this->freq = freq;
        this->left = left;
        this->right = right;
    }
};


struct compare {
    bool operator()(HuffmanNode* l, HuffmanNode* r) {
        return l->freq > r->freq;
    }
};


bool isLeaf(HuffmanNode* root) {
    return root->left == nullptr && root->right == nullptr;
}

void encode(HuffmanNode* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr) {
        return;
    }
    if (isLeaf(root)) {
        huffmanCode[root->data] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}


HuffmanNode* buildHuffmanTree(unordered_map<char, int>& freq) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> pq;


    for (auto pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }


    while (pq.size() > 1) {

        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();


        int sum = left->freq + right->freq;
        pq.push(new HuffmanNode('\0', sum, left, right));
    }


    return pq.top();
}


string decode(HuffmanNode* root, string encodedString) {
    string decodedString;
    HuffmanNode* curr = root;
    for (char c : encodedString) {
        if (c == '0') {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        if (isLeaf(curr)) {
            decodedString += curr->data;
            curr = root;
        }
    }
    return decodedString;
}

int main() {
    string text = "Hello, world!";
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    HuffmanNode* root = buildHuffmanTree(freq);
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes are:\n";
    for (auto pair : huffmanCode) {
    cout << pair.first << " : " << pair.second << '\n';
    }

    string encodedString;
    for (char c : text) {
        encodedString += huffmanCode[c];
    }
    cout << "\nEncoded string is:\n" << encodedString << '\n';

    string decodedString = decode(root, encodedString);
    cout << "\nDecoded string is:\n" << decodedString << '\n';

    return 0;
}

