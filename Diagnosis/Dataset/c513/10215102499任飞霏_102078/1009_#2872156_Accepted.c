#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y);

int main()
{
    int n,i,j;
    scanf("%d",&n);
    getchar();
    for(i = 0;i < n;i++){
        int len = 0,number = 0;
        char c;
        while((c = getchar()) != '\n'){
            len++;
            char flag = 1;
            for(j = 0;j < 8;j++){
                if(c&flag)number++;
                flag = flag << 1;
            }
        }
        len *= 8;
        int g = gcd(len,number);
        printf("%d/%d\n",number/g,len/g);
    }
    return 0;
}

int gcd(int x,int y)
{
    int r = 0;
    r = x % y;
    if(r == 0)return y;
    else
        return gcd(y,r);
}
