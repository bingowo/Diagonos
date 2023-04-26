#include<stdio.h>
#include<string.h>
#include<math.h>
int compare(int* a1,int* a2,int len1,int len2)
{
    if(len1>len2)
    {
        return 1;
    }
    if(len1<len2)
    {
        return -1;
    }
    else
    {
        for(int i=200-len1;i<200;i++)
        {
            if(a1[i]>a2[i]) return 1;
            if(a1[i]<a2[i]) return -1;
            else continue;
        }
    }
    return 0;
}
void trans(char* s,int* a,int flag)
{
    int len=strlen(s)-flag;
    if(flag==0)
    {
        for(int i=199;i>=200-len;i--)
        {
            a[i]=s[len-199+i-1]-'0';
        }
    }
    else
    {
        for(int i=199;i>=200-len;i--)
        {
            a[i]=s[len-199+i]-'0';
        }
    }
}

void fadd(int* a1,int* a2,int flag1,int flag2,int len1,int len2,int* ans)
{
    if(flag1==flag2)//同符号
    {
        ans[0]=flag1;
        int len=len1>len2? len1:len2;
        for(int i=199;i>=200-len;i--)
        {
            int temp=a1[i]+a2[i];
            if(temp>=10)
            {
                ans[i]=ans[i]+(temp%10);
                ans[i-1]++;
            }
            else
            {
                ans[i]=ans[i]+temp;
            }
        }
    }
    if(flag1==0&&flag2==1)//正数加负数
    {
        if(compare(a1,a2,len1,len2)==1)
        {
            ans[0]=0;
            for(int i=199;i>=200-len1;i--)
            {
                int temp=a1[i]-a2[i];
                if(temp<0)
                {
                    ans[i]=ans[i]+(10+temp);
                    a1[i-1]--;
                }
                else
                {
                    ans[i]=ans[i]+temp;
                }
            }
            return ;
        }
        if(compare(a1,a2,len1,len2)==-1)
        {
            fadd(a2,a1,0,1,len2,len1,ans);
            ans[0]=1;
        }
    }
    if(flag1==1&&flag2==0)//负数加正数
    {
        if(compare(a1,a2,len1,len2)==1)
        {
            fadd(a1,a2,0,1,len1,len2,ans);
            ans[0]=1;
        }
        if(compare(a1,a2,len1,len2)==-1)
        {
            fadd(a2,a1,0,1,len2,len1,ans);
            ans[0]=0;
        }
    }
}


int main()
{
    char s1[200];
    char s2[200];
    scanf("%s %s",s1,s2);
    int flag1=0,flag2=0;
    if(s1[0]=='-') flag1=1;
    if(s2[0]=='-') flag2=1;
    int a1[200]={0};
    int a2[200]={0};
    int len1=strlen(s1)-flag1;
    int len2=strlen(s2)-flag2;
    trans(s1,a1,flag1);
    trans(s2,a2,flag2);
    /*for(int i=200-len1;i<200;i++)
    {
        printf("%d",a1[i]);
    }
    printf("\n");
    for(int i=200-len2;i<200;i++)
    {
        printf("%d",a2[i]);
    }
    printf("\n");
    printf("%d %d\n",a1[198],a2[198]);
    printf("%d %d\n",a1[199],a2[199]);
    printf("\n\n\n");
    printf("%d\n",compare(a1,a2,len1,len2));*/
    int ans[200]={0};
    fadd(a1,a2,flag1,flag2,len1,len2,ans);
    int cnt=0;
    if(ans[0]==0)
    {
        for(int i=0;i<200;i++)
        {
            if(cnt==0&&ans[i]==0) continue;
            if(cnt==0&&ans[i]!=0)
            {
                cnt=1;
                printf("%d ",ans[i]);
            }
            else
            {
                printf("%d ",ans[i]);
            }
        }
    }
    if(ans[0]==1)
    {
        printf("-");
        for(int i=1;i<200;i++)
        {
            if(cnt==0&&ans[i]==0) continue;
            if(cnt==0&&ans[i]!=0)
            {
                cnt=1;
                printf("%d",ans[i]);
            }
            else
            {
                printf("%d",ans[i]);
            }
        }
    }


}
