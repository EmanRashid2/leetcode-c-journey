#include <stdlib.h>
#include <string.h>

unsigned long hash(const char* str) {
    unsigned long h = 5381;
    int c;
    while ((c = *str++))
        h = ((h << 5) + h) + c; // h = h*33 + c
    return h;
}

char* sortString(const char* s) {
    int n = strlen(s);
    char* copy = (char*)malloc(n + 1);
    strcpy(copy, s);

    // simple bubble sort (n <= 100, fine)
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (copy[i] > copy[j]) {
                char tmp = copy[i];
                copy[i] = copy[j];
                copy[j] = tmp;
            }

    return copy;
}

typedef struct Node {
    char* key;
    char** list;
    int size;
    int capacity;
    struct Node* next;
} Node;

#define TABLE_SIZE 2003

int** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Node* table[TABLE_SIZE] = {0};
    Node* groups[2000];
    int groupsCount = 0;

    for (int i = 0; i < strsSize; i++) {
        char* key = sortString(strs[i]);
        unsigned long h = hash(key) % TABLE_SIZE;

        Node* node = table[h];
        while (node) {
            if (strcmp(node->key, key) == 0) {
                break;
            }
            node = node->next;
        }

        if (!node) {
            node = (Node*)malloc(sizeof(Node));
            node->key = key;
            node->capacity = 4;
            node->size = 0;
            node->list = (char**)malloc(sizeof(char*) * node->c**

