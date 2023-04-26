#include<stdio.h>
int main()
{
    int T; //输入正整数T，为测试组数
    scanf("%d",&T); //测试组数
    for(int i=0;i<T;i++)
    {
        int N,R; //十进制数N，转换为R进制数
        scanf("%d%d",&N,&R);
        char temp[100]; //存放转换后数据

        if(N<0) 
        {
            printf("-");
            N=-N;
        }          

        int j=0;
        while (N!=0)
        {
            temp[j]=N%R;  //存放余数
            N=N/R;  //X存放除后结果
            j++;
        }
        j--;

        if(R<=10)
        {            
            for(j;j>=0;j--)   printf("%d",temp[j]);
        }

        else
        {
            for(j;j>=0;j--)
            {
                if(temp[j]<10) printf("%c",temp[j]+48);
                else printf("%c",temp[j]+55);
            }            
        }
        printf("\n");

    }
    return 0;
}