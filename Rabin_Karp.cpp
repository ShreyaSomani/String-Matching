#include <bits/stdc++.h>
#include <vector>
#include <math.h>
using namespace std;
 
// d is the number of characters in the input alphabet
#define d 26
 
/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(char pat[], char txt[], int q,vector<int> &T)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt

    int h = ((int)(pow(d,M-1) + 0.5)) % q;  
 
     
    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d * p + int(pat[i])) % q;
        t = (d * t + int(txt[i])) % q;
    }
    T.push_back(t);
 
    // Slide the pattern over text one by one
    for (int s = 0; s <= N - M; s++)
    {
 
        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[s+j] != pat[j])
                    break;
            }
 
            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout<<"Pattern found at index "<< s<<endl;
        }
 
        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( s < N-M )
        {
            t = (d*(t - int(txt[s])*h) + int(txt[s+M]))%q;
           
            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            t = (t + q);
            T.push_back(t);
        }
    }
}
 
/* Driver code */
int main()
{
    char txt[] = "2359023141526739921";
    char pat[] = "31415";
    vector<int> T;
      // A prime number
    int q = 13;
     
      // Function Call
      search(pat, txt, q,T);
     
      for(int i=0;i<T.size();++i)
      cout<<T[i]<<" ";
    return 0;
}