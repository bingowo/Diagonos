#include <stdio.h>
#include <stdlib.h>
int numx[32], numy[32];
int main(){
	int t, i, j, x, y, lenx, leny, l, sum;
	scanf("%d", &t);
	for(i = 0; i < t; ++i){
		scanf("%d%d", &x, &y);
		lenx = 0; leny = 0; sum = 0;
		for(j = 0; j < 32; ++j){	numx[j] = 0; numy[j] = 0;}
		while(x){
			numx[lenx++] = x % 2;
			x = x / 2;
		}
		while(y){
			numy[leny++] = y % 2;
			y = y / 2;
		}
		if(lenx > leny)	l = lenx;
		else	l = leny;
		for(j = 0; j < l; ++j){
			if(numx[j] != numy[j])	sum += 1;
		}
		printf("%d\n", sum);
	}
}