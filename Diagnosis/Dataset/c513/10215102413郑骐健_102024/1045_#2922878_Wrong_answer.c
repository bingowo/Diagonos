#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Alpha
{
    int a[26];
    char min [101];
    char init[101]
}alpha;
int cmp(const void *p1,const void*p2)
{
    return ((*(int*)p1)>(* (int*)p2))?1:0;//??
}


int main()
{
    alpha* p1 = (alpha*)malloc(sizeof(alpha)*1e5);
    int n;
    scanf("%d",&n);
    int *num[26];
    for(int i =0;i<26;i++)
    {
        num[i] = (int*)malloc(sizeof(int)*1e5);//用于存储各个原始字符串到最简字符串各个字母需要的变化次数
        memset(num[i],0,sizeof(int)*1e5);
    }
    for(int i = 0;i<n;i++)
    {
        scanf("%s",p1[i].init);
        int m =0;
        p1[i].min[0] = p1[i].init[0];


        for(int z = 1;z<strlen(p1[i].init);z++)
        {
            if(p1[i].min[m]!=p1[i].init[z])
            {
                m+=1;
                p1[i].min[m] = p1[i].init[z];
            }
            else
            {
                num[p1[i].min[m] -'a'][i]+=1;
            }

        }
    }

        int flag = 1;
        for(int i=1;i<n;i++)
        {
            if(strcmp(p1[0].min,p1[i].min))
            {
                printf("-1");
                flag = 0;
                break;
            }
        }
        double min_num = 0;
        double mid =0;
        if(flag)
        {
            for(int i = 0;i<26;i++)
            {

                qsort(num[i],n,sizeof(int),cmp);
                if(n%2 ==0) mid = (num[i][n/2]+num[i][n/2-1])/2.0;//
                else mid = num[i][n/2];
                for(int q = 0;q<n;q++)min_num += fabs(mid - num[i][q]);
            }
        printf("%d",(int)min_num);
        }

}
