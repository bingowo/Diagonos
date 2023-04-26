#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct
{
    char s[21];
    int num;
    int alb[26];
}stu;
int cmp(const void *a,const void *b)
{
    stu * p1=(stu *)a;
    stu *p2 =(stu *)b;
    if(p1->num!=p2->num){
        return p2->num - p1->num;
    }
    else {
        return strcmp(p1->s,p2->s);
        }
    }
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        stu a[n];
        for(int j=0;j<n;j++){
            scanf("%s",a[j].s);
            
            //a[j].num=0;必须有 要不然不对哈哈哈哈
            a[j].num=0;
            for(int x=0;x<26;x++){
                a[j].alb[x]=0;
            }
            int len= strlen(a[j].s);
            for(int k=0;k<len;k++){
                if(a[j].alb[a[j].s[k]-'A']==0){
                    a[j].num++;
                }
                 a[j].alb[a[j].s[k]-'A']=1;
            }

        }
        qsort(a,n,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<n;q++){
           printf("%s\n",a[q].s);
        }
    }
}
