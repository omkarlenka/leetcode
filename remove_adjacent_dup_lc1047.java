//
//  remove_adjacent_dup_lc1047.java
//
//  Created by omlenka on 02/05/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> stk = new Stack<Character>();
        String res = new String();
        for(int i  = 0;i<S.length();i++){
            if(!stk.empty() && (stk.peek() == S.charAt(i))){
                stk.pop();
            }
            else{
                stk.push(S.charAt(i));
            }
        }
        while(!stk.empty()){
            res += String.valueOf(stk.peek());
            stk.pop();
        }
        return new StringBuilder(res).reverse().toString();
    }
}