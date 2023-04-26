#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *A[]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

int Date(char*a){
    char b[2];
    int i=0;
    while(a[i]!='.'){
        b[i]=a[i];
        i++;
    }
    b[i]='\0';
    int date=atoi(b);
    return date;
}

int Month(char*a){
    int month;
    char b[7];
    int i=0,x=0;
    while(a[i]<'a'||a[i]>'z')
        i++;
    while(a[i]>='a'&&a[i]<='z'){
        b[x++]=a[i];
        i++;
    }
    b[x]='\0';
    for(int j=0;j<19;j++){
        if(strcmp(b,A[j])==0)
            month=j;
    }
    return month;
}

int Year(char*a){
    int i=5,x=0;
    char b[4];
    while(a[i]<'0'||a[i]>'9')
        i++;
    while(a[i]>='0'&&a[i]<='9'&&a[i]!='\0'){
        b[x++]=a[i];
        i++;
    }
    b[x]='\0';
    int year=atoi(b);
    return year;
}
int cmp(const void* a,const void* b){
    int date_a=Date((char *)a),month_a=Month((char *)a),year_a=Year((char *)a);
    int date_b=Date((char *)b),month_b=Month((char *)b),year_b=Year((char *)b);
    if(year_a!=year_b)  return year_a-year_b;
    else{
        if(month_a!=month_b)  return month_a-month_b;
        else    return date_a-date_b;
    }
}

int main()
{
    int T;
    int N;
    char c;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        getchar();
        char a[N][20];
        int cnt=0;
        for(int j=0;j<N;j++){
            c=getchar();
            while(c!='\n'){
                a[j][cnt++]=c;
                c=getchar();
            }
            a[j][cnt]='\0';
            cnt=0;
        }
        qsort(a,N,sizeof(a[0]),cmp);
        printf("case #%d:\n",i);
        for(int k=0;k<N;k++)
            printf("%s\n",a[k]);
    }
    return 0;
}


