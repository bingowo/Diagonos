#include<stdio.h>
#include<string.h>
int main(){
    long long int a,b;
    int s[1000];
    int digit[1000];
    scanf("%lld %lld",&a,&b);
    long long int n;
    n=a/b;
    double t;
    t=a%b;
    itob(n,s);
    dig(t,b,digit);
    printf("%d",digit[0]);
    printf("%d",digit[1]);
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
int dig(double a,long long int b,int digit[1000]){
	int i;
	while((a*3/(double)b-1!=0)&&(a*3/(double)b-2!=0)){
		if(a*3/b>=2){
			a=a-2*(double)b;
			digit[i]=2;
		}else if(a*3/b>=1){
			a=a-(double)b;
			digit[i]=1;
		}else{
			digit[i]=0;
		}
		i++;
	}
	digit[i]='\0';
}