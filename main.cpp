#include "geom.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <ctime>
#include <string>
#include <cstring>
#include <unordered_map>
#define mp make_pair
#define pb push_back
#define NAME ""
#define y1 y1_423
#define list lista

using namespace std;

typedef long long ll;
typedef long double ld;

const int nmax = 2000 * 1000;
const int inf = 2000 * 1000 * 1000;
const ll infl = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const int mod = 1000 * 1000 * 1000 + 7;
const ld pi = acos(-1.0);

int main() {
	//ios_base::sync_with_stdio(false);
	TScene scene;
	scene.set_Dt(1e-3);
	scene.add_Molecul(TMolecul(TPoint(0, 0, 0), 1, 0, TVector(0, 0, 0), "C"));
	scene.add_Molecul(TMolecul(TPoint(1, 1, 1), 1, 0, TVector(0, 0, 0), "H"));
	scene.move();
	cout << scene;
	return 0;
}

