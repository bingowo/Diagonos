#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
void sclear(char *s1){
    char *a, *b, *c;
    int count;
    while(1){
        count = 0;
        a = strstr(s1,"AA");
        if(a){
            while(a[count]=='A')
                a[count++] = '\0';
            strcat(s1,a+count);
            continue;
        } 
        b = strstr(s1,"BB");
        if(b){
            while(b[count]=='B')
                b[count++] = '\0';
            strcat(s1,b+count);
            continue;
        } 
        c = strstr(s1,"CC");
        if(c){
            while(c[count]=='C')
                c[count++] = '\0';
            strcat(s1,c+count);
            continue;
        } 
        break;
    }
}
int main(){
    int T, len1, len2, len_max;
    scanf("%d", &T);
    char s[101], temp[101];
    for(int k=0; k<T; k++){
        scanf("%s", s);
        printf("case #%d:\n", k);
        len1 = strlen(s);
        sclear(s);
        len2 = strlen(s);
        if(len2==0){
            printf("%d\n", len1+1);
            continue;
        }
        len_max = len1-len2;
        for(int i=0; i<len2; i++){
            for(int j=0; j<3; j++){
                memcpy(temp,s,i);
                temp[i] = (char)(65+j);
                temp[i+1] = '\0';
                strcat(temp,s+i);
                sclear(temp);
                len_max = max(len_max,len1-strlen(temp)+1);
            }
        }
        printf("%d\n", len_max);
    }
    return 0;
}