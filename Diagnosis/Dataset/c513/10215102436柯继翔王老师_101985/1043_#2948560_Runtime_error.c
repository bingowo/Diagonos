#include <stdio.h>
#include <stdlib.h>

char* insert(char* s,char x, int i){
    int len = strlen(s);
    char* p;
    p = (char*)malloc((len + 2) * sizeof(char));
    for(int j = 0 ;j < i;j++){
        p[j] = s[j];
    }
    p[i] = x;
    for(int j = i + 1;j < len + 1;j++){
        p[j] = s[j - 1];
    }
    p[len + 1] = 0;
    return p;
}

void f(char* s){
    int len = strlen(s);
    char* x;
    x = (char*)malloc((len) * sizeof(char));
    int index = 0;
    int i = 0;
    while(i < len){
        if(i + 1 < len &&s[i] == s[i + 1]){
            int j = i + 1;
            while(j + 1 < len && s[j] == s[j + 1])j++;
            i = j + 1;
        }else{
            x[index++] = s[i];
            i++;
        }
    }
    x[index] = 0;
    for(int i = 0;i <= index;i++)s[i] = x[i];
    free(x);
    if(index == len || s == ""){
    }else{
        f(s);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i < T;i++){
        char* s = (char*)malloc(100 * sizeof(char));
        int max = 0;
        scanf("%s",s);
        int len = strlen(s);
        for(int j = 0;j <= len;j++){
            char *p1,*p2,*p3;
            p1 = insert(s,'A',j);
            p2 = insert(s,'B',j);
            p3 = insert(s,'C',j);

            f(p1);
            int len1 = strlen(p1);
            free(p1);

            f(p2);
            int len2 = strlen(p2);
            free(p2);

            f(p3);
            int len3 = strlen(p3);
            free(p3);

            int min = (len1 < len2?len1:len2) < len3?(len1 < len2?len1:len2):len3;
            if(len + 1 - min > max)max = len + 1 - min;
        }
        printf("case #%d:\n",i);
        printf("%d\n",max);
        free(s);
    }
    return 0;
}
