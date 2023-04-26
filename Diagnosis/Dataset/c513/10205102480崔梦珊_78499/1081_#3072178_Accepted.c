#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        int ans[101]={0};
        int a,n;
        int len=1;
        scanf("%d %d",&a,&n);
        ans[100]=a;
        //printf("%d\n\n",ans[100]);
        if(n==0)
        {
            printf("case #%d:\n",i);
            printf("1\n");
            continue;
        }
        else
        {
            for(int m=0;m<n-1;m++)
            {/////////////////////////////////////
                int woc=0;
                for(int i=100;i>=0;i--)
                {
                    int temp=ans[i]*a;
                    ans[i]=woc+temp;
                    ans[i]=ans[i]%10;
                    if((temp+woc)>=10)
                    {
                        woc=(temp+woc)/10;
                    }
                    else
                    {
                        woc=0;
                    }
                    /*for(int p=95;p<=100;p++)
                    {
                        printf("%d",ans[p]);
                    }*/
                    //printf("\n");
                }
                //if(ans[100-len]>0) len++;
            }
        }
        printf("case #%d:\n",i);
        int flag=0;
        for(int k=0;k<=100;k++)
        {
            if(flag==0&&ans[k]==0) continue;
            if(flag==0&&ans[k]!=0)
            {
                printf("%d",ans[k]);
                flag=1;
                continue;
            }
            if(flag==1)
            {
                printf("%d",ans[k]);
            }
        }
        printf("\n");
    }
}
