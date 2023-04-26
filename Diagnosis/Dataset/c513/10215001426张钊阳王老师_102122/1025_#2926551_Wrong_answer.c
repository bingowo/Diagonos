#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st{
    char str[20];
    int num;
};

int main()
{
    int count(const char *a,int *dic,int l);
    int cmp(const void *a1,const void *b1);
    int dic[128]={0};
    int m;
    scanf("%d",&m);
    for(int z=0;z<m;z++)
    {
        int n,l;
        scanf("%d\n",&n);
        struct st* s=(struct st*)malloc(sizeof(struct st)*n);
        for(int k=0;k<n;k++)
        {
            scanf("%s",s[k].str);
            l=strlen(s[k].str);
            s[k].num=count(s[k].str,dic,l);
        }

        qsort(s,n,sizeof(s[0]),cmp);

        printf("case #%d:\n",z);
        for(int u=0;u<n;u++)
            printf("%s\n",s[u].str);
    }
    return 0;
}

int count(const char *a,int *dic,int l)
{
    int ans=0;
    for(int i=0;i<l;i++)
    {
        if(dic[a[i]]==0) {dic[a[i]]++;ans++;}
        else if(dic[a[i]]!=0) {dic[a[i]]++;}
    }
    return ans;
}

int cmp(const void *a1,const void *b1)
{
    struct st a=*(struct st *)a1;
    struct st b=*(struct st *)b1;
    if(a.num!=b.num) return b.num-a.num;
    else if(a.num==b.num) return strcmp(a.str,b.str);
}
