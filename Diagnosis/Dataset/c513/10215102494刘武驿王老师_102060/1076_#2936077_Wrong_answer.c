#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char w=getchar();
    char s[1000];
    int nums[1000];
    for(int i=0;i<n;i++)
    {
        memset(s,'\0',1000);
        memset(nums,0,1000);
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0;j<len;j++)
        {
            if(s[j]=='{') nums[j]=3;
            if(s[j]=='[') nums[j]=2;
            if(s[j]=='(') nums[j]=1;
            if(s[j]=='}') nums[j]=-3;
            if(s[j]==']') nums[j]=-2;
            if(s[j]==')') nums[j]=-1;
        }
        int flag=0,test=1;
        if(nums[0]<0)
        {
            printf("No\n");
            continue;
        }
        if(nums[len-1]>0)
        {
            printf("No\n");
            continue;
        }
        for(int j=1;j<len;j++)
        {
            if(nums[j]>0&&nums[j]==nums[flag]-1)
            {
                flag=j;
                continue;
            }
            if((nums[j]>0&&nums[j]>=nums[flag])||(nums[j]>0&&nums[j]==nums[flag]-2))
            {
                if(nums[j]==nums[flag]+2)
                {
                    flag=j;
                    continue;
                }
                test=0;
                break;
            }
             if(nums[j]<0&&nums[j]!=-nums[flag])
            {
                test=0;
                break;
            }
            if(nums[j]<0&&nums[j]==-nums[flag])
            {
                nums[flag]=0;
                nums[j]=0;
                while(nums[flag]==0&&flag>=0) flag--;
                if(flag==-1)
                {
                    if(nums[j+1]>=0)
                    {
                        flag=j+1;
                        j++;
                    }
                    else
                    {
                        test=0;
                        break;
                    }
                }
                continue;
            }
        }
        if(test==1) printf("Yes\n");
        else printf("No\n");
    }
}