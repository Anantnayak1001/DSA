#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool CheckThreeWaySplit(string &input_string){
    int length = input_string.size();

    if(length < 3) return false;

    vector<int> character_count(26, 0);
    for(char character : input_string) {
        character_count[character - 'a']++;
    }
    
    for(int count : character_count){
        if(count >= 3) return true;
    }

    return false;
    // Time Complexity: O(N)
    // Space Complexity: O(26) = O(1)
}

int main(){
    
    string test_string = "ababa";
    cout << (CheckThreeWaySplit(test_string) ? "Possible" : "Not possible");
    
    return 0;
}