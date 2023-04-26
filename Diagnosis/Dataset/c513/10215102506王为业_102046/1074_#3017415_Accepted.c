//simu\1074.c

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

#define MOD 210
#define MAX 1000000007

char str[110];
int Mkind[110][MOD]={0};

int stoi(int l,int r)
{
    int ret=0;
    while(l<=r){
        ret*=10;
        ret+=str[l]-'0';
        ret%=MOD;
        ++l;
    }
    return ret;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        memset(Mkind,0,110*sizeof(Mkind[0]));
        scanf("%s",str);
        int slen=strlen(str);
        for(int beg=0;beg<slen;++beg){
            int m_num=stoi(0,beg);
            ++Mkind[beg][m_num];//searching as a whole
            Mkind[beg][m_num]%=MAX;
            for(int j=0;j<beg;++j){
                m_num=stoi(j+1,beg);
                for(int k=0;k<MOD;++k){
                    Mkind[beg][(k+MOD+m_num)%MOD]+=Mkind[j][k];
                    Mkind[beg][(k+MOD+m_num)%MOD]%=MAX;
                    Mkind[beg][(k+MOD-m_num)%MOD]+=Mkind[j][k];
                    Mkind[beg][(k+MOD-m_num)%MOD]%=MAX;
                }
            }
        }
        int ans=0;
        for(int i=0;i<MOD;++i){
            if(i%2==0||i%3==0||i%5==0||i%7==0){
                ans+=Mkind[slen-1][i];
                ans%=MAX;
            }
        }
        printf("%d\n",ans);
    }
}