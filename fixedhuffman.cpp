#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

// Define a struct to represent a node in the Huffman tree
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Define a custom comparison function for nodes in the priority queue
struct CompareNodes {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Function to arrange characters in ascending order of frequency
priority_queue<Node*, vector<Node*>, CompareNodes> arrangeInAscendingOrder(map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap;

    for (auto& pair : frequencies) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    return minHeap;
}

// Function to build the Huffman tree
Node* buildHuffmanTree(priority_queue<Node*, vector<Node*>, CompareNodes>& minHeap) {
    while (minHeap.size() > 1) {
        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* internalNode = new Node('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

// Function to generate Huffman codes for characters
void generateCodes(Node* root, string code, map<char, string>& codes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '\0') {
        codes[root->data] = code;
    }

    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Function to calculate the total bits required for encoding
int calculateTotalBits(map<char, int>& frequencies, map<char, string>& codes) {
    int totalBits = 0;

    for (auto& pair : frequencies) {
        totalBits += pair.second * codes[pair.first].length();
    }

    return totalBits;
}

int main() {
    map<char, int> frequencies;
    int numCharacters;

    cout << "Enter the number of characters: ";
    cin >> numCharacters;

    cout << "Enter character frequencies:" << endl;
    for (int i = 0; i < numCharacters; ++i) {
        char character;
        int frequency;

        cout << "Character " << i + 1 << ": ";
        cin >> character;

        cout << "Frequency: ";
        cin >> frequency;

        frequencies[character] = frequency;
    }

    priority_queue<Node*, vector<Node*>, CompareNodes> minHeap = arrangeInAscendingOrder(frequencies);

    Node* root = buildHuffmanTree(minHeap);

    map<char, string> codes;
    generateCodes(root, "", codes);

    cout << "Huffman Codes:" << endl;
    for (const auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    int totalBits = calculateTotalBits(frequencies, codes);
    cout << "Total Bits Required: " << totalBits << endl;

    return 0;
}

// Enter the number of characters: 5
// Enter character frequencies:
// Character 1: A
// Frequency: 45
// Character 2: B
// Frequency: 13
// Character 3: C
// Frequency: 12
// Character 4: D
// Frequency: 9
// Character 5: E
// Frequency: 5
// Time Complexity: O(n * log(n))
// Space Complexity: O(n)