#include <stdio.h>
#include <ctype.h>

typedef struct{
    int a[1000];
    int cnt;
    int flag;
}NUM;

void catch(int* a, int* p);
int absCmp(NUM* a, NUM* b);
NUM plus(NUM* a, NUM* b);
NUM minus(NUM* a,NUM* b);


int main()
{
    int bin[10000] = {0}, cnt = 0;
    catch(bin, &cnt);
    NUM a = {{0},1,1}, b = {{0},1,1}, temp, one={{1},1,1};;
    for(int i=0; i<cnt; ++i) {
        temp = plus(&a, &b);
        b = minus(&a, &b);
        a = temp;  a.flag *= -1;
        if(bin[i]) a = plus(&a, &one);
        if(a.cnt==1 && a.a[0]==0) a.flag = 1;
        if(b.cnt==1 && b.a[0]==0) b.flag = 1;
    }
    if(a.flag == -1) printf("-");
    if(b.cnt==1 && b.a[0]==0) {
        for(int i=a.cnt-1; i>=0; --i) printf("%d",a.a[i]);
    }else if(a.cnt==1 && a.a[0]==0) {
        if(b.flag == -1) printf("-");
        if(b.cnt!=1 || b.a[0]!=1)
            for(int i=b.cnt-1; i>=0; --i) printf("%d",b.a[i]);
        printf("i");
    }else {
        for(int i=a.cnt-1; i>=0; --i) printf("%d",a.a[i]);
        printf("%c",b.flag==1 ? '+' : '-');
        if(b.cnt!=1 || b.a[0]!=1)
            for(int i=b.cnt-1; i>=0; --i) printf("%d",b.a[i]);
        printf("i");
    }
    printf("\n");
    return 0;
}


int absCmp(NUM* a, NUM* b) {
    if(a->cnt < b->cnt)  return 1;
    else if(a->cnt == b->cnt)
        for(int i=a->cnt-1; i>=0; --i){
            if(a->a[i] > b->a[i]) return 0;
            else if(a->a[i] < b->a[i]) return 1;
        }
    return 0;
}

NUM plus(NUM* a, NUM* b) {
    NUM ans = {{0},0,a->flag};
    if(a->flag != b->flag){
        if(b->flag == -1) {
            b->flag = 1;
            ans =  minus(a, b);
            b->flag = -1;
        }else {
            a->flag = 1;
            ans =  minus(b, a);
            a->flag = -1;
        }
        return ans;
    }
    ans.cnt = a->cnt > b->cnt ? a->cnt : b->cnt;
    int carry = 0;
    for(int i=0; i<ans.cnt; ++i) {
        int t = a->a[i] + b->a[i] + carry;
        carry = t / 10;
        ans.a[i] = t % 10;
    }
    if(carry) ans.a[ans.cnt++] = carry;
    return ans;
}

NUM minus(NUM* a, NUM* b) {
    NUM ans = {{0},0,a->flag};
    if(a->flag != b->flag) {
        b->flag = a->flag;
        ans = plus(a, b);
        b->flag *= -1;
        return ans;
    }
    if(absCmp(a, b)){
        ans = minus(b, a);
        ans.flag = -a->flag;
        return ans;
    }
    ans.cnt = a->cnt;
    for(int i=0; i<ans.cnt; ++i) {
        if(a->a[i] < b->a[i]) {
            a->a[i] += 10;
            int k = i+1;
            while(a->a[k] == 0) a->a[k++] = 9;
            --a->a[k];
        }
        ans.a[i] = a->a[i] - b->a[i];
    }
    while(ans.a[ans.cnt]==0 && ans.cnt) --ans.cnt;
    ++ans.cnt;
    return ans;
}

void catch(int* a, int* p) {
    char c;  getchar(); getchar();
    while((c = getchar()) != '\n') {
        int n = isdigit(c) ? c-'0' : c-'A'+10;
        for(int i=3; i>=0; --i) {
            a[*p+i] = n % 2;
            n /= 2;
        }
        *p += 4;
    }
}
