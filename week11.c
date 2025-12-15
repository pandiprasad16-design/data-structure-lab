#include <stdio.h>
#include <string.h>

#define SIZE 10
#define EMPTY_KEY "EMPTY"

typedef struct {
    char key[20];
    char value[50];
} Dict;

void init(Dict dict[]) {
    for (int i = 0; i < SIZE; i++) {
        strcpy(dict[i].key, EMPTY_KEY);
    }
}

int hashFunction(char *key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++)
        sum += key[i];
    return sum % SIZE;
}

void insert(Dict dict[], char *key, char *value) {
    int index = hashFunction(key);

    while (strcmp(dict[index].key, EMPTY_KEY) != 0) {
        index = (index + 1) % SIZE;  // linear probing
    }
    strcpy(dict[index].key, key);
    strcpy(dict[index].value, value);
}

void search(Dict dict[], char *key) {
    int index = hashFunction(key);
    int start = index;

    while (strcmp(dict[index].key, EMPTY_KEY) != 0) {
        if (strcmp(dict[index].key, key) == 0) {
            printf("Found: %s -> %s\n", key, dict[index].value);
            return;
        }
        index = (index + 1) % SIZE;

        if (index == start) break;
    }
    printf("Key not found!\n");
}

void display(Dict dict[]) {
    printf("\nDictionary (Hashing):\n");
    for (int i = 0; i < SIZE; i++) {
        if (strcmp(dict[i].key, EMPTY_KEY) != 0)
            printf("[%d] %s : %s\n", i, dict[i].key, dict[i].value);
        else
            printf("[%d] ---\n", i);
    }
}

int main() {
    Dict dict[SIZE];
    init(dict);

    insert(dict, "apple", "a fruit");
    insert(dict, "book", "a set of pages");
    insert(dict, "cat", "an animal");

    display(dict);

    search(dict, "book");
    search(dict, "dog");

    return 0;
}

