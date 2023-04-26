#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*typedef struct
{
    double f;
    char zm;
}group;
*/
double ord[128];

int cmp(const void*a,const void*b)
{
    char aa=*((char*)a);
    char bb=*((char*)b);
    if(ord[aa]>ord[bb]) return -1;
    else if (ord[aa]<ord[bb]) return 1;
    else if (tolower(aa)>tolower(bb)) return 1;
    else if (tolower(aa)<tolower(bb)) return -1;
    else return bb-aa;
}

int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int j,len;
        double mid;
        memset(ord,0.0,128*sizeof(double));
        char s[200];
         memset(s,0,200*sizeof(char));
        for(j=0;j<26;j++)
        {
            scanf("%lf",&mid);
            ord['A'+j]=mid;
            ord['a'+j]=mid;
        }
        /*for(j=0;j<26;j++)
        {
            printf("test test: ord[%d]=%lf %c %c\n",j,ord['A'+j],'A'+j,'a'+j);
        }*/
        scanf("%s",s);
        len=strlen(s);
        //printf("len=%d\n",len);
        //printf("test test:%s\n",s);
        qsort(s,len,sizeof(char),cmp);
        printf("case #%d:\n%s\n",i,s);

    }
    return 0;
}
