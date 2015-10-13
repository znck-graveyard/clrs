/*
 * Insertion Sort, Page 18 (CRLS section 2.1)
 * @author Rahul Kadyan
 */
#include <iostream>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &A) {
  int key, i;
  for (int j = 1; j < A.size(); ++j) {
    key = A[j];
    i = j - 1;
    while (i >= 0 && A[i] > key) {
      A[i + 1] = A[i];
      --i;
    }
    A[i + 1] = key;
  }
}

// Test Case
int main() {
  vector<int> v;
  int n, a;
  cin >> n;
  while(n--) {
    cin >> a;
    v.push_back(a);
  }
  insertion_sort(v);
  for(vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
}
