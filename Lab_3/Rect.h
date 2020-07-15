#define Rect_h
#include <string>
using namespace std;

class Rect{

private:

  float x,y,width,height;

public:
   //constructor

  Rect(float x,float y,float width,float height){

  this.x=x;

  this.y=y;
        this.width=width;
        this.height=height;
  }

    //this function will return tre if a vertex is inside else false
   // as the initial point is left upper point
  
  bool Vec(float x,float y){
  
     if(x>=this.x && x<=this.x+this.width && x<=this.y && x>=this.y- this.height)
  return true;
    else
     return false;
  }


