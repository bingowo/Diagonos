#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,d;
    char s[100]={0};
    void dectoR(int n,int m,char x[]) /*将十进制数转化为R进制*/
    {
        char y[36]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};/*对应0~36*/
        char p;
        int i=0,z=0,t=0;
        if (n<0)
        {
            x[0]='-';
            i++;
            n=-n;
            t=1;/*t=1标记该数为负数*/
        }
        while(n)
        {
            z=n%m;/*求商取余法*/
            n=n/m;
            x[i]=y[z];
            i++;
        }
        i--;/*上一行代码中会让i比实际位数多1*/
        if(t)/*得到的字符串需倒置后才是正确的R进制表示*/
        {
            for(int k=1;k<i;k++,i--)/*输入的值为负数时的情况,第一位为符号-故不需倒置*/
            {
                p=x[k];
                x[k]=x[i];
                x[i]=p;
            }
        }
        else
        {
            for(int k=0;k<i;k++,i--)
            {
                p=x[i];
                x[k]=x[i];
                x[i]=p;
            }
        }
    }
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<100;j++)
        {
            s[j]=0;
        }
        scanf("%d %d",&b,&c);
        dectoR(b,c,s);
        printf("%s\n",s);
    }
    return 0;
}
