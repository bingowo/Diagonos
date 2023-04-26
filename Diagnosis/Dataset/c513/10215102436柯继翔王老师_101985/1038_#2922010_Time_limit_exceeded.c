#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,k,a[200][200];
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++)
            scanf("%d",&a[i][j]);
    int s = 0;
    for(int i = 0;i < n;i++)
        for(int j = 0;j < m;j++){
            for(int r = 1;i + r < n && j + r < m;r++){
                int sum = 0;
                for(int x = 0;x <= r;x++)
                    for(int y = 0;y <= r;y++)
                        if(x + y <= r)sum += a[i + x][j + y];
                if(sum >= k)s++;
            }
            for(int r = 1;i - r >= 0 && j + r < m;r++){
                int sum = 0;
                for(int x = 0;x <= r;x++)
                    for(int y = 0;y <= r;y++)
                        if(x + y <= r)sum += a[i - x][j + y];
                if(sum >= k)s++;
            }
            for(int r = 1;i + r < n && j - r >= 0;r++){
                int sum = 0;
                for(int x = 0;x <= r;x++)
                    for(int y = 0;y <= r;y++)
                        if(x + y <= r)sum += a[i + x][j - y];
                if(sum >= k)s++;
            }
            for(int r = 1;i - r >= 0 && j - r >= 0;r++){
                int sum = 0;
                for(int x = 0;x <= r;x++)
                    for(int y = 0;y <= r;y++)
                        if(x + y <= r)sum += a[i - x][j - y];
                if(sum >= k)s++;
            }
        }
        printf("%d",s);
    return 0;
}
