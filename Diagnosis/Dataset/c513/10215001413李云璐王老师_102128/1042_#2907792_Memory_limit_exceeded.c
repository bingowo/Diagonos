#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

void output(char*s,int count)
{
    for(int i=0;i<count;i++)
        {
            printf("%c",s[i]);
            if(i<count-1){output(s+i,count-i);}
        }

}
int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        int a[129]={0};
        char b[18]={},c[18]={};
        scanf("%s\n",b);
        int lenb=strlen(b),l=0,k;
        for(k=0;k<lenb;k++)
        {
            if(a[b[k]]==0) {c[l]=b[k];l++;a[b[k]]=1;}
        }

        printf("case #%d:\n",i);
        qsort(c,l,sizeof(char),strcmp);
        output(c,l);
    }
        return 0;
}