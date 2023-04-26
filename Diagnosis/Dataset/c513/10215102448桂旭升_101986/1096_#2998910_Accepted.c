#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include<ctype.h>
int* d = NULL;
typedef struct 
{
    int a;
    int b;
}LIST;
int cmp1(const void *a, const void *b){
    LIST *pa = (LIST*)a, *pb = (LIST*)b;
    if(pa -> a != pb -> a)return pa -> a < pb -> a ? -1 : 1;
    else return pa -> b < pb -> b ? -1 : 1;
}
int cmp2(const void *a, const void *b){
    int pa = *(int*)a, pb = *(int*)b;
    return pa < pb ? -1 : 1;
}
LIST* Input(int n)
{
    LIST *a = (LIST*)malloc(sizeof(LIST)*n);
    int i, j = 0, len, k = 0;
    for(i = 0; i < n; i++){
        scanf("%d%d", &a[i].a, &a[i].b);
    }
    return a; 
}
int main(){
	int i, j, t, n, flag;
    scanf("%d", &t);
    while(t--){
        LIST* A = NULL; 
        flag = 0;
        scanf("%d", &n);
        A = Input(n);
        int *d = (int*)malloc(sizeof(int)*n);
        for(i = 0; i < n; i++){
            d[i] = A[i].b;
        }
        qsort(A, n, sizeof(LIST), cmp1);
        for(i = 1; i < n; i++){
            if(A[i].a == A[i-1].a && A[i].b != A[i-1].b){
                flag = 1; break;
            }
        }
        if(flag)printf("Poor dxw!\n");
        else{
            qsort(d, n, sizeof(int), cmp2);
            i = 0; j = 0;
            if(d[0] > A[0].a){
                while(i < n && j < n){
                    if(A[i].a < d[j])i++;
                    else if(A[i].a == d[j]){
                        flag = 1; break;
                    }
                    else j++;
                }
            }
            else if (d[0] == A[0].a)flag = 1;
            else{
                while(i < n && j < n){
                    if(d[j] < A[i].a)j++;
                    else if(A[i].a == d[j]){
                        flag = 1; break;
                    }
                    else i++;
                }
            }
            if(flag)printf("Poor dxw!\n");
            else printf("Lucky dxw!\n");
        }
        free(A); free(d);
    }
    system("pause");
	return 0;
}