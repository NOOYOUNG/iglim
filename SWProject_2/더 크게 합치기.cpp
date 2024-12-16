#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string strA=to_string(a);
    string strB=to_string(b);
    
    int ab=stoi(strA+strB);
    int ba=stoi(strB+strA);
    answer=max(ab,ba);
    
    return answer;
}