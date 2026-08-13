#include <bits/stdc++.h>
class Node {
    // submitted on the codestudio
    // Leetcode subscription Q 
public:
  char data;
  bool terminal;
  unordered_map<char, Node *> children;
  int countWordsEndingHere, countWordsStarting;
  Node(char data) {
    this->data = data;
    this->terminal = false;
    this->countWordsEndingHere = this->countWordsStarting = 0;
  }
  void makeTerminal() { this->terminal = true; }
};
class Trie {
public:
  Node *root;
  Trie() { root = new Node('\0'); }

  void insert(string &word) {
    Node *curr = root;
    for (char ch : word) {
      if (curr->children.count(ch)) {
        curr = curr->children[ch];
      } else {
        Node *child = new Node(ch);
        curr->children[ch] = child;
        curr = child;
      }
      curr->countWordsStarting++;
    }
    curr->makeTerminal();
    curr->countWordsEndingHere++;
  }

  int countWordsEqualTo(string &word) {
    Node *curr = root;
    for (char ch : word) {
      if (curr->children.count(ch)) {
        curr = curr->children[ch];
      } else {
        return 0;
      }
    }
    return curr->countWordsEndingHere;
  }

  int countWordsStartingWith(string &word) {
    Node *curr = root;
    for (char ch : word) {
      if (curr->children.count(ch)) {
        curr = curr->children[ch];
      } else {
        return 0;
      }
    }
    return curr->countWordsStarting;
  }

  void erase(string &word) {
    Node *curr = root;
    for (char ch : word) {
      curr = curr->children[ch];
      curr->countWordsStarting--;
    }
    curr->countWordsEndingHere--;
  }
};
