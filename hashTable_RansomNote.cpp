//******PROBLEM STATEMENT - Hash Tables : Ransom Note******/
//A kidnapper wrote a ransom note but is worried it will be traced back to him. He found a magazine and wants to know if he can cut out whole words from it and use them to create an untraceable replica of his ransom note. The words in his note are case-sensitive and he must use whole words available in the magazine, meaning he cannot use substrings or concatenation to create the words he needs.
//
//Given the words in the magazine and the words in the ransom note, print Yes if he can replicate his ransom note exactly using whole words from the magazine; otherwise, print No.
//
//Input Format
//
//The first line contains two space-separated integers describing the respective values of  (the number of words in the magazine) and  (the number of words in the ransom note).
//The second line contains  space-separated strings denoting the words present in the magazine.
//The third line contains  space-separated strings denoting the words present in the ransom note.
//
//Constraints
//
//.
//Each word consists of English alphabetic letters (i.e.,  to  and  to ).
//The words in the note and magazine are case-sensitive.
//Output Format
//
//Print Yes if he can use the magazine to create an untraceable replica of his ransom note; otherwise, print No.
//
//Sample Input 0
//
//6 4
//give me one grand today night
//give one grand today
//Sample Output 0
//
//Yes
//Sample Input 1
//
//6 5
//two times three is not four
//two times two is four
//Sample Output 1
//
//No


//******CODE******/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool create_ransom_note(unordered_map<string, int> magazine, vector<string> ransom)
{
    unordered_map<string, int>::iterator  mapIt;
    for(vector<string>::const_iterator it=ransom.begin();
            it != ransom.end(); ++it)
    {
        mapIt = magazine.find(*it);
        if( mapIt == magazine.end())// && mapIt->second <= 0 )
        {
            return false;
        }
        else
        {
            mapIt->second--;
            if(mapIt->second == 0)
            {
                magazine.erase(*it);
            }
        }
    }

    return true;
}

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    bool ret_val = false;
    unordered_map<string, int> mag;
    unordered_map<string, int>::iterator  mapIt;

    //Insert magazine words into map "mag"
    for(vector<string>::const_iterator it=magazine.begin(); it != magazine.end(); ++it)
    {
        mapIt = mag.find(*it);
        if( mapIt == mag.end() )
        {
            mag.insert(std::make_pair(*it, 1));
        }
        else
        {
            mapIt->second++;
        }
    }
    ret_val = create_ransom_note(mag, ransom);
    return ret_val;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}

