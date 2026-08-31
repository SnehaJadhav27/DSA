class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char, int> mag;

        for (char ch : magazine) {
            mag[ch]++;
        } 

        for (char ch : ransomNote) {
            if (mag.find(ch) == mag.end() || mag[ch] == 0) {
                return false;
            }

            mag[ch]--;
        }

        return true;
    }
};