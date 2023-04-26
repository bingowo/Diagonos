#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct da{
    char st1[1234];
    char st2[1234];
    int year;
}date[12340];

int n;
char month[19][20]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

int find(const void* x){
    struct da *dai=(struct da *)x;
    for (int i=0;i<19;i++){
        if (strcmp(month[i],dai->st2)==0) return i;
    }
}

int cmp(const void* datai,const void* dataj){
    struct da *dai=(struct da *)datai;
    struct da *daj=(struct da *)dataj;
    int num1=0,num2=0;
    for (int k=0;k<strlen(dai->st1)-1;k++){
        num1*=10;
        num1+=dai->st1[k]-'0';
    }
    for (int k=0;k<strlen(daj->st1)-1;k++){
        num2*=10;
        num2+=daj->st1[k]-'0';
    }
    if (dai->year<daj->year) return -1;
    else if (dai->year>daj->year) return 1;
    else if (find(dai)>find(daj)) return 1;
    else if (find(dai)<find(daj)) return -1;
    else if (num1<num2) return -1;
    else return 1;
}

int main(){
    int t;
    scanf("%d",&t);
    for (int l=1;l<=t;l++){
        scanf("%d",&n);
        for (int k=1;k<=n;k++){
            scanf("%s %s %d",date[k].st1,date[k].st2,&date[k].year);
        }
        qsort(date+1,n,sizeof(date[1]),cmp);
        printf("case #%d:\n",l-1);
        for (int i=1;i<=n;i++){
            printf("%s %s %d\n",date[i].st1,date[i].st2,date[i].year);
        }
    }
    return 0;
}
