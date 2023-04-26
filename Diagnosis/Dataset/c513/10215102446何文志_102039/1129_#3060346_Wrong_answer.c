#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[10001];
char res[10000001];
int resCnt = 0;

int main()
{
    scanf("%s",s);

    int ptr = 0;

    char curStr[10001];
    while(s[ptr]!=0){
        if(!isdigit(s[ptr])){
            memset(curStr, 0, sizeof(curStr));
            int curCnt = 0;
            while(!isdigit(s[ptr]) && s[ptr]!=0){
                curStr[curCnt] = s[ptr];
                curCnt++; ptr++;
            }
            // printf("curStr : %s\n",curStr);
        }else{
            char curNumStr[101];
            memset(curNumStr, 0, sizeof(curNumStr));
            int curNumStrCnt = 0;
            while(isdigit(s[ptr]) && s[ptr]!=0){
                curNumStr[curNumStrCnt] = s[ptr];
                curNumStrCnt++; ptr++;
            }
            int curNum = atoi(curNumStr);
            // printf("curNum : %d\n", curNum);
            for(int i = 0;i<curNum;i++){
                strcat(res, curStr);
            }
        }
        //ptr++;
    }

    printf("%s",res);
    return 0;
}
