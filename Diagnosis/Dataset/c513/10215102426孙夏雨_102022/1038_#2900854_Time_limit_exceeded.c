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
    int squaremax=(n>m) ? m:n;
    int square=2,all=0;
    while(square<=squaremax){
        for(int k=0;k+square<=n;k++){
            for(int w=0;w+square<=m;w++){
                int sum=0,minu=0;
                for(int x=0;x<square;x++){
                    for(int y=0;y<square;y++){
                        sum+=(*(*(p+x+k)+y+w));
                    }
                }
                for(int kk=0;kk<square-1;kk++){
                    for (int ww=0;ww<square-1-kk;ww++){
                        minu+=(*(*(p+kk+k)+ww+w));
                    }
                }
                if((sum-minu)>=kw) all++;
                minu=0;
                for(int kk=square-1;kk>0;kk--){
                    for(int ww=kk-1;ww>=0;ww--){
                        minu+=(*(*(p+kk+k)+ww+w));
                    }
                }
                if((sum-minu)>=kw) all++;
                minu=0;
                for(int kk=0;kk<square-1;kk++){
                    for(int ww=square-1;ww>kk;ww--){
                        minu+=(*(*(p+kk+k)+ww+w));
                    }
                }
                if((sum-minu)>=kw) all++;
                minu=0;
                for(int kk=square-1;kk>0;kk--){
                    for(int ww=square-1;ww>=square-kk;ww--){
                        minu+=(*(*(p+kk+k)+ww+w));
                    }
                }
                if((sum-minu)>=kw) all++;
                minu=0;
            }
        }
        square++;
    }
    printf("%d",all);
    for(int jj=0;jj<n;jj++){
        p1=p[jj];
        free(p1);
    }
    free(p);
    return 0;
}
