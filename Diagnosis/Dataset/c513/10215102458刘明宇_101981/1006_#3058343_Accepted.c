#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int T,cnt = 0;
    scanf("%d",&T);
    while(T-->0){
        char s[100];
        scanf("%s",s);
        int len = strlen(s);
        double num = 0.0;
        char *p = s;
        for(int i = 0;i < len;i++){
            int flag;
            if(*p == '-') flag = -1;
            else if(*p == '0') flag = 0;
            else flag = 1;
            num += (double)flag * pow(3,len-1-i);
            p++;
        }
        printf("case #%d:\n",cnt);
        printf("%0.f\n",num);
        cnt++;
    }
}
