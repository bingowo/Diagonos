#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5

void atob(int n, int r)
{
    //printf("%d %d\n",n,r);
    int i,p;
    int j;
    char s[10000];
    int m = 0;
    while(n>0)
    {
        p = n%r;
        if(p<10)
        {
            s[m] = '0'+p;
            m++;
        }
        else
        {
            s[m] = 'A'+p-10;
            m++;
        }
        n /= r;
    }
    for(j=m-1; j>=0; j--)
        printf("%c",s[j]);
}

int main()
{
    int A,i;
    char s[1000];
    int B;
    int j = 1, n = 0;
    scanf("%d%s%d",&A,s,&B);
    int len = strlen(s);
    for(i=len-1; i>=0; i--)
    {
        if(s[i]<='9')
            n += (s[i]-'0') * j;
        if(s[i]>='A'&&s[i]<='Z')
            n += (s[i]-'A'+10)* j;
        if(s[i]>='a'&&s[i]<='z')
            n += (s[i]-'a'+10)* j;

        j *= A;
    }
    //printf("n=%d\n",n);
    atob(n,B);

    return 0;
}
