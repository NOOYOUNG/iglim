#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string my_string, string is_prefix) {
    int answer = 0;
    vector<string> v;
    string str="";
    for(int i=0; i<my_string.length(); i++){
        str+=my_string[i];
        v.push_back(str);
    }
    
    auto it=find(v.begin(), v.end(), is_prefix);
    if(it!=v.end()){
        answer=1;
    }
    return answer;
}