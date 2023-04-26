#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
long long answer(char s[61]){
	int a[128],i;
	for(i=0;i<128;i++)
	a[i]=-1;
	int digit=0,N=1;char *p=s;
	a[*p]=1;
	while(*++p)
	if(a[*p]==-1){
		a[*p]=digit;
		digit=digit?digit+1:2;
		N++;
	}
	long long ans=0;
   p=s; while (*p) 
   ans=ans*N+a[*p++];
   

		
	return ans;
}

int main(int argc, char *argv[]) {
	int n,m;char s[61];
	scanf("%d",&n);
	for(m=0;m<=n;m++){
	scanf("%s",s);
	printf("case #%d:\n%lld",m,answer(s));
	return 0;
	
}