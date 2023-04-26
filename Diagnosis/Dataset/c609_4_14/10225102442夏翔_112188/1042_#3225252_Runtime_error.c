#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){  //模拟队列
    int T, M, count, len, numSpace, averSpace, leftSpace, count1, head;
    scanf("%d", &T);
    char **s, *temp, c;
    for(int k=0; k<T; k++){
        printf("case #%d:\n", k);
        s = (char**)calloc(1001, sizeof(char*));
        scanf("%d", &M);
        getchar();
        count = 0; //单词总个数
        temp = (char*)malloc(sizeof(char)*(M/2+1));
        while(1){
            scanf("%s", temp);
            if(strlen(temp)==0) break;
            s[count] = (char*)malloc(sizeof(char)*(M/2+1));
            strcpy(s[count++], temp);
            scanf("%c", &c);
            if(c=='\n') break;
        }
        head = 0;//队列头
        len = 0; //每行当前单词总长度
        count1 = 0; //当前行所包含单词数
        for(int i=0; i<count; i++){
            if(len+count1+strlen(s[i])<=M){
                len += strlen(s[i]);
                count1++;
            }else{
                printf("%s", s[head++]);
                numSpace = M-len; //空格总数
                averSpace = (M-len)/(count1-1);//平均空格数
                leftSpace = (M-len)%(count1-1);//多出来的空格数
                for(int j=0; j<count1-1-leftSpace; j++){
                    for(int t=0; t<averSpace; t++) printf("%c", ' ');
                    printf("%s", s[head++]);
                }
                for(int j=0; j<leftSpace; j++){
                    for(int t=0; t<averSpace+1; t++) printf("%c", ' ');
                    printf("%s", s[head++]);
                }
                printf("%c", '\n');
                len = 0; //每行当前单词总长度
                count1 = 0;
                i--;
            }
        }
        if(count1!=0){
            printf("%s", s[head++]);
            for(int i=0; i<count1-1; i++) printf(" %s", s[head++]);
            printf("%c", '\n');
        }
        for(int i=0; i<count; i++) free(s[i]);
        free(s);
        free(temp);
    }
    return 0;
}
