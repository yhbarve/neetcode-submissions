class Solution {
public:

    string encode(vector<string>& strs) {
        string sol = "";
        for (auto s : strs){
            int len = s.size();
            sol += to_string(len);
            sol += '#';
            sol += s;
        }
        return sol;
    }

    vector<string> decode(string s) {
        vector<string> sol;
        int len = 0;
        int i = 0;
        while (i < s.size()){
            while (s[i] != '#'){
                len *= 10;
                len += (s[i] - '0');
                i++;
            }
            if (s[i] == '#') i++;
            string str = s.substr(i, len);
            sol.push_back(str);
            i += len;
            len = 0;
        }

        return sol;
    }
};
