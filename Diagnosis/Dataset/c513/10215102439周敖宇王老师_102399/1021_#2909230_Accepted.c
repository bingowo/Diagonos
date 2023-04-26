#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int num[120];
int cmp(const void *a,const void *b)
{
    char *pa=(char*)a,*pb=(char*)b;
    int i=0,t;
    while(*(pa+i)!='\0' && *(pb+i)!='\0')
    {
        t=num[*(pa+i)-'A']-num[*(pb+i)-'A'];
        if(t!=0)  return t;
        i++;
    }
    if(*(pa+i)=='\0' && *(pb+i)=='\0')  return 1;
    if(*(pa+i)=='\0' && *(pb+i)!='\0')  return -1;
    if(*(pa+i)!='\0' && *(pb+i)=='\0')  return 1;
}
int main()
{
    int i,j,k,cnt=0;
    char s[30],c;
    char m[120][30];
    while((c=getchar())!=EOF)
    {
        num[c-'A']=0;
        num[c-'A'+32]=0;
        scanf("%s",s);
        for(i=0;i<=24;i++)
        {
            num[s[i]-'A']=i+1;
            num[s[i]-'A'+32]=i+1;
        }
        cnt=0;
        scanf("%s",m[cnt++]);
        while((c=getchar())==' ')
        {
            scanf("%s",m[cnt++]);
        }
        qsort(m,cnt,sizeof(m[0]),cmp);
        for(i=0;i<=cnt-2;i++)  printf("%s ",m[i]);
        printf("%s\n",m[cnt-1]);

        
        if(c==EOF)  break;
    }
    return 0;
}