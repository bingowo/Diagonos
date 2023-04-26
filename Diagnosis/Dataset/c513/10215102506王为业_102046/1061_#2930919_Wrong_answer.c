//string\1061.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <ctype.h>
/*
    one word pressure test
*/
//#define LOCAL
#define TRUE 1
#define FALSE 0
typedef long long LL;
typedef unsigned long long ULL;

struct sANDd{
    char str[17];
    ULL dig;
};
typedef struct sANDd sd;
sd arr[10010];

unsigned char temrelation[100];
int sear(char x)
{
    if('0'<=x&&x<='9')
        return x-'0';
    else if('a'<=x&&x<='z')
        return x-'a'+10;
    else
        return x-'A'+60;//bigger array,no brain
}
ULL getMINnum(char str[])
{
    memset(temrelation,-1,100*sizeof(temrelation[0]));
    char *sp=str;
    char fir=*sp;
    if(*sp)
        temrelation[sear(*sp++)]=1;

    if(*sp=='\0')return 1;

    while(*sp==fir)++sp;
    int nowsize=2;
    if(*sp!='\0'){
        temrelation[sear(*sp++)]=0;
        while(*sp){
            temrelation[sear(*sp++)]=nowsize++;
        }
    }
    --sp;//before this,*sp=0
    ULL tem=1,ret=0;
    while(sp>=str){
        ret+=tem*temrelation[sear(*sp)];
        tem*=nowsize;
        --sp;
    }
    return ret;
}

int comp(sd*x,sd*y)
{
    if(x->dig==y->dig)
        return strcmp(x->str,y->str);
    else
        return x->dig>y->dig?1:-1;
}

int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int N;
    char str[17];
    scanf("%d",&N);
    for(int iN=0;iN<N;++iN){
        scanf("%s",&arr[iN].str);
        arr[iN].dig=getMINnum(arr[iN].str);
    }
    qsort(arr,N,sizeof(arr[0]),comp);
    for(int iN=0;iN<N;++iN){
        printf("%s\n",arr[iN].str);
    }
}
