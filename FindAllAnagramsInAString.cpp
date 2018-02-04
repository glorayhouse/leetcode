class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //ע��һ��vector���Ĵ�С�����ٿ�256����һ��ASCII���ַ�ռ8��bit��2^8
        //sv,pv�ֱ���s��p��Ӧ�Ĺ�ϣ��ά������ÿ���ַ����ֵĴ�����res�ǽ��
        vector<int> sv(256,0), pv(256,0), res;
        if (p.size() > s.size()) return res;
        //�ȸ�p�Ĺ�ϣ����ʼֵ
        for (int i = 0; i < p.size(); ++i) {
            ++sv[s[i]];
            ++pv[p[i]];
        }
        if (sv == pv)
            res.push_back(0);
        for (int i = p.size(); i < s.size(); ++i) {
            ++sv[s[i]];
            //sv��֤p���ڳ��ȷ�Χ�ڵ�s[i]ֵ
            --sv[s[i-p.size()]];
            if (sv == pv) {
                res.push_back(i-p.size()+1);
            }
        }
        return res;
    }
};