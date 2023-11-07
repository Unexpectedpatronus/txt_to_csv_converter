#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "dynamic_array.h"

void readDataFromFile(const char *file_name, DynamicArray *array);
int compareStrings(const void *a, const void *b);
void sortDynamicArray(DynamicArray *array);
void writeDataToCSV(const char *csv_file, DynamicArray *array);

#endif
