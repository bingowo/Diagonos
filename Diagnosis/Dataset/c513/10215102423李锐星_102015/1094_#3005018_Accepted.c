#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 120

typedef struct{
	int num[L+1];
	int len;
	int max;
	int sign;
}NUM;

int cmp(const void *a,const void *b)
{
	NUM x,y;
	x=*(NUM*)a;
	y=*(NUM*)b;
	if(x.sign==-1&&y.sign==1) return -1;
	if(x.sign==1&&y.sign==-1) return 1;
	if(x.sign==1&&y.sign==1){
		if(x.len<y.len) return -1;
		if(x.len>y.len) return 1;
		if(x.max<y.max) return -1;
		else{
			int i=0;
			while(i<=L&&x.num[i]==0)i++;
			while(x.num[i]==y.num[i])i++;
			if(x.num[i]>y.num[i]) return 1;
			return -1;
		}
	}
	if(x.sign==-1&&y.sign==-1){
		if(x.len>y.len) return -1;
		if(x.len<y.len) return 1;
		if(x.max>y.max) return -1;
		if(x.max<y.max) return 1;
		else{
			int i=0;
			while(i<=L&&x.num[i]==0)i++;
			while(x.num[i]==y.num[i])i++;
			if(x.num[i]>y.num[i]) return -1;
			return 1;
		}
	}

}

int main()
{
	int n;
	scanf("%d",&n);
	NUM a[50];
	int i; 
	for (i=0;i<n;i++){
		char s[L+1];
		scanf("%s",s);
		if(s[0]=='-'){
			a[i].sign=-1;
		}
		else a[i].sign=1;
		int j,k;
		for (j=0;j<121;j++){
			a[i].num[j]=0;
		}
		for (j=strlen(s)-1,k=L;j>-1;j--){
			if(s[j]>='0'&&s[j]<='9'){
				a[i].num[k]=s[j]-'0';
				k--;
			}
		}
		a[i].len=strlen(s);
		a[i].max=a[i].num[k+1];
	}
	qsort(a,n,sizeof(a[0]),cmp);
	if(a[0].sign==a[n-1].sign){
		int l;
		if(a[0].len<a[n-1].len){
			l=a[n-1].len;
			for (i=L;i>L-l+1;i--){
				a[n-1].num[i]-=a[0].num[i];
				if(a[n-1].num[i]<0){
					a[n-1].num[i]+=10;
					a[n-1].num[i-1]--;
				}
			}
			a[n-1].num[i]-=a[0].num[i];
			for (;i<=L;i++){
				printf("%d",a[n-1].num[i]);
			}
		}
		else {
			l=a[0].len;
			for (i=L;i>L-l+1;i--){
				a[0].num[i]-=a[n-1].num[i];
				if(a[0].num[n-1]<0){
					a[0].num[n-1]+=10;
					a[0].num[n-1]--;
				}
			}
			a[0].num[i]-=a[n-1].num[i];
			for (;i<=L;i++){
				printf("%d",a[0].num[i]);
			}
		}
		
	}
	else{
		for (i=L;i>-1;i--){
			a[0].num[i]+=a[n-1].num[i];
			a[0].num[i-1]+=a[0].num[i]/10;
			a[0].num[i]%=10;
		}
		i=0;
		while(i<=L&&a[0].num[i]==0)i++;
		for (i;i<=L;i++){
			printf("%d",a[0].num[i]);
		}
	}
	printf("\n");
	return 0;
}
