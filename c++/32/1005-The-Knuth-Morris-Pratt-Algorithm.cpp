/*
 * The Knuth Morris Pratt Algorithm, Page 1005 (CLRS section 32.4)
 * @author Anup Agarwal
 */
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

void buildprefix(vector<int> &prefix, string &pattern){

        int j = 0; int i = 0;
        int c = 1;

        while(c<pattern.length()){
            if(pattern[c]==pattern[i]){
                prefix[c++]=++j;
                i++;
            }
            else{
                j = 0; i = 0; c++;
            }
        }
}


void match(string &pattern,string &given, vector<int> prefix){

    int i = 0, j = 0, k = 0;
    while(i<given.length()){
        while(j<pattern.length()){
            if(pattern[j]==given[i]){
                j++;i++;
            }
        }
        if(j>=pattern.length()){ //Match Found
            printf("Pattern Found at Given Array Index %d \n",k);
            k = i-prefix[j-1];
            j = prefix[j-1];
        }
        else if(j!=pattern.length()&&prefix[j]!=0){ //Possible Match In Current Comparision
            k = i-prefix[j-1];
            j = prefix[j-1];
        }
        else{ //No Possible Match Shift whole pattern
            i++;
            j = 0;
        }
    }

}

int main()
{

    string pattern="cocacolaacocacola";
    string given="cocacolaacocacolaacocacola";

    vector<int> prefix(pattern.size());
    buildprefix(prefix,pattern);
    match(pattern,given,prefix);

    return 0;
}
