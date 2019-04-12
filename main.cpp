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

TScene cur;

void draw() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    for (TMolecul molecul : cur.moleculs) {
        glTranslatef(molecul.position.x / 1e9, molecul.position.y / 1e9, molecul.position.z / 1e9);
        if (molecul.name == "H") {
            glColor3f(1, 0, 0);
        } else {
            glColor3f(0, 1, 0);
        }
        glutSolidSphere(molecul.radius / 500, 40, 50);
    }
    glPopMatrix();
    glFlush();
    glutSwapBuffers();
    cur.move();
    //cerr << cur << endl;
}

void init_Draw(int argc, char** argv, TScene &scene) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1540, 1540);
    glutCreateWindow("Moleculs");
    glEnable(GL_DEPTH_TEST);
    cur = scene;
    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutMainLoop();
}

const int nmax = 2000 * 1000;
const int inf = 2000 * 1000 * 1000;
const ll infl = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll;
const int mod = 1000 * 1000 * 1000 + 7;
const ld pi = acos(-1.0);

int main(int argc, char** argv) {
	//ios_base::sync_with_stdio(false);
    TScene scene;
	scene.set_Dt(1e3);
	scene.add_Molecul(TMolecul(TPoint(0, 0, 0), 6e24, 0, TVector(0, 0, 0), 5, "C"));
	scene.add_Molecul(TMolecul(TPoint(0, 384467000, 0), 7.34e22, 0, TVector(1000, 0, 0), 5, "H"));
	//scene.add_Molecul(TMolecul(TPoint(0, -384467, 0), 7.34e22, 0, TVector(1000, 0, 0), 5, "H"));

    init_Draw(argc, argv, scene);
	return 0;
}
