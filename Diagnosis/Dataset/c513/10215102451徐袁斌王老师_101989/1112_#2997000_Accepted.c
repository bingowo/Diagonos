#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
		scanf("%d",&n);
		int ans=0;
		for(int a=0;4*a<=n;a++)
		{
			int x=n;
			x=n-4*a;
			for(int b=0;x-b*3>=0;b++)
			{
				int y=x-b*3;
				for(int c=0;y-c*2>=0;c++)
				{
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
}