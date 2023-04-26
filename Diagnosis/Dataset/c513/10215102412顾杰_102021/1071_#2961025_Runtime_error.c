#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
int main()
{
    int i,j,d,a,b,k,m,n,c=10007;long long ans=1;
    //int y[1001][1002];
    int(*y)[1002]=(int(*)[1002])malloc(1001*1002*sizeof(int));
    y[0][0]=0;y[0][1]=1;
    for(i=1;i<=1001;i++)
    {
        y[i][0]=0;
        for(j=1;j<=i;j++)
        {
            y[i][j]=y[i-1][j-1]+y[i-1][j];
            if(y[i][j]>=c)y[i][j]%=c;
        }
        y[i][j]=0;
    }//printf("%d%d%d",y[1][1],y[5][3],y[2][1]);
    scanf("%d",&d);
    for(i=0;i<d;i++)
    {
        scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
        if(a>=c)a%=c;if(b>=c)b%=c;
        for(j=0;j<n;j++){ans*=a;if(ans>=c)ans%=c;}
        for(j=0;j<m;j++){ans*=b;if(ans>=c)ans%=c;}
        printf("case #%d:\n%lld\n",i,ans*y[k+1][n+1]%c);
        ans=1;
    }
    free(y);
}
