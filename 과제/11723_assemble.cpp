#include <stdio.h>

int main() {
    int M;
    scanf("%d", &M);
    int S[21] = {0};
    for (int i = 0; i < M; i++) {
        char command[10];
        int X;
        scanf("%s", command);
        if (command[0] == 'a' && command[1] == 'd') {
            scanf("%d", &X);
            S[X] = 1;
        } 
        else if (command[0] == 'r' && command[1] == 'e') {
            scanf("%d", &X);
            S[X] = 0;
        } 
        else if (command[0] == 'c' && command[1] == 'h') {
            scanf("%d", &X);
            printf("%d\n", S[X]);
        } 
        else if (command[0] == 't' && command[1] == 'o') {
            scanf("%d", &X);
            S[X] = 1 - S[X];
        } 
        else if (command[0] == 'a' && command[1] == 'l') {
            for (int j = 1; j <= 20; j++) {
                S[j] = 1;
            }
        } 
        else if (command[0] == 'e') {
            for (int j = 1; j <= 20; j++) {
                S[j] = 0;
            }
        }
    }
    return 0;
}

