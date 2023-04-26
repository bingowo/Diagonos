#include<stdio.h>
#include<math.h>

void Print(int *res, int lo, int len, int pro){
    printf("case #%d:\n", pro);
    for (int i = lo; i != len; i++)
        if (i != len-1) printf("%d,", res[i]);
        else printf("%d\n", res[i]);
}
void exch(int *nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int isPrime(int num){
    for(int i = 3; i <= sqrt(num)+1; i += 2)
        if (!(num % i)) return 0;
    return 1;
}
void add(int *v, int *w, int vidx, int widx, int pro){
    int table[30] = {2}, res[26], tidx = 1, prime = 3;
    while (tidx != 31){
        if (isPrime(prime)) table[tidx++] = prime;
        prime += 2;
    }

    if (vidx > widx){
        for (int i = 0; i != widx; i++)
            exch(w, i, i+vidx-widx);
        for (int i = 0; i != vidx-widx; i++)
            w[i] = 0;
    }
    
    int sum = 0, carry = 0;
    for (int i = vidx-1; i >= 0; i--){
        int weight = table[vidx-1-i];
        sum = v[i] + w[i] + carry;
        res[i+1] = sum;
        if(sum >= weight){
            res[i+1] -= weight;
            carry = 1;
        } 
        else carry = 0; 
    }
    if (carry) {res[0] = 1; Print(res, 0, vidx+1, pro);}
    else Print(res, 1, vidx+1, pro);

}
int main(){
    int n; 
    scanf("%d", &n);
    char c;
    c = getchar();
    for(int i = 0; i != n; i++){
        int a[25], b[25], aidx = 0, bidx = 0;
        while(1){
            if (c == ' ') break;
            else if (c == '\n' || c == ',')
                scanf("%d", &a[aidx++]);
            c = getchar();
        }
        while(1){
            if (c == '\n') break;
            else if (c == ' ' || c == ',')
                scanf("%d", &b[bidx++]);
            c = getchar();
        }
        if (aidx > bidx) add(a, b, aidx, bidx, i);
        else add(b, a, bidx, aidx, i);
    }
    return 0;
}