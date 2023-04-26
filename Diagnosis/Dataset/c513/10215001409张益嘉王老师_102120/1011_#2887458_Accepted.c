#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>

int main()
{
    int len,i,a[100]={0},j,num,st=0;
    int c[1000]={-1};
    //long long z=0;
    long double complex re,m=-1.0+1.0*I;
    long long cr,ci;
    char s[100];

    //scanf("%llx",&z);

    scanf("%s",s);
    len=strlen(s);
    for (i=2,j=0;i<len;i++,j+=4)
    {
        switch(s[i])
        {
            case '0':c[j]=0;c[j+1]=0;c[j+2]=0;c[j+3]=0;break;
            case '1':c[j]=0;c[j+1]=0;c[j+2]=0;c[j+3]=1;break;
            case '2':c[j]=0;c[j+1]=0;c[j+2]=1;c[j+3]=0;break;
            case '3':c[j]=0;c[j+1]=0;c[j+2]=1;c[j+3]=1;break;
            case '4':c[j]=0;c[j+1]=1;c[j+2]=0;c[j+3]=0;break;
            case '5':c[j]=0;c[j+1]=1;c[j+2]=0;c[j+3]=1;break;
            case '6':c[j]=0;c[j+1]=1;c[j+2]=1;c[j+3]=0;break;
            case '7':c[j]=0;c[j+1]=1;c[j+2]=1;c[j+3]=1;break;
            case '8':c[j]=1;c[j+1]=0;c[j+2]=0;c[j+3]=0;break;
            case '9':c[j]=1;c[j+1]=0;c[j+2]=0;c[j+3]=1;break;
            case 'A':c[j]=1;c[j+1]=0;c[j+2]=1;c[j+3]=0;break;
            case 'B':c[j]=1;c[j+1]=0;c[j+2]=1;c[j+3]=1;break;
            case 'C':c[j]=1;c[j+1]=1;c[j+2]=0;c[j+3]=0;break;
            case 'D':c[j]=1;c[j+1]=1;c[j+2]=0;c[j+3]=1;break;
            case 'E':c[j]=1;c[j+1]=1;c[j+2]=1;c[j+3]=0;break;
            case 'F':c[j]=1;c[j+1]=1;c[j+2]=1;c[j+3]=1;break;
            default:break;
        }
    }
   /* for(i=0;i<len-2;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
    */
    /*
    for (i=0;i<len-2;i++)
    {
        z+=a[i]*pow(16,len-3-i);
    }*/
    //printf("z=%d\n",z);

    /*for(i=0;i<(len-2)*4;i++)
    {
        //if(z==0) break;
        //c[i]=z&1;
        //z=z>>1;

        printf("c[%d]=%d\n",i,c[i]);
    }*/

    for(i=0;i<=num;i++)
    {
        if (c[i]==0) st++;
        else break;
    }
    num=(len-2)*4-1;
    //printf("num=%d\n",num);
    re=c[st]+0.0*I;
    /*cr=creal(re);
    ci=cimag(re);
    printf("test:cr=%d,ci=%di\n",cr,ci);
    */

    for(i=st+1;i<=num;i++)
    {
        re*=m;
        re+=(c[i]+0.0*I);

    }

    cr=creall(re);
    ci=cimagl(re);
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
