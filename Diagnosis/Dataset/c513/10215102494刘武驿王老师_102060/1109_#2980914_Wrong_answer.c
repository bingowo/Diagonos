#include<stdio.h>
int main()
{
    int n,nums[9];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<9;j++) scanf("%d",&nums[j]);
        printf("case #%d:\n",i);
        int test=0;
        for(int j=0;j<9;j++) if(nums[j]!=0) test=1;
        if(test==0)
        {
            printf("0\n");
            continue;
        }
        test=0;
        for(int j=0;j<9;j++)
        {
            if(nums[j]!=0)
            {
                test+=1;
                if((j!=8&&j!=7)&&test!=1)
                {
                    if(nums[j]==1)
                    {
                        printf("+x^%d",8-j);
                        continue;
                    }
                    if(nums[j]==-1)
                    {
                         printf("-x^%d",8-j);
                         continue;
                    }
                    if(nums[j]>0&&j!=0)
                    {
                        printf("+%dx^%d",nums[j],8-j);
                        continue;
                    }
                    printf("%dx^%d",nums[j],8-j);
                }
                else if(j==7&&test!=1)
                {
                    if(nums[j]==1)
                    {
                        printf("+x");
                        continue;
                    }
                    if(nums[j]==-1)
                    {
                         printf("-x");
                         continue;
                    }
                    if(nums[j]>1&&j!=0)
                    {
                        printf("+%dx",nums[j]);
                        continue;
                    }
                    printf("%dx",nums[j]);
                }
                else if(test==1&&j!=8)
                {
                    if(nums[j]==1)
                    {
                        printf("x^%d",8-j);
                        continue;
                    }
                    if(nums[j]==-1)
                    {
                         printf("-x^%d",8-j);
                         continue;
                    }
                    if(nums[j]>0&&j!=0)
                    {
                        printf("%dx^%d",nums[j],8-j);
                        continue;
                    }
                    printf("%dx^%d",nums[j],8-j);
                }
                else if(test==1&&j==8)
                {
                    if(nums[j]==1)
                    {
                        printf("x");
                        continue;
                    }
                    if(nums[j]==-1)
                    {
                         printf("-x");
                         continue;
                    }
                    if(nums[j]>0&&j!=0)
                    {
                        printf("%dx",nums[j]);
                        continue;
                    }
                    printf("%dx",nums[j]);
                }
                else
                {
                    if(nums[j]>0) printf("+%d",nums[j]);
                    if(nums[j]<0) printf("%d",nums[j]);
                }
            }
        }
        printf("\n");
    }
}
