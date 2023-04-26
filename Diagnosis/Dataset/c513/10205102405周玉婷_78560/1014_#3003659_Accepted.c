#include <stdio.h>
#include <string.h>
/*思路：1.将A B化为普通三进制：首先得到整数与分数部分，将分子分母化到最简，HEXTOTRI分别对整数部分及分数化为三进制，以字符串的形式保存；
2.三进制各位加1：循环并保持进制3.各位减1：不用真的相减，1——0，2——1，0——-1——2  */
int GCD(int a, int b)
{
    if(a%b==0) return b;
    else return GCD(b,a%b);
}

void HEXTOTRI(int intteger,int num,char* tri, int length)
{
    int index=98;
    if(intteger==0) tri[index--]='0';
    else 
    {
        while(intteger!=0)
        {
            tri[index--]=intteger%3+'0';
            intteger/=3;
        }
    }
    memmove(tri,tri+index+1,99-index);
    int len=strlen(tri);
    index=98;tri[99]=0;
    if(length!=0)
    {
    while(98-index < length)
    {
        tri[index--]=num%3+'0';
        num/=3;
    }
    memmove(tri+len,tri+index+1,99-index);
    }
}


void TRITOBALANCE(char* balance,char* tri,int length)
{
    int index=98;
    int len=strlen(tri);
    int i=0;balance[index]=0;
    for( i=len-1; i>=0 ;i-- )
    {
        balance[index]=tri[i]+1+balance[index];
        if(balance[index]>'2')  {balance[index]-=3; balance[index-1]=1;}
        index--;
    }
    if(balance[index]==1) 
    {balance[index]+=(1+'0');
    memmove(balance,balance+index,100-index);}
    else memmove(balance,balance+index+1,99-index);
    int len_=strlen(balance);
    for(int i=len_-1; i>=0;i--)
    {
        int temp=balance[i];
        if(temp=='1') balance[i]='0';
        if(temp=='0') balance[i]='2';
        if(temp=='2') balance[i]='1';
    }
    if(length!=0)
    {memmove(balance+(len_-length)+1,balance+(len_-length),length+1);
    balance[len_-length]='.';}
}

int main()
{
    int num=0,den=0,intteger=0,gcd=0;
    scanf("%d%d",&num,&den);
    intteger=num/den;//得整数部分
    num=num%den;//得分子部分
    if(num!=0)//分子不为0，分数化为最简
    {gcd=GCD(num,den);
    num/=gcd;den/=gcd;}
    else den=1;//分子为0，即分母为0，记den=0,经下列过程即得小数点后length=0
    int length=0;
    while(den%3==0)
    {
        den/=3;
        length++;
    }

    char tri[100]={0},balance[100]={0};
    tri[99]=0;
    if(intteger==0&&num==0)  printf("0");//全为0
    else //整数或小数部位0
    {
      HEXTOTRI(intteger,num,tri,length);
      TRITOBALANCE(balance,tri,length);
      printf("%s",balance);
    }
    return 0;
}
