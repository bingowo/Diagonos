#include <stdio.h>
#include <string.h>
char ans[100][50];
int m(int i,int k)
{
    if(i<k)
        return 0;
    else
        return i-k;
}
void add(int x,int y)
{
    int i,l1,l2;
    l1=strlen(ans[x]);
    l2=strlen(ans[y]);
    if(l1<l2){
        for(i=l1;i<l2;i++)
            ans[x][i]='0';
        l1=l2;
    }
    for(i=0;i<l2;i++){
        ans[x][i]=ans[x][i]+(ans[y][i]-'0');
        if(ans[x][i]>'9'){
            ans[x][i]=ans[x][i]-10;
            ans[x][i+1]+=1;
        }
    }
    if(ans[x][l1]==1)
        ans[x][l1]='1';
}
int main()
{
    int i,j,k,n;
    scanf("%d%d",&k,&n);
    memset(ans,0,sizeof(ans));
    ans[0][0]='0';
    ans[1][0]='1';
    for(i=2;i<n;i++)
        for(j=m(i,k);j<i;j++)
           add(i,j);
    for(i=strlen(ans[n-1])-1;i>=0;i--)
        printf("%c",ans[n-1][i]);
    printf("\n");
    return 0;
}
