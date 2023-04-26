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
        gets(array);
        printf("case #%d:\n",index);
        int i,copy = 0,scale = strlen(array);
        long long int sum = 0;
        for(i=0;i<strlen(array);i++)     //读入字符
        {
            for(int j=0;j<i;j++)
            {
                if(array[i] == array[j])
                {
                    digit[i] = digit[j];
                    copy++;
                    scale--;
                    break;
                }
                else if(array[1] != array[0])
                {
                    digit[1] = 0;
                    break;
                }
                else 
                {
                    digit[i] = i - copy; 
                    break;
                }        
            }
            sum = sum*scale + digit[i];
        }
        printf("%d\n",sum);   
    }
}