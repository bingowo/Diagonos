#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a,const void* b)
{
    return *(char*)a-*(char*)b;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char s[22]={'0'};
        scanf("%s",s+1);
        int minx='9'+1,pos,xi;
        // 从后往前找比后一位小的数
        for(pos=strlen(s)-1;pos>0&&s[pos-1]>=s[pos];pos--);
        int p=s[pos-1];
        // 该数与最后一位交换
        for(int j=strlen(s)-1;j>=pos;j--){
            if(s[j]>p&&s[j]<minx){
                minx=s[j];
                xi=j;
            }
        }
        s[pos-1]=minx;
        s[xi]=p;
        //交换后的位置从小到大排列
        qsort(s+pos,strlen(s)-pos,sizeof(s[0]),cmp);
        printf("case #%d:\n%s\n",t,s[0]=='0'?s+1:s);
    }

    return 0;
}
