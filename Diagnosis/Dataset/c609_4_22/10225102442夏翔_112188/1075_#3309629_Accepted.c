//1075
#include<stdio.h>
#include<string.h>
void print(char *s, int len, int *num, int *level, int max, int min);
int main(){
    char s1[85];
    int num[170], level[85]; //num记录某层的字母个数，level记录每个字符是第几层，从85下标开始
    int len1, pos, max, min; //记录最高层和最低层
    while(scanf("%s", s1) != EOF){
        len1 = strlen(s1); pos = 85; max = 85; min = 85;
        memset(num, 0, sizeof(num));
        memset(level, 0, sizeof(level));
        num[pos] ++; level[0] = pos; 
        for(int i = 1; i < len1; i ++){ //记录每层字母数，每个字母在哪一层
            if(s1[i] > s1[i-1]) 
                pos ++;
            else if(s1[i] < s1[i-1])
                pos --;
            min = (pos < min)? pos: min;
            max = (pos > max)? pos: max;
            num[pos] ++;
            level[i] = pos;
        }
        print(s1, len1, num, level, max, min);
    }

    return 0;
}

void print(char *s, int len, int *num, int *level, int max, int min){ //逐层打印
    for(int i = max; i >= min; i--){
        for(int j = 0; j < len && num[i] > 0; j++){ //一层没了直接下一层
            if(level[j] != i) printf(" ");
            else{
                printf("%c", s[j]);
                num[i] --;
            }
        }
        printf("\n");
    }
}