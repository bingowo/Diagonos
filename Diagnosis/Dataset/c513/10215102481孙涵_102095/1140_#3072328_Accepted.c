#include <stdio.h>
#include <stdlib.h>

int cmp1(const void *a, const void *b);
int cmp2(const void *a, const void *b);
int find(int a, int *s,int m);

struct data{
    int m;
    int arr[100];
};

int main()
{
    int n;
    scanf("%d",&n);
    struct data s[100];
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d",&m);
        s[i].m = m;
        int temp;
        for(int j = 0; j < m; j++){
            scanf("%d",&temp);
            s[i].arr[j] = temp;
        }
        qsort(s[i].arr,m,sizeof(int),cmp2);
    }
    qsort(s,n,sizeof(s[0]),cmp1);
    int ans[100];
    int pl = 0;
    int flag = 0;
    for(int i = 0; i < s[0].m; i++){
        for(int j = 1; j < n; j++){
            int temp = find(s[0].arr[i],s[j].arr,s[j].m);
            if (temp == 0){
                flag = -1;
            }
        }
        if(flag == 0){
            ans[pl] = s[0].arr[i];
            pl++;
        }
        flag = 0;
    }
    for(int i = 0; i < pl; i++){
        printf("%d ",ans[i]);
    }
    return 0;
}

int cmp1(const void *a, const void *b){
    struct data d1;
    struct data d2;
    d1 = (*(struct data *)a);
    d2 = (*(struct data *)b);
    if(d1.m > d2.m){
        return 1;
    }else{
        return -1;
    }
}

int cmp2(const void *a, const void *b){
    int i1;
    int i2;
    i1 = (*(int *)a);
    i2 = (*(int *)b);
    if (i1 > i2){
        return 1;
    }else{
        return -1;
    }
}

int find(int a, int *s,int m){
    int flag = 0;
    for(int i = 0; i < m; i++){
        if(*(s + i) == a){
            flag = 1;
        }
    }
    return flag;
}
