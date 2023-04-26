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
    int pos, turn;//不完整遍历开始位//不完整遍历轮
    if (m==0) {pos = 0;turn=0;}
    else {pos = m-(n%m);turn = n/m;}
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
        lindex=0;
        int M; 
        scanf(" %d ", &M);//长度为M，则最后一个字母在[M-1],换行符在[M]，终止符在[M+1]。
        //将所有单词读入二维数组s
        char s[2005][36] = {0};
        int word_index = 0, sj=0;

        char ch = getchar();
        while (ch==' ') ch=getchar();
        s[word_index][sj++]=ch;
        while (1) {
            ch = getchar();
            if (ch==' '){
                s[word_index][sj]='\0';
                word_index++;sj=0;
                while (ch == ' ') ch = getchar();
            }
            if (ch == '\n') break;
            s[word_index][sj++]=ch;
        }
        printf("case #%d:\n", t);
        if (word_index==0) word_index=1;
        while(1){
            char line[75] = {0};
            int newadd = putin(line, M, s+lindex, word_index);
            lindex += newadd;
            if (lindex>=word_index) {line[strlen(line)-1]='\0';printf("%s\n", line);break;}
            else ad_printf(line, M, newadd);  
            if (lindex==0) lindex=1;          
        }
    }
    return 0;
}