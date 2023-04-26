#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char A[100005],ans[100005];

int main() {
	scanf("%s",A);
	int l=strlen(A),difpos=0,cnt=0;
	for(int i=0; i<l; i++) {
		while(difpos<l && A[i]==A[difpos]) difpos++;
		if(difpos<l && A[difpos] > A[i]) ans[cnt++]=A[i];
		ans[cnt++]=A[i];
	}
	ans[cnt]='\0';
	printf("%s",ans);
	return 0;
}