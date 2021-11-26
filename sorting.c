# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>

# include "sorting.h"
# include "time.h"

/****
 * Calculates the amount of time it takes to run a function
****/
float Calculate_Runtime(clock_t end, clock_t start){
    return (double)(end - start) / CLOCKS_PER_SEC;
}


/****
 * Prints the array
****/
void printArr(int arr[], int ARRSIZE){
    for(int x = 0; x <= ARRSIZE; x++){
        printf("%d\t%d\n", x, arr[x]);
    }
}


void Run_Sorting_Algorithms(int ARRSIZE){
    // Creating a massive array of random integers between 0 and 300
    //int ARRSIZE = 60000;
    int intArr[ARRSIZE];

    for(int x = 0; x <= ARRSIZE; x++){
        intArr[x] = rand() % 300;
        // printf("%d\t%d\n", x, intArr[x]);
    }

    // Insetion sort stuff
    int insertionArr[ARRSIZE];          // Copy Array
    for(int x = 0; x <= ARRSIZE; x++){
        insertionArr[x] = intArr[x];
        // printf("%d\t%d\n", x, intArr[x]);
    }
    insertionsort(insertionArr, ARRSIZE);

    // Selection sort stuff
    int selectionArr[ARRSIZE];          // Copy Array
    for(int x = 0; x <= ARRSIZE; x++){
        selectionArr[x] = intArr[x];
    }
    selectionSort(selectionArr, ARRSIZE);

    // Bubble sort stuff
    int bubbleArr[ARRSIZE];
    for(int x = 0; x <= ARRSIZE; x++){
        bubbleArr[x] = intArr[x];
    }
    bubbleSort(bubbleArr, ARRSIZE);
}


/****
 * Insertion Sort
****/
void insertionsort(int insertionArr[], int ARRSIZE){
    clock_t start = clock();        // Start timer

    //int i;
    int j;
    int key;

    for(int i = 1; i <= ARRSIZE; i++){
        key = insertionArr[i];          // The value that is being compared
        j = i - 1;                      // The value that is one element to the left of the key value
        // Iterate through the array leftwards until the key is in the right order
        while(j >= 0 && insertionArr[j] > key){
            insertionArr[j + 1] = insertionArr[j];
            j = j - 1;
        }
        insertionArr[j + 1] = key;
    }

    clock_t end = clock();      // End timer

    // printArr(insertionArr, ARRSIZE);     // Prints the array

    double runtime = Calculate_Runtime(end, start);
    printf("\nInsertion Sort completed:\t%f seconds\n", runtime);
}


/****
 * Selection Sort
****/
void selectionSort(int selectionArr[], int ARRSIZE){
    clock_t start = clock();        // Start timer

    int i, j, minimumIndex;

    // Iterate through the array
    for(i = 0; i <= ARRSIZE; i++){      // Goes to the next element in the unsorted part of the array
        minimumIndex = i;
        for (j = i + 1; j < ARRSIZE + 1; j++){
            if(selectionArr[j] < selectionArr[minimumIndex]) minimumIndex = j;
        }
        int temp = selectionArr[minimumIndex];
        selectionArr[minimumIndex] = selectionArr[i];
        selectionArr[i] = temp;
    }

    clock_t end = clock();      // End timer

    //printArr(selectionArr, ARRSIZE);     // Prints the array

    double runtime = Calculate_Runtime(end, start);
    printf("\nSelection Sort completed:\t%f seconds\n", runtime);
}


/****
 * Bubble Sort
****/
void bubbleSort(int bubbleArr[], int ARRSIZE){
    clock_t start = clock();

    // For ARRSIZE - 1 number of passes
    for(int i = 0; i < ARRSIZE; i++){
        // All the items less than i are already sorted so we iterate past them
        for (int j = 0; j <= ARRSIZE - 1 - i; j++){
            if(bubbleArr[j] > bubbleArr[j + 1]){
                // Swap the two elements if true
                int temp = bubbleArr[j + 1];
                bubbleArr[j + 1] = bubbleArr[j];
                bubbleArr[j] = temp;
            }
        }
    }

    clock_t end = clock();

    //printArr(bubbleArr, ARRSIZE);

    double runtime = Calculate_Runtime(end, start);
    printf("\nBubble Sort completed:\t\t%f seconds\n", runtime);
}


/****
 * Merge Sort
****/


/****
 * Quick Sort
****/


/****
 * Counting Sort
****/


/****
 * Merge Sort
****/


