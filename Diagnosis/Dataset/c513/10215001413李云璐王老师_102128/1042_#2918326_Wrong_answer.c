#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int cmp(const void*a1,const void*a2)
{
    char *a=(char*)a1;
    char *b=(char*)a2;
    return strcmp(a,b);
    
}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int a[129]={0};
        char b[18]={},c[18]={};
        scanf("%s\n",b);
        int lenb=strlen(b),l=0,k;
        for(k=0;k<lenb;k++)
        {
            if(a[b[k]]==0) {c[l]=b[k];l++;a[b[k]]=1;}
        }
       
        qsort(c,l,sizeof(char),strcmp);
         //c中存储非重复排序后的字母，共l个，共2的l次方-1种输出(er)
        int er=pow(2,l)-1;
        //er的二进制表示是l位1
        printf("case #%d:\n",i);
        char ans[er+1][l+1];
        for(int h=1;h<=er;h++)
       { 
           int m=er&h,g,r;
           for(g=0,r=0;g<l;g++)
           if((m>>g)&1) {ans[h-1][r]=c[g];r++;}
           ans[h-1][r]='\0';
       }
       qsort(ans,er,sizeof(char*),cmp);
       for(int t=0;t<er;t++)
       printf("%s\n",ans[t]);
    }
        return 0;
}