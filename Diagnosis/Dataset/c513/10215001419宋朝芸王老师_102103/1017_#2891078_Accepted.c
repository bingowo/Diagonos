#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
***debug example***
(((MMMCCCXXXIII)))  12  ->   4 + 3 * n
*/
int main()
{
    int acc[255] = {0};
    acc['I'] = 1;   acc['V'] = 5;
    acc['X'] = 10;  acc['L'] = 50;
    acc['C'] = 100; acc['D'] = 500;
    acc['M'] = 1000;

    char input[50];
    scanf("%s",input);
    int lenOri = strlen(input);    //nums

    long long int ans = 0, temp;
    long long int solve[50] = {0};
    int lenNum = 0;
    long long int flag = 1;

    for(int i = 0; i < lenOri; i++){
        while(input[i] == '(') {
                flag *= 1000;
                i++;
        }
        while(input[i] == ')') {
                flag /= 1000;
                i++;
        }

        if(i < lenOri)
            solve[lenNum++] = acc[input[i]] * flag;
    }

    for(int i = 0; i < lenNum; i++){
        temp = solve[i];

        if(solve[i+1] > solve[i])
            temp = -temp;

        ans = ans + temp;
    }

    printf("%lld",ans);

    return 0;
}
