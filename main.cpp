#include<windows.h>
#include<gl/glut.h>
#include<math.h>

void init(void);
void tampil (void);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

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

void atap(void){

}

void pintu(void){

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
