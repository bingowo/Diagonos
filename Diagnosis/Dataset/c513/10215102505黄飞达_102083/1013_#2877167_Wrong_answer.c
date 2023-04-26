#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int gcd(int a, int b){
    int c;
    while (b){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    int arr[50] = {0}, table[3] = {0, 1, -1};
    char ch;
    int index = 0, pointPos = -1;
    int lres = 0, rres1 = 0, rres2 = 0;
    while ((ch = getchar()) != '\n'){
        if (ch != '.') arr[index++] = ch - '0';
        else{
            pointPos = index;
            index++;
        }
    }
    if (pointPos == -1){
        for (int i = 0; i < index; i++){
            lres += table[arr[i]] * pow(3, index-1-i);
        }
    }
    else{
        for (int i = 0; i < pointPos; i++){
            lres += table[arr[i]] * pow(3, pointPos-1-i);
        }        
        for (int i = pointPos + 1; i < index; i++){
            rres1 += table[arr[i]] * pow(3, index-i-1);
        }
        rres2 = pow(3, index-pointPos-1);   
        int t;
        while (1){
            t = gcd(rres2, rres1);
            if (t == 1 || t == -1) break;
            else{
                rres2 /= t;
                rres1 /= t;
            }
        }    
    }
    if (lres > 0 && rres1 > 0) printf("%d %d %d\n", lres, rres1, rres2);
    else if (rres1 == 0) printf("%d\n", lres);
    else if (lres == 0) printf("%d %d\n", rres1, rres2);
    else if (lres<-1 && rres1>0) printf("%d %d %d\n", lres+1, rres2-rres1, rres2);
    else if (-1<=lres && rres1>0) printf("%d %d\n", -(rres2-rres1), rres2);
    else if (lres>1 && rres1<0) printf("%d %d %d\n", lres-1, rres2+rres1, rres2);
    else if (lres<=1 && rres1<0) printf("%d %d\n", rres1+rres2, rres2);
    else if (lres<0 && rres1<0) printf("%d %d %d\n", lres, -rres1, rres2);

    return 0;

// >1>全部

// >=只输出lres
// ==只输出lres
// <=只输出lres

// =>只输出rres
//-1<=l<0,r>0只输出变号取余rres
//l<-1,r>0 

// =<只输出rres
//0<l<=1,r<0 只输出变号取余rres
//l>1,r>0

// l>1,r<0  lres-1，rres取余
// l<-1,r>0 lres+1， rres1取余

// <<rres1符号去掉

//2.1-> l=-1 r=5\9
}