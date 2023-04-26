#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "char  " <<(int)numeric_limits<char>::min()<<"   "<<(int)numeric_limits<char>::max()<< endl;
    cout << "wchar_t   " <<numeric_limits<wchar_t>::lowest()<<"   "<<numeric_limits<wchar_t>::max()<< endl;
    cout << "short   " <<numeric_limits<short>::min()<<"   "<<numeric_limits<short>::max()<< endl;
    cout << "int   " <<numeric_limits<int>::min()<<"   "<<numeric_limits<int>::max()<< endl;
    cout << "long   " <<numeric_limits<long>::min()<<"   "<<numeric_limits<long>::max()<< endl;
    cout << "float   " <<numeric_limits<float>::lowest()<<"   "<<numeric_limits<float>::max()<< endl;
    cout << "double   " <<numeric_limits<double>::lowest()<<"   "<<numeric_limits<double>::max()<< endl;
    cout << "unsigned   " <<numeric_limits<unsigned>::min()<<"   "<<numeric_limits<unsigned>::max()<< endl;
    cout << "long long   " <<numeric_limits<long long>::min()<<"   "<<numeric_limits<long long>::max()<< endl;

    return 0;
}