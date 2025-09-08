#include <iostream>
#include <string>
using namespace std;

void ExchangeChars(char &first, char &second){
    char temporary = first;
    first = second;
    second = temporary;
}

void ExchangeStrings(string &first, string &second){
    string temporary = first;
    first = second;
    second = temporary;
}

void CombineStrings(string &primary, string &secondary){
    primary = primary + " " + secondary;
}

void InvertByCharacter(string &text){
    int length = text.size();
    
    for(int index = 0; index < length/2; index++){
        ExchangeChars(text[index], text[length-index-1]);
    }
}

void InvertByWord(string &text){
    int length = text.size();
    string current_word = "";
    string result = "";
    
    for(int index = length-1; index >= 0; index--){
       if(text[index] != ' '){
           current_word = text[index] + current_word;
        }
        else{
            result += current_word + " ";
            current_word = "";
        }
    }

    if(!current_word.empty()){
        result += current_word;
    }
    text = result;
}

bool CheckVowel(char character){
    char upper_char = toupper(character);
    if(upper_char == 'A' || upper_char == 'E' || upper_char == 'I' || 
       upper_char == 'O' || upper_char == 'U'){
           return true; 
       }
       return false;
}

void RemoveVowels(string &text){
    int length = text.size();
    int write_pos = 0;
    int read_pos = 0;
    
    while(read_pos < length){
        if(!CheckVowel(text[read_pos])){
            text[write_pos++] = text[read_pos];
         }
        read_pos++;
     }
     text.resize(write_pos);
 }
 
 void AlphabetizeStrings(string *collection, int count){
     for(int outer = 0; outer < count-1; outer++){
         for(int inner = 0; inner < count-outer-1; inner++){
             if(collection[inner] > collection[inner+1]){
                 ExchangeStrings(collection[inner], collection[inner+1]);
             }
         }
     }
 }
 
 void ConvertToLowercase(string &input_string){
     int length = input_string.size();
     for(int position = 0; position < length; position++){
         if(input_string[position] >= 'A' && input_string[position] <= 'Z'){
             input_string[position] = input_string[position] + 32;
         }
     }
 }

int main()
{
    string first_text = "Hello";
    string second_text = "Main";
    
    CombineStrings(first_text, second_text);
    cout << "Combined: " << first_text << endl;
    
    InvertByWord(first_text);
    cout << "Reversed by word: " << first_text << endl;
    
    RemoveVowels(first_text);
    cout << "Without vowels: " << first_text << endl;
    
    string fruits[5] = {"apple", "mango", "lichi", "guava", "tomato"};
    int fruit_count = sizeof(fruits) / sizeof(fruits[0]);
    AlphabetizeStrings(fruits, fruit_count);
    
    cout << "Sorted fruits:" << endl;
    for(int i = 0; i < fruit_count; i++){
        cout << fruits[i] << endl;
    }
    
    ConvertToLowercase(second_text);
    cout << "Lowercase: " << second_text;
    
    return 0;
}