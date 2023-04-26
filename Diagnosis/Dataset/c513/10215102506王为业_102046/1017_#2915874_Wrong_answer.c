//digsys\1017.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
/*

*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

int Roman[7]={1,5,10,50,100,500,1000};
int RoPosSear(char c)
{
    if(c=='I')
        return 0;
    else if(c=='V')
        return 1;
    else if(c=='X')
        return 2;
    else if(c=='L')
        return 3;
    else if(c=='C')
        return 4;
    else if(c=='D')
        return 5;
    else if(c=='M')
        return 6;
    else if(c=='(')
        return -2;
    else{
        printf("Roman_sear_error");
        return -1;
    }
}
char strnum[55];
int NumRoPos(int i)
{
    return RoPosSear(strnum[i]);
}
int canPOSleftMinus(int pos)
{
    switch(strnum[pos-1]){
    case 'I':
    case 'X':
    case 'C':
        break;
    default:
        return FALSE;
    }
    if(RoPosSear(strnum[pos])-RoPosSear(strnum[pos-1])==2)
        return TRUE;
    else
        return FALSE;
}


long long sum=0;
int numlen;

long long areaRoman(int ipos,int endpos)
{
    long long temsum=0;
    int jpos=ipos;
    while(ipos<endpos-1){
        if(canPOSleftMinus(ipos+1)){
            temsum-=Roman[RoPosSear(strnum[ipos])];
            ++ipos;
            ++jpos;
        }
        for(;jpos<endpos;++jpos){
            if(jpos==endpos-1){
                ++jpos;
                break;
            }
            if(NumRoPos(jpos)<NumRoPos(jpos+1)){
                if(canPOSleftMinus(jpos+1)){
                    break;
                }else{
                    ++jpos;
                    break;
                }
            }
        }
        for(int tk=ipos;tk<jpos;++tk){
            temsum+=Roman[RoPosSear(strnum[tk])];
        }
        ipos=jpos;
    }
    if(ipos==endpos-1)
        temsum+=Roman[RoPosSear(strnum[endpos-1])];
    //*Pjpos=jpos;
    return temsum;
}
long long find_kuohao(int begin,int end)
{
    long long sumnow=0;
    int no_kuohao=TRUE;
    for(int i=begin;i<end;++i){
        if(strnum[i]=='('){
            no_kuohao=FALSE;
            int t=0,tpos=i+1;
            while(tpos<end){
                if(strnum[tpos]=='(')
                    ++t;
                else if(strnum[tpos]==')'){
                    if(t==0){
                        sumnow+=find_kuohao(i+1,tpos);
                        break;
                    }else{
                        --t;
                    }
                }
                ++tpos;
            }
            break;//key
        }
    }
    if(no_kuohao){
        sumnow=areaRoman(begin,end);
    }
    return 1000*sumnow;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    scanf("%s",strnum);
    numlen=strlen(strnum);
    sum+=areaRoman(0,numlen);
    printf("%lld",sum);
}
