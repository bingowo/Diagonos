#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y){
    while(x%y){
        x = y;
        y = x%y;
    }
    return y;
}

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        char c;
        int len = 0,count=0;
        while((c = getchar()) != '\n'){
            len++;
            int flag = 1;
            for(int j=0;j<8;j++){
                if(c&flag)count++;
                flag = flag<<1;
            }
        }
        len *= 8;
        int g = gcd(len,count);
        printf("%d/%d\n",count/g,len/g);
    }
    return 0;
}
