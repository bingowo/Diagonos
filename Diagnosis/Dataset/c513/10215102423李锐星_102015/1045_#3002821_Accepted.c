#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
	char c;
	int cnt;
}P;
int cmp(const void *a,const void* b)
{
	return *(int*)a-*(int*)b;
}


P a[100001][100];
int number[100001];

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		char s[101];
		scanf("%s",s);
		int num=1;
		int cnt=0;
		int j,k=0;
		for (j=1;j<=strlen(s);j++){
			if(s[j]!=s[j-1]){
				a[i][k].c=s[j-1];
				a[i][k].cnt=num;
				k++;
				num=1;
				cnt++;
			}
			else{
				num++;
			}
		}
		number[i]=cnt;
	}
	int flag=1;
	for (i=1;i<n;i++){
		if(number[i]!=number[0]){
			flag=0;
			break;
		}
	}
	if(flag){
		for (i=0;i<number[0];i++){
			for (int j=1;j<n;j++){
				if(a[j][i].c!=a[0][i].c){
					flag=0;
					break;
				}
			}
		}
	}
	if(flag){
		int ans=0;
		int b[100001];
		for (i=0;i<number[0];i++){
			for (int j=0;j<n;j++){
				b[j]=a[j][i].cnt;
			}
			qsort(b,n,sizeof(int),cmp);
			for (int j=0;j<n;j++){
				ans=ans+abs(b[j]-b[n/2]);
			}
		}
		printf("%d\n",ans);
	}
	else{
		printf("-1\n");
	}
	return 0;
}