#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lindex=0;

int putin(char line[], int M, char s[2005][36], int slen){
    int newadd=0;
    for (int i=0; i<slen; i++){
        if (strlen(line)+strlen(s[i])>M) break;
        if (strlen(s[i])<=M-strlen(line)){
            strcat(line, s[i]);
            line[strlen(line)] = ' ';
            newadd++;
        }
    }
    return newadd;
}

void ad_printf(char line[], int M, int index){
    int n = M-strlen(line)+1;//盈余空格数
    int m = index-1;//可插位置数
    int pos = m-(n%m);//不完整遍历开始位
    int turn = n/m;//不完整遍历轮
    int count=0;//空格计数
    for (int i=0; i<M; i++){
        if (line[i]==' '){
            printf(" ");
            if (count<pos) for (int j=0; j<turn; j++) printf(" ");
            else for (int j=0; j<turn+1; j++) printf(" ");
            count++;
        }
        else printf("%c", line[i]);
    }
    printf("\n");
    return;
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t=0; t<T; t++){
        int M; 
        scanf("%d ", &M);//长度为M，则最后一个字母在[M-1],换行符在[M]，终止符在[M+1]。
        //将所有单词读入二维数组s
        char s[2005][36] = {0};
        int word_index = 0;
        while (1) {
            scanf("%s", s[word_index++]);
            char ch = getchar();
            if (ch == '\n') break;
        }
        printf("case #%d:\n", t);

        while(1){
            char line[75] = {0};
            int newadd = putin(line, M, s+lindex, word_index);
            lindex += newadd;
            if (lindex>=word_index) {printf("%s\n", line);break;}
            else ad_printf(line, M, newadd);            
        }
    }
    return 0;
}