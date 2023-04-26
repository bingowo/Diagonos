#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void*a1,const void*a2)
{
    int*a=*(int**)a1;
    int*b=*(int**)a2;
    
    if(a[0]!=b[0]) return b[0]-a[0];
    else if(a[1]!=b[1]) return b[1]-a[1];
    else if(a[2]!=b[2]) return b[2]-a[2];
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int m;
        scanf("%d\n",&m);
        int s[m][50];
        for(int k=0;k<m;k++)
        {
            for(int e=0;e<50;e++)
            s[k][e]=0;
        }//初始化
        int l[m]={0};
        for(int k=0;k<m;k++)
        {
            
            while((scanf("%d",&s[k][l[k]])!=EOF&&s[k][l[k]]!=-1)) l[k]++;
        }//输入，l[k]对应s[k]行的数字个数
        qsort(s,m,sizeof(s[0]),cmp);//排序
        for(int k=0;k<m;k++)
    {
        for(int p=0;p<l[k];p++)
        {
            printf("%d ",s[k][p]);
        }
        printf("\n");//输出
    }
        
    }
}