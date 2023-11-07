#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"

#define BUFFER_SIZE 1000


// Чтение данных из файла с их последующим сохранением в динамическом массиве
void readDataFromFile(const char *file_name, DynamicArray *array) {
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        perror("Не удалось открыть файл");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        // Remove newline character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        appendToDynamicArray(array, buffer);
    }

    fclose(fp);
}


// Функция сравнения для qsort
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **) a, *(const char **) b);
}


// Сортировка строк в динамическом массиве
void sortDynamicArray(DynamicArray *array) {
    qsort(array->data, array->size, sizeof(char *), compareStrings);
}


// Запись данных в CSV-файл
void writeDataToCSV(const char *csv_file, DynamicArray *array) {
    FILE *fp = fopen(csv_file, "w");
    if (fp == NULL) {
        perror("Ошибка при создании файла");
        exit(1);
    }

    for (size_t i = 0; i < array->size; i++) {
        fprintf(fp, "%s\n", array->data[i]);
    }

    fclose(fp);
}