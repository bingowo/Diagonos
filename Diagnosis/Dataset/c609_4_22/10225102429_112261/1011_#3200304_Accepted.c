#include <stdio.h>
#include <string.h>
long long Sum(char s[])
{
    long long sum = 0,pow = 1;
    for(int i = strlen(s)-1; i>-1; i--)
    {
        if(s[i]=='1') sum+=pow;
        if(s[i]=='2') sum-=pow;
        pow*=3;
    }
    return sum;
}
int main()
{
    long long A,B,C = 1;
    char s[31] = {0},sInt[31] = {0},sDou[31] = {0};
    scanf("%s",s);
    int i = 0, ret = 0;//ret记录是否存在小数点,若存在则i即代表小数点的下标
    for(; i< strlen(s); i++) {
        if(s[i]=='.') {
            ret = 1; i++; break;
        }
    }
    if(!ret) printf("%lld",Sum(s));
    else{
        if(s[0]=='0'){
            for(int j = 2; j< strlen(s); j++)
            {
                sDou[j-2] = s[j];
            }
            for(int j = 0; j< strlen(sDou); j++)
            {
                C*=3;
            }
            printf("%lld %lld", Sum(sDou),C);
        }
        else{
            strncpy(sInt,s,i-1);
            for(int j = i; j< strlen(s); j++) {sDou[j-i] = s[j];}
            //printf("%s\n",sDou);
            for(int j = 0; j< strlen(sDou); j++) {C *= 3;}
            A = Sum(sInt),B = Sum(sDou);
            //printf("%lld %lld %lld ",A,B,C);
            if(A>0)
            {
                if(B<0) {
                    A--;
                  //  printf("B = %lld\n");
                    B = C+B;}
            }
            else
            {
                if(B>0) {A++; B = C-B;}
                else {
                //    printf("B = %lld ",B);
                    B = -B;
                }
            }
            printf("%lld %lld %lld",A,B,C);
        }
    }

    return 0;
}
//C取决于小数点后的长度,有C = 3^(strlen(小数点后部分))
//分开处理整数部分和小数部分,当读入的整数部分第一个为0时,A的部分将不输出
//当读入的第一个数为2时,整体取反(即1~2,2~1,0~0),如此仅需处理正数(即第一个数为1的情况)
//对于整数部分只需按权重相加即可得到A，对于小数部分,如果第一个为2,则小数部分取反求和且A-1，再用C减去即可得B,若第一个为1则A不变,求和即可得B

//当整数部分和小数部分异号时,整数部分向0靠近1，小数部分用C-B
//当同号时,不做处理