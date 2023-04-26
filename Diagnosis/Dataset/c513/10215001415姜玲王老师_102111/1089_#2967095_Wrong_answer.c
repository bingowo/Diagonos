#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void multiply(char*a,char*b,char*c)
{
    int k=strlen(a),l=strlen(b),i,j,d,temp;
    for(i=0;i<k;i++)
    {
        d=0;
        for(j=0;j<l;j++)
        {
            temp=(a[i]-'0')*(b[j]-'0')+d+c[i+j];
            c[i+j]=temp%10+'0';
            d=temp/10;
        }
        c[i+j]+=d;
    }
    if(c[i+j-1]) c[i+j-1]+='0';
}
int main()
{   int t;
     scanf("%d",&t);
     for(int y=0;y<t;y++)
    {printf("case #%d:\n",y);
    char A[100],B[100]={0},C[100]={0};
    scanf("%s",A);
    int b,n,i,k,o,p;
    scanf("%d%d",&b,&n);
    strcpy(B,A);
    if(b==0)
        {C[0]='1';}
    else{
        if(b==1) strcpy(C,A);
        else{
                for(i=2;i<b;i++)
                {   memset(C,0,sizeof(char)*100);
                    multiply(A,B,C);
                    int t=strlen(C);
                    for(k=n;k<t;t++)
                    {
                        C[k]=0;
                    }
                    strcpy(B,C);


                }
            }
        }
    for(o=n;o>=strlen(C);o--) printf("0");
    for(;o>=0;o--) printf("%c",C[o]);}

}
