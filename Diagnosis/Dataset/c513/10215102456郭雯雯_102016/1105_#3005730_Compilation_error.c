#include<stdio.h>

int trans(int *num,int l){
    int ans=0;
    for(int i=0;i<l;i++){
        ans*=2;
        ans+=num[i];
    }
    return ans;
}

int max(int a,int b){
    if(a>=b)return 1;
    else return 0;
}

int lbp(int l[][],int m,int n){
    int num[17],k=0,a=l[m][n],ans=256;
    for(int i=0;i<17;i++)num[i]=0;
    num[0]=max(l[m-1][n-1],a);
    num[1]=max(l[m-1][n],a);
    num[2]=max(l[m-1][n+1],a);
    num[3]=max(l[m][n+1],a);
    num[4]=max(l[m+1][n+1],a);
    num[5]=max(l[m][n+1],a);
    num[6]=max(l[m+1][n-1],a);
    num[7]=max(l[m][n-1],a);
    for(int i=0;i<17;i++)printf("%d\n",num[i]);
    //for(int i=0;i<=8;i++){
    //    int k=trans(num,i+8);
    //    if(k<ans)ans=k;
    //    num[i+8]=num[i];
    //    num[i]=0;
    //}
    return ans;
}

int main(){
    int w,h;
    scanf("%d %d",&w,&h);
    int num[h][w],ans[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++){
            scanf("%d",&num[i][j]);
            ans[i][j]=0;
        }
    for(int i=1;i<h-1;i++)
        for(int j=1;j<w-1;j++)ans[i][j]=lbp(num,i,j);
    for(int i=1;i<h-1;i++)
        for(int j=1;j<w-1;j++){
            printf("%d",ans[i][j]);
            if(j==w-2)printf("\n");
            else printf(" ");
        }
    return 0;
}