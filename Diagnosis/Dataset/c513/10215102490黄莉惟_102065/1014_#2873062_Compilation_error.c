#include<stdio.h>
#include<string.h>
int main(){
    long long int a,b,r;
    int i=0;
    int j=0;
    int num=0;
    int s[1000];
    scanf("%lld %lld",&a,&b);
    long long int n;
    n=a/b;
    if(n=0){
        s[0]=0;
    }
    while(n!=0){
        r=n%3;
        n=n/3;
        s[i]=r;
        i=i+1;
        num++;
        } 
    s[i]='\0';
    int k[1000];
    int num1;
    for(i=num-1;i>=0;i--) k[j++]=s[i];
    for(i=0;i<num;i++) s[i]=k[i];
    s[++i]='\0'; //整数部分
    int t;
    t=a%b;
    double m;
    m=(double)t;
    double p;
    p=(double)b;
    i=0;
    while((m!=p)&&(m!=2*p)&&(m!=0)){
    	m*=3;
		if(m/p>=2){
			m=m-2*p;
			digit[i]=2;
			i++;
		}else if(m/p>=1){
			m=m-p;
			digit[i]=1;
			i++;
		}else{
			digit[i]=0;
			i++
		}		
	}
	num1=i;
	digit[i]='\0';
	for(i=0;i<num1;i++){
	    printf("%d",digit[i]);
	}
    
}