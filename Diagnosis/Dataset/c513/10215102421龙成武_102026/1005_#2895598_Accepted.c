#include <stdio.h>
#include <string.h>
#define MAXLEN 1010
char str1[MAXLEN];

void myPrint(char *res)
{
    static int tim=0;
    printf("case #%d:\n", tim);
    printf("0.");
    printf("%s\n",res);
    tim++;
}

int main()
{
    int T,i,j,b=8,len,digit,numbers,temp;
    scanf("%d",&T);
    char str1[55],result[165];
    int a[55],c[165];
    for(i=0;i<T;i++)
    {
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        scanf("%s",str1);       //第0个元素是0，第一个元素是.
        len=strlen(str1)-1;    //len1指向str最后一个非\0元素
        numbers=0;              //记录当前十进制小数位数
        temp=0;                 //储存每一次计算中的被除数
        for(;len!=1;len--)      //核心计算
        {
            j=0;
            digit=str1[len]-'0';      //从后往前的每一位
            do
            {
                if(j<numbers)
                {
                    temp=digit*10+result[j]-'0';
                }
                else
                {
                    temp=digit*10;
                }
                result[j++]=temp/b+'0'; //j++
                digit=temp%b;
            }while(digit!=0||j<numbers);
            numbers=j;
        }
        result[numbers]=0;
        myPrint(result);
    }

    return 0;
}
