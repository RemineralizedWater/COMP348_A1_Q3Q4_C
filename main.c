#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Aggregate.h"

void switchFunction(int i) {
    switch (i) {
        case 0:
            printf ("Min");
            break;
        case 1:
            printf ("Max");
            break;
        case 2:
            printf ("Sum");
            break;
        case 3:
            printf ("Avg");
            break;
        case 4:
            printf ("Pseudo Avg");
            break;
        default:
            break;
    }
}

int main() {
    srand(time(0));
    int sizeFive = 5;
    int sizeTen = 10;
    float randomFive[sizeFive], randomTen[sizeTen];
    float (*aggregates[5])(float* arr, int size) = { &min, &max, &sum, &avg, &pseudo_avg };

    printf("Initializing array of %d random floats:\n", sizeFive);
    for (int i = 0; i < sizeFive; i++) {
        randomFive[i] = (float)(rand() % RAND_MAX) + (float)rand()/RAND_MAX - (float)RAND_MAX/2;
        printf("%f\n", randomFive[i]);
    }
    printf("\n");

    printf("Results running functions on array of %d random floats:\n", sizeFive);
    for (int i = 0; i < 5; i++) {
        switchFunction(i);
        printf(" is %f\n",aggregates[i](randomFive, sizeFive));
    }
    printf("\n");

    printf("Initializing array of %d random floats:\n", sizeTen);
    for (int i = 0; i < sizeTen; i++) {
        randomTen[i] = (float)(rand() % RAND_MAX) + (float)rand()/RAND_MAX - (float)RAND_MAX/2;
        printf("%f\n", randomTen[i]);
    }
    printf("\n");

    printf("Results running functions on array of %d random floats:\n", sizeTen);
    for (int i = 0; i < 5; i++) {
        switchFunction(i);
        printf(" is %f\n",aggregates[i](randomTen, sizeTen));
    }

    return 0;
}
