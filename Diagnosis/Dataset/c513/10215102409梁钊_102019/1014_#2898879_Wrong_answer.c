#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    int A,B;
    scanf("%d %d",&A,&B);
    int integer = A / B ;
    int mol = A % B , den = B ;
    int n[31];int digits = 0 ;
    if(mol!=0){
        while(mol){
            n[digits++] = mol % 3 ;
            mol /= 3 ;
        }
    }
    int dec_digits = 0 ;
    while(den/3){
        dec_digits++;
        den /= 3 ;
    }
    while(digits<dec_digits) n[digits++] = 0 ; 

    if(integer==0) n[digits++] = 0 ;
    while(integer){
        n[digits++] = integer % 3 ;
        integer /= 3 ;
    }

    int i = 0 ;
    int count=0;
    while(i!=digits){
        if(n[i] + 1 + count >= 3){
            n[i] = n[i] + 1 + count -3 ;
            if(i+1==digits){
                n[i+1]=1;
                digits++ ;
            }
            else n[i+1]++;
        }
        else n[i] = n[i] + 1 + count ;
        count = 0 ;
        i++;
    }
    i = 0 ;
    while(i!=digits){
        n[i]--;
        if(n[i] == -1) n[i] = 2;
        i++ ;
    }
    i = digits-1 ;
    int idx = 0 ;
    while(n[idx++]==0) ;
    while(i!=idx-2){
        if((i+1==dec_digits) && (A % B != 0)) printf(".") ;
        printf("%d",n[i--]);
    }
}