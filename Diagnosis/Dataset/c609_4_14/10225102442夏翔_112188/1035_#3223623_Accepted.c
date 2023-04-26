#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a, int b){
    if(a>b) return a;
    else return b;
}
void sclear(char s1[]){
    int count, len;
    while(strstr(s1,"AA")||strstr(s1,"BB")||strstr(s1,"CC")){
        count = 0;
        len = strlen(s1);
        if(s1[0]!=s1[1]) count++;
        for(int i=1; i<len-1; i++){ //左右均不相等
            if(s1[i-1]!=s1[i]&&s1[i]!=s1[i+1]) s1[count++] = s1[i];
        }
        if(s1[len-1]!=s1[len-2]) s1[count++] = s1[len-1];
        s1[count] = '\0';
    }
}
int main(){
    int T, len1, len_max=0;
    scanf("%d", &T);
    char s[101], temp[101];
    for(int k=0; k<T; k++){
        scanf("%s", s);
        printf("case #%d:\n", k);
        len1 = strlen(s);
        len_max = 0;
        for(int i=0; i<len1; i++){  //枚举
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