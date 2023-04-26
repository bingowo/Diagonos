#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int FindSubstrFromLeft(char*s,char*s1)              //从左到右在s中找出第一个字串s1(s2)出现的位置x
{ int i,sLen=strlen(s),s1Len=strlen(s1),j;
  for (i=0;i<sLen-s1Len;i++)
  {  for (j=0;j<s1Len&&s[i+j]==s1[j];j++);
      if (j==s1Len) return i;
  }
  return -1;
}

int FindSubstrFromRight(char*s,char*s1)      //从右到左在s中找出第一个字串s2(s1)出现的位置y
{ int i,sLen=strlen(s),s1Len=strlen(s1),j;
  for (i=sLen-s1Len;i>=0;i--)
  {  for (j=0;j<s1Len&&s[i+j]==s1[j];j++);
	 if (j==s1Len) return i;
  }
  return -1;
}

int max(int a,int b) { return a>b?a:b; }


int main()
{
    int T,n,i,j;
    scanf("%d",&T);
    
    for(n=0;n<T;n++){
    int maxDist=0,x,y;
    char s[81],s1[81],s2[81];
    scanf("%s",s1);                     //gets(s1);gets(s2);gets(s);
    scanf("%s",s2);
    scanf("%s",s);    
    
    x=FindSubstrFromLeft(s,s1);
    y=FindSubstrFromRight(s,s2);
    if (x!=-1&&y!=-1) {  
        maxDist=max(maxDist,y-x-strlen(s1));
        x=FindSubstrFromLeft(s,s2);
        y=FindSubstrFromRight(s,s1);
        maxDist=max(maxDist,y-x-strlen(s2));
    }
        
            
            
    printf("case #%d:\n",n);
    printf("%d",maxDist);
    printf("\n");
    }
return 0;
}
