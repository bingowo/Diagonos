#include<stdio.h>
#include<string.h>

int main()
{
    char array[500];
    scanf("%s",array);
    int l = strlen(array);         //l为数组长度
    printf("0001");
    int index = l / 3;
    int left = l - 3*index;
    
    for(int i=0;i<index;i++)
    {
        long long int sum;
        sum = (array[3*i]-'0')*100 +(array[3*i+1]-'0')*10 +(array[3*i+2]-'0');
        int ans[10];
        for(int j=0;j<10;j++)
        {
            ans[9-j] = sum % 2;
            sum /= 2;
        }
        for(int j=0;j<10;j++)
            printf("%d",ans[j]);
    }
        
    	if(left == 1)              //末尾一位数字，转4位
        {
            int sum;
        	sum = array[l-1]-'0';
       		int ans[4];
        	for(int j=0;j<4;j++)
        	{
            	ans[4-j] = sum % 2;
            	sum /= 2;
       		}
        	for(int j=0;j<4;j++)
           		printf("%d",ans[j]);
        }
    
   		if(left == 2)              //末尾2位数字，转7位
        {
            int sum;
       		sum = array[l-1]-'0' + (array[l-2] - '0')*10;
        	int ans[7];
        	for(int j=0;j<7;j++)
        	{
            	ans[7-j] = sum % 2;
            	sum /= 2;
        	}
        	for(int j=0;j<7;j++)
            	printf("%d",ans[j]);
        }   
    }
		
		int ans[10];
        for(int j=0;j<10;j++)
        {
            ans[9-j] = l % 2;
            l /= 2;
        }
        for(int j=0;j<10;j++)
            printf("%d",ans[j]);
    }
	return 0;
}

    
