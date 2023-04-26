#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int s[9],res[9];
    for(int j=0; j<t; j++)
    {
    for(int i=0; i<9; i++)//输入
    scanf("%d",&s[i]);

    for(int i=0; i<9; i++)//sum即某一位点的总操作数为偶数，为亮；否则为暗
    {
    int sum=0;
    switch(i)
    {
        case 0:
        sum=s[0]+s[1]+s[3];break;
        case 1:
        sum=s[0]+s[1]+s[2]+s[4];break;
        case 2:
        sum=s[1]+s[2]+s[5];break;
        case 3:
        sum=s[0]+s[3]+s[4]+s[6];break;
        case 4:
        sum=s[1]+s[3]+s[4]+s[5]+s[7];break;
        case 5:
        sum=s[2]+s[4]+s[5]+s[8];break;
        case 6:
        sum=s[3]+s[6]+s[7];break;
        case 7:
        sum=s[4]+s[6]+s[7]+s[8];break;
        case 8:
        sum=s[5]+s[7]+s[8];break;
    }
    if(sum%2 == 0) res[i]=1;
    else res[i]=0;
    }

    
    printf("case #%d:\n",j);
    for(int i=0; i<9; i++)
    printf("%d%c", res[i], (i%3==2)?'\n':' ');
    }
    return 0;
}