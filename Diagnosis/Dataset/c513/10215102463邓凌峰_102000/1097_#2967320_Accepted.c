#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int can;
    char th[81];
}S;

void doIt(S *outPut,int row,int i,char tmpc){
    outPut[row].can=1;outPut[row].th[i]=tmpc;
    for(int j=0;j<201;j++){
        if(j!=row) outPut[j].th[i]=' ';
    }
}

int main()
{
    char tmps[81]={0};
    while(scanf("%s",tmps)!=EOF){
        S outPut[201]={0};
        int row=100;
        for(int i=0;i<strlen(tmps);i++){
            if(i>0){
                if(tmps[i]>tmps[i-1]) row--;
                else if(tmps[i]<tmps[i-1]) row++;
            }
            doIt(outPut,row,i,tmps[i]);
        }

        for(int i=0;i<201;i++){
            if(outPut[i].can) printf("%s\n",outPut[i].th);
        }
    }




    return 0;
}
