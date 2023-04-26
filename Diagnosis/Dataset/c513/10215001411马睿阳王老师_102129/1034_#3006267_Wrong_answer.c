#include<stdio.h>
#include<string.h>
#include<math.h>
double flag[50];

 int cmp(const void*a1,const void*b1)
{
    char a=*(char*)a1;
    char b=*(char*)b1;
    if(flag[a-'A']==flag[b-'A'])//如果频率相同
    {
        if(a!=b&&abs(a-b)!=32)//频率一样，但不是大小写关系
        {
            if(a-'0'>=b-'0') return 1;
            else return -1;
        }
        else if(a-b-'0'==32)//a是大写
        return -1;
        else return 1;
    }
    else
    {
        if(flag[a]>flag[b])  return 1;
        else return -1;
    }

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
        char s[105]={0};
        scanf("%s",s);
        c=strlen(s);
        sort(s,c);
        printf("case #%d:\n",k);
        for(j=0;j<c;j++)
        printf("%c",s[j]);
        printf("\n");
    }

    return 0;
}
