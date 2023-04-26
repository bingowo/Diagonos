#include <stdio.h>

void print(unsigned long long ,unsigned long long);

int main() {
    int cnt = -1;char c;int arr[40000000];
    while(1)
    {
        scanf("%c",&c);if(c == '\n')break;
        if(cnt>0)
        {
            int tmp;
            if(c >= 'A'&& c <= 'F')tmp = 10 + c - 'A';
            else tmp = c - '0';int i = 1;
            while(i <= 4){arr[cnt*4 - i] = tmp%2;tmp /=2;i++;}
        }
        cnt++;
    }cnt--;
    unsigned long long qr = 0,qi = 0;int k = cnt*4;unsigned long long  a,b;int j = 0;
    while(k){a = -qr - qi + arr[j++];b = qr - qi;qr = a;qi = b;k--;}
    if(b == 0)
    {if(a == 0)
        printf("0");
     else
         printf("%llu",a);}
    else
    {if(a == 0)
        {printf("%llu",b);printf("i");}
     else
     {if(b == 1)
         printf("%llu+i",a);
      else
         {printf("%llu%llu",a,b);printf("i");}}}
}

