#include <stdlib.h>
#include <iostream>
 
void solve(); /* write function solve() to process one case of the problem    */
using namespace std;
struct MyStruct
{
 int n;
 long long int numbers;
};
 
int cmp(const void *a, const void *b)
{
 struct MyStruct d1, d2;
 d1=*((struct MyStruct*)a);
 d2 = *((struct MyStruct*)b);
 if (d1.n != d2.n)
  return d2.n - d1.n;
 else {
  if (d1.numbers > d2.numbers)return 1;
  else return -1;
 }
 
}
void solve() /* Define function solve() to process one case of the problem    */
{
 MyStruct data[10000];
 int n;
 cin >> n;
 for (int i = 0; i <n; i++)
 {
  //int count = 0;
  long long int d = 1;
  data[i].n = 0;
  cin >> data[i].numbers;
  //long long int temp = data[i].numbers;
  for (int j = 0; j < 64; j++)
  {
   if (data[i].numbers&d)
    data[i].n++;
   d = d << 1;
  }
  //data[i].n = count;
 }
 qsort(data, n, sizeof(data[0]), cmp);
 for (int i = 0; i < n-1; i++)
 {
  cout << data[i].numbers<< ' ';
 }
 cout << data[n - 1].numbers<<endl;
 
 
}
 
void init()  /* Define function init() to do global intialization if needed   */
{
 
}
 
/******************************************************************************/
/*                                                                            */
/*  DON'T MODIFY main() function anyway!                                      */
/*                                                                            */
/******************************************************************************/
 
 
int main()
{
 int i, t; init();
 std::cin >> t;
 for (i = 0; i<t; i++)
 {
  std::cout << "case #" << i << ":" << std::endl;
  solve();
 }
 return 0;
}