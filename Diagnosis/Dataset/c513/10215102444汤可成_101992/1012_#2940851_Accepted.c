#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ret[1000] = {0};
    char get[50] = {0};
    scanf("%s", get);
    int i = 0;
    int r = 0;
    int flag = 1;
    long long QR = 0;
    long long QI = 0;
    long long qr = 0;
    int len = strlen(get);
    long long num = 0;
    if(get[0] == '0') printf("0\n");
    else
    {
        while(i<len)
        {
            if(i == 0 && get[i] == '-')
            {
                flag = -1;
                if(get[i+1] == 'i')num = 1;
                i++;
            }
            else if(get[i] >= '0' && get[i] <= '9')
            {
                num = num*10 + get[i]-'0';
                i++;
                if(i == len) QR = num*flag;
            }
            else if(get[i] == '+' || get[i] == '-')
            {
                QR = num*flag;
                if(get[i] == '-')
                {
                    flag = -1;
                }
                else flag = 1;
                if(get[i+1] == 'i') num = 1;
                else num = 0;
                i++;
            }
            else if(get[i] == 'i')
            {
                if(i == 0) QI = 1;
                else QI = num*flag;
                i++;
            }
        }
        int j = 0;
        while(QR != 0 || QI != 0)
        {
            if((QR&(long long)1) == (QI&(long long)1))
            {
                r = 0;
            }
            else
            {
                r = 1;
                QR--;
            }
            ret[j++] = '0'+r;
            QR = (QI-QR)/2;
            QI = QR - QI;
        }
        for(i = j-1; i>=0; i--)
        {
            printf("%c", ret[i]);
        }

    }
    return 0;
}
