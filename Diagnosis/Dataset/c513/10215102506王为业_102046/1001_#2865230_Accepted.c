#include <stdio.h>
#include <stdlib.h>
char ans[40];
int pos=0;
void trans(int N,int R)
{

    pos=0;
    if(N==0){
        ans[pos++]='0';
        ans[pos]='\0';
        return;
    }
    int tem;
    int pluszero=1;
    if(N<0){
        pluszero=0;
        N=-N;
    }
    while(N!=0){
        tem=N%R;
        if(tem<10)ans[pos++]=tem+'0';
        else ans[pos++]=tem-10+'A';
        N/=R;
    }
    if(!pluszero){
        ans[pos++]='-';
    }
    if(ans[pos])ans[pos]='\0';

}
int main()
{
    int T,N,R;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&R);
        trans(N,R);
        for(int i=pos-1;i>=0;--i){
            putchar(ans[i]);
        }putchar('\n');
    }
    return 0;
}
