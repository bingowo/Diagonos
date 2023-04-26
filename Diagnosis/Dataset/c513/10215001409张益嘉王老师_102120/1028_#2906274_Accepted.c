#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int splitstring(char zong[],char sign,int fen[],int nmax)
{
    int len,i,st=0,en,j,k;
    len=strlen(zong);
    for(i=0,j=0;i<len;i++)
    {
        if(zong[i]==sign)
        {
            en=i;
            fen[j]=0;
            for(k=st;k<en;k++)
            {
                fen[j]*=10;
                fen[j]+=zong[k]-'0';
            }
            j++;
            st=i+1;
        }
        if(j>nmax) break;
    }
    for(i=st;i<len;i++)
    {
        fen[j]*=10;
        fen[j]+=zong[i]-'0';
    }
    return j+1;
}*/

int cmpA(const void *a,const void*b)
{
    int aa=*((int*)a);
    int bb=*((int*)b);

    return aa-bb;
}

int cmpD(const void *a,const void*b)
{
    int aa=*((int*)a);
    int bb=*((int*)b);

    return bb-aa;
}

int main()
{
    char ch;
    int co;
    char s[200000];
    memset(s,0,sizeof(char)*200000);
    scanf("%c",&ch);
    //printf("ch=%s\n",ch);
    int i,j,a[120];
    memset(a,0,120*sizeof(int));
    for(i=0;;i++)
    {
        if(scanf("%d",&a[i])==EOF) break;
    }
    co=i;
    //co=splitstring(s,' ',a,120);
    /*for(i=0;i<co;i++)
    {
        printf("test a[%d]=%d\n",i,a[i]);
    }*/
    if(ch=='A') qsort(a,co,sizeof(int),cmpA);
    else qsort(a,co,sizeof(int),cmpD);
    a[co]=-1;
    for(i=0;i<co;i++)
    {
        if(a[i]!=a[i+1])
        {
            printf("%d",a[i]);
            if(i!=co-1) printf(" ");
        }
        else continue;
    }

}
