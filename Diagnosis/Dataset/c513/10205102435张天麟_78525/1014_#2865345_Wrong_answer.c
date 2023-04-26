#include<stdio.h>
#include<string.h>
int main()
{
    int A,B,x,z;
    int zs[30],xs[30];
    scanf("%d %d",&A,&B);
    int k=0,i=0;
    z=A/B;
    x=A%B;
    while(B!=1)
    {
        B=B/3;
        xs[k]=x%3;
        x=x/3;
        k++;
    }
    while(z!=0)
    {
        zs[i]=z%3;
        z=z/3;
        i++;
    }
    int jin=0,j;
    for(j=0;j<k;j++)
    {
        xs[j]+=1+jin;
        jin=xs[j]/3;
        xs[j]%=3;
    }
    for(j=0;j<i;j++)
    {
        zs[j]+=1+jin;
        jin=zs[j]/3;
        zs[j]%=3;
    }
    if(jin!=0)
    {
        zs[i]=jin;
        i++;
    }
    for(j=0;j<k;j++)
    {
        xs[j]--;
        xs[j]%=3;
    }
    for(j=0;j<i;j++)
    {
        zs[j]--;
        zs[j]%=3;
    }
    if(z==0&&x==0)
    {
        printf("0");
    }
    else if(z==0&&x!=0)
    {
        printf("0.");
        for(j=k-1;j>=0;j--)
        {
            printf("%d",xs[j]);
        }
    }
    else if(x==0&&z!=0)
    {
        for(j=i-1;j>=0;j--)
        {
            printf("%d",zs[j]);
        }
    }
    else
    {
        for(j=i-1;j>=0;j--)
        {
            printf("%d",zs[j]);
        }
        printf(".");
        for(j=k-1;j>=0;j--)
        {
            printf("%d",xs[j]);
        }
    }
    return 0;
}