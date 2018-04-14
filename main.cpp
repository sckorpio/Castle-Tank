#include<stdio.h>
#include<stdlib.h>
#include<gl/glut.h>
//#include<windows.h>
#include<math.h>

#define PI 3.146


int screen=1;
extern GLfloat X=40;
extern GLfloat Y=40;

extern GLfloat Bx=40;
extern GLfloat By=60;


extern GLfloat U=0;

extern GLfloat Ux=0;
extern GLfloat Uy=0;

extern GLfloat Vx=0;
extern GLfloat Vy=0;

extern GLfloat V=0;

extern GLfloat ay=-200;

extern GLfloat Ai=0;

extern GLfloat p=1;
extern GLfloat q=0;

extern GLfloat bp=1;
extern GLfloat bq=0;


int rate=40;
float t=rate/1000.0;

int motion=0;

int E=0;
int EC[6][2]={
              {650,240},
              {800,100},
              {900,100},
              {1100,200},
              {1100,500},
              {1150,580}   };

int Shots=0;

int Hits=0;





void drawString (void *font, float x, float y, char *str)
 {
/* Draws string ’str’ in font ’font’, at world (x,y,0) */
char *ch;
glRasterPos3f(x, y, 0.0);
for (ch= str; *ch; ch++)
glutBitmapCharacter(font, (int)*ch);
 }


 void printscore()
  {       char ch4;  char W[3];
      char *p=W;

  int temp=Shots;

     switch(temp/10)
    {
        case 0:  ch4='0';  break;
        case 1:  ch4='1';  break;
        case 2:  ch4='2';  break;
        case 3:  ch4='3';  break;
        case 4:  ch4='4';  break;
        case 5:  ch4='5';  break;
        case 6:  ch4='6';  break;
        case 7:  ch4='7';  break;
        case 8:  ch4='8';  break;
        case 9:  ch4='9';  break;


    }

     *p=ch4;   p++;




      switch(Shots%10)
    {
        case 0:  ch4='0';  break;
        case 1:  ch4='1';  break;
        case 2:  ch4='2';  break;
        case 3:  ch4='3';  break;
        case 4:  ch4='4';  break;
        case 5:  ch4='5';  break;
        case 6:  ch4='6';  break;
        case 7:  ch4='7';  break;
        case 8:  ch4='8';  break;
        case 9:  ch4='9';  break;


    }
        *p=ch4;




         glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_TIMES_ROMAN_24, 200, 500,W);






temp=Hits;    p=W;

     switch(temp/10)
    {
        case 0:  ch4='0';  break;
        case 1:  ch4='1';  break;
        case 2:  ch4='2';  break;
        case 3:  ch4='3';  break;
        case 4:  ch4='4';  break;
        case 5:  ch4='5';  break;
        case 6:  ch4='6';  break;
        case 7:  ch4='7';  break;
        case 8:  ch4='8';  break;
        case 9:  ch4='9';  break;


    }

     *p=ch4;   p++;




      switch(Hits%10)
    {
        case 0:  ch4='0';  break;
        case 1:  ch4='1';  break;
        case 2:  ch4='2';  break;
        case 3:  ch4='3';  break;
        case 4:  ch4='4';  break;
        case 5:  ch4='5';  break;
        case 6:  ch4='6';  break;
        case 7:  ch4='7';  break;
        case 8:  ch4='8';  break;
        case 9:  ch4='9';  break;


    }
        *p=ch4;  p++;

        *p='\0';




         glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_TIMES_ROMAN_24, 200, 400,W);


  }


void drawTextNum(char ch[],int numtext,int xpos, int ypos)//counting the score
{
    int len;   int i;
    int k;
    k = 0;
    len = numtext - strlen (ch);
    glLoadIdentity ();
    glRasterPos2f( xpos , ypos);
    for (i = 0; i <=numtext - 1; i++)
    {
    if ( i < len )
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'0');
    else
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[k]);
        k++;
    }

    }
}


