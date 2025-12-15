#include <stdio.h>

#define SIZE 10
#define EMPTY -1

void init(int hash[]) {
    for (int i = 0; i < SIZE; i++)
        hash[i] = EMPTY;
}

void insertQuadratic(int hash[], int key) {
    int index = key % SIZE;
    int i = 1;

    while (hash[index] != EMPTY) {
        index = (index + i * i) % SIZE;  // quadratic probing: 1², 2², 3²...
        i++;
        if (i > SIZE) {
            printf("Hash Table Full!\n");
            return;
        }
    }
    hash[index] = key;
}

void display(int hash[]) {
    printf("\nHash Table (Quadratic Probing):\n");
    for (int i = 0; i < SIZE; i++)
        printf("Index %d -> %d\n", i, hash[i]);
}

int main() {
    int hash[SIZE];
    init(hash);

    int keys[] = {12, 25, 35, 26, 92, 44};
    int n = sizeof(keys)/sizeof(keys[0]);

    for (int i = 0; i < n; i++)
        insertQuadratic(hash, keys[i]);

    display(hash);
    return 0;
}

