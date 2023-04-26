#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number(char *str) {
    int len, sum = 0, flag = 0;
    for (int i = 0; i < strlen(str); i++)
        if (str[i] >= '0' && str[i] <= '9') {
            sum = 10 * sum + str[i] - 48;
            flag = 1;
        }
    if (flag == 0) sum = -1;
    return sum;
}


int cmp(const void *a,const void *b){
    char *a1,*b1;
    int a2,b2;
    a1 = (char*)a;
    b1 = (char*)b;
    a2 = number(a1);
    b2 = number(b1);
    if(a2 == b2)return strcmp(a1,b1);
    else{
        return a2 - b2;
    }
}

int main()
{
    char s[100][31];
    int n = 0;
    while(scanf("%s",s[n++]) != EOF);
    n--;
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i = 0;i < n - 1;i++){
        printf("%s ",s[i]);
    }
    printf("%s\n",s[n - 1]);
    return 0;
}
