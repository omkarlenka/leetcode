//
//  final_price_lc1475.java
//
//  Created by omlenka on 05/05/21.
//  Copyright © 2021 omkar lenka. All rights reserved.
//

class Solution {
    public int[] finalPrices(int[] prices) {
        Stack<Integer> S = new Stack<Integer>();
        int[] res = new int[prices.length];
        
        for(int i = 0;i<prices.length;i++){
            
            if(S.empty() || prices[i] > prices[S.peek()]){
                S.push(i);
                System.out.println(S);
            }
            else{
                while(!S.empty() && prices[i] <= prices[S.peek()]){
                    int top = S.peek();
                    S.pop();
                    res[top] = prices[top] - prices[i];
                }
                S.push(i);
            }
        }
        
        while(!S.empty()){
            int top = S.peek();
            S.pop();
            res[top] = prices[top];
        }
        return res;
    }
}
