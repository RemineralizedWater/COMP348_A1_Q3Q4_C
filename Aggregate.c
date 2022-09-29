//
// Created by RemineralizedWater on 5/9/2022.
//
#include <stdio.h>
#include <stdlib.h>

#include "Aggregate.h"

float min(const float* arr, int size) {
    if (arr == NULL || size < 1) {
        printf("FATAL ERROR in line %d", __LINE__);
        exit(-1);
    }

    float min = arr[0];
    for (int i = 0; i < size; i++) {
        if(min > arr[i]) {
            min = arr[i];
        }
    }

    return min;
}

float max(const float* arr, int size) {
    if (arr == NULL || size < 1) {
        printf("FATAL ERROR in line %d", __LINE__);
        exit(-1);
    }

    float max = arr[0];
    for (int i = 0; i < size; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

float sum(const float* arr, int size) {
    if (arr == NULL || size < 1) {
        printf("FATAL ERROR in line %d", __LINE__);
        exit(-1);
    }

    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

float avg(const float* arr, int size) {
    if (arr == NULL || size < 1) {
        printf("FATAL ERROR in line %d", __LINE__);
        exit(-1);
    }

    return sum(arr, size)/(float)size;
}

float pseudo_avg(const float* arr, int size) {
    if (arr == NULL || size < 1) {
        printf("FATAL ERROR in line %d", __LINE__);
        exit(-1);
    }

    return (min(arr, size)+max(arr, size))/2;
}