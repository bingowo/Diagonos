#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int power(int base,int n)
{
    int i;
    int p;
    p=1;
    for(i=1;i<=n;i++) p=p*base;
    return p;
}
int cmp(const void *a,const void *b)
{
    char *s1=(char*) a,*s2=(char*)b;
    int len1=strlen(s1),len2=strlen(s2);
    int ints1[len1],ints2[len2];
    int i=2,j=2;ints1[0]=1,ints2[0]=1;
    for(int i1=1;i1<len1;i1++)
    {
        for(int k=0;k<i1;k++)
        {
            if(s1[i1]==s1[k]) ints1[i1]=ints1[k];
            if(k==i1-1&&s1[i1]!=s1[k])
            {
                if(s1[k]==1) s1[i1]=0;
                else s1[i1]=i++;
            }
        }
    }
    for(int i1=1;i1<len2;i1++)
    {
        for(int k=0;k<i1;k++)
        {
            if(s2[i1]==s2[k]) ints2[i1]=ints2[k];
            if(k==i1-1&&s2[i1]!=s2[k])
            {
                if(s2[k]==1) s2[i1]=0;
                else s2[i1]=i++;
            }
        }
    }
    int num1=0,num2=0;
    for(int ii=len1-1,j=0;ii>=0;ii--,j++)
    {
        num1+=s1[ii]*power(i,j);
    }
    for(int ii=len2-1,jj=0;ii>=0;ii--,jj++)
    {
        num2+=s2[ii]*power(j,jj);
    }
    printf("num1=%d num2=%d\n",num1,num2);
    if(num1>num2) return 1;
    else return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    char A[t][20];
    for(int i=0;i<t;i++)
    {
        scanf("%s",&A[i]);
    }
    qsort(*A,t,sizeof(A[0]),cmp);
    for(int i=0;i<t;i++)
    {
        printf("%s\n",A[i]);
    }
    return 0;
}
