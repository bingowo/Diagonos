#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    long long *a1 = (long long*)a,*b1 = (long long*)b;
    if(a1[2] == b1[2])return a1[0] > b1[0]?-1:1;
    else return a1[2] > b1[2]?-1:1;
}

int main()
{
    int m,n;
    long long a[1000][3];
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%lld%lld",&a[i][0],&a[i][1]);
        a[i][2] = 2 * a[i][0] * a[i][1];
    }
    qsort(a,n,sizeof(a[0]),cmp);
    long long sum,ans = 0;
    for(int i = 0;i < n;i++){
        int count = 1;
        sum = a[i][0] * a[i][0] + a[i][2];
		for (int j = 0; j < n && count < m; j++)
		{
			if (i == j || a[j][0] > a[i][0])  continue;
			sum += a[j][2];
			count++;
		}
		if (count == m)
            ans = sum > ans?sum:ans;
    }
    printf("%lld",ans);
    return 0;
}
