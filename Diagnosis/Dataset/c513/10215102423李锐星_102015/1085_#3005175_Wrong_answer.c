#include <stdio.h>
#include <string.h>
#define L 500

typedef struct{
	int num[L+1];
	int sign;
	int len;
	int max;
}NUM;

NUM input(char  *s)
{
	NUM a;
	if(s[0]=='-') {
		a.len=strlen(s)-1;
		a.sign=-1;
		a.max=s[1]-'0';
	}
	else {
		a.len=strlen(s);
		a.sign=1;
		a.max=s[0]-'0';
	}
	int i,j;
	for (i=0;i<=L;i++){
		a.num[i]=0;
	}
	for (i=strlen(s)-1,j=L;i>-1;i--){
		if(s[i]>='0'&&s[i]<='9'){
			a.num[j]=s[i]-'0';
			j--;
		}
	}
	return a;
}

int cmp(NUM a,NUM b)
{
	if(a.sign<b.sign) return -1;
	if(a.sign>b.sign) return 1;
	if(a.len>b.len) return 1;
	if(a.len<b.len) return -1;
	if(a.max>b.max) return 1;
	if(a.max<b.max) return -1;
	int i;
	while(i<=L&&a.num[i]==0) i++;
	while(a.num[i]==b.num[i]) i++;
	if(a.num[i]>b.num[i]) return 1;
	return -1;
}

int main()
{
	char s[L+1],t[L+1];
	while((scanf("%s %s",s,t))!=EOF){
		NUM a,b;
		int c[L+1];
		a=input(s);
		b=input(t);
		int i;
		int flag=cmp(a,b);
		if(flag){
			if(a.sign==1&&b.sign==1){
				for (i=L;i>L-a.len+1;i--){
					a.num[i]-=b.num[i];
					if(a.num[i]<0){
						a.num[i]+=10;
						a.num[i-1]--;
					}
				}
				a.num[i]-=b.num[i];
				i=0;
				while(i<=L&&a.num[i]==0)i++;
				for (;i<=L;i++){
					printf("%d",a.num[i]);
				}
			}
			if(a.sign==1&&b.sign==-1){
				for (i=L;i>0;i--){
					a.num[i]+=b.num[i];
					a.num[i-1]+=a.num[i]/10;
					a.num[i]%=10;
				}
				i=0;
				while(i<=L&&a.num[i]==0)i++;
				for (;i<=L;i++){
					printf("%d",a.num[i]);
				}
			}
			if(a.sign==-1&&b.sign==-1){
				for (i=L;i>L-b.len+1;i--){
					b.num[i]-=a.num[i];
					if(b.num[i]<0){
						b.num[i]+=10;
						b.num[i-1]--;
					}
				}
				b.num[i]-=a.num[i];
				i=0;
				while(i<=L&&a.num[i]==0)i++;
				for (;i<=L;i++){
					printf("%d",b.num[i]);
				}
			}
		}
		else{
			if(a.sign==-1&&b.sign==-1){
				for (i=L;i>L-a.len+1;i--){
					a.num[i]-=b.num[i];
					if(a.num[i]<0){
						a.num[i]+=10;
						a.num[i-1]--;
					}
				}
				a.num[i]-=b.num[i];
				printf("-"); 
				i=0;
				while(i<=L&&a.num[i]==0)i++;
				for (;i<=L;i++){
					printf("%d",a.num[i]);
				}
			}
			if(a.sign==-1&&b.sign==1){
				for (i=L;i>0;i--){
					a.num[i]+=b.num[i];
					a.num[i-1]+=a.num[i]/10;
					a.num[i]%=10;
				}
				i=0;
				while(i<=L&&a.num[i]==0)i++;
				printf("-");
				for (;i<=L;i++){
					printf("%d",a.num[i]);
				}
			}
			if(a.sign==1&&b.sign==1){
				for (i=L;i>L-b.len+1;i--){
					b.num[i]-=a.num[i];
					if(b.num[i]<0){
						b.num[i]+=10;
						b.num[i-1]--;
					}
				}
				b.num[i]-=a.num[i];
				printf("-");
				i=0;
				while(i<=L&&a.num[i]==0)i++;
				for (;i<=L;i++){
					printf("%d",b.num[i]);
				}
			}
		}
		printf("\n");
	}
}