#include <iostream>
#include <vector>
using namespace std;

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */

	//write your code here
    if (s1.length() == 0)
        return s2.length();
    if (s2.length() == 0)
        return s1.length();
    
    if (s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));
    
    return 1 + min(editDistance(s1.substr(1),s2.substr(1)), 
                   min(editDistance(s1.substr(1), s2), editDistance(s1, s2.substr(1))) );
}