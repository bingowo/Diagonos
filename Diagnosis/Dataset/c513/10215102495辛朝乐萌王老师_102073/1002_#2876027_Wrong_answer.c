#include <stdio.h>
#include <ctype.h>
#include <string.h>

int change(char c)
{
    int ret;
    if(isdigit(c))
        ret = c-'0';
    else if(isupper(c))
        ret=c-'A'+10;
    else
        ret=c-'a'+36;
    return ret;
}

int main(void)
{
    char s[61];
    int a[62],b[62];
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        memset(a, -1, sizeof(a));
        memset(b, -1, sizeof(b));
        scanf("%s",s);
        int len=strlen(s);
        for(int j=0;j<len;j++){
            a[j] = change(s[j]);
        }
        int number=0;
        unsigned long long outnum = 0;
        for (int j=0; j<len; j++) {
            if(b[a[j]] == -1){
                if(j==0){
                    b[a[j]] =1;
                }
                else if(number==0){
                    b[a[j]] == number;
                    number++;
                }
            }
        }
        if(number==0){
            number=2;
        }
        for (int j=0; j<len; j++) {
            outnum= outnum*number+b[a[j]];
        }
        printf("case #%d:\n",i);
        printf("%lld\n",outnum);
    }
    return 0;
}
