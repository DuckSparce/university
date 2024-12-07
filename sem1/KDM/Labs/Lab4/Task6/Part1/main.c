#include <stdio.h>
#include <stdlib.h>

int calculateParityBits(int dataBits) {
    int r = 1;
    while ((1 << r) < (dataBits + r + 1)) {
        r++;
    }
    return r;
}

void insertParityBits(int *data, int dataBits, int *hamming) {
    int r = calculateParityBits(dataBits);
    int i, j, k;

    for (i = 0, j = 0, k = 1; i < dataBits + r; i++) {
        if (i + 1 == k) {
            hamming[i] = 0;
            k <<= 1;
        } else {
            hamming[i] = data[j++];
        }
    }

    for (i = 0; i < r; i++) {
        int parityBit = 0;
        for (j = (1 << i) - 1; j < dataBits + r; j += (1 << (i + 1))) {
            for (k = 0; k < (1 << i) && j + k < dataBits + r; k++) {
                parityBit ^= hamming[j + k];
            }
        }
        hamming[(1 << i) - 1] = parityBit;
    }
}

int main() {
    int dataBits;
    
    printf("Enter the number of data bits in initial code: ");
    scanf("%d", &dataBits);

    int *data = calloc(dataBits, sizeof(int));
    int *hamming = calloc(dataBits + calculateParityBits(dataBits), sizeof(int));

    printf("Enter the data bits (0 or 1):\n");
    for (int i = 0; i < dataBits; i++) {
        scanf("%d", &data[i]);
    }

    insertParityBits(data, dataBits, hamming);

    printf("Hamming Code:\n");
    for (int i = 0; i < dataBits + calculateParityBits(dataBits); i++) {
        printf("%d ", hamming[i]);
    }

    free(data);
    data = NULL;
    free(hamming);
    hamming = NULL;

    return 0;
}