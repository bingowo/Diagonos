#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
long long num[100];
long long decode(char* begin, char* end){
    if(begin > end) return 0;
    long long sum = 0;
    if(strchr(begin, '(') != NULL) {
        char *p = strchr(begin, '(');
        char *q = strrchr(begin, ')');
        *p = *q = '\0';
        long long t = decode(p+1, q-1)*1000;
        int sign = t > decode(begin, p-1) ? -1 : 1;
        return sign*decode(begin, p-1) + t + decode(q+1, end);
    }
    for(char *p=begin; p<=end; ++p) {
        if(p==end || num[*p]>=num[*(p+1)])
            sum += num[*p];
        else {
            sum += num[*(p+1)] - num[*p];
            ++p;
        }
    }
    return sum;
}

int main()
{
     num['I']=1; num['V']=5;
    num['X']=10; num['L']=50;
    num['C']=100; num['D']=500; num['M']=1000;
    
    char s[51], *p;
    scanf("%s",s);
    for(p=s; *p; ++p);
    printf("%lld\n",decode(s, p-1));
    return 0;
}