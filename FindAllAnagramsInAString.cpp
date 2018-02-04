class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //注意一下vector开的大小，至少开256个，一个ASCII码字符占8个bit，2^8
        //sv,pv分别是s和p对应的哈希表，维护的是每个字符出现的次数，res是结果
        vector<int> sv(256,0), pv(256,0), res;
        if (p.size() > s.size()) return res;
        //先给p的哈希表赋初始值
        for (int i = 0; i < p.size(); ++i) {
            ++sv[s[i]];
            ++pv[p[i]];
        }
        if (sv == pv)
            res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++sv[s[i]];
            //sv保证p窗口长度范围内的s[i]值
            --sv[s[i-p.size()]];
            if (sv == pv) {
                res.push_back(i-p.size()+1);
            }
        }
        return res;
    }
};