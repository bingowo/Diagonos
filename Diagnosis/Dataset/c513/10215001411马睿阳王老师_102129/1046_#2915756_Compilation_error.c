#include<stdio.h>
#include<string.h>
int main()
{int T;
 char s[105];
 scanf("%d",&T);
 gets(s);
 int i=0,word=0,count=0;
 for(i=0;i<strlen(s);i++)
 {if(s[i]=='') word=0;
  else {if(s[i+1]=='') count++;}
 }
 printf("case #:%d\n",i);
 printf("%d",count);
 return 0;
}
