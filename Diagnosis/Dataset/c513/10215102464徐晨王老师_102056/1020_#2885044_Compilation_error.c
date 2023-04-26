#include <stdio.h>
#include <stdlib.h>

struct file{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int bite;
    char name[63];
    char name1[63];
    int bh;

}

int main(){
    int n;
    scanf("%d",&n);
    while(1){
        int a,b,c,d,e,f;
        char s1[63],s2[63];
        struct file[100];
        for(int i=0;i<n;i++){
        
        scanf("%d-%d-%d %d:%d %d ",&a,&b,&c,&d,&e,&f);
        file[i].year=a;
        file[i].month=b;
        file[i].day=c;
        file[i].hour=d;
        file[i].minute=e;
        file[i].bite=f;
        scanf("%s.%s",s1,s2);
        file[i].name=s1;
        file[i].name1=s2;
        }
        
        if(n==0)break;
        else {
            scanf("%d",&n);
            printf("\n\n");
    }
}
