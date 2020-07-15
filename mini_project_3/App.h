#ifndef App_hpp
#define App_hpp
#include <vector>

#include "GlutApp.h"
using namespace std;
class App : public GlutApp {
	// Maintain app state here

	float mx;
	float my;
public:
	class Circle {
	public:
		float x, y, radius;
	};

	class Vec {
	public:
		float x, y;

		Vec() {
			x = 0;
			y = 0;
		}

		Vec(float xc, float yc) {
			x = xc;
			y = yc;

		}
		void add(Vec &n) {
			x += n.x;
			y += n.y;
		}
		void print() {
			cout << "(" << x << ", " << y << ")" << endl;
		}
		static Vec null;
	};


	class Rect : public Vec {
	public:
		float x, y, l, w;
		bool red, green, blue;
		bool sel;

		Rect(float xl, float yl, float ll, float wl, bool color)
		{
			x = xl;
			y = yl;
			l = ll;
			w = wl;
			red = color;
			green = color;
			blue = color;
		}

		float getX() { return x; }
		float getY() { return y; }
		float getL() { return l; }
		float getW() { return w; }
		float getRed() { return red; }
		float getGreen() { return green; }
		float getBlue() { return blue; }

		//void select() { sel = true; }
		//void deselect() {sel = false;}
		//bool selected() {return sel;}

		void setX(float xl) { x = xl; }
		void setY(float yl) { y = yl; }
		void setL(float ll) { l = ll; }
		void setW(float wl) { w = wl; }

		void setRed(float color) { red = color; }
		void setGreen(float color) { green = color; }
		void setBlue(float color) { blue = color; }

		//if mouse is in rectangle make true so it can change color
		//else it stays the same initial color
		bool contains(Vec v) {
			float xis = x + l;
			float yis = y - w;
			
			if (v.x >= x && v.y <= y && v.x <= xis && v.y >= yis) {
				return true;
			}
			else {
				return false;
			}
		}

	};
	int num;
	int count;
	bool player;
	bool rand;

	Vec vc;
	vector<Rect> v;
	unsigned char k;
	// Constructor, to initialize state
	App(const char* label, int x, int y, int w, int h);

	// These are the events we want to handle
	void draw();
	void keyPress(unsigned char key);
	void mouseDown(float x, float y);
	void mouseDrag(float x, float y);
};

#endif

