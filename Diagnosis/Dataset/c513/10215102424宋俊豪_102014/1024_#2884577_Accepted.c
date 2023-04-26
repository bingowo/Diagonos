#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[12];
    int num;
} tt;

int cmp(const void *a,const void *b)
{
    tt *ax=(tt*)a;
    tt *bx=(tt*)b;
    if (ax->num==bx->num)
        return strcmp(ax->s,bx->s);
    else
        return -(ax->num-bx->num);

}
int main()
{
    int n,stu,t,t1,score,a[12],f;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {   int cnt=0;
        scanf("%d%d%d",&stu,&t,&score);
        for(int j=1; j<t+1; j++)
            scanf("%d",&a[j]);
        tt* p=(tt*)malloc(stu*sizeof(tt));
        for (int j=0; j<stu; j++)
        {   p[j].num=0;
            scanf("%s",p[j].s);
            scanf("%d",&t1);
            for(int q=0; q<t1; q++)
            {
                scanf("%d",&f);
                p[j].num+=a[f];
            }
            if(p[j].num>=score)
                cnt++;
        }
        qsort(p,stu,sizeof(p[0]),cmp);
        printf("case #%d:\n",i);
        printf("%d\n",cnt);
        for(int j=0;j<cnt;j++)
            printf("%s %d\n",p[j].s,p[j].num);
        free(p);
    }
}
