#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char table[5] = "RBYG";
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        char s[110];memset(s,0,110*sizeof(char));
        scanf("%s",s);
        int len = strlen(s);
        int res[4];memset(res,0,4*sizeof(int));
        while(strchr(s,'!')!=NULL){//当还有坏灯泡时
            for(int i1 = 0;i1<len-3;i1++){
                int badCnt = 0,badindex = 0;
                char tmp[5];memset(tmp,0,5*sizeof(char));
                int tmpCnt = 0;
                for(int j = i1;j<i1+4;j++){//每四个一组
                    tmp[tmpCnt++] = s[j];
                    if(s[j]=='!'){//记录四个中坏掉的数量
                        badCnt++;
                        badindex = j;
                    }
                }
                //printf("i1 = %d, tmp = %s\n",i1,tmp);
                if(badCnt!=1){//当只有一个灯泡坏掉才能判断
                    //printf("continue\n");
                    continue;
                }
                else if(badCnt =1){
                    for(int j = 0;j<4;j++){//检查未出现的灯泡
                        if(strchr(tmp,table[j])==NULL){
                            s[badindex] = table[j];
                            res[j]++;
                        }
                    }
                }
                //printf("s = %s\n",s);
            }
        }
        printf("case #%d:\n",i);
        for(int j = 0;j<4;j++){
            printf("%d ",res[j]);
        }
        printf("\n");
    }
    return 0;
}
