#include<stdio.h>
#include<string.h>
typedef struct
{
   int m;//十六进制开始的位置
   int l;//十六进制的长度
} sl;

int main()
{
    unsigned int i=0,j=0,k=0,t=0,sum,l=0,r;
    char s[10001]={0},b[107][107];
    sl a[100];
    scanf("%s",s);
    int len = strlen(s);
    for(i=0;i<len-1;i++)
    {
        if(s[i]=='0'&&s[i+1]=='x')
        {
            for(k = i+2,r = 0; (s[k] <= 'f'&&s[k] >= 'a')||(s[k] <= '9'&&s[k] >= '0'); r++,k++)
                b[j][r] = s[k];
            a[j].l = r;
            j++;
            
         }
    }
    l=j;//l为0x的个数
    if(l==0) printf("-1");
    else
    {
       for(j = 0; j < l; j++)
        {
            for(t=0,sum = 0;t<a[j].l;t++)
           {
               if(b[j][t] <= 'f'&&b[j][t] >= 'a')sum = sum*16 + b[j][t]-'a'+10;
               else if(b[j][t] <= '9'&&b[j][t] >= '0')sum = sum*16 + b[j][t]-'0';
           }
           printf("%d ",sum);
        }

    }


return 0;
}