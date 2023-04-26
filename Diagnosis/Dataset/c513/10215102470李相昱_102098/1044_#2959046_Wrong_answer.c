#include <stdio.h>
#include <ctype.h>
int main() {
    unsigned int a[100001];
    char c;
    int sign = 0;
    int i=0;
    int n=-1;
    unsigned int ret=0;
    while ((c=getchar())&&(c!='\n')){
        if((c=='0')&&(sign==0||sign==1))
        {
            sign = 1;
        }else if((sign == 1)&&(c=='x'))
        {
            if(n>=0){
                a[n] = ret;
                ret =0;
                i=0;
            }
            sign =2;
            n++;
        }else if(sign ==2)
        {
            if(isdigit(c)){
                ret = ret*16+(c-'0');
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
    if(ret){
        a[n]=ret;
        n++;
    }
    if(n==-1){
        printf("-1");
    }
    for(int j=0;j<n;j++){
        printf("%u%c",a[j],j==n-1?'\n':' ');
    }
    return 0;
}
