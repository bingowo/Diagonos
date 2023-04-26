#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
char s[20];
int c,m,e,a;
}node;
int cmpa(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.a!=p2.a)return p2.a-p1.a;
    else return strcmp(p1.s,p2.s);

}
int cmpc(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.c!=p2.c)return p2.c-p1.c;
    else return strcmp(p1.s,p2.s);

}
int cmpm(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.m!=p2.m)return p2.m-p1.m;
    else return strcmp(p1.s,p2.s);

}
int cmpe(const void*a,const void*b)
{
    node p1=*((node*)a);
    node p2=*((node*)b);
    if(p1.e!=p2.e)return p2.e-p1.e;
    else return strcmp(p1.s,p2.s);

}
int main(){
    int T;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        int n;
       scanf("%d",&n);
       node p[101]={0};
       for(int j=0;j<n;j++)
       {
           scanf("%s%d%d%d",p[j].s,&p[j].c,&p[j].m,&p[j].e);
           p[j].a=(int)((p[j].c+p[j].m+p[j].e)/3.0+0.5);

       }
        printf("case #%d:\n",i);
        printf("A:\n");
        qsort(p,n,sizeof(p[0]),cmpa);
        printf("%s\n",p[0].s);
        int j=1;
        while((p[j-1].a==p[j].a)&&(j<n))
        {
            printf("%s\n",p[j].s);
            j++;
        }

        printf("C:\n");
        qsort(p,n,sizeof(p[0]),cmpc);
        printf("%s\n",p[0].s);
       j=1;
        while((p[j-1].c==p[j].c)&&(j<n))
        {
            printf("%s\n",p[j].s);
            j++;
        }

                printf("M:\n");
        qsort(p,n,sizeof(p[0]),cmpm);
        printf("%s\n",p[0].s);
        j=1;
        while((p[j-1].m==p[j].m)&&(j<n))
        {
            printf("%s\n",p[j].s);
            j++;
        }

                printf("E:\n");
        qsort(p,n,sizeof(p[0]),cmpe);
        printf("%s\n",p[0].s);
       j=1;
        while((p[j-1].e==p[j].e)&&(j<n))
        {
            printf("%s\n",p[j].s);
            j++;
        }

    }



}
