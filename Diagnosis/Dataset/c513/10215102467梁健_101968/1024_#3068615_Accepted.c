#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
/*int cmp(const void *a,const void *b)
{
    int x=*(int*)a,y=*(int*)b;
    return x>y?-1:1;
}
int cmpt(const void *a,const void *b){
    TEXT x=*(TEXT*)a;
    TEXT y=*(TEXT*)b;
    if(strcmp(x.date,y.date)!=0)return strcmp(x.date,y.date);
    else if(strcmp(x.time,y.time)!=0)return strcmp(x.time,y.time);
    else return strcmp(x.name,y.name);
}*/
// A=65，a=97 0=48；
typedef struct stu{
    char num[12];
    int sco;
}STU;
int cmp(const void *a,const void *b)
{
    STU x=*(STU*)a;
    STU y=*(STU*)b;
    if(x.sco!=y.sco)return x.sco>y.sco?-1:1;
    else return strcmp(x.num,y.num);
}
int main()
{
    int T;scanf("%d",&T);
    for(int p=0;p<T;p++){
        printf("case #%d:\n",p);
        int n,m,g,cnt=0;
        scanf("%d %d %d",&n,&m,&g);
        int s[m+2];
        for(int i=1;i<=m;i++)scanf("%d",&s[i]);
        STU*a=NULL;
        a=(STU*)malloc(sizeof(STU)*n);
        for(int i=0;i<n;i++){
            scanf("%s",a[i].num);
            int nu=0;
            scanf("%d",&nu);
            int k;
            a[i].sco=0;
            for(int j=0;j<nu;j++){
                scanf("%d",&k);
                a[i].sco+=s[k];
            }
            if(a[i].sco>=g)cnt++;
        }
        qsort(a,n,sizeof(STU),cmp);
        printf("%d\n",cnt);
        for(int i=0;i<cnt;i++)printf("%s %d\n",a[i].num,a[i].sco);
    }
    return 0;
}
