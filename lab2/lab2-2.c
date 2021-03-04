#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
FILE *arrayFile;
FILE *sortedArrayFile;
 
void CreateArray(int [], int n);
void BubbleSort(int [], int n);
 
unsigned long long int comparisons = 0, swaps = 0, intermediate = 0;
 
int main() {
    setlocale(LC_ALL, "Russian");
    FILE *csv = fopen("data.csv", "w");
    for (int i = 100; i <= 10000; i += 100) {
        for (int j = 0; j < 5; j++) {
            int arr[i];
            CreateArray(arr, i);
            BubbleSort(arr, i);
            intermediate += (unsigned long long int)(comparisons+swaps)/2; 
            comparisons = 0, swaps = 0;
        }
        fprintf(csv, "%d; %lld\n", i, (unsigned long long int)intermediate/5);
        intermediate = 0;
    }
    printf("Выполнено, результаты в data.csv\nНажмите Enter, чтобы продолжить..."); getchar();
    return 0;
}
 
void CreateArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 20001) - 10000;
    }
}
 
void BubbleSort(int arr[], int n) {
    int i, j, temp;
    
    //Сортировка обменами
    for (i = 0; i < n - 1; i++) {
        for (j = (n - 1); j > i; j--){
            comparisons++;
            if (arr[j - 1] > arr[j]){
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
                swaps++;
            }
        }
    }
}