#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(char *)b - *(char *)a); 
}
int main() {
    char num[10];
    scanf("%s", num);
    int len = strlen(num);
    qsort(num, len, sizeof(char), compare);
    printf("%s\n", num);
    return 0;
}
