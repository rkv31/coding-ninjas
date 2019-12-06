#include<iostream>
#include<cstring>
using namespace std;
// int editDistance_helper(string s1, string s2, int **output)                //Memoization approach
// {
//     int m = s1.length();
//     int n = s2.length();
    
//     if (m == 0)
//         return n;
        
//     if (n == 0)
//         return m;
    
//     if(output[m][n] != -1) 
// 		return output[m][n];
    
//     int ans;
//     if (s1[0] == s2[0])
//         ans = editDistance_helper( s1.substr(1), s2.substr(1), output );
//     else
//     {
//         int ins = editDistance_helper( s1.substr(1), s2, output );
//         int del = editDistance_helper( s1, s2.substr(1), output );
//         int rep = editDistance_helper( s1.substr(1), s2.substr(1), output );
//         ans = 1 + min(ins, min(del, rep));
//     }
    
//     output[m][n] = ans;
//     return ans;
// }

// int editDistance(string s1, string s2){

//   /*  Don't write main().
//    *  Don't read input, it is passed as function argument.
//    *  Return output and don't print it.
//    *  Taking input and printing output is handled automatically.
//    */
//     int m = s1.length();
//     int n = s2.length();
//     int **output = new int*[m+1];
//     for (int i=0; i <= m; i++)
//     {
//         output[i] = new int[n+1];
//         for(int j=0; j<=n; j++)
//             output[i][j] = -1;
//     }
//     return editDistance_helper(s1, s2, output);
// }

int editDistance(string s1, string s2)            //Dynamic Programming approach
{
    int m = s1.length();
    int n = s2.length();
    int **output = new int*[m+1];
    for(int i=0; i<=m; i++)
    {
        output[i] = new int[n+1];
    }
    
    output[0][0] = 0;
    // Fill 1st row
	for(int j = 1; j <= n; j++) 
		output[0][j] = j;

	// Fill 1st col
	for(int i = 1; i <= m; i++) 
		output[i][0] = i;
    
    for(int i = 1; i <= m; i++) 
    {
		for(int j = 1; j <= n; j++) 
        {
			// Check if 1st char matches
			if(s1[m-i] == s2[n-j]) {
				output[i][j] = output[i-1][j-1];
			}
			else {
				int ins = output[i-1][j];
				int del = output[i][j-1];
				int rep = output[i-1][j-1];
				output[i][j] = 1 + min(ins, min(del, rep));
			}
		}
	}

	return output[m][n];
}

