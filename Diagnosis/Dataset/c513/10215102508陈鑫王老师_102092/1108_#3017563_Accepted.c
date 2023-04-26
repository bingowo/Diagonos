#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int a[100],b[100];
        int f1,temp,j,flag=0,indexa=0,indexb=1;
        f1=n/m;
        temp=n%m;
        b[0]=temp;
        while(temp)
        {
            temp*=10;
            a[indexa++]=temp/m;
            temp=temp%m;
            b[indexb]=temp;
            for(j=0;j<indexb;j++)
            {
                if(b[j]==b[indexb])
                {
                    flag=1;
                    break;
                }

            }
            if(flag==1)break;
            indexb++;
        }
        printf("case #%d:\n",i);

        printf("%d.",f1);
        if(flag==1)
        {

        for(int l=0;l<indexa;l++)
        {
                printf("%d",a[l]);
        }

        printf("\n");
        printf("%d-%d\n",j+1,indexb);
        }
        else
        {
            for(int l=0;l<indexa;l++)
            {
                printf("%d",a[l]);
            }
            printf("\n");
        }

    }
    return 0;
}