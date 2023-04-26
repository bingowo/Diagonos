#include <stdio.h>
#include <string.h>

void solve()
{
	char s[61];
	scanf("%s",s);
	int a[128];
	int i;
	for (i=0;i<128;i++){
		a[i]=-1;
	}
	int r=1;
	for (i=0;i<strlen(s);i++){
		int t=s[i];
		if(i==0){
			a[t]=1;
		}
		else{
			if(a[t]==-1&&r==1){
				a[t]=0;
				r++; 
			}
			else if(a[t]==-1&&r!=1){
				a[t]=r;
				r++;
			}
		}
	}
	unsigned long long res=0,weight=1;
	if(r==1) r++;
	for (i=strlen(s)-1;i>-1;i--){
		int t=s[i];
		res+=a[t]*weight;
		weight*=r;
	}
	printf("%llu\n",res);
}

int main()
{
	int T;
	scanf("%d",&T);
	for (int i=0;i<T;i++){
		printf("case #%d:\n",i);
		solve(); 
	}
	return 0;
}