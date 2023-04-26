#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        int arr[9]={0},cnt=0;
        printf("case #%d:\n",i);
        for (int j=8;j>=0;j--)
        {
            scanf("%d",&arr[j]);
            if (arr[j]==0)
                cnt++;
        }
        int m=8,start;
        for (m=8;m>=0 && arr[m]==0;m--);
            start=m;
        for (int j=8;j>=0;j--)
        {
            if (arr[j]!=0 && j>1)
            {
                if (arr[j]==-1)
                    printf("-x^%d",j);
                else if (arr[j]==1)
                {
                    if (j==start)
                        printf("x^%d",j);
                    else
                        printf("+x^%d",j);
                }
                else
                {
                    if (j==start)
                        printf("%dx^%d",arr[j],j);
                    else
                    {
                        if (arr[j]>0)
                             printf("+%dx^%d",arr[j],j);
                        else
                            printf("%dx^%d",arr[j],j);
                    }
                }
            }
            else if (arr[j]!=0 && j==1)
            {
                if (arr[j]==-1)
                    printf("-x");
                else if (arr[j]==1)
                {
                    if (j==start)
                        printf("x");
                    else
                        printf("+x");
                }
                else
                {
                    if (arr[j]>0)
                    {
                        if (j==start)
                            printf("%dx",arr[j]);
                        else
                            printf("+%dx",arr[j]);
                    }
                    else
                        printf("%dx",arr[j]);
                }
            }
            else if (arr[j]!=0 && j==0)
            {
                if (arr[j]>0)
                {
                    if (j==start)
                        printf("%d");
                    else
                        printf("+%d");
                }
                else
                    printf("%d",arr[j]);
            }

        }
        if (cnt==9)
            printf("0");
        printf("\n");



    }
    return 0;
}
