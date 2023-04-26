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
 int i=0,t=0;
 char b[100];
 while(!isspace(s[i++]))
 {b[t++]=s[i++];
 if(strncmp(b,'the',t)==0)  count--;
 else if(strncmp(b,'a',t)==0) count--;
 else if(strncmp(b,'an',t)==0) count--;
 else if(strncmp(b,'of',t)==0) count--;
 else if(strncmp(b,'for',t)==0) count--;
 else if(strncmp(b,'and',t)==0) count--;
 t=0;
 }
}
 printf("case #%d\n",k);
 printf("%d\n",count);
 return 0;
}
