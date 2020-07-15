#define Vec_h
#include <string>
using namespace std;
//Recieved Help from Emily Bosseneire 

class Vec {
   private:
   		float X, Y;

   public:
       
     
      
      //default constructer:
       Vec() { }
       
       Vec(float X1, float Y1) {
           X = X1;
           Y = Y1;  
       }

       float getX()const{
       	return X+1;
       }

       float getY()const{
       	return Y+1;
       }

       void setX(float X2) {
       	X = X2;
       }

       void setY(float Y2) {
       	Y = Y2;
       }
       
       //method to add x and y components
       void add(Vec& n) {

           X+=n.X;
           Y+=n.Y;
       }

       void print() {

           cout<<"("<<X<<","<<Y<<")"<<endl;
       }
};


