#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num;
    char zifu;
}Date;



int main()
{
    int T;scanf("%d",&T);
    char a=getchar();
    for(int i=0;i<T;i++){
        char wenben[501];
        gets(wenben);
        Date date[250];
        for(int j=0;j<250;j++){date[j].num=0;date[j].zifu='\0';}
        int wordCnt=-1;
        char tmp1='\0',tmp2;
        for(int k=0;wenben[k];k++){
            tmp2=wenben[k];
            if(tmp2!=tmp1){
                wordCnt++;
                date[wordCnt].zifu=tmp2;
                date[wordCnt].num++;
            }
            else if(tmp2==tmp1 && date[wordCnt].num<255){
                date[wordCnt].num++;
            }
            else if(tmp2==tmp1 && date[wordCnt].num==255){
                wordCnt++;
                date[wordCnt].zifu=tmp2;
                date[wordCnt].num++;
            }
            tmp1=tmp2;
        }
        printf("case #%d:\n",i);
        for(int m=0;m<=wordCnt;m++){
            printf("%d%c",date[m].num,date[m].zifu);
        }
        printf("\n");

    }

    return 0;
}
