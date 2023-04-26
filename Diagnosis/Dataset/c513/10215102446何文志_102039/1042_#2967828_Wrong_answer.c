#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char res[1000][20];
int resCnt = 0;
char track[20];

void backtrack(char* table,int start){
    strcpy(res[resCnt],track);
    resCnt++;
    for(int i = start;i<strlen(table);i++){
        track[strlen(track)] = table[i];
        backtrack(table,start+1);
        track[strlen(track)-1] = 0;
    }
}

int cmp(const void *a,const void *b)
{
    char A = *(char*)a,B = *(char*)b;
    return A-B;
}

int main(){
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        memset(res,0,1000*20*sizeof(char));
        memset(track,0,20*sizeof(char));
        resCnt = 0;
        char s[20];memset(s,0,20*sizeof(char));
        scanf("%s",s);
        char table[20];memset(table,0,20*sizeof(char));

        int len = strlen(s),cnt = 0;
        for(int j = 0;j<len;j++){
            int flag = 0;
            for(int k = j+1;k<len;k++){
                if(s[j]==s[k]){flag = 1;break;}
            }
            if(flag==0){table[cnt++]=s[j];}
        }
        qsort(table,strlen(table),sizeof(table[0]),cmp);
        backtrack(table,0);

        printf("case #%d:\n",i);
        for(int j = 0;j<resCnt;j++){
            printf("%s\n",res[j]);
        }
    }
    return 0;
}
