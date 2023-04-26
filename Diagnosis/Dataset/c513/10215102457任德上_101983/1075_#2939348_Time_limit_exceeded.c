#include<stdio.h>
int a[200][200],b[200][200];
void find(int line,int row,int m,int n){
    int min=b[line+1][row]>b[line][row+1]?b[line][row+1]:b[line+1][row];
    b[line+1][row+1]=min+a[line+1][row+1];
    if(line<m-2)find(line+1,row,m,n);
    if(row<n-2)find(line,row+1,m,n);

}
int main(){
    int m,n,line=0,row=0,p=0;
    char s[400]={0};
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++){
        for(int k=0;k<n;k++)scanf("%d",&a[i][k]);
    }
    b[0][0]=a[0][0];
    for(int i=1;i<m;i++)b[i][0]=a[i][0]+b[i-1][0];
    for(int i=1;i<n;i++)b[0][i]=a[0][i]+b[0][i-1];
    find(0,0,m,n);
    printf("%d\n",b[m-1][n-1]);
    for(int i=m-1,k=n-1;i>=0&&k>=0;){
        if(i==0){s[p++]='R';k--;}
        else if(k==0){s[p++]='D';i--;}
        else if(b[i-1][k]<b[i][k-1]){s[p++]='D';i--;}
        else {s[p++]='R';k--;}
    }
    s[--p]=0;
    char *s1,*s2,c;
    s1=s;
    s2=s+p-1;
    while(s1<s2){
        c=*s1;
        *s1=*s2;
        *s2=c;
        s1++;
        s2--;
    }
    printf("%s",s);
    return 0;
}