#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char alpha[21];
        int num[10]={0},list[26]={0};
        scanf("%s",alpha);
        char *p=alpha-1;
        while(*++p){
            list[*p-'A']++;
        }
        int count=0;
        if(list['Z'-'A']){
            count=list['Z'-'A'];
            num[0]+=count;
            list['Z'-'A']-=count;
            list['E'-'A']-=count;
            list['R'-'A']-=count;
            list['O'-'A']-=count;
        }
        if(list['W'-'A']){
            count=list['W'-'A'];
            num[2]+=count;
            list['T'-'A']-=count;
            list['W'-'A']-=count;
            list['O'-'A']-=count;
        }
        if(list['U'-'A']){
            count=list['U'-'A'];
            num[4]+=count;
            list['F'-'A']-=count;
            list['O'-'A']-=count;
            list['U'-'A']-=count;
            list['R'-'A']-=count;
        }
        if(list['F'-'A']){
            count=list['F'-'A'];
            num[5]+=count;
            list['F'-'A']-=count;
            list['I'-'A']-=count;
            list['V'-'A']-=count;
            list['E'-'A']-=count;
        }
        if(list['O'-'A']){
            count=list['O'-'A'];
            num[1]+=count;
            list['O'-'A']-=count;
            list['N'-'A']-=count;
            list['E'-'A']-=count;
        }
        if(list['R'-'A']){
            count=list['R'-'A'];
            num[3]+=count;
            list['T'-'A']-=count;
            list['H'-'A']-=count;
            list['R'-'A']-=count;
            list['E'-'A']-=(2*count);
        }
        if(list['X'-'A']){
            count=list['X'-'A'];
            num[6]+=count;
            list['S'-'A']-=count;
            list['I'-'A']-=count;
            list['X'-'A']-=count;
        }
        if(list['S'-'A']){
            count=list['S'-'A'];
            num[7]+=count;
            list['S'-'A']-=count;
            list['E'-'A']-=(2*count);
            list['V'-'A']-=count;
            list['N'-'A']-=count;
        }
        if(list['G'-'A']){
            count=list['G'-'A'];
            num[8]+=count;
            list['E'-'A']-=count;
            list['I'-'A']-=count;
            list['G'-'A']-=count;
            list['H'-'A']-=count;
            list['T'-'A']-=count;
        }
        if(list['I'-'A']){
            count=list['I'-'A'];
            num[9]+=count;
            list['N'-'A']-=(2*count);
            list['I'-'A']-=count;
            list['E'-'A']-=count;
        }
        printf("cast #%d:\n",t);
        for(int i=0;i<10;i++){
            while(num[i]){
                printf("%d",i);
                num[i]--;
            }
        }
        printf("\n");
    }
    return 0;
}
