#include<iostream>
#include<fstream>
#include<string>
#include<boost/tokenizer.hpp>
#include<boost/foreach.hpp>

typedef boost::char_separator<char> charsep;
typedef boost::tokenizer<charsep> tokenizer;

using namespace std;

void dump(tokenizer &tokens) {
  BOOST_FOREACH(string s, tokens) {
    cout << s << endl;
  }
}

int read_tokens(string url, tokenizer &tokens) {
  vector<string> ss;
  BOOST_FOREACH(string s, tokens) {
    ss.push_back(s);
  }
  if (ss[0] == url) {
    return stoi(ss[1]);
  } else {
    return -1;
  }
}

int judge_line(string url, string line) {
  charsep sep("\t");
  tokenizer tokens(line, sep);
  return read_tokens(url,tokens);
}

int judge(string url) {
  ifstream ifs;
  ifs.open("data");
  string buf;
  while (ifs && getline(ifs, buf)) {
    int score = judge_line(url, buf);
    if (score >= 0) return score;
  }
  ifs.close();
  return -1;
}
