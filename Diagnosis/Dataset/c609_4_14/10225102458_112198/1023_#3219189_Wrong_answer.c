#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {int day;char month[10];int year;}str;
int change(char *f)
{
    char a[19][10]={
         "pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu"};
    for(int i=0;i<19;i++){
        if(strcmp(a[i],f)==0){return i;break;}
    }
}
int cmp(const void* a,const void* b)
{
    str aa=*(str*)a;
    str bb=*(str*)a;
    if(aa.year==bb.year){
        if(aa.month==bb.month){
            return aa.day-bb.day;
        }
        else return change(aa.month)-change(bb.month);
    }else return aa.year-bb.year;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);
        str s[m];
        for(int j=0;j<m;j++){
            scanf("%d. %s %d",&s[j].day,s[j].month,&s[j].year);
        }
        qsort(s,m,sizeof(s[0]),cmp);
        for(int i=0;i<m;i++){
        printf("%d. %s %d\n",s[i].day,s[i].month,s[i].year);
        }
    }
    return 0;

}
