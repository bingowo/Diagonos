#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int getnumber(char *p, int len){
    int sum = -1;
    for (int i = 0; i != len; i++){
        if (isdigit(p[i])){
            sum = 0;
            while(isdigit(p[i]))
                sum = p[i++] - '0' + sum * 10; 
            break;
        }
    }
    return sum;
}

int compare(const void *p1, const void *p2){
    char *string1 = *(char**)p1, *string2 = *(char**)p2;
    int sum1 = getnumber(string1, strlen(string1));
    int sum2 = getnumber(string2, strlen(string2));
    if (sum1 == sum2) return strcmp(string1, string2);
    return sum1 - sum2;
}

int main(){
    char **strings;
    strings = (char**) malloc(sizeof(char*) * 100);
    int len = 0;
    do{
        char temp[30];
        scanf("%s", temp);
        strings[len] = (char*)malloc(sizeof(char) * strlen(temp));
        strcpy(strings[len++], temp);
    }while(getchar() != '\n' && len < 100);
    qsort(strings, len, sizeof(strings[0]), compare);
    for (int i = 0; i != len; i++){
        if (i != len-1) printf("%s ", strings[i]);
        else printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
    return 0;
}
