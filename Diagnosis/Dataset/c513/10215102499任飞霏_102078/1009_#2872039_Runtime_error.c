#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        int len = 0,part = 0;
        char c;
        while((c = getchar()) != EOF){
            len++;
            int number = 0,flag = 1;
            for(j = 0;j < 8;j++){
                if(c&flag == 1)number++;
            }
            part += number;
        }
        int g = gcd(len*8,part);
        printf("%d/%d\n",part/g,len*8/g);
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
