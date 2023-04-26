//1055
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int A=0, B=0, flag1=1, flag2=1;
typedef struct{
    int num[110];  //倒着存数字
    int len;  //长度
    int flag;  //符号
}Fuc;
void getAB(char *s){
    int len = strlen(s);
    if(s[len-1]!='i'){ //若没有i，故只有A
        A = atoi(s);
        if(A<0){
            A *= -1;
            flag1 *= -1;
        }
        return;
    }
    int i=0, flag=1, temp=0;
    if(s[i]=='-'){  //查符号
        flag *= -1;
        i++;
    }
    for(; i<len; i++){
        if(s[i]>='0'&&s[i]<='9'){
            temp = temp*10+(int)s[i]-48;
        }else break;
    }
    if(s[i]=='i'){ //若碰到了i，说明没有A
        B = (temp>0)? temp: 1;
        flag2 = flag;
        return;
    }else{ //否则先赋给A
        A = temp;
        flag1 = flag;
    }
    flag=1; temp=0;
    if(s[i]=='-'){ //查符号
        flag *= -1;
    }
    i++;
    for(; i<len; i++){ //读B
        if(s[i]>='0'&&s[i]<='9'){
            temp = temp*10+(int)s[i]-48;
        }else break;
    }
    B = (temp>0)? temp: 1;
    flag2 = flag;
}
int cmp(Fuc a, Fuc b){  //比较数字大小
    if(a.len>b.len) return 1;
    else if(a.len<b.len) return -1;
    for(int i=a.len-1; i>=0; i--){
        if(a.num[i]>b.num[i]) return 1;
        else if(a.num[i]<b.num[i]) return -1;
    }
    return 0;
}
void multiply(int x, int flag, Fuc num1, Fuc* store){ //高精度*低精度
    memset(store->num, 0, sizeof(store->num));
    int temp=0, pos=0;
    store->flag = flag*num1.flag;
    while(pos<num1.len){
        store->num[pos] = num1.num[pos]*x+temp;
        temp = (store->num[pos])/10;
        store->num[pos++] %= 10;
    }
    while(temp != 0){
        store->num[pos++] = temp%10;
        temp /= 10;
    }
    store->len = pos;
}

void getAns(Fuc* store, Fuc num1, Fuc num2){ //获得该轮结果
    int temp=0;
    memset(store->num, 0, sizeof(store->num));
    if(num1.flag*num2.flag==1){  //高精度加法
        store->len = (num1.len>num2.len)? num1.len: num2.len;
        for(int i=0; i<store->len; i++){
            store->num[i] = num1.num[i]+num2.num[i]+temp;
            temp = (store->num[i])/10;
            store->num[i] %= 10;
        }
        while(temp!=0){
            store->num[(store->len)++] = temp%10;
            temp /= 10;
        }
        store->flag = num1.flag;
    }else{
        int tmp=cmp(num1, num2);
        if(tmp==0){
            store->len = 1;
            store->flag = 1;
            store->num[0] = 0;
        }else{
            if(tmp==-1){ //高精度减法, 绝对值大的在前面
                store->flag = num2.flag;
                Fuc x = num1;
                num1 = num2;
                num2 = x;
            }else{
                store->flag = num1.flag;
            }
            store->len = num1.len;
            for(int i=0; i<store->len; i++){
                store->num[i] = num1.num[i]-num2.num[i]+temp;
                if(store->num[i]<0){
                    store->num[i] += 10;
                    temp = -1;
                }else temp = 0;
            }
            while(store->num[(store->len)-1]==0) (store->len)--;
        }
    }
}
int main(){
    char s[15];
    Fuc ans[2], ret[4];
    int n, temp;
    scanf("%s %d", s, &n);
    if(n==0) printf("0\n");
    else if(n==1) printf("%s\n", s);
    else{
        getAB(s);
        temp = A;
        ans[0].len = 0;
        ans[0].flag = flag1;
        while(temp!=0){ //将A倒着存入ans1
            ans[0].num[ans[0].len++] = temp%10;
            temp /= 10;
        }
        if(ans[0].len==0) ans[0].len++;
        temp = B;
        ans[1].len = 0;
        ans[1].flag = flag2;
        while(temp!=0){ //将B倒着存入ans1
            ans[1].num[ans[1].len++] = temp%10;
            temp /= 10;
        }
        if(ans[1].len==0) ans[1].len++;
        n--;
        while(n--){
            multiply(A, flag1, ans[0], &ret[0]); //A*ans[0], 结果存入ret[0]
            multiply(B, flag2, ans[1], &ret[1]); //B*ans[1], 结果存入ret[1]
            ret[1].flag *= -1; //i*i==-1
            multiply(A, flag1, ans[1], &ret[2]); //A*ans[1], 结果存入ret[2]
            multiply(B, flag2, ans[0], &ret[3]); //B*ans[0], 结果存入ret[3]
            getAns(&ans[0], ret[0], ret[1]);  //ret[0]+ret[1], 结果存入ans[0]
            getAns(&ans[1], ret[2], ret[3]);  //ret[2]+ret[3], 结果存入ans[1]
        }
        temp = 1;
        if(!(ans[0].len==1 && ans[0].num[0]==0)){ //输出部分
            if(ans[0].flag==-1) printf("-");
            for(int i=0; i<ans[0].len; i++) printf("%d", ans[0].num[ans[0].len-i-1]);
            temp = 0; 
        }
        //printf("   %d\n", ans[1].len);

        if(!(ans[1].len==1 && ans[1].num[0]==0)){
            if(ans[1].flag==1 && temp==0) printf("+");
            else if(ans[1].flag==-1) printf("-");
            if(!(ans[1].len==1 && ans[1].num[0]==1)){
                for(int i=0; i<ans[1].len; i++) printf("%d", ans[1].num[ans[1].len-1-i]);
            }
            printf("i");
        }
    }
    return 0;
}
