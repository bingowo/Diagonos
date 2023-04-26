#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int m,n;
        scanf("%d%d",&m,&n);
        unsigned long long int mm=1,nn=1,m_n=1;
        /*for(int i=1;i<=m;i++){
            mm=mm*i;
        }*/
        //printf("%llu\n",mm);
        for(int i=1;i<=n;i++){
            nn=nn*i;
        }
        //printf("%llu\n",nn);
        for(int i=m-n+1;i<=m;i++){
            m_n=m_n*i;
        }
        //printf("%llu\n",m_n);
        printf("case #%d:\n%llu\n",t,m_n/nn);
    }
    return 0;
}
