#include<stdio.h>
int main()
{
    int decimal_num,base_num,quotient_num;
    scanf("%d %d",&decimal_num,&base_num);
    int remainders[32],i=0;
    do{
        quotient_num=decimal_num/base_num;
        if(decimal_num%base_num<0)
        {
            quotient_num++;
            remainders[i++]=decimal_num-quotient*base_num;
        }
        else remainders[i++]=decimal_num%base_num;
    }while(quotient!=0);
    i--;
    for(i=i;i>=-;i--)
    {
        if(remainders[i]>10) printf("%c",remainders[i]+55);
        else printf("%d",remainders[i]);
    }
    return 0;
}