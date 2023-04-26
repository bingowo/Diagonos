#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mul(int a[],int j,int x)
{
    int i,add=0,mult;
    for(i=j-1;i>=0;i--)
    {
        mult=a[i]*x+add;
        add=mult/10;
        a[i]=mult%10;
    }
    if(add!=0)
    {
        for(i=j-1;i>=0;i--)
        {
            a[i+1]=a[i];
        }
        a[0]=add;
        j=j+1;
    }
    return j;
}
int main()
{
    int k,T,hu,sum,a2,a1,a[100]={0},b,j;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        j=0;
        scanf("%d %d",&a1,&b);
        a2=a1;
        while(a1!=0)
        {
            a[j]=a1%10;
            a1=a1/10;
            j++;
        }
        for(k=0;k<j/2;k++)
        {
            hu=a[k];
            a[k]=a[j-k-1];
            a[j-k-1]=hu;
        }
        printf("case #%d:\n",i);
        if(b==0) printf("1\n");
        else
        {
            for(k=1;k<b;k++)
            {
                j=mul(a,j,a2);
            }
            for(k=0;k<j;k++) printf("%d",a[k]);
            printf("\n");
        }
    }
    return 0;
}
