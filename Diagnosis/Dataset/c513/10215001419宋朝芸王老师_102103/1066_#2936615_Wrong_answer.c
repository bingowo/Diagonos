#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d",&N);
    for(int R = 0; R < N; R++){

        int n,m,p,t;
        scanf("%d%d%d%d",&n,&p,&m,&t);

        if(abs(p-t) % 2 != abs(m) % 2){
            printf("0\n");
            continue;
        }

        else if(abs(p-t) > m){
            printf("0\n");
            continue;
        }

        else{
            long long int ans = 1;
            m = m - abs(p-t);
            int current = t;
            int cnt = 0;

            while(m > 0){
                if(current - cnt != 0 && current - cnt != n
                   && current + cnt != 0 && current + cnt != n)
                ans += 2;
                else ans += 1;
                m = m - 2;
                cnt++;
            }

            printf("%lld\n",ans);
        }

    }

    return 0;
}
