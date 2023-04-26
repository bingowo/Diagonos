#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 500

typedef struct{
    int bi[M+1];
}BIGINT;


int main()
{
    char s1[M+1],s2[M+1];
    while(scanf("%s %s",s1,s2) == 2){
        int len1 = strlen(s1), len2 = strlen(s2);

        BIGINT a = {{0}}, b = {{0}}, r = {{0}};
        //input a,b
        for(int i = 0; i < len1; i++)
            a.bi[i] = s1[len1 - i - 1] - '0';
        for(int i = 0; i < len2; i++)
            b.bi[i] = s2[len2 - i - 1] - '0';


        //who is bigger
        int flag;
        if(len1 != len2) flag = len1 > len2 ? 1 : -1;
        else for(int i = len1-1; i >= 0; i--){
            if(a.bi[i] != b.bi[i]){
                flag = a.bi[i] > b.bi[i] ? 1 : -1;
                break;
            }
            else if(i == 0) flag = 0;
        }


        //cal minus
        if(flag == 0){printf("0\n");continue;}

        int temp,carry = 0;
        int len = len1 > len2 ? len1 : len2;
        for(int i = 0; i <= M; i++){

            temp = a.bi[i] - b.bi[i];
            if(flag == 1)
                temp += carry;
            else temp = carry - temp;

            if(temp < 0){
                temp += 10;
                carry = -1;
            }
            else carry = 0;

            r.bi[i] = temp % 10;
        }


        //output
        int k = M;
        if(flag == -1) printf("-");
        while(r.bi[k] == 0) k--;
        while(k >= 0)
            printf("%d",r.bi[k--]);
        printf("\n");

    }
    return 0;
}
