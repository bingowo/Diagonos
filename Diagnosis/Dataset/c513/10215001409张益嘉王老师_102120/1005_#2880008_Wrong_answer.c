#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[55];
        int a[55],len,j,k,n;
        float re=0.0;
        scanf("%s",s);
        len=strlen(s);
        for(j=2,k=0;j<len;j++,k++)
        {
            a[k]=s[j]-'0';
        }
        for(k=0;k<(len-2);k++)
        {
            re+=a[k]*pow(8,-(k+1));
        }
        n=3*k;
        printf("case #%d:\n%.*f\n",i,n,re);

    }
    return 0;
}
