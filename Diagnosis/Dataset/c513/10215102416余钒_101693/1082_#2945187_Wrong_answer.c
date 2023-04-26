#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n;
char s1[10005],s2[10005];
struct node{
	int num[1005],cnt;
}A,B;
int main(){
	scanf("%s%s%d",s1,s2,&n);
	int pre1=0,pre2=0;
	for(int i=0;s1[i];i++){
		if(s1[i]=='.'){
			pre1=i;
			break;
		}
		if(!s1[i+1]) pre1=i+1;
	}
	if(pre1<1) A.num[++A.cnt]=0,pre1++;
	for(int i=0;s2[i];i++){
		if(s2[i]=='.'){
			pre2=i;
			break;
		}
		if(!s2[i+1]) pre2=i+1;
	}
	if(pre2<1) B.num[++B.cnt]=0,pre2++;
	while(pre1<pre2) A.num[++A.cnt]=0,pre1++;
	while(pre2<pre1) B.num[++B.cnt]=0,pre2++;
	A.num[++A.cnt]=0,pre1++;
	B.num[++B.cnt]=0,pre2++;
	for(int i=0;s1[i];i++)
		if(s1[i]!='.') A.num[++A.cnt]=s1[i]-'0';
	for(int i=0;s2[i];i++)
		if(s2[i]!='.') B.num[++B.cnt]=s2[i]-'0';
		
	while(A.cnt<B.cnt||A.cnt<pre1+n) A.num[++A.cnt]=0;
 	while(B.cnt<A.cnt||B.cnt<pre1+n) B.num[++B.cnt]=0;
 	printf("%d %d\n",pre1,pre2);
 	for(int i=1;i<=A.cnt;i++) printf("%d",A.num[i]);
 	puts("");
 	for(int i=1;i<=B.cnt;i++) printf("%d",B.num[i]);
 	puts("");
 	for(int i=A.cnt;i;i--){
 		A.num[i]+=B.num[i];
 		if(i==pre1+n && A.num[i+1]>=5) A.num[i]++; 
 		A.num[i-1]+=A.num[i]/10;
 		A.num[i]%=10;
	 }
	 for(int i=1;i<=A.cnt;i++) printf("%d",A.num[i]);
 	puts("");
	 int i=1;
	 while(A.num[i]==0&&i<pre1) i++;
	 for(i;i<=pre1+n;i++){
	 	printf("%d",A.num[i]);
	 	if(i==pre1) printf(".");
	 }
	return 0;
}