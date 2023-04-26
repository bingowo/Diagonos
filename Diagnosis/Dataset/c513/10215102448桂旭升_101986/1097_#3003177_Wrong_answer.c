#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int t[81];int min = 0;
int hang(char s[]){
    int len = strlen(s), temp = 0, max = 0, i;
    for(i = 1; i < len; i++){
        if(s[i]>s[i-1])temp++;
        else if(s[i]<s[i-1])temp--;
        t[i] = temp;//printf("%d %d ", max, min);
        max = max > temp ? max:temp;
        min = min < temp ? min:temp;
    }//printf("\n");
    for(i = 1; i < len; i++){
        t[i] -= min;
    }
    return max - min;
}
int cmp(const void *a, const void *b){
    int pa = *(int*)a, pb = *(int*)b;
    return pa < pb ? -1:1;
}
int main(){
    int k, n, i, j = 0, len, max;
    char s[81];
    while(scanf("%s", s) != EOF){
        max = 0; min = 0;
        len = strlen(s); max = hang(s)+1;
        char ans[max][len];
        for(i = 0; i < max; i++){
            for(j = 0; j < len; j++){
                ans[i][j] = ' ';
            }
        }
        ans[max-1+min][0] = s[0];
        for(i = 1; i < len; i++){
            ans[max-1-t[i]][i] = s[i];
            t[i] = max-1-t[i];
        }
        t[0] = max-1;
        qsort(t, len, sizeof(int), cmp);
        k = 0;//printf("%d %d %d %d\n", t[0], t[1], t[2], t[3]);
        for(i = 0; i < max; i++){
            int flag = 0;
            for(j = 0; j < len; j++){
                printf("%c", ans[i][j]);
                if(!isspace(ans[i][j])){
                    k++;
                    if(t[k] != i)flag = 1;
                }
                if(flag)break;
            }
            printf("\n");
        }
    }
    system("pause");
	return 0;
}