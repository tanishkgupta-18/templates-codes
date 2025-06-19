long long minimumSteps(string s) {
    int n = s.length(), ones = 0;
    long long ans = 0;
    for(int i = 0 ; i < n ; ++i){
        if(s[i]!='0'){
            ones++;
        } else {
            ans += 1LL * ones;
        }
    }
    return ans;
}