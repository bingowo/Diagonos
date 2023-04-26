#include <stdio.h>
#include <stdlib.h>
char input[70];
inpos=0;
int list[65];
int posof(char c)
{
    if('0'<=c&&c<='9')
        return c-'0';
    else if('A'<=c&&c<='Z')
        return 10-'A'+c;
    else
        return c-61;
}
unsigned long long getmini()
{

    if(inpos==1)return 1;//1
    if(inpos==2){
        if(input[0]==input[1])return 3;//11
        else return 2;//10
    }
    memset(list,-1,65*sizeof(int));
    int tem=input[0];
    list[posof(input[0])]=1;
    input[0]=1;
    int two_begin=1;
    while(input[two_begin]==tem){
        input[two_begin++]=1;
        if(two_begin==inpos)
            return (1<<inpos)-1;
    }
    list[posof(input[two_begin])]=0;
    input[two_begin++]=0;
    int R=2;
    for(int i=two_begin;i<inpos;++i){
        if((tem=list[posof(input[i])])!=-1){//NOT empty
            input[i]=tem;
        }else{//empty
            list[posof(input[i])]=R;
            input[i]=R++;
        }
    }
    tem=1;
    unsigned long long result=0;
    for(int j=inpos-1;j>=0;--j){
        result+=input[j]*tem;
        tem*=R;
    }
    return result;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int itime=0;itime<T;++itime){
        printf("case #%d:\n",itime);
        scanf("%s",input);
        inpos=strlen(input);
        printf("%llu\n",getmini());
    }
    return 0;
}
