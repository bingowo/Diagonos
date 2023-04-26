#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int A,B;
    char s[33];
    scanf("%d",&A);
    scanf("%s",s);
    scanf("%d",&B);
    long long int num = 0;
    int carry = 1;
    for(int i = strlen(s) - 1; i >= 0; i--){
        if (s[i] >= 'a' && s[i] <= 'z'){
            num = num + carry * (s[i] - 'a' + 10);
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            num = num + carry * (s[i] - 'A' + 10);
        }else if(s[i] >= '0' && s[i] <= '9'){
            num = num + carry * (s[i] - '0');
        }
        carry = carry * A;
    }
    char ans[33];
    //a / b = c ...... d
    int a,b,c,d;
    a = num;
    b = B;
    c = a / b;
    d = a % b;
    int pl = 0;
    while(c != 0){
        if(d >= 10){
            ans[pl] = d + 'A' - 10;
        }else{
            ans[pl] = d + '0';
        }
        a = a / b;
        b = B;
        c = a / b;
        d = a % b;
        pl++;
    }
    if(d >= 10){
        ans[pl] = d + 'A' - 10;
    }else{
        ans[pl] = d + '0';
    }
    if(num == 0){
        printf("0");
    }else{
        for(int i = pl; i >= 0; i--){
            printf("%c",ans[i]);
        }
    }

    return 0;
}
