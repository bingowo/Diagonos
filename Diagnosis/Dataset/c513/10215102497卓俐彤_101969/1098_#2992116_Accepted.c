#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char str[101];
        scanf("%s",str);
        int lights[4]={0},num[4]={0};
        for(int i=0;i<4;i++)num[i]=-1;
        int index=0;
        char *p=str;
        while(*p){
            switch (*p) {
                case 'R':{
                    num[index%4]=0;
                    break;
                }
                case 'B':{
                    num[index%4]=1;
                    break;
                }
                case 'Y':{
                    num[index%4]=2;
                    break;
                }
                case 'G':{
                    num[index%4]=3;
                    break;
                }
                default:
                    break;
            }
            p++;index++;
        }
        int count=-1;
        int flag[4]={0};
        for(int i=0;i<4;i++){
            if(num[i]==-1)count=i;
            else flag[num[i]]=1;
        }
        if(count!=-1){
            for(int i=0;i<4;i++)if(!flag[i])num[count]=i;
        }
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='!'){
                lights[num[i%4]]++;
            }
        }
        printf("case #%d:\n",t);
        for(int i=0;i<4;i++){
            printf("%d%c",lights[i],i==3?'\n':' ');
        }
    }
    return 0;
}
