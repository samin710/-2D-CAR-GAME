# include "iGraphics.h"
# include "myheader.h"
#include<time.h>

//int mposx, mposy;
bool musicOn = false;
//bool music = true;
int image[200], timervariabel;
int flag = 0;
int road1, road2, r1, r2, r3, r4, r5, r6, r7, r8, r9;
int ry1=0, ry2=800, car_x = 360, car_y = 50;
int carBlack,carWhite,carAsh,carYellow,carBlue,carTruck,coin;
int carBlue_x,carBlue_y;
int carBlack_x,carBlack_y;
int carYellow_x,carYellow_y;
int carTruck_x,carTruck_y;
int carAsh_x,carAsh_y;
int carWhite_x,carWhite_y;
int coin[2][6];


/*
function iDraw() is called again and again by the system.
*/
void fixCollision(int enemy_x, int enemy_y){
    if(abs(enemy_x - car_x) < 60 || abs(enemy_y - car_y) < 90){
         car_x = 360;
         car_y = 50;
    }
}


void start(){
	iShowImage(0, ry1, 800, 800, road1);	
	iShowImage(0, ry2, 800, 800, road2);

	iShowImage(car_x, car_y, 60, 90, image[17]);

	iShowImage(carBlue_x, carBlue_y, 60, 90, carBlue);	
	iShowImage(carYellow_x, carYellow_y, 60, 90, carYellow);
	iShowImage(carWhite_x, carWhite_y, 60, 90, carWhite);	
	iShowImage(carBlack_x, carBlack_y, 60, 90, carBlack);
	//iShowImage(386, carTruck_y, 110, 120, carTruck);
	//iShowImage(500, carAsh_y, 60, 90, carAsh);

	//iShowImage(323, ry2 + 620, 60, 90, r4);
	//iShowImage(521, ry2 + 406, 40, 40, r3);
	//iShowImage(326, ry2 + 200, 60, 90, r8);
	//iShowImage(220, ry1, 40, 40, r3);
	//iShowImage(395, ry1 + 300, 60, 90, r1);
	
	//coin
	//iShowImage(coin_x, coin_y, 40, 40, coin);
	// Drawing random no of coins
   /* int limit = rand()%6 + 3;
    for(int i=0; i<limit; i++)
        iShowImage(coin[0][i], coin[1][i], 40, 40, coin);*/

	/*iShowImage(270, ry1 + 600, 40, 40, r3);
	iShowImage(540, ry1 + 800, 40, 40, r3);
	iShowImage(420, ry2 + 300, 40, 40, r3);
	iShowImage(520, ry2 + 100, 40, 40, r3);*/
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
		printf("(%d, %d) ", mx, my);
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

	  road1=iLoadImage("images\\roadnafis1.png");
	  road2=iLoadImage("images\\roadnafis1.png");
	  carBlack = iLoadImage("images\\carblack.png");
	  carBlue = iLoadImage("images\\carblue.png");
	  coin = iLoadImage("images\\gamecoin.png");

	  carYellow = iLoadImage("images\\caryellow.png");
	 // carSuv = iLoadImage("images\\carsuv.png");
	  carTruck = iLoadImage("images\\cartruck.png");
	 // r7 = iLoadImage("images\\caryellow.png");
	  carWhite = iLoadImage("images\\carwhite.png");
	  carAsh = iLoadImage("images\\carash.png");

}
void changeRoad(){
	ry1 = ry1 - 4;
	ry2 = ry2 - 4;

	carBlack_y -= 5;
	carYellow_y -=5;
	carBlue_y -= 5;
	carWhite_y -= 5;
	//carAsh_y -= 5;
	//carTruck_y -= 5;
	for(int i=0; i<5; i++){
        coin[1][i] -= 5;
    }

	if(carBlack_y<=-90)
	{
		carBlack_x=(rand() % (530-220) )+ 220; 
		carBlack_y = 800;
	}
	if(carWhite_y<=-90)
	{
		carWhite_x=(rand() % (530-220) )+ 220; 
		carWhite_y = 800;
	}
	if(carYellow_y<=-90)
	{
		carYellow_x=(rand() % (530-220) )+ 220; 
		carYellow_y = 800;
	}
	if(carBlue_y<=-90)
	{
		carBlue_x=(rand() % (530-220) )+ 220; 
		carBlue_y = 800;
	}
	/*if(carAsh_y==-90)
	{
		carAsh_y = 800;
	}
	if(carTruck_y==-90)
	{
		carTruck_y = 800;
	} */
	for(int i=0; i<5; i++){
        if(coin[1][i]) <= -40){
            coin[0][i] = rand() % (530-220) + 220;
            coin[1][i] = rand() % 300 + 800;
        }
    }



	if(ry1 <= - 800) ry1=800;
	if(ry2 <= - 800) ry2=800;
	
	/*if(car_y+90>=carBlue && car_y<=carBlue_y && car_x-10<=210 && car_x<=210+120){
		//exit(timervariabel);	
		flag = 7;
		car_x = 360;
		car_y = 50;
	}
	if(car_y+90>=carYellow && car_y<=carYellow_y+90 && car_x-10<=210 && car_x<=210+120){
		//exit(timervariabel);
		flag = 7;
		car_x = 360;
		car_y = 50;
	}/*
    if(car_y+90>=ry1 && car_y<=ry1 + 500 + 120 && car_x+60>=395 && car_x<=395+120){
		//exit(timervariabel);
		//flag = 1;	
	}*/
	/*if(car_y+90>=carWhite_y && car_y<=carWhite_y && car_x+90>=520 && car_x<=520+120){
		//exit(timervariabel);
		flag = 7;
		car_x = 360;
		car_y = 50;
	}
	if(car_y+90>=carBlack_y && car_y<carBlack_y && car_x+90>=520 && car_x<=520+120){
		//exit(timervariabel);
		flag = 7;
		car_x = 360;
		car_y = 50;
	}*/
	/*if(car_y+90>=carWhite_y && car_y<=carWhite_y+90 && car_x+50>=carWhite_x && car_x<=carWhite_x+50)
	{
		//flag = 7;
		car_x=360;
		car_y=50;
		
	}
	if(car_y+90>=carBlue_y && car_y<=carBlue_y+90 && car_x>=carBlue_x && car_x<=carBlue_x+50)
	{
		//flag = 7;
		car_x=360;
		car_y=50;
	}
	if(car_y+90>=carBlack_y && car_y<=carBlack_y+90 && car_x+50>=carBlack_x && car_x<=carBlack_x+50)
	{
		//flag = 7;
		car_x=360;
		car_y=50;
	}
	if(car_y+90>=carYellow_y && car_y<=carYellow_y+90 && car_x+50>=carYellow_x && car_x<=carYellow_x+50)
	{
		//flag = 7;
		car_x=360;
		car_y=50;
	}*/

	fixCollision(carBlue_x,carBlue_y);
	fixCollision(carBlack_x,carBlack_y);
	fixCollision(carWhite_x,carWhite_y);
	fixCollision(carYellow_x,carYellow_y);
}


int main()
{
	srand(time(0));
	iSetTimer(15, changeRoad);
	//place your own initialization codes here.
	carBlack_x = 520;
	carYellow_x = 210;
	carBlue_x = 335;
	carWhite_x = 195;

	/*for(int i=0; i<5; i++){
        coin[0][i] = rand() % 200 + 200;
        coin[1][i] = rand() % 250 + 250;
    }
	*/
	carBlack_y  =700;
	carYellow_y =500;
	carBlue_y  =750;
	carWhite_y =600;
	carAsh_y =800;
	carTruck_y =500;


	  iInitialize(800, 800, "2D CAR GAME");
  
	//load_images();


	// loading images.
	/* iLoadImage() will return an interger type id
	   for each image you load.
	*/
	 allimage();
	 //timervariabel = iSetTimer(15,changeRoad);

	 	if(musicOn){
		PlaySound("music\\ctssong.wav", NULL, SND_LOOP | SND_ASYNC);	
	}
	
	 iStart(); // it will start drawing

	return 0;
}