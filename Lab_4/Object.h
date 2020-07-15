#ifndef OBJECT_H
#define OBJECT_H

class Object {
	int val; 

    public:

        //Static variable
        static int count;

        Object() {
        	count++;
        }
        Object(const Object& obj) {
        	val = obj.val;
        	count++;
        }
};

//int Object::count = 0;

#endif 

