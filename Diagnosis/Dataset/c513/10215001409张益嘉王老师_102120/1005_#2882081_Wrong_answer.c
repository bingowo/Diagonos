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
        long double re=0.0;
        scanf("%s",s);
        len=strlen(s);
        for(j=2,k=0;j<len;j++,k++)
        {
            a[k]=s[j]-'0';
        }
        for(k=(len-3);k>=0;k--)
        {
            re+=a[k];
            re/=8.0;
        }
        n=3*(len-2);
        //printf("[%d]n=%d\n",i,n);
        char str[1000];
        sprintf(str,"%.*lf",n,re);
        for(j=strlen(str)-1;j>=0;j--)
        {
            if(str[j]=='0') str[j]=0;
            else break;
        }
        printf("case #%d:\n%s\n",i,str);

    }
    return 0;
}