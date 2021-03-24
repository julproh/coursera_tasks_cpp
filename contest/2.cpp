#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {

    int m, n , a1, a2;
    cin >> n >> m;
    if (m < 2) {
        cout << "-1" << endl;
        return 0;
    }
    vector <vector<int>> m_v(n);
    for (int i = 0; i < m; i++) {
            cin >> a1 >> a2;
        m_v[a1].push_back(a2);
        m_v[a2].push_back(a1); 
    }


    for (int i = 0; i < m_v.size(); i++) {
        for (int j = 0; j< m_v.size(); j++) {
            if (count(m_v[j].begin(), m_v[j].end(),i) && !count(m_v[i].begin(), m_v[i].end(),i)) {
                for (auto p : m_v[j]) {
                    if (!count(m_v[j].begin(), m_v[j].end(),p))
                m_v[i].push_back(p);
                }
            }
        }
    
    }
    int t = n;
    for (int i = 0; i < m_v.size();i++) {
        int s = count(m_v[i]. begin(), m_v[i].end(),i);
        if (s && t > m_v[i].size()) {
                t = m_v[i].size();
        }
    }
   // for (auto i : m_v) {
     //   cout << i.size() << ' ';
    //}
    if (t == n) { 
        cout << "-1" << endl;
        } else { cout << t << endl;} 
    return 0;
}
