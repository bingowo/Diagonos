#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void shandiao(char s[100000],char s2[100])
{
      int i=0;
      char t[2];
      for(i=0;s2[i];i++)
      {    t[0]=s2[i];t[1]='\0';
          char *p=strstr(s,t);
          s[p-s]='0'+1;
      }
}
int mima(char s[100000],int a[100000])
{
    int i=0,k=0;
    for(i=0;s[i];i++)
    {
        switch(s[i])
        {
            case 'Z':a[k]=0;k++;shandiao(s,"ZORE");break;
            case 'W':a[k]=2;k++;shandiao(s,"TWO");break;
            case 'U':a[k]=4;k++;shandiao(s,"FOUR");break;
            case 'X':a[k]=6;k++;shandiao(s,"SIX");break;
            case 'G':a[k]=0;k++;shandiao(s,"EIGHT");break;
        }
    }
    for(i=0;s[i];i++)
    {
        switch(s[i])
        {
            case 'R':a[k]=3;k++;shandiao(s,"THREE");break;
            case 'F':a[k]=5;k++;shandiao(s,"FIVE");break;
            case 'S':a[k]=7;k++;shandiao(s,"SEVEN");break;
            case 'N':a[k]=1;k++;shandiao(s,"ONE");break;
        }
    }
    for(i=0;s[i];i++)
    {
        switch(s[i])
        {
            case 'I':a[k]=9;k++;shandiao(s,"NINE");break;
        }
    }
    return k;
}
int cmp(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}
void hanshu(int h)
{
    char s[100000]={0};
    int a[100000]={0};
    scanf("%s",s);
    int k=0,i=0;
    k=mima(s,a);
    qsort(a,k,sizeof(a[0]),cmp);
    printf("case #%d:\n",h);
    for(i=0;i<k;i++)printf("%d",a[i]);
    printf("\n");
}
int main()
{
    int N,h;
    scanf("%d",&N);
    for(h=0;h<N;h++)
        hanshu(h);
}
