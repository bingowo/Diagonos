#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char c;
    int c=0,t=0;
    int z1[500]={0},f1[500]={0};
    int z2[500]={0},f2[500]={0};
    int resz[500]={0};resf[500]={0};
    int lz1=0,lf1=0,lz2=0,lf2=0;
    int lf=0,lz=0;
    int n;
    int i=0,j=0,k=0;
    while((c=getchar())!=EOF)
    {
        if(c==' ')
        {
            i++;
            j=0;
        }
        else if(c=='.')
        {
            j++;
            c=getchar();
            if(c==' ')
            {
                i++;
                j=0;
            }
        }
        if(i==0)
        {
            if(j==0)
            {
                z1[lz1]=c-'0';
                lz1++;
            }
            else if(j==1)
            {
                f1[lf1]=c-'0';
                lf1++;
            }
        }
        else if(i==1)
        {
            if(j==0)
            {
                z2[lz2]=c-'0';
                lz2++;
            }
            else if(j==1)
            {
                f2[lf2]=c-'0';
                lf2++;
            }
        }
        else if(i==2)
        {
            scanf("%d",&n);
        }
    }
    if(lf1>lf2)
        lf=lf1;
    else
        lf=lf2;
    if(lz1>lz2)
        lz=lz1;
    else
        lz=lz2;
    for(i=lz-1;i>=0;i--)
    {
        t=z1[i]+z2[i]+c;
        c=t/10;
        resz[lz-1-i]=t%10;
    }
    if(c!=0)
    {
        resz[lz]=c;
        lz++;
        c=0;
    }
    for(i=lf-1;i>=0;i--)
    {
        t=f1[i]+f2[i]+c;
        c=t/10;
        resf[lf-1-i]=t%10;
    }
    if(c!=0)
    {
        resf[lf]=c;
        lf++;
        c=0;
    }
    if(lz==0)
        printf("0.");
    else
    {
        for(i=lz-1;i>=0;i--)
        {
            printf("%d",resz[i]);
        }
        printf(".");
    }
    i=lf-1;
    for(j=0;j<n;j++)
    {
        printf("%d",resf[i]);
        i--;
    }
    printf("\n");
    return 0;
}