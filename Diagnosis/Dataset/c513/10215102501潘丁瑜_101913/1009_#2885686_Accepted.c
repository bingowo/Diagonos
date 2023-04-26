#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int gcd(int a,int b);
int main()
{
    int n,i,result,g,j;
    int len,nume,deno;
    unsigned char s[241]={0};
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(s);
        nume = 0;
        len = strlen(s);
        for(j=0;j<len;j++)
        {
            while(s[j]>0)
            {
                if(s[j] & 1 == 1)
                    nume ++;
                s[j] >>= 1;
            }
        }
        deno = len * 8;
        g = gcd(nume,deno);
        printf("%d/%d\n",nume/g , deno/g);

    }
    return 0;
}

int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}