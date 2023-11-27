#include<iostream>
#include<string>
using namespace std;

int main()
{
    static string address = "125.42.56.89";
    string defanged;
    for(int i=0; i < address.size(); ++i)
    {
        if(address[i] == '.')
        {
            defanged += "[.]";
        }
        else
        {
            defanged += address[i];
        }
    }
    cout<<defanged<<endl;
    return 0;
}