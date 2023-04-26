#include <stdio.h>
#include <stdlib.h>
void Quicksort(int a[], int left, int right) {   //快排函数
	int temp;
	int mid = a[(left + right) / 2];            //找基准值
	int i = left;
	int j = right;
//在左侧找一个大于基准值的数，在右侧找一个小于基准数的数，然后交换位置
	while (i <= j) {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < right) Quicksort(a, i, right);        //递归
	if (j > left) Quicksort(a, left, j);           //递归
}

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
    Quicksort(sum, 0, h - 1);
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