void displayEnemy(int a,int b)
{
   float x1,y1,x2,y2;
float angle;
double radius=30;

x1=a;   y1=b;
   glColor3f(1.000, 0.271, 0.000);
   glBegin(GL_POLYGON);

   for (angle=1.0f;angle<361.0f;angle+=0.2)
  {
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*radius;
    glVertex2f(x2,y2);
  }

       glEnd();


   glColor3f(1,1,1);
   glPointSize(10);

   glBegin(GL_POINTS);
     glVertex2f(a-10,b+10);
     glVertex2f(a+10,b+10);
     glEnd();


    glFlush();
    glutPostOverlayRedisplay();

}

void Bricks(int X,int Y)
{
     int i;  int x,y;

     glColor3f(0.502, 0.502, 0.502);

    glBegin(GL_POLYGON);
    glVertex2f(X-50,Y);
    glVertex2f(X-50,Y+30);
    glVertex2f(X+50,Y+30);
    glVertex2f(X+50,Y);
    glEnd();


    x=X-80;  y=Y;
    for(i=0;i<3;i++)
    {
         glColor3f(0.184, 0.310, 0.310);

    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    glVertex2f(x,y+40);
    glVertex2f(x+40,Y+40);
    glVertex2f(x+40,y);
    glEnd();

    x=x+60;

    }



}


void doors(int X,int Y)
{
   glColor3f(0.871, 0.722, 0.529);

    glBegin(GL_POLYGON);
    glVertex2f(X,Y);
    glVertex2f(X,Y+30);
    glVertex2f(X+20,Y+30);
    glVertex2f(X+20,Y);
    glEnd();
}

void displayCastle()
{
    glColor3f(0.412,0.412,0.412);

    glBegin(GL_POLYGON);
    glVertex2f(600,0);
    glVertex2f(600,200);
    glVertex2f(700,200);
    glVertex2f(700,0);
    glEnd();



    glColor3f(0.502,0.502,0.502);

    glBegin(GL_POLYGON);
    glVertex2f(700,0);
    glVertex2f(700,100);
    glVertex2f(1100,100);
    glVertex2f(1100,0);
    glEnd();

   glColor3f(0.412,0.412,0.412);

    glBegin(GL_POLYGON);
    glVertex2f(1100,0);
    glVertex2f(1100,500);
    glVertex2f(1200,500);
    glVertex2f(1200,0);
    glEnd();

    Bricks(600+50,200);

    Bricks(600+50,100);

    Bricks(1100+50,200);

    Bricks(1100+50,500);

    doors(600,0);   doors(800,0);    doors(1000,0);    doors(1150,0);  doors(1150,240);



    glColor3f(1.000, 0.843, 0.000);
    glBegin(GL_POLYGON);   //MAIN GATE
    glVertex2f(950,50);
    glVertex2f(1050,50);
    glVertex2f(1050,0);
    glVertex2f(950,0);
    glEnd();


     glColor3f(0.196, 0.804, 0.196);   //GRASS
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,30);
    glVertex2f(600,30);
    glVertex2f(600,0);
    glEnd();




}

void displaytank()
{                                      int t;
    glColor3f(0.855,0.647,0.125);

    glBegin(GL_POLYGON);
    glVertex2f(X+20,Y+10);
    glVertex2f(X-20,Y+10);
    glVertex2f(X-20,Y-10);
    glVertex2f(X+20,Y-10);
    glEnd();


    glColor3f(0.722,0.525,0.043);
    glBegin(GL_POLYGON);
    glVertex2f(X-20,Y+10);
    glVertex2f(X-15,Y+15);
    glVertex2f(X-10,Y+15);
    glVertex2f(X-10,Y+20);
    glVertex2f(X+10,Y+20);
    glVertex2f(X+10,Y+15);
    glVertex2f(X+15,Y+15);
    glVertex2f(X+20,Y+10);
    glEnd();



    glColor3f(0.722,0.525,0.043);
    glBegin(GL_POLYGON);
    glVertex2f(X,Y+10);
    glVertex2f(X+50*p,Y+10+50*q);
    glVertex2f(X+50*p-10*q,Y+10+50*q+10*p);
    glVertex2f(X-10*q,Y+10+10*p);
    glEnd();

float x1,y1,x2,y2;
float angle;
double radius=7;

x1=X-20;   y1=Y-5;

glColor3f(0,0,0);
    for(t=0;t<5;t++)
    {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x1,y1);

for (angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*radius;
    glVertex2f(x2,y2);
}

       glEnd();

       x1+=13;
    }

    glFlush();
    glutPostOverlayRedisplay();

}



