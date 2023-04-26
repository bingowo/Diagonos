#include <stdio.h>
int j;
void f(long long int n,int s[]){
	if(n/2333){
		f(n/2333,s);
	}
	s[j++]=n%2333;
}
int main(){
    int t,i,num[100],k;
    long long int n; 
    scanf("%lld",&t);                 //12698260037
    for(i=0;i<t;i++){
        j=0;
        scanf("%lld",&n);
        f(n,num);
        for(k=0;k<j;k++){
            printf("%d%c",num[k],k==j-1?'\n':' ');
        }
    }
}