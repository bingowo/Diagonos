#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,m=0,kw=0;
    scanf("%d %d %d",&n,&m,&kw);
    int** p=(int** )malloc(n*sizeof(int* ));
    int element=0,* p1;
    for(int i=0;i<n;i++){
        p1=(int* )malloc(m*sizeof(int));
        for(int j=0;j<m;j++){
            scanf("%d",&element);
            *(p1+j)=element;
        }
        *(p+i)=p1;
    }
    int ans=0;
    for(int x0=1;x0<=n;x0++){
        for(int y0=1;y0<=m;y0++){
            long long int s=(*(*(p+x0-1)+y0-1));
            for(int r=1;x0-r>0&&y0-r>0;r++){
                int lb=y0-r-1;
                int rb=y0;
                for(int y=lb;y<rb;y++) s+=(*(*(p+x0+y0-2-r-y)+y));
                if(s>=kw) ans++;
            }
            s=(*(*(p+x0-1)+y0-1));
            for(int r=1;x0-r>0&&y0+r<=m;r++){
                int rb=x0-r-1;
                int lb=x0;
                int y=y0-1;
                for(int x=rb;x<lb;x++,y++) s+=(*(*(p+x)+y));
                if(s>=kw) ans++;
            }
            s=(*(*(p+x0-1)+y0-1));
            for(int r=1;y0-r>0&&x0+r<=n;r++){
                int lb=y0-1-r;
                int rb=y0;
                int x=x0-1;
                for(int y=lb;y<rb;x++,y++) s+=(*(*(p+x)+y));
                if(s>=kw) ans++;
            }
            s=(*(*(p+x0-1)+y0-1));
            for(int r=1;x0+r<=n&&y0+r<=m;r++){
                int lb=y0-1+r;
                int rb=y0-1;
                for(int y=lb;y>=rb;y--) s+=(*(*(p+x0+y0-2+r-y)+y));
                if(s>=kw) ans++;
            }
        }
    }
    printf("%d",ans);
    for(int jj=0;jj<n;jj++){
        p1=p[jj];
        free(p1);
    }
    free(p);
    return 0;
}
