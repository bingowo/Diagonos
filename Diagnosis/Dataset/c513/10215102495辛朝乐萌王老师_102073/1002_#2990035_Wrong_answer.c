#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int change(char c)
{
    int ret;
    if(isdigit(c)){
        ret = c-'0';
    }
    if (isupper(c)) {
        ret = c-'A'+10;
    }
    else{
        ret=c-'a'+36;
    }
    return ret;
}

int main()
{
    int  s[61];
    int find[62],cro[62];
    int t;
    for (int i=0; i<t; i++) {
        memset(find, -1, sizeof(find));
        memset(cro, -1, sizeof(cro));
        scanf("%s",s);
        int len=strlen(s);
        for (int j=0; j<len; j++) {
            find[j]=change(s[j]);
        }
        int number=0;
        unsigned long long outnum=0;
        for (int j=0; j<len; j++) {
            if(cro[find[j]]==-1){
                if(j==0){
                    cro[find[j]]=1;
                }
                else if(number==0){
                    cro[find[j]]=number;
                    number=2;
                }
                else{
                    cro[find[j]]=number;
                    number++;
                }
            }
        }
        if(number==0){number=2;}
        for (int j=0; j<len; j++) {
            outnum=outnum*number+cro[find[j]];
        }
        printf("case #%d:\n",i);
        printf("%llu\n",outnum);
    }
    return 0;
}
