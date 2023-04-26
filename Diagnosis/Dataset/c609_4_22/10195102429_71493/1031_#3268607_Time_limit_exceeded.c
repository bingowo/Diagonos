#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int cas=0;cas<t;cas++){
        int n,m;
        scanf("%d %d",&n,&m);
        int a[1001];
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int l[21],u[21];
        for(int j=0;j<m;j++){
            scanf("%d %d",&l[j],&u[j]);
        }
        int sum[500501];
        int h=0;
        int k=0;
        int temp=0;
        while(k<n){
            for(int z=k;z<n;z++){
                temp+=a[z];
                sum[h]=temp;
                h++;
            }
            k++;
            temp=0;
        }
    int q,tmp;
    q=h;
    for (int w = 0; w < h; w++) {
		int exchange = 0;           //记录这一轮会不会有数据的交换；
		for (int r = 0; r < q-1; r++) {
			if (sum[r] > sum[r + 1]) {
				tmp = sum[r];
				sum[r] = sum[r + 1];
				sum[r + 1] = tmp;
				exchange = 1;
			}
		}
		q--;
		if (!exchange)  //若没有数据的交换，则数据已经排列完毕，跳出循环；
			break;
	}
	int num[21];
	for(int g=0;g<21;g++){
        num[g]=0;
	}
	int o;
	for(o=0;o<m;o++){
        for(int b=l[o]-1;b<=u[o]-1;b++){
                num[o]=num[o]+sum[b];
        }
	}
	printf("case #%d:\n",cas);
	for(o=0;o<m;o++){
        printf("%d\n",num[o]);
	}


    }
    return 0;
}
