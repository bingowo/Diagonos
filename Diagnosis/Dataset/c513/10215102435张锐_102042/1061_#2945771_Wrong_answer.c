#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a,const void *b)
{
    char *s1=(char*) a,*s2=(char*)b;
    int len1=strlen(s1),len2=strlen(s2);
    if(len1>len2) return 1;
    if(len1<len2) return 0;
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
    if(len1==len2)
    {
        for(int k=0;k<len1;k++)
        {
            if(ints1[k]>ints2[k]) return 1;
        }
        return 0;
    }
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
    qsort(A,t,sizeof(A[0]),cmp);
    for(int i=0;i<t;i++)
    {
        printf("%s\n",A[i]);
    }
    return 0;
}
