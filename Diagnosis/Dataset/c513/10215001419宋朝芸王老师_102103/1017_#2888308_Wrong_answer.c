#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int acc[255] = {0};
    acc['I'] = 1;   acc['V'] = 5;
    acc['X'] = 10;  acc['L'] = 50;
    acc['C'] = 100; acc['D'] = 500;
    acc['M'] = 1000;

    char input[50];
    scanf("%s",input);
    int len = strlen(input);    //个数
    long long int ans = 0,temp;
    int flag = 1;

    for(int i = 0; i < len; i++){
        while(input[i] == '(') {flag *= 1000;i++;}
        while(input[i] == ')') {flag /= 1000;i++;}

        temp = acc[input[i]];
        if( i + 1 < len && input[i+1] != '('
            && input[i+1] != ')'
            && acc[input[i+1]] > acc[input[i]])
                {temp = -temp;}

        ans = ans + temp*flag;
    }

    printf("%lld",ans);

    return 0;
}
