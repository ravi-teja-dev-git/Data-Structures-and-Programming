#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char * maxSubstringPalindrome(char * s){
    
    //length of the string
    int lenS = strlen(s);
    // keep longest palindrome length as 1 default
    int begin = 0;
    int longest = 1;
    // dp array
    bool dp[lenS][lenS];
    memset( dp, false, lenS*lenS*sizeof(bool) );
    
    // Base case: only one charactor
    for (int i = 0; i < lenS; i++)
    {
        dp[i][i] = true;
    }
    
    // Loop for substring with length of x
    for (int length = 2; length <= lenS; length++)
    {
        // Loop for substring with starting index of x
        for (int start = 0; start < lenS; start++)
        {
            int end = start + length - 1;
            // If end is out of range exit the loop
            if (end >= lenS)
            {
                break;
            }
            
            // Palindrome condition (start and end char must be same) 
            if (s[start] != s[end])
            {
                dp[start][end] = false;
            }
            else
            {
                // If the length is 1 or 2, no need for palindrome consition check
                if (length <= 2)
                {
                    dp[start][end] = true;
                }
                // Check if (start+1 to end-1) is a palindrome substring
                else
                {
                    dp[start][end] = dp[start+1][end-1];
                }
            }
            // Check it the current substing is a palindrome
            if (dp[start][end])
            {
                // Compare the current substring with the longest
                if (length > longest)
                {
                    longest = length;
                    begin = start;
                }
            }
        }
    }
    char *result = malloc(longest+1);
    strncpy(result, s+begin, longest);
    result[longest] = '\0';
    return result;
    
}


int main() {
	// declaring string
    char str[50];
      
    // reading string
    scanf("%s",str);
    char *ans = maxSubstringPalindrome(str);
    printf("%s", ans);
	return 0;
}