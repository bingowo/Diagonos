#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int i=0;
    long long ansA=0;
    long long ansB=0, ansC=1;

    int N=100;
    char s[N];
    scanf("%s",s);

    for(;i<strlen(s);i++){         //整数部分
        if(s[i]=='.') break;
        ansA = ansA *3;              //右移一位，前面的数的进制位乘3
        if (s[i]=='1') ansA += 1;
        if (s[i]=='2') ansA -= 1;
    }
    i++;
    for (;i<strlen(s);i++) {                 //小数部分
        ansB =ansB * 3;                      //分子
        if (s[i]=='2') ansB -= 1;
        if (s[i]=='1') ansB += 1;
        ansC = ansC * 3;                      //分母
      }

      if(ansA>0 && ansB<0){
        ansA--;
        ansB=ansB+ansC;
      }
       if(ansA<0 && ansB>0){
        ansA++;
        ansB=ansC-ansB;
        if(ansA==0) ansB=-ansB;
      }
      long long e=GCD(abs(ansB),abs(ansC));
      //十进制分数计算其分子和分母的最大公约数，化简。

     if (ansB==0) printf("%lld\n",ansA);
     else{
            if (ansA!=0) printf("%lld ",ansA);
         printf("%lld %lld\n",ansB/e,ansC/e); }


}


int GCD(int m,int n)

{  int t,r;
    if(m<n)
    {
        t=m;
        m=n;
        n=t;
    }


    r=m%n;
    if(r==0)
        {return n;}
    else
    {
        GCD(n,r);          //递归 看高代
    }

}