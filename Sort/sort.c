#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* parseList(char* direction);

int main() {
    parseList("./sort.csv");

    return 0;
}

char* parseList(char* direction) {
    FILE* f = fopen(direction, "r");
    char buffer[1024];


    while (fgets(buffer, 1024, f) != NULL) {
        printf("&s", buffer);
    }


    
    close(f);
    return direction;
}