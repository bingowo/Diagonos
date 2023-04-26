#include<stdio.h>
#include<stdlib.h>
int main()
{
    char AD;
    scanf("%c",&AD);
    int num[100];
    int i=0;

    ///C实现输入任意多个整数///
    ///BEGIN///
    char y;
    do
    {
        scanf("%d",&num[i]);
        i++;
    } while (y=getchar()!='\n');//判断是否输入回车
    ///END///

    if(AD=='A')
    {
        int j;
        int flag=0;
        while (flag==0)
        {
            flag=1;
            for(j=0;j<i-1;j++)
            {
                if(num[j]>num[j+1])
                {
                    int temp=num[j];
                    num[j]=num[j+1];
                    num[j+1]=temp;
                    flag=0;
                }
            }
        }
        for(j=0;j<i-1;j++)
            if(num[j]<num[j+1]) 
                printf("%d ",num[j]);
        printf("%d",num[i-1]);        
    }
    else
    {
        int j;
        int flag=0;
        while (flag==0)
        {
            flag=1;
            for(j=0;j<i-1;j++)
            {
                if(num[j]<num[j+1])
                {
                    int temp=num[j];
                    num[j]=num[j+1];
                    num[j+1]=temp;
                    flag=0;
                }
            }
        }
        for(j=0;j<i-1;j++)
            if(num[j]>num[j+1]) 
                printf("%d ",num[j]);
        printf("%d",num[i-1]);      
    }    
    return 0;
}