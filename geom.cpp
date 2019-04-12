#include "geom.h"

ld powa(ld a, ll b) {
    assert(b >= 0);
    ld answer = 1;
    while (b) {
        if (b & 1) {
            answer *= a;
            b--;
        } else {
            a *= a;
            b /= 2;
        }
    }
    return answer;
}

TPoint::TPoint() {
    x = 0, y = 0, z = 0;
}

TPoint::TPoint(ld _x, ld _y, ld _z) {
    x = _x;
    y = _y;
    z = _z;
}

TPoint TPoint::operator + (const TPoint &a) const {
    return TPoint(x + a.x, y + a.y, z + a.z);
}

TPoint TPoint::operator - (const TPoint &a) const {
    return TPoint(x - a.x, y - a.y, z - a.z);
}

TPoint TPoint::operator * (ld k) const {
    return TPoint(x * k, y * k, z * k);
}

TPoint TPoint::operator / (ld k) const {
    return TPoint(x / k, y / k, z / k);
}

TPoint TPoint::operator * (const TPoint &a) const {
    return TPoint(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
}

ld TPoint::operator ^ (const TPoint &a) const {
    return x * a.x + y * a.y + z * a.z;
}

TPoint TPoint::operator - () const {
    return TPoint(-x, -y, -z);
}

const TPoint TPoint::operator += (const TPoint &a) {
    x += a.x;
    y += a.y;
    z += a.z;
    return *this;
}

const TPoint TPoint::operator -= (const TPoint &a) {
    x -= a.x;
    y -= a.y;
    z -= a.z;
    return *this;
}

const TPoint TPoint::operator *= (ld k) {
    x *= k;
    y *= k;
    z *= k;
    return *this;
}

const TPoint TPoint::operator /= (ld k) {
    x /= k;
    y /= k;
    z /= k;
    return *this;
}

ld TPoint::len() const {
    return sqrt(x * x + y * y + z * z);
}

ld TPoint::sqlen() const {
    return x * x + y * y + z * z;
}

ostream& operator << (ostream& cout, const TPoint& point) {
    return (cout << "{x: " << point.x << ", y: " << point.y << ", z: " << point.z << "}");
}

TMolecul::TMolecul() {
    position = TPoint();
    mass = 0;
    charge = 0;
    velocity = TVector();
    radius = 0;
    name = "NoName";
}

TMolecul::TMolecul(const TPoint& _position,  ld _mass, ld _charge,
        const TVector& _velocity, ld _radius, const string &_name) {
    position = _position;
    mass = _mass;
    charge = _charge;
	velocity = _velocity;
	radius = _radius;
    name = _name;
}

TVector TMolecul::get_Force(const TMolecul &a) {
    TVector r = position - a.position;
    TVector gravicy_force = -r * G * mass * a.mass / powa(r.len(), 3);
    TVector electrical_force = r * K * charge * a.charge / powa(r.len(), 3);
    return gravicy_force + electrical_force;
}

ostream& operator << (ostream& cout, const TMolecul& molecul) {
    return (cout << "Molecul: " << molecul.name << " " << molecul.position << " " << molecul.velocity);
}

TScene::TScene() {
}

TScene::TScene(ld _dt, const vector <TMolecul> &a) {
    dt = _dt;
    moleculs = a;
}

void TScene::set_Dt(ld _dt) {
	dt = _dt;
}

void TScene::add_Molecul(const TMolecul &molecul) {
    moleculs.push_back(molecul);
}

void TScene::move() {
    vector<TVector> cur_force;
    cur_force.assign(moleculs.size(), TVector());
    for (int i = 0; i < (int)moleculs.size(); i++) {
        for (int j = 0; j < (int) moleculs.size(); j++) {
            if (i == j) continue;
            cur_force[i] += moleculs[i].get_Force(moleculs[j]);
        }
    }
    for (int i = 0; i < (int)moleculs.size(); i++) {
        moleculs[i].position += moleculs[i].velocity * dt;
        moleculs[i].position += cur_force[i] / moleculs[i].mass * dt * dt / 2;
        moleculs[i].velocity += cur_force[i] / moleculs[i].mass * dt;
    }
}

ostream& operator << (ostream &cout, const TScene& scene) {
    cout << "Scene" << endl;
    for (const TMolecul& molecul : scene.moleculs) {
        cout << molecul << endl;
    }
    return cout;
}
