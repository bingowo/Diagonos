#include <stdio.h>
#include <ctype.h>

typedef struct{
    int a[4000];
    int cnt;
    int flag;
}NUM;

void catch(NUM* pa, NUM* pb);
int absCmp(NUM* a, NUM* b);
NUM mult(NUM* a, NUM* b);
NUM plus(NUM* a, NUM* b);
NUM minus(NUM* a,NUM* b);


NUM a = {{0},1,1}, b = {{0},1,1};
NUM A = {{1},1,1}, B = {{0},1,1}, temp, t1,t2;
int main()
{
    catch(&a, &b);
    int n;  scanf("%d",&n);
    if(n == 0) {printf("1\n"); return 0;}
    while(n > 0) {
        if(n % 2) {
            t1 = mult(&A, &a); t2 = mult(&B, &b);
            temp = minus(&t1,&t2);
            t1 = mult(&a, &B); t2 = mult(&A, &b);
            B = plus(&t1,&t2);
            for(int i=0; i<temp.cnt; ++i) A.a[i] = temp.a[i];
            A.cnt = temp.cnt; A.flag = temp.flag;
            if(A.cnt==1 && A.a[0]==0) A.flag = 1;
            if(B.cnt==1 && B.a[0]==0) B.flag = 1;
        }
        t1 = mult(&a, &a); t2 = mult(&b, &b);
        temp = minus(&t1,&t2);
        t1 = mult(&a, &b);
        b = plus(&t1,&t1);
        for(int i=0; i<temp.cnt; ++i) a.a[i]=temp.a[i];
        a.cnt = temp.cnt; a.flag = temp.flag;
        if(a.cnt==1 && a.a[0]==0) a.flag = 1;
        if(b.cnt==1 && b.a[0]==0) b.flag = 1;
        n /= 2;
    }
    if(A.flag == -1) printf("-");
    if(B.a[0]==0 && B.cnt==1) { //b=0
        for(int i=A.cnt-1; i>=0; --i) printf("%d",A.a[i]);
    }else if(A.cnt==1 && A.a[0]==0) {
        if(B.flag == -1) printf("-");
        if(B.cnt!=1 || B.a[0]!=1)
            for(int i=B.cnt-1; i>=0; --i) printf("%d",B.a[i]);
        printf("i");
    }else {
        for(int i=A.cnt-1; i>=0; --i) printf("%d",A.a[i]);
        printf("%c",B.flag==1 ? '+' : '-');
        if(B.cnt!=1 || B.a[0]!=1)
            for(int i=B.cnt-1; i>=0; --i) printf("%d",B.a[i]);
        printf("i");
    }
    printf("\n");
    return 0;
}


NUM mult(NUM* a, NUM* b) {
    NUM ans = {{0},a->cnt+b->cnt,1};
    if(a->flag != b->flag) ans.flag = -1;
    for(int i=0; i<a->cnt; ++i){
        for(int j=0; j<b->cnt; ++j)
            ans.a[i+j] += a->a[i] * b->a[j];
    }
    int carry = 0;
    for(int i=0; i<a->cnt+b->cnt; ++i) {
        ans.a[i] += carry;
        carry = ans.a[i] / 10;
        ans.a[i] %= 10;
    }
    while(ans.a[ans.cnt]==0 && ans.cnt) --ans.cnt;
    ++ans.cnt;
    return ans;
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

void catch(NUM* pa, NUM* pb) {
    char s[15];
    scanf("%s",s);
    int i = 0, flag;
    while(s[i]) {
        flag = 1;
        if(s[i]=='+' || s[i]=='-') {
            if(s[i] == '-') flag = -1;
            ++i;
        }
        int sum = 0;
        if(s[i] != 'i') {
            for(; isdigit(s[i]); ++i) sum = sum*10 + s[i] - '0';
        }else sum = 1;
        NUM* p = s[i] == 'i'? pb : pa;
        p->cnt = 0;  p->flag = flag;
        do{
            p->a[p->cnt++] = sum % 10;
            sum /= 10;
        }while(sum);
        if(s[i] == 'i') ++i;
    }
}
