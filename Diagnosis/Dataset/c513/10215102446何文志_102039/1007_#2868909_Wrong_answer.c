#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* itobinaryString(int N)
{
    static char s[100];
    memset(s,0,100);
    int n = N,r = 0,i = 0;

    while(n != 0)
    {
        r = n%2;
        n = n/2;
        s[i++] = r + '0';
    }
    reverseString(s);
    return s;
}

void reverseString(char* s)
{
    int len = strlen(s);
    int i = 0,j = len;
    char temp = 0;
    for(i = 0,j = len-1;i<j;i++,j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int solveMaxLenth(char s[])
{
    int i = 0,j = 0,len = 0,maxLen = 0;
    while(s[j+1]!=0)
    {
        if(s[j] == s[j+1])
        {
            i = j+1;

        }
        j++;
        len = j+1-i;
        if(len>maxLen){maxLen = len;}

    }
    return maxLen;
}

int main()
{
    int T = 0, n = 0;
    int i = 0;
    scanf("%d",&T);
    int nlist[T];
    memset(nlist,0,T);

    for(i = 0;i<T;i++)
    {
        scanf("%d",&nlist[i]);
    }

    for(i = 0;i<T;i++)
    {
        printf("case #%d:\n%d\n",i,solveMaxLenth(itobinaryString(nlist[i])));
    }

    return 0;
}
