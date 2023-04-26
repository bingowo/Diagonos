#include <stdio.h>
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[61];
        scanf("%s",s);
        int a[128];
        int digit=0,N=0;
        
        for(int i=0;s[i]!='\0';i++)
        {
        	int repeat=0;
        	for(int j=0;j<i;j++)
        	{
        		if(s[i]==s[j]){
        			repeat=1;
        			break;
				}
			}
			if(repeat==0) N++;
		}
		
		a[0]=1;
        for(int y=1;s[y]!='\0';y++)
        {
        	int repeat=0;
        	for(int j=0;j<y;j++)
        	{
        		if(s[y]==s[j]){
        			repeat=1;
					a[y]=a[j];
					break;	
				}
			}
			if(repeat==0)
			{
				a[y]=digit;
				digit = digit? digit+1:2;
			}
        }
        if(N<2) N=2;
        long long result=0;
        for(int y=0;s[y]!='\0';y++)
        {
            result=result*N+a[y];
        }
        printf("case #%d\n",i);
        printf("%lld\n",result);
    }
    return 0;

}