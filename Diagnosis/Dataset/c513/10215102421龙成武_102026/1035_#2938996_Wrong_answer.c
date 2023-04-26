#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct
{
    int R;
    int H;
    int RH;
    int flag;
}COLUMN;
int compar(const void *p1,const void *p2);
int compar1(const void *p1,const void *p2)
{
    int flag=0;
    int sa,sb;
    COLUMN *a=(COLUMN*)p1,*b=(COLUMN*)p2;
    sa=a->R*(2*a->H+a->R);
    sb=b->R*(2*b->H+b->R);
    if(sa>sb)
        flag=-1;
    else
        flag=1;
    return flag;
}
void myPrint(char*a);
int main()
{
    int n,m,i,j,res;
    scanf("%d %d",&n,&m);
    COLUMN *a=(COLUMN*)malloc(n*sizeof(COLUMN));
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].R,&a[i].H);
        a[i].RH=a[i].R*a[i].H;
        a[i].flag=0;                //代表未被选中
    }
    qsort(a,n,sizeof(COLUMN),compar);
    res=0;
    for(i=0;i<m-1;i++)
    {
        res+=2*a[i].RH;
        a[i].flag=1;
    }
    qsort(a,n,sizeof(COLUMN),compar1);
    for(i=0;i<n;i++)
    {
        if(a[i].flag==0)
        {
            res+=a[i].R*(a[i].R+2*a[i].H);
            break;
        }
    }
    printf("%d",res);
    return 0;
}
int compar(const void *p1,const void *p2)
{
    int flag=0;
    int arh,brh;
    COLUMN *a=(COLUMN*)p1,*b=(COLUMN*)p2;
    arh=a->R*a->H;
    brh=b->R*b->H;
    if(arh>brh)
        flag=-1;
    else
        flag=1;
    return flag;
}
void myPrint(char*a)
{
    static int tim=0;
    int i=0;
    printf("case #%d:\n",tim++);
    printf("%s\n",a);
}
