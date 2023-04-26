#include<stdio.h>
#include <stdlib.h>


typedef struct string{
    char s[1000];
    int cnt;
} str;

int cnt(str);

int cmp(const void* a,const void*b){
    str* p1 = (str*)a;
    str* p2 = (str*)b;
    return p2->cnt - p1->cnt;
}

int main(void)
{
    int loop;scanf("%d",&loop);
    for (int i = 0; i < loop; ++i) {printf("case #%d:\n",i);
        int numb;scanf("%d",&numb);
        getchar();str a[numb];
        for (int j = 0; j < numb; ++j) a[j].cnt = 0;
        for (int j = 0; j < numb; ++j) {
            scanf("%s",a[j].s);
            a[j].cnt = cnt(a[j]);
        }
        qsort(a,numb,sizeof(str),cmp);
        for (int j = 0; j < numb; ++j) {
            printf("%s\n",a[j].s);
        }
    }

}


int cnt(str a){
    int i,j,count=0,x=0;
    for(i=0;a.s[i]!='\0';i++)count++;
    for(i=0;i<count;i++)
    {for(j=i+1;j<count;j++){if(a.s[i]==a.s[j]){x++;break;}}}
    return count -x;
}