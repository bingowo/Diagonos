#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct MyChar{
    char c;
    int row;
    int col;
}myChar;


void swap(char* a, char* b){
    char *tmp = a;
    a = b;
    b = tmp;
    return;
}

int main()
{
    while(1){
        char s[100];memset(s,0,100*sizeof(char));
        if(scanf("%s",s)==EOF){
            break;
        }
        int len = strlen(s);
        myChar mc[len]; memset(mc,0,len*sizeof(myChar));
        for(int i = 0;i<len;i++){
            mc[i].c = s[i];
            mc[i].col = i;
        }

        mc[0].row = 0;
        for(int i = 1;i<len;i++){
            if(s[i]>s[i-1]){
                if(mc[i-1].row>0){//上一个字符不是在最高处
                    mc[i].row = mc[i-1].row-1;
                }else{
                    for(int j = 0;j<i;j++){
                        mc[j].row++;
                    }
                    mc[i].row = 0;
                }
            }else if(s[i]<s[i-1]){
                mc[i].row = mc[i-1].row+1;
            }else{
                mc[i].row = mc[i-1].row;
            }
        }


        int maxRow = 0;
        for(int i = 0;i<len;i++){
            if(mc[i].row>maxRow){
                maxRow = mc[i].row;
            }
        }
        maxRow+=1;
        char** res = (char**)calloc(maxRow,sizeof(char*));//定义为指针数组，便于整行交换
        for(int i = 0;i<maxRow;i++){
            res[i] = (char*)calloc(len+1,sizeof(char));
            for(int j = 0;j<len;j++){
                res[i][j] = ' ';
            }

        }

        for(int i = 0;i<len;i++){
            res[mc[i].row][mc[i].col] = mc[i].c;
            //printf("%c: %d, %d\n",mc[i].c,mc[i].row,mc[i].col);
        }

        for(int i = 0;i<maxRow;i++){
            printf("%s\n",res[i]);
        }
    }
    return 0;
}
