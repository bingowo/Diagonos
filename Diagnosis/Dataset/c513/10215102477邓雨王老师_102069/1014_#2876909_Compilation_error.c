#include<stdio.h>
#include<string.h>
void itob(int n,char *s,int b)  //用来进制转换
{
	int sign,i=0,d;
	if((sign=n)<0){
	    n=-n;
	}
	do{
	    d=n%b;
	    if(d<10){
	        *s(i)=d+'0';
	    }
	    else{
	        *s(i)=d-10+'A';
	    }
	    i++;
	    n/=b;
	    
	    
	}while(n>0);
	if(sign<0) *s(i++)='-';
	*s(i)='\0';
	for(i=0,j=strlen(s)-1;i<j;i++,j--)
	      c=*s(i),*s(i)=*s(j),*s(j)=c;
   
}
int main(){
    long long A,B;
    char s[1000];
    scanf("%lld %lld",&A,&B);
    if(A%B==0){
        long long chance=;
        long long temp=A/B;
        while(temp>=1){
            if(temp%3==1){s[chance]=''
        }
        
    }
}