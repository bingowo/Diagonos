#include<stdio.h>
#include<string.h>

void reverse(char *res){
    int lo = 0, hi = strlen(res) - 1;
    while(lo <= hi){
        char temp = res[lo];
        res[lo++] = res[hi];
        res[hi--] = temp;
    }
}

void transToB(int num, int len, char *res){
    for (int i = 0; i != len; ++i){
        if (num % 2) res[i] = '1';
        else res[i] = '0';
        num /= 2;
    }
    res[len] = '\0';
    reverse(res);
}

int main(){
    char res[2000] = {'\0'};
    char s[500]; scanf("%s", s);
    strcat(res, "0001");
    int slen = strlen(s);
    char tempCat[11];
    transToB(slen, 10, tempCat);
    strcat(res, tempCat);

    for (int i = 0; i != slen; ){
        int numLen = 0, num = 0;
        for (; numLen != 3; ++numLen, ++i){
            if (i == slen) break;
            num = num * 10 + s[i] - '0';
        }
        switch (numLen){
            case 1:
                transToB(num, 4, tempCat);
                break;
            case 2:
                transToB(num, 7, tempCat);
                break;
            case 3:
                transToB(num, 10, tempCat);
                break;
            default:
                printf("Error");
                break;
        }
        strcat(res, tempCat);
    }
    printf("%s\n", res);
    return 0;
}
