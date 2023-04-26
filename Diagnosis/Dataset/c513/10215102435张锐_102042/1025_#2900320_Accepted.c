#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num(char *s1)
{
    int len=strlen(s1);int x=1;
    for(int i=1;i<len;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(s1[i]==s1[j]) break;
            else if(j==i-1&&s1[i]!=s1[j]) x++;
        }
    }
    return x;
}
int cmp(const void *a,const void *b)
{
    char *s1,*s2;
    s1=(char *)a,s2=(char *)b;
    int num1=num(s1),num2=num(s2);
    if(num1<num2) return 1;
    else if(num1>num2) return -1;
    else if(num1==num2)
    {
        int n=0;
        if(strlen(s1)<=strlen(s2)) n=strlen(s1);
        else n=strlen(s2);
        for(int i=0;i<n;i++)
        {
            if(s1[i]==s2[i]) continue;
            else return s1[i]-s2[i];
        }
        if(strlen(s1)<=strlen(s2)) return -1;
        else return 1;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        char A[200][50]={0};
        for(int j=0;j<n;j++)
        {
            scanf("%s",A[j]);
        }
        qsort(A,n,sizeof(A[0]),cmp);
        printf("case #%d:\n",i);
        for(int j=0;j<n;j++)
        {
            printf("%s\n",A[j]);
        }
    }
    return 0;
}
