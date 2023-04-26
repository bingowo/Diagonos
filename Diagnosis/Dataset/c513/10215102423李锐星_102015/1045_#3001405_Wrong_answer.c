#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define N 10000


typedef struct{
	char c;
	int cnt;
}STR;

int cmp(const void *a,const void* b)
{
	return *(int*)a-*(int*)b;
}

int main()
{
	int n;
	int i,j;
	scanf("%d",&n);
	int f[N];
	STR str[N][100];
	for (i=0;i<n;i++){
		char s[101];
		scanf("%s",s);
		int k;
		int j=0,num=1;
		for (k=1;k<=strlen(s);k++){
			if(s[k]!=s[k-1]){
				str[i][j].c=s[k-1];
				str[i][j].cnt=num;
				num=1;
				j++;
				printf("%c=%d\n",str[i][j].c,str[i][j].cnt);
			}
			else{
				num++;
			}
		}
		f[i]=j;
	}
	int ans=0;
	int flag=1;
	for (i=1;i<n;i++){
		if(f[i]!=f[0]){
			flag=0;
			break;
		}
	}
	if(flag){
		int j;
		for (i=1;i<n;i++){
			for (j=1;j<n;j++){
				if(str[j][i].c!=str[0][i].c){
					flag=0;
					break;
				}
			}
		}
	}
	if(flag){
		int a[N];
		for (i=0;i<f[0];i++){
			for (j=0;j<n;j++){
				a[j]=str[j][i].cnt;
			}
			qsort(a,n,sizeof(int),cmp);
			for (j=0;j<n;j++){
				ans+=abs(a[j]-a[n/2]);
			}
		}
		printf("%d\n",ans);
	}
	else{
		printf("-1\n");
	}
	return 0;
}