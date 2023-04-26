#include<stdio.h>
#include<string.h>
int main(){
    int n,r,t;
    char s[1000];
    int i=0;
    char c1;
    scanf("%d %d",&n,&r);
    while(n!=0){
        t=n%r;
        n/=r;
        if(t<0){
            t-=r;
            n=n+1;
        }
        if(t<10){
        	s[i]=t+'0';
		}else{
			s[i]=t+55;
		}
        i++; 
    }
    for(i=strlen(s)-1;i>=0;i--){
    	printf("%c",s[i]);
	}
}