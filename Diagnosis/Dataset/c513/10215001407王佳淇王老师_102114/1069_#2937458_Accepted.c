#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int judge(int x){
	int r, m = 0,copy=x;
    while (x > 0) {
        r = x % 10;
        m = 10 * m + r;
        x = x / 10;}
        if(copy==m) return 0;
        else return 1;
}
int rev(int x){
	int r, m = 0;
    while (x > 0) {
        r = x % 10;
        m = 10 * m + r;
        x = x / 10;}
	return m;
}
int main(){
	int n;
	scanf("%d",&n);
	int count=0;
	while(judge(n)){
		count++;
		int m=rev(n);
		n=n+m;
	}
	printf("%d %d",count,n);
	return 0;
}