#include <stdio.h>
#include <ctype.h>
int main() {
    unsigned int a[100001];
    char c;
    int sign = 0;
    int i=0;
    int n=-1;
    int flag=0;
    unsigned int ret=0;
    while ((c=getchar())&&(c!='\n')){
        if((c=='0')&&(sign==0||sign==1))
        {
            sign = 1;
        }else if((sign == 1)&&(c=='x'))
        {
            if(n>=0){
                if(flag ==0&&ret==0){
                    n--;
                }else{
                    a[n] = ret;
                    flag=0;
                }
                ret =0;
                i=0;
            }
            sign =2;
            n++;
        }else if(sign ==2)
        {
            if(isdigit(c)){
                ret = ret*16+(c-'0');
                flag =1;
            }else if(c>='a'&&c<='f'){
                ret = ret *16+(c-'a'+10);
            } else{
                sign =0;
            }
            i++;
        }else{
            sign =0;
        }
    }
    if(ret>=0){
        a[n]=ret;
        n++;
    }
    if(flag ==0&&ret==0){
        n--;
    }
    if(n==-1||n==0){
        printf("-1");
    }
    for(int j=0;j<n;j++){
        printf("%u%c",a[j],j==n-1?'\n':' ');
    }
    return 0;
}
