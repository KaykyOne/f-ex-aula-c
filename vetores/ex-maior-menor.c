#include <stdio.h>

void findLargestSmallest(int v[], int size) {
    int largest = v[0];
    int smallest = v[0];

    for (int i = 1; i < size; i++) {
        if (v[i] > largest) largest = v[i];
        if (v[i] < smallest) smallest = v[i];
    }

    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
}

int main() {
    int values[] = {12, 5, 78, 3, 42};
    findLargestSmallest(values, 5);
    return 0;
}
