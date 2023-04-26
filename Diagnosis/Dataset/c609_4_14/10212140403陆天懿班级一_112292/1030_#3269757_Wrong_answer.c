#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>

typedef long long ll;
typedef unsigned long long ull;

#define N 105
#define L 26
double ni[256];
char str[N];

int IsClose(double a, double b){return fabs(a-b)<1e-6;}
char ChUpr(char c){return c>='a'&&c<='z'?c+'A'-'a':c;}

int Cmp(const char* pa,const char* pb){
    int a=*pa,b=*pb;
    //if(labs(a-b)=='a'-'A') return b-a;
    if(!IsClose(ni[a],ni[b])) return ni[b]-ni[a];
    if(ChUpr(*pa)!=ChUpr(*pb)) return ChUpr(*pa)-ChUpr(*pb);
    return b-a;
}

int main(){
    for(int i=0;i<256;i++) ni[i]=-1;

    int pros;
    scanf("%d",&pros);
    for(int cnt=0;cnt<pros;cnt++){
        for(int i=0;i<L;i++){
            scanf("%lf",ni+'a'+i);
            ni['A'+i]=ni['a'+i];
        }
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),Cmp);
        printf("case #%d:\n",cnt);
        printf("%s\n",str);
    }

    return 0;
}
