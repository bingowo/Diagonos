#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int num;
int cmp1(const void *a,const void *b)
{
    char *s1=(char*)a,*s2=(char*)b;
    return strcmp(s1,s2);
}
void print(char *s,int a)
{
    num=a+1;int i=(int)(pow(2,num)-1);
    int n=i;
    char an[i][num];int k,j;
    for(int i1=0;i>0;i--,i1++)
    {
        int suo=0;
        for(j=num-1,k=0;j>=0;j--,k++)
        {
            if((i>>j)&1) {an[i1][suo++]=s[k];}
        }
        an[i1][suo]='\0';
    }
    qsort(an,n,sizeof(an[0]),cmp1);
    for(int i2=0;i2<n;i2++)
    {
        for(int i3=0;i3<num;i3++) printf("%c",an[i2][i3]);
        printf("\n");
    }
}
int cmp(const void *a,const void *b)
{
    char s1=*(char *)a,s2=*(char *)b;
    if(s1>s2) return 1;
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[21];
        scanf("%s",s);
        int len=strlen(s);
        char ans[16];int i1=0;//i1记录个数
        ans[0]=s[0];
        for(int j=0;j<len;j++)
        {
            for(int k=0;k<j;k++)
            {
                if(s[j]!=s[k]&&k==j-1) ans[++i1]=s[j];
                else if(s[j]==s[k]) break;
            }
        }
        qsort(ans,i1+1,sizeof(char),cmp);
        printf("case #%d:\n",i);
        print(ans,i1);
    }
    return 0;
}
