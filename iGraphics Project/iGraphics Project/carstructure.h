# include "iGraphics.h"
# include "myheader.h"

//int mposx, mposy;
bool musicOn = false;
//bool music = true;
int image[200], timervariabel;
int flag = 0;
int road1, road2, r1, r2, r3;
int ry1=0, ry2=800, car_x = 360, car_y = 50;
int rspeed=3;

/*
function iDraw() is called again and again by the system.
*/
void start(){
	iShowImage(0, ry1, 800, 800, road1);	
	iShowImage(0, ry2, 800, 800, road2);
	iShowImage(car_x, car_y, 140, 140, image[17]);
	iShowImage(210, ry1 + 500, 60, 90, r1);	
	iShowImage(210, ry2 + 500, 60, 90, r2);
	//iShowImage(395, ry1 + 300, 60, 90, r1);
	iShowImage(520, ry1, 60, 90, r1);	
	iShowImage(520, ry2 + 200, 60, 90, r2);
	iShowImage(395, ry1, 40, 40, r3);
	iShowImage(210, ry1 + 300, 40, 40, r3);
	iShowImage(510, ry1 + 600, 40, 40, r3);
	iShowImage(420, ry2 + 300, 40, 40, r3);
	iShowImage(520, ry2 + 600, 40, 40, r3);
}

void background(){
	iShowImage(0, 0, 800, 800, image[18]);
	//iShowImage(10, 720, 100, 50, image[13]);
}

void menu(){
	iShowImage(0, 0, 800, 800, image[0]);//background
	iShowImage(300, 500, 200, 60, image[1]);//play
	iShowImage(300, 420, 200, 60, image[2]);//setting
	iShowImage(300, 340, 200, 60, image[3]);//ins
	iShowImage(300, 260, 200, 60, image[4]);//sb
	iShowImage(300, 180, 200, 60, image[5]);//aboutus
	//iShowImage(300, 100, 200, 60, image[6]);//exit
}

void ins(){
	iShowImage(0, 0, 800, 800, image[7]);
	iShowImage(10, 720, 100, 50, image[13]);
}

void aboutus(){
	iShowImage(0, 0, 800, 800, image[8]);
	iShowImage(10, 720, 100, 50, image[13]);
}

void scoreboard(){
	iShowImage(0, 0, 800, 800, image[9]);
	iShowImage(10, 720, 100, 50, image[13]);
}

void setting(){
	iShowImage(0, 0, 800, 800, image[10]);
	iShowImage(10, 720, 100, 50, image[13]);
}

void exit(){
	iShowImage(0, 0, 800, 800, image[11]);
	iShowImage(10, 720, 100, 50, image[13]);
}

void gameover(){
	iShowImage(0, 0, 800, 800, image[19]);
	iShowImage(600, 180, 80, 80, image[20]);
	iShowImage(100, 180, 80, 80, image[21]);
}

void iDraw(){
	//place your drawing codes here

	iClear();

	if(flag == 0){
		//menu();
		background();
	}
	if(flag == 1){	
		//background();
		menu();
	}	
	if(flag == 2){
		ins();
	}			
	if(flag == 3){	
		aboutus();
	}			
	if(flag == 4){	
		scoreboard();
	}	
	if(flag == 5){
		setting();
	}
	if(flag == 6){
		start();
	}
	if(flag == 7){
		gameover();
	}

	/* iShowImage():
	Here, first 2 parameters are the lower left
	corner position of image you want to put.
	3rd and 4th parameters are the widht and the height
	of the image.
	Last parameter is the id of the image you want to put.
	*/

/*angle in degree*/


}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}
/*
	function iPassiveMouse() is called when the user moves the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iPassiveMouse(int mx, int my)
{
	//place your codes here
}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my){

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		printf("%d, %d", mx, my);
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		printf("%d, %d", mx, my);
	}
	if(flag == 1 && mx >= 300 && mx <= 300 + 200 && my >= 500 && my <= 500 + 60){
		flag = 6;
		//PlaySound(0, 0, 0);
		//PlaySound("music\\car_driving_sound.wav", NULL, SND_LOOP | SND_ASYNC)
	}
	if(flag == 1 && mx >= 300 && mx <= 300 + 200 && my >= 420 && my <= 420 + 60){
		flag = 5;
	}
	if(flag == 1 && mx >= 300 && mx <= 300 + 200 && my >= 340 && my <= 340 + 60){
		flag = 2;
	}
	if(flag == 1 && mx >= 300 && mx <= 300 + 200 && my >= 260 && my <= 260 + 60){
		flag = 4;
	}
	if(flag == 1 && mx >= 300 && mx <= 300 + 200 && my >= 180 && my <= 180 + 60){
		flag = 3;
	}
	if(flag == 1 && mx >= 300 && mx <= 300 + 200 && my >= 100 && my <= 100 + 60){
		flag = 6;
	}
	if(flag == 7 && mx >= 600 && mx <= 600 + 80 && my >= 180 && my <= 180 + 80){
		flag = 6;
	}
	if(flag == 7 && mx >= 100 && mx <= 100 + 80 && my >= 180 && my <= 180 + 80){
		flag = 1;
	}
	//-------------------------------------------------------------------------------------------------------------------

		if(flag == 3 && mx >= 10 && mx < 10 + 100 && my >= 720 && my <= 720 + 50){
		flag = 1;
	}
		if(flag == 2 && mx >= 10 && mx < 10 + 100 && my >= 720 && my <= 720 + 50){
		flag = 1;
	}
		if(flag == 4 && mx >= 10 && mx < 10 + 100 && my >= 720 && my <= 720 + 50){
		flag = 1;
	}
		if(flag == 5 && mx >= 10 && mx < 10 + 100 && my >= 720 && my <= 720 + 50){
		flag = 1;
	}
		/*if(flag == 0 && mx >= 10 && mx < 10 + 100 && my >= 720 && my <= 720 + 50){
		flag = 1;
	}*/

}
/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key){

	if(flag==0 && key =='s'){
	flag=1;
	}
	if (key == 'p'){
		//do something with 'q'
		iPauseTimer(timervariabel);
	}
	if (key == 'r'){
		iResumeTimer(timervariabel);
	}

	//place your codes for other keys here
}
/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key){

	if (key == GLUT_KEY_END){
	
		exit(timervariabel);
	}
	if (key == GLUT_KEY_UP){
		if(car_y >= 0 && car_y < 660){
					car_y += 10;
		}	
	}
	if (key == GLUT_KEY_DOWN){
		if(car_y <= 660 && car_y > 0){
			car_y -= 10;
		}		
	}
	if (key == GLUT_KEY_RIGHT){
		if(car_x >= 150 && car_x < 490){
			car_x += 10;
		}
	}
	if (key == GLUT_KEY_LEFT){
		if(car_x <= 490 && car_x > 150){
			car_x -= 10;
		}		
	}
	
	//place your codes for other keys here
}

