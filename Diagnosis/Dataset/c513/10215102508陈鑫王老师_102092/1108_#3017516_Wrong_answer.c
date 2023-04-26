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
        int f1,temp,j,flag=0,index=0;
        f1=n/m;
        temp=n%m;
        while(temp)
        {
            temp*=10;
            a[index]=temp/m;
            temp=temp%m;
            b[index]=temp;
            for(j=0;j<index;j++)
            {
                if(b[j]==b[index])
                {
                    flag=1;
                    break;
                }

            }
            if(flag==1)break;
            index++;
        }
        printf("case #%d:\n",i);

        printf("%d.",f1);
        if(flag==1)
        {

        for(int l=0;l<=index;l++)
        {
                printf("%d",a[l]);
        }
        printf("\n");
        printf("%d-%d\n",j+2,index+1);
        }
        else
        {
            for(int l=0;l<index;l++)
            {
                printf("%d",a[l]);
            }
            printf("\n");
        }

    }
    return 0;
}
