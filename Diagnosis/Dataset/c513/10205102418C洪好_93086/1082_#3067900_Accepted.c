#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define L 500
void Input(int*a);
void add(int*a,int*b,int n);
void Output(int*a,int n);

int main()
{
    int n;
    int a[2*L+1]={0};int b[2*L+1]={0};
    Input(a);
    Input(b);
    scanf("%d",&n);
    add(a,b,n);
    Output(a,n);
    return 0;
}
void Input(int*a)
{
    int len;
    char s[L+1]={0};
    scanf("%s",s);
    len =strlen(s);
    int i=0,j,k;
    while(s[i]&&s[i]!='.')i++;
    for(j=i-1,k=L;j>=0;j--,k-- )
    {
       a[k]=s[j]-'0';
    }
    for(k=L+1,j=i+1;j<len;k++,j++)
    {
       a[k]=s[j]-'0';
    }
}
void add(int *a,int *b,int n)
{
    int i;
    for( i=2*L;i>L+n;i--)
    {
        //printf("%d",a[i]);
        a[i]=a[i]+b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }//printf("\n");
     //printf("%d %d\n",b[i+1],a[i+1]);
    if(a[i+1]>=5) a[i]++;
    for(i=L+n;i>0;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]%=10;
    }
     //printf("%d\n",a[i+1]);


}
void Output(int*a,int n)
{
    int i,j,k;
    for(i=0;i<=L;i++)
    {
        if (a[i]!=0)break;
    }
    if(i>L)printf("0");
    else
    {
        for(j=i;j<=L;j++)
        {
            printf("%d",a[j]);
        }
    }
    printf(".");
    for(k=L+1;k<=L+n;k++)
    {
        printf("%d",a[k]);
    }
    printf("\n");
}
