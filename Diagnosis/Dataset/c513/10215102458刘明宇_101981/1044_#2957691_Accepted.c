#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main()
{
    char *s = (char*)malloc(100001*sizeof(char));
    double *num = (double*)malloc(100001*sizeof(double));
    scanf("%s",s);
    char *p = s;
    int cnt = 0;
    char *p0 = s;
    while(*p0) p0++;
    p0 = p0-1;
    //统计十进制数的个数
    //来存放十进制数
    while(*p){
        if(*p == '0' && *(p+1) == 'x'){
            char *p1 = p+2;
            char *p2 = p+2;
            int len = 0;
            if(*p1 >='g' || p+1 == p0);
            else{
            while((*p1>='0' && *p1 <='9')||(*p1>='a' && *p1<='f')){
                p1++;
                len++;
            }
            for(int i = 0;i<len;i++){
                if(*p2 >= 'a' && *p2 <='f') {num[cnt] += (*p2-'a'+10)*pow(16,(len-i-1));}
                else if(*p2 >='0' && *p2 <='9'){num[cnt] += (double)(*p2 - '0')*pow(16.0,(double)(len-i-1));}
                p2++;
            }
            cnt++;
        }
        }
        p++;
    }
    int flag = 0;
    for(int k = 0;k<cnt;k++){
        if(num[k] != 0) flag = 1;
    }
    if(flag == 0) printf("-1");
    if(flag == 1){
    for(int k = 0;k<cnt;k++){
    printf("%0.f ",num[k]);
    }
    }
    //printf("%s",s);
}

