#include<windows.h>
#include<gl/glut.h>
#include<math.h>

void init(void);
void tampil (void);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void timer(int value);
int time=0;
int naik=0,turun=60,kiriL=22,kananr=0;

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1300, 650);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Kelompok 11");
    init();
    glutDisplayFunc(tampil);
    glutTimerFunc(800, timer, 10);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}

void init(void){
    glClearColor(70/255.0, 130/255.0, 180/255.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_LEQUAL);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);

}

void depan(void){
    ///depan
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-55.0, -50.0, 10.0);
    glVertex3f(-55.0, 30.0, 10.0);
    glVertex3f(55.0, 30.0, 10.0);
    glVertex3f(55.0, -50.0, 10.0);
    glEnd();
    ///depan kanan
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(55.0, -50.0, 30.0);
    glVertex3f(55.0, 30.0, 30.0);
    glVertex3f(130.0, 30.0, 30.0);
    glVertex3f(130.0, -50.0, 30.0);
    glEnd();
    ///depan kiri
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-55.0, -50.0, 30.0);
    glVertex3f(-55.0, 30.0, 30.0);
    glVertex3f(-130.0, 30.0, 30.0);
    glVertex3f(-130.0, -50.0, 30.0);
    glEnd();
}

void belakang (void){
    ///belakang
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-180.0, -50.0, -100.0);
    glVertex3f(-180.0, 30.0, -100.0);
    glVertex3f(180.0, 30.0, -100.0);
    glVertex3f(180.0, -50.0, -100.0);
    glEnd();
}

