#include<stdio.h>
#include<string.h>
#define c 4
void f(int a){
    long d[1001];
    for(int i = 0; i < 1001; i++){
    	d[i] = 0;
	}
    d[0]=1;
    int v[4] = {1,2,3,4};
    for(int i=0;i<4;i++){
        for(int j=v[i];j<a+1;j++){
            d[j]+=d[j-v[i]];                         
        }
    }     
    printf("%ld\n", d[a]);
}
int main(){
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d", &n);
		f(n);
	}
	return 0;
}