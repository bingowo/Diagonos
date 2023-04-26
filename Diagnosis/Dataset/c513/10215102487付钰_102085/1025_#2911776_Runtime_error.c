#include <stdlib.h>
#include <stdio.h>
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
        for(int i=0;i<20;i++){
            if(p1->s[i]!=p2->s[i])
                return p1->s[i] - p2->s[i];
        }
    }
}

int main()
{
    int t,n,j;
    scanf("%d",&t);
    stu stu1[t];
    for(int i=0;i<t;i++){
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%s",&stu1[i].s[j]);
        
        stu1[j].o=n;
        for(int y=0;y<n;y++){
                for(int u=1;u<n;u++){
                    if(stu1[i].s[u]==stu1[i].s[y]){
                        stu1[i].o--;
                    }
                }
}
        }
        qsort(stu1,n,sizeof(stu1),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<n;q++){
           printf("%s\n",stu1[q].s);
        }

    }
}