void kiri(void){
    ///kiri
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(-55.0, 30.0, 30.0);
    glVertex3f(-55.0, -50.0, 30.0);
    glVertex3f(-55.0, -50.0, 10.0);
    glVertex3f(-55.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(-130.0, 30.0, 30.0);
    glVertex3f(-130.0, -50.0, 30.0);
    glVertex3f(-130.0, -50.0, -20.0);
    glVertex3f(-130.0, 30.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-130.0, -50.0, -20.0);
    glVertex3f(-130.0, 30.0, -20.0);
    glVertex3f(-180.0, 30.0, -20.0);
    glVertex3f(-180.0, -50.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(-180.0, 30.0, -20.0);
    glVertex3f(-180.0, -50.0, -20.0);
    glVertex3f(-180.0, -50.0, -100.0);
    glVertex3f(-180.0, 30.0, -100.0);
    glEnd();
}

void kanan(void){
    ///kanan
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(55.0, 30.0, 30.0);
    glVertex3f(55.0, -50.0, 30.0);
    glVertex3f(55.0, -50.0, 10.0);
    glVertex3f(55.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(130.0, 30.0, 30.0);
    glVertex3f(130.0, -50.0, 30.0);
    glVertex3f(130.0, -50.0, -20.0);
    glVertex3f(130.0, 30.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(130.0, -50.0, -20.0);
    glVertex3f(130.0, 30.0, -20.0);
    glVertex3f(180.0, 30.0, -20.0);
    glVertex3f(180.0, -50.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(180.0, 30.0, -20.0);
    glVertex3f(180.0, -50.0, -20.0);
    glVertex3f(180.0, -50.0, -100.0);
    glVertex3f(180.0, 30.0, -100.0);
    glEnd();
}

void alas(void){
    int x = 0;
    int a = 0;
    for(int i=0;i<5;i++){
        glColor3f(0*a/255.0, 2*a/255.0, 10*a/255.0);
        ///kanan
        glBegin(GL_POLYGON);
        glVertex3f(55.0, -50.0+x, -100.0);
        glVertex3f(55.0, -50.0+x, 30.0);
        glVertex3f(130.0, -50.0+x, 30.0);
        glVertex3f(130.0, -50.0+x, -20.0);
        glVertex3f(180.0, -50.0+x, -20.0);
        glVertex3f(180.0, -50.0+x, -100.0);
        glEnd();
        ///tengah
        glBegin(GL_POLYGON);
        glVertex3f(55.0, -50.0+x, 10.0);
        glVertex3f(-55.0, -50.0+x, 10.0);
        glVertex3f(-55.0, -50.0+x, -100.0);
        glVertex3f(55.0, -50.0+x, -100.0);
        glEnd();
        ///kiri
        glBegin(GL_POLYGON);
        glVertex3f(-55.0, -50.0+x, -100.0);
        glVertex3f(-55.0, -50.0+x, 30.0);
        glVertex3f(-130.0, -50.0+x, 30.0);
        glVertex3f(-130.0, -50.0+x, -20.0);
        glVertex3f(-180.0, -50.0+x, -20.0);
        glVertex3f(-180.0, -50.0+x, -100.0);
        glEnd();
        x+=20;
        a+=5;
    }
}

void pembatas_kelas(void){
    //TEPI
    glBegin(GL_QUADS);
        glColor3f(224/255.0, 224/255.0, 224/255.0);
        glVertex3f(45.0, -50.0, -20.0);
        glVertex3f(45.0, 30.0, -20.0);
        glVertex3f(110.0, 30.0, -20.0);
        glVertex3f(110.0, -50.0, -20.0);
        glEnd();

        glPointSize(6.0);

         float r=0;
        for(int e=0;e<10;e++){
        glBegin(GL_QUADS);

        glColor3f(255/255.0, 128/255.0, 0/255.0);
        glVertex3f(55+r, 5.0, -19.5-r);
        glVertex3f(55+r, -10.0, -19.5-r);
        glVertex3f(60+r, -10.0, -19.5-r);
        glVertex3f(60+r, 5.0, -19.5-r);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(255/255.0, 128/255.0, 0/255.0);
        glVertex3f(55+r, 5.0-40, -19.5-r);
        glVertex3f(55+r, -10.0-40, -19.5-r);
        glVertex3f(60+r, -10.0-40, -19.5-r);
        glVertex3f(60+r, 5.0-40, -19.5-r);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(255/255.0, 128/255.0, 0/255.0);
        glVertex3f(55+r, 5.0-20, -19.5-r);
        glVertex3f(55+r, -10.0-20, -19.5-r);
        glVertex3f(60+r, -10.0-20, -19.5-r);
        glVertex3f(60+r, 5.0-20, -19.5-r);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(255/255.0, 128/255.0, 0/255.0);
        glVertex3f(55+r, 5.0+20, -19.5-r);
        glVertex3f(55+r, -10.0+20, -19.5-r);
        glVertex3f(60+r, -10.0+20, -19.5-r);
        glVertex3f(60+r, 5.0+20, -19.5-r);
        glEnd();

        glBegin(GL_POINTS);
        glColor3f(102/255.0, 51/255.0, 0/255.0);
        glVertex3f(60, -4.0+20, -19.5-r);

        glVertex3f(60, -4.0, -19.5-r);

        glVertex3f(60, -4.0-20, -19.5-r);

        glVertex3f(60, -4.0-40, -19.5-r);

        glEnd();



        r+=0.1;
        }

///OBJEK KELAS//////////////////////////////////
//////////////////////////////////////////////
///Papan Tulis
/////////////////////////////////////////////////////
    //Belakang
    float x = 0;
    float a=0;
    for(int i=0;i<10;i++){
    glBegin(GL_QUADS);
    glColor3f(1*a/255.0, 1*a/255.0, 1*a/255.0);
        glVertex3f(46.0+x, -44.0, 15.0);
        glVertex3f(46.0+x, -34.0, 15.0);
        glVertex3f(46.0+x, -34.0, -5.0);
        glVertex3f(46.0+x, -44.0, -5.0);
        glEnd();

        x+=0.1;
        a+=25.5;
    }

    glLineWidth(2.0);

    glBegin(GL_LINES);
    glColor3f(0,0,0);
        glVertex3f(47.0, -44.0, 15.0);
        glVertex3f(47.0, -34.0, 15.0);

        glVertex3f(47.0, -34.0, -5.0);
        glVertex3f(47.0, -44.0, -5.0);

        glVertex3f(47.0, -44.0, 15.0);
        glVertex3f(47.0, -44.0, -5.0);

        glVertex3f(47.0, -34.0, 15.0);
        glVertex3f(47.0, -34.0, -5.0);
        glEnd();

        //TIANG

                glLineWidth(5.0);

        glBegin(GL_LINES);
    glColor3f(0,0,0);
        glVertex3f(46.0, -44.0, 14.0);
        glVertex3f(46.0, -50.0, 14.0);
        glVertex3f(46.0, -50.0, -4.0);
        glVertex3f(46.0, -44.0, -4.0);
        glEnd();

///MEJA///

    for(int i=0;i<10;i++){
    glBegin(GL_QUADS);
    glColor3f(0/255.0, 128/255.0, 255/255.0);
        glVertex3f(67.0, -43.0-x, 14.0);
        glVertex3f(71.0, -43.0-x, 14.0);
        glVertex3f(71.0, -43.0-x, -4.0);
        glVertex3f(67.0, -43.0-x, -4.0);
        glEnd();

        x+=0.1;
    }

        ///KAKI///
        glBegin(GL_LINES);
    glColor3f(0/255.0, 0/255.0, 153/255.0);
        glVertex3f(67.0, -44.0, 14.0);
        glVertex3f(67.0, -50.0, 14.0);

        glVertex3f(67.0, -44.0, -4.0);
        glVertex3f(67.0, -50.0, -4.0);

        glVertex3f(71.0, -44.0, 14.0);
        glVertex3f(71.0, -50.0, 14.0);

        glVertex3f(71.0, -44.0, -4.0);
        glVertex3f(71.0, -50.0, -4.0);

        glEnd();




///KURSI///
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(71.0, -47.0, 14.0);
        glVertex3f(73.0, -47.0, 14.0);
        glVertex3f(73.0, -47.0, -4.0);
        glVertex3f(71.0, -47.0, -4.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(73, -43.0, -4.0);
        glVertex3f(73, -43.0, 14.0);
        glVertex3f(73.0, -48.0, 14.0);
        glVertex3f(73, -48.0, -4.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(153/255.0,0,0);
        glVertex3f(71.0, -47.0, 13.0);
        glVertex3f(71.0, -50.0, 13.0);

        glVertex3f(71.0, -47.0, -3.0);
        glVertex3f(71.0, -50.0, -3.0);

        glVertex3f(73.0, -47.0, -3.0);
        glVertex3f(73.0, -50.0, -3.0);

        glVertex3f(73.0, -47.0, 13.0);
        glVertex3f(73.0, -50.0, 13.0);
        glEnd();





}

void lantai_atas(void){

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-85.0, 30.0, 10.0);
    glVertex3f(-85.0, 60.0, 10.0);
    glVertex3f(85.0, 60.0, 10.0);
    glVertex3f(85.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-85.0, 30.0, 10.0);
    glVertex3f(-85.0, 60.0, 10.0);
    glVertex3f(-85.0, 60.0, -50.0);
    glVertex3f(-85.0, 30.0, -50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(85.0, 30.0, 10.0);
    glVertex3f(85.0, 60.0, 10.0);
    glVertex3f(85.0, 60.0, -50.0);
    glVertex3f(85.0, 30.0, -50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-85.0, 30.0, -50.0);
    glVertex3f(-85.0, 60.0, -50.0);
    glVertex3f(85.0, 60.0, -50.0);
    glVertex3f(85.0, 30.0, -50.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 0/255.0);
    glVertex3f(-85.0, 60.0, 10.0);
    glVertex3f(-85.0, 60.0, -50.0);
    glVertex3f(85.0, 60.0, -50.0);
    glVertex3f(85.0, 60.0, 10.0);
    glEnd();
}



void timer(int value)
{
   naik++;
   kananr++;
   if(naik==21)
   {
       naik--;
       kananr--;
       time++;
   }
   if(time==10)
   {
       time=0;
       naik=22;
   }
   glutPostRedisplay();
   glutTimerFunc(800,timer,10);
}

void garis(float jalurx,int pilih)
{
    //glLineWidth(100.0);
    glColor3ub(157,157,127);
    glBegin(GL_QUADS);
    if(pilih==1)
    {
    ///depan
    glVertex3f(-73.75+jalurx,50,10.1);
    glVertex3f(-81.75+jalurx,45,10.1);
    glVertex3f(-80.75+jalurx,45,10.1);
    glVertex3f(-72.75+jalurx,50,10.1);

    glVertex3f(-74.75+jalurx,50,10.1);
    glVertex3f(-66.75+jalurx,45,10.1);
    glVertex3f(-65.75+jalurx,45,10.1);
    glVertex3f(-73.75+jalurx,50,10.1);

    glVertex3f(-73.25+jalurx,50,10.1);
    glVertex3f(-74.25+jalurx,50,10.1);
    glVertex3f(-74.25+jalurx,55,10.1);
    glVertex3f(-73.25+jalurx,55,10.1);

    glVertex3f(-82.5+jalurx,45,10.1);
    glVertex3f(-83+jalurx,45,10.1);
    glVertex3f(-83+jalurx,55,10.1);
    glVertex3f(-82.5+jalurx,55,10.1);

    glVertex3f(-64.75+jalurx,45,10.1);
    glVertex3f(-65.25+jalurx,45,10.1);
    glVertex3f(-65.25+jalurx,55,10.1);
    glVertex3f(-64.75+jalurx,55,10.1);

    glVertex3f(-63.75+jalurx,50,10.1);
    glVertex3f(-83.75+jalurx,50,10.1);
    glVertex3f(-83.75+jalurx,49,10.1);
    glVertex3f(-63.75+jalurx,49,10.1);

    glVertex3f(-63.75+jalurx,45,10.1);
    glVertex3f(-83.75+jalurx,45,10.1);
    glVertex3f(-83.75+jalurx,47,10.1);
    glVertex3f(-63.75+jalurx,47,10.1);

    //tiang
    glColor3ub(127,127,127);
    glVertex3f(-83.75+jalurx,55,10.2);
    glVertex3f(-85+jalurx,55,10.2);
    glVertex3f(-85+jalurx,30,10.2);
    glVertex3f(-83.75+jalurx,30,10.2);

    glVertex3f(-63.75+jalurx,55,10.2);
    glVertex3f(-62.5+jalurx,55,10.2);
    glVertex3f(-62.5+jalurx,30,10.2);
    glVertex3f(-63.75+jalurx,30,10.2);
    }
    else if(pilih==2)
    {
    ///belakang
    glVertex3f(-73.75+jalurx,50,-50.1);
    glVertex3f(-81.75+jalurx,45,-50.1);
    glVertex3f(-80.75+jalurx,45,-50.1);
    glVertex3f(-72.75+jalurx,50,-50.1);

    glVertex3f(-74.75+jalurx,50,-50.1);
    glVertex3f(-66.75+jalurx,45,-50.1);
    glVertex3f(-65.75+jalurx,45,-50.1);
    glVertex3f(-73.75+jalurx,50,-50.1);

    glVertex3f(-73.25+jalurx,50,-50.1);
    glVertex3f(-74.25+jalurx,50,-50.1);
    glVertex3f(-74.25+jalurx,55,-50.1);
    glVertex3f(-73.25+jalurx,55,-50.1);

    glVertex3f(-82.5+jalurx,45,-50.1);
    glVertex3f(-83+jalurx,45,-50.1);
    glVertex3f(-83+jalurx,55,-50.1);
    glVertex3f(-82.5+jalurx,55,-50.1);

    glVertex3f(-64.75+jalurx,45,-50.1);
    glVertex3f(-65.25+jalurx,45,-50.1);
    glVertex3f(-65.25+jalurx,55,-50.1);
    glVertex3f(-64.75+jalurx,55,-50.1);

    glVertex3f(-63.75+jalurx,50,-50.1);
    glVertex3f(-83.75+jalurx,50,-50.1);
    glVertex3f(-83.75+jalurx,49,-50.1);
    glVertex3f(-63.75+jalurx,49,-50.1);

    glVertex3f(-63.75+jalurx,45,-50.1);
    glVertex3f(-83.75+jalurx,45,-50.1);
    glVertex3f(-83.75+jalurx,47,-50.1);
    glVertex3f(-63.75+jalurx,47,-50.1);

    //tiang
    glColor3ub(127,127,127);
    glVertex3f(-83.75+jalurx,55,-50.2);
    glVertex3f(-85+jalurx,55,-50.2);
    glVertex3f(-85+jalurx,30,-50.2);
    glVertex3f(-83.75+jalurx,30,-50.2);

    glVertex3f(-63.75+jalurx,55,-50.2);
    glVertex3f(-62.5+jalurx,55,-50.2);
    glVertex3f(-62.5+jalurx,30,-50.2);
    glVertex3f(-63.75+jalurx,30,-50.2);
    }
    else if(pilih==3)
    {
        ///kiri
    glVertex3f(-85.1,45,-42.5+jalurx);
    glVertex3f(-85.1,50,-35.5+jalurx);
    glVertex3f(-85.1,50,-34.5+jalurx);
    glVertex3f(-85.1,45,-41.5+jalurx);

    glVertex3f(-85.1,50,-35.5+jalurx);
    glVertex3f(-85.1,45,-28.5+jalurx);
    glVertex3f(-85.1,45,-27.5+jalurx);
    glVertex3f(-85.1,50,-34.5+jalurx);

    glVertex3f(-85.1,50,-34+jalurx);
    glVertex3f(-85.1,50,-36+jalurx);
    glVertex3f(-85.1,55,-36+jalurx);
    glVertex3f(-85.1,55,-34+jalurx);

    glVertex3f(-85.1,45,-48+jalurx);
    glVertex3f(-85.1,45,-47+jalurx);
    glVertex3f(-85.1,55,-47+jalurx);
    glVertex3f(-85.1,55,-48+jalurx);

    glVertex3f(-85.1,45,-22+jalurx);
    glVertex3f(-85.1,45,-23+jalurx);
    glVertex3f(-85.1,55,-23+jalurx);
    glVertex3f(-85.1,55,-22+jalurx);

    glVertex3f(-85.1,50,-21+jalurx);
    glVertex3f(-85.1,50,-49+jalurx);
    glVertex3f(-85.1,49,-49+jalurx);
    glVertex3f(-85.1,49,-21+jalurx);

    glVertex3f(-85.1,45,-21+jalurx);
    glVertex3f(-85.1,45,-49+jalurx);
    glVertex3f(-85.1,47,-49+jalurx);
    glVertex3f(-85.1,47,-21+jalurx);

    //tiang
    glColor3ub(127,127,127);
    glVertex3f(-85.1,55,-48.5+jalurx);
    glVertex3f(-85.1,55,-50+jalurx);
    glVertex3f(-85.1,30,-50+jalurx);
    glVertex3f(-85.1,30,-48.5+jalurx);

    glVertex3f(-85.1,55,-21.5+jalurx);
    glVertex3f(-85.1,55,-20+jalurx);
    glVertex3f(-85.1,30,-20+jalurx);
    glVertex3f(-85.1,30,-21.5+jalurx);
    }
    else if(pilih==4)
    {
        ///kiri
    glVertex3f(85.1,45,-42.5+jalurx);
    glVertex3f(85.1,50,-35.5+jalurx);
    glVertex3f(85.1,50,-34.5+jalurx);
    glVertex3f(85.1,45,-41.5+jalurx);

    glVertex3f(85.1,50,-35.5+jalurx);
    glVertex3f(85.1,45,-28.5+jalurx);
    glVertex3f(85.1,45,-27.5+jalurx);
    glVertex3f(85.1,50,-34.5+jalurx);

    glVertex3f(85.1,50,-34+jalurx);
    glVertex3f(85.1,50,-36+jalurx);
    glVertex3f(85.1,55,-36+jalurx);
    glVertex3f(85.1,55,-34+jalurx);

    glVertex3f(85.1,45,-48+jalurx);
    glVertex3f(85.1,45,-47+jalurx);
    glVertex3f(85.1,55,-47+jalurx);
    glVertex3f(85.1,55,-48+jalurx);

    glVertex3f(85.1,45,-22+jalurx);
    glVertex3f(85.1,45,-23+jalurx);
    glVertex3f(85.1,55,-23+jalurx);
    glVertex3f(85.1,55,-22+jalurx);

    glVertex3f(85.1,50,-21+jalurx);
    glVertex3f(85.1,50,-49+jalurx);
    glVertex3f(85.1,49,-49+jalurx);
    glVertex3f(85.1,49,-21+jalurx);

    glVertex3f(85.1,45,-21+jalurx);
    glVertex3f(85.1,45,-49+jalurx);
    glVertex3f(85.1,47,-49+jalurx);
    glVertex3f(85.1,47,-21+jalurx);

    //tiang
    glColor3ub(127,127,127);
    glVertex3f(85.1,55,-48.5+jalurx);
    glVertex3f(85.1,55,-50+jalurx);
    glVertex3f(85.1,30,-50+jalurx);
    glVertex3f(85.1,30,-48.5+jalurx);

    glVertex3f(85.1,55,-21.5+jalurx);
    glVertex3f(85.1,55,-20+jalurx);
    glVertex3f(85.1,30,-20+jalurx);
    glVertex3f(85.1,30,-21.5+jalurx);
    }
    glEnd();
}


void atap(void){
    glColor3ub(102+50,51+50,50);
    ///1
    ///kiri
    glBegin(GL_POLYGON);
    glVertex3f(-85,60,20);
    glVertex3f(-85,60,-60);
    glVertex3f(-65,90,-20);
    glEnd();
    ///kanan
    glBegin(GL_POLYGON);
    glVertex3f(85,60,20);
    glVertex3f(85,60,-60);
    glVertex3f(65,90,-20);
    glEnd();
    ///blakang
    glBegin(GL_POLYGON);
    glVertex3f(-85,60,-60);
    glVertex3f(85,60,-60);
    glVertex3f(65,90,-20);
    glVertex3f(-65,90,-20);
    glEnd();
    ///depan
    glBegin(GL_QUADS);
    glVertex3f(85,60,20);
    glVertex3f(-85,60,20);
    glVertex3f(-65,90,-20);
    glVertex3f(65,90,-20);
    glEnd();
    ///2
    glColor3ub(102+100,51+100,100);
    ///depan
    glBegin(GL_QUADS);
    glVertex3f(100,55,30);
    glVertex3f(-100,55,30);
    glVertex3f(-80,70,10);
    glVertex3f(80,70,10);
    glEnd();
    ///kiri

    glBegin(GL_QUADS);
    glVertex3f(-100,55,30);
    glVertex3f(-80,70,10);
    glVertex3f(-80,70,-50);
    glVertex3f(-100,55,-70);
    glEnd();
    ///blakang

    glBegin(GL_QUADS);
    glVertex3f(100,55,-70);
    glVertex3f(-100,55,-70);
    glVertex3f(-80,70,-50);
    glVertex3f(80,70,-50);
    glEnd();
    ///kanan

    glBegin(GL_QUADS);
    glVertex3f(100,55,30);
    glVertex3f(80,70,10);
    glVertex3f(80,70,-50);
    glVertex3f(100,55,-70);
    glEnd();
    ///alas
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex3f(-100,55,30);
    glVertex3f(-100,55,-70);
    glVertex3f(100,55,-70);
    glVertex3f(100,55,30);
    glEnd();
///shadow
    glBegin(GL_LINES);
    float bwh=0,ats=0,bwh1=0,ats1=0,bwh2=0,ats2=0,bwh3=0,ats3=0;
    for(int i=0;i<25;i++){
    glVertex3f(-80+bwh,60.1,20); glVertex3f(-60+ats,90.1,-20);
    glVertex3f(-80+bwh,60.1,-60); glVertex3f(-60+ats,90.1,-20);
    bwh+=6.6;
    ats+=5;
    }
    for(int i=0;i<25;i++){
    glVertex3f(-93+bwh1,55.1,30); glVertex3f(-73.5+ats1,70.1,10);
    glVertex3f(-93+bwh1,55.1,-70); glVertex3f(-73.5+ats1,70.1,-50);
    bwh1+=7.7;
    ats1+=6.05;
    }
    for(int i=0;i<10;i++){
    glVertex3f(-100,55.1,-70+bwh3); glVertex3f(-80,70.1,-50+ats3);
    glVertex3f(100,55.1,-70+bwh3); glVertex3f(80,70.1,-50+ats3);
    bwh3+=10;
    ats3+=6.05;
    }
    glEnd();
    ///outline
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
///atas
    glVertex3f(-65,89,-19);
    glVertex3f(-65,89,-21);
    glVertex3f(65,89,-21);
    glVertex3f(65,89,-19);

    glVertex3f(65,94,-21);
    glVertex3f(65,94,-19);
    glVertex3f(-65,94,-19);
    glVertex3f(-65,94,-21);

    glVertex3f(65,94,-21);
    glVertex3f(-65,94,-21);
    glVertex3f(-65,89,-21);
    glVertex3f(65,89,-21);

    glVertex3f(65,94,-19);
    glVertex3f(-65,94,-19);
    glVertex3f(-65,89,-19);
    glVertex3f(65,89,-19);

    ///tanduk
    //kiri
    glBegin(GL_QUADS);
    glVertex3f(-66,103,-19);
    glVertex3f(-66,94,-19);
    glVertex3f(-63,94,-19);
    glVertex3f(-63,103,-19);

    glVertex3f(-66,103,-21);
    glVertex3f(-66,94,-21);
    glVertex3f(-63,94,-21);
    glVertex3f(-63,103,-21);

    glVertex3f(-66,103,-21);
    glVertex3f(-66,94,-21);
    glVertex3f(-66,94,-19);
    glVertex3f(-66,103,-19);

    glVertex3f(-63,103,-21);
    glVertex3f(-63,94,-21);
    glVertex3f(-63,94,-19);
    glVertex3f(-63,103,-19);

    glVertex3f(-63,103,-21);
    glVertex3f(-59,103,-21);
    glVertex3f(-59,103,-19);
    glVertex3f(-63,103,-19);

    glVertex3f(-63,100,-21);
    glVertex3f(-59,103,-21);
    glVertex3f(-59,103,-19);
    glVertex3f(-63,100,-19);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-59,103,-21);
    glVertex3f(-63,103,-21);
    glVertex3f(-63,100,-21);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-59,103,-19);
    glVertex3f(-63,103,-19);
    glVertex3f(-63,100,-19);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glVertex3f(66,103,-19);
    glVertex3f(66,94,-19);
    glVertex3f(63,94,-19);
    glVertex3f(63,103,-19);

    glVertex3f(66,103,-21);
    glVertex3f(66,94,-21);
    glVertex3f(63,94,-21);
    glVertex3f(63,103,-21);

    glVertex3f(66,103,-21);
    glVertex3f(66,94,-21);
    glVertex3f(66,94,-19);
    glVertex3f(66,103,-19);

    glVertex3f(63,103,-21);
    glVertex3f(63,94,-21);
    glVertex3f(63,94,-19);
    glVertex3f(63,103,-19);

    glVertex3f(63,103,-21);
    glVertex3f(59,103,-21);
    glVertex3f(59,103,-19);
    glVertex3f(63,103,-19);

    glVertex3f(63,100,-21);
    glVertex3f(59,103,-21);
    glVertex3f(59,103,-19);
    glVertex3f(63,100,-19);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(59,103,-21);
    glVertex3f(63,103,-21);
    glVertex3f(63,100,-21);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(59,103,-19);
    glVertex3f(63,103,-19);
    glVertex3f(63,100,-19);
    glEnd();
///tengah
///kanan
    glBegin(GL_QUADS);
    glVertex3f(84,64,-61);
    glVertex3f(86,64,-60);
    glVertex3f(66,94,-20);
    glVertex3f(64,94,-21);

    glVertex3f(84,59,-61);
    glVertex3f(84,64,-61);
    glVertex3f(64,94,-21);
    glVertex3f(64,89,-21);

    glVertex3f(86,59,-60);
    glVertex3f(86,64,-60);
    glVertex3f(66,94,-20);
    glVertex3f(66,89,-20);

    glVertex3f(84,64,21);
    glVertex3f(86,64,20);
    glVertex3f(66,94,-20);
    glVertex3f(64,94,-19);

    glVertex3f(84,59,21);
    glVertex3f(84,64,21);
    glVertex3f(64,94,-19);
    glVertex3f(64,89,-19);

    glVertex3f(86,59,20);
    glVertex3f(86,64,20);
    glVertex3f(66,94,-20);
    glVertex3f(66,89,-20);
///kiri

    glVertex3f(-84,64,-61);
    glVertex3f(-86,64,-60);
    glVertex3f(-66,94,-20);
    glVertex3f(-64,94,-21);

    glVertex3f(-84,59,-61);
    glVertex3f(-84,64,-61);
    glVertex3f(-64,94,-21);
    glVertex3f(-64,89,-21);

    glVertex3f(-86,59,-60);
    glVertex3f(-86,64,-60);
    glVertex3f(-66,94,-20);
    glVertex3f(-66,89,-20);

    glVertex3f(-84,64,21);
    glVertex3f(-86,64,20);
    glVertex3f(-66,94,-20);
    glVertex3f(-64,94,-19);

    glVertex3f(-84,59,21);
    glVertex3f(-84,64,21);
    glVertex3f(-64,94,-19);
    glVertex3f(-64,89,-19);

    glVertex3f(-86,59,20);
    glVertex3f(-86,64,20);
    glVertex3f(-66,94,-20);
    glVertex3f(-66,89,-20);

/// tutup
    glVertex3f(-84,59,21);
    glVertex3f(-84,64,21);
    glVertex3f(-86,64,20);
    glVertex3f(-86,59,20);

    glVertex3f(84,59,21);
    glVertex3f(84,64,21);
    glVertex3f(86,64,20);
    glVertex3f(86,59,20);

    glVertex3f(-84,59,-61);
    glVertex3f(-84,64,-61);
    glVertex3f(-86,64,-60);
    glVertex3f(-86,59,-60);

    glVertex3f(84,59,-61);
    glVertex3f(84,64,-61);
    glVertex3f(86,64,-60);
    glVertex3f(86,59,-60);

    ///bawah
    ///belakang
    glColor3ub(0,0,0);
    glVertex3f(-101,57,-69);
    glVertex3f(-99,57,-71);
    glVertex3f(-99,55,-71);
    glVertex3f(-101,55,-69);

    glVertex3f(-101,57,-69);
    glVertex3f(-99,57,-71);
    glVertex3f(-79,72,-51);
    glVertex3f(-80,72,-49);

    glVertex3f(-99,57,-71);
    glVertex3f(-99,55,-71);
    glVertex3f(-79,70,-51);
    glVertex3f(-79,72,-51);

    glVertex3f(-101,57,-69);
    glVertex3f(-101,55,-69);
    glVertex3f(-80,70,-49);
    glVertex3f(-80,72,-49);

    ///
    glVertex3f(101,57,-69);
    glVertex3f(99,57,-71);
    glVertex3f(99,55,-71);
    glVertex3f(101,55,-69);

    glVertex3f(101,57,-69);
    glVertex3f(99,57,-71);
    glVertex3f(79,72,-51);
    glVertex3f(80,72,-49);

    glVertex3f(99,57,-71);
    glVertex3f(99,55,-71);
    glVertex3f(79,70,-51);
    glVertex3f(79,72,-51);

    glVertex3f(101,57,-69);
    glVertex3f(101,55,-69);
    glVertex3f(80,70,-49);
    glVertex3f(80,72,-49);

    ///depan
    glColor3ub(0,0,0);
    glVertex3f(-101,57,29);
    glVertex3f(-99,57,31);
    glVertex3f(-99,55,31);
    glVertex3f(-101,55,29);

    glVertex3f(-101,57,29);
    glVertex3f(-99,57,31);
    glVertex3f(-79,72,11);
    glVertex3f(-80,72,9);

    glVertex3f(-99,57,31);
    glVertex3f(-99,55,31);
    glVertex3f(-79,70,11);
    glVertex3f(-79,72,11);

    glVertex3f(-101,57,29);
    glVertex3f(-101,55,29);
    glVertex3f(-80,70,9);
    glVertex3f(-80,72,9);

    ///
    glVertex3f(101,57,29);
    glVertex3f(99,57,31);
    glVertex3f(99,55,31);
    glVertex3f(101,55,29);

    glVertex3f(101,57,29);
    glVertex3f(99,57,31);
    glVertex3f(79,72,11);
    glVertex3f(80,72,9);

    glVertex3f(99,57,31);
    glVertex3f(99,55,31);
    glVertex3f(79,70,11);
    glVertex3f(79,72,11);

    glVertex3f(101,57,29);
    glVertex3f(101,55,29);
    glVertex3f(80,70,9);
    glVertex3f(80,72,9);
    ///papan
    glColor3ub(157,157,127);
    glVertex3f(-21.25,50,10.1);
    glVertex3f(21.25,50,10.1);
    glVertex3f(21.25,49,10.1);
    glVertex3f(-21.25,49,10.1);

    glVertex3f(-21.25,45,10.1);
    glVertex3f(21.25,45,10.1);
    glVertex3f(21.25,47,10.1);
    glVertex3f(-21.25,47,10.1);

    glVertex3f(-18.75,45,10.1);
    glVertex3f(-19.25,45,10.1);
    glVertex3f(-19.25,55,10.1);
    glVertex3f(-18.75,55,10.1);

    glVertex3f(18.75,45,10.1);
    glVertex3f(19.25,45,10.1);
    glVertex3f(19.25,55,10.1);
    glVertex3f(18.75,55,10.1);
glColor3ub(0,0,50);
    glVertex3f(-18.25,45,10.2);
    glVertex3f(18.25,45,10.2);
    glVertex3f(18.25,55,10.2);
    glVertex3f(-18.25,55,10.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(212,175,55);
    glVertex3f(-17,46,10.3);
    glVertex3f(17,46,10.3);
    glVertex3f(17,54,10.3);
    glVertex3f(-17,54,10.3);
    glEnd();
    for(float i=0;i<43;i+=21.25)
        garis(i,1);
    for(float i=105;i<149;i+=21.25)
        garis(i,1);
    for(float i=0;i<149;i+=21.25)
        garis(i,2);
    for(float i=0;i<=30;i+=30)
        garis(i,3);
    for(float i=0;i<=30;i+=30)
        garis(i,4);
}

void gerak(void)
{
    ///dalam lift
    if(naik>=60)
    {
        glTranslated(0,turun,0);
        turun--;
        if(turun==0)
            {
            naik=0;
            turun=60;
            }
    }else
        glTranslated(0,naik,0);
        glBegin(GL_QUADS);
        glColor3ub(172,172,172);
        glVertex3f(-7.0, -50.0, -79);
        glVertex3f(-7.0, -30.0, -79);
        glVertex3f(-7.0, -30.0, -99);
        glVertex3f(-7.0, -50.0, -99);

        glVertex3f(-7.0, -50.0, -99);
        glVertex3f(-7.0, -30.0, -99);
        glVertex3f(10.0, -30.0, -99);
        glVertex3f(10.0, -50.0, -99);
        glColor3ub(122,122,122);
        glVertex3f(10.0, -50.0, -79);
        glVertex3f(10.0, -30.0, -79);
        glVertex3f(10.0, -30.0, -99);
        glVertex3f(10.0, -50.0, -99);
        glColor3ub(100,100,100);
        glVertex3f(10.0, -30.0, -79);
        glVertex3f(-7.0, -30.0, -79);
        glVertex3f(-7.0, -30.0, -99);
        glVertex3f(10.0, -30.0, -99);
        glColor3ub(190,190,190);
        glVertex3f(10.0, -50.0, -79);
        glVertex3f(-7.0, -50.0, -79);
        glVertex3f(-7.0, -50.0, -99);
        glVertex3f(10.0, -50.0, -99);
        glEnd();

    if(naik>=60)
        glTranslated(0,-turun,0);
    else
        glTranslated(0,-naik,0);

    if(kananr>=22)
    {
        glTranslated(kiriL,0,0);
        kiriL--;
        if(kiriL==0)
            {
            kananr=0;
            kiriL=22;
            }
    }else
        glTranslated(kananr,0,0);
        glColor3ub(150,150,255);
        glBegin(GL_QUADS);
        glVertex3f(0,-30,9.9);
        glVertex3f(18,-30,9.9);
        glVertex3f(18,-50,9.9);
        glVertex3f(0,-50,9.9);
        glEnd();
    if(kananr>=22)
        glTranslated(-kiriL,0,0);
    else
        glTranslated(-kananr,0,0);
    if(kananr>=22)
        glTranslated(-kiriL,0,0);
    else
        glTranslated(-kananr,0,0);
        glBegin(GL_QUADS);
        glVertex3f(0,-30,9.9);
        glVertex3f(-18,-30,9.9);
        glVertex3f(-18,-50,9.9);
        glVertex3f(0,-50,9.9);
        glEnd();
}

void pintu(void){

glColor3ub(230,230,230);
    ///batas
    //glBegin(GL_QUADS);
    /*glVertex3f(30,-50,40);
    glVertex3f(30,-30,40);
    glVertex3f(-30,-30,40);
    glVertex3f(-30,-50,40);
    glEnd();*/
    ///atap
    glBegin(GL_POLYGON);
    glVertex3f(0,-31,40);
    glVertex3f(15,-32,40);
    glVertex3f(15,-30,40);
    glVertex3f(0,-28,40);
    glVertex3f(-15,-30,40);
    glVertex3f(-15,-32,40);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(17,-32,40);
    glVertex3f(15,-30,40);
    glVertex3f(15,-32,40);
    glVertex3f(17,-33,40);
    glVertex3f(30,-34,40);
    glVertex3f(30,-33,40);

    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-17,-32,40);
    glVertex3f(-15,-30,40);
    glVertex3f(-15,-32,40);
    glVertex3f(-17,-33,40);
    glVertex3f(-30,-34,40);
    glVertex3f(-30,-33,40);
    glEnd();
glColor3ub(230,0,230);
    glBegin(GL_POLYGON);
    glVertex3f(0,-28,10);
    glVertex3f(15,-30,10);
    glVertex3f(15,-30,40);//
    glVertex3f(0,-28,40);//
    glVertex3f(-15,-30,40);//
    glVertex3f(-15,-30,10);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-17,-32,40);//
    glVertex3f(-15,-30,40);//
    glVertex3f(-15,-30,10);
    glVertex3f(-17,-32,10);
    glVertex3f(-30,-33,10);
    glVertex3f(-30,-33,40);//
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(17,-32,40);//
    glVertex3f(15,-30,40);//
    glVertex3f(15,-30,10);
    glVertex3f(17,-32,10);
    glVertex3f(30,-33,10);
    glVertex3f(30,-33,40);//
    glEnd();

    ///tiang
    glBegin(GL_QUADS);
    ///atas
    glColor3ub(250,250,250);
    glVertex3f(19,-35,39.5);
    glVertex3f(-19,-35,39.5);
    glVertex3f(-19,-33,39.5);
    glVertex3f(19,-33,39.5);

    glVertex3f(19,-33,36.5);
    glVertex3f(-19,-33,36.5);
    glVertex3f(-19,-33,39.5);
    glVertex3f(19,-33,39.5);

    glVertex3f(-19,-33,36.5);
    glVertex3f(-19,-35,36.5);
    glVertex3f(-19,-35,39.5);
    glVertex3f(-19,-33,39.5);

    glVertex3f(19,-35,36.5);
    glVertex3f(-19,-35,36.5);
    glVertex3f(-19,-33,36.5);
    glVertex3f(19,-33,36.5);

    glVertex3f(19,-35,36.5);
    glVertex3f(-19,-35,36.5);
    glVertex3f(-19,-35,39.5);
    glVertex3f(19,-35,39.5);

    glVertex3f(19,-33,36.5);
    glVertex3f(19,-35,36.5);
    glVertex3f(19,-35,39.5);
    glVertex3f(19,-33,39.5);


    ///kanan
    glColor3ub(30,30,30);
    glVertex3f(16,-34,39);
    glVertex3f(18,-34,39);
    glVertex3f(18,-50,39);
    glVertex3f(16,-50,39);

    glVertex3f(18,-34,37);
    glVertex3f(18,-34,39);
    glVertex3f(18,-50,39);
    glVertex3f(18,-50,37);

    glVertex3f(16,-34,37);
    glVertex3f(18,-34,37);
    glVertex3f(18,-50,37);
    glVertex3f(16,-50,37);

    glVertex3f(16,-34,37);
    glVertex3f(16,-34,39);
    glVertex3f(16,-50,39);
    glVertex3f(16,-50,37);
///b
glColor3ub(100,100,100);
    glVertex3f(16,-34,10);
    glVertex3f(18,-34,10);
    glVertex3f(18,-34,40);
    glVertex3f(16,-34,40);

    glVertex3f(18,-34,10);
    glVertex3f(18,-33,10);
    glVertex3f(18,-33,40);
    glVertex3f(18,-34,40);

    glVertex3f(16,-34,10);
    glVertex3f(16,-33,10);
    glVertex3f(16,-33,40);
    glVertex3f(16,-34,40);

    glVertex3f(16,-34,40);
    glVertex3f(16,-33,40);
    glVertex3f(18,-33,40);
    glVertex3f(18,-34,40);
///kiri
    glBegin(GL_QUADS);
    glColor3ub(30,30,30);
    glVertex3f(-16,-34,39);
    glVertex3f(-18,-34,39);
    glVertex3f(-18,-50,39);
    glVertex3f(-16,-50,39);

    glVertex3f(-18,-34,37);
    glVertex3f(-18,-34,39);
    glVertex3f(-18,-50,39);
    glVertex3f(-18,-50,37);

    glVertex3f(-16,-34,37);
    glVertex3f(-18,-34,37);
    glVertex3f(-18,-50,37);
    glVertex3f(-16,-50,37);

    glVertex3f(-16,-34,37);
    glVertex3f(-16,-34,39);
    glVertex3f(-16,-50,39);
    glVertex3f(-16,-50,37);
///b
    glColor3ub(100,100,100);
    glVertex3f(-16,-34,10);
    glVertex3f(-18,-34,10);
    glVertex3f(-18,-34,40);
    glVertex3f(-16,-34,40);

    glVertex3f(-18,-34,10);
    glVertex3f(-18,-33,10);
    glVertex3f(-18,-33,40);
    glVertex3f(-18,-34,40);

    glVertex3f(-16,-34,10);
    glVertex3f(-16,-33,10);
    glVertex3f(-16,-33,40);
    glVertex3f(-16,-34,40);

    glVertex3f(-16,-34,40);
    glVertex3f(-16,-33,40);
    glVertex3f(-18,-33,40);
    glVertex3f(-18,-34,40);
    ///lantai
    glVertex3f(25,-50,40);
    glVertex3f(25,-50,10);
    glVertex3f(-25,-50,10);
    glVertex3f(-25,-50,40);

    glVertex3f(55,-50,40);
    glVertex3f(55,-50,10);
    glVertex3f(-55,-50,10);
    glVertex3f(-55,-50,40);

    ///dinding
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    //kiri
    glVertex3f(-55,-30,10);
    glVertex3f(-18,-30,10);
    glVertex3f(-18,-50,10);
    glVertex3f(-55,-50,10);
    //kanan
    glVertex3f(55,-30,10);
    glVertex3f(18,-30,10);
    glVertex3f(18,-50,10);
    glVertex3f(55,-50,10);
    glEnd();

    ///outline dinding depan
    glBegin(GL_QUADS);
    ///vertikal
    float x=0,y=18;
    for(int i=0;i<3;i++)
    {
    glColor3ub(255-20, 250-20, 205-20);
    glVertex3f(-128.5+x,-50,32);
    glVertex3f(-128.5+x,30,32);
    glVertex3f(-126+x,30,32);
    glVertex3f(-126+x,-50,32);

    glColor3ub(255-50, 253-50, 208-50);
    glVertex3f(-129.5+x,-50,30);
    glVertex3f(-129.5+x,30,30);
    glVertex3f(-128.5+x,30,32);
    glVertex3f(-128.5+x,-50,32);

    glVertex3f(-125+x,-50,30);
    glVertex3f(-125+x,30,30);
    glVertex3f(-126+x,30,32);
    glVertex3f(-126+x,-50,32);

    ///----///

    glColor3ub(255-20, 250-20, 205-20);
    glVertex3f(128.5-x,-50,32);
    glVertex3f(128.5-x,30,32);
    glVertex3f(126-x,30,32);
    glVertex3f(126-x,-50,32);

    glColor3ub(255-50, 253-50, 208-50);
    glVertex3f(129.5-x,-50,30);
    glVertex3f(129.5-x,30,30);
    glVertex3f(128.5-x,30,32);
    glVertex3f(128.5-x,-50,32);

    glVertex3f(125-x,-50,30);
    glVertex3f(125-x,30,30);
    glVertex3f(126-x,30,32);
    glVertex3f(126-x,-50,32);
    x+=27;
    }
    ///horizontal
    for(int i=0; i<3;i++)
    {
        glColor3ub(255-20, 250-20, 205-20);
    glVertex3f(-129.5,24-y,32);
    glVertex3f(-129.5,27-y,32);
    glVertex3f(-55,27-y,32);
    glVertex3f(-55,24-y,32);

    glColor3ub(255-50, 253-50, 208-50);
    glVertex3f(-129.5,27-y,32);
    glVertex3f(-129.5,27-y,30);
    glVertex3f(-55,27-y,30);
    glVertex3f(-55,27-y,32);

    glVertex3f(-129.5,24-y,32);
    glVertex3f(-129.5,24-y,30);
    glVertex3f(-55,24-y,30);
    glVertex3f(-55,24-y,32);

    glVertex3f(-129.5,24-y,30);
    glVertex3f(-129.5,27-y,30);
    glVertex3f(-129.5,27-y,32);
    glVertex3f(-129.5,24-y,32);

    glVertex3f(-55,24-y,30);
    glVertex3f(-55,27-y,30);
    glVertex3f(-55,27-y,32);
    glVertex3f(-55,24-y,32);

    ///----///
    glColor3ub(255-20, 250-20, 205-20);
    glVertex3f(129.5,24-y,32);
    glVertex3f(129.5,27-y,32);
    glVertex3f(55,27-y,32);
    glVertex3f(55,24-y,32);

    glColor3ub(255-50, 253-50, 208-50);
    glVertex3f(129.5,27-y,32);
    glVertex3f(129.5,27-y,30);
    glVertex3f(55,27-y,30);
    glVertex3f(55,27-y,32);

    glVertex3f(129.5,24-y,32);
    glVertex3f(129.5,24-y,30);
    glVertex3f(55,24-y,30);
    glVertex3f(55,24-y,32);

    glVertex3f(129.5,24-y,30);
    glVertex3f(129.5,27-y,30);
    glVertex3f(129.5,27-y,32);
    glVertex3f(129.5,24-y,32);

    glVertex3f(55,24-y,30);
    glVertex3f(55,27-y,30);
    glVertex3f(55,27-y,32);
    glVertex3f(55,24-y,32);

    y+=18;
    }
///atas
glColor3ub(255-20, 250-20, 205-20);
    glVertex3f(-129.5,24,32);
    glVertex3f(-129.5,30,32);
    glVertex3f(-55,30,32);
    glVertex3f(-55,24,32);

    glColor3ub(255-50, 253-50, 208-50);
    glVertex3f(-129.5,30,32);
    glVertex3f(-129.5,30,30);
    glVertex3f(-55,30,30);
    glVertex3f(-55,30,32);

    glVertex3f(-129.5,24,32);
    glVertex3f(-129.5,24,30);
    glVertex3f(-55,24,30);
    glVertex3f(-55,24,32);

    glVertex3f(-129.5,24,30);
    glVertex3f(-129.5,30,30);
    glVertex3f(-129.5,30,32);
    glVertex3f(-129.5,24,32);

    glVertex3f(-55,24,30);
    glVertex3f(-55,30,30);
    glVertex3f(-55,30,32);
    glVertex3f(-55,24,32);

    ///----///

    glColor3ub(255-20, 250-20, 205-20);
    glVertex3f(129.5,24,32);
    glVertex3f(129.5,30,32);
    glVertex3f(55,30,32);
    glVertex3f(55,24,32);

    glColor3ub(255-50, 253-50, 208-50);
    glVertex3f(129.5,30,32);
    glVertex3f(129.5,30,30);
    glVertex3f(55,30,30);
    glVertex3f(55,30,32);

    glVertex3f(129.5,24,32);
    glVertex3f(129.5,24,30);
    glVertex3f(55,24,30);
    glVertex3f(55,24,32);

    glVertex3f(129.5,24,30);
    glVertex3f(129.5,30,30);
    glVertex3f(129.5,30,32);
    glVertex3f(129.5,24,32);

    glVertex3f(55,24,30);
    glVertex3f(55,30,30);
    glVertex3f(55,30,32);
    glVertex3f(55,24,32);

    ///bawah
    glColor3ub(255-20, 250-20, 205-20);
    glVertex3f(-129.5,-45,32);
    glVertex3f(-129.5,-50,32);
    glVertex3f(-55,-50,32);
    glVertex3f(-55,-45,32);

    glColor3ub(255-50, 253-50, 208-50);
    glVertex3f(-129.5,-50,32);
    glVertex3f(-129.5,-50,30);
    glVertex3f(-55,-50,30);
    glVertex3f(-55,-50,32);

    glVertex3f(-129.5,-45,32);
    glVertex3f(-129.5,-45,30);
    glVertex3f(-55,-45,30);
    glVertex3f(-55,-45,32);

    glVertex3f(-129.5,-45,30);
    glVertex3f(-129.5,-50,30);
    glVertex3f(-129.5,-50,32);
    glVertex3f(-129.5,-45,32);

    glVertex3f(-55,-45,30);
    glVertex3f(-55,-50,30);
    glVertex3f(-55,-50,32);
    glVertex3f(-55,-45,32);

    ///----///

        glColor3ub(255-20, 250-20, 205-20);
    glVertex3f(129.5,-45,32);
    glVertex3f(129.5,-50,32);
    glVertex3f(55,-50,32);
    glVertex3f(55,-45,32);

    glColor3ub(255-50, 253-50, 208-50);
    glVertex3f(129.5,-50,32);
    glVertex3f(129.5,-50,30);
    glVertex3f(55,-50,30);
    glVertex3f(55,-50,32);

    glVertex3f(129.5,-45,32);
    glVertex3f(129.5,-45,30);
    glVertex3f(55,-45,30);
    glVertex3f(55,-45,32);

    glVertex3f(129.5,-45,30);
    glVertex3f(129.5,-50,30);
    glVertex3f(129.5,-50,32);
    glVertex3f(129.5,-45,32);

    glVertex3f(55,-45,30);
    glVertex3f(55,-50,30);
    glVertex3f(55,-50,32);
    glVertex3f(55,-45,32);


    glEnd();
    ///jendela
   // for(int i=0;i<55;i+=27)
     //   lt1(i);
}


void jendela(void){

    glLineWidth(3.0);
    ///depan
    int x=0;
    int y=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<2;i++){
            glBegin(GL_QUADS);
            glColor3f(192/255.0, 192/255.0, 192/255.0);
            glVertex3f(-41.0+x, 10.0-y, 10.0);
            glVertex3f(-41.0+x, 22.0-y, 10.0);
            glVertex3f(-19.0+x, 22.0-y, 10.0);
            glVertex3f(-19.0+x, 10.0-y, 10.0);
            glEnd();

            glBegin(GL_LINE_LOOP);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x, 10.0-y, 10.0);
            glVertex3f(-41.0+x, 22.0-y, 10.0);
            glVertex3f(-19.0+x, 22.0-y, 10.0);
            glVertex3f(-19.0+x, 10.0-y, 10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-34.0+x,10.0-y,10.0);
            glVertex3f(-34.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-26.0+x,10.0-y,10.0);
            glVertex3f(-26.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x,18.0-y,10.0);
            glVertex3f(-19.0+x,18.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-31.5+x,18.0-y,10.0);
            glVertex3f(-31.5+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-28.5+x,18.0-y,10.0);
            glVertex3f(-28.5+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-40.0+x,10.0-y,10.0);
            glVertex3f(-40.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-39.0+x,10.0-y,10.0);
            glVertex3f(-39.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-38.0+x,10.0-y,10.0);
            glVertex3f(-38.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-37.0+x,10.0-y,10.0);
            glVertex3f(-37.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-23.0+x,10.0-y,10.0);
            glVertex3f(-23.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-22.0+x,10.0-y,10.0);
            glVertex3f(-22.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-21.0+x,10.0-y,10.0);
            glVertex3f(-21.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-20.0+x,10.0-y,10.0);
            glVertex3f(-20.0+x,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x,20.7-y,10.0);
            glVertex3f(-37.0+x,20.7-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x,19.4-y,10.0);
            glVertex3f(-37.0+x,19.4-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x,17.0-y,10.0);
            glVertex3f(-37.0+x,17.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x,15.5-y,10.0);
            glVertex3f(-37.0+x,15.5-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x,14.0-y,10.0);
            glVertex3f(-37.0+x,14.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x,12.5-y,10.0);
            glVertex3f(-37.0+x,12.5-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-41.0+x,11.0-y,10.0);
            glVertex3f(-37.0+x,11.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-23.0+x,20.7-y,10.0);
            glVertex3f(-19.0+x,20.7-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-23.0+x,19.4-y,10.0);
            glVertex3f(-19.0+x,19.4-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-23.0+x,17.0-y,10.0);
            glVertex3f(-19.0+x,17.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-23.0+x,15.5-y,10.0);
            glVertex3f(-19.0+x,15.5-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-23.0+x,14.0-y,10.0);
            glVertex3f(-19.0+x,14.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-23.0+x,12.5-y,10.0);
            glVertex3f(-19.0+x,12.5-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-23.0+x,11.0-y,10.0);
            glVertex3f(-19.0+x,11.0-y,10.0);
            glEnd();
            x+=60;
        }
        y+=18;
        x-=60*2;
    }

    x=0,y=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<2;i++){
            glBegin(GL_QUADS);
            glColor3f(192/255.0, 192/255.0, 192/255.0);
            glVertex3f(-14.0, 10.0-y, 10.0);
            glVertex3f(-14.0, 22.0-y, 10.0);
            glVertex3f(14.0, 22.0-y, 10.0);
            glVertex3f(14.0, 10.0-y, 10.0);
            glEnd();

            glBegin(GL_LINE_LOOP);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-14.0, 10.0-y, 10.0);
            glVertex3f(-14.0, 22.0-y, 10.0);
            glVertex3f(14.0, 22.0-y, 10.0);
            glVertex3f(14.0, 10.0-y, 10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-14.0,18.0-y,10.0);
            glVertex3f(14.0,18.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-13.0,10.0-y,10.0);
            glVertex3f(-13.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-12.0,10.0-y,10.0);
            glVertex3f(-12.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-11.0,10.0-y,10.0);
            glVertex3f(-11.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-10.0,10.0-y,10.0);
            glVertex3f(-10.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(13.0,10.0-y,10.0);
            glVertex3f(13.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(12.0,10.0-y,10.0);
            glVertex3f(12.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(11.0,10.0-y,10.0);
            glVertex3f(11.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(10.0,10.0-y,10.0);
            glVertex3f(10.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-5.0,10.0-y,10.0);
            glVertex3f(-5.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(5.0,10.0-y,10.0);
            glVertex3f(5.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-3.0,10.0-y,10.0);
            glVertex3f(-3.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(3.0,10.0-y,10.0);
            glVertex3f(3.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-7.5,18.0-y,10.0);
            glVertex3f(-7.5,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(7.5,18.0-y,10.0);
            glVertex3f(7.5,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-1.0,18.0-y,10.0);
            glVertex3f(-1.0,22.0-y,10.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(1.0,18.0-y,10.0);
            glVertex3f(1.0,22.0-y,10.0);
            glEnd();
        }
        y+=18;
    }

    ///kiri
    x=0,y=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<2;i++){
            glBegin(GL_QUADS);
            glColor3f(192/255.0, 192/255.0, 192/255.0);
            glVertex3f(-125.0+x, 10.0-y, 30.0);
            glVertex3f(-125.0+x, 22.0-y, 30.0);
            glVertex3f(-103.0+x, 22.0-y, 30.0);
            glVertex3f(-103.0+x, 10.0-y, 30.0);
            glEnd();

            glBegin(GL_LINE_LOOP);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x, 10.0-y, 30.0);
            glVertex3f(-125.0+x, 22.0-y, 30.0);
            glVertex3f(-103.0+x, 22.0-y, 30.0);
            glVertex3f(-103.0+x, 10.0-y, 30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-118.0+x,10.0-y,30.0);
            glVertex3f(-118.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-111.0+x,10.0-y,30.0);
            glVertex3f(-111.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x,18.0-y,30.0);
            glVertex3f(-103.0+x,18.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-124.0+x,10.0-y,30.0);
            glVertex3f(-124.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-123.0+x,10.0-y,30.0);
            glVertex3f(-123.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-122.0+x,10.0-y,30.0);
            glVertex3f(-122.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-121.0+x,10.0-y,30.0);
            glVertex3f(-121.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-107.0+x,10.0-y,30.0);
            glVertex3f(-107.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-106.0+x,10.0-y,30.0);
            glVertex3f(-106.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-105.0+x,10.0-y,30.0);
            glVertex3f(-105.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-104.0+x,10.0-y,30.0);
            glVertex3f(-104.0+x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x,20.7-y,30.0);
            glVertex3f(-121.0+x,20.7-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x,19.4-y,30.0);
            glVertex3f(-121.0+x,19.4-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x,17.0-y,30.0);
            glVertex3f(-121.0+x,17.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x,15.5-y,30.0);
            glVertex3f(-121.0+x,15.5-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x,14.0-y,30.0);
            glVertex3f(-121.0+x,14.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x,12.5-y,30.0);
            glVertex3f(-121.0+x,12.5-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-125.0+x,11.0-y,30.0);
            glVertex3f(-121.0+x,11.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-107.0+x,20.7-y,30.0);
            glVertex3f(-103.0+x,20.7-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-107.0+x,19.4-y,30.0);
            glVertex3f(-103.0+x,19.4-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-107.0+x,17.0-y,30.0);
            glVertex3f(-103.0+x,17.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-107.0+x,15.5-y,30.0);
            glVertex3f(-103.0+x,15.5-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-107.0+x,14.0-y,30.0);
            glVertex3f(-103.0+x,14.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-107.0+x,12.5-y,30.0);
            glVertex3f(-103.0+x,12.5-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(-107.0+x,11.0-y,30.0);
            glVertex3f(-103.0+x,11.0-y,30.0);
            glEnd();
            x+=27;
        }
        y+=18;
        x-=27*2;
    }

    x=0,y=0;
    for(int j=0;j<3;j++){
        glBegin(GL_QUADS);
        glColor3f(192/255.0, 192/255.0, 192/255.0);
        glVertex3f(-71.0, 10.0-y, 30.0);
        glVertex3f(-71.0, 22.0-y, 30.0);
        glVertex3f(-58.0, 22.0-y, 30.0);
        glVertex3f(-58.0, 10.0-y, 30.0);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(-71.0, 10.0-y, 30.0);
        glVertex3f(-71.0, 22.0-y, 30.0);
        glVertex3f(-58.0, 22.0-y, 30.0);
        glVertex3f(-58.0, 10.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(-71.0, 18.0-y, 30.0);
        glVertex3f(-58.0, 18.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(-69.5, 10.0-y, 30.0);
        glVertex3f(-69.5, 22.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(-68.0, 10.0-y, 30.0);
        glVertex3f(-68.0, 22.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(-66.5, 10.0-y, 30.0);
        glVertex3f(-66.5, 22.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(-65.0, 10.0-y, 30.0);
        glVertex3f(-65.0, 22.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(-71.0+x,20.7-y,30.0);
        glVertex3f(-65.0+x,20.7-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(-71.0+x,19.4-y,30.0);
        glVertex3f(-65.0+x,19.4-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(-71.0+x,17.0-y,30.0);
        glVertex3f(-65.0+x,17.0-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(-71.0+x,15.5-y,30.0);
        glVertex3f(-65.0+x,15.5-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(-71.0+x,14.0-y,30.0);
        glVertex3f(-65.0+x,14.0-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(-71.0+x,12.5-y,30.0);
        glVertex3f(-65.0+x,12.5-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(-71.0+x,11.0-y,30.0);
        glVertex3f(-65.0+x,11.0-y,30.0);
        glEnd();
        y+=18;
    }

    ///kanan
    x=0,y=0;
    for(int j=0;j<3;j++){
        glBegin(GL_QUADS);
        glColor3f(192/255.0, 192/255.0, 192/255.0);
        glVertex3f(71.0, 10.0-y, 30.0);
        glVertex3f(71.0, 22.0-y, 30.0);
        glVertex3f(58.0, 22.0-y, 30.0);
        glVertex3f(58.0, 10.0-y, 30.0);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(71.0, 10.0-y, 30.0);
        glVertex3f(71.0, 22.0-y, 30.0);
        glVertex3f(58.0, 22.0-y, 30.0);
        glVertex3f(58.0, 10.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(71.0, 18.0-y, 30.0);
        glVertex3f(58.0, 18.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(69.5, 10.0-y, 30.0);
        glVertex3f(69.5, 22.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(68.0, 10.0-y, 30.0);
        glVertex3f(68.0, 22.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(66.5, 10.0-y, 30.0);
        glVertex3f(66.5, 22.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glVertex3f(65.0, 10.0-y, 30.0);
        glVertex3f(65.0, 22.0-y, 30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(71.0+x,20.7-y,30.0);
        glVertex3f(65.0+x,20.7-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(71.0+x,19.4-y,30.0);
        glVertex3f(65.0+x,19.4-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(71.0+x,17.0-y,30.0);
        glVertex3f(65.0+x,17.0-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(71.0+x,15.5-y,30.0);
        glVertex3f(65.0+x,15.5-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(71.0+x,14.0-y,30.0);
        glVertex3f(65.0+x,14.0-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(71.0+x,12.5-y,30.0);
        glVertex3f(65.0+x,12.5-y,30.0);
        glEnd();

        glBegin(GL_LINES);
        glColor3f(0/255.0, 0/255.0, 0/255.0);
        glVertex3f(71.0+x,11.0-y,30.0);
        glVertex3f(65.0+x,11.0-y,30.0);
        glEnd();
        y+=18;
    }

    x=0,y=0;
    for(int j=0;j<3;j++){
        for(int i=0;i<2;i++){
            glBegin(GL_QUADS);
            glColor3f(192/255.0, 192/255.0, 192/255.0);
            glVertex3f(125.0-x, 10.0-y, 30.0);
            glVertex3f(125.0-x, 22.0-y, 30.0);
            glVertex3f(103.0-x, 22.0-y, 30.0);
            glVertex3f(103.0-x, 10.0-y, 30.0);
            glEnd();

            glBegin(GL_LINE_LOOP);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x, 10.0-y, 30.0);
            glVertex3f(125.0-x, 22.0-y, 30.0);
            glVertex3f(103.0-x, 22.0-y, 30.0);
            glVertex3f(103.0-x, 10.0-y, 30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(118.0-x,10.0-y,30.0);
            glVertex3f(118.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(111.0-x,10.0-y,30.0);
            glVertex3f(111.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x,18.0-y,30.0);
            glVertex3f(103.0-x,18.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(124.0-x,10.0-y,30.0);
            glVertex3f(124.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(123.0-x,10.0-y,30.0);
            glVertex3f(123.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(122.0-x,10.0-y,30.0);
            glVertex3f(122.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(121.0-x,10.0-y,30.0);
            glVertex3f(121.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(107.0-x,10.0-y,30.0);
            glVertex3f(107.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(106.0-x,10.0-y,30.0);
            glVertex3f(106.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(105.0-x,10.0-y,30.0);
            glVertex3f(105.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(104.0-x,10.0-y,30.0);
            glVertex3f(104.0-x,22.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x,20.7-y,30.0);
            glVertex3f(121.0-x,20.7-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x,19.4-y,30.0);
            glVertex3f(121.0-x,19.4-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x,17.0-y,30.0);
            glVertex3f(121.0-x,17.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x,15.5-y,30.0);
            glVertex3f(121.0-x,15.5-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x,14.0-y,30.0);
            glVertex3f(121.0-x,14.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x,12.5-y,30.0);
            glVertex3f(121.0-x,12.5-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(125.0-x,11.0-y,30.0);
            glVertex3f(121.0-x,11.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(107.0-x,20.7-y,30.0);
            glVertex3f(103.0-x,20.7-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(107.0-x,19.4-y,30.0);
            glVertex3f(103.0-x,19.4-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(107.0-x,17.0-y,30.0);
            glVertex3f(103.0-x,17.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(107.0-x,15.5-y,30.0);
            glVertex3f(103.0-x,15.5-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(107.0-x,14.0-y,30.0);
            glVertex3f(103.0-x,14.0-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(107.0-x,12.5-y,30.0);
            glVertex3f(103.0-x,12.5-y,30.0);
            glEnd();

            glBegin(GL_LINES);
            glColor3f(0/255.0, 0/255.0, 0/255.0);
            glVertex3f(107.0-x,11.0-y,30.0);
            glVertex3f(103.0-x,11.0-y,30.0);
            glEnd();
            x+=27;
        }
        y+=18;
        x-=27*2;
    }
}

void balkon(void){
    ///kiri
    int x=0;
    for (int i=0;i<3;i++){
        glBegin(GL_POLYGON);
        glColor3f(0/255.0, 0/255.0, 255/255.0);
        glVertex3f(-45.0, -30.0+x, 10.0);
        glVertex3f(-45.0, -30.0+x, 30.0);
        glVertex3f(-55.0, -30.0+x, 30.0);
        glVertex3f(-55.0, -30.0+x, 10.0);
        glEnd();
        x+=20;
    }

    ///kanan
    x=0;
    for (int i=0;i<3;i++){
        glBegin(GL_POLYGON);
        glColor3f(0/255.0, 0/255.0, 255/255.0);
        glVertex3f(45.0, -30.0+x, 10.0);
        glVertex3f(45.0, -30.0+x, 30.0);
        glVertex3f(55.0, -30.0+x, 30.0);
        glVertex3f(55.0, -30.0+x, 10.0);
        glEnd();
        x+=20;
    }
}

void duplicate(void){
    int a = 15;

///ROW 2///

///MEJA///

    glBegin(GL_QUADS);
    glColor3f(0/255.0, 128/255.0, 255/255.0);
        glVertex3f(67.0+a, -44.0, 14.0);
        glVertex3f(71.0+a, -44.0, 14.0);
        glVertex3f(71.0+a, -44.0, -4.0);
        glVertex3f(67.0+a, -44.0, -4.0);
        glEnd();



        ///KAKI///
        glBegin(GL_LINES);
    glColor3f(0/255.0, 0/255.0, 153/255.0);
        glVertex3f(67.0+a, -44.0, 14.0);
        glVertex3f(67.0+a, -50.0, 14.0);

        glVertex3f(67.0+a, -44.0, -4.0);
        glVertex3f(67.0+a, -50.0, -4.0);

        glVertex3f(71.0+a, -44.0, 14.0);
        glVertex3f(71.0+a, -50.0, 14.0);

        glVertex3f(71.0+a, -44.0, -4.0);
        glVertex3f(71.0+a, -50.0, -4.0);

        glEnd();




///KURSI///
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(71.0+a, -47.0, 14.0);
        glVertex3f(73.0+a, -47.0, 14.0);
        glVertex3f(73.0+a, -47.0, -4.0);
        glVertex3f(71.0+a, -47.0, -4.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(73+a, -43.0, -4.0);
        glVertex3f(73+a, -43.0, 14.0);
        glVertex3f(73.0+a, -48.0, 14.0);
        glVertex3f(73+a, -48.0, -4.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(153/255.0,0,0);
        glVertex3f(71.0+a, -47.0, 13.0);
        glVertex3f(71.0+a, -50.0, 13.0);

        glVertex3f(71.0+a, -47.0, -3.0);
        glVertex3f(71.0+a, -50.0, -3.0);

        glVertex3f(73.0+a, -47.0, -3.0);
        glVertex3f(73.0+a, -50.0, -3.0);

        glVertex3f(73.0+a, -47.0, 13.0);
        glVertex3f(73.0+a, -50.0, 13.0);
        glEnd();


///ROW 3 ///

///MEJA///

    glBegin(GL_QUADS);
    glColor3f(0/255.0, 128/255.0, 255/255.0);
        glVertex3f(67.0+2*a, -44.0, 14.0);
        glVertex3f(71.0+2*a, -44.0, 14.0);
        glVertex3f(71.0+2*a, -44.0, -4.0);
        glVertex3f(67.0+2*a, -44.0, -4.0);
        glEnd();



        ///KAKI///
        glBegin(GL_LINES);
    glColor3f(0/255.0, 0/255.0, 153/255.0);
        glVertex3f(67.0+2*a, -44.0, 14.0);
        glVertex3f(67.0+2*a, -50.0, 14.0);

        glVertex3f(67.0+2*a, -44.0, -4.0);
        glVertex3f(67.0+2*a, -50.0, -4.0);

        glVertex3f(71.0+2*a, -44.0, 14.0);
        glVertex3f(71.0+2*a, -50.0, 14.0);

        glVertex3f(71.0+2*a, -44.0, -4.0);
        glVertex3f(71.0+2*a, -50.0, -4.0);

        glEnd();




///KURSI///
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(71.0+2*a, -47.0, 14.0);
        glVertex3f(73.0+2*a, -47.0, 14.0);
        glVertex3f(73.0+2*a, -47.0, -4.0);
        glVertex3f(71.0+2*a, -47.0, -4.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(73+2*a, -43.0, -4.0);
        glVertex3f(73+2*a, -43.0, 14.0);
        glVertex3f(73.0+2*a, -48.0, 14.0);
        glVertex3f(73+2*a, -48.0, -4.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(153/255.0,0,0);
        glVertex3f(71.0+2*a, -47.0, 13.0);
        glVertex3f(71.0+2*a, -50.0, 13.0);

        glVertex3f(71.0+2*a, -47.0, -3.0);
        glVertex3f(71.0+2*a, -50.0, -3.0);

        glVertex3f(73.0+2*a, -47.0, -3.0);
        glVertex3f(73.0+2*a, -50.0, -3.0);

        glVertex3f(73.0+2*a, -47.0, 13.0);
        glVertex3f(73.0+2*a, -50.0, 13.0);
        glEnd();


}

void lobi(void){

///KURSI///
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(71.0, -47.0, 14.0);
        glVertex3f(73.0, -47.0, 14.0);
        glVertex3f(73.0, -47.0, -4.0);
        glVertex3f(71.0, -47.0, -4.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(73, -43.0, -4.0);
        glVertex3f(73, -43.0, 14.0);
        glVertex3f(73.0, -48.0, 14.0);
        glVertex3f(73, -48.0, -4.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(153/255.0,0,0);
        glVertex3f(71.0, -47.0, 13.0);
        glVertex3f(71.0, -50.0, 13.0);

        glVertex3f(71.0, -47.0, -3.0);
        glVertex3f(71.0, -50.0, -3.0);

        glVertex3f(73.0, -47.0, -3.0);
        glVertex3f(73.0, -50.0, -3.0);

        glVertex3f(73.0, -47.0, 13.0);
        glVertex3f(73.0, -50.0, 13.0);
        glEnd();


int a=2;
    ///MEJA///

    glBegin(GL_QUADS);
    glColor3f(204/255.0, 102/255.0, 0/255.0);
        glVertex3f(-3, -45.0, -35.0);
        glVertex3f(3, -45.0, -35.0);
        glVertex3f(3, -45.0, -45.0);
        glVertex3f(-3, -45.0, -45.0);
        glEnd();

glLineWidth(4.0);

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(102/255.0, 51/255.0, 0/255.0);
        glVertex3f(-2.5, -45.0, -45.0);
        glVertex3f(-2.5, -50.0, -45.0);

        glVertex3f(-2.5, -45.0, -35.0);
        glVertex3f(-2.5, -50.0, -35.0);

        glVertex3f(2.5, -45.0, -45.0);
        glVertex3f(2.5, -50.0, -45.0);

        glVertex3f(2.5, -45.0, -35.0);
        glVertex3f(2.5, -50.0, -35.0);

        glEnd();




///SOFA KANAN///
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(8, -47.0, -50.0);
        glVertex3f(12, -47.0, -50.0);
        glVertex3f(12, -47.0, -30.0);
        glVertex3f(8, -47.0, -30.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(13, -41.0, -30.0);
        glVertex3f(13, -41.0, -50.0);
        glVertex3f(12, -48.0, -50.0);
        glVertex3f(12, -48.0, -30.0);
        glEnd();

        float x = 0;
        for(int i=0;i<200;i++){

        ///SENAKA///
        glBegin(GL_POLYGON);
        glColor3f(255/255.0,128/255.0,0/255.0);
        glVertex3f(12, -48.0, -30.0-x);
        glVertex3f(13, -41.0, -30.0-x);
        glVertex3f(14, -41.0, -30.0-x);
        glVertex3f(14, -50.0, -30.0-x);
        glVertex3f(12, -50.0, -30.0-x);

        glEnd();

        ///BAWAH///
        glBegin(GL_POLYGON);
        glColor3f(255/255.0,128/255.0,0/255.0);
        glVertex3f(8, -47.0, -30.0-x);
        glVertex3f(12, -47.0, -30.0-x);
        glVertex3f(12, -50.0, -30.0-x);
        glVertex3f(7, -50.0, -30.0-x);
        glEnd();

        x+=0.1;

        }

///SOFA KIRI///
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(-8, -47.0, -50.0);
        glVertex3f(-12, -47.0, -50.0);
        glVertex3f(-12, -47.0, -30.0);
        glVertex3f(-8, -47.0, -30.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(-13, -41.0, -30.0);
        glVertex3f(-13, -41.0, -50.0);
        glVertex3f(-12, -48.0, -50.0);
        glVertex3f(-12, -48.0, -30.0);
        glEnd();

        float xy=0;
        for(int i=0;i<200;i++){

        ///SENAKA///
        glBegin(GL_POLYGON);
        glColor3f(255/255.0,128/255.0,0/255.0);
        glVertex3f(-12, -48.0, -30.0-xy);
        glVertex3f(-13, -41.0, -30.0-xy);
        glVertex3f(-14, -41.0, -30.0-xy);
        glVertex3f(-14, -50.0, -30.0-xy);
        glVertex3f(-12, -50.0, -30.0-xy);

        glEnd();

        ///BAWAH///
        glBegin(GL_POLYGON);
        glColor3f(255/255.0,128/255.0,0/255.0);
        glVertex3f(-8, -47.0, -30.0-xy);
        glVertex3f(-12, -47.0, -30.0-xy);
        glVertex3f(-12, -50.0, -30.0-xy);
        glVertex3f(-7, -50.0, -30.0-xy);
        glEnd();

        xy+=0.1;

        }
}

void lt3 (void){

/// RUANG RAPAT ///

///MEJA///

    glLineWidth(6.0);
    glBegin(GL_QUADS);
    glColor3f(0/255.0, 153/255.0, 0/255.0);
        glVertex3f(70.0, -44.0+40, 14.0);
        glVertex3f(76.0, -44.0+40, 14.0);
        glVertex3f(76.0, -44.0+40, -4.0);
        glVertex3f(70.0, -44.0+40, -4.0);
        glEnd();



        ///KAKI///
        glBegin(GL_LINES);
    glColor3f(0/255.0, 102/255.0, 0/255.0);
        glVertex3f(71.0, -44.0+40, 14.0);
        glVertex3f(71.0, -50.0+40, 14.0);

        glVertex3f(71.0, -44.0+40, -4.0);
        glVertex3f(71.0, -50.0+40, -4.0);

        glVertex3f(75.0, -44.0+40, 14.0);
        glVertex3f(75.0, -50.0+40, 14.0);

        glVertex3f(75.0, -44.0+40, -4.0);
        glVertex3f(75.0, -50.0+40, -4.0);

        glEnd();


        ///2///
        ///MEJA///

    glLineWidth(4.0);
    glBegin(GL_QUADS);
    glColor3f(0/255.0, 128/255.0, 255/255.0);
        glVertex3f(70.0+10, -44.0+40, 14.0);
        glVertex3f(76.0+10, -44.0+40, 14.0);
        glVertex3f(76.0+10, -44.0+40, -4.0);
        glVertex3f(70.0+10, -44.0+40, -4.0);
        glEnd();



        ///KAKI///
        glBegin(GL_LINES);
    glColor3f(0/255.0, 0/255.0, 153/255.0);
        glVertex3f(71.0+10, -44.0+40, 14.0);
        glVertex3f(71.0+10, -50.0+40, 14.0);

        glVertex3f(71.0+10, -44.0+40, -4.0);
        glVertex3f(71.0+10, -50.0+40, -4.0);

        glVertex3f(75.0+10, -44.0+40, 14.0);
        glVertex3f(75.0+10, -50.0+40, 14.0);

        glVertex3f(75.0+10, -44.0+40, -4.0);
        glVertex3f(75.0+10, -50.0+40, -4.0);

        glEnd();

/// //////////////////////////////////////////////////////////////////

///KURSI KIRI///

    int x=0;
    for(int i=0;i<3;i++){
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(71.0+20+x, -47.0+40, 0.0);
        glVertex3f(73.0+20+x, -47.0+40, 0.0);
        glVertex3f(73.0+20+x, -47.0+40, -4.0);
        glVertex3f(71.0+20+x, -47.0+40, -4.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(73+20+x, -43.0+40, -4.0);
        glVertex3f(73+20+x, -43.0+40, 0.0);
        glVertex3f(73.0+20+x, -48.0+40, 0.0);
        glVertex3f(73+20+x, -48.0+40, -4.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(153/255.0,0,0);
        glVertex3f(71.0+20+x, -47.0+40, 0.0);
        glVertex3f(71.0+20+x, -50.0+40, 0.0);

        glVertex3f(71.0+20+x, -47.0+40, -3.0);
        glVertex3f(71.0+20+x, -50.0+40, -3.0);

        glVertex3f(73.0+20+x, -47.0+40, -3.0);
        glVertex3f(73.0+20+x, -50.0+40, -3.0);

        glVertex3f(73.0+20+x, -47.0+40, 0.0);
        glVertex3f(73.0+20+x, -50.0+40, 0.0);
        glEnd();

        x+=5;
    }


    ///KURSI KIRI DUPLICATE///

    float xy=0;
    for(int i=0;i<3;i++){
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(71.0+20+xy, -47.0+40, 12.0);
        glVertex3f(73.0+20+xy, -47.0+40, 12.0);
        glVertex3f(73.0+20+xy, -47.0+40, 8.0);
        glVertex3f(71.0+20+xy, -47.0+40, 8.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(73+20+xy, -43.0+40, 8.0);
        glVertex3f(73+20+xy, -43.0+40, 12.0);
        glVertex3f(73.0+20+xy, -48.0+40, 12.0);
        glVertex3f(73+20+xy, -48.0+40, 8.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(153/255.0,0,0);
        glVertex3f(71.0+20+xy, -47.0+40, 12.0);
        glVertex3f(71.0+20+xy, -50.0+40, 12.0);

        glVertex3f(71.0+20+xy, -47.0+40, 9.0);
        glVertex3f(71.0+20+xy, -50.0+40, 9.0);

        glVertex3f(73.0+20+xy, -47.0+40, 9.0);
        glVertex3f(73.0+20+xy, -50.0+40, 9.0);

        glVertex3f(73.0+20+xy, -47.0+40, 12.0);
        glVertex3f(73.0+20+xy, -50.0+40, 12.0);
        glEnd();

        xy+=5;
    }

    ///KURSI KANAN///
    float j=0;
    for(int i=0;i<3;i++){
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
        glVertex3f(71.0-10-j, -47.0+40, 0.0);
        glVertex3f(73.0-10-j, -47.0+40, 0.0);
        glVertex3f(73.0-10-j, -47.0+40, -4.0);
        glVertex3f(71.0-10-j, -47.0+40, -4.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(73-12-j, -43.0+40, -4.0);
        glVertex3f(73-12-j, -43.0+40, 0.0);
        glVertex3f(73.0-12-j, -48.0+40, 0.0);
        glVertex3f(73-12-j, -48.0+40, -4.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(153/255.0,0,0);
        glVertex3f(71.0-10-j, -47.0+40, 0.0);
        glVertex3f(71.0-10-j, -50.0+40, 0.0);

        glVertex3f(71.0-10-j, -47.0+40, -3.0);
        glVertex3f(71.0-10-j, -50.0+40, -3.0);

        glVertex3f(73.0-10-j, -47.0+40, -3.0);
        glVertex3f(73.0-10-j, -50.0+40, -3.0);

        glVertex3f(73.0-10-j, -47.0+40, 0.0);
        glVertex3f(73.0-10-j, -50.0+40, 0.0);
        glEnd();

    j+=5;
    }


    ///KURSI KANAN///
    float jy=0;
    for(int i=0;i<3;i++){
    glBegin(GL_QUADS);
    glColor3f(255/255.0,0,0);
        glVertex3f(71.0-10-jy, -47.0+40, 12.0);
        glVertex3f(73.0-10-jy, -47.0+40, 12.0);
        glVertex3f(73.0-10-jy, -47.0+40, 8.0);
        glVertex3f(71.0-10-jy, -47.0+40, 8.0);
        glEnd();

        ///SANDARAN///
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0,0);
        glVertex3f(73-12-jy, -43.0+40, 8.0);
        glVertex3f(73-12-jy, -43.0+40, 12.0);
        glVertex3f(73.0-12-jy, -48.0+40, 12.0);
        glVertex3f(73-12-jy, -48.0+40, 8.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
        glColor3f(153/255.0,0,0);
        glVertex3f(71.0-10-jy, -47.0+40, 12.0);
        glVertex3f(71.0-10-jy, -50.0+40, 12.0);

        glVertex3f(71.0-10-jy, -47.0+40, 9.0);
        glVertex3f(71.0-10-jy, -50.0+40, 9.0);

        glVertex3f(73.0-10-jy, -47.0+40, 9.0);
        glVertex3f(73.0-10-jy, -50.0+40, 9.0);

        glVertex3f(73.0-10-jy, -47.0+40, 12.0);
        glVertex3f(73.0-10-jy, -50.0+40, 12.0);
        glEnd();

    jy+=5;
    }

}

void objek(void){
//lift

        glLineWidth(1.0);

        //kiri
        glBegin(GL_QUADS);
        glColor3f(224/255.0, 224/255.0, 224/255.0);
        glVertex3f(-7.0, -50.0, -79);
        glVertex3f(-7.0, 30.0, -79);
        glVertex3f(-7.0, 30.0, -99);
        glVertex3f(-7.0, -50.0, -99);
        glEnd();

        //depan
        glBegin(GL_QUADS);
        glColor3f(224/255.0, 224/255.0, 224/255.0);
        glVertex3f(-7.0, -50.0, -79);
        glVertex3f(-7.0, 30.0, -79);
        glVertex3f(7.0, 30.0, -79);
        glVertex3f(7.0, -50.0, -79);
        glEnd();

        //depan_tombol
        glBegin(GL_QUADS);
        glColor3f(192/255.0, 192/255.0, 192/255.0);
        glVertex3f(7.0, -50.0, -79);
        glVertex3f(7.0, 30.0, -79);
        glVertex3f(10.0, 30.0, -79);
        glVertex3f(10.0, -50.0, -79);
        glEnd();

        //kiri
        glBegin(GL_QUADS);
        glColor3f(224/255.0, 224/255.0, 224/255.0);
        glVertex3f(10.0, -50.0, -79);
        glVertex3f(10.0, 30.0, -79);
        glVertex3f(10.0, 30.0, -99);
        glVertex3f(10.0, -50.0, -99);
        glEnd();

        //garis
        glBegin(GL_LINES);
        glColor3f(160/255.0,160/255.0,160/255.0);
        glVertex3f(-7.0, -50.0, -78);
        glVertex3f(-7.0, 30.0, -78);

        glVertex3f(0, -50.0, -78);
        glVertex3f(0, 30.0, -78);

        glVertex3f(7.0, 30.0, -78);
        glVertex3f(7.0, -50.0, -78);
        glEnd();

/////////////////////////////////////////////////////////////////////////////////////
///KURSI BEBAS///

 int x = 0;
    for(int i=0;i<4;i++){
        //atas
        glBegin(GL_QUADS);
        glColor3f(51/255.0,51/255.0,255/255.0);
        glVertex3f(-85.5, -47.0+x, 15.0-80-30);
        glVertex3f(-69.5, -47.0+x, 15.0-80-30);
        glVertex3f(-69.5, -47.0+x, 25.0-80-30);
        glVertex3f(-85.5, -47.0+x, 25.0-80-30);
        glEnd();

        //tepibwh
        glBegin(GL_QUADS);
        glColor3f(0/255.0,0/0.0,255/255.0);
        glVertex3f(-85.5, -48.5+x, 25.0-80-30);
        glVertex3f(-69.5, -48.5+x, 25.0-80-30);
        glVertex3f(-69.5, -47.0+x, 25.0-80-30);
        glVertex3f(-85.5, -47.0+x, 25.0-80-30);
        glEnd();

        glLineWidth(15.0);

        ///GARIS
        glBegin(GL_LINES);
        glColor3f(0.8,0.8,0.8);
        glVertex3f(-69.5, -44.0+x, 15.0-80-30);
        glVertex3f(-85.5, -44.0+x, 15.0-80-30);
        glEnd();

        //kaki bangku
        //kiri
        glBegin(GL_QUADS);
        glColor3f(0.5,0.5,0.5);
        glVertex3f(-69.5, -50.0+x, 15.0-80-30);
        glVertex3f(-69.5, -45.0+x, 15.0-80-30);
        glVertex3f(-69.5, -45.0+x, 25.0-80-30);
        glVertex3f(-69.5, -50.0+x, 25.0-80-30);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glColor3f(0.5,0.5,0.5);
        glVertex3f(-85.5, -50.0+x, 15.0-80-30);
        glVertex3f(-85.5, -45.0+x, 15.0-80-30);
        glVertex3f(-85.5, -45.0+x, 25.0-80-30);
        glVertex3f(-85.5, -50.0+x, 25.0-80-30);
        glEnd();

        x+=20;
    }
}

void rdosen(void){

    ///PEMBATAS RUANG
     //TEPI
    glBegin(GL_QUADS);
        glColor3f(224/255.0, 224/255.0, 224/255.0);
        glVertex3f(-110.0, -50.0, -20.0);
        glVertex3f(-110.0, 30.0, -20.0);
        glVertex3f(-110.0, 30.0, -100.0);
        glVertex3f(-110.0, -50.0, -100.0);
        glEnd();

        ///PINTU

        float r=0;
        for(int e=0;e<10;e++){
        glBegin(GL_QUADS);
        glColor3f(255/255.0, 128/255.0, 0/255.0);
        glVertex3f(-110.5+r, 5.0, -40.0);
        glVertex3f(-110.5+r, -10.0, -40.0);
        glVertex3f(-110.5+r, -10.0, -45.0);
        glVertex3f(-110.5+r, 5.0, -45.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(255/255.0, 128/255.0, 0/255.0);
        glVertex3f(-110.5+r, 5.0+20, -40.0);
        glVertex3f(-110.5+r, -10.0+20, -40.0);
        glVertex3f(-110.5+r, -10.0+20, -45.0);
        glVertex3f(-110.5+r, 5.0+20, -45.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(255/255.0, 128/255.0, 0/255.0);
        glVertex3f(-110.5+r, 5.0-20, -40.0);
        glVertex3f(-110.5+r, -10.0-20, -40.0);
        glVertex3f(-110.5+r, -10.0-20, -45.0);
        glVertex3f(-110.5+r, 5.0-20, -45.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(255/255.0, 128/255.0, 0/255.0);
        glVertex3f(-110.5+r, 5.0-40, -40.0);
        glVertex3f(-110.5+r, -10.0-40, -40.0);
        glVertex3f(-110.5+r, -10.0-40, -45.0);
        glVertex3f(-110.5+r, 5.0-40, -45.0);
        glEnd();

        glPointSize(9.0);
        glBegin(GL_POINTS);
        glColor3f(0,0,0);
        glVertex3f(-110.5+r, -4.0, -40.5);
        glVertex3f(-110.5+r, -4.0-20, -40.5);
        glVertex3f(-110.5+r, -4.0-40, -40.5);
        glVertex3f(-110.5+r, -4.0+20, -40.5);



        glEnd();

        r+=0.1;}

    float x=0;
    float xa=40;
    float q=0;

///MEJA KOMPI

    glBegin(GL_QUADS);
        glColor3f(255/255.0,0/255.0,0/255.0);
        glVertex3f(-115.5, -45.0+xa, -98.0);
        glVertex3f(-130.5, -45.0+xa, -98.0);
        glVertex3f(-130.5, -45.0+xa, -88.0);
        glVertex3f(-115.5, -45.0+xa, -88.0);
        glEnd();

        //tepibwh
        glBegin(GL_QUADS);
        glColor3f(153/255.0,0/255.0,0/255.0);
        glVertex3f(-115.5, -46.5+xa, -88.0);
        glVertex3f(-130.5, -46.5+xa, -88.0);
        glVertex3f(-130.5, -45.0+xa, -88.0);
        glVertex3f(-115.5, -45.0+xa, -88.0);
        glEnd();

        glLineWidth(10.0);

        //kaki
        //kiri
        glBegin(GL_QUADS);
        glColor3f(0.5,0.5,0.5);
        glVertex3f(-115.5, -50.0+xa, -88.0);
        glVertex3f(-115.5, -45.0+xa, -88.0);
        glVertex3f(-115.5, -45.0+xa, -98.0);
        glVertex3f(-115.5, -50.0+xa, -98.0);
        glEnd();

        //kanan
        glBegin(GL_QUADS);
        glColor3f(0.5,0.5,0.5);
        glVertex3f(-130.5, -50.0+xa, -88.0);
        glVertex3f(-130.5, -45.0+xa, -88.0);
        glVertex3f(-130.5, -45.0+xa, -98.0);
        glVertex3f(-130.5, -50.0+xa, -98.0);
        glEnd();

        ///KOMPI
        glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex3f(-120.0, -37.0+xa, -94.0);
        glVertex3f(-120.0, -44.0+xa, -93.0);
        glVertex3f(-125.0, -44.0+xa, -93.0);
        glVertex3f(-125.0, -37.0+xa, -94.0);
        glEnd();

        ///cpu
        float o=0;
        for(int v=0;v<30;v++){
        glBegin(GL_QUADS);
        glColor3f(0.7,0.7,0.7);
        glVertex3f(-117.0, -50.0+xa, -89.0-o);
        glVertex3f(-117.0, -45.0+xa, -89.0-o);
        glVertex3f(-119.0, -45.0+xa, -89.0-o);
        glVertex3f(-119.0, -50.0+xa, -89.0-o);
        glEnd();

        o+=0.1;}


        glLineWidth(4.0);
        glBegin(GL_LINES);
        glColor3f(0.5,0.5,0.5);
        glVertex3f(-120.0, -37.0+xa, -94.0);
        glVertex3f(-120.0, -44.0+xa, -93.0);

        glVertex3f(-125.0, -44.0+xa, -93.0);
        glVertex3f(-125.0, -37.0+xa, -94.0);

        glVertex3f(-120.0, -44.0+xa, -93.0);
        glVertex3f(-125.0, -44.0+xa, -93.0);

        glVertex3f(-120.0, -37.0+xa, -94.0);
        glVertex3f(-125.0, -37.0+xa, -94.0);

        glVertex3f(-122.5, -44.0+xa, -94.0);
        glVertex3f(-122.5, -45.0+xa, -94.0);
        glEnd();


/// ////////////////////////////////////////////////////
    for (int a=0;a<70;a++){

        ///buku
        glBegin(GL_QUADS);
        glColor3f(20*q/255.0, 0/255.0, 0/255.0);
        glVertex3f(-154.0+q, -35.0+40, -98.0);
        glVertex3f(-154.0+q, -40.0+40, -98.0);
        glVertex3f(-154.0+q, -40.0+40, -93.0);
        glVertex3f(-154.0+q, -35.0+40, -93.0);
        glEnd();

        q+=0.1;
        }
        float qx = 0;
        for (int w=0;w<30;w++){



        ///buku
        glBegin(GL_QUADS);
        glColor3f(230/255.0, 230/255.0, 193*qx/255.0);
        glVertex3f(-149.0+qx, -45.0+40, -98.0);
        glVertex3f(-149.0+qx, -40.0+40, -98.0);
        glVertex3f(-149.0+qx, -40.0+40, -93.0);
        glVertex3f(-149.0+qx, -45.0+40, -93.0);
        glEnd();

        qx+=0.1;
        }

        ///BUKU 3///
        float qxy = 0;
        for (int z=0;z<30;z++){



        ///buku
        glBegin(GL_QUADS);
        glColor3f(100/255.0, 100/255.0, 193*qx/255.0);
        glVertex3f(-154.0+qxy, -45.0+40, -98.0);
        glVertex3f(-154.0+qxy, -50.0+40, -98.0);
        glVertex3f(-154.0+qxy, -50.0+40, -93.0);
        glVertex3f(-154.0+qxy, -45.0+40, -93.0);
        glEnd();

        qxy+=0.1;
        }


    for(int i=0;i<10;i++){
    ///MEJA///

    glLineWidth(6.0);
    glBegin(GL_QUADS);
    glColor3f(153/255.0, 76/255.0, 0/255.0);
        glVertex3f(-135.0, -44.0+40, -60.0);
        glVertex3f(-141.0, -44.0+40, -60.0);
        glVertex3f(-141.0, -44.0+40, -40.0);
        glVertex3f(-135.0, -44.0+40, -40.0);
        glEnd();

        ///KAKI///
        glBegin(GL_LINES);
    glColor3f(102/255.0, 51/255.0, 0/255.0);
        glVertex3f(-135.0, -44.0+40, -60.0);
        glVertex3f(-135.0, -50.0+40, -60.0);

        glVertex3f(-135.0, -44.0+40, -40.0);
        glVertex3f(-135.0, -50.0+40, -40.0);

        glVertex3f(-141.0, -44.0+40, -60.0);
        glVertex3f(-141.0, -50.0+40, -60.0);

        glVertex3f(-141.0, -44.0+40, -40.0);
        glVertex3f(-141.0, -50.0+40, -40.0);

        glEnd();


/// lemari ////////////////////////////////////
        glBegin(GL_QUADS);
        glColor3f(153/255.0, 76/255.0, 0/255.0);
        glVertex3f(-155.0, -50.0+40, -98.0);
        glVertex3f(-145.0, -50.0+40, -98.0);
        glVertex3f(-145.0, -35.0+40, -98.0);
        glVertex3f(-155.0, -35.0+40, -98.0);
        glEnd();

        ///KANAN///
        glBegin(GL_QUADS);
        glColor3f(204/255.0, 102/255.0, 0/255.0);
        glVertex3f(-145.0, -50.0+40, -93.0);
        glVertex3f(-145.0, -50.0+40, -98.0);
        glVertex3f(-145.0, -35.0+40, -98.0);
        glVertex3f(-145.0, -35.0+40, -93.0);
        glEnd();

        ///KIRI///
        glBegin(GL_QUADS);
        glColor3f(204/255.0, 102/255.0, 0/255.0);
        glVertex3f(-155.0, -50.0+40, -93.0);
        glVertex3f(-155.0, -50.0+40, -98.0);
        glVertex3f(-155.0, -35.0+40, -98.0);
        glVertex3f(-155.0, -35.0+40, -93.0);
        glEnd();

        ///-----///
        ///1


        glBegin(GL_QUADS);
        glColor3f(204/255.0, 102/255.0, 0/255.0);
        glVertex3f(-155.0, -45.0+40, -98.0);
        glVertex3f(-145.0, -45.0+40, -98.0);
        glVertex3f(-145.0, -45.0+40, -93.0);
        glVertex3f(-155.0, -45.0+40, -93.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(204/255.0, 102/255.0, 0/255.0);
        glVertex3f(-155.0, -40.0+40, -98.0);
        glVertex3f(-145.0, -40.0+40, -98.0);
        glVertex3f(-145.0, -40.0+40, -93.0);
        glVertex3f(-155.0, -40.0+40, -93.0);
        glEnd();



        /// KURSI


        glBegin(GL_QUADS);
        glColor3f(160/255.0,160/255.0,160/255.0);
        glVertex3f(-142.0, -47.0+40+x, -47.0);
        glVertex3f(-145.0, -47.0+40+x, -47.0);
        glVertex3f(-145.0, -47.0+40+x, -53.0);
        glVertex3f(-142.0, -47.0+40+x, -53.0);
        glEnd();

        ///SANDARAN///


        glBegin(GL_QUADS);
        glColor3f(96/255.0,96/255.0,96/255.0);
        glVertex3f(-146.0+x, -41.0+40, -53.0);
        glVertex3f(-146.0+x, -41.0+40, -47.0);
        glVertex3f(-145.0+x, -48.0+40, -47.0);
        glVertex3f(-145.0+x, -48.0+40, -53.0);
        glEnd();

        ///TIANG///
        glLineWidth(6.0);
        glBegin(GL_LINES);
        glColor3f(96/255.0,96/255.0,96/255.0);
        glVertex3f(-143.5, -47.0+40, -50.0);
        glVertex3f(-143.5, -50.0+40, -50.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(100/255.0,100/255.0,100/255.0);
        glVertex3f(-142.0, -49.8+40+0.5*x, -47.0);
        glVertex3f(-145.0, -49.8+40+0.5*x, -47.0);
        glVertex3f(-145.0, -49.8+40+0.5*x, -53.0);
        glVertex3f(-142.0, -49.8+40+0.5*x, -53.0);
        glEnd();


        /// KURSI MHS


        glBegin(GL_QUADS);
        glColor3f(160/255.0,160/255.0,160/255.0);
        glVertex3f(-130.0, -47.0+40+x, -47.0);
        glVertex3f(-133.0, -47.0+40+x, -47.0);
        glVertex3f(-133.0, -47.0+40+x, -53.0);
        glVertex3f(-130.0, -47.0+40+x, -53.0);
        glEnd();

        ///SANDARAN///


        glBegin(GL_QUADS);
        glColor3f(96/255.0,96/255.0,96/255.0);
        glVertex3f(-129.0+x, -41.0+40, -53.0);
        glVertex3f(-129.0+x, -41.0+40, -47.0);
        glVertex3f(-130.0+x, -48.0+40, -47.0);
        glVertex3f(-130.0+x, -48.0+40, -53.0);
        glEnd();

        ///TIANG///
        glLineWidth(6.0);
        glBegin(GL_LINES);
        glColor3f(96/255.0,96/255.0,96/255.0);
        glVertex3f(-131.5, -47.0+40, -50.0);
        glVertex3f(-131.5, -50.0+40, -50.0);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(100/255.0,100/255.0,100/255.0);
        glVertex3f(-130.0, -49.8+40+0.5*x, -47.0);
        glVertex3f(-133.0, -49.8+40+0.5*x, -47.0);
        glVertex3f(-133.0, -49.8+40+0.5*x, -53.0);
        glVertex3f(-130.0, -49.8+40+0.5*x, -53.0);
        glEnd();
        x+=0.1;}


}

void tampil(void){

        glPushMatrix();

    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);

    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
       glRotatef(xrot, 1.0f,0.0f, 0.0f);
       glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    pintu();
    jendela();
    balkon();
    depan();
    belakang();
    kanan();
    kiri();
    lobi();
    pembatas_kelas();
    duplicate();
    alas();
    lantai_atas();
    atap();
    lt3();
    rdosen();

    objek();

    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
    /// > = putar kanan
    /// < = putar kiri
    /// a = rotasi kiri
    /// s = rotasi kanan
    /// + = maju
    /// - = mundur
    /// 2 = geser kanan
    /// 1 = geser kiri
    /// 3 = geser atas
    /// 4 = geser bawah
    /// 5 = putar bawah
    /// 6 = putar atas
    /// 0 = transparan

    switch (key)
    {
    case '+':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case '-':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case '1':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case '2':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case '3':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case '4':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case '5':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '>':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '<':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case 'a':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case 's':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '0':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void identity(){
    glLoadIdentity();

}

void idle(){
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y){
    //identity();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }

}

void ukuran(int lebar, int tinggi){
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
