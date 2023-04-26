#include <stdio.h>
#include <stdlib.h>
double p[27];
int cmp(const void*a,const void*b);
int main()
{
    int T;
    scanf("%d",&T);

    for(int j=0;j<T;j++){

        for(int i=0;i<26;i++){
                scanf("%lf",&p[i]);
        }
        char str[101];
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",j);
        printf("%s\n",str);
    }
    return 0;
}
int cmp(const void*a,const void*b){
    char ch1,ch2;
    int p1,p2;
    // double p[27];
    ch1=*((char*)a);
    ch2=*((char*)b);
    if(ch1>='a' && ch1<='z') p1=ch1-'a';
    else p1=ch1-'A';
    if(ch2>='a' && ch2<='z') p2=ch2-'a';
    else p2=ch2-'A';
    if(p[p2]>p[p1]) return 1;
    else if(fabs(p[p2]-p[p1])<1e-8)//浮点数相等
        if(p1==p2) return ch1-ch2; //相同字母小写在大写前面
        else return p1-p2;               //不同字母，但使用频率相同，则按照字母表顺序排列
    else return -1;
}
