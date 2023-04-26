#include<stdio.h>
int main()
{
    int number;
    scanf("%d",&number);
    for(int i=0;i<number;i++)
    {
        int r,c,n,k0;
        scanf("%d %d %d %d",&r,&c,&n,&k0);
        int a[r][c];
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                a[j][k]=0;
            }
        }
        for(int j=0;j<n;j++){
            int x,y;
            scanf("%d %d",&x,&y);
            a[x-1][y-1]=1;
        }
        int N=0;
        for(int j=0;j<r;j++){
            int m=j;
            for(int k=0;k<c;k++){
                int d=k;
                for(int p=0;p+m<r;p++){
                	int x=p;
                    for(int q=0;q+d<c;q++){
                        int y=q;
                        int num=0;
                        for(int l=0;l<=x;l++){
                        	for(int w=0;w<=y;w++){
                        		num+=a[m+l][d+w];
							}
						}
						if(num>=k0){
							N++;
						}
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",N);
    }
    return 0;
}