#include<stdio.h>
int main()
{
    int T,i,a,b;
    scanf("%d",&T);
    char hex[36]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for(i=1;i<=T;i++){
        scanf("%d%d",&a,&b);
        itob(a,s,b);
        printf("%s\n",s);
        
    }
    return 0;
}
void itob(int a,char s[100],int b)
{
    // TODO: your function definition
    char  hex[36] = { "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
    int m,i=0;
    if(a<0)//n为负数
    {
        m=-a;
        printf("-");
    }
    else
    {
        m=a;
    }
    do
    {
        s[i++] = m% b;
        m = m/b;
    }
    while(m);
    {
        for (--i; i >= 0; i--)
            printf("%c", hex[s[i]]);//逆序输出转换的进制数
    }
    s[i+1]='\0';//数组的结束标志
    return 0;
}
