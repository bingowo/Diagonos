#include <stdio.h>
#include <stdlib.h>
int s[120][100];
int main()
{
    int n,a,m;
    scanf("%d",&n);
    s[0][0]=1;s[1][0]=1;
    s[0][1]=0;s[1][1]=1;
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        for(int i=2;i<=a;i++){
            s[i][0]=s[i-1][0]>s[i-2][0]?s[i-1][0]:s[i-2][0];
            m=0;
        for(int j=1;j<=s[i][0];j++){
            s[i][j]+=s[i-1][j]+s[i-2][j];
            s[i][j+1]+=s[i][j]/10;
            s[i][j]%=10;
            m=s[i][j+1];
        }
        if(m!=0)s[i][0]++;

    }
    printf("case #%d:\n",i);
    for(int k=s[a][0];k>=1;k--)printf("%d",s[a][k]);
    printf("\n");
    }
    return 0;
}
