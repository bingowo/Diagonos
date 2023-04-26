#include <stdio.h>
#include <string.h>
int main()
{   
    char s[51], d[155];
    int t,p,i,j,k,tmp;
    scanf("%d\n", &p);
    for (t = 0; t<p; ++t)
    {
        gets(s);
        int len=strlen(s);
        k=0;
        memset(d, 0, sizeof d);
        for (i=len-1;i>1;i--)
        {
            int n=s[i] - '0';
            for (j=0; j<k || n;j++)
            {
                tmp=10*n+(j<k?d[j]-'0': 0);
                d[j]=tmp/8+'0';
                n=tmp%8;
            }
            k=j;
        }
        printf("case #%d:\n0.%s\n",t,d);
    }
    return 0;
}