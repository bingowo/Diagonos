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
        int er=pow(2,l)-1,data=0;
        for(int k=0;k<l;k++)
        data+=pow(2,l);//data的二进制表示是l位1
        printf("case #%d:\n",i);
        for(int h=1;h<=er;h++)
       { 
           int m=data&h;
           for(int g=0;g<l;g++)
           if((m>>g)&1) printf("%c",c[g]);
           printf("\n");
        
        }
       
        
        
        
        
        
        
    }
        return 0;
}