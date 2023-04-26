#include<stdio.h>
#include<stdlib.h>
//#define pi 3.1415926
typedef struct{
   int r,h;
}node;
int cmp(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.h*p1.r>p2.h*p2.r)return -1;
    else return 1;
}
int main()
{
    node p[1005]={0};
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].r,&p[i].h);
    }
    /*
    for(int i=0;i<n;i++)
    {
        printf("%d %d\n",p[i].r,p[i].h);
    }*/
    int ans=0;
    int tmp;
    for(int i=0;i<n;i++)
    {int k=0;
    tmp=0;
        node pp[1005]={0};

        for(int j=0;j<n;j++)
        {
            if((j!=i)&&(p[j].r<=p[i].r))pp[k++]=p[j];
        }
        qsort(pp,k,sizeof(p[0]),cmp);

    if(k>=m-1)
    {
     tmp+=p[i].r*p[i].r+2*p[i].r*p[i].h;

    for(int j=0;j<m-1;j++)
    {
        tmp+=2*pp[j].r*pp[j].h;

    }
    if(ans<tmp)ans=tmp;
    }
    }
    printf("%d",ans);

}
