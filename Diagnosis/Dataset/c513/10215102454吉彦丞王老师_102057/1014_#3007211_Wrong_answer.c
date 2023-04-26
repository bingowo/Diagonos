#include<stdio.h>
int zhishu(int n)
{
    int t=0;
    while(n>0)
    {
        t++;
        n=n/3;
    }
    return t;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    int m=a/b;
    int n=a%b;
    if(n!=0&&m!=0)
	{
    	int re1[zhishu(m)];
    	int re2[zhishu(n)];
    	int re[zhishu(m)+zhishu(n)+1];
    	int t1=zhishu(m);
    	int t2=zhishu(n);
    	int cut1=zhishu(m)-1;
    	int cut2=zhishu(n)-1;
    	while(m>0)
    	{
        	re1[cut1]=m%3;
        	m=m/3;
        	cut1--;
    	}
    	while(n>0)
    	{
        	re2[cut2]=n%3;
        	n=n/3;
        	cut2--;
    	}
    	re[0]=0;
    	for(int i=1;i<=t1;i++)
    	{
    	    re[i]=re1[i-1];
    	}
   		for(int i=t1+1;i<=t1+t2;i++)
   		{
    	    re[i]=re2[i-t1-1];
    	}
    	for(int i=t1+t2;i>0;i--)
    	{
    	    re[i]=re[i]+1;
    	    if(re[i]>=3)
    	    {
    	        re[i-1]+=re[i]/3;
    	        re[i]=re[i]%3;
    	    }
    	}
    	for(int i=1;i<t1+t2+1;i++)
    	{
    	    re[i]=re[i]-1;
    	}
    	for(int i=0;i<t1+t2+1;i++)
    	{
    	    if(re[i]==-1)
    	    {
    	        re[i]=2;
    	    }
    	}
    	int num=0;
    	for(int i=t1+t2;i>0;i--)
    	{
    		if(re[i]==0)
    		{
    			num++;
			}
			else
			{
				break;
			}
		}
    	if(re[0]==0)
    	{
    	    for(int i=1;i<t1+1;i++)
    	    {
    	        printf("%d",re[i]);
    	    }
    	    printf(".");
    	    for(int i=t1+1;i<t1+t2+1-num;i++)
    	    {
    	        printf("%d",re[i]);
    	    }
    	}
    	else
    	{
    	    for(int i=0;i<t1+1;i++)
    	    {
    	        printf("%d",re[i]);
    	    }
    	    printf(".");
    	    for(int i=t1+1;i<t1+t2+1-num;i++)
    	    {
    	        printf("%d",re[i]);
    	    }
    	}
	}
	else if(n==0&&m!=0)
	{
		int re1[zhishu(m)];
		int re[zhishu(m)+1];
		int t1=zhishu(m);
		int cut1=zhishu(m)-1;
		while(m>0)
    	{
        	re1[cut1]=m%3;
        	m=m/3;
        	cut1--;
    	}
    	re[0]=0;
    	for(int i=1;i<=t1;i++)
    	{
    	    re[i]=re1[i-1];
    	}
    	for(int i=t1;i>0;i--)
    	{
    	    re[i]=re[i]+1;
    	    if(re[i]>=3)
    	    {
    	        re[i-1]+=re[i]/3;
    	        re[i]=re[i]%3;
    	    }
    	}
    	for(int i=1;i<t1+1;i++)
    	{
    	    re[i]=re[i]-1;
    	}
    	for(int i=0;i<t1+1;i++)
    	{
    	    if(re[i]==-1)
    	    {
    	        re[i]=2;
    	    }
    	}
    	if(re[0]==0)
    	{
    	    for(int i=1;i<t1+1;i++)
    	    {
    	        printf("%d",re[i]);
    	    }
    	}
    	else
    	{
    	    for(int i=0;i<t1+1;i++)
    	    {
    	        printf("%d",re[i]);
    	    }
    	}
	}
	else if(n!=0&&m==0){
		int num=zhishu(b);
		int re1[num-1];
		for(int i=num-2;i>=0;i--)
		{
			re1[i]=a%3;
			a=a/3;
		}
		int re[num];
		re[0]=0;
		for(int i=1;i<num;i++)
    	{
    	    re[i]=re1[i-1];
    	}
    	for(int i=num-1;i>0;i--)
    	{
    	    re[i]=re[i]+1;
    	    if(re[i]>=3)
    	    {
    	        re[i-1]+=re[i]/3;
    	        re[i]=re[i]%3;
    	    }
    	}
    	for(int i=1;i<num;i++)
    	{
    	    re[i]=re[i]-1;
    	}
    	for(int i=0;i<num;i++)
    	{
    	    if(re[i]==-1)
    	    {
    	        re[i]=2;
    	    }
    	}
    	printf("%d",re[0]);
    	printf(".");
    	for(int i=1;i<num;i++)
    	{
    		printf("%d",re[i]);
		}
	}
	else
	{
		printf("0");
	}
    return 0;
}