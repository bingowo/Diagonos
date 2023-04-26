#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T;
char s[10005];
int solve(int l,int r,int sta)
{
    //printf("%d %d\n",l,r);
    if(l>=r)
        return 1;
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=l;i<=r;i++)
    {
        if(s[i]=='{')
        {
            if(sta==1||sta==2)
                return 0;
        }
        else if(s[i]=='[')
        {
            if(sta==2||sta==3)
                return 0;
        }
        else if(s[i]=='(')
        {
            if(sta==3||sta==1)
                return 0;
        }
        for(int j=i;j<=r;j++)
        {
            if(s[j]=='{')
                cnt1++;
            if(s[j]=='[')
                cnt2++;
            if(s[j]=='(')
                cnt3++;
            if(s[j]=='}')
                cnt1--;
            if(s[j]==']')
                cnt2--;
            if(s[j]==')')
                cnt3--;
            if(cnt1<0||cnt2<0||cnt3<0)
                return 0; 
            if(cnt1==0&&cnt2==0&&cnt3==0)
            {
                int flg=1;
                if(s[i]=='{')
                    flg&=solve(i+1,j-1,1);
                else if(s[i]=='[')
                    flg&=solve(i+1,j-1,2);
                else
                    flg&=solve(i+1,j-1,3);
                i=j;
                if(flg==0)
                    return 0;
                break;
            }
            if(j==r)
                return 0;
        }
    }
    return 1;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1);
        int l=strlen(s+1);
        if(solve(1,l,-1)==0)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}