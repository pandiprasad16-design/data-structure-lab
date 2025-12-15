#include <stdio.h>

#define SIZE 10
#define EMPTY -1

void init(int hash[]) {
    for (int i = 0; i < SIZE; i++)
        hash[i] = EMPTY;
}

void insertLinear(int hash[], int key) {
    int index = key % SIZE;

    while (hash[index] != EMPTY) {
        index = (index + 1) % SIZE;  // linear probing
    }
    hash[index] = key;
}

void display(int hash[]) {
    printf("\nHash Table (Linear Probing):\n");
    for (int i = 0; i < SIZE; i++)
        printf("Index %d -> %d\n", i, hash[i]);
}

int main() {
    int hash[SIZE];
    init(hash);

    int keys[] = {12, 25, 35, 26, 92, 44};
    int n = sizeof(keys)/sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        insertLinear(hash, keys[i]);

    display(hash);
    return 0;
}

