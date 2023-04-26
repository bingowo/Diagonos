#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//因为要s1 s2间距最大，故肯定两者越分别靠近s两端越好
//故分别由头、尾向另一端搜索最近的串 
int find(char*s,char*s1,char*s2)
{
	int k1=0,k2=0,cnt1=0,cnt2=0;
	int j1=0,j2=0,i=0;//分别记录s1 s2的位置 
	int flg1=0,flg2=0;//记录找没找到 
	while(s[i])//顺向找s1 
	{
		int c1=i;
		while(s[c1]==s1[k1]&&s[c1]&&s1[k1]){
		//	printf("s1[]:%d %c\n",k1,s1[k1]);
			c1++;
			k1++;
			cnt1++; 
		}
		//printf("cnt1:%d\n",cnt1);
		if(cnt1==strlen(s1)){
			j1=c1;//若找到，j1指向s1末尾的下一个
	//		printf("j1:%d\n",j1);
		    flg1=1;
			break;
		}
		i++;
		k1=0,cnt1=0;
	}
	if(flg1==0)
	{
		int t=0;
		return t;
	}
	int len1=strlen(s)-1,len2=strlen(s2)-1;
//	printf("len1 len2:%d %d\n",len1,len2);
//	printf("s2:%s\n",s2);
	while(len1>=0)//逆向找s2 
	{
	//	printf("s[len1],s2[len2]:%d %d %c %c\n",len1,len2,s[len1],s2[len2]);
		while(s[len1]==s2[len2]&&s2[len2]&&s[len1])
		{
			len1--;
			len2--; 
			cnt2++;
		}
	//	printf("cnt2:%d\n",cnt2);
		if(cnt2==strlen(s2)){
			j2=len1;//若找到，j2指向s2首的下一个
		//	printf("j2:%d\n",j2);
			flg2=1;
			break; 
		}
		len1--;
		len2=strlen(s2)-1,cnt2=0;//长度要-1！！！！ 
	}
	if(flg2==0)//没找到 
	{
		int t=0;
		return t;
	}
	if(j1>j2)return 0;//用于ab ab情况 
	if(j1==j2)return 1;
	int ans=1,temp=j1;
	while(temp!=j2)
	{
		temp++;
		ans++;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		char s1[100]={0};
		char s2[100]={0};
		char s[100] ={0};
		scanf("%s %s %s",s1,s2,s);
		//printf("%s %s %s\n",s1,s2,s); 
		int cnt1=find(s,s1,s2);
		int cnt2=find(s,s2,s1);
		printf("case #%d:\n",i);
		if(cnt1>cnt2)printf("%d\n",cnt1);
		else printf("%d\n",cnt2);
	}
 } 