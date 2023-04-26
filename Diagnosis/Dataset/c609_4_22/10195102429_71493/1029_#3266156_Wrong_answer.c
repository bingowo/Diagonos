#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y;

    scanf("%d",&x);
    int a[x];
    for(int i=0;i<x;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&y);
    int b[y];
    for(int j=0;j<y;j++){
        scanf("%d",&b[j]);
    }
    int c[y];
    int i,n=0;
    for(i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(b[j]==a[i]){
                c[n]=b[j];
                b[j]=0;
                n++;
            }
        }
    }
    int m,temp;
    m=y;
    for (int z = 0; z < y; z++) {
		int exchange = 0;           //记录这一轮会不会有数据的交换；
		for (int j = 0; j < m-1; j++) {
			if (b[j] > b[j + 1]) {
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
				exchange = 1;
			}
		}
		m--;
		if (!exchange)  //若没有数据的交换，则数据已经排列完毕，跳出循环；
			break;
	}
	for(int k=0;k<n;k++){
        b[k]=c[k];
	}
	for(int h=0;h<y;h++){
        printf("%d ",b[h]);
	}

    return 0;
}