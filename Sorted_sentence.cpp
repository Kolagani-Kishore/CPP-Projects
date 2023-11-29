/*A sentence is a list of words that are separated by a single space with no leading or trailing spaces. 
Each word consists of lowercase and uppercase English letters.
A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.
For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".*/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string s = "is2 sentence4 This1 a3";
        vector<pair<int, string>>p;
        stringstream sentence(s);
        string word;
        string ans;
        while(sentence >> word)
        {
            int index = word[word.length()-1];
            word.pop_back();
            p.push_back({index,word});
        }

        sort(p.begin(), p.end());

        for(auto it: p)
        {
            ans += it.second;
            ans += " ";
        }

        ans.pop_back();

        cout<<ans<<endl;
        return 0;
}