#include <iostream>
#include "PileChainee.h"
using namespace std;

int main() {
  Pile<int> maPile;

  maPile.empiler(10);
  maPile.empiler(30);
  maPile.empiler(40);

  while(!maPile.pileVide()) {
    int item = maPile.sommet();
    cout << item << endl;
    maPile.depiler();
  }
}