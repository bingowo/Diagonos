#include <stdio.h>;;
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int GCD(int m,int n)
{
   if(m%n==0) return n;
   else return GCD(n,m%n);}
int main(int argc, char *argv[]) {
	int i,c;
	long long ans=0;
	long long ans1=0,ans2=1;
	
	char s[30];
	scanf("%s",s);
	c=strlen(s);
	for(i=0;i<c;i++){
		if(s[i]=='.') break;
		ans=ans*3;
		if(s[i]=='2') ans-=1;
		if(s[i]=='1') ans+=1;}
		i++;
		for(;i<c;i++){
		ans1=ans1*3;
		if(s[i]=='2') ans-=1;
		if(s[i]=='1') ans+=1;	
	ans2*=3;
		}
		if(ans>0&&ans1>0){
			printf("%lld %lld %lld",ans,ans1/GCD(ans1,ans2),ans2/GCD(ans1,ans2));
		}











return 0;
}