void displayBullet()
{
    glColor3f(0.0,0.5,1.0);

    glBegin(GL_POLYGON);
    glVertex2f(Bx,By);
    glVertex2f(Bx+bp*30,By+bq*30);
    glVertex2f(Bx+bp*30-bq*10,By+bq*30+bp*10);
    glVertex2f(Bx-bq*10,By+bp*10);
    glEnd();

    glColor3f(1.0,0.0,0.0);

    glBegin(GL_POLYGON);
    glVertex2f(Bx+bp*30,By+bq*30);
    glVertex2f(((2*Bx-bq*10)/2+bp*(50)),((2*By+bp*10)/2+bq*(50)));
    glVertex2f(Bx+bp*30-bq*10,By+bq*30+bp*10);
    glEnd();


    glFlush();
}

void displayVelocity()
{
   int w,i;  w=(U/100)+1;

    if(motion==0)
    {
       for(i=0;i<w;i++)
       {
            switch(i)
            {
                case 0:glColor3f(0.941,0.902,0.549);break;
                case 1:glColor3f(0.596,0.984,0.596);break;
                case 2:glColor3f(0.196,0.804,0.196);break;
                case 3:glColor3f(1.0,0.647,0.0);break;
                case 4:glColor3f(1.0,0.271,0.0);break;
                case 5:glColor3f(1.0,0.0,0.0);break;
            }





          glBegin(GL_POLYGON);
           glVertex2f(X-50,Y+20+i*5);
           glVertex2f(X-50,Y+30+i*5);
           glVertex2f(X-20,Y+30+i*5);
           glVertex2f(X-20,Y+20+i*5);
           glEnd();
       }

    glFlush();
    }

}
void display()
{

    if(screen == 1)
    {
    glClear(GL_COLOR_BUFFER_BIT);

     glColor3f(1.0, 0.0, 0.0); /* Select white */
    drawString (GLUT_BITMAP_HELVETICA_18, 100, 200,"PRESS 1 to PLAY");

    drawString (GLUT_BITMAP_HELVETICA_18, 100, 300,"PRESS 2 to HELP");

  glClearColor(0.000, 0.545, 0.545,0);
    glClear(GL_COLOR_BUFFER_BIT);

              int X=200;  int Y=400;   float p=0.883;  float q=0.111;                         int t;
    glColor3f(0.502, 0.502, 0.000);

    glBegin(GL_POLYGON);
    glVertex2f(180,400);
    glVertex2f(210,450);
    glVertex2f(510,450);
    glVertex2f(540,400);
    glEnd();

    glColor3f(0.420, 0.557, 0.137);
    glBegin(GL_POLYGON);
    glVertex2f(220,450);
    glVertex2f(240,490);
    glVertex2f(460,490);
    glVertex2f(480,450);
    glEnd();

     glColor3f(0.502, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(260,490);
    glVertex2f(270,530);
    glVertex2f(400,530);
    glVertex2f(440,490);
    glEnd();

    glColor3f(0.502, 0.502, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(390,530);
    glVertex2f(500,590);
    glVertex2f(490,600);
    glVertex2f(350,530);
    glEnd();


float x1,y1,x2,y2;
float angle;
double radius=40;

x1=X;   y1=Y;

glColor3f(0,0,0);
    for(t=0;t<5;t++)
    {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x1,y1);

for (angle=1.0f;angle<361.0f;angle+=0.2)
{
    x2 = x1+sin(angle)*radius;
    y2 = y1+cos(angle)*radius;
    glVertex2f(x2,y2);
}

       glEnd();

       x1+=80;
    }


    displayCastle();
    glFlush();
    glutPostOverlayRedisplay();


    }
    else if(screen == 2)
    {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);

    drawString (GLUT_BITMAP_HELVETICA_18, 100, 500,"Use forward & back ARROW to move tank");

    drawString (GLUT_BITMAP_HELVETICA_18, 100, 400,"Use Top & Down ARROW to set Angle");

    drawString (GLUT_BITMAP_HELVETICA_18, 100, 300,"Use A & Z to Change Speed");

    drawString (GLUT_BITMAP_HELVETICA_18, 100, 200,"PRESS Esc to exit");
    }
    else if(screen==3)
    {

    glClearColor(0.529,0.808,0.922,0.0);
    glClear(GL_COLOR_BUFFER_BIT);

     displayBullet();
    displayCastle();
     displayEnemy(EC[E][0],EC[E][1]);

     displaytank();
     displayVelocity();


         glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 100, 500,"SHOTS---");


   glColor3f(0.0, 0.0, 1.0); /* Select white */
drawString (GLUT_BITMAP_HELVETICA_18, 100, 400,"HITS---");

printscore();

}

