#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    long long up,down;
    scanf("%lld%lld",&up,&down);
    if(up==0){printf("0");return 0;}
    int ri[200];
    int rl[200]={0};
    int flag =1;//判断正负；
    if(up<0){flag =0;up *=(-1);}
    long long integer = up/down;
    long long little = up%down;
    int cnt = 0;
    int d = down;
    do{
        d/=3;
        cnt++;
    }while(d!=0);

    //处理整数范围,左边为低位
    int cnti = 0;
    do
    {
        ri[cnti++] = integer %3;
        integer/=3;
    }while(integer !=0);
    //小数范围左边为低位
    int cntl =0;
    do{
        rl[cnt-1] = little%3;
        if(cntl==0&&little%3!=0)cntl = cnt;
        cnt--;
        little/=3;
    }while(little!=0);

    int carry =0;
    for(int k2 =0 ;k2<cntl;k2++)
    {
        rl[k2] = rl[k2]+1+carry;
        if(rl[k2]>=3){rl[k2]-=3;carry =1;}
        else carry = 0;
    }
    for(int k1 =0 ;k1<cnti;k1++)
    {
        ri[k1] = ri[k1]+1+carry;
        if(ri[k1]>=3){ri[k1] -= 3;carry =1;}
        else carry = 0;
    }
    int mid = cnti;
    if(carry){ri[cnti] = 1;cnti++;}

    for(int g1 =0;g1<mid;g1++)ri[g1]-=1;
    for(int g2 =0;g2<cntl;g2++)rl[g2]-=1;

    //输出
    for(int k1 = cnti-1;k1>=0;k1--)
    {
        ri[k1]=(ri[k1]==-1)?2:ri[k1];
    }
     for(int k1 = cntl-1;k1>=0;k1--)
    {
        rl[k1]=(rl[k1]==-1)?2:rl[k1];
    }

    if(!flag)
    {
        for(int p1 = cnti-1;p1>=0;p1--){
            ri[p1] = (3-ri[p1])%3;
    }
    for(int p2 = cntl-1;p2>=0;p2--)
    {
        rl[p2] = (3-rl[p2])%3;
    }
    }

    for(int z1=cnti-1;z1>=0;z1--)
    {
        printf("%d",ri[z1]);
    }
    int j;
    for(j = cntl-1;j>=0;j--){if(rl[j]!=0)break;
    }
    if(j>=0)
    {printf(".");
    for(int z2 = j;z2>=0;z2--)
        printf("%d",rl[z2]);
    }
    return 0;
}
