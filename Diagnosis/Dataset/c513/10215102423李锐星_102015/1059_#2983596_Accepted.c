#include <stdio.h>
#include <stdlib.h>
#define N 1111
#define INF 1000000

int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}

int gcd(int a,int b)
{
	if(b%a==0) return a;
	return gcd(b%a,a);
}


void solve()
{
	int n,s;
	scanf("%d%d",&n,&s);
	int a[N];
	int i;
	for (i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	a[n]=INF;
	int ans_int=0,ans_fz=0,ans_fm=0;
	for (i=1;i<=n;i++){
		int t=(a[i]-a[i-1])*i;
		if(s<t){
			ans_int=a[i-1]+s/i;
			ans_fz=s%i;
			ans_fm=i;
			break;
		}
		else{
			s-=t;
		}
	}
	if(ans_fz!=0){
		int x=gcd(ans_fz,ans_fm);
		ans_fz/=x;
		ans_fm/=x;
	}
	if(ans_int==0&&ans_fz>0){
		printf("%d/%d\n",ans_fz,ans_fm);
	}
	else{
		printf("%d",ans_int);
		if(ans_fz>0){
			printf("+%d/%d\n",ans_fz,ans_fm);
		}
	}
}

int main()
{
	solve();
	return 0;
}