#include<stdio.h>
#include<math.h>

void Print(int *res, int lo, int len, int pro){
    printf("case #%d:\n", pro);
    for (int i = lo; i != len; i++)
        if (i != len-1) printf("%d,", res[i]);
        else printf("%d\n", res[i]);
}

int isPrime(int num){
    for(int i = 3; i <= sqrt(num)+1; i += 2)
        if (!(num % i)) return 0;
    return 1;
}
void add(int *v, int *w, int vidx, int widx, int pro){
    int res[52], table[25] = {2};
    for (int i = 3, j = 1; j != 25; i += 2)
        if (isPrime(i)) table[j++] = i;

    if (vidx > widx){
        for (int i = widx-1; i >= 0; i--)
            w[i+vidx-widx] = w[i];
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
    for(int i = 0; i != n; i++){
        int a[51], b[51], aidx = 0, bidx = 0;
        do{
            scanf("%d", &a[aidx++]);
        }while(getchar() != ' ');
        
        do{
            scanf("%d", &b[bidx++]);
        }while(getchar() != '\n');

        if (aidx > bidx) add(a, b, aidx, bidx, i);
        else add(b, a, bidx, aidx, i);
    }
    return 0;
}