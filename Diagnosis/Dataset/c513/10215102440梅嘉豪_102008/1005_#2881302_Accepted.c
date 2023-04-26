#include <stdio.h>
#include <string.h>
int main()
{
    char octal[100],decimal[200];
    int T,len,number,digit,j,temp;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%s",octal);
        len=strlen(octal)-1;
        number=0;//上一循环所得decimal数组的长度
        for(;len!=1;len--)//倒序遍历octal数组，到小数点停止
        {
            digit=octal[len]-'0';//取出octal数组中的某个数，在本次循环后续digit作余数
            j=0;//用于decimal数组定位
            while(digit||j<number)
            {
                if(j<number)    temp=digit*10+decimal[j]-'0';//temp用于存储被除数
                else    temp=digit*10;
                decimal[j++]=temp/8+'0';//更新decimal
                digit=temp%8;
            }
            number=j;//革命·更新decimal数组的长度
        }
        decimal[j]='\0';
        printf("case #%d:\n0.%s\n",i,decimal);
    }
}
