#include "App.h"
#include <vector>
#include <random>
#include <iostream>

App::App(const char* label, int x, int y, int w, int h) : GlutApp(label, x, y, w, h) {
	// Initialize state variables

	cout << "Pres q for single player mode. Press w for multiplayer mode. " << endl;
	//RECTANGLES:
	Rect r = Rect(-0.75, 0.75, 0.5, 0.5, false);
	v.push_back(r);
	Rect r1 = Rect(-0.25, 0.75, 0.5, 0.5, false);
	v.push_back(r1);
	Rect r2 = Rect(0.25, 0.75, 0.5, 0.5, false);
	v.push_back(r2);
	Rect r3 = Rect(-0.75, 0.25, 0.5, 0.5, false);
	v.push_back(r3);
	Rect r4 = Rect(-0.25, 0.25, 0.5, 0.5, false);
	v.push_back(r4);
	Rect r5 = Rect(0.25, 0.25, 0.5, 0.5, false);
	v.push_back(r5);
	Rect r6 = Rect(-0.75, -0.25, 0.5, 0.5, false);
	v.push_back(r6);
	Rect r7 = Rect(-0.25, -0.25, 0.5, 0.5, false);
	v.push_back(r7);
	Rect r8 = Rect(0.25, -0.25, 0.5, 0.5, false);
	v.push_back(r8);
	
	num = -1;
	count = 0;
	rand = true;
	player = true;
	mx = 0.0;
	my = 0.0;
}

void App::draw() {

	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set background color to black
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Set up the transformations stack
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Set Color
	glColor3d(1.0, 1.0, 1.0);

	// Yellow X
		//glColor3d(1.0, 1.0, 0.0);
		//glBegin(GL_LINES);
		//glVertex2f(mx, my);
		//glVertex2f(mx + 0.49f, my - 0.49f);
		//glEnd();

		//glColor3d(1.0, 1.0, 0.0);
		//glBegin(GL_LINES);
		//glVertex2f(mx + 0.49f, my);
		//glVertex2f(mx, my - 0.49f);
		//glEnd();


	for (int b = 0; b < v.size(); b++) {
		glColor3d(1.0, 1.0, 0.0);
		glBegin(GL_LINES);
		glVertex2f(v[b].getX(), v[b].getY());
		glVertex2f(v[b].getX() + v[b].getL(), v[b].getY());
		glVertex2f(v[b].getX() + v[b].getL(), v[b].getY());
		glVertex2f(v[b].getX() + v[b].getL(), v[b].getY() - v[b].getW());
		glVertex2f(v[b].getX() + v[b].getL(), v[b].getY() - v[b].getW());
		glVertex2f(v[b].getX(), v[b].getY() - v[b].getW());
		glVertex2f(v[b].getX(), v[b].getY() - v[b].getW());
		glVertex2f(v[b].getX(), v[b].getY());

		if(v[b].getRed()) {
			glVertex2f(v[b].getX()+0.1, v[b].getY()-0.1);
			glVertex2f(v[b].getX() +0.4, v[b].getY()-0.4);
			glVertex2f(v[b].getX() +0.1, v[b].getY()-0.4);
			glVertex2f(v[b].getX() +0.4, v[b].getY() - 0.1);
		}
		glEnd();
		 if (v[b].getGreen()) {
			const float PI= 3.14159;

			glBegin(GL_LINE_LOOP);
			for (int i = 0; i <= 300; i++) {
				double angle = 2 * PI * i / 300;
				double x = cos(angle);
				double y = sin(angle);
				glVertex2d(x*0.15+v[b].getX()+0.25, y*0.15+v[b].getY()-0.25);
			}
			glEnd();
				
		}
	}
		
	

	// We have been drawing everything to the back buffer
	// Swap the buffers to see the result of what we drew
	glFlush();
	glutSwapBuffers();
}

void App::mouseDown(float x, float y) {
	// Update app state
	mx = x;
	my = y;
	vc = Vec(mx, my);

	if (player) {

		for (int c = 0; c < v.size(); c++) {

			if (v[c].contains(vc) && v[c].getBlue() == false) {
				if (num == -1) {
					v[c].setGreen(true);
					num = c;
					v[c].setBlue(true);
				}
				else {
					if (v[num].getGreen()) {
						v[c].setRed(true);
						num = c;
						v[c].setBlue(true);
					}
					else {
						v[c].setGreen(true);
						num = c;
						v[c].setBlue(true);
					}
				}
			}
		}
		
		if (v[0].getGreen() && v[1].getGreen() && v[2].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[0].getGreen() && v[3].getGreen() && v[6].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[0].getGreen() && v[4].getGreen() && v[8].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[1].getGreen() && v[4].getGreen() && v[7].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[2].getGreen() && v[4].getGreen() && v[6].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[2].getGreen() && v[5].getGreen() && v[8].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[3].getGreen() && v[4].getGreen() && v[5].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[6].getGreen() && v[7].getGreen() && v[8].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[0].getRed() && v[1].getRed() && v[2].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[0].getRed() && v[3].getRed() && v[6].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[0].getRed() && v[4].getRed() && v[8].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[1].getRed() && v[4].getRed() && v[7].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[2].getRed() && v[4].getRed() && v[6].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[2].getRed() && v[5].getRed() && v[8].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}

		if (v[3].getRed() && v[4].getRed() && v[5].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[6].getRed() && v[7].getRed() && v[8].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}

	}
	else {
		for (int c = 0; c < v.size(); c++) {
			if (v[c].contains(vc) && v[c].getBlue() == false) {

				v[c].setGreen(true);

				v[c].setBlue(true);
			}
		}
		if (v[0].getGreen() && v[1].getGreen() && v[2].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[0].getGreen() && v[3].getGreen() && v[6].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[0].getGreen() && v[4].getGreen() && v[8].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[1].getGreen() && v[4].getGreen() && v[7].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[2].getGreen() && v[4].getGreen() && v[6].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[2].getGreen() && v[5].getGreen() && v[8].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[3].getGreen() && v[4].getGreen() && v[5].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[6].getGreen() && v[7].getGreen() && v[8].getGreen()) {
			cout << "O has won!!" << endl;
			return;
		}
		if (v[0].getRed() && v[1].getRed() && v[2].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[0].getRed() && v[3].getRed() && v[6].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[0].getRed() && v[4].getRed() && v[8].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[1].getRed() && v[4].getRed() && v[7].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[2].getRed() && v[4].getRed() && v[6].getRed()) {
			cout << "X has won!!" << endl; 
			return;
		}
		if (v[2].getRed() && v[5].getRed() && v[8].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}

		if (v[3].getRed() && v[4].getRed() && v[5].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		if (v[6].getRed() && v[7].getRed() && v[8].getRed()) {
			cout << "X has won!!" << endl;
			return;
		}
		
			for (int c = 0; c < v.size(); c++) {
				if (v[c].getBlue() == false) {

					v[c].setRed(true);

					v[c].setBlue(true);
					break;
				}
			}
		
	}
	// Redraw the scene
	redraw();
}

void App::mouseDrag(float x, float y) {
	// Update app state
	mx = x;
	my = y;

	// Redraw the scene
	redraw();
}

void App::keyPress(unsigned char key) {
	if (key == 27) {
		// Exit the app when Esc key is pressed
		exit(0);
	}

	if (key == 'q') {
		cout << "You will play against the computer. Please, go first." <<endl;
		player = false;
	}

	if (key == 'w') {
		cout << "Multi player mode!" << endl;
	}
}
