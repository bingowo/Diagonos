#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void conversion(int x,int k)
{
    int n=abs(x);
    int out;
    int i=0;
    while(n>0)
    {
        out=k*(pow(10,i));
        out+=out;
        n/=10;
        i++;
    }
    printf("%d",out);
}
void shenmixinxi(char e[])
{
    int s=sizeof(e);
    int i,a,flag=1;
    int y[100];
    for(i=0;i<s;i++)
    {
        if(e[i]==e[i+1])
        {
            flag=-1;
            break;
        }
    }
    if(flag==1)
    {
        y[0]=1;
        y[1]=0;
        int k=1;
        for(int j=2;j<s;j++)
        {
            y[j]=++k;
        }
        a=atoi(y);
        conversion(a,s);
    }
    if(flag==-1)
    {
        y[0]=1;
        if(e[1]!=e[0])
        {
            y[1]=0;
        }
        int k=1;
        for(int l=0;l<s;l++)
        {
            for(int u=1;u<s;u++)
           {
               if(e[l]==e[u])
               {
                   y[u]==y[l];
               }

           }
           if(l>1)
           {
               y[l]=++k;
           }
        }
        a=atoi(y);
        conversion(a,s);
    }


}
int main()
{
    int t,i;
    char a[11][100];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",a[i]);
        printf("case #%d:\n",i);
        shenmixinxi(a[i]);
        if(i<t-1)
            printf("\n");
    }

}
