#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 550

void reverse (char* s)
{
    int i,j;
    for (i=0,j=strlen(s)-1;i<j;i++,j--)
    {
        char temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}

int main()
{
    char s1[MAX]={0}; char s2[MAX]={0};
    while (scanf("%s",s1)!=EOF)
    {
        int A[MAX]={0}; int B[MAX]={0}; int C[MAX]={0};
        scanf("%s",s2);
        int m=strlen(s1),n=strlen(s2);
        reverse(s1); reverse(s2);
        for (int i=0;i<m;i++)
            A[i]=s1[i]-'0';
        for (int i=0;i<n;i++)
            B[i]=s2[i]-'0';
        m=(m>n)?m:n;
        for (int i=0;i<m;i++)
        {
            if (A[i]>=B[i])
                C[i]=A[i]-B[i];
            else
            {
                A[i]+=10;
                A[i+1]-=1;
                C[i]=A[i]-B[i];
            }

        }
        int j;
        for (j=m-1;C[j]==0;j--);
        for ( j;j>=0;j--)
            printf("%d",C[j]);
        printf("\n");

    }


    return 0;
}
