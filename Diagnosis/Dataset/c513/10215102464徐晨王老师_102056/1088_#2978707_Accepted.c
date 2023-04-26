#include <stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int m,n;
        scanf("%d%d",&m,&n);
        unsigned long long int m_n=1;
        for(int i = 1 ; i <= n; i ++){
            m_n =m_n * (m - i  + 1) / i;
        }
        printf("case #%d:\n%llu\n",t,m_n);
    }
    return 0;
}
