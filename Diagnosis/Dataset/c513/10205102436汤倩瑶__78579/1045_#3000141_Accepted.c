#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct {
char c;
int num;
}node;
node p[100005][105]={0};
int cmp(const void*a,const void*b)
{
    return *((int*)a)-*((int*)b);

}
int main()
{
    int n;
    scanf("%d",&n);
    char s[105];

    int fn[100005]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int k=0;
        p[i][k].c=s[0];
        p[i][k].num++;
        for(int j=1;s[j]!=0;j++)
        {
            if(s[j]!=s[j-1]){p[i][++k].c=s[j]; p[i][k].num++;}
            else {p[i][k].num++;}
        }
        fn[i]=k;
    }
int flag=0;
for(int i=1;i<n;i++){if(fn[i]!=fn[0])flag=1;}
for(int i=0;i<=fn[0]&&flag==0;i++)
{
    for(int j=1;j<n;j++)
    {
       // printf("%c %d",p[i][j].c,p[i][j].num);
        if(p[j][i].c!=p[0][i].c){flag=1;break;}
    }
    //printf("\n");
}
if(flag==1)printf("-1");
else{
        int ans=0;
    for(int j=0;j<=fn[0];j++)
{
    int a[105]={0};
    for(int i=0;i<n;i++)
    {
       a[i]=p[i][j].num;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    int mid=a[n/2];
  //  printf("%d\n",mid);
for(int k=0;k<n;k++)
{
    ans+=abs(a[k]-mid);
  //  printf("%d ",abs(a[k]-mid));
}

}
 printf("%d",ans);


}


}
