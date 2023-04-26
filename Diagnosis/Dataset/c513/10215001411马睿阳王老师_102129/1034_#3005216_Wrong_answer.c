#include<stdio.h>
#include<string.h>
#include<math.h>
double flag[50];
void cmp(char a,char b)
{
    if(flag[a-'A']==flag[b-'A'])
    {
        if(a!=b&&abs(a-b)!=32)//频率一样，但不是大小写关系
        return a<b;
        else
        return a>b;
    }
    else return flag[a-'A']>flag[b-'A'];
}

void sort(char s[105],int c)
{
    qsort(s,c,sizeof(char),cmp);

}
int main()
{
    int T;
    int i=0,j=0,t=0,k=0;
    scanf("%d",&T);
    for(k=0;k<T;k++)
    {
        int c=0;
        for(i=1;i<=26;i++)
        {
            double m;
            scanf("%lf",&m);
            flag[i]=flag[i+32]=m;
        }
        char s[105];
        scanf("%s",s);
        sort(s,c);
        printf("case #%d:\n",&k);
        for(j=0;j<c;j++)
        printf("%c",s[j]);
        printf("\n");
    }
    return 0;
}
