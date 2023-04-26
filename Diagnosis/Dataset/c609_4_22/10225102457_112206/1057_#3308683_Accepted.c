#define MAX_LEN 1003
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    int ilen;
    int *i;
}NUM;

void multi(NUM *i1, int n);
int zero(NUM *i1, int num);

int main(void){
	int T;
	scanf("%d",&T);

	for(int i = 0; i < T; i++){
		int n;
		scanf("%d",&n);
		
		NUM mul;
        mul.i = (int*)malloc(MAX_LEN * sizeof(int) + 1);
        mul.ilen = 1;
        for(int v = 0; v < MAX_LEN; v++)
            mul.i[v] = 0;
        mul.i[0] = 1;

		int num = 0;
		for(int v = 1; v <= n; v++){
			multi(&mul,v);
            num = zero(&mul,num);
		}
		
		printf("case #%d:\n",i);
		printf("%d\n",num);
		free(mul.i);
	}
	
	return 0;
}

int zero(NUM *i1, int num){
    while(i1->i[0] == 0){
        for(int v = 0; v < i1->ilen; v++){
            i1->i[v] = i1->i[v+1];
        }
        i1->ilen--;
        num++;
    }

    return num;
}

void multi(NUM *i1, int n){
	int carry = 0;

    for(int t = 0; t < i1->ilen; t++){
        i1->i[t] = i1->i[t] * n + carry;

        if(i1->i[t] > 9){
            carry = i1->i[t] / 10;
            i1->i[t] %= 10;
        }
        else carry = 0;
    }

    if(carry != 0){//deal with integer overflow
        i1->i[i1->ilen] = carry;
        i1->ilen++;
        if(i1->ilen > 2*MAX_LEN) fprintf(stderr,"Multi error! Overflow in integer!\n");
    }
}