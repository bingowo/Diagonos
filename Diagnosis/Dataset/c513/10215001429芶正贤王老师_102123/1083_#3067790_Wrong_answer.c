#include<stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        printf("case #%d:\n",i);
        unsigned long long int a=0,b=0;
        
        for(int j=1;j<n+1;j++)
        {
            if(j/2 > 0)//能被2除
            {
                int temp=j;
                while(temp%2 == 0)//如果是2的倍数
                {
                    a++;
                    temp = temp/2;
                    if(temp%2 != 0)
                        break;
                }
                    
            }
            if(j/5 > 0)//能被5除
            {
                int tmpt=j;
                while(tmpt%5 == 0)//如果是2的倍数
                {
                    b++;
                    tmpt = tmpt/5;
                    if(tmpt%5 != 0)
                        break;
                }
                    
            }
            int num;
            if(a>0 && b>0)
            {
                if(a>b)
                    num=b;
                else
                    num=a;
            }
            else
            {
                num=0;
            }
            printf("%d\n",num);
            
            
        }
        return 0;
        
        
    }
    
    
}


