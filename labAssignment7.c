#include <stdio.h>

void copyArray(int array1[], int array2[], int len);
void sortswap(int* elem1, int* elem2);
void bubbleSort(int* array, int blen);
void selectionSort(int* array, int slen);

//function to swap elements
void sortswap(int* elem1, int* elem2){
    int temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}

//function to copy the original array to an array that will be sorted
void copyArray(int array1[], int array2[], int len){
    for(int i = 0; i < len; i++){
        array2[i] = array1[i];
    }
}

int main(){
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int len1 = sizeof(array1)/sizeof(array1[0]);
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int len2 = sizeof(array2)/sizeof(array2[0]);
    
    printf("%s\n", "Array 1 bubble sort:");
    bubbleSort(array1, len1);
    printf("%s\n", "Array 2 b3ubble sort:");
    bubbleSort(array2, len2);
    printf("%s\n", "Array 1 selection sort:");
    selectionSort(array1, len1);
    printf("%s\n", "Array 2 selection sort:");
    selectionSort(array2, len2);
}


void bubbleSort(int* array, int blen){
    int *toBeSorted = (int*)malloc(blen * sizeof(int));
    copyArray(array, toBeSorted, blen);
    int counters[9] = {0};
    int swap;
    int sum = 0;

    for (int i = 0; i < blen-1; i++){
        swap = 0;
        for(int j = 0; j < blen-i-1; j++){
            //if the current element is larger than the next, swap
            if(toBeSorted[j] > toBeSorted[j+1]){
                counters[j]++;
                counters[j+1]++;
                sortswap(&counters[j], &counters[j+1]);
                sortswap(&toBeSorted[j], &toBeSorted[j+1]);
                //indicate that a swap as occured
                swap = 1;
            }
        }
        //if no swap occurred, exit the loop
        if(swap == 0){
            break;
        }
    }
    //calculate sum
    for(int k = 0; k < blen; k++){
        sum = sum + counters[k];
    }
    //print the values of the sorted array and how many times the element was sorted
    for(int k = 0; k < blen; k++){
        printf("%d: %d\n", toBeSorted[k], counters[k]);
    }
    //print total amount of swaps
    printf("%d\n", sum/2);
}

void selectionSort(int* array, int slen){
    int *toBeSorted = (int*)malloc(slen * sizeof(int));
    copyArray(array, toBeSorted, slen);
    int counters[9] = {0};
    int min;
    int sum = 0;
    
    for(int i = 0; i < slen-1; i++){
        min = i;

        //find the index of the minimum value
        for(int j = i+1; j < slen; j++){
            if(toBeSorted[j] < toBeSorted[min]){
                min = j;
            }
        }

        //given the minimum index is not the current index,
        //swap elements at current index and minimum index for "toBeSorted" and "counters"
        if(min != i){
                counters[min]++;
                counters[i]++;
                sortswap(&counters[min], &counters[i]);
                sortswap(&toBeSorted[min], &toBeSorted[i]);
            }
    }
    //calculate sum
    for(int k = 0; k < slen; k++){
        sum = sum + counters[k];
    }
    //print the values of the sorted array and how many times the element was sorted
    for(int k = 0; k < slen; k++){
        printf("%d: %d\n", toBeSorted[k], counters[k]);
    }
    //print total amount of swaps
    printf("%d\n", sum/2);
}