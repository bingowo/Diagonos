#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
	char t[65];
	int num;
}p;
int cmp1(const void *a, const void *b){
	if((*(p *)a).num!=(*(p *)b).num) return (*(p *)a).num>(*(p *)b).num;
	else return strcmp((*(p *)a).t,(*(p *)b).t);
}
int main(){
	int n,i,j,k;
	p anss[10005];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		char a[65];
		char li[65];
		int l=0;
		scanf("%s",a);
		strcpy(anss[i].t,a);
		for(j=0;j<strlen(a);j++){
			int f=0;
			for(k=0;k<l;k++){
				if(a[j]==li[k]) f=1;
			}
			if(f==0){
				li[l]=a[j];
				l++;
			}
		}
		if(l==1) l=2;
		long long q=1,ans=0;
		for(j=strlen(a)-1;j>=0;j--){
			long long t=0;
			for(k=0;k<l;k++){
				if(a[j]==li[k]){
					t=k;
				//	break;
				}
			}
			if(t==0) t=1;
			else if(t==1) t=0;
			ans=ans+q*t;
			q=q*l;
		}
		anss[i].num=ans;
	}
	qsort((void *)anss,n,sizeof(anss[0]),cmp1);
	for(i=0;i<n;i++){
		printf("%s\n",anss[i].t);
	}
} 

