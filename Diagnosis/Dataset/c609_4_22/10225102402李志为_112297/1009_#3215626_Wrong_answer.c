#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int m,int n)
{
    if(n%m && n!=m )
        return GCD(n%m,m);
    else
        return m;

}
int main()
{
    int n,a=0,b=0,t,d=0;
    char s[200]={0};
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        a=0;b=0;
        gets(s);
        for(int j=0;j<strlen(s);j++){
            t=(int)s[j];//t是十进制的字符表示
            for(int y=0;y<8;y++){
                int x=1;
                d=t&x;//d是判据
                if(d) a++;
                else b++;
                t=t>>1;
            }
        }
        d=GCD(a,b);
        a=a/d;
        b=b/d;
        printf("%d/%d",a,a+b);
    }
    return 0;
}