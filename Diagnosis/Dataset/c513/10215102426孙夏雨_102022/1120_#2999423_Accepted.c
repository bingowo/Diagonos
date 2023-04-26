#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int r=0,c=0,n=0,k=0;
        scanf("%d %d %d %d",&r,&c,&n,&k);
        int p[10][2]={0};
        for(int i=0;i<n;i++){
            int x0=0,y0=0;
            scanf("%d %d",&x0,&y0);
            p[i][0]=x0;
            p[i][1]=y0;
        }
        int kuan=1,gao=1;
        int all=0;
        for(;gao<=r;gao++){
            for(kuan=1;kuan<=c;kuan++){
                if(kuan*gao<k) continue;
                int x=0,y=0;
                for(;x+gao<=r;x++){
                    for(y=0;y+kuan<=c;y++){
                        int kk=0;
                        for(int j=0;j<n;j++){
                            if(p[j][0]>x&&p[j][0]<=x+gao&&p[j][1]>y&&p[j][1]<=y+kuan){
                                kk++;
                            }
                        }
                        if(kk>=k) all++;
                    }
                }
            }
        }
        printf("case #%d:\n",t);
        printf("%d\n",all);
    }
    return 0;
}
