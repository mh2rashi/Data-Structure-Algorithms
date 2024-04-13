// My original solution
class Solution {

#include<cmath>    
public:
    bool isHappy(int n) {
        
        unordered_set<int> seen;
        
        while (true) {
            
            if (n == 1) {
                return true;
            }
            
            else if (seen.find(n) == seen.end()) {
                seen.insert(n);
                
                int new_n = 0;
                
                  while (n > 0) {
                    int digit = n % 10; // Extract the last digit
                    new_n += pow(digit, 2); // Add the square of the digit to the sum
                    n /= 10; // Remove the last digit from the number
                  }

                n = new_n;       
            }
            else {
                return false ;
            }
            
            
            
        }
        
    }
};

// Could prolly copy how to get the digits of a number.




/// Better solution
std::unordered_set<int> seen;
        
        while (n != 1) {
            if (seen.find(n) != seen.end()) {
                return false; // Cycle detected, not a happy number
            }
            
            seen.insert(n); // Add current number to seen set
            
            int new_n = 0;
            while (n > 0) {
                int digit = n % 10;
                new_n += digit * digit; // Square the digit and add to new_n
                n /= 10; // Remove the last digit
            }
            
            n = new_n; // Update n to the new computed value
        }
        
        return true; // If n becomes 1, it's a happy number
    }