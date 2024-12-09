#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char num[20];
    int base;
    int result = 0;
    scanf("%s %d", num, &base);
    int len = strlen(num); 
    for (int i = 0; i < len; i++) {
        char ch = num[i];
        int value;
        if (isdigit(ch)) {
            value = ch - '0';
        } 
        else {
            value = ch - 'A' + 10;
        }
        result = result * base + value;
    }
    printf("%d\n", result);
    return 0;
}

