#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int m,n;
int a[1010] = {0};
int b1[1010] = {0}, b2[1010] = {0}, b[1010] = {0};
int have[1010] = {0};
int bhave[1010] = {0};
int mycmp(const void*aa,const void*bb)
{
	int a = *(int*)aa;
	int b = *(int*)bb;
	if(a<=b) return -1;
	else return 1;
}
int main(void)
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		scanf("%d",&a[i]);
		have[a[i]] = 1;
	}
	scanf("%d",&n);
	int idx1 = 1, idx2 = 1;
	for(int i=1;i<=n;i++){
		int num;
		scanf("%d",&num);
		if(have[num]) {
			bhave[num]++;
		}
		else b2[idx2++] = num; 
	} 
	qsort(b2+1,idx2-1,sizeof(b2[0]),mycmp);
	for(int i=1;i<=m;i++){
		for(int j=0;j<bhave[a[i]];j++)
			b1[idx1++] = a[i];
	}
	int idx = 1;
	for(int i=1;i<idx1;i++) b[idx++] = b1[i];
	for(int i=1;i<idx2;i++) b[idx++] = b2[i];
	for(int i=1;i<idx;i++) printf("%d ",b[i]);
	return 0;
}