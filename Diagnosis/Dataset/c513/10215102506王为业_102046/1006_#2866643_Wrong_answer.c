#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define LOCAL
char instr[100];
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int T,slen,tem,sum;
    scanf("%d",&T);
    for(int iT=0;iT<T;++iT){
        scanf("%s",instr);
        printf("case #%d:\n",iT);
        sum=0;
        tem=1;
        for(int i=strlen(instr)-1;i>=0;--i){
            sum+=tem*(instr[i]=='-'?-1:instr[i]-'0');
            tem*=3;
        }
        printf("%d\n",sum);
    }
    return 0;
}
