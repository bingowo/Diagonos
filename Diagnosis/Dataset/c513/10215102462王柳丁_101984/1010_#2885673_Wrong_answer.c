#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[501];
	char nums[5010];
	int i=0,n=0,num,count;
	char c;
	while((c=getchar())!='\n')
	{
		a[n]=c;
		n++;
	}
	//printf("%s\n%d\n",a,n);
	for(i=0;i<3*(n/3);i+=3)
	{
		num=0;
		num=(a[i]-'0')*100+(a[i+1]-'0')*10+a[i+2]-'0';
		for(count=0;count<10;count++){
			nums[(i/3+1)*10-count-1]='0';
			if((num&(1<<count))==(1<<count))nums[(i/3+1)*10-count-1]='1';
		}
	}
	//printf("%s\n",nums);
	//printf("i=%d",i);
	if(i<n)
	{
		if((n-i)==1)
		{
			num=a[i]-'0';
			for(count=0;count<4;count++)
			{	
				nums[(i/3)*10+4-count-1]='0';
				if((num&(1<<count))==(1<<count))nums[(i/3)*10+4-count-1]='1';
			}
		}
		if((n-i)==2)
		{
			num=(a[i]-'0')*10+(a[i+1]-'0');
			//printf("num=%d\n",num);
			for(count=0;count<7;count++)
			{
				nums[(i/3)*10+7-count-1]='0';
				if((num&(1<<count))==(1<<count))nums[(i/3)*10+7-count-1]='1';
			}
		}
	}
	char nums2[10];
	for(count=0;count<10;count++)
	{
		nums2[9-count]='0';
		if((n&(1<<count))==(1<<count))nums2[9-count]='1';
	}
	nums2[10]='\0';
	printf("0001");
	printf("%s%s",nums2,nums);

	
	return 0;
}