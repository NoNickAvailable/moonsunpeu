#include <stdio.h>

int main() {
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    int d = c-a;
    int e = (d+(a-b)-1)/(a-b)+1;
	printf("%d", e);
    return 0;
}

