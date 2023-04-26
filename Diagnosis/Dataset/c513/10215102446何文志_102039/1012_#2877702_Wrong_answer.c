#include <stdio.h>
#include <stdlib.h>
#include <string.h>


long long getAB(char* s)
{
    long long* pResList = (long long*)malloc(2*sizeof(long long));
    memset(pResList,0,2*sizeof(long long));
    if(s[0] == 'i'){pResList[1] = 1;return pResList;}
    else if((s[0]=='-')&&(s[1]=='i')){pResList[1] = -1;return pResList;}
    else if(s[0] == '0'){pResList[0] = 0;return pResList;}

    long long flagi = 0;//表示只有一个bi，没有a
    long long flag1 = 1,flag2 = 1;//表示符号正负
    long long n1 = 0,n2 = 0;//表示第一第二个数
    int i = 0;
    if(s[0] == '-'){flag1 = -1;i++;}
    while((s[i] != 0)&&isdigit(s[i]))
    {
        n1 = 10*n1 + s[i]-'0';//获取第一个数
        i++;
    }
    if(s[i] == 'i'){flagi = 1;pResList[1] = n1*flag1;return pResList;}//第一个数后面就是i则直接返回
    if(s[i] == '-'){flag2 = -1;}
    while((s[i] != 0)&&isdigit(s[i]))
    {
        n2 = 10*n2 + s[i]-'0';//获取第二个数
        i++;
    }
    pResList[0] = n1*flag1;pResList[1] = n2*flag2;
    return pResList;
}

long long getR(long long a, long long b)
{
    if((a+b)%2 == 0){return 0;}
    else{return 1;}
}
long long getQi(long long a, long long b, long long r)
{
    long long Qi = 0;
    Qi = (r-a-b)/2;
    return Qi;
}

int main()
{
    char* s[100];memset(s,0,100*sizeof(char));
    scanf("%s",s);
    long long* pab = getAB(s);
    long long a = pab[0], b = pab[1],Qi = 0,Qr = 0;
    long long r = getR(a,b);
    free(pab);
    //printf("a = %d,b = %d,r = %d\n",a,b,r);

    long long res[100];memset(res,0,100*sizeof(long long));
    int j = 0;
    while(!((a == 0)&&(b == 0)))
    {
        r = getR(a,b);
        Qi = getQi(a,b,r);
        Qr = Qi + b;
        a = Qr;b = Qi;
        res[j++] = r;
        //printf("a = %d, b = %d, Qr = %d, Qi = %d, r = %d\n",a,b,Qr,Qi,r);
    }
    if(s[0] == '0'){printf("0");}
    else
    {
        for(int i = j-1;i>=0;i--)
        {
            printf("%lld",res[i]);
        }
    }

    return 0;
}
