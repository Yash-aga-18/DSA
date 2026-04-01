#include <bits/stdc++.h>
#include "hero.h"
using namespace std;

int main() {
    Hero h1;

    h1.setHealth(100);
    h1.setLevel('A');

    cout << "Health : " << h1.getHealth() << endl;
    cout << "Level  : " << h1.getLevel() << endl;
    cout << "Size   : " << sizeof(h1) << endl;

    return 0;
}
