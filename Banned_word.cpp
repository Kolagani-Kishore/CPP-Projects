/*Given a string paragraph and a string array of the banned words banned, 
return the most frequent word that is not banned. 
It is guaranteed there is at least one word that is not banned, and that the answer is unique.
The words in paragraph are case-insensitive and the answer should be returned in lowercase.*/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<ctype.h>
#include<string>
#include <sstream>
#include<vector>
using namespace std;

int main()
{
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    char* banned = "hit";
    unordered_map<string, int> frequency;                    
    unordered_set<string> ban(banned.begin(), banned.end());

        for(auto& it : paragraph)
        {
		    if(ispunct(it))
            {
                 it = ' ';
            }
            else
            {
                it = tolower(it);
            }
        }

        stringstream para(paragraph);
        int max =0;
        string ans, words; 
     
        while(para >> words) 
        {
            frequency[words]++;
        }

        for(auto& it:frequency)
        {
            if(it.second > max && !ban.count(it.first))
            {
                max = it.second;
                ans = it.first;
            }
        }

        cout<<ans<<endl;
        return 0;
}