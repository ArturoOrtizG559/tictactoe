#include "App.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

App::App(const char* label, int x, int y, int w, int h): GlutApp(label, x, y, w, h){
    // Initialize state variables which wont change
    mx = 1.0;
    my = 1.0;

	
	srand((unsigned)time(0));
	int t = random()%2;



	if(t%2 == 0){

		p1.setIsNext(true);
		turnP = p1;
		turnP.setIsNext(true);
	}
	else{
		turnP = p2;
		turnP.setIsNext(true);


	}

	xx = -.9;
	yy = .9;
 	for(int i = 0; i < 3; i++){
		
		
		rec.push_back(Rect(xx,yy,.3,.3));	//sets rectangle coordinates
		vec.push_back(Vec(xx+.15,yy-.15));
		line.push_back(Line(xx,yy));
		xx += .4;
		
	}

	xx = -.9;
	yy = .5;

	for(int j = 0;j < 3; j++){
		
		rec.push_back(Rect(xx,yy,.3,.3));
		vec.push_back(Vec(xx+.15,yy-.15));
		line.push_back(Line(xx,yy));
		xx += .4;
	}

	xx = -.9;
	yy = .1;

	for(int k = 0;k < 3; k++){
		
		rec.push_back(Rect(xx,yy,.3,.3));
		vec.push_back(Vec(xx+.15,yy-.15)); //sets center of each rectangle box
		line.push_back(Line(xx,yy));
		xx += .4;
	}

	for(int i = 0;i < rec.size();i++){ // vector for holding values
		tic.push_back(Tic());
	}


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
   
	
	

	


	



	



	for(int i = 0;i < rec.size();i++){
	glColor3d(1.0, 0.0, 1.0);
 	glBegin(GL_POLYGON);
  
    glVertex2f(rec[i].getX(),rec[i].getY());
    glVertex2f(rec[i].getX() + rec[i].getW(), rec[i].getY());
    glVertex2f(rec[i].getX() + rec[i].getW(),rec[i].getY() - rec[i].getH());
    glVertex2f(rec[i].getX(),  rec[i].getY() - rec[i].getH());
    
    glEnd();
	}


	if(!turnP.getWinner() && (count != 9)){

		if(turnP.getIsNext() && !turnP.getAi()){	//checks wheter ai or not 1
			for(int i =0;i< rec.size();i++){	//makes next slection for players //2
				if(rec[i].contains(mx,my) && (tic[i].getCh() == NULL) && turnP.getIsNext()){ //3
			
					tic[i].setCh(turnP.getCh());
					
					
					count++;
					
					//x check
					

					if(p1.getIsNext()){
						p1.setIsNext(false); //switches players
						p2.setIsNext(true);
						turnP = p2;
					
						
						if(p2.getAi()){
							redraw();
						}
					
						}
					else{
						p2.setIsNext(false);
						p1.setIsNext(true);
						turnP = p1;
						
					}

				} //3
						
				
					
				else{
					
					}
				} //2
			} //1
			

		else{
			vector<int> ri;
			int rn;
			for(int i = 0;i < rec.size();i++){
				if(tic[i].getCh() == NULL){
					ri.push_back(i);
				}
			}
			rn = ri[random()%ri.size()];
	
			tic[rn].setCh(p2.getCh());
			p2.setIsNext(false);
			p1.setIsNext(true);
			turnP = p1;
			count++;
			glFlush();
			glutSwapBuffers();
			
		}
		if((tic[0].getCh() == 'x') && (tic[1].getCh() == 'x') && (tic[2].getCh() == 'x')){
						turnP.setWinner(true);
						cout << "player 1 Won!"<<endl;
						
					}
					else if((tic[3].getCh() == 'x') && (tic[4].getCh() == 'x') && (tic[5].getCh() == 'x')){
						turnP.setWinner(true);
						cout << "player 1 Won!"<<endl;
						
					}

					else if((tic[6].getCh() == 'x') && (tic[7].getCh() == 'x') && (tic[8].getCh() == 'x')){
						turnP.setWinner(true);
						cout << "player 1 Won!"<<endl;
						
					}

					else if((tic[0].getCh() == 'x') && (tic[3].getCh() == 'x') && (tic[6].getCh() == 'x')){
						turnP.setWinner(true);
						cout << "player 1 Won!"<<endl;
						
					}

					else if((tic[1].getCh() == 'x') && (tic[4].getCh() == 'x') && (tic[7].getCh() == 'x')){
						turnP.setWinner(true);
						cout << "player 1 Won!"<<endl;
						
					}

					else if((tic[2].getCh() == 'x') && (tic[5].getCh() == 'x') && (tic[8].getCh() == 'x')){
						turnP.setWinner(true);
						cout << "player 1 Won!"<<endl;
						
					}

					else if((tic[0].getCh() == 'x') && (tic[4].getCh() == 'x') && (tic[8].getCh() == 'x')){
						turnP.setWinner(true);
						cout << "player 1 Won!"<<endl;
						
					}

					else if((tic[2].getCh() == 'x') && (tic[4].getCh() == 'x') && (tic[6].getCh() == 'x')){
						turnP.setWinner(true);
						cout << "player 1 Won!"<<endl;
						
					}


					// O check
					else if((tic[0].getCh() == 'o') && (tic[1].getCh() == 'o') && (tic[2].getCh() == 'o')){
						turnP.setWinner(true);
						cout << "player 2 Won!"<<endl;
						
					}
					else if((tic[3].getCh() == 'o') && (tic[4].getCh() == 'o') && (tic[5].getCh() == 'o')){
						turnP.setWinner(true);
						cout << "player 2 Won!"<<endl;
						
					}

					else if((tic[6].getCh() == 'o') && (tic[7].getCh() == 'o') && (tic[8].getCh() == 'o')){
						turnP.setWinner(true);
						cout << "player 2 Won!"<<endl;
						
					}

					else if((tic[0].getCh() == 'o') && (tic[3].getCh() == 'o') && (tic[6].getCh() == 'o')){
						turnP.setWinner(true);
						cout << "player 2 Won!"<<endl;
						
					}

					else if((tic[1].getCh() == 'o') && (tic[4].getCh() == 'o') && (tic[7].getCh() == 'o')){
						turnP.setWinner(true);
						cout << "player 2 Won!"<<endl;
						
					}

					else if((tic[2].getCh() == 'o') && (tic[5].getCh() == 'o') && (tic[8].getCh() == 'o')){
						turnP.setWinner(true);
						cout << "player 2 Won!"<<endl;
						
					}

					else if((tic[0].getCh() == 'o') && (tic[4].getCh() == 'o') && (tic[8].getCh() == 'o')){
						turnP.setWinner(true);
						cout << "player 2 Won!"<<endl;
						
					}

					else if((tic[2].getCh() == 'o') && (tic[4].getCh() == 'o') && (tic[6].getCh() == 'o')){
						turnP.setWinner(true);
						cout << "player 2 Won!"<<endl;
						
					}

					else if(count == 9){
						cout << "Tie Game!"<< endl;
					}

			else{}



}
			
			

	for(int i = 0 ; i < vec.size();i++){	//draws x

	if((tic[i].getCh() == 'x')){
    glColor3d(0.0, 1.0, 1.0);
    glLineWidth(2);
 	glBegin(GL_LINES);
   
    glVertex3f(line[i].getX1(),line[i].getY1(),-1.0);
    glVertex3f(line[i].getX2(), line[i].getY2(),-1.0);

    glVertex3f(line[i].getX3(),line[i].getY3(),-1.0);
    glVertex3f(line[i].getX4(), line[i].getY4(),-1.0);
 
 
    
    glEnd();
}
}

	
for(int i = 0;i < vec.size();i++){	//draws circles
	if(tic[i].getCh() == 'o'){
		for(float theta = 0;theta < 2*M_PI;theta += 0.1){
			glColor3d(0.0,1.0,1.0);
			glBegin(GL_LINES);
			glVertex3f(.1*cos(theta) + vec[i].getX(), .1*sin(theta) + vec[i].getY(),-1.0);
			glVertex3f(.1*cos(theta+.1) + vec[i].getX(), .1*sin(theta+.1) + vec[i].getY(),-1.0);
		glEnd();
		}
	}
}

	

  
    
    // We have been drawing everything to the back buffer
    // Swap the buffers to see the result of what we drew
    glFlush();
    glutSwapBuffers();
}

void App::mouseDown(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::mouseDrag(float x, float y){
    // Update app state
    mx = x;
    my = y;
    
    // Redraw the scene
    redraw();
}

void App::keyPress(unsigned char key) {
    if (key == 27){
        // Exit the app when Esc key is pressed
        exit(0);
    }
}
