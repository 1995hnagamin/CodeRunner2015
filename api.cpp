#include"curl.cpp"
#include<vector>
#include<utility>
#include<cstdlib>
#include<unistd.h>
#include<fstream>

using namespace std;

void wait(double t) {
  clock_t clockStart = clock();
  while (clock() - clockStart < t * CLOCKS_PER_SEC);
}

void keep(string url, string res) {
  string filename = "data";
  ofstream os;
  os.open(filename, ios::app);
  os  << url << "\t" << res << endl << endl;
  cout  << url << "\t" << res << endl << endl;
}

string submit(vector<pair<string,string>> args) {
  string token  = "[DATA EXPUNGED]";
  string url    = "https://game.coderunner.jp/query?token=" + token;
  for (pair<string,string> arg:args) {
    url += "&" + arg.first + "=" + arg.second;
  }
  wait(1.01);
  string res = query(url);
  keep(url, res);
  return res;
}
