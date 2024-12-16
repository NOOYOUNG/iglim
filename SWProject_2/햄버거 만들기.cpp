#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    vector<int> burger;
    
    for(int i=0; i<ingredient.size(); i++){
        burger.push_back(ingredient[i]);
        
        if(burger.size()>=4 && burger[burger.size()-1]==1 && burger[burger.size()-2]==3 && burger[burger.size()-3]==2 && burger[burger.size()-4]==1){
            answer++;
            for(int j=0; j<4; j++){
                burger.pop_back();                
            }
        }
    }
    
    return answer;
}