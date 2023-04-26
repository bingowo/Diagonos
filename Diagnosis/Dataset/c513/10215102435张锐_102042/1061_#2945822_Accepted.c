#include <stdio.h>
#include <stdlib.h>
#include <string.h>
long long int power(int base,int n)
{
    int i;
    long long int p;
    p=1;
    for(i=1;i<=n;i++) p=p*base;
    return p;
}
long long int ctoi(int *s,int len,int b)
{
    long long int sum=0;
    for(int i=len-1,j=0;i>=0;i--,j++)
    {
        sum+=s[i]*power(b,j);
    }
    return sum;
}
int cmp(const void *a,const void *b)
{
    char *s1=(char*) a,*s2=(char*)b;
    int len1=strlen(s1),len2=strlen(s2);
    int ints1[len1],ints2[len2];
    int i=2,j=2;ints1[0]=1,ints2[0]=1;int bo=1;
    for(int i1=1;i1<len1;i1++)
    {
        for(int k=0;k<i1;k++)
        {
            if(s1[i1]==s1[k]) {ints1[i1]=ints1[k];break;}
            if(k==i1-1&&s1[i1]!=s1[k])
            {
                if(bo) {ints1[i1]=0;bo=0;}
                else ints1[i1]=i++;
            }
        }
    }
    bo=1;
    for(int i1=1;i1<len2;i1++)
    {
        for(int k=0;k<i1;k++)
        {
            if(s2[i1]==s2[k]) {ints2[i1]=ints2[k];break;}
            if(k==i1-1&&s2[i1]!=s2[k])
            {
                if(bo) {ints2[i1]=0;bo=0;}
                else ints2[i1]=j++;
            }
        }
    }
    long long int num1=ctoi(ints1,len1,i),num2=ctoi(ints2,len2,j);
    if(num1>num2) return 1;
    if(num1==num2) return strcmp(s1,s2);
    else return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    char A[t][120];
    for(int i=0;i<t;i++)
    {
        scanf("%s",&A[i]);
    }
    qsort(A,t,sizeof(A[0]),cmp);
    for(int i=0;i<t;i++)
    {
        printf("%s\n",A[i]);
    }
    return 0;
}