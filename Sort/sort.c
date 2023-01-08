#include <stdio.h>
#include <stdlib.h>
#include <string.h>


size_t* parseList(char* direction, size_t fixedSize);
size_t getFirstElement(char* row);

void bubbleSort(size_t* array, size_t length, int ascending);
void insertionSort(size_t* array, size_t length, int ascending);


int main() {
    /* Example array, this is not important for the sort functions. It's just a test */
    size_t* arr;
    size_t length = 10000;

    // TODO: We might give the length of the array in any part of the list
    arr = parseList("list.csv", length); /* The array is obtained from a .csv */

    // Nice :)
    insertionSort(arr, length, 1);

    for (size_t i = 0; i < length; i++) {
        printf("%li, ", arr[i]);
    }


    free(arr);
    return 0;
}


size_t* parseList(char* direction, size_t fixedSize) {
    /*
         The parseList function returns a list of 'fixedSize' count (or 
        less if there are no more values in the file). 
         The list is obtained from a .csv file, and the same only
        will store the first column of numbers.

        WARNING! 
            * You have to free() the returned list.
    */


    // The array that we will return
    size_t* array = (size_t*) malloc(sizeof(size_t) * fixedSize);
    size_t count = 0; // Count for the length of main list

    // File and row buffer
    FILE* f = fopen(direction, "r");
    char buffer[1024];

    // Boolean to avoid the .csv header
    int isFirst = 1; 

    // Before that we follow, let's insurance that the route is correct
    if (f == NULL) { return array; }


    // Read row by row, or the same row in 1024 chunck's
    while (fgets(buffer, 1024, f)) {
        /* Avoid header */
        if (isFirst) {
            isFirst = 0;
            continue;
        }
        /* Keep the count of the array (even if there is more values on the csv) */
        if (count == fixedSize) {
            break;
        }

        // Save the first element of the row and increase the index
        array[count] = getFirstElement(buffer);
        count++;
    }

    // EOF
    fclose(f);
    return array;
}

size_t getFirstElement(char* row){
    /* 
         This function receive a string corresponding to the 
        row of a csv file, and return a size_t number that correspond
        to the first element of that row.

        Alert!
         * This function will return 0 if the first element is not a number!!
    */

    // The string where we will store the first element
    char temp[strlen(row) + 1];
    temp[strlen(row)] = '\0';

    /* Read the row */
    for (size_t i = 0; i < strlen(row); i++) {

        // If it is a number, we'll add it to the str
        // Otherwise, we'll assume that the current value is the separator
        if ((int) row[i] < 58 && (int) row[i] > 47) {
            temp[i] = row[i];
        } else {
            temp[i] = '\0';
            break;
        }
    }

    // Finally, we convert the string to a size_t and return it
    return atoi(temp);
}


void bubbleSort(size_t* array, size_t length, int ascending){

   if (length < 2 || ascending < 0 || ascending > 1) { return; }


   int isSorted = 1;
   size_t iterations = 1;
   
   
   while(1) {
    if (iterations >= (length * length)) {
        printf("THE BUBBLE SORT FUNCTION REACHED A ITERATION OVERFLOW!\n");
        return;
    }

    for (size_t i = 0; i < (length - 1); i++) {
        if ((array[i] > array[i+1] && ascending) ||
            (array[i] < array[i+1] && !ascending)) {

            size_t temp = array[i];

            array[i] = array[i+1];
            array[i+1] = temp;

            isSorted = 0;
        }
        iterations ++;
    }

    if (isSorted) { break; }
    else { isSorted = 1; }
   }

}

void insertionSort(size_t* array, size_t length, int ascending) {
    if (length < 2 || ascending < 0 || ascending > 1) { return; }
    
    int isSorted = 1;
    size_t iterations = 1;

    while (1) {
        if (iterations >= length * length) {
            printf("The INSERTION SORT function reached an iteration overflow!\n");
            return;
        }

        for (size_t i = 1; i < length; i++) {
            
            if ((array[i] < array[i-1] && ascending == 1) ||
                (array[i] > array[i-1] && ascending == 0)) {

                size_t temp = array[i];

                array[i] = array[i-1];
                array[i-1] = temp;

                isSorted = 0;
            }

            iterations ++;
        }
        
        if (isSorted == 1) { break; }
        isSorted = 0;
    }
}
