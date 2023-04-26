#include<stdio.h>

int *f(int m,int n)
{
    int ans[505]={0};
    ans[0]=1;
    for(int i=n+1;i<m+1;i++)//每次×i
    {
        int num=0;
        for(int j=1;j<505;j++)
        {
            ans[j] = ans[j]*i+num;
            
            if(ans[i]>9)
        	{
            	num = ans[i]/10;
            	ans[i] = ans[i]%10;
        	}
        }
    }
    int mark;
    for(int i=504;i>-1;i--)//找第一个不是0的地方
    {
        if(ans[i]!=0)
        {
            mark = i;
            break;
        }
    }
    int s[505]={0};
    for(int i=0;i<mark+1;i++)
        s[i]=ans[mark-i];
    
    int t=m-n;
    for(int i=1;i<t+1;i++)  //每次×i
    {
        int num=0;
        for(int j=0;j<mark+1;j++)//对每一位
        {
            s[j] = s[j]+num*10;
            num = 0;
        	if(s[j]>t)
        	{
                num = s[j]%i;
            	s[j] = s[j]/i;
        	}
        }
    }
    return s;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int m,n;
        scanf("%d %d",&m,&n);
        
        if(n==0 || m==n)
        {
            printf("1\n");
        }
        else
        {
            int ans[505];
        	ans = f(m,n);
        	printf("%s\n",ans);
        }
        
        
    }
    return 0;
}
