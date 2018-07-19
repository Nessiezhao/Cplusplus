#include <iostream>
using namespace std;
int main()
{
    int intBit = 0xABCD;
    const char* testBit = (char*)(&intBit);
    cout<<hex;
    cout<<"内存中整数intBit的内容为：";
    cout<<(int(testBit[0])&0xff)<<" ";
    cout<<(int(testBit[1])&0xff)<<" ";
    cout<<int(testBit[2])<<" ";
    cout<<int(testBit[3])<<endl;
    return 0;
}
