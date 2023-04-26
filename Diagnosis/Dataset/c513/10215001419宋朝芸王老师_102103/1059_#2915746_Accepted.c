#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b){
    int temp;
    if(a < b){      //a = max(a,b)
        temp = b;
        b = a;
        a = temp;
    }

    if(a%b == 0) return b;

    temp = b;
    b = a % b;
    a = temp;
    return(GCD(a,b));
}


int cmp(const void *a, const void *b){
    int ia = *(int*)a, ib = *(int*)b;
    return (ia-ib);
}


int main()
{
    int n,s;
    scanf("%d%d",&n,&s);

    int *a = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    qsort(a,n,sizeof(a[0]),cmp);

    int lower, upper;
    int temp_height = a[0];
    for(int i = 0; i < n;  ){
        while(a[i] == temp_height) i++;
        if(i >= n){
            lower = i;
            upper = s + temp_height * i;
            break;
        }
        if(i * (a[i] - temp_height) < s){
            s = s - i * (a[i] - temp_height);
            temp_height = a[i];
            continue;
        }
        if(i * (a[i] - temp_height) >= s){
            lower = i;
            upper = s + temp_height * i;
            break;
        }
    }

    int full = upper / lower;
    if(full != 0) printf("%d",full);
    if(full * lower == upper) {
        free(a);
        return 0;
    }

    upper = upper - lower * full;

    int gcd = GCD(upper,lower);
    upper = upper / gcd;
    lower = lower / gcd;

    if(full != 0) printf("+");
    printf("%d/%d",upper,lower);


    free(a);
    return 0;
}
