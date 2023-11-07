#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynamic_array.h"

#define INITIAL_CAPACITY 10


// Инициализация динамического массива
void initDynamicArray(DynamicArray *array) {
    array->data = malloc(sizeof(char *) * INITIAL_CAPACITY);
    if (array->data == NULL) {
        perror("Ошибка при попытке выделить память");
        exit(1);
    }
    array->size = 0;
    array->capacity = INITIAL_CAPACITY;
}


// Добавление строки в динамический массив
void appendToDynamicArray(DynamicArray *array, const char *str) {
    if (array->size == array->capacity) {
        array->capacity *= 2;
        char **temp = realloc(array->data, sizeof(char *) * array->capacity);
        if (temp == NULL) {
            perror("Ошибка при попытке выделить память");
            exit(1);
        }
        array->data = temp;
    }
    array->data[array->size] = strdup(str);
    if (array->data[array->size] == NULL) {
        perror("Ошибка при попытке выделить память");
        exit(1);
    }
    array->size++;
}


// Очистка выделенной памяти
void freeDynamicArray(DynamicArray *array) {
    for (size_t i = 0; i < array->size; i++) {
        free(array->data[i]);
    }
    free(array->data);
}