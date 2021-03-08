#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

bool isSameString(string& str1, string& str2) {
  if(str1.length() != str2.length()) {
    return false;
  }

  for(int i=0; i<str1.length(); i++) {
    if(str1[i] != str2[i]) {
      return false;
    }
  }
  return true;
}


int main() {
  ifstream in("words.inp");
  ofstream out("words.out");
  //My Code
  
  int N;

  list<string> words; 
  list<string> past_words;
  string input_word;
  
  in >> N;
  for(int word_count = 0; word_count < N; ++word_count) {
    in >> input_word;
    words.push_back(input_word);
  }

  list<string>::iterator word_first = words.begin();
  list<string>::iterator word_second = next(word_first);

  while(words.size() > 1) {
    int iter_count = words.size()/2;
    int is_size_odd = words.size()%2;

    while(iter_count > 0) {
      if(isSameString(*word_first, *word_second)) {
        words.push_back((*word_first));
      } else {
        past_words.push_back((*word_first));
      }
      past_words.push_back((*word_second));
      advance(word_first, 2);
      advance(word_second, 2);

      words.pop_front();
      words.pop_front();
      --iter_count;
    }

    if((words.size() > 1) && is_size_odd == 1) {
      list<string>::iterator it;
      for(it = word_second; it != words.end(); ++it) {
        if(isSameString(*it, *word_first)) {
          break;
        }
      } 
      if(it == words.end()) {
        past_words.push_back(*word_first);
      } else {
        words.push_back(*word_first);
      }
      ++word_first;
      ++word_second;
      words.pop_front();
    }
  }

  if(words.size() == 0) {
    out << "NONE" << "\n";
  } else {
    list<string>::iterator it;
    int final_word_count = 0;
    for(it = past_words.begin(); it != past_words.end(); ++it) {
      if(isSameString(*it, *word_first)) {
        final_word_count++;
      }
    }
    if(final_word_count >= (N/2)) {
      out << *word_first << "\n";
    } else {
      out << "NONE" << "\n";
    }
  }

  in.close();
  out.close();

  return 0;
}