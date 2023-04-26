#include <stdio.h>
int main() {
    char c;
    int sign=0;
    int t=0;
    while (c=getchar()!=EOF){
        if(c=='"'){
            if(sign==0){
                sign = 1;
            } else{
                sign =0;
            }
        }
        if(sign==0)
        {
            if(c=='/')
            {
                if(t==0)
                {
                    t =1;
                }
                else{
                    while (c = getchar()&&c!='\n');
                    t = 0;
                }

            }
            if(c=='*'){
                if(t==1){
                    char d;
                    while (c=getchar()&&(c!='*'||(d=getchar()&&d!='/')));
                }
            }
        }
        printf("%c",c);
    }
    return 0;
}
