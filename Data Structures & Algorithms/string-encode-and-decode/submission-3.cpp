class Solution {
public:

    string encode(vector<string>& strs) {
        string sol = ""; // format: X<X-len string>
        for (auto s : strs){
            int len = s.size();
            string lenString = to_string(len);
            sol += lenString;
            sol += '#';
            sol += s;
        }
        return sol;
    }

    vector<string> decode(string s) {
        if (s == "0#") return {""};
        // cout << s << endl;
        vector<string> sol;
        int i = 0;
        int len = 0;
        while (i < s.size()){
            while (s[i] != '#'){
                len = len*10 + (s[i]-'0');
                i++;
            }
            i++;
            string msg = "";
            for (int x = 0; x < len; x++){
                msg += s[i];
                i++;
            }
            sol.push_back(msg);
            len = 0;
        }
        return sol;
    }
};
