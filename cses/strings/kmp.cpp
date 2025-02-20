#include <bits/stdc++.h>
using namespace std;

int main(){
    string text,pattern;
    cin>>text>>pattern;

    vector<int> lps(pattern.size()+1,0);

    // int i=0,j=0;
    // create lps

    int prevlps = 0,i=1;
    while(i<pattern.size()){
        if(pattern[prevlps]==pattern[i]){
            prevlps++;
            lps[i]=prevlps;
            i++;
        }else{
            if(prevlps==0){
                lps[i]=0;
                i++;
            }else{
                prevlps=lps[prevlps-1];
            }
        }
    }

    //check pattern

    i=0;
    int j=0;

    while(i<text.size()){
        if(text[i]==pattern[j]){
            //pattern and text matched so move ahead
            i++;
            j++;
        }else{
            if(j==0){
                //pattern hasn't even matched once
                i++;
            }else{
                //move j to the point till where we have matched the pattern
                j=lps[j-1];
            }
        }

        if(j==pattern.size()){
            //pattern matched at this index (First occurence)
            return i-pattern.size();
        }
    }
    return -1;
}
