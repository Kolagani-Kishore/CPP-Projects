#include<iostream>
#include<string>
#include<unordered_map>
#include<cstdlib>
using namespace std;

int Non_repeating(string input)
{
    for(int i=0; i<input.size(); ++i)
    {
        int count = 0;
        for(int j = 0; j<input.size(); ++j)
        {
            if((input[i] == input[j])&&(i!=j))
            {
                ++count;
            }
        }
        if(!count)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string in = "abcdacb";
    int ans = Non_repeating(in);
    cout<<ans<<endl;
    return 0;
}