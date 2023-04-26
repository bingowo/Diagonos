#include <stdio.h>
#include <stdlib.h>

struct file{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int bite;
    char *name;
    char *name1;
    int bh;

};

int NAME(const void*a,const void*b){
struct file x,y;
x=*((struct file *)a);
y=*((struct file *)b);

}

int SIZE(const void* a,const void* b){
struct file x,y;
x=*((struct file *)a);
y=*((struct file *)b);
return x.bite<y.bite;
}

int TIME(const void* a,const void* b){
struct file x,y;
x=*((struct file *)a);
y=*((struct file *)b);

}



int main(){
    int n;
    scanf("%d",&n);
    while(1){
        int a,b,c,d,e,f;
        char s1[63],s2[63],s3[5];
        struct file p[100];

        for(int i=0;i<n;i++){
        scanf("%d-%d-%d %d:%d %d ",&a,&b,&c,&d,&e,&f);
        p[i].year=a;
        p[i].month=b;
        p[i].day=c;
        p[i].hour=d;
        p[i].minute=e;
        p[i].bite=f;
        scanf("%s.%s",s1,s2);
        p[i].name=s1;
        p[i].name1=s2;
        }

        scanf("LIST /%s",s3);
        if(s3[0]=='N')qsort(p,n,sizeof(p[0]),NAME);
        if(s3[0]=='S')qsort(p,n,sizeof(p[0]),SIZE);
        if(s3[0]=='T')qsort(p,n,sizeof(p[0]),TIME);

        for(int j=0;j<n;j++){
            printf("%d-%d-%d %d:%d %16d ",p[j].year,p[j].month,p[j].day,p[j].hour,p[j].minute,p[j].bite);
            printf("%s.%s",s1,s2);
        }

        if(n==0)break;
        else {
            scanf("%d",&n);
            printf("\n\n");
    }
}
return 0;
}
