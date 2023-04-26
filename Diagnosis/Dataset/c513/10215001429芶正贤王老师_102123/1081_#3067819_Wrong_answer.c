#include<stdio.h>
//大整数位数超出范围，用数组每一位代表个位等
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int a,n;
        scanf("%d %d",&a,&n);
        int s[105]={0};
        s[0] = 1;
        for(int j=0;j<n;j++)//每一遍×a
        {   
            int num=0;
            //从个位开始读
            for(int r=0;r<100;r++)//对数组中每一位×a  
                						//??判断条件??
            {
                if(s[r] == 0)
                    continue;
                else
                {
                    s[r] = s[r]*a+num;
                	if(s[r] > 9)
                	{
                    	num = (s[r]/10);
                    	s[r] = s[r]%10;
                	}
                
                }
                
            }
            
        }
        
        //长度为mark，从s[mark]开始输出
        int t;
        for(t=99;t>-1;t--)
        {
            if(s[t]!=0)
                break;
        }
        for(int l=t+1;l>-1;l--)
        {
            printf("%d",s[l]);
        }
        printf("\n");
    }
    return 0;
}

