#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int FindSubstrFromLeft(char*s,char*s1)
{
	int i,slen,s1len,j;
	slen=strlen(s);
	s1len=strlen(s1);
	for(i=0;i<slen-s1len;i++){
		for(j=0;j<s1len&&s[i+j]==s[j];j++);
		if(j==s1len) return i;
		}
		return -1;
}
int FindSubstrFromRight(char*s,char*s1){
		int i,slen,s1len,j;
	slen=strlen(s);
	s1len=strlen(s1);
	for(i=slen-s1len;i>=0;i--){
		for(j=0;j<s1len&&s[i+j]==s[j];j++);
		if(j==s1len) return i;
		}
		return -1;
}
int Max(int a,int b){
	return a>b?a:b;
}
int main(int argc, char *argv[]) {
	char s[80],s1[80],s2[80];
	int n,k,max=0,x,y;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		scanf("%s\n%s\n%s\n",s1,s2,s);
		printf("case #%d:\n",k);
		x=FindSubstrFromLeft(s,s1);printf("x1=%d\n",x);
		y=FindSubstrFromRight(s,s2);printf("y1=%d\n",y);
		if (x!=-1&&y!=-1) 
  {  max=Max(max,y-x-strlen(s1));
      x=FindSubstrFromLeft(s,s2);printf("x2=%d\n",x);
      y=FindSubstrFromRight(s,s1);printf("y2=%d\n",y);
      max=Max(max,y-x-strlen(s2));
  }
  printf("%d\n",max);
		
		
		
		
	}
	return 0;
}