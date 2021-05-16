void pushTrueIP(vector<string> &vs, const string s, int pos, int dots){
    static string ip = ""; if(pos == 0) ip = "";
    if(dots==0){
        if(pos >= s.size()) return;                                                               // kill path
        int num = stoi(s.substr(pos,s.size()-pos));
        if(s.substr(pos,s.size()-pos).size() > 1 && s.substr(pos,s.size()-pos)[0] == '0') return; // kill path
        if(num >= 0 && num <= 255) {vs.push_back(ip+to_string(num)); return;}                     // reached a possible ip
        else return;              								  // kill path
    }
    else if (s.size() - 1 - pos < dots) return;	        // kill path
    for(int i = 1; i <=3; i++){
        if(i != 1 && s[pos] == '0') return;	        // kill path
        string str = "";
        if(s.size()-pos >= i) str = s.substr(pos, i);
        else return; 					// kill path
        int num = stoi(str);
        if(num >= 0 && num <= 255){
            string temp = ip;
            ip+=str;
            ip+=".";
            pushTrueIP(vs, s, pos + str.size(), dots-1);
            ip = temp;
        }
    }
}

vector<string> genIp(string &s) {
    vector<string> vs;
    if(s.size() > 12) return vs;
    pushTrueIP(vs, s, 0, 3);
    return vs;
}