else if(screen==4)
        {
                drawString (GLUT_BITMAP_HELVETICA_18, 100, 200,"BYE");
                Sleep(1000); exit(0);
        }
}



void normalkey(unsigned char key,int x,int y)
{

  if(screen==1)
  {
      if(key=='1')
        screen=3;
  }

  else if(screen==2)
  {
      if(key=='1')
        screen=3;
  }
  else if(screen==3)
  {

   if(motion==0)
   {
    if(key==' '||key=='W'||key=='w')
    {
       motion=1;   Shots++;
    }
   }


     if(key=='A'||key=='a')
       {   if(U<700)
           U+=50;  }

    else if(key=='Z'||key=='z')
        U-=50;

        displayVelocity();
        //Sleep(500);

         printf("U=%f\n",U);
       Ux=U*p;   Uy=U*q;

  }
       else if(key==27)
        screen=4;
  }




void specialkey(int key,int x,int y)
{
   if(motion==0)
   {

    switch(key)
    {
        case GLUT_KEY_RIGHT: { if(X<600)  X+=10; }  break;
        case GLUT_KEY_LEFT:  { if(X>0) X-=10;     }  break;
        case GLUT_KEY_UP:    { if(Ai<90) Ai++;    }  break;
        case GLUT_KEY_DOWN:  { if(Ai>0) Ai--;     } break;
    }

    Ux=U*p;   Uy=U*q;

   }



}

int generateEnemy()
{   int W;
    W=rand();

    return(W%6);
}




void Timer(int value)
{

if(screen==3)
{

  if(motion==1)
   {

      Bx=Bx+Vx*t;

      Vy=Vy+ay*t;
      By=By+Vy*t;

      V=sqrt((Vx*Vx)+(Vy*Vy));

      bp=Vx/V;  bq=Vy/V;

       if((Bx<0)||(By<0)||(Bx>1200))
      {   motion=0;  U=0;  }

      else if(((Bx>560)&&(By<200)&&(Bx<730))||((Bx>1100)&&(By<500)))
      {  // motion=0;  U=0;
         Vx=0-Vx;  // Vx=Vx*0.6;
            }
  /*  else if((Bx>700)&&(By<100)&&(Bx<1100))
      {  // motion=0;  U=0;
         Vy=0-Vy;   Vy=Vy*0.6;
            }   */


      if(((Bx<EC[E][0]+25)&&(Bx>EC[E][0]-25))&&((By<EC[E][1]+25)&&(By>EC[E][1]-25)))
      {
          //printf("HIT");
          Hits++;

          E=generateEnemy();        printf("%d of %d\n",Hits,Shots);
      }

   }




   else
   {

       Ux=U*p;   Uy=U*q;
       Bx=X;  By=Y+10;
       Vx=Ux;  Vy=Uy;
       V=U;

        p=cos((Ai*PI)/180.0);
        q=sin((Ai*PI)/180.0);



        bp=p;   bq=q;

   }

   glutPostRedisplay();

}

   glutTimerFunc(rate, Timer,0 ); // timer call at milliseconds
}


void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1200.0, 0.0, 600.0,-1.0,1.0);
}



int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(1200,600);
    glutInitWindowPosition(10,10);
    glutCreateWindow("TANK2");

    init();

    glutDisplayFunc(display);
   // glutIdleFunc(idle);
    glutTimerFunc(0,Timer,25);
    glutKeyboardFunc(normalkey);
    glutSpecialFunc(specialkey);
    glutMainLoop();

    return 0;


}
