// A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
// Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".
// We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * Gets all the subdomains
 */
vector<string> parser(string s){
  vector<string> result;
  string domain = "";

  for(int i=(int)s.length()-1; i>=0 ; i--){
    if(s[i] == '.'){
      result.push_back(domain);
      domain.insert(domain.begin(), '.');
    }
    else domain.insert(domain.begin(), s[i]);
  }
  result.push_back(domain);

  return result;  
}

vector<string> subdomainVisits(vector<string>& cpdomains) {
  vector<string> result;
  unordered_map<string, int> hash;

  for(string domain : cpdomains){
    int index = 0;
    for(index=0; index<(int)domain.length(); index++) if(domain[index] == ' ') break;

    //Get the count, the link and the subdomains
    string number_as_string = domain.substr(0,index);
    int count = stoi(number_as_string);
    string link = domain.substr(index+1, domain.length());
    vector<string> subdomains = parser(link);
    
    //Adds and updates values in hash
    for(string x : subdomains){
      if(hash.find(x) != hash.end()) hash[x] += count; 
      else hash.emplace(x, count);
    }  
  }

  //Runs through the hash
  auto it = hash.begin();
  while(it != hash.end()){
    result.push_back(to_string(it->second) + " " + it->first);
    it++;
  }

  return result;
}

int main(){
  vector<string> s = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
  vector<string> result = subdomainVisits(s);

  for(string x : result) cout << x << endl;

  return 0;
}