//=============================================================================
//     PROGRAMMER : B12611009
//     DATE       : 2023-10-10
//     FIELNAME   : HW04DB12611009.CPP
//     DESCRIPTION: This is a program that find words
//=============================================================================
 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer1 = 0;    // Store the total number of words in the Dictionary.txt file
int answer2 = 0;    // Store the total number of valid words for the user input strin
int answer3 = 0;    // Store the answer3

string lower(string words){                 //to lower
    int i=0;
    do{
        words[i] = tolower(words[i]);       //use tolower to lower each char
    }while(words[++i]);
    return words;
}

void load_words(string filename,vector<string> &word_list){
    string words;
    ifstream inFile;
    inFile.open(filename.c_str());    //open file
    while (inFile>>words) {
        word_list.push_back(lower(words));          //add to the list
        answer1++;
    }
    inFile.close();                 //close file
}

string str_reverse(string str){         //reverse string
    int i= str.length();
    string str2(str);
    for(int j=i;j>=0;j--){
        str2[j]=str[i-j-1];             //put each char in reverse
    }
    return str2;
}

void find_longest_reversible_word(string word){
    int l = int(word.length());
    answer2 = (l > answer2) ? l : answer2;              //update if it's longer
}

int is_reversible(string word,vector<string> &word_list,int i){
    if(binary_search(word_list.begin(), word_list.end(), str_reverse(word))){           //search the reverse word
        find_longest_reversible_word(word);
        return (str_reverse(word) == word) ? 2 : 1;
    }
    return 0;
}

int count_reversible_word_pairs(vector<string> &word_list){
    int count = 0;
    for(int i=0;i<answer1+1;i++){
        count += is_reversible(word_list[i], word_list,i);          //add 1 if it's reversible, add 2 if it equal to itself
    }
    return count/2;
}

int main(){
    string filename = "words.txt";        //filename
    vector<string> word_list;
    load_words(filename, word_list);                                        //load words
    answer3 = count_reversible_word_pairs(word_list);                       //answer3
    cout<<answer1<<" "<<answer2<<" "<<answer3<<endl;                        //cout
    
    return 0;
}


