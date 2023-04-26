#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int FindSubstrFromLeft(char*s,char*s1)
{ int i,sLen=strlen(s),s1Len=strlen(s1),j;
  for (i=0;i<sLen-s1Len;i++)
  {  for (j=0;j<s1Len&&s[i+j]==s1[j];j++);
      if (j==s1Len) return i;
  }
  return -1;
}
int FindSubstrFromRight(char*s,char*s1)
{ int i,sLen=strlen(s),s1Len=strlen(s1),j;
  for (i=sLen-s1Len;i>=0;i--)
  {  for (j=0;j<s1Len&&s[i+j]==s1[j];j++);
	 if (j==s1Len) return i;
  }
  return -1;
}
int max(int a,int b) { return a>b?a:b; }

int main(){
	int T;
	char s1[100],s2[100],s[100];
	scanf("%d\n",&T);
	for(int i=0;i<T;i++){
		scanf("%s\n",s1);
		scanf("%s\n",s2);
		scanf("%s\n",s);
		int x=FindSubstrFromLeft(s,s1);
		int y=FindSubstrFromRight(s,s2);
		int maxDist=0;
		if (x!=-1&&y!=-1) 
  {   maxDist=max(maxDist,y-x-strlen(s1));
      x=FindSubstrFromLeft(s,s2);
      y=FindSubstrFromRight(s,s1);
      maxDist=max(maxDist,y-x-strlen(s2));
  }
  printf("case #%d:\n",i);
  printf("%d\n",maxDist);
		
	}
	
	return 0;
	
}