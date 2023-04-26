#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{
    char s[3000];
    int num;
    int chongfu;
}stu;
int cmp(const void *a,const void *b)
{
    stu * p1=(stu *)a;
    stu *p2 =(stu *)b;
    if(p1->num!=p2->num){
        return p2->num - p1->num;
    }
    else {return strcmp(p1->s,p2->s);
    }
}
int main()
{
    int t,n,j;
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        scanf("%d",&n);
        stu stu1[n];
        for(j=0;j<n;j++){
            scanf("%s",stu1[j].s);
            for(int y=0;y<strlen(stu1[j].s);y++){
                for(int u=y+1;u<strlen(stu1[j].s);u++){
                    if(stu1[j].s[u]==stu1[j].s[y]){
                        stu1[j].chongfu++;
                    }
                }
            }
            stu1[j].num=strlen(stu1[j].s)-stu1[j].chongfu;



        }

        qsort(stu1,n,sizeof(stu1[0]),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<n;q++){
            printf("%s\n",stu1[q].s);
        }

    }

