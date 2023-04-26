#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int n,l,id[100005],cnt[300],A[100005];
char s[2000005];
long long val[100005];
int cmp(const void* a,const void* b){
	long long x=val[*(int *)a],y=val[*(int *)b];
	//printf("%lld %lld\n",x,y);
	if(x>y) return 1;
	else if(x<y) return -1;
	else return strcmp(s+id[*(int *)a],s+id[*(int *)b]);
}
int main() {
	for(int c=0;c<256;c++) cnt[c]=-1;
	scanf("%d",&n);
	l=0;
	for(int i=1;i<=n;i++){
		id[i]=l;
		scanf("%s",s+l);
		int num=0;
		long long x=0;
		for(int j=l;s[j];j++){
			if(cnt[s[j]]==-1){
				if(num==0) cnt[s[j]]=1;
				else if(num==1) cnt[s[j]]=0;
				else cnt[s[j]]=num;
				num++;
			}
		}
		if(num==1) num++;
		for(int j=l;s[j];j++) x=x*num+cnt[s[j]];
		val[i]=x;
		for(int j=l;s[j];j++) cnt[s[j]]=-1;
		//printf("%d %d \n",num,val[i]);
		l+=strlen(s+l)+1;
	}
	for(int i=1;i<=n;i++) A[i]=i;
	qsort(A+1,n,sizeof(int),cmp);
	for(int i=1;i<=n;i++)
		printf("%s\n",s+id[A[i]]);
	return 0;
}
