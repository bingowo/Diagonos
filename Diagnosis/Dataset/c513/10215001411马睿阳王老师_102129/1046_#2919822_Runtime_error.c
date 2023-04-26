#include<stdio.h>
#include<string.h>
void lower(char*str)
{char b[1000];
 int x=0,d,y=0;
 d=strlen(str);
 for(x=0,y=0;x<d;x++,y++)
 if(isspace(str[x])) x++;
 else if(str[x]>='A'||str[x]<='Z')
       b[y]=str[x];
}
int main()
{int T,c,k,count;
 scanf("%d",&T);
 getchar();
 for(k=0;k<T;k++)
{int j=0,word=0;
 count=0;
 char s[105];
 char*p;
 p=gets(s);
 lower(s);
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
}
 printf("case #%d\n",k);
 printf("%d\n",count);
 return 0;
}
