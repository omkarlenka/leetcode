//
//  text_justification_lc68.cpp
//
//  Created by omlenka on 14/03/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
    void addExtraSpace(string &s, int extra_space){
        while(extra_space > 0){
            s += " ";
            extra_space--;
        }
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int curr_index = 0;
        
        while(curr_index < n){
            int len = 0;
            int start_index = curr_index;
            while(curr_index < n && len + words[curr_index].length() <= maxWidth){
                len += words[curr_index].length()+1;
                curr_index++;
            }
            len--;
            int extra_space = maxWidth - len;
            string res_tmp = "";
            if(curr_index == n){  //this is last line
                for(int i = start_index; i<curr_index;i++){
                    res_tmp += words[i];
                    if(i != curr_index - 1){
                        res_tmp += " ";
                    }
                }
                
                addExtraSpace(res_tmp, extra_space);
            }
            else{
                int no_of_words = curr_index - start_index;
                int no_of_blanks = no_of_words-1;
                if(no_of_words == 1){
                    res_tmp = words[start_index];
                    addExtraSpace(res_tmp, extra_space);
                    res.push_back(res_tmp);
                    continue;
                }
                
                vector<int> spaces(no_of_blanks,1);
                int i = 0;
                while(extra_space > 0){
                    spaces[i++]++;
                    extra_space--;
                    if(i == no_of_blanks){
                        i = 0;
                    }
                }
                
                i = start_index;
                int j = 0;
                while(i<curr_index){
                    res_tmp += words[i];
                    if(j == no_of_blanks)
                        break;
                    int no_of_spaces = spaces[j++];
                    while(no_of_spaces > 0){
                        res_tmp += " ";
                        no_of_spaces--;
                    }
                    
                    i++;
                }
            }
            res.push_back(res_tmp);
        }
        
        return res;
    }
};

int main() {
    Solution S;
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
    vector<string> res = S.fullJustify(words, maxWidth);
    
    return 0;
}
