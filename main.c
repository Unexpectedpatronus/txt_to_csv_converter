#include <stdio.h>
#include <locale.h>
#include "dynamic_array.h"
#include "file_operations.h"


// ������� �������
int main(void) {
    setlocale(LC_ALL, "");

    const char file_name[] = "C:/Dev_C/txt_to_csv_converter/test_file.txt";
    const char csv_file[] = "new_file.csv";

    DynamicArray data;
    initDynamicArray(&data);

    readDataFromFile(file_name, &data);

    sortDynamicArray(&data);

    writeDataToCSV(csv_file, &data);

    freeDynamicArray(&data);

    printf("���� '%s' ������� ������!\n", csv_file);
    return 0;
}
