#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int x,int y)
{
    int max=1;
    for(int i=2;i<=y;i++){
        if(x%i==0 && y%i==0)max=i;
    }
    return max;
}

int main()
{
    int T;
    scanf("%d",&T);
    char a=getchar();
    for(int i=0;i<T;i++){
        char s[300]={'\0'};
        gets(s);
        int num=strlen(s)*8,ones=0;
        for(int j=0;j<strlen(s);j++){
            int tmp=s[j];
            for(int k=0;k<8;k++){
            if((tmp&1)==1){ones++;}
            tmp=tmp>>1;
            }
        }
        int max=gcd(num,ones);
        printf("%d/%d\n",ones/max,num/max);
    }
    return 0;
}
