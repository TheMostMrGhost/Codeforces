#include <iostream>
#include<set>
#include<string>

using namespace std;

int ans(string text);
int main() {
  int t;
  cin >> t;

  for (int ii =0; ii < t; ii++) {
    string temp;
    int num;
    cin >> num >> temp;
    cout << ans(temp) << "\n";

  }
}

int ans(string text) {
  set<string> zbior{};
  char last = text[0];

  for (int ii = 1; ii < text.length(); ii++) {
    string comb="";
    comb += last ;
    comb += text[ii] ;
    zbior.insert(comb);
    last = text[ii];
  }
  return zbior.size();
}
