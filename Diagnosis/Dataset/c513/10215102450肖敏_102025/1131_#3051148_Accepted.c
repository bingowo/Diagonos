#include <stdio.h>

int main() {
    long long A,B,C,D,sign=1;
    int ternary[100]={0},cnt=0,point=0;
    scanf("%lld %lld",&A,&B);
    if(A<0)
    {
        sign=-1;
        A=-A;
    }
    
    C=A%B,D=A/B;//分解成整数部分和小数部分
    
    while(D)//将整数部分化成普通三进制
    {
        ternary[++cnt]=D%3;
        D/=3;
    }
    //调整存储，从高位到低位
    for(int i=1,j=cnt;i<j;i++,j--)
    {
        int temp=ternary[i];
        ternary[i]=ternary[j];
        ternary[j]=temp;
    }
    point=cnt+1;//小数点
    //小数部分化成普通三进制
    while(C)
    {
        ternary[++cnt]=C*3/B;
        C=C*3%B;
    }
    
    int carry=0;
    //全加1，有进位
    for(int i=cnt;i>0;i--)
    {
        int temp=ternary[i]+1+carry;
        ternary[i]=temp%3;
        carry=temp/3;
    }
    if(carry) {
        ternary[0] = carry;//最高位的进位
    }   
    // 全减1，不进位
    for(int i=cnt;i>0;i--)
    {
        ternary[i]=(ternary[i]-1+3)%3;
    }
    
    if(sign==1)//A>0
    {
        if(ternary[0])//最高位不为0
            printf("%d",ternary[0]);
        else if(point==1)//整数部分为0
            printf("0");
        for(int i=1;i<=cnt;i++)
        {
            if(i==point)
                printf(".");
            printf("%d",ternary[i]);
        }
        printf("\n");
    }
    else//A<0
    {
        if(ternary[0])//最高位不为0,输出
            printf("%d",(3-ternary[0])%3);
        else if(point==1)//整数部分为0，输出0
            printf("0");
        for(int i=1;i<=cnt;i++)
        {
            if(i==point)
                printf(".");
            printf("%d",(3-ternary[i])%3);
        }
        printf("\n");
    }
    return 0;
}
