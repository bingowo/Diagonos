#include<stdio.h>
#include<string.h>
int main(){
    int t;
    int cas=0;
    scanf("%d",&t);
    while(t--){
        char in[61];
        scanf("%s",in);
        int albet[128];
        for(int i=0;i<128;i++)albet[i]=-1;
        int digit=1;
        int out[61]={0};
        albet[in[0]]=1;
        out[0]=1;
        for(int i=1;i<strlen(in);i++){
            if(albet[in[i]]==-1){
                if(digit==1)albet[in[i]]=0;
                else albet[in[i]]=digit;
                digit++;
            }
            out[i]=albet[in[i]];
        }
        if(digit<2)digit=2;
        int ret=0;
        for(int i=0;i<strlen(in);i++){
            ret=ret*digit+out[i];
        }
        printf("case #%d:\n%d\n",cas++,ret);
    }
}
