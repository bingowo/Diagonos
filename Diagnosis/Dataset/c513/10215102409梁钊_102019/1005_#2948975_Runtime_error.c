#include<stdio.h>
#include<string.h>

int main()
{
    int t ;
    scanf("%d",&t) ;
    for(int i = 0; i != t; i++){
        char s[50] = {0} ;
        scanf("%s",&s) ;
        int numbers = 0;
        int len = strlen(s) - 1;
        char res[50] = {0} ;
        for (; len != 1; --len) {
            int digit = s[len] - '0' ;
            int j = 0;
            do {
                int tmp ;
                if (j < numbers)
                    tmp = digit*10 + res[j] - '0' ;
                else
                    tmp = digit*10 ;
                res[j++] = tmp / 8 + '0' ;
                digit = tmp % 8;
            } while (digit!=0 || j < numbers);
            numbers = j ;
        }
        printf("case #%d:\n0.%s\n",i,res) ;
    }
}