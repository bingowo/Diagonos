#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
char map[4000][16];
int cmp(const void*a,const void*b){
	int len1=strlen((char*)a);
	int len2=strlen((char*)b);
	return (len1>len2)?1:-1;
}
int judge(char*temp,int n){
	for(int i=0;i<n;i++)
	{if(strcmp(temp,map[i])==0)
	{printf("%s",map[i]);
	return 1;}
	}
	return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int v=0;v<n;v++){
		scanf("%s",&map[v]);
	}
	qsort(map,n,sizeof(map[0]),cmp);
	char str[5001];
	scanf("%s",&str);
	int left=0,len=strlen(str),right=len-1;
	
	for(;left<=right;right--)
	{
	//printf("%d %d\n",left,right);
		char temp[5001]={0};
		int k=0;
		for(int i=left;i<=right;i++) temp[k++]=str[i];
		temp[k]='\0';
		int b=judge(temp,n);
		if(b==1) {
		printf(" ");	
     	left=right+1;	
	    right=len;}
		else if(b==0&&right==left){
			printf("%c ",str[left]);
			left++;	
	        right=len;
		}
		
	}
	
	
	return 0;
}