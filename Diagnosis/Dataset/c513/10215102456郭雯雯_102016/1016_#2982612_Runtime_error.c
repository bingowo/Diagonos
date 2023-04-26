#include<stdio.h>
#include<string.h>
#define L 50
int n;

int mod(int a, int b){
	if(a < 0 && a%b != 0){
		n = a / b + 1;
		return a - (a / b + 1) * b;//返回非负余数
	}
	n = a / b;
	return a % b;
}


int main(){
    int r;
    scanf("%d %d",&n,&r);
    char c[20]="0123456789ABCDEFGHIJ",s[L];
    memset(s,0,sizeof(s));
    int i=L-1;
    while(n>0){
        int y=mod(n,r);
        s[i]=c[y];
        i--;
    }
    int m=0;
    while(s[m]==0)m++;
    for(int j=m;j<L;j++)printf("%c",s[j]);
}