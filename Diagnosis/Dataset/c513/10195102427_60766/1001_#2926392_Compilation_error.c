#include<stdio.h>
#include<cstring>
using namespace std;
#define MAXN 1000
int main(){
	int T,N,R;
	char c[36] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	scanf("%d",T);
	while (T--) {
		scanf("%d %d",N,R);
		char a[MAXN],b[MAXN];
		int i = 0;
		int flag = 1;
		if (N < 0)
		{
			N = -N;
			flag = -1;
		}
		while (N)
		{
			b[i++] =c[N % R];
			N = N / R;
			if (N < R)
			{
				b[i++] =c[N];
				break;
			}
		}
		int j = 0;
		while (i) {
			a[j++] = b[--i];
		}
		if (flag == -1)
			printf("-");
		for (int k = 0; k < j; k++) {
			printf("%s",a[k]);
		}
	}
 }