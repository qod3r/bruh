#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
 
FILE *arrayFile;
FILE *sortedArrayFile;
 
char * CreateArrayFile(char *);
void BubbleSort(char *);
void SelectionSort(char *);
int ElementsCount(char *);
 
 
 
int main() {
    setlocale(LC_ALL, "Russian");
    char filename[50];
    CreateArrayFile(filename);
    BubbleSort(filename);
    SelectionSort(filename);
    
    return 0;
}
 
char * CreateArrayFile(char *filename) {
    int n = 0;
    
    
    printf("Введите имя файла(*.txt) ");
    scanf("%s", filename);
    
    arrayFile = fopen(filename, "w");
    printf("Введите размерность массива\n");
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++) {
        int element = (rand() % 201) - 100;
        fprintf(arrayFile, "%d ", element);
    }
    
    fclose(arrayFile);
    return filename;
}
 
int ElementsCount(char *filename) {
    int c;
    int count = 0;
    arrayFile = fopen(filename, "r");
 
    if (arrayFile == NULL)
        return 0;
    for (c = getc(arrayFile); c != EOF; c = getc(arrayFile)) {
        if (c == ' ')
            count++;
    }
    fclose(arrayFile);
    return count;
}
 
void BubbleSort(char *filename) {
    int n = ElementsCount(filename);
    arrayFile = fopen(filename, "r");
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(arrayFile, "%d", &arr[i]);
    }
    fclose(arrayFile);
    
    //Сортирвока обменами
    for (int i = 0; i < n - 1; i++)
     {
       for (int j = (n - 1); j > i; j--){
         if (arr[j - 1] > arr[j]){
           int temp = arr[j - 1];
           arr[j - 1] = arr[j];
           arr[j] = temp;
         }
       }
     }
    
    sortedArrayFile = fopen("sortedArray_Bubble.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(sortedArrayFile, "%d ", arr[i]);
    }
    fclose(sortedArrayFile);
}
 
void SelectionSort(char *filename) {
    int n = ElementsCount(filename);
    arrayFile = fopen(filename, "r");
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(arrayFile, "%d", &arr[i]);
    }
    fclose(arrayFile);
    
    //Сортирвока выбором
    int min, temp;
      for (int i = 0; i < n - 1; i++){
        min = i;
        for (int j = i + 1; j < n; j++){
          if (arr[j] < arr[min])
            min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
      }
    
    sortedArrayFile = fopen("sortedArray_Selection.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(sortedArrayFile, "%d ", arr[i]);
    }
    fclose(sortedArrayFile);
}
