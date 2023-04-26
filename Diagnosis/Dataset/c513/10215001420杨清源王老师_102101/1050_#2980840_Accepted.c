#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int max(int a,int b);
    int FindSubstrFromLeft(char*s,char*s1);
    int FindSubstrFromRight(char*s,char*s1);
    int m;
    scanf("%d\n",&m);
    for(int z=0; z<m; z++)
    {
        char s1[81],s2[81],s[81];
        int maxDist=0,x,y;
        gets(s1);
        gets(s2);
        gets(s);
        x=FindSubstrFromLeft(s,s1);
        y=FindSubstrFromRight(s,s2);
        if (x!=-1&&y!=-1)
        {
            maxDist=max(maxDist,y-x-strlen(s1));
            x=FindSubstrFromLeft(s,s2);
            y=FindSubstrFromRight(s,s1);
            maxDist=max(maxDist,y-x-strlen(s2));
        }

        printf("case #%d:\n",z);

        printf("%d",maxDist);

        printf("\n");
    }
    return 0;
}


int max(int a,int b)
{
    return a>b?a:b;
}

int FindSubstrFromLeft(char*s,char*s1)
{
    int i,sLen=strlen(s),s1Len=strlen(s1),j;
    for (i=0; i<sLen-s1Len; i++)
    {
        for (j=0; j<s1Len&&s[i+j]==s1[j]; j++);
        if (j==s1Len) return i;
    }
    return -1;
}

int FindSubstrFromRight(char*s,char*s1)
{
    int i,sLen=strlen(s),s1Len=strlen(s1),j;
    for (i=sLen-s1Len; i>=0; i--)
    {
        for (j=0; j<s1Len&&s[i+j]==s1[j]; j++);
        if (j==s1Len) return i;
    }
    return -1;
}




