#include<stdio.h>
#include<string.h>
typedef struct{int a,b;}ACM;

int cmp(const void*a,const void*b)
{
    ACM *p1=(ACM*)a,*p2=(ACM*)b;
    if(p1->b > p2->b) return 0;
    else if(p1->b < p2->b) return 1;
    else return p1->a - p2->a;
}

int main()
{
    int n,m,i;
    while(scanf("%d%d",&n,&m),m!=0 && n!=0)
    {
        ACM s[10]={0};
        int win,lose,gad;
        for(i=0;i<n;i++)
        {
            s[i].a=i+1;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&win,&lose,&gad);
            if(gad==1)
            {
                s[win-1].b+=3; s[lose-1].b--;
            }
            else if(gad==-1)
            {
                s[win-1].b--; s[lose-1].b+=3;
            }
            else {s[win-1].b++;s[lose-1].b++;}
            //printf("%d %d\n",s[i].a,s[i].b);
        }
        //for(i=0;i<n;i++) printf("%d %d\n",s[i].a,s[i].b);
        qsort(s,n,sizeof s[1],cmp);
        for(i=0;i<n;i++) printf("%d ",s[i].a);
        printf("\n");
    }

}
