#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void * a, const void * b);

struct data{
    char s[301];
    int flag;
};

int main()
{
    int n;
    scanf("%d",&n);
    struct data d[100];
    for (int i = 0; i < n; i++){
        scanf("%s",d[i].s);
        if(d[i].s[4] == 's'){
            d[i].flag = -1;
        }else{
            d[i].flag = 1;
        }

    }
    qsort(d,n,sizeof(d[0]),cmp);
    for(int i = 0; i < n; i++){
        if(d[i].flag == -1){
                ;
        }else{
            printf("%s\n",d[i].s);
        }
    }
    return 0;
}


int cmp(const void * a, const void * b){
    struct data d1;
    struct data d2;
    d1 = (*(struct data *)a);
    d2 = (*(struct data *)b);
    char * s1 = d1.s;
    char * s2 = d2.s;
    return strcmp(s1,s2);

}
