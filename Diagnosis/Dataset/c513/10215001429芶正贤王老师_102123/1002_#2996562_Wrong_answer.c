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
        long long int sum = 0;
        int sign;
        for(i=1;i<strlen(array);i++)     //读入字符
        {
            for(int j=0;j<i;j++)
            {
                if(array[i] == array[j])
                {
                    copy++;
                    scale--;
                }  
                if(array[i] != array[j])
                {
                    sign = i;
                    break;
                }  
            } 
        }
        for(i=1;i<strlen(array);i++)     //读入字符
        {
            digit[sign] = 0;
            for(int j=0;j<i;j++)
            {
                 if(array[i] == array[j])
                     digit[i] = digit[j];
                else
                    digit[i] = i - copy;
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