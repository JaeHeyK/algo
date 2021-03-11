#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
  ifstream in("deck.inp");
  ofstream out("deck.out");
  

  long N;
  long currentNumber;
  long input_count = 0;
  
  in >> N;
  long origSum = (N * (N+1))/2;
  long origSquareSum = (N * (N+1) * (2*N+1))/6;
  long sum = origSum;
  long squareSum = squareSum;


  while(in>>currentNumber) {
    sum -= currentNumber;
    squareSum -= currentNumber*currentNumber;
    input_count++;
  }


  if(N - input_count == 1) {
    out << sum << "\n";
  } else {
    long squareSubOfTwo = 2*squareSum - (sum*sum);
    long subOfTwo = (long) sqrt((double)squareSubOfTwo);

    out << (sum - subOfTwo)/2 << "\n"; 
    out << (sum + subOfTwo)/2 << "\n"; 
  }

  in.close();
  out.close();
  
  return 0;
}