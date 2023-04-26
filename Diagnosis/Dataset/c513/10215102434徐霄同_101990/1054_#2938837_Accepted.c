#include <stdio.h>
#include <string.h>
int sum(int lw[],int x,int y)
{
    int n,i;
    n=0;
    for(i=x;i<=y;i++)
        n=n+lw[i];
    return n;
}
int main()
{
    char s[2001];
    char w[1000][36];
    int lw[1000];
    int kg[35];
    int t,i,j,j0,k,p,x,y,z,l,n,m;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&m);
        getchar();
        gets(s);
        printf("case #%d:\n",i);
        l=strlen(s);
        memset(lw,0,sizeof(lw));
        n=0;
        j=0;
        while(j<=l){
            if(s[j]==' ')
                j++;
            else{
                w[n][lw[n]]=s[j];
                lw[n]++;
                if(j==l-1||s[j+1]==' '){
                    w[n][lw[n]]=0;
                    n++;
                }
                j++;
            }
        }
        j=0;
        while(j<n){
            j0=j;
            while(j0+1<n&&sum(lw,j,j0+1)+(j0+1-j)<=m)
                j0++;
            if(j0==n-1)
                for(k=j;k<=j0;k++){
                    printf("%s",w[k]);
                    if(k==j0)
                        printf("\n");
                    else
                        printf(" ");
                }
            else{
                x=m-sum(lw,j,j0);
                y=x/(j0-j);
                z=x%(j0-j);
                for(k=0;k<j0-j;k++){
                    kg[k]=y;
                    if(k>=j0-j-z)
                        kg[k]++;
                }
                for(k=j;k<=j0;k++){
                    printf("%s",w[k]);
                    if(k==j0)
                        printf("\n");
                    else
                        for(p=0;p<kg[k-j];p++)
                            printf(" ");
                }
            }
            j=j0+1;
        }
    }
    return 0;
}
