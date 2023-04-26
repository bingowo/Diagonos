#include <stdio.h>
#include <string.h>
typedef long long int ll;
typedef struct {char date[16];char size[17];char name[63]}File;
char w[11];

int cmp(const void*pa,const void *pb)
{
    File *a=(File *)pa;
    File *b=(File *)pb;
    if(w[6]=='N')
        {return strcmp(a->name,b->name) ;}
    if(w[6]=='S')
        {
            if(strcmp(a->size,b->size)!=0)
               {return strcmp(a->size,b->size); }
            else{return strcmp(a->name,b->name); }
        }
    if(w[6]=='T')
        {
            if(strcmp(a->date,b->date)!=0)
               {return strcmp(a->date,b->date) ;}
            else{return strcmp(a->name,b->name) ;}
        }
}
int main()
{
    int N=1,n=1;
    char e='1',c;
    while(N)
    {
        scanf("%d\n",&N);
        if(N==0){return 0;}
        File f[N];
        for(int i=0;i<N;i++){memset(f[i].date,0,sizeof(char));memset(f[i].size,0,sizeof(char));memset(f[i].name,0,sizeof(char));}
        n=0;
        while(n++<N)
        {
            for(int i=0,j=0;i<16;i++)
            {
                if((scanf("%c",&c)!=' '))
                {
                    f[n-1].date[j++]=c;
                }
                f[n-1].date[j]='\0';
            }
            for(int i=0,j=0;i<17;i++)
            {
                if((scanf("%c",&c)!=' '))
                {
                    f[n-1].size[j++]=c;
                }
                f[n-1].size[j]='\0';
            }
            scanf("%s\n",f[n-1].name);
        }
        scanf("%s\n",f[n-1].name);
        qsort(f,N,sizeof(File),cmp);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<16;j++){printf("%c",f[i].date[j]);}
            printf("%s",f[i].size);
            printf("%s",f[i].name);
            printf("\n");
        }
        printf("\n");
    }
    return 0;}
