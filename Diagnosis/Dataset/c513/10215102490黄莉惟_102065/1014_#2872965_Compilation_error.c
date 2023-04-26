#include<stdio.h>
#include<string.h>
int main(){
    long long int a,b;
    int i=0;
    int j=0
    int s[1000];
    int digit[1000];
    scanf("%lld %lld",&a,&b);
    long long int n;
    n=a/b;
    int t;
    t=a%b;
    double m;
    m=(double)t;
    double p;
    p=(double)b;
    itob(n,s); //整数 
    dig(m,p,digit); //小数
    while(s[i]!='/0'){
        i++;
    }
    while(digit[j]!='\0'){
        s[i++]=digit[j++];
    }
    s[i]='\0';
    printf("%d",s);
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
int dig(double m,double p,int digit[1000]){
	int i=0;
	while((m!=p)&&(m!=2*p)&&(m!=0)){
    	m*=3;
		if(m/p>=2){
			m=m-2*p;
			digit[i]=2;
		}else if(m/p>=1){
			m=m-p;
			digit[i]=1;
		}else{
			digit[i]=0;
		}		
		i++;
	}
	digit[i]='\0';
}