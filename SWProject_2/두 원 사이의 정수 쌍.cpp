#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int x=1; x<=r2; x++){
        int maxY=floor(sqrt((long long)r2*r2-(long long)x*x));
        int minY=0;
        if(r1>x){
            minY=ceil(sqrt((long long)r1*r1-(long long)x*x));
        }
        else{
            minY=1;
        }
        
        answer+=(maxY-minY+1);
    }
    
    answer=4*(answer+r2-r1+1);
    
    return answer;
}