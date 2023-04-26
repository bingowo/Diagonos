#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define M 1000000
int main()
{
    char str[M]={0};
    int number[10]={0};
    int big[26]={0};
    int small[26]={0};
    int i,j,k,temp,t,MAX=0;
    int L=0,R=0;
    int n=0;
    scanf("%s",str);
    n=strlen(str);
    for(i=0;i<n;i++)
    {
        if(('A'<=str[i])&&(str[i]<='Z'))
        {
            temp=str[i]-'A';
            if(big[temp]==0)
            {
                big[temp]++;
                R=i;
            }
            else
            {
                big[temp]=1;
                t=R-L+1;
                if(t>MAX)
                {
                    j=L;
                    k=R;
                }
                L=i;
            }
        }
        else if(('a'<=str[i])&&(str[i]<='z'))
        {
            temp=str[i]-'a';
            if(small[temp]==0)
            {
                small[temp]++;
                R=i;
            }
            else
            {
                small[temp]=1;
                t=R-L+1;
                if(t>MAX)
                {
                    j=L;
                    k=R;
                }
                L=i;
            }
        }
        else if(('0'<=str[i])&&(str[i]<='9'))
        {
            temp=str[i]-'0';
            if(number[temp]==0)
            {
                number[temp]++;
                R=i;
            }
            else
            {
                number[temp]=1;
                t=R-L+1;
                if(t>MAX)
                {
                    j=L;
                    k=R;
                }
                L=i;
            }
        }
    }
    for(i=j;i<MAX;i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}