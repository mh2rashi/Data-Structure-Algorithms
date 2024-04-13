

// Approach 1

 int maxProfit(vector<int>& prices) {
        
        int profit = 0;

        int i = 0, j = 0;
        
        while (j < prices.size()) {
            
            profit = max(profit, prices[j] - prices[i]);
            
            if (prices[i] > prices[j]) { 
                i++;
            }
            
            else {
                j++;    
            } 
        }
            
         return profit;
            
        };


// Approach 2

    int maxProfit(vector<int>& prices) {
        
        int profit = 0;

        int buy_price = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            
            profit = max(profit, prices[i] - buy_price);
            buy_price = min(buy_price, prices[i]);
        }
        
        return profit;}
};

