#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T;
    scanf("%d",&T);
    for (int i=0;i<T;i++)
    {
        printf("case #%d:\n",i);
        int r,c,n,k;
        int cnt=0,sum=0;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int **matrix=(int**)calloc(r,sizeof(int*));
        for (int j=0;j<r;j++)
            matrix[j]=(int*)calloc(c,sizeof(int));
        for (int j=0;j<n;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            matrix[a-1][b-1]=1;
        }
        for(int x1=0; x1<r; x1++) {
			for(int y1=0; y1<c; y1++) {
				for(int x2=x1; x2<r; x2++) {
					for(int y2=y1; y2<c; y2++) {
						int ans=0;
						for(int x=x1; x<=x2; x++) {
							for(int y=y1; y<=y2; y++) {
								if(matrix[x][y]==1)
									ans++;
							}
						}
						if(ans>=k)
							sum++;
					}
				}
			}
        }
        printf("%d\n",sum);

    }
    return 0;
}
