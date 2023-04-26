#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct{
    char target;//它对应哪个字符
    int repeat;//它重复了几次
}str;
int sameLen;
int cmp(const void *a,const void *b) {


    return *(int*)a-*(int*)b;

}

int main(){
    int n; scanf("%d", &n);
    char s[101]; int len;
    str** L = (str**)malloc(sizeof(str*)*n);
    for(int i = 0; i<n; i++){
        L[i] = (str*)malloc(sizeof(str)*101);
    }
    int* simple_letter_lenth = (int*)malloc(sizeof(int)*n);
    int simple_index = 0;
    for(int i = 0; i<n; i++){
        scanf("%s", s);
        len = strlen(s);
        int cnt = 0; int pos = 0;
        for(int j = 0; j<len; j++){
            if(j==0){
                L[i][cnt].target = s[0];
                L[i][cnt].repeat = 1;
            }
            else if(s[j] == s[j-1]){
                L[i][cnt].repeat++;
            }
            else if(s[j] != s[j-1]){
                pos += L[i][cnt].repeat;
                cnt++;
                L[i][cnt].target = s[j];
                L[i][cnt].repeat = 1;
            }
        }
        //cnt代表了在本次输入里，最简子串的长度
        simple_letter_lenth[simple_index++] = cnt+1;
    }
    //如果最简子串长度都不同，肯定无法继续
    int judge = 0;
    for(int i = 1; i<simple_index; i++){
        if(simple_letter_lenth[i] != simple_letter_lenth[0]){
            judge = 1;
            break;
        }
    }
    if(judge){
        printf("-1");
    }
    else{//此分支代表最简子串长度相同
        int stop = 0;
        int sum = 0;
        sameLen = simple_letter_lenth[0];
        for(int i = 1; i<n; i++){
            for(int j = 0; j<sameLen; j++){
                if(L[i][j].target != L[i-1][j].target){
                    stop = 1; break;
                }
            }
            if(stop){
                break;
            }
        }
        if(stop){printf("-1");}
        else{
            int a[100000];
            for(int i = 0; i<sameLen; i++){
                for(int j = 0; j<n; j++){
                    a[j] = L[j][i].repeat;
                }
                qsort(a, n, sizeof(int), cmp);
                for(int j = 0; j<n; j++){
                    sum += abs(a[j] - a[n/2]);
                }
            }
            printf("%d", sum);
        }
    }
    free(simple_letter_lenth);
    free(L);
    return 0;
}
