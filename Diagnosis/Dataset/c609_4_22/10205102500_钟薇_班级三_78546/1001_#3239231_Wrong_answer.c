#include<stdio.h>
int main()
{
    int T; //输入正整数T，为测试组数
    scanf("%d",&T); //测试组数
    for(int i=0;i<T;i++)
    {
        int N,R; //十进制数N，转换为R进制数
        int X,x;  //临时存放数值,余数
        scanf("%d%d",&N,&R);
        char temp[100]; //存放转换后数据
        if(N<0) X=-N;  
        else X=N;
        int j=0;
        while (X!=0)
        {
            temp[j]=X%R;  //存放余数
            X=X/R;  //X存放除后结果
            j++;
        }
        j--;
        if(N<0) printf("-");
        for(j;j>=0;j--)   printf("%d",temp[j]);
        printf("\n");
    }
    return 0;
}