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
    int temp = l;
    
    	int Ans[10];
        for(int j=0;j<10;j++)
        {
            Ans[9-j] = temp % 2;
            temp /= 2;
        }
        for(int j=0;j<10;j++)
            printf("%d",Ans[j]);
    
    for(int i=0;i<index;i++)
    {
        if(l < 3)
            break;
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
            int value;
        	value = array[l-1]-'0';
       		if(value == 0)
                printf("0000");
            else
                printf("0001");
        }
    
   		if(left == 2)              //末尾2位数字，转7位
        {
            int sum;
       		sum = (array[l-1]-'0') + (array[l-2] - '0')*10;
        	int ans[7];
        	for(int j=0;j<7;j++)
        	{
            	ans[6-j] = sum % 2;
            	sum /= 2;
        	}
        	for(int j=0;j<7;j++)
            	printf("%d",ans[j]);
        }   
    
		return 0;
}

    
