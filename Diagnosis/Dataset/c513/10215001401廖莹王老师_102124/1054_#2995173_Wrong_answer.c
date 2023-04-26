#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int l;
    char t[40]
}point;
point p[2000];
int world(int i,int m,int t)
{
    int j=0,l=0,k=0,o=0;
    l=p[i].l;
    for(j=i+1;;j++)
    {   if(j>=t-1)return i;
        else
        {
        if(l<=m  && l+1+p[j].l>m)break;
        else l=l+1+p[j].l;
        }
    }
    for(k=i;k<=j-2;k++)p[k].l++;
    if(l!=m)
    {
        while(l<m)
        {
         for(k=j-2;k>=i;k--){p[k].l++;l++;if(l==m)break;}
        }
    }
    for(k=i;k<=j-1;k++){printf("%s",p[k].t);for(o=strlen(p[k].t);o<p[k].l;o++)printf(" ");}printf("\n");
    return j;
}
void paiban(int h)
{
    int m=0,i=0,k=0,q=0,j=0;
    char s[2500]={0};
    memset(s,0,sizeof(char)*2500);
    scanf("%d",&m);getchar();gets(s);
    for(i=0;i<2000;i++){memset(p[i].t,0,sizeof(char)*40);p[i].l=0;}
    for(i=0;s[i];i++)
    {   q=0;
        if(s[i]==' ')continue;
        else
        {
           for(i=i;s[i];i++){if(s[i]==' ')break;p[k].t[q]=s[i];q++;}
        p[k].l=strlen(p[k].t);k++;
        }
    }
    printf("case #%d:\n",h);
    for(i=0;i<k;)
    {   j=0;
        j=world(i,m,k);
        if(j==i && j<k)break;
        else i=j;
    }
    if(i<k-1 ||i==0)
    {
        for(i=i;i<k-1;i++)printf("%s ",p[i].t);
    printf("%s",p[i].t);printf("\n");
    }

    return;
}
int main()
{
    int n=0,h=0;
    scanf("%d",&n);
    for(h=0;h<n;h++){paiban(h);}
}
