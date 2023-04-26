#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct T{
    string s;
    int n;//string number
    int flag;//have number : flag == 1
};
int sort(const void * a, const void * b);

int main() {
    
	return 0;
}
int sort(const void * a, const void * b){
     return ( *(int*)b - *(int*)a);
}
