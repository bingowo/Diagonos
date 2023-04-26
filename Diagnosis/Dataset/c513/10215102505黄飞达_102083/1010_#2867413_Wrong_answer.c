#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char* func(int len, int num){
    int templen = 0;
    static char s[11];
    switch(len){
        case 3:
            templen = 9;
            break;
        case 2:
            templen = 6;
            s[7] = '\0';
            break;
        case 1:
            templen = 3;
            s[4] = '\0';
            break;
    }
    while (templen > -1){
        s[templen--] = '0' + num%2;
        num /= 2;
    }
    //printf("s:%s\n", s);
    return (char*)s;
}

int main(){
    char s[510];
    char res1[10000];
    char res2[11];
    char res3[10000] = "0001";

    gets(s);
    int len = strlen(s), index = 0;
    for (int i = 0; i < len; i+=3){
        if (i + 3 > len){
            index = i;
            len = len - index;
            break;
        }
        int num = (s[i] - '0')*100 + (s[i+1]-'0')*10+(s[i+2]-'0');
        strcat(res1, func(3, num));
    }
    int num;
    if (len == 2){
        num = (s[index]-'0')*10+(s[index+1]-'0');
    }
    else if (len == 1){
        num = s[index]-'0';
    }
    if (len != 3){
        strcat(res1, func(len, num));
    }
    len = strlen(s);

    for (int i = 0; i < 10; i++) {
        res2[i] = '0' + (1&len);
        len >>= 1;
    }
    len = strlen(res2);

    char *l = res2;
    char *r = res2 + len - 1;
    char ctemp;
    while (l < r){
        ctemp = *l;
        *l = *r;
        *r = ctemp;
        l++;r--;
    }

// printf("1:%s\n", res1);
// printf("2:%s\n", res2);

    strcat(res3, res2);
    strcat(res3, res1);
    
    printf("%s\n", res3);
    return 0;
}
