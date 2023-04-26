#include <stdio.h>
#include <string.h>
#define L 500

void input(int* a,char* s)
{
	int i,j;
	for (i=strlen(s)-1,j=L;i>=0;i--,j--){
		a[j]=s[i]-'0';
	}
}

int sub(int* a,int* b,int n,int m)
{
	int len;
	int i;
	int flag;
	if(n==m){
		while(i<=L&&a[i]==0)i++;
		if(a[i]>=b[i])flag=1;
		else flag=0;
	}
	if(n>m||flag==1) {
		len=n;
		for (i=L;i>L-len+1;i--){
			a[i]-=b[i];
			if(a[i]<0){
				a[i]+=10;
				a[i-1]--;
			}
		}
		a[i]-=b[i];
		return 1;
	}
	else if(n<m||flag==0){
		len=m;
		for (i=L;i>L-len+1;i--){
			b[i]-=a[i];
			if(b[i]<0){
				b[i]+=10;
				b[i-1]--;
			}
		}
		b[i]-=a[i];
		return -1;
	}
}
void output(int* a,int * b,int sign)
{
	int i=0;
	if(sign==1){
		while(i<=L&&a[i]==0)i++;
		if(i>L){
			printf("0");
		}
		else{
			for(;i<=L;i++){
				printf("%d",a[i]);
			}
		}
	}
	else{
		while(i<=L&&b[i]==0)i++;
		if(i>L){
			printf("0");
		}
		else{
			printf("-");
			for (;i<=L;i++){
				printf("%d",b[i]);
			}
		}
	}
	printf("\n");
}

int main()
{	
	char s[L+1],t[L+1];
	while((scanf("%s %s",s,t))!=EOF){
		int a[L+1]={0},b[L+1]={0};
		int len1,len2;
		len1=strlen(s);
		len2=strlen(t);
		input(a,s);
		input(b,t);
		int sign=sub(a,b,len1,len2);
		output(a,b,sign);
	}
	return 0;
}