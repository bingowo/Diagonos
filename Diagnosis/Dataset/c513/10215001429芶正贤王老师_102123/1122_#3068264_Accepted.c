#include<stdio.h>
#include<math.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        long long int n;
        scanf("%lld",&n);
        int s[7];
        int mark;
        for(int j=0;j<7;j++)
        {
            if(n == 0)
            {
                mark = j;
                break;
            }
            s[j]= (int)(n%2333);
            n = n/2333;
            
                
        }
        if(mark == 0)
            printf("0\n");
        else
        {
            for(int j=mark-1;j>0;j--)
        	{
            	printf("%d ",s[j]);
        	}
        	printf("%d\n",s[0]);
        }
        
        
    }
    return 0;
}





