#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,n;
    cin >> m >> n;
    string mWord; //words in magazine
    string nWord; //words in note
    
    map<string, int> letter; //set words in mgazine as key and how many times they appear as value 
    
    vector<string> note;    // a list with words in notes
    
    for (int i=0;i<m;i++){
        cin >> mWord;
        letter[mWord]++;       
    }
    for (int i=0;i<n;i++){
        cin>> nWord;
        note.push_back(nWord);
    }
    
    string possible = "Yes"; 
    // traverse words in the notes
    for(string nWord: note){
        // if the word is not in the magazine
        if (letter[nWord]==0){
            possible = "No";
            break;
        }
        letter[nWord]--; // cut out the word when it is in the magazine
    }
    cout << possible;
    
    
    
    return 0;
}
