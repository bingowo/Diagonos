#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmp1(const void* a,const void* b)
{
    char x=*((char *)a);
    char y=*((char *)b);
    return (int)(x-y);
}

int cmp2(const void* a,const void* b)
{
    char *x=*(char(*)[16])a;
    char *y=*(char(*)[16])b;
    int i=0 ;
    while(x[i]==y[i])i++;
    return (int)(x[i]-y[i]);
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        // 获取不重复的字母
        int table[130]={0};
        char x[20]={0};
        int d=0;
        char s[20];
        scanf("%s",s);
        for(int j=0;j<16;j++){
            if(table[s[j]]==0){
                table[s[j]]=1;
                x[d++]=s[j];
            }
        }
        // 将不重复字母排序，方便接下来操作
        qsort(x,strlen(x),sizeof(x[0]),cmp1);
        // 所有排列 注意：字符串设置要多一位，最后有终止符！！！
        char a[65535][17]={0};
        int l=pow(2,strlen(x))-1;
        // 按每一位上的1和0来获取全排列
        for(int j = 1;j <= l;j++){
            int n=0,w=0,t=j;
            while(t){
                if((t&1) == 1)a[j-1][w++]=x[n];
                n++;
                t/=2;
            }
        }
        // 排序
        qsort(a,l,sizeof(a[0]),cmp2);
        for(int j=0;j<l;j++){
            printf("%s\n",a[j]);
        }
    }
    return 0;
}


