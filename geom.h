#pragma once
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long double ld;
typedef long long ll;

const ld K = 8.98e9;
const ld G = 6.67408e-11;

struct TPoint {
    ld x, y, z;
    TPoint();
    TPoint(ld _x, ld _y, ld _z);
    TPoint operator + (const TPoint &a) const;
    TPoint operator - (const TPoint &a) const;
    TPoint operator * (ld k) const;
    TPoint operator / (ld k) const;
    TPoint operator * (const TPoint &a) const;
    TPoint operator - () const;
	const TPoint operator += (const TPoint &a);
	const TPoint operator -= (const TPoint &a);
	const TPoint operator *= (ld k);
	const TPoint operator /= (ld k);
    ld operator ^ (const TPoint &a) const;
    ld len() const;
    ld sqlen() const;
    friend ostream& operator<<(ostream& cout, const TPoint& err);
};

typedef TPoint TVector;

struct TMolecul {
    TPoint position;
	ld mass;
	ld charge;
	TVector velocity;
	string name;
	TMolecul();
	TMolecul(const TPoint& _position,  ld _mass, ld _charge, const TVector& _velocity, const string& _name);
    TVector get_Force(const TMolecul &b);
    friend ostream& operator<<(ostream& cout, const TMolecul& err);
};

struct TScene {
    ld dt;
    vector<TMolecul> moleculs;
    TScene();
    TScene(ld, const vector<TMolecul> &);
	void set_Dt(ld _dt);
	void add_Molecul(const TMolecul &molecul);
    void move();
    friend ostream& operator << (ostream &cout, const TScene& scene);
};
