#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct{
    char s[30];
    int num;
    int chongfu;
    //int alb[26];
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
    int t,n,j;
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        scanf("%d",&n);
        stu stu1[n];
        for(j=0;j<n;j++){

            scanf("%s",stu1[j].s);
            //stu1[j].num=0;
            //stu1[j].num=strlen(stu1[j].s);
            //for(int q=0;q<26;q++){
                //stu1[j].alb[q] = 0;

        for(int y=0;y<strlen(stu1[j].s);y++){
                for(int u=y+1;u<strlen(stu1[j].s);u++){
                    if(stu1[j].s[u]==stu1[j].s[y]){
                        stu1[j].chongfu++;
               }
            }
           }

            stu1[j].num=strlen(stu1[j].s)-stu1[j].chongfu;


           //for(int p=0;p< strlen(stu1[j].s);p++){
                //if(stu1[j].alb[stu1[j].s[p]-'A']==0){
                    //stu1[j].num ++;
                //}
                //stu1[j].alb[stu1[j].s[p]-'A']=1;

        //printf("%d\n",stu1[j].num);
       // printf("%d\n",stu1[j].chongfu);
        //printf("%d\n",strlen(stu1[j].s));
           }

        qsort(stu1,n,sizeof(stu1[0]),cmp);
        printf("case #%d:\n",i);
        for(int q=0;q<n;q++){
           printf("%s\n",stu1[q].s);
        }

    }
}
