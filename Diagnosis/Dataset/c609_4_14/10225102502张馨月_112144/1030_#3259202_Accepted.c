#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{
    char ch1,ch2;
    int p1,p2;
    ch1=*((char*)a);
    ch2=*((char*)b);

}

int main()
{
    int T;//问题数
    scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        double p[27];
        int i;
        for(i=0;i<26;i++)
            scanf("%lf",&p[i]);

        int cmp(const void*a,const void*b)
        {
            char ch1,ch2;
            int p1,p2;//ch1,2在字母表中的位置
            ch1=*((char*)a);
            ch2=*((char*)b);
            if(ch1>='a'&&ch1<='z') p1=ch1-'a'; else p1=ch1-'A';
            if(ch2>='a'&&ch2<='z') p2=ch2-'a'; else p2=ch2-'A';
            if(p[p2]>p[p1]) return 1;
            else if(fabs(p[p2]-p[p1])<1e-8){
                if(p1==p2) return ch2-ch1;//A65,a97
                else return p1-p2;
            }
            else return -1;
        }

        char str[101];
        scanf("%s",str);

        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("case #%d:\n",t);
        printf("%s\n",str);
    }
    return 0;
}
