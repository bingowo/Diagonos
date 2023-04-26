#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long GCD(long long m,long long n)
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
		if(s[i]=='1') ans+=1;
		if(s[i]=='0') ans=ans;}
		i++;
		for(;i<c;i++){
		ans1=(ans1)*3;
		if(s[i]=='2') ans1-=1;
		if(s[i]=='1') ans1+=1;	
	if(s[i]=='0') ans1=ans1;
	(ans2)*=3;
		}printf("ans1=%lld ans2=%lld",ans1,ans2);
		if(ans>0&&ans1>0){
			printf("%lld %lld %lld",ans,ans1/GCD(ans1,ans2),ans2/GCD(ans1,ans2));
		}
		if(ans>0&&ans1<0){
			ans--;
			ans1=ans2-ans1;
			printf("%lld %lld %lld",ans,ans1/GCD(abs(ans1),abs(ans2)),ans2/GCD(abs(ans1),abs(ans2)));
			}
	if(ans1==0&&ans2==0) printf("%lld", ans);
	if(ans<0&&ans1>0){
		ans++;
		ans1=ans2-ans1;	
			printf("%lld %lld %lld",ans,ans1/GCD(abs(ans1),abs(ans2)),ans2/GCD(abs(ans1),abs(ans2)));
}
if(ans<0&&ans1<0) 	printf("%lld %lld %lld",ans,ans1/GCD(abs(ans1),abs(ans2)),ans2/GCD(abs(ans1),abs(ans2)));
return 0;
}