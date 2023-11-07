#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
    char **data;
    size_t size;
    size_t capacity;
} DynamicArray;

void initDynamicArray(DynamicArray *array);

void appendToDynamicArray(DynamicArray *array, const char *str);

void freeDynamicArray(DynamicArray *array);

#endif
