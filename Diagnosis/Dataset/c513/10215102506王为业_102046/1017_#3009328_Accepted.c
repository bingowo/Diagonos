//simu\1017.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
/*
    
*/


#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;
int beforeLEFT=FALSE;
int Roman[7]={1,5,10,50,100,500,1000};
int RoPosSear(char c)//return pos in Roman
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
    else if(c==')')
        return -500;
    else if(c=='(')
        return 1200;
    else{
        printf("Roman_sear_error");
        return -1;
    }
}
char strnum[55];
int NumRoPos(int i)//give pos in strnum:return pos in Roman
{
    return RoPosSear(strnum[i]);
}

int canPOSleftMinus(int pos)
{
    if(beforeLEFT){
        return TRUE;
    }
    /*
    switch(strnum[pos-1]){
    case 'I':
    case 'X':
    case 'C':
        break;
    default:
        return FALSE;
    }*/
    if(RoPosSear(strnum[pos])-RoPosSear(strnum[pos-1])<=2)
        return TRUE;
    else
        return FALSE;
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    scanf("%s",strnum);
    int slen=strlen(strnum);
    int i=slen-1;//from big to small
    int temlen=0;
    long long coe=1;
    
    long long ans=0;
    while(i>=1){
        if(strnum[i]==')'){
            beforeLEFT=FALSE;
            coe*=1000;
            --i;
        }else if(strnum[i]=='('){
            coe/=1000;
            --i;
            beforeLEFT=TRUE;
        }else{
            if(NumRoPos(i)>NumRoPos(i-1)&&canPOSleftMinus(i)){//normal situation
                ans+=coe*Roman[NumRoPos(i)];
                ans-=coe*Roman[NumRoPos(i-1)];
                i-=2;
            }else{
                ans+=coe*Roman[NumRoPos(i)];
                --i;
            }
            beforeLEFT=FALSE;
        }
    }
    if(i>=0){
        if(strnum[i]==')'){
            coe*=1000;
            --i;
        }else if(strnum[i]=='('){
            coe/=1000;
            --i;
        }else{
            if(beforeLEFT){
                ans-=coe*Roman[NumRoPos(i)];
            }
            else{
                ans+=coe*Roman[NumRoPos(i)];
            }
            --i;
        }
    }
    printf("%lld",ans);
}