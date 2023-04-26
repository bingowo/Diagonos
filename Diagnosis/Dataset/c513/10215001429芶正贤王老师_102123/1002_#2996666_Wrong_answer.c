#include<stdio.h>
#include<string.h>

int main()
{
    int T;
    scanf("%d",&T);          //题目数
    getchar();
    int index = 0;
    for(;index < T;index++)  //进入一组数据
    {
        char array[60];
        int digit[60];
        digit[0] = 1;
        scanf("%s",array);
        printf("case #%d:\n",index);
        int i,copy = 0,scale = strlen(array);   
        //copy重复出现次数，scale进制
        long long int sum = 0;
        int sign;
        for(i=1;i<strlen(array);i++)     //判断第一个0出现的位置
        {
            if(array[i] != array[0])
                {
                    sign = i;
                    break;
                }  
           
        }
        
        for(i=0;i<strlen(array);i++)       
                     //判断重复出现的字符数，确定进制 
        {
            for(int j=i+1;j<strlen(array);j++)
            {
                if(array[j] == array[i])
                {
                    scale--;
                }  
            } 
        }
         digit[sign] = 0;
       
        for(i=0;i<strlen(array);i++)     //读入字符,赋值
        {
            for(int j = i+1;j<strlen(array);j++)
            {
                 if(array[j] == array[i])
                 {
                     copy++;
                     digit[j] = digit[i];
                 }
                 else 
                 {
                     digit[i] = i - copy;
                     break;
                 }               
            }    
        }
        for(i=0;i<strlen(array);i++)
        {
            sum = sum*scale + digit[i];
        }
        printf("%lld\n",sum);   
    }
    return 0;
}