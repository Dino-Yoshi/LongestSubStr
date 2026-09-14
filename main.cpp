#include <iostream>
#include <unordered_set>

using namespace std;

/*
*potential n^2 solution

variable to keep track of the longest seen substring

outer loop: at this index, how far can you go down the chain.
    inner loop, starting from outer index + 1, how many unique characters can we string together before we encounter a duplicate?
        should also initalize a way to keep track of unique characters.
    once inner loop breaks either to early term or length cap, compare the sizes, and overwrite with the actual integer size.

"abcabcbb"
first examine a
    from b, keep chaining until we see a duplicate.
    we'll end up seeing the full substring abc before our duplicate a makes us terminate.
    0 < 3, so abc is our new substring.

then from b
    from c keep chaning until we see a duplicate.
    we'll end up seeing the full substring bca before we see a 'b' duplicate.
    3 == 3, so nothing is changed.

so on and so forth.
 */

int lengthOfLongestSubstring(string s) {

    int longestSeen = 0;

    for (int i = 0; i < s.length(); i++) {
        unordered_set<string> seen;
        seen.insert(s.substr(i, 1));
        for (int j = i + 1; j < s.length(); j++) {
            if (seen.count(s.substr(j, 1)) > 0) {
                break;
            }
            seen.insert(s.substr(j, 1));
        }
        longestSeen = max(longestSeen, static_cast<int>(seen.size()));
    }


    return longestSeen;
}

int main() {

    cout << "Expected: 3 | Actual: " << lengthOfLongestSubstring("dvdf") << endl;
    cout << "Expected: 2 | Actual: " << lengthOfLongestSubstring("abba") << endl;
    cout << "Expected: 5 | Actual: " << lengthOfLongestSubstring("tmmzuxt") << endl;
    cout << "Expected: 3 | Actual: " << lengthOfLongestSubstring("pwwkew") << endl;
    cout << "Expected: 10 | Actual: " << lengthOfLongestSubstring("abcdefaghijaa") << endl;
    cout << "Expected: 6 | Actual: " << lengthOfLongestSubstring("aabcdeffgh") << endl;
    cout << "Expected: 7 | Actual: " << lengthOfLongestSubstring("aabbcdefgh") << endl;
    cout << "Expected: 3 | Actual: " << lengthOfLongestSubstring("abcabc") << endl;
    cout << "Expected: 7 | Actual: " << lengthOfLongestSubstring("abc def ghi") << endl;
    cout << "Expected: 4 | Actual: " << lengthOfLongestSubstring("abc  def   ghi") << endl;
    cout << "Expected: 10 | Actual: " << lengthOfLongestSubstring("ab!cd@ef#gh!ij") << endl;
    cout << "Expected: 9 | Actual: " << lengthOfLongestSubstring("a1b2c3d4a1e5") << endl; // this is actually wrong
    cout << "Expected: 6 | Actual: " << lengthOfLongestSubstring("aAbBcCaA") << endl;
    cout << "Expected: 2 | Actual: " << lengthOfLongestSubstring("abababababababababab") << endl;
    cout << "Expected: 9 | Actual: " << lengthOfLongestSubstring("abcabcbbdefghijkd") << endl;
    cout << "Expected: 26 | Actual: " << lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyza") << endl;
    cout << "Expected: 16 | Actual: " << lengthOfLongestSubstring("abbaefghijklmnopqrb") << endl;
    cout << "Expected: 26 | Actual: " << lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzz") << endl;
    cout << "Expected: 5 | Actual: " << lengthOfLongestSubstring("anviaj") << endl;
    cout << "Expected: 8 | Actual: " << lengthOfLongestSubstring("abcadbefcgh") << endl;

    return 0;

}
