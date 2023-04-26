#include <stdio.h>
#include <stdlib.h>

unsigned long long gc(unsigned long long x,unsigned long long y)
{
	unsigned long long i=y;
	while(i>1)
	{
		if(x%i==0&&y%i==0) return i;
		i--;//printf("%d\n",i);
	}
	return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        int x,y;
        scanf("%d%d",&x,&y);
        if(y==0) printf("1\n");
        else 
        {
            unsigned long long ans=1;
            unsigned long long chu=1;
            unsigned long long zz=1;
           // unsigned long long uu=1;
            for(int j=y;j>=1;j--)
            {
            	zz=gc(ans,chu);
            	ans/=zz;
            	chu/=zz;
            	zz=gc((x-y+j),j);
            	ans*=((x-y+j)/zz);
				chu*=(j/zz);//printf("%llu %llu\n",ans,chu);
            }
            printf("%llu\n",ans/chu);
        }
        
    }
    return 0;
}