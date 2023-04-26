#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
double frequceny[26];
int compar(const void *p1,const void *p2);
void myPrint(char*a);
int main()
{
    int T,N,i,j,temp;
    char a[101];
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<26;i++)
            scanf("%lf",&frequceny[i]);
        scanf("%s",a);
        qsort(a,strlen(a),sizeof(char),compar);
        myPrint(a);
    }
    return 0;
}
int compar(const void *p1,const void *p2)
{
    int flag=0,fla=0,flb=0;       //默认是大写
    double fa,fb;
    char *a=(char*)p1,*b=(char*)p2;
    if(*a>='a')
    {
        fa=frequceny[(*a-'a')];
        fla=1;
    }
    else
        fa=frequceny[(*a-'A')];
    if(*b>='a')
    {
        fb=frequceny[(*b-'a')];
        flb=1;
    }
    else
        fb=frequceny[(*b-'A')];

    if(fa>fb)
        flag=-1;
    else if(fa<fb)
        flag=1;
    else
    {
        if(fla==flb)
        {
            if(*a<*b)
                flag=-1;
            else
                flag=1;
        }
        else if(fla==0&&flb==1)
        {
            if((*a-'A')<(*b-'a'))
                flag=-1;
            else
                flag=1;
        }
        else if(fla==1&&flb==0)
        {
            if((*a-'a')<(*b-'A'))
                flag=-1;
            else
                flag=1;
        }
    }
    return flag;
}
void myPrint(char*a)
{
    static int tim=0;
    int i=0;
    printf("case #%d:\n",tim++);
    printf("%s\n",a);
}
