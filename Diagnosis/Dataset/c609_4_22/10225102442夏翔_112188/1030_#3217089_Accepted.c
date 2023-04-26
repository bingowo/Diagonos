#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static double frequency[26];
int cmp1(const void *a, const void *b){
    char c1=*(char*)a, c2=*(char*)b;
    int temp1=(int)c1-65, temp2=(int)c2-65;
    if(c1>='a' && c1<='z') temp1 -= 32;
    if(c2>='a' && c2<='z') temp2 -= 32;
    if(frequency[temp1]>frequency[temp2]) return -1;
    else if(frequency[temp1]<frequency[temp2]) return 1;
    if(temp1!=temp2) return temp1-temp2;
    else return (int)c2-(int)c1;
}
int main(){
    int T, count;
    scanf("%d", &T);
    char *s, c;
    s = (char*)malloc(sizeof(char)*101);
    for(int k=0; k<T; k++){
        count = 0;
        for(int i=0; i<26; i++) scanf("%f",&frequency[i]);
        getchar();
        scanf("%c", &c);
        while(c!='\n'){
            s[count++] = c;
            scanf("%c", &c);
        }
        qsort(s,count,sizeof(s[0]),cmp1);
        printf("case #%d:\n", k);
        for(int i=0; i<count; i++) printf("%c", s[i]);
        printf("%c", '\n');
    }
    free(s);
    return 0;
}