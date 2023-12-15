#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_TREE_HT 100

class MinHeapNode {
public:
  char data;
  unsigned freq;
  MinHeapNode* left;
  MinHeapNode* right;
};

class MinHeap {
public:
  unsigned size;
  unsigned capacity;
  vector<MinHeapNode*> array;
};

class MyComparator {
public:
  bool operator() (MinHeapNode* a, MinHeapNode* b) {
    return a->freq > b->freq;
  }
};

MinHeapNode* newNode(char data, unsigned freq) {
  MinHeapNode* temp = new MinHeapNode();
  temp->left = temp->right = nullptr;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

MinHeap* createMinHeap(unsigned capacity) {
  MinHeap* minHeap = new MinHeap();
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array.resize(capacity);
  return minHeap;
}

void swapMinHeapNode(MinHeapNode*& a, MinHeapNode*& b) {
  MinHeapNode* t = a;
  a = b;
  b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
    smallest = left;
  }

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
    smallest = right;
  }

  if (smallest != idx) {
    swapMinHeapNode(minHeap->array[smallest], minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

bool isSizeOne(MinHeap* minHeap) {
  return (minHeap->size == 1);
}

MinHeapNode* extractMin(MinHeap* minHeap) {
  MinHeapNode* temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }

  minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap* minHeap) {
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i) {
    minHeapify(minHeap, i);
  }
}

void printArr(int arr[], int n) {
  int i;
  for (i = 0; i < n; ++i) {
    cout << arr[i];
  }

  cout << endl;
}

bool isLeaf(MinHeapNode* root) {
  return !(root->left) && !(root->right);
}

MinHeap* createAndBuildMinHeap(vector<char>& data, vector<unsigned>& freq, int size) {
  MinHeap* minHeap = createMinHeap(size);

  for (int i = 0; i < size; ++i) {
    minHeap->array[i] = newNode(data[i], freq[i]);
  }

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

MinHeapNode* buildHuffmanTree(vector<char>& data, vector<unsigned>& freq, int size) {
  MinHeapNode* left, * right, * top;
  MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

  while (!isSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);

    cout << "Combining: " << left->data << "(" << left->freq << ") + " << right->data << "(" << right->freq << ") = " << top->data << "(" << top->freq << ")\n";
  }

  cout << "Huffman Tree Construction Complete!\n";

  return extractMin(minHeap);
}

int printCodes(MinHeapNode* root, int arr[], int top, int totalBits) {
  if (root->left) {
    arr[top] = 0;
    totalBits = printCodes(root->left, arr, top + 1, totalBits);
  }

  if (root->right) {
    arr[top] = 1;
    totalBits = printCodes(root->right, arr, top + 1, totalBits);
  }

  if (isLeaf(root)) {
    cout << root->data << ": ";
    printArr(arr, top);
    totalBits += top * root->freq;
  }
  return totalBits;
}

int HuffmanCodes(vector<char>& data, vector<unsigned>& freq, int size) {
  MinHeapNode* root = buildHuffmanTree(data, freq, size);
  int arr[MAX_TREE_HT], top = 0;
  int totalBits = printCodes(root, arr, top, 0); // Pass totalBits as 0 initially
  cout << "Huffman Codes Generated!" << endl;
  cout << "Total bits required for encoding: " << totalBits << endl;
  return totalBits;
}

int main() {
  int size;
  cout << "Enter the number of characters: ";
  cin >> size;

  vector<char> arr(size);
  vector<unsigned> freq(size);

  cout << "Enter the characters and their frequencies:" << endl;
  for (int i = 0; i < size; i++) {
    cin >> arr[i] >> freq[i];
  }

  int totalBits = HuffmanCodes(arr, freq, size);
  return 0;
}