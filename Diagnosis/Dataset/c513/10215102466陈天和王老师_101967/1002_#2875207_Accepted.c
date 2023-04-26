#include <stdio.h>
long long f(char str[]);
int main()
{
    int T;
    char a[10][61];//objects in an array are presumed to 0(without initialization）
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",a[i]);
    }

    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%lld\n",f(a[i]));
    }

    return 0;
}
long long f(char str[]){
    int a[128];
    for(int i=0;i<128;i++){a[i]=-1;}

    int digit=0,N=1,i;
    char *p=str;
    a[*p]=1;
    while (*++p)// move pointer before the operation!
                //objects in an array are presumed to 0(without initialization）
        if (a[*p]==-1)
        {
            a[*p]=digit;
            digit=digit?digit+1:2;
            //calculate as :  digit=((digit)?(digit+1):2);
            N++;//N用来记录有多少个不同字符，最开始是一个，然后每次a[*p]==-1就多一个
        }
    if (N<2) N=2;
    //数组a其实是一个以asc码为编号的数组，刚好储存了128个字符对应的数字（asc值为0到127）

    long long ans=0;
    p=str;//初始化指针，让他再次指向数组最前面
    //7进制 1829的不用次幂运算方式
    //ans=1
    //ans=1*7+8
    //ans=1*7*7+8*7+2
    //ans=1*7*7*7+8*7*7+2*7
    //ans=1*7*7*7*7+8*7*7*7+2*7*7+9
    while (*p){
        ans=ans*N+a[*p++];
    }
    return ans;

}