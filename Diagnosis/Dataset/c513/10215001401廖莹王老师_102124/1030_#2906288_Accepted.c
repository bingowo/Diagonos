#include <stdio.h>
#include <stdlib.h>
int  cmp(const void*a,const void*b)
{
    char *s1,*s2;
    int k1=0,k2=0,i,f;
    long long a1=0,a2=0;
    s1=(char*)a;
    s2=(char*)b;
    if(s1[0]=='-')k1=s1[1]-'0';else k1=s1[0]-'0';
    if(s2[0]=='-')k2=s2[1]-'0';else k2=s2[0]-'0';
    if(k1!=k2)return k2-k1;
    else
    {
        f=1,i=0;
        if(s1[0]=='-'){f=-1;i++;}
        for(i=i;s1[i];i++)a1=a1*10+(s1[i]-'0');
        a1=a1*f;
        f=1,i=0;
        if(s2[0]=='-'){f=-1;i++;}
        for(i=i;s2[i];i++)a2=a2*10+(s2[i]-'0');
        a2=a2*f;
        if(a1>=a2)return 1;
            else return -1;
    }
}
void js(int h)
{
    char str[1000000],t[10000][25];
    gets(str);
    int i=0,j=0,r=0;
    while(str[i])
    {
        j=0;
        while(str[i]!=' ' && str[i]){t[r][j]=str[i];j++;i++;}
        t[r][j]='\0';
        if(str[i]==' ')r++,i++;
    }

    qsort(t,r+1,sizeof(t[0]),cmp);
    printf("case #%d:\n",h);
    for(i=0;i<r+1;i++)printf("%s ",t[i]);
    printf("\n");
}
int main()
{
    int n,l,h;
    scanf("%d" ,&n);
    getchar();
    for(h=0;h<n;h++)
    {

        scanf("%d",&l);
        getchar();
        js(h);
    }

}
