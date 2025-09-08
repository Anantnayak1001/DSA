#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool CheckAnagramPair(string& first_string, string& second_string){
    if(first_string.size() != second_string.size()) return false;
    
    vector<int> character_frequency(26, 0);
    
    for(char letter : first_string) {
        character_frequency[letter - 'a']++;
    }
    
    for(char letter : second_string) {
        character_frequency[letter - 'a']--;
    }
    
    for(int frequency : character_frequency) {
        if(frequency != 0) {
            return false;
        }
    }
    return true;
    // Time Complexity: O(N + M)
    // Space Complexity: O(26) = O(1)
}

int main(){
    string input1 = "hello";
    string input2 = "leloh";
    
    bool are_anagrams = CheckAnagramPair(input1, input2);
    cout << "Do the strings form an anagram pair? " << (are_anagrams ? "Yes" : "No");
    
    return 0;
}