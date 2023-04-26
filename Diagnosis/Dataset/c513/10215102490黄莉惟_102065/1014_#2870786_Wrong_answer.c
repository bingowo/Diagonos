#include<stdio.h>
#include<string.h>
int main(){
    long long int a,b;
    int s[1000];
    scanf("%lld %lld",&a,&b);
    long long int n;
    n=a/b;
    itob(n,s);
    
}
int itob(long long int n,int s[1000]){
	long long int r;
	int i=0;
	int j=0;
	int num=0;
	while(n!=0){
        r=n%3;
        n=n/3;
        s[i]=r;
        i=i+1;
        num++;
        } 
    s[i]='\0';
    int t[1000];
    for(i=num-1;i>=0;i--) t[j++]=s[i];
    for(i=0;i<num;i++) s[i]=t[i];
    s[++i]='\0';
}