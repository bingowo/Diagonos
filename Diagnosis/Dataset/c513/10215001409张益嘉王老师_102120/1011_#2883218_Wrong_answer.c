#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>

int main()
{
    int len,i,a[100],j,c[1000],num;
    long long z=0;
    complex double re,m=-1.0+1.0*I;
    long long cr,ci;
    char s[100];
    scanf("%s",s);
    len=strlen(s);
    for (i=2,j=0;i<len;i++,j++)
    {
        if((s[i]<='9')&&(s[i]>='0')) a[j]=s[i]-'0';
        else a[j]=s[i]-'A'+10;
    }
    /*for(i=0;i<len-2;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }*/

    for (i=0;i<len-2;i++)
    {
        z+=a[i]*pow(16,len-3-i);
    }
    //printf("z=%d\n",z);
    for(i=0;;i++)
    {
        if(z==0) break;
        c[i]=z%2;
        z=z>>1;

        //printf("z=%d,i=%d,c[%d]=%d\n",z,i,i,c[i]);
    }
    num=i-1;
    //printf("num=%d\n",num);
    re=c[num]+0.0*I;
    /*cr=creal(re);
    ci=cimag(re);
    printf("test:cr=%d,ci=%di\n",cr,ci);
    */
    for(i=num-1;i>=0;i--)
    {
        re*=m;
        re+=(c[i]+0.0*I);

    }

    cr=creal(re);
    ci=cimag(re);
    //printf("cr=%d,ci=%di\n",cr,ci);
    if(ci==0) printf("%lld",cr);
    else
    {
        if(cr!=0)
        {
            if (ci<0)
            {
                if (ci==-1) printf("%lld-i",cr);
                else printf("%lld%lldi",cr,ci);
            }
            else
            {
                if(ci==1) printf("%lld+i",cr);
                else printf("%lld+%lldi",cr,ci);
            }
        }
        else
        {
            if (ci<0)
            {
                if (ci==-1) printf("-i");
                else printf("%lldi",ci);
            }
            else
            {
                if(ci==1) printf("i");
                else printf("%lldi",ci);
            }
        }
    }
    return 0;

}
