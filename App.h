#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include <vector>
#include <cmath>

using namespace std;

class Player;

class Player{

	
	char a;
	bool isNext = false;
	bool isWinner = false;
	bool ai = false;

	
public:

	Player(){
		
	}

	Player(char ee){
	a = ee;
	
		
	}

	Player(char ww, bool b){
		a = ww;
		ai = b;
		
	}

	void setCh(char aa){
		a = aa;
	}

	char getCh(){
		return a;
	}
	
	

	void setIsNext(bool tr){
		isNext = tr;
	}

	bool getIsNext(){
		return isNext;
	}
	
	void setWinner(bool w){
		isWinner = w;
	}

	bool getWinner(){
		return isWinner;
	}

	bool getAi(){
		return ai;
	} 

	//void inCount(){

//}



};



class Vec {
    float x;
    float y;
    
public:
    Vec (){
        x = 0;
        y = 0;
    }
    
    Vec (float x, float y){
        this->x = x;
        this->y = y;
    }
    
    void add (Vec u){
        x += u.x;
        y += u.y;
    }
    
    float getX() const {
        return x;
    }
    
    float getY() const {
        return y;
    }
    
    void setX(float x) {
        this->x = x;
    }
    
    void setY(float y) {
        this->y = y;
    }
    
};

class Rect{
	float x;
	float y;
	float w;
	float h;

	public:
	Rect(float xx, float yy, float ww, float hh){
		x = xx;
		y = yy;
		w = ww;
		h = hh;
	}

	~Rect(){

	}

	void setX(float x1){
		x = x1;
	}

	void setY(float y1){
		y = y1;
	}
	void setW(float w1){
		w = w1;
	}
	void setH(float h1){
		h = h1;
	}

	float getX(){
		return x;
	}

	float getY(){
		return y;
	}
	float getW(){
		return w;
	}
	float getH(){
		return h;
	}

	bool contains(float xx, float yy){
		if(x <= xx &&  (x + w) >= xx && y >= yy && (y-h) <= yy) {
			return true;
		}
		return false;
	}

};


class Line{
	float x1;
	float y1;
	float x2;
	float y2;
	float x3;
	float y3;
	float x4;
	float y4;

	public:
	Line(float x, float y){
		x1 = x;
		y1 = y;
		x2 = x+.3;
		y2 = y-.3;
		x3 = x;
		y3 = y-.3;
		x4 = x+.3;
		y4 = y;

	}

	float getX1(){
		return x1;
	}

	float getY1(){
		return y1;
	}

	float getX2(){
		return x2;
	}

	float getY2(){
		return y2;
	}

	float getX3(){
		return x3;
	}

	float getY3(){
		return y3;
	}

	float getX4(){
		return x4;
	}

	float getY4(){
		return y4;
	}

};

class Tic{
	char a;
public:
	Tic(){
		a = NULL;
	}

	Tic(char aa){
		a = aa;
	}
	
	void setCh(char xo){
		a = xo;
	}

	char getCh(){
		return a;
	}

};



class App: public GlutApp {
    // Maintain app state here
    float mx;
    float my;
	
	vector<Rect> rec;
	vector<Tic> tic;
	vector<Vec> vec;
	vector<Line> line;
	Player p1 = Player('x');
	Player p2 = Player('o',true);
	Player turnP;

	

	float xx;
	float yy;
	int count = 0;


public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void mouseDown(float x, float y);
    void mouseDrag(float x, float y);



};


#endif
