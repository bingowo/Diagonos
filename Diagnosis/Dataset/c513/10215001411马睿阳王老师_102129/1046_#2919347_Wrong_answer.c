#include<stdio.h>
#include<string.h>
int main()
{int T,c;
 char s[105];
 scanf("%d",&T);
 gets(s);
 int j=0,word=0,count=0;
 for(j=0;j<strlen(s);j++)
 {if(isspace(s[j])) word=0;
  else {if(isspace(s[j+1])) {word=1;count++;}}
 }
 c=strlen(s);
 int i=0;
 for(i;i<c;i++)
 {while(isspace(s[i])) i++;//判断每个单词的长度
 i=i-1;
 if(strncmp(s,'the',i)==0)  count--;
 else if(strncmp(s,'a',i)==0) count--;
 else if(strncmp(s,'an',i)==0) count--;
 else if(strncmp(s,'of',i)==0) count--;
 else if(strncmp(s,'for',i)==0) count--;
 else if(strncmp(s,'and',i)==0) count--;
 }
 printf("case #%d\n",i);
 printf("%d\n",count);
 return 0;
}
