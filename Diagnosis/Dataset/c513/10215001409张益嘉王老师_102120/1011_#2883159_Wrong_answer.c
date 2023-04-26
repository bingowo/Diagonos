#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <complex.h>

int main()
{
    int len,i,z=0,a[100],j,c[1000],num;
    complex double re,m=-1.0+1.0*I;
    int cr,ci;
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
    for(i=0;i<32;i++)
    {
        if(z==0) break;
        c[i]=z%2;
        z=z>>1;

        //printf("z=%d,i=%d,c[%d]=%d\n",z,i,i,c[i]);
    }
    num=i-1;
    //printf("num=%d\n",num);
    re=(c[num]+0.0*I)*m;
    /*cr=creal(re);
    ci=cimag(re);
    printf("test:cr=%d,ci=%di\n",cr,ci);
    */
    for(i=num-1;i>0;i--)
    {
        re+=(c[i]+0.0*I);
        re*=m;
    }
    re+=c[0];
    cr=creal(re);
    ci=cimag(re);
    //printf("cr=%d,ci=%di\n",cr,ci);
    if(ci==0) printf("%d",cr);
    else
    {
        if (ci<0) 
        {
            if (ci==-1) printf("%d-i",cr);
            else printf("%d%di",cr,ci);
        }
        else 
        {
            if(ci==1) printf("%d+i",cr);
            else printf("%d+%di",cr,ci);
        }
    }
    return 0;

}
