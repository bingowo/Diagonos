#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
typedef struct dic
{
    int len;
    char s[15];
}DIC;
int cmp(const void *a,const void *b)
{
    DIC a1=*(DIC*)a;
    DIC b1=*(DIC*)b;
    if(a1.len!=b1.len)return a1.len>b1.len?1:-1;
    else return 0;
}
int main()
{
    int n;scanf("%d",&n);
    DIC*a=(DIC*)malloc(sizeof(DIC)*n);
    for(int i=0;i<n;i++){
        scanf("%s",a[i].s);
        a[i].len=strlen(a[i].s);
    }
    qsort(a,n,sizeof(DIC),cmp);
    char s[5500];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++){
        int k=0,size=1;
        char judge[15];
        for(int j=i;j<14+i&&j<strlen(s);j++){
            judge[k++]=s[j];
            judge[k]=0;
            for(int step=0;step<n;step++){
                if(strcmp(a[step].s,judge)==0){
                    if(j+1-i>size)size=j+1-i;
                }
            }
        }
        for(int step=0;step<size;step++){
            printf("%c",judge[step]);
        }
        printf("\n");
        i+=size-1;
    }
    return 0;
}
