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
        for(int j=1;j<=s[i][0];j++){
            m=s[i-1][j]+s[i-2][j];
            s[i][j]+=m%10;
            s[i][j+1]+=m/10;
        }
        if(m!=0)s[i][0]++;
    }
    printf("case #%d:\n",i);
    int i=s[a][0];
    while(s[a][i]==0&&i>1)i--;
    for(;i>=1;i--)printf("%d",s[a][i]);
    printf("\n");
    }
    return 0;
}
