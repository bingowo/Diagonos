#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char table[10][10] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

void deleteTinS(char* s, char* t, int slen){
    int tlen = strlen(t);
    for(int i = 0;i<tlen;i++){
        for(int j = 0;j<slen;j++){
            if(s[j]==t[i]){
                s[j] = '1';
                break;
            }
        }
    }
    return;
}

int cmp(const void*a, const void*b){
    return *(int*)a - *(int*)b;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        char s[30];memset(s,0,30*sizeof(char));
        scanf("%s",s);
        int slen = strlen(s);
        int num[10],numCnt = 0;memset(num,0,10*sizeof(char));
        for(int j = 0;j<slen;j++){
            int curNum = -1;
            if(s[j]=='Z'){
                curNum = 0;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
            else if(s[j]=='W'){
                curNum = 2;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
            else if(s[j]=='U'){
                curNum = 4;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
            else if(s[j]=='X'){
                curNum = 6;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
            else if(s[j]=='G'){
                curNum = 8;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
        }

        for(int j = 0;j<slen;j++){
            int curNum = -1;
            if(s[j]=='O'){
                curNum = 1;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
            else if(s[j]=='T'){
                curNum = 3;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
            else if(s[j]=='F'){
                curNum = 5;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
            else if(s[j]=='S'){
                curNum = 7;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
        }
        for(int j = 0;j<slen;j++){
            int curNum = -1;
            if(s[j]=='N'){
                curNum = 9;
                num[numCnt++] = curNum;
                deleteTinS(s,table[curNum],slen);
            }
        }
        qsort(num,numCnt,sizeof(num[0]),cmp);
        printf("case #%d:\n",i);
        for(int k = 0;k<numCnt;k++){
            printf("%d",num[k]);
        }
        printf("\n");
    }
    return 0;
}
