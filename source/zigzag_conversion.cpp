class Solution {
public:
	string convert(string s, int numRows) {
	    if(s == "" || numRows == 1) return s;
	    vector<string> str(numRows);
	    int index = -1, direct = 1;
	    for(int i = 0; i < s.length(); ++i){
	        if(index == 0) direct = 1;
	        if(index == numRows - 1) direct = -1;
	        index += direct;
	        str[index] += s[i];
	    }
	    
	    string result = "";
	    for(int i = 0; i < str.size(); ++i){
	        result += str[i];
	    }
	    return result;
	}
};