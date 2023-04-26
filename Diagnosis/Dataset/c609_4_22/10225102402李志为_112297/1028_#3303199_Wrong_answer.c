#include <stdlib.h>
#include <string.h>
typedef struct
{
    char s[1000];
} N;
int cmp(const void*a,const void*b)
{
    return strcmp(((N*)b)->s,((N*)a)->s);
}
N p[1001];
int main()
{
    int T;
    scanf("%d\n",&T);
    for(int i=0;i<T;i++){
        int n;
        scanf("%d\n",&n);
        for(int j=0;j<n;j++){
            gets(p[j].s);
            int len=strlen(p[j].s);
            for(int x=0;x<len;x++){
                if(p[j].s[x]=='-'){
                    p[j].s[x-1]=0;
                    break;
                }
            }
        }
        qsort(p,n,sizeof(p[0]),cmp);
        for(int j=0;j<n;j++){
            printf("%s\n",p[j].s);
        }
    }
	return 0;
}