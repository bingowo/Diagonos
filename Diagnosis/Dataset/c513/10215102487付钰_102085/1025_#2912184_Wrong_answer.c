#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{
    char s[30];
    int num;
    int o;
}stu;
int cmp(const void *a,const void *b)
{
    stu * p1=(stu *)a;
    stu *p2 =(stu *)b;
    if(p1->o!=p2->o){
        return p2->o - p1->o;
    }
    else {
        return strcmp(p1->s,p2->s);
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
            stu1[i].o=strlen(stu1[j].s);
        for(int y=0;y<strlen(stu1[j].s);y++){
                for(int u=1;u<strlen(stu1[j].s);u++){
                    if(stu1[i].s[u]==stu1[i].s[y]){
                        stu1[i].o--;
               }     }
           }
        }
        qsort(stu1,n,sizeof(stu1[0]),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<n;q++){
           printf("%s\n",stu1[q].s);
        }

    }
}