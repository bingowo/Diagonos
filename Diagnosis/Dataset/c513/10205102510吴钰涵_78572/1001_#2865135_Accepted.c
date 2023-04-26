#include <stdio.h>

void trans1(int num,int R)  //10进制以内
{
    int a[32];
    int i;
    for(i=0;num/R!=0;i++)
    {
        a[i]=num%R;
        num=num/R;
    }
    a[i]=num;  //此时num的R进制数在数组内是倒着存放的
    for(;i>=0;i--)
        printf("%d",a[i]);
    printf("\n");
}

void trans2(int num,int R)  //10进制以外
{
    char arr[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  //因为存在字符，所以使用字符串进行存储表示
    char b[32];
    int i;
    for(i=0;num/R!=0;i++)
    {
        b[i]=arr[num%R];
        num=num/R;
    }
    b[i]=arr[num];
    for(;i>=0;i--)
        printf("%c",b[i]);
    printf("\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int num,R;
        scanf("%d %d",&num,&R);
        if(num<0)   //输入的数为负数时
        {
            num=-num;
            printf("-");
        }
        if(R>=2 && R<=9)   //如果要求进制小于10，不需要字母表示
        {
            trans1(num,R);
        }
        else  //如果要求进制大于10，需要表示字母
        {
            trans2(num,R);
        }
    }
    return 0;
}
