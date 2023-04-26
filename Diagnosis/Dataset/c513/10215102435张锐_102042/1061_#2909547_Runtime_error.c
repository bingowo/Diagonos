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
int ctoi(char *s,int b)
{
    int len=strlen(s);int sum=0;
    for(int i=len-1,j=0;i>=0;i--,j++)
    {
        sum+=(s[i]-'0')*power(b,j);
    }
    return sum;
}
int cmp(const void *a,const void *b)
{
    char *s1=(char*) a,*s2=(char*)b;
    int len1=strlen(s1),len2=strlen(s2);
    int i=0,j=0,num=0;
    for(;i<len1;i++) {if(s1[i]!=0) break;}
    len1-=i;
    for(;i<len1+i;i++)
    {
        for(j=0;j<i;j++)
        {
            if(s1[i]==s1[j]) break;
            if(j==i-1&&s1[i]!=s1[j]) num++;
        }
    }
    len1-=num;num=0;
    for(i=0;i<len1;i++){if(s1[i]!=0) break;}
    len2-=i;
    for(;i<len2+i;i++)
    {
        for(j=0;j<i;j++)
        {
            if(s2[i]==s2[j]) break;
            if(j==i-1&&s2[i]!=s2[j]) num++;
        }
    }
    len2-=num;
    int num1,num2;
    num1=ctoi(s1,len1+1);
    num2=ctoi(s2,len2+1);
    if(num1>num2) return 1;
    if(num1==num2) return strcmp(s1,s2);
    else return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    char **A=(char**) malloc(t*sizeof(char*));
    for(int i=0;i<t;i++)
    {
        scanf("%s",A[i]);
    }
    qsort(*A,t,sizeof(A[0]),cmp);
    for(int i=0;i<t;i++)
    {
        printf("%s\n",A[i]);
    }
    free(A);
    return 0;
}
