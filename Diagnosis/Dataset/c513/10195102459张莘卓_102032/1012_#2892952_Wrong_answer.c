#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    char s[50]; scanf("%s",s);
    long long a=0, b=0;
    char *p = strchr(s, 'i');
    if(p == NULL) a = atoll(s);
    else {
        if(!isdigit(*(p-1))){
            *p = '1'; *(p+1) = '\0';
        }else *(p--) = '\0';
        
        while(p>=s && isdigit(*p)) --p;
        if(p < s){
            b = atoll(p+1);
        }else {
            b = atoll(p);
            *p = '\0';
            a = atoll(s);
        }
    }
    //printf("a=%lld  b=%lld\n",a,b);
    int num[100] = {0}, i=0;
    while(a || b) {
        if(abs(a%2) != abs(b%2)){
            num[i] = 1;
            --a;
        }
        long long t = (-a-b) / 2;
        a = (b-a) / 2;
        b = t;
        ++i;
    }
    for(i=i-1; i>=0; --i)
        printf("%d",num[i]);
    printf("\n");
    return 0;
}
