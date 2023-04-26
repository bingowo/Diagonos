#include <stdio.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0; j<T; ++j) {
        int n, cnt = 0;
        scanf("%d",&n);
        for(int w=0; w*4<=n; ++w)
            for(int x=0; 3*x<=n-4*w; ++x)
                for(int y=0; 2*y<=n-4*w-3*x; ++y)
                    ++cnt;
        printf("%d\n",cnt);
    }
    return 0;
}
