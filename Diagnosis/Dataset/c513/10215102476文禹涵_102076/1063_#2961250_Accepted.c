#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long int llu;

int main(void)
{
	llu w, l;
	llu str = 0, temp;
	scanf("%llu %llu", &w, &l);
	if(w < l){
		temp = w;
		w = l;
		l = temp;
	}
	while(w && l){
		str += (4*l) * (w/l);
		w -= (l*(w/l));
		if(w < l){
			temp = w;
			w = l;
			l = temp;
		}
	}
	printf("%llu", str);
	
	return 0;
}
