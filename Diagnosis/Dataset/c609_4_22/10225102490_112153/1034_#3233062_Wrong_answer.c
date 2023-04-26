#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char* s = (char*)malloc(sizeof(char) * 111111);
    scanf("%s",s);
    int i = 0;
    int flag = 0;
    while(i < strlen(s)-2)
    {
        char a,b,c;
        unsigned int h = 0;
        a = s[i], b = s[i+1], c = s[i+2];
        if (a == '0' && b == 'x' && //则后面的数为十六进制数
            ((c >= '0' && c <= '9') || (c >='a' && c <= 'f')))
        {
            i += 3;
            h = (c >= 'a' ? c-'a'+10 : c-'0');
            printf("h=%u ",h);
            while (i < strlen(s) &&
                   ((s[i] >= '0' && s[i] <= '9') || (s[i] >='a' && s[i] <= 'f')))
            {
                h = h * 16 + (s[i] >= 'a' ? s[i]-'a'+10 : s[i]-'0');
                //printf("%u ",h);
                i++;
            }
            //printf("\n");
            flag = 1;
            printf("%u ",h);
        }
        else i++;
    }
    if (flag == 0) printf("-1\n");
}