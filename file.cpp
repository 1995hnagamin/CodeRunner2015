#include<iostream>
#include<fstream>
#include<string>
#include<boost/tokenizer.hpp>
#include<boost/foreach.hpp>

typedef boost::tokenizer<boost::escaped_list_separator<char>>
BOOST_ESCAPED_LIST_SEP;
typedef boost::tokenizer<boost::escaped_list_separator<char>>
BOOST_TOKENIZER_ESCAPED_LIST;

using namespace std;

void dump(BOOST_TOKENIZER_ESCAPED_LIST &tokens) {
  BOOST_FOREACH(string s, tokens) {
    cout << s << endl;
  }
}

int read_tokens(string url, BOOST_TOKENIZER_ESCAPED_LIST &tokens) {
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
  BOOST_ESCAPED_LIST_SEP sep('\\', '\t', '\"');
  BOOST_TOKENIZER_ESCAPED_LIST tokens(line, sep);
  return read_tokens(url,tokens);
}

int judge(string url, ifstream ifs) {
  string buf;
  while (ifs && getline(ifs, buf)) {
    int score = judge_line(url, buf);
    if (score >= 0) return score
  }
  return -1;
}
