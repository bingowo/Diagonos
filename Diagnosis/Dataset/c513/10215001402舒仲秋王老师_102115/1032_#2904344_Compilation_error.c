#include <stdio.h>
#include <stdlib.h>
struct data
{
    long int num[100]
};
int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        long int n,j,q;
        scanf("%ld",&n);
        struct data NUM[5000];
        for(j=0;j<=5000;j++) for(q=0;q<=100;q++) NUM[j].num[q]=0;
        for(j=0;j<n-1;j++)
        {
            char mid[5000];
            gets(mid);
            for(q=0,r=0;q<strlen(mid);q++)
            {
                if(mid[q]==' ') {r++;continue;}
                NUM[j].num[r]=NUM[j].num[r]+mid[q]-'0';
            }
        }
        char mid[5000];
        gets(mid);
        for(q=0,r=0;q<strlen(mid)-1;q++)
        {
            if(mid[q]==' ') {r++;continue;}
            NUM[j].num[r]=NUM[j].num[r]+mid[q]-'0';
        }
        for(j=0;j<n-1;j++)
            qsort(NUM,n,sizeof(NUM[0]),cmp);
            
    }
}
    
    