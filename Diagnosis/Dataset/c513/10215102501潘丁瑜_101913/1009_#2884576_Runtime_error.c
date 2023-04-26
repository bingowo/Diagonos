#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int gcd(int a,int b);
int main()
{
    int n,i,result,g,j;
    int len,nmr,dnm;
    char s[120]={0};
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++)
    {
        gets(s);
        nmr =0;
        len = strlen(s);
        for(j=0;j<len;j++)
        {
            while(s[j]>0)
            {
                if(s[j] & 1 == 1)
                    nmr++;
                s[j] >>= 1;
            }
        }
        dnm = len * 8;
        g = gcd(nmr,dnm);
        printf("%d/%d\n",nmr/g,dnm/g);

    }
    return 0;
}

int gcd(int a,int b)
{
    return a?gcd(b%a,a):b;
}
