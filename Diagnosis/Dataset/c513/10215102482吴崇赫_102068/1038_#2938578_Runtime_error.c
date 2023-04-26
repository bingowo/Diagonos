#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#define N 20005

int main()
{
    int row,col,k;
    scanf("%d %d %d\n",&row,&col,&k);
    int m[row][col+1];long long sum[row][col+1];
    for(int i=0;i<row;++i){
        for(int j=0;j<col+1;++j){
            m[i][j]=sum[i][j]=0;
        }
    }
    for(int i=0;i<row;++i){
        for(int j=1;j<col+1;++j){
            scanf("%d",&m[i][j]);
        }
    }
    for(int i=0;i<row;++i){
        for(int j=1;j<col+1;++j){
            sum[i][j]=sum[i][j-1]+m[i][j];
        }
    }
    int size=row<col?row:col;
    long long* ret=(long long*)malloc(100005*sizeof(long long));
    for(int i=0;i<100005;++i)ret[i]=0;
    int p=0;

    // up triangle
    for(int k=2;k<=size;++k){
        for(int i=0;i<=row-k;++i){
            for(int j=1;j<=col-k+1;++j){
               for(int w=0;w<k;++w)ret[p]+=sum[i+w][j+w]-sum[i+w][j-1];
               p++;
            }
        }
    }

    for(int k=2;k<=size;++k){
        for(int i=0;i<=row-k;++i){
            for(int j=k;j<=col;++j){
               for(int w=0;w<k;++w)ret[p]+=sum[i+w][j]-sum[i+w][j-1-w];
               p++;
            }
        }
    }

    //down triangle
    for(int k=2;k<=size;++k){
        for(int i=row-1;i>=k-1;--i){
            for(int j=col;j>=k;--j){
               for(int w=0;w<k;++w)ret[p]+=sum[i-w][j]-sum[i-w][j-w-1];
               p++;
            }
        }
    }

    for(int k=2;k<=size;++k){
        for(int i=0;i<=row-k;++i){
            for(int j=k;j<=col;++j){
               for(int w=0;w<k;++w)ret[p]+=sum[i+w][j-w]-sum[i+w][j-k];
               p++;
            }
        }
    }

    //for(int i=0;i<p;++i)printf("%d ",ret[i]);
    int cnt=0;
    for(int i=0;i<p;++i){
        if(ret[i]>=k)cnt++;
    }
    printf("%d",cnt);
    free(ret);
    return 0;
}
