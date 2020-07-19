#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil (void);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

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
    glVertex3f(-45.0, -50.0, 10.0);
    glVertex3f(-45.0, 30.0, 10.0);
    glVertex3f(45.0, 30.0, 10.0);
    glVertex3f(45.0, -50.0, 10.0);
    glEnd();
    ///depan kanan
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(45.0, -50.0, 30.0);
    glVertex3f(45.0, 30.0, 30.0);
    glVertex3f(110.0, 30.0, 30.0);
    glVertex3f(110.0, -50.0, 30.0);
    glEnd();
    ///depan kiri
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-45.0, -50.0, 30.0);
    glVertex3f(-45.0, 30.0, 30.0);
    glVertex3f(-110.0, 30.0, 30.0);
    glVertex3f(-110.0, -50.0, 30.0);
    glEnd();
}

void belakang (void){
    ///belakang
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-160.0, -50.0, -100.0);
    glVertex3f(-160.0, 30.0, -100.0);
    glVertex3f(160.0, 30.0, -100.0);
    glVertex3f(160.0, -50.0, -100.0);
    glEnd();
}

void kiri(void){
    ///kiri
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(-45.0, 30.0, 30.0);
    glVertex3f(-45.0, -50.0, 30.0);
    glVertex3f(-45.0, -50.0, 10.0);
    glVertex3f(-45.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(-110.0, 30.0, 30.0);
    glVertex3f(-110.0, -50.0, 30.0);
    glVertex3f(-110.0, -50.0, -20.0);
    glVertex3f(-110.0, 30.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(-110.0, -50.0, -20.0);
    glVertex3f(-110.0, 30.0, -20.0);
    glVertex3f(-160.0, 30.0, -20.0);
    glVertex3f(-160.0, -50.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(-160.0, 30.0, -20.0);
    glVertex3f(-160.0, -50.0, -20.0);
    glVertex3f(-160.0, -50.0, -100.0);
    glVertex3f(-160.0, 30.0, -100.0);
    glEnd();
}

void kanan(void){
    ///kanan
    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(45.0, 30.0, 30.0);
    glVertex3f(45.0, -50.0, 30.0);
    glVertex3f(45.0, -50.0, 10.0);
    glVertex3f(45.0, 30.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(110.0, 30.0, 30.0);
    glVertex3f(110.0, -50.0, 30.0);
    glVertex3f(110.0, -50.0, -20.0);
    glVertex3f(110.0, 30.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 250/255.0, 205/255.0);
    glVertex3f(110.0, -50.0, -20.0);
    glVertex3f(110.0, 30.0, -20.0);
    glVertex3f(160.0, 30.0, -20.0);
    glVertex3f(160.0, -50.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(255/255.0, 0/255.0, 205/255.0);
    glVertex3f(160.0, 30.0, -20.0);
    glVertex3f(160.0, -50.0, -20.0);
    glVertex3f(160.0, -50.0, -100.0);
    glVertex3f(160.0, 30.0, -100.0);
    glEnd();
}

void alas(void){
    int x = 0;
    int a = 0;
    for(int i=0;i<5;i++){
        glColor3f(0*a/255.0, 2*a/255.0, 10*a/255.0);
        ///kanan
        glBegin(GL_POLYGON);
        glVertex3f(45.0, -50.0+x, -100.0);
        glVertex3f(45.0, -50.0+x, 30.0);
        glVertex3f(110.0, -50.0+x, 30.0);
        glVertex3f(110.0, -50.0+x, -20.0);
        glVertex3f(160.0, -50.0+x, -20.0);
        glVertex3f(160.0, -50.0+x, -100.0);
        glEnd();
        ///tengah
        glBegin(GL_POLYGON);
        glVertex3f(45.0, -50.0+x, 10.0);
        glVertex3f(-45.0, -50.0+x, 10.0);
        glVertex3f(-45.0, -50.0+x, -100.0);
        glVertex3f(45.0, -50.0+x, -100.0);
        glEnd();
        ///kiri
        glBegin(GL_POLYGON);
        glVertex3f(-45.0, -50.0+x, -100.0);
        glVertex3f(-45.0, -50.0+x, 30.0);
        glVertex3f(-110.0, -50.0+x, 30.0);
        glVertex3f(-110.0, -50.0+x, -20.0);
        glVertex3f(-160.0, -50.0+x, -20.0);
        glVertex3f(-160.0, -50.0+x, -100.0);
        glEnd();
        x+=20;
        a+=5;
    }
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

}

void objek(void){

}

void tampil(void){
    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);

    pintu();
    jendela();
    depan();
    belakang();
    kanan();
    kiri();
    alas();
    lantai_atas();
    atap();

    objek();

    glPushMatrix();
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

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

void identity(){
    glLoadIdentity();
       gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
       glRotatef(xrot, 1.0f,0.0f, 0.0f);
       glRotatef(yrot, 0.0f, 1.0f, 0.0f);
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
    identity();
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
    gluPerspective(55.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
