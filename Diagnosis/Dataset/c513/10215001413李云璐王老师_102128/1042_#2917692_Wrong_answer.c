#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
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
           int m=er&h;
           for(int g=0;g<l;g++)
           if((m>>g)&1) ans[h-1][g]=c[g];
       }
       for(int p=0;p<er-1;p++)
       for(int o=0;o<er-1-p;o++)
       if(strcmp(ans[o],ans[o+1])>0) 
       {char zh[l+1];strcpy(zh,ans[o]);strcpy(ans[o],ans[o+1]);strcpy(ans[o+1],zh);}
       for(int t=0;t<er;t++)
       printf("%s\n",ans[t]);
    }
        return 0;
}