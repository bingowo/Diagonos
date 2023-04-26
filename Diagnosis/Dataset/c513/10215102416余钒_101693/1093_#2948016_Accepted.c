#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char s[10005]; 
int num[10005],cnt=0,l;
int main() {
	scanf("%s",s);
	l=strlen(s);
	for(int i=1;i<=10000;i++) num[i]=0;
	for(int i=l-1;i>=0;i--) num[++cnt]=s[i]-'0';
	num[1]++;
	for(int i=1;i<=cnt;i++) 
		num[i+1]+=num[i]/10,num[i]%=10;
	if(num[cnt+1]>0) cnt++;
	for(int i=cnt;i;i--){
		if(num[i]==9){
			int j;
			for(j=i;j;j--) 
				if(num[j]!=9) break;
			num[++j]++;
			for(int k=j;k<=cnt;k++){
				if(num[k]==9) num[k]++;
				num[k+1]+=num[k]/10,num[k]%=10;
			}
			if(num[cnt+1]>0) cnt++;
			for(int k=j-1;k;k--) num[k]=0;
			break;
		}
	}
	int res=0;
	for(int i=1;i<=cnt;i++) res+=num[i];
	if(res%9==0){
		num[1]++;
		if(num[1]==9){
			for(int j=1;j<=cnt;j++){
				if(num[j]==9) num[j]++;
				num[j+1]+=num[j]/10,num[j]%=10;
			}
			if(num[cnt+1]>0) cnt++;
			res=0;
			for(int i=1;i<=cnt;i++) res+=num[i];
			if(res%9==0) num[1]++;
		}
	}
	for(int i=cnt;i;i--) printf("%d",num[i]);
	return 0;
}