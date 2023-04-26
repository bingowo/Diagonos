#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int number(char* str)
{
    int len,i=0,sum=0,flag=0;
    len=strlen(str);
    for(i;i<len;i++)
    {
          if(str[i]>='0'&&str[i]<='9')
        {
            sum=sum*10+str[i]-'0';
            flag=1;
        }
    }
    if (flag==1)
        return sum;
    else return -1;

}

int cmp(const void*a,const void *b)
{
    char *p1=(char *)a;
    char *p2=(char *)b;
    int shuzi1=number(p1);
    int shuzi2=number(p2);
    if(shuzi1<shuzi2)
    {
        return -1;
    }
    else if(shuzi1==-1&&shuzi2==-1)
    {
        return strcmp(p1,p2);
    }
    else return 1;
}

int main()
{
    char str[101][40];
    int i=0;
    while(scanf("%s",str[i])!=EOF)
    {
        i++;
    }
    qsort(str,i,sizeof(str[0]),cmp);
    for(int j=0;j<i;j++)
    {
        printf("%s ",str[j]);
    }

}

