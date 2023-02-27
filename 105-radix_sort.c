#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void counting_sort(int *array, size_t size, int place) {
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};

    for (size_t i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = (int)size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (size_t i = 0; i < size; i++) {
        array[i] = output[i];
    }

    free(output);
}

void radix_sort(int *array, size_t size) {
    int max = array[0];
    int prev_max_digits = 0;

    for (size_t i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    for (int place = 1; max / place > 0; place *= 10) {
        counting_sort(array, size, place);

        int current_max_digits = 0;
        int temp_max = max;
        while (temp_max != 0) {
            current_max_digits++;
            temp_max /= 10;
        }

        if (current_max_digits > prev_max_digits) {
            prev_max_digits = current_max_digits;
            for (size_t i = 0; i < size; i++) {
                printf("%d, ", array[i]);
            }
            printf("\n");
        }
    }
}