void allimage(){

      image[0] = iLoadImage("images\\14.png");
	  image[1] = iLoadImage("images\\1.png");
	  image[2] = iLoadImage("images\\3.png");
	  image[3] = iLoadImage("images\\2.png");
	  image[4] = iLoadImage("images\\4.png");
	  image[5] = iLoadImage("images\\5.png");
	  //image[6] = iLoadImage("images\\6.png");
	  image[7] = iLoadImage("images\\instructions.png");
	  image[8] = iLoadImage("images\\credit.png");
	  image[9] = iLoadImage("images\\sb.png");
	  image[10] = iLoadImage("images\\st.jpg");
	 //image[11] = iLoadImage("images\\tree.png");
	  image[12] = iLoadImage("images\\road2.png");
	  image[13] = iLoadImage("images\\back.png");
	  image[17] = iLoadImage("images\\carsuv1.png");
	  image[18] = iLoadImage("images\\interface.png");
	  image[19] = iLoadImage("images\\GAMEOVER.png");
	  image[20] = iLoadImage("images\\playagain.png");
	  image[21] = iLoadImage("images\\home2.png");

	  road1=iLoadImage("images\\road4.jpg");
	  road2=iLoadImage("images\\road4.jpg");
	  r1 = iLoadImage("images\\CAR1_f.png");
	  r2 = iLoadImage("images\\CAR3_f.png");
	  r3 = iLoadImage("images\\coin2.png");

}
void changeRoad(){
	ry1 = ry1 - 4;
	ry2 = ry2 - 4;

	if(ry1 <= - 800) ry1=800;
	if(ry2 <= - 800) ry2=800;

	
	if(car_y+90>=ry1+500 && car_y<=ry1 + 500 + 120 && car_x-10<=210 && car_x<=210+120){
		//exit(timervariabel);	
		flag = 7;
		car_x = 360;
		car_y = 50;
	}
	if(car_y+90>=ry2+500 && car_y<=ry2 + 500 + 120 && car_x-10<=210 && car_x<=210+120){
		//exit(timervariabel);
		flag = 7;
		car_x = 360;
		car_y = 50;
	}/*
    if(car_y+90>=ry1 && car_y<=ry1 + 500 + 120 && car_x+60>=395 && car_x<=395+120){
		//exit(timervariabel);
		//flag = 1;	
	}*/
	if(car_y+350>=ry1 + 250 && car_y<=ry1 + 250-260 && car_x+90>=520 && car_x<=520+120){
		//exit(timervariabel);
		flag = 7;
		car_x = 360;
		car_y = 50;
	}
	if(car_y+90>=ry2 + 200 && car_y<=ry2 + 200 && car_x+90>=520 && car_x<=520+120){
		//exit(timervariabel);
		flag = 7;
		car_x = 360;
		car_y = 50;
	}
	
}

int main()
{
	//place your own initialization codes here.


	  iInitialize(800, 800, "2D CAR GAME");
  
	//load_images();


	// loading images.
	/* iLoadImage() will return an interger type id
	   for each image you load.
	*/
	 allimage();
	 timervariabel = iSetTimer(15,changeRoad);

	 	if(musicOn){
		PlaySound("music\\ctssong.wav", NULL, SND_LOOP | SND_ASYNC);	
	}
	
	 iStart(); // it will start drawing

	return 0;
}

