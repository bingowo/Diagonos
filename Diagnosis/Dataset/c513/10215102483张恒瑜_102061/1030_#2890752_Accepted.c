#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void* a, const void* b)
{
    char *a0=(char*)a,*b0=(char*)b;
    int i=0,j=0;
    if(a0[0]=='-') i++;
    if(b0[0]=='-') j++;
    if(a0[i]==b0[j]) return atoll(a0) < atoll(b0) ? -1:1;
    else return b0[j]-a0[i];
}

int main()
{
    int T,t=0;
    scanf("%d",&T);
    while (T--)
    {
        int n,i;
        scanf("%d",&n);
        char input[10010][20]={{'\0'}};
        for(i=0;i<n;i++) scanf("%s",&input[i]);
        
        qsort(input,n,sizeof(input[0]),cmp);
        printf("case #%d:\n",t);
        for(i=0;i<n;i++)
        {
            i==n-1 ? printf("%s",input[i]) : printf("%s ",input[i]);
        }
        printf("\n");
        t++;
    }
    return 0;
}