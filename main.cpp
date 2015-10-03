#include"api.cpp"
#include<bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (int)n; ++i)

typedef vector<int> Dat;

string stringfy(Dat d) {
  ostringstream ss;
  for (int i = 0; i < (int)d.size(); ++i) {
    if (i > 0) ss << ",";
    ss << to_string(d[i]);
  }
  return ss.str();
}

const int beam_width = 5;

random_device rnd;

int main() {
  vector<pair<int,Dat>> window, nextgen;
  Dat v;
  window.emplace_back(0, v);
  while (true) {
    for (auto cand__ : window) {
      auto cand_ = cand__.second;
      REP(i_, 7) REP(j_, 7) {
        Dat cand = cand_;
        int i = 0, j = 0;
        while (i == j ||
            find(cand.begin(), cand.end(), i) != cand.end() || 
            find(cand.begin(), cand.end(), j) != cand.end()) {
          i = rnd() % 1000, j = rnd() % 1000;
        }
        cand.push_back(i);
        cand.push_back(j);
        string query = stringfy(cand);
        vector<pair<string,string>> q;
        q.emplace_back("v", query);
        string res = submit(q);
        try {
          int score = stoi(res);
          nextgen.emplace_back(score, cand);
        } catch (exception e) {
          cout << "error: " << res << endl;
        }
      }
    }
    nextgen.insert(nextgen.end(), window.begin(), window.end());
    if ((int)nextgen.size() > beam_width) {
      sort(nextgen.begin(), nextgen.end(), greater<pair<int,Dat>>());
      nextgen.resize(beam_width);
    }
    window = nextgen;
    nextgen.clear();
  }
  return 0;
}
