#include <stdio.h>
int L[10][10];
int check(int x1,int x2,int y1,int y2,int target)
{
    int num=0;
    for(int i=x1;i<=x2;i++){
        for(int j=y1;j<=y2;j++){
            if(L[j][i]==1) num++;
        }
    }
    if(num>=target) return 1;
    else return 0;
}
int main()
{
    int cnt;
    scanf("%d",&cnt);
    for(int mm=0;mm<cnt;mm++){
        int r,c,n,k;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                L[i][j]=0;
            }
        }
        
        scanf("%d %d %d %d",&r,&c,&n,&k);
        for(int i=0;i<n;i++){
            int x=0,y=0;
            scanf("%d %d",&x,&y);
            L[y-1][x-1]=1;
        }
        
        int x1=0,x2=0,y1=0,y2=0,res=0;
        for(x1=0;x1<r;x1++){
            for(x2=x1;x2<r;x2++){
                for(y1=0;y1<c;y1++){
                    for(y2=y1;y2<c;y2++){
                        if(check(x1,x2,y1,y2,k)==1) res++;
                    } } } }
        printf("case #%d:\n",mm);
        printf("%d\n",res);
    }
}