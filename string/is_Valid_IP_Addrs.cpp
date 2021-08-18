    int isValid(string s) {
        
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') count++;
        }
        if (count != 3) return 0;

        unordered_set<string> st;
        for (int i = 0; i < 256; i++) st.insert(to_string(i));
        count = 0;
        string temp = "";
        for (int i = 0; i < s.length(); i++) {

            if (s[i] != '.') {
                temp = temp + s[i];
            } else {
                if (st.find(temp) != st.end()) count++;

                temp = "";
            }
        }
        if (st.find(temp) != st.end()) count++;

        if (count == 4)
            return 1;
        else
            return 0;
    }