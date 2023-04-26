#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int T,n;
struct node{
	int cnt;
	char c;
}E[100005][105];
char s[105];
int num[105]; 
int main() {
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int cnt=0,id=0;//当前字符连续出现了多少次，当前是第几个不同的字符 
		for(int j=1;s[j];j++){
			cnt++;
			if(s[j]!=s[j+1]) E[i][++id].c=s[j],E[i][id].cnt=cnt,cnt=0;
		}
		if(tot<id) tot=id;//记录最大的id，最多有多少个不同字符 
	}
	for(int i=1;i<=tot;i++) 
		for(int j=2;j<=n;j++)	
			if(E[j][i].c!=E[j-1][i].c) puts("-1"),exit(0);//比较不同字符串"压缩"后是否有可能变得相同 
			
    long long ans=0;
	for(int i=1;i<=tot;i++){ 
		for(int j=0;j<=100;j++) num[j]=0
		for(int j=1;j<=n;j++) num[E[i][j].cnt]++; 
		int cnt=0,p;  
		for(p=0;p<=100;p++)
		{
			if(cnt<(n+1)/2 && cnt+num[p]>=(n+1)/2) break;
			cnt+=num[p];
		}
		for(int j=1;j<=n;j++) ans+=1ll*abs(E[j][i].cnt-p);
	}
	printf("%lld",ans);
	return 0; 
}