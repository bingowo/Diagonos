#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>

void fz(int*a,int k)
{
    for(int i=0;i<k/2;i++)
    {
        int c;
        c=a[i];
        a[i]=a[k-i-1];
        a[k-i-1]=c;
    }
}

void jh(int*a,int*b,int z1,int z2)
{
    int s1[600];
    int max=(z1>z2)?z1:z2;
    for(int i=0;i<max;i++)
       {
           s1[i]=a[i];
           a[i]=b[i];
           b[i]=s1[i];
       }
}

void jiayi(int*c2,int *c1,int wei,int maxf,int maxz)
{
    int yu=(c2[maxf-wei]+1)/10;
    c2[maxf-wei]=(c2[maxf-wei]+1)%10;
    for(int i=maxf-wei+1;i<maxf;i++)
    {
        int z=c2[i];
        c2[i]=(c2[i]+yu)%10;
        yu=(z+yu)/10;
    }

        for(int i=0;i<maxz;i++)
        {
            int z=c1[i];
            c1[i]=(c1[i]+yu)%10;
            yu=(z+yu)/10;
        }


    if(yu>0) {c1[maxz]=yu;maxz++;}
    fz(c1,maxz);
    fz(c2,maxf);
    int k=0;
    while(k<maxz&&c1[k]==0) k++;
    if(k==maxz) printf("0");
    else if(k==maxz-1) printf("%d",c1[k]);
    else for(int i=k;i<maxz;i++)
        printf("%d",c1[i]);
    if(wei>0)
       {
           printf(".");
           for(int i=0;i<wei;i++)
           printf("%d",c2[i]);}

}

int main()
{
    int a1[600]={0},a2[600]={0},b1[600]={0},b2[600]={0},z1=0,z2=0,f1=0,f2=0,wei;
    int c1[600]={0},c2[600]={0};
    char a[600],b[600];
    scanf("%s",a);
    scanf("%s",b);
    scanf("%d",&wei);

    char *p1=a,*p2=b;
    while(*p1!='.'&&*p1)
       {
           a1[z1]=*p1-'0';
           z1++;
           p1++;
       }
    if(*p1=='.'){p1++;
    while(*p1)
    {
        a2[f1]=*p1-'0';
        f1++;
        p1++;
    }}
    while(*p2!='.'&&*p2)
       {
           b1[z2]=*p2-'0';
           z2++;
           p2++;
       }
    if(*p2=='.'){p2++;
    while(*p2)
    {
        b2[f2]=*p2-'0';
        f2++;
        p2++;
    }}
    //z1,z2是a,b整数的位数，f1,f1是a,b小数的位数
    int flag=0;

    if(z1<z2) {jh(a1,b1,z1,z2);jh(a2,b2,f1,f2);flag=1;}
    if(z1==z2)
    {
        if(strcmp(a1,b1)<0) {jh(a1,b1,z1,z2);jh(a2,b2,f1,f2);flag=1;}
        if(strcmp(a1,b1)==0)
        {

            if(strcmp(a2,b2)<0) {jh(a1,b1,z1,z2);jh(a2,b2,f1,f2);flag=1;}
        }
    }
    int maxf=(f1>f2)?f1:f2;
    fz(a2,maxf);
    fz(b2,maxf);
    int jie1=0,jie2=0;
    for(int i=0;i<maxf;i++)
        {
            c2[i]=a2[i]-b2[i]-jie1;
            if(c2[i]<0) {c2[i]+=10;jie1=1;}
            else jie1=0;
        }
    fz(c2,maxf);
    if(jie1>0) jie2=jie1;
    int maxz=(z1>z2)?z1:z2;
    fz(a1,z1);
    fz(b1,z2);
    for(int i=0;i<maxz;i++)
        {
            c1[i]=a1[i]-b1[i]-jie2;
            if(c1[i]<0) {c1[i]+=10;jie2=1;}
            else jie2=0;
        }
    if(flag==1) printf("-");
    if(c2[wei]>=5)
        {
            fz(c2,maxf);
            jiayi(c2,c1,wei,maxf,maxz);

        }


    if(c2[wei]<=4)
{

    fz(c1,maxz);
    int k=0;
    while(k<maxz&&c1[k]==0) k++;
    if(k==maxz) printf("0");
    else if(k==maxz-1) printf("%d",c1[k]);
    else for(int i=k;i<maxz;i++)
        printf("%d",c1[i]);
    if(wei>0)
       {
           printf(".");
           for(int i=0;i<wei;i++)
           printf("%d",c2[i]);}
}
    return 0;
    }

