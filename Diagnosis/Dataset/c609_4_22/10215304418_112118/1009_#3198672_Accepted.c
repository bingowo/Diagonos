#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y){
    if (x<y){
        int temp=x;
        x=y;
        y=temp;
    }
    if (y==0) return x;
    else return (gcd(y,x%y));
}

int main()
{
    char s[10010];
    int t;
    scanf("%d",&t);
    gets(s);
    for (int l=1;l<=t;l++){
        int ans=0;
        gets(s);
        for (int i=0;i<=strlen(s);i++){
            int x=s[i];
            int d=1;
            int number=0;
            for (int j=0;j<8;j++){
                if (x&d) ans++;
                d=d << 1;
            }
        }
        int gcdx=gcd(ans,8*strlen(s));
        printf("%d/%d\n",ans/gcdx,8*strlen(s)/gcdx);
    }
    return 0;
}
