#include<stdio.h>
#include<string.h>
int number(char*str);
int strnumcmp(const void*a,const void*b);
void sort(char*str,int n);
int main()
{char s[110][40];int i=0,x,t;
 
 while(scanf("%s",s[i])!=EOF)
 i++;
  sort(s,i);
  for(x=0;x<i-1;x++)
  printf("%s ",s[x]);
  printf("%s\n",s[x]);
  return 0;
}

int number(char*str,int sum)
{
  int l,f=0,j;
  l=strlen(str);
  for(j=0;j<l;j++)
  {
    if(str[j]>='0'&&str[j]<='9')
    {f=1;
    sum=sum*10+str[j]-48;}
  }
  if(f==0) sum=-1;
return sum;
}

void strnumcmp(const void*a,const void*b)
{
 int s1,s2;int sum1,sum2;
 char*str1,*str2;
 str1=(char*)a;
 str2=(char*)b;
 s1=number(str1,sum1);
 s2=number(str2,sum2);
 if(s1==s2) return strcmp(str1,str2);
 else{if(s1>s2) return -1;
       else return 1;}
}

void sort(char*str,int n)
{ qsort(str,n,sizeof(str[0]),strnumcmp);
}

