#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct data
{
    char str[21];
    char alpha[26];
    int dif;

};

 int cmp(const void *a,const void *b){
     struct data d1,d2;
     d1=*((struct data *)a);
     d2=*((struct data *)b);
     int len1= strlen(d1.str);
        for(int i = 0 ; i < len1; i++)
        {
            if(d1.alpha[d1.str[i] - 'A'] == 0)
            {
                d1.alpha[d1.str[i] - 'A'] = 1;
                d1.dif++;
            }
        }
        int len2 = strlen(d2.str);
        for(int i = 0 ; i < len2; i++)
        {
            if(d2.alpha[d2.str[i] - 'A'] == 0)
            {
                d2.alpha[d2.str[i] - 'A'] = 1;
                d2.dif++;
            }
        }
     if(d2.dif!=d1.dif)
         return d2.dif-d1.dif;
    else
    {    if(d1.str>d2.str) return 1;
         else return -1;
    }

 }

int main()
{
    int n,i;
    scanf("%d",&n);
    for(int cas=0;cas<n;cas++){
        struct data p[1000];
        int t;
        scanf("%d",&t);
        for(int j=0;j<t;j++){
                scanf("%s",p[j].str);
        }
        qsort(p,t,sizeof(p[0]),cmp);
        printf("case #%d:\n",cas);
        for(i=0;i<t;i++)
           printf("%s\n",p[i].str);



    }


    return 0;
}
