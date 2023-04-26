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
    int i=0;
    if(n==0)printf("0");
    while(n!=0){
        if(n<0&&n%r!=0){
            y=n-(n/r+1)*r;
            n=n/r+1;
        }
        else{
            y=n%r;
            n=n/r;
        }
        s[i]=c[y];
        i++;
    }
    for(int j=i-1;j>=0;j--)printf("%c",s[j]);
}