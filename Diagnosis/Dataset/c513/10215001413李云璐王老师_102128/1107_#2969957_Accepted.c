#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void fz(int a[][3],int k,int l)
{
    if(a[k][l]==0) a[k][l]=1;
    else a[k][l]=0;
}


void p(int a[][3],int k,int l)
{
    if(k==1&&l==1) {fz(a,k,l);fz(a,k,l-1);fz(a,k,l+1);fz(a,k-1,l);fz(a,k+1,l);}
    if(k==1&&l==0) {fz(a,k,l);fz(a,k+1,l);fz(a,k-1,l);fz(a,k,l+1);}
    if(k==1&&l==2) {fz(a,k,l);fz(a,k,l-1);fz(a,k+1,l);fz(a,k-1,l);}
    if(k==0&&l==0) {fz(a,k,l);fz(a,k,l+1);fz(a,k+1,l);}
    if(k==0&&l==1) {fz(a,k,l);fz(a,k,l-1);fz(a,k,l+1);fz(a,k+1,l);}
    if(k==0&&l==2) {fz(a,k,l);fz(a,k+1,l);fz(a,k,l-1);}
    if(k==2&&l==0) {fz(a,k,l);fz(a,k-1,l);fz(a,k,l+1);}
    if(k==2&&l==1) {fz(a,k,l);fz(a,k-1,l);fz(a,k,l+1);fz(a,k,l-1);}
    if(k==2&&l==2) {fz(a,k,l);fz(a,k-1,l);fz(a,k,l-1);}


}

int main()
{
    int n;
    scanf("%d",&n);
    int a[3][3];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
            for(int u=0;u<3;u++)
            a[j][u]=1;
        int c[3][3];
        for(int k=0;k<3;k++)
         {
             scanf("%d %d %d",&c[k][0],&c[k][1],&c[k][2]);
         }
         for(int k=0;k<3;k++)
             {
                 for(int l=0;l<3;l++)
                {
                    c[k][l]=c[k][l]%2;
                    if(c[k][l]!=0)
                    p(a,k,l);

                }

              }
         printf("case #%d:\n",i);
         for(int k=0;k<3;k++)
            printf("%d %d %d\n",a[k][0],a[k][1],a[k][2]);

    }
    return 0;
}
