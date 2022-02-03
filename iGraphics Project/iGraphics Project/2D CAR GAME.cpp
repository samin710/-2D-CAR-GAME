# include "iGraphics.h"
# include "myheader.h"
# include "time.h"


bool musicOn = false;

int image[200], timervariabel;
int flag = 0;

int road1, road2;
int ry1=0, ry2=800, car_x = 360, car_y = 50;
int carBlack,carWhite,carAsh,carYellow,carBlue,carTruck,coin,coin1,coin2;

int carBlue_x,carBlue_y;
int carBlack_x,carBlack_y;
int carYellow_x,carYellow_y;
int carTruck_x,carTruck_y;
int carAsh_x,carAsh_y;
int carWhite_x,carWhite_y;

int coin_x, coin_y;
int coin1_x, coin1_y;
int coin2_x, coin2_y;

char scr[50], hScore[50], lastScr[50];

int highScore, lastScore;
int score;

/*
function iDraw() is called again and again by the system.
*/
void start(){
	iShowImage(0, ry1, 800, 800, road1);	
	iShowImage(0, ry2, 800, 800, road2);
	iShowImage(car_x, car_y, 140, 140, image[17]);	

	
	iShowImage(carYellow_x, carYellow_y, 60, 90, carYellow);
	iShowImage(carWhite_x, carWhite_y, 60, 90, carWhite);	
	iShowImage(carBlack_x, carBlack_y, 60, 90, carBlack);
	
	//coin

	iShowImage(coin_x, coin_y, 40, 40, coin);
	iShowImage(coin1_x, coin1_y, 40, 40, coin1);
	iShowImage(coin2_x, coin2_y, 40, 40, coin2);
	
	_itoa_s(score, scr,10);
	iSetColor(0, 0, 0);
	iText(600, 700, "SCORE:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(700, 700, scr, GLUT_BITMAP_TIMES_ROMAN_24);
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

		FILE *f = fopen("high score.txt", "r+");
	fscanf(f,"%d", &highScore);
	fclose(f);
	if(score > highScore){
		highScore = score;
		FILE *g = fopen("high score.txt", "w+");
		fprintf(g,"%d", highScore);
		fclose(g);
	}

	_itoa_s(highScore, hScore,10);
	_itoa_s(lastScore, lastScr,10);
	iSetColor(255, 255, 255);
	iText(300, 420, "HIGH SCORE: ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(475, 420, hScore, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(300, 380, "LAST SCORE: ", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(475, 380, lastScr, GLUT_BITMAP_TIMES_ROMAN_24);

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

			if(score > highScore){
		highScore = score;
		FILE *g = fopen("high score.txt", "w+");
		fprintf(g,"%d", highScore);
		fclose(g);
	}
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
	//button
	if(flag == 1 && mx >= 300 && mx <= 300 + 200 && my >= 500 && my <= 500 + 60){
		flag = 6;
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
	
	//back
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
			car_y += 20;
		}	
	}
	if (key == GLUT_KEY_DOWN){
		if(car_y <= 660 && car_y > 0){
			car_y -= 20;
		}		
	}
	if (key == GLUT_KEY_RIGHT){
		if(car_x >= 140 && car_x < 500){
			car_x += 20;
		}
	}
	if (key == GLUT_KEY_LEFT){
		if(car_x <= 500 && car_x > 140){
			car_x -= 20;
		}		
	}

	//---------------------------------------------------------------musuic on/off

	if(key == GLUT_KEY_F1){
		
		 if(musicOn){
				musicOn = false;
		        PlaySound(0, 0, 0);	
	}
		else{
			musicOn = true;
			PlaySound("music\\ctssong.wav", NULL, SND_LOOP | SND_ASYNC); 
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
	  image[10] = iLoadImage("images\\musicimage.jpeg");
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

	  coin = iLoadImage("images\\coin.png");
	  coin1 = iLoadImage("images\\coin.png");
	  coin2 = iLoadImage("images\\coin.png");

	  carYellow = iLoadImage("images\\caryellow.png");
	 // carSuv = iLoadImage("images\\carsuv.png");
	  carTruck = iLoadImage("images\\cartruck.png");
	 // r7 = iLoadImage("images\\caryellow.png");
	  carWhite = iLoadImage("images\\carwhite.png");
	  carAsh = iLoadImage("images\\carash.png");

}
void changeRoad(){

	if(flag != 6 && flag != 7){
		return;
	}

	ry1 = ry1 - 4;
	ry2 = ry2 - 4;

	carBlack_y -= 6;
	carYellow_y -= 6;
	carWhite_y -= 6;


	coin_y -= 4;
	coin1_y -= 4;
	coin2_y -= 4;
	
	if(carBlack_y<=-90)
	{
		carBlack_x=(rand() % (530-395) )+ 395; 
		carBlack_y = 800;
	}
	if(carWhite_y<=-90)
	{
		carWhite_x=(rand() % (396-260) )+ 260; 
		carWhite_y = 800;
	}
	if(carYellow_y<=-90)
	{
		carYellow_x=(rand() % (261-200) )+ 200; 
		carYellow_y = 800;
	}


	if(ry1 <= - 800) ry1=800;
	if(ry2 <= - 800) ry2=800;
	

	//collision
	if(car_y+120>=carWhite_y && car_y<=carWhite_y+90 && car_x+90>=carWhite_x && car_x<=carWhite_x+15)
	{
		flag = 7;
		car_x=360;
		car_y=50;

		carWhite_y =198+ 800;
		carBlack_y  = 402 + 800;
		carYellow_y = 668 + 800;
		
	coin_y = 298+800;
	coin1_y = 44+800;
	coin2_y = 548+800;

	lastScore = score;
	score = 0;
	
	}

	if(car_y+120>=carBlack_y && car_y<=carBlack_y+90 && car_x+100>=carBlack_x && car_x<=carBlack_x+10)
	{
		flag = 7;
		car_x=360;
		car_y=50;

		carWhite_y =198+ 800;
		carBlack_y  = 402 + 800;
		carYellow_y = 668 + 800;

	coin_y = 298+800;
	coin1_y = 44+800;
	coin2_y = 548+800;

	lastScore = score;
	score = 0;
	
	}
	if(car_y+120>=carYellow_y && car_y<=carYellow_y+90 && car_x+90>=carYellow_x && car_x<=carYellow_x+10)
	{
		flag = 7;
		car_x=360;
		car_y=50;

		carWhite_y =198+ 800;
		carBlack_y  = 402 + 800;
		carYellow_y = 668 + 800;

	coin_y = 298+800;
	coin1_y = 44+800;
	coin2_y = 548+800;

	lastScore = score;
	score = 0;
	
	}
}

void coinChange()
{
	if(  car_y+120>=coin_y && car_y<=coin_y+70 && car_x+90>=coin_x && car_x<=coin_x+5)
	{
		score +=5;
		lastScore = score;
		coin_x=(rand() % (530-395) )+ 395; 
		coin_y=800+298;		
		
	}

	if( car_y+120>=coin1_y && car_y<=coin1_y+70 && car_x+90>=coin1_x && car_x<=coin1_x+2)
	{
		score +=5;
		lastScore = score;
		coin1_x=(rand() % (530-395) )+ 395;
		coin1_y=800+44;

	}

	if( car_y+120>=coin2_y && car_y<=coin2_y+70 && car_x+90>=coin2_x && car_x<=coin2_x-2)
	{
		score +=5;
		lastScore = score;
		coin2_x=(rand() % (396-260) )+ 260; 
		coin2_y=800+548;				
	}


	if(coin_y <= -40){
		coin_x=(rand() % (530-395) )+ 395; 
		coin_y=800;
	}
	if(coin1_y <= -40){
		coin1_x=(rand() % (530-395) )+ 395;;
		coin1_y=800;
	}
	if(coin2_y <= -40){
		coin2_x=(rand() % (396-260) )+ 260; 
		coin2_y=800;
	}

}
int main()
{
	srand(time(0));
	iSetTimer(15, changeRoad);
	//place your own initialization codes here.
	iSetTimer(15, coinChange);

	carBlack_x = 283;
	carYellow_x = 450;
	carWhite_x = 321;
	coin_x = 350;
	coin1_x = 495;
	coin2_x = 400;

	carBlack_y  = 402 + 800;
	carYellow_y = 668 + 800;
	carWhite_y =198+ 800;
	coin_y = 298+800;
	coin1_y = 44+800;
	coin2_y = 548+800;

	//srand(time(0));

	iInitialize(800, 800, "2D CAR GAME");

	FILE *f = fopen("high score.txt", "r+");
	fscanf(f,"%d", &highScore);
	fclose(f);
  
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



