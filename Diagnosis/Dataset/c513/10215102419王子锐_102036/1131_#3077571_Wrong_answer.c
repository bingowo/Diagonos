#include<stdio.h>
int main()
{
    long long int A,B,C,sign=1;
    int ternary[100]={0},cnt=0,point=0;
    scanf("%lld%lld",&A,&B);
    if(A<0) {sign=-1;A=-A;}
    
    C=A%B;A=A/B;
    
    while(A)//整数部分转换为普通三进制,注意最低位在前面
    {
        ternary[++cnt]=A%3;
        A=A/3;
    }
    
    for(int i=1,j=cnt;i<j;i++,j--)//调整整数部分存储，从高位到为低位
    {
        int temp=ternary[i];ternary[i]=ternary[j];ternary[j]=temp;
    }
    
    point=cnt+1;//小数点位置
    
    while(C)//小数部分转为普通三进制
    {
        ternary[++cnt]=C*3/B;
        C=C*3%B;
    }
    int carry=0;
    for(int i=cnt;i>0;i--)//按三进制规则加1操作
    {
        int t=ternary[i]+1+carry;
        ternary[i]=t%3;
        carry=t/3;
    }
    if(carry) ternary[0]=carry;//最高位的进位
    
    for(int i=cnt;i>0;i--) //与全1序列按位独立相减
    {
        ternary[i]=(ternary[i]-1+3)%3;
        if(sign==1)//A>=0
        {
            if(ternary[0]) printf("%d",ternary[0]);
            else if(point==1) printf("%d",0);//整数部分为0
            for(int i=1;i<=cnt;i++)
            {
                if(i==point) printf(".");
                printf("%d",ternary[i]);
            }
            printf("\n");
        }
        else//A<0
        {
            if(ternary[0]) printf("%d",(3-ternary[0])%3);
            else if(point==1) printf("%d",0);
            for(int i=1;i<=cnt;i++)
            {
                if(i==point) printf(".");
                printf("%d",(3-ternary[i])%3); 
            }
            printf("\n");
        }
        return 0;
    }
}

