#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int calculateParityBits(int dataBits) {
    int r = 1;

    while (!(pow(2, r-1) < dataBits && dataBits < pow(2, r))) {
        r++;
    }

    return r;
}

unsigned int bitsToInt(const int *bits, int size) {
    unsigned int result = 0;

    for (int i = size - 1; i >= 0; i--) {
        result = (result << 1) | bits[i];
    }

    return result;
}

int findSyndrom(int* hamming, int dataBits) {
    int r = calculateParityBits(dataBits);
    int *syndromArray = calloc(r, sizeof(int));

    for (int i = 0; i < r; i++) {
        int temp = 0;
        int gap = pow(2, i);
        for (int currentIndex = gap - 1; currentIndex < dataBits; currentIndex += 2 * gap) {
            for (int j = 0; j < gap && (currentIndex + j) < dataBits; j++) {
                temp = temp ^ hamming[currentIndex + j];
            }
        }
        syndromArray[i] = temp;
    }

    int result = bitsToInt(syndromArray, r);
    free(syndromArray);
    syndromArray = NULL;

    return result;
}

int main() {
    int dataBits;
    
    printf("Enter the number of data bits in Hamming code: ");
    scanf("%d", &dataBits);

    int *hamming = calloc(dataBits, sizeof(int));
    int *data = calloc(dataBits - calculateParityBits(dataBits), sizeof(int));

    printf("Enter the Hamming code bits (0 or 1):\n");
    for (int i = 0; i < dataBits; i++) {
        scanf("%d", &hamming[i]);
    }

    unsigned int syndrom = findSyndrom(hamming, dataBits);

    if (syndrom) {
        if (syndrom < dataBits) {
            printf("The error is in bit number %d.\n", syndrom);
            printf("Corrected code: ");
            for (int i = 0; i < syndrom - 1; i++) {
                printf("%d ", hamming[i]);
            }
            printf("%d ", !hamming[syndrom - 1]);
            for (int i = syndrom; i < dataBits; i++) {
                printf("%d ", hamming[i]);
            }
        } else {
            printf("There is more than one error in provided code.");
        }
    } else {
        printf("No errors detected. Provided Hamming code is correct.");
    }

    free(data);
    data = NULL;
    free(hamming);
    hamming = NULL;

    return 0;
}