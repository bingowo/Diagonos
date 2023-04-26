#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct data
{
    int x;
    int y;
    int d;
};
int cmp(const void *pa,const void *pb)
{
    struct data a,b;
    a=*((struct data *)pa);
    b=*((struct data *)pb);
    return b.d-a.d;
}
int turn(int a)
{
    int b=a+1;
    int t=0;
    while(b>0)
    {
        b=b/2;
        t++;
    return t-1;
}
int main()
{
    int number;
    scanf("%d",&number);
    struct data area[number];
    int a=0;
    for(int i=0;i<number;i++)
    {
        scanf("%d%d",&area[i].x,&area[i].y);
        area[i].d=abs(area[i].x)+abs(area[i].y);
    }
    int a[number-1];
    for(int j=1;j<number;j++)
    {
        a[j-1]=abs(area[j+1].x-area[j].x)+abs(area[j+1].y-area[j].y);
    }
    for(int k=0;k<number-1;k++)
    {
        
    }
    qsort(area,number,sizeof(area[0]),cmp);
    int d1=abs(area[1].x-area[0].x)+abs(area[1].y-area[0].y);
    
}