#include<stdio.h>
#include<string.h>
void lower(char*str)
{char b[1000];
 int x=0,d,y=0;
 d=strlen(str);
 for(x=0,y=0;x<d;x++,y++)
 if(isspace(str[x])) x++;
 else if(str[x]>='A'||str[x]<='Z')
       b[y]=str[x]+'32';
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
 count++;
 c=strlen(s);
 int i=0,t=0,d=0;
 char b[100];
for(i=0;i<c;i++)
{if(s[i]!='') 
 {b[t++]=s[i];
 continue;
 }
 b[t]='\0';
 if(strncmp(b,"the",i)==0)  count--;
 else if(strncmp(b,'a',i)==0) count--;
 else if(strncmp(b,"an",i)==0) count--;
 else if(strncmp(b,"of",i)==0) count--;
 else if(strncmp(b,"for",i)==0) count--;
 else if(strncmp(b,"and",i)==0) count--;
 t=0;
}
}
 printf("case #%d\n",k);
 printf("%d\n",count);
 return 0;
}
