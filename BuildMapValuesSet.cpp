set<string> BuildMapValuesSet(const map<int, string>& m) {
  set <string> s;
  for (auto x : m) {
      s.insert(x.second);
  }
  return s;
}