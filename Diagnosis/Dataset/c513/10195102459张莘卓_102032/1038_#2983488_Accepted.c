#include <stdio.h>

int min(int a, int b) {return a < b ? a : b;}

int main()
{
    int n, m, k, cnt = 0;
    scanf("%d %d %d",&n, &m, &k);
    int a[200][200] = {0};
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j) scanf("%d",&a[i][j]);
    
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j) {
            int sqr = a[i][j];
            for(int s=1; i+s<n && j+s<m; ++s) {
                for(int t=i; t<=i+s; ++t)
                    sqr += a[t][j+s-t+i];
                if(sqr >= k) {
                    cnt += min(n-i, m-j) - s;
                    break;
                }
            }
            sqr = a[i][j];
            for(int s=1; i+s<n && j-s>=0; ++s) {
                for(int t=i; t<=i+s; ++t)
                    sqr += a[t][j-s+t-i];
                if(sqr >= k) {
                    cnt += min(n-i,j+1) - s;
                    break;
                }
            }
            sqr = a[i][j];
            for(int s=1; i-s>=0 && j+s<m; ++s) {
                for(int t=i; t>=i-s; --t)
                    sqr += a[t][j+s-i+t];
                if(sqr >= k) {
                    cnt += min(i+1, m-j) - s;
                    break;
                }
            }
            sqr = a[i][j];
            for(int s=1; i-s>=0 && j-s>=0; ++s) {
                for(int t=i; t>=i-s; --t)
                    sqr += a[t][j-s+i-t];
                if(sqr >= k) {
                    cnt += min(i+1, j+1) - s;
                    break;
                }
            }
        }
    printf("%d\n",cnt);
    return 0;
}
