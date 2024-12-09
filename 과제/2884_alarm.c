#include <stdio.h>
int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	if(a<=24 && b <= 59){
		if(a<1){
			if(b>=45){
				b = b - 45;
			}
			else{
				a = 23;
				b = 60 + (b-45);
			}
		}
		else{
			if(b>=45){
				b = b - 45;
			}
			else{
				a = a - 1;
				b = 60 + (b-45);
			}
		}
	}
	printf("%d %d", a, b);
	return 0;
}
