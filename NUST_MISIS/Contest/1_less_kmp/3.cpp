#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string& str ) {
    return equal( str.begin(), str.begin() + str.size() / 2,
                  str.rbegin());
}

string longestPalindrome(string &s){
    vector<char> s2(s.size() * 2 + 1, '#');
    //       '#'
    for(int i = 0; i != s.size(); ++i){
        s2[i*2 + 1] = s[i];
    }

    int p[s2.size()];
    int r, c, index, i_mir;
    int maxLen = 1;
    i_mir = index = r = c = 0;

    for(int i = 1; i != s2.size() - 1; ++i){
        i_mir = 2*c-i;

        //       ,
        //         
        p[i] = r > i ? min(p[i_mir], r-i) : 0;

        while(i > p[i] && (i + p[i] + 1) < s2.size() && s2[i - p[i] - 1] == s2[i + p[i] + 1])
            ++p[i];

        if(p[i] + i > r){
            c = i;
            r = i + p[i];
        }

        if(maxLen < p[i]){
            maxLen = p[i];
            index = i;
        }
    }

    //     
    return s.substr((index-maxLen)/2, maxLen);
}
 
int main() {
    string s;
    int numb;
    cin >> numb;
    cin >> s;
    string res = longestPalindrome(s);
    cout << res.size() << "\n";
    return 0;
}
