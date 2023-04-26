
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


int erase_num(const char *or_s,int tslen)
{
    char tstr[105];
    strcpy(tstr,or_s);
    int not_end=TRUE;
    int ret=0;
    while(not_end){
        not_end=FALSE;//set it false;if something can be erased,set it true
        if(tslen<=1){
            break;
        }
        int left=1;
        while(left<tslen){
            if(tstr[left-1]==tstr[left]){
                not_end=TRUE;
                int begin=left-1;
                ++left;
                while(left<tslen&&tstr[left-1]==tstr[left]){
                    ++left;
                }//search the end of the string
                for(int i=left;i<tslen;++i){
                    tstr[i-left+begin]=tstr[i];
                }
                ret+=left-begin;
                tslen-=left-begin;
                left=begin;//adapt to the change
                tstr[tslen]='\0';
            }
            ++left;//key
            
        }
    }
    return ret;
}

char str[105];

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    getchar();
    for(int iT=0;iT<T;++iT){
        printf("case #%d:\n",iT);
        
        scanf("%s",str);
        int slen=strlen(str);
        int most_dels=0;
        for(int ins_pos=0;ins_pos<=slen;++ins_pos){
            char temstr[105];
            strcpy(temstr,str);
            int temlen=slen;//create temstr
            for(int j=temlen-1;j>=ins_pos;--j){
                temstr[j+1]=temstr[j];
            }//move add in the right
            temstr[++temlen]='\0';//update string
            //sort three situations:A,B,C
            for(char add='A';add<='C';++add){
                temstr[ins_pos]=add;//complete insertation
                int tmaxdel=erase_num(temstr,temlen);
                if(tmaxdel>most_dels)
                    most_dels=tmaxdel;
            }
        }
        printf("%d\n",most_dels);
    }
}

