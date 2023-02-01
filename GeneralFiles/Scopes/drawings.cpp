#include <GL/freeglut.h>
#include "../Header/drawings.h"
#include "../Header/globalParameters.h"
#include <functional>

std::vector<GLuint> textures;

void textureModule(void templateSquare(double, double, GLuint),double x, double y, GLuint z)
{
    GLuint aux = glGenLists(1);
    
    glNewList(aux, GL_COMPILE);
        templateSquare(x,y,z);
    glEndList();
    textures.push_back(aux);
}

void textureModule(void templateSquare(double  , double  , GLuint  , double   , double   , double   , double ),
                                       double x, double y, GLuint z, double wo, double uo, double dw, double du)
{
    GLuint aux = glGenLists(1);
    
    glNewList(aux, GL_COMPILE);
        templateSquare(x, y, z, wo, uo, dw, du);
    glEndList();
    textures.push_back(aux);
}

void templateSquare(double x, double y, GLuint id)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, id);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_FAN);

    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(0,0); 
        glVertex2f (-x,-y);

        glTexCoord2f(1,0);
        glVertex2f (x,-y);

        glTexCoord2f(1,1);
        glVertex2f (x,y);

        glTexCoord2f(0,1);
        glVertex2f(-x,y);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

void templateSquare(double x, double y, GLuint id, double wo, double uo, double dw, double du)
{
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, id);
        glColor3f(1,1,1);
        glBegin(GL_TRIANGLE_FAN);

        glBegin(GL_TRIANGLE_FAN);
            glTexCoord2f(wo,uo); 
            glVertex2f (-x,-y);

            glTexCoord2f(wo + dw,uo);
            glVertex2f (x,-y);

            glTexCoord2f(wo + dw,uo + du);
            glVertex2f (x,y);

            glTexCoord2f(wo,uo + du);
            glVertex2f(-x,y);
        glEnd();
    glDisable(GL_TEXTURE_2D);
}

GLuint loadTexture(const char* arquivo)
{
    GLuint idTextura = SOIL_load_OGL_texture(
        arquivo,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );

    return idTextura;
}

void initializeTextures()
{
    // Cria um quadrado com dimensoes x y, carrega a textura em questão e armazena os IDs gerados no vector "textures"

     /*[0]*/textureModule(templateSquare,50, 15,loadTexture("PNG_deposit/ajudaNew.png"));
     /*[1]*/textureModule(templateSquare, 5,  5,loadTexture("PNG_deposit/blueBall.png"));
     /*[2]*/textureModule(templateSquare, 7,  2,loadTexture("PNG_deposit/blueLaser.png"));
     /*[3]*/textureModule(templateSquare, 7,  7,loadTexture("PNG_deposit/fireBall.png"));
     /*[4]*/textureModule(templateSquare, 2, 20,loadTexture("PNG_deposit/greenLaser.png"));
     /*[5]*/textureModule(templateSquare,50, 15,loadTexture("PNG_deposit/iniciarNew.png"));
     /*[6]*/textureModule(templateSquare, 5,  5,loadTexture("PNG_deposit/orangeBall.png"));
     /*[7]*/textureModule(templateSquare, 1, 12,loadTexture("PNG_deposit/redLaser.png"));
     /*[8]*/textureModule(templateSquare, 7,  7,loadTexture("PNG_deposit/setaNew.png"));
     /*[9]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/space1.png"));
    /*[10]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/space2.png"));
    /*[11]*/textureModule(templateSquare,25, 25,loadTexture("PNG_deposit/spaceship1.png"));
    /*[12]*/textureModule(templateSquare,20, 25,loadTexture("PNG_deposit/spaceship2.png"));
    /*[13]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/spaceship3.png"));
    /*[14]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/spaceship4.png"));
    /*[15]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/ajudaBackgoundNew.png"));
    /*[16]*/textureModule(templateSquare, 1, 4, loadTexture("PNG_deposit/letrinhasDemasiadamenteMuitoCria.png"), 0, 0, 53.0/1242, 1);
    /*[17 - 25]*/

    float soma=60.0/1242, propX = 131.0/1242;
    for(int i=0; i<9; i++)
    {
        textureModule(templateSquare, 3, 4, loadTexture("PNG_deposit/letrinhasDemasiadamenteMuitoCria.png"), soma, 0, propX, 1);
        soma += propX;
    }
    /*[26]*/textureModule(templateSquare, 7,  7,loadTexture("PNG_deposit/heart.png"));
    /*[27]*/textureModule(templateSquare,15, 15,loadTexture("PNG_deposit/spaceship5.png"));
    /*[28]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/spaceship6.png"));
    /*[29]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/spaceship7.png"));
    /*[30]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/backGroundMenu.png"));
    /*[31]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/asteroidShip.png"));
    /*[32]*/textureModule(templateSquare,30, 30,loadTexture("PNG_deposit/asteroid.png"));
    /*[33]*/textureModule(templateSquare,20, 20,loadTexture("PNG_deposit/rotationSpecaship.png"));
    /*[34]*/textureModule(templateSquare,10, 10,loadTexture("PNG_deposit/coletavelVida.png"));
    /*[35]*/textureModule(templateSquare,10, 10,loadTexture("PNG_deposit/coletavelFireRate.png"));
    /*[36]*/textureModule(templateSquare,10, 10,loadTexture("PNG_deposit/coletavelDamage.png"));
    /*[37]*/textureModule(templateSquare,10, 10,loadTexture("PNG_deposit/coletavelAumentaNumTiro.png"));
    /*[38]*/textureModule(templateSquare,10, 10,loadTexture("PNG_deposit/coletavelTrocaTipoTiro.png"));
    /*[39]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/redSpace1.png"));
    /*[40]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/redSpace2.png"));
    /*[41]*/textureModule(templateSquare,50, 50,loadTexture("PNG_deposit/boss.png"));
    /*[42]*/textureModule(templateSquare, 17, 15,loadTexture("PNG_deposit/rotationSpecaship.png"));
    /*[43]*/textureModule(templateSquare, 30, 20,loadTexture("PNG_deposit/trippleTurret.png"));
    /*[44]*/textureModule(templateSquare, 140, 140,loadTexture("PNG_deposit/chadMaster.png"));
    /*[45]*/textureModule(templateSquare, 80, 40,loadTexture("PNG_deposit/level1.png"));
    /*[46]*/textureModule(templateSquare, 80, 40,loadTexture("PNG_deposit/level2.png"));
    /*[47]*/textureModule(templateSquare, 80, 40,loadTexture("PNG_deposit/gameOver.png"));
    /*[48]*/textureModule(templateSquare, 80, 40,loadTexture("PNG_deposit/missaoConcluida.png"));
    /*[49]*/textureModule(templateSquare, 40, 40,loadTexture("PNG_deposit/balao.png"));
    /*[50]*/textureModule(templateSquare, 30, 25,loadTexture("PNG_deposit/torretaGrossa.png"));
    /*[51]*/textureModule(templateSquare, 40, 10,loadTexture("PNG_deposit/barraHp.png"));
    /*[52]*/textureModule(templateSquare, 40, 10,loadTexture("PNG_deposit/molduraBarraHp.png"));
    /*[53]*/textureModule(templateSquare, 30, 20,loadTexture("PNG_deposit/trippleTurretGG.png"));
    /*[54]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/creditos1.png"));
    /*[55]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/creditos2.png"));
    /*[56]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/creditos3.png"));
    /*[57]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/creditos4.png"));
    /*[58]*/textureModule(templateSquare,90,100,loadTexture("PNG_deposit/creditos5.png"));

}

void drawModel(MovableEntity *m)
{
    glPushMatrix();
        glTranslatef(m->getMidPoint().getX(),
                    m->getMidPoint().getY(),
                    0);
        glRotatef(m->getAngle(), 0, 0, 1);
        glScalef(m->getResize(), m->getResize(), 1);
        glCallList(m->getDisplayListModel());
    glPopMatrix();
}

void drawModel(MovableEntity *m, const int& dx, const int& dy)
{
    glPushMatrix();
        glTranslatef(m->getMidPoint().getX(),
                    m->getMidPoint().getY(),
                    0);
        glRotatef(m->getAngle(), 0, 0, 1);
        glTranslatef(dx, dy, 0);
        glScalef(m->getResize(), m->getResize(), 1);
        glCallList(m->getDisplayListModel());
    glPopMatrix();
}

void drawHitbox(MovableEntity* m)
{
    glColor3f(0, 1, 0);
    glLineWidth(2);


    for (int i = 0, j = 1; i < 4; i++, j = (i + 1) % 4)
    {
        glBegin(GL_LINES);
            glVertex2f(m->getAlteredHitbox()[i].getX(), m->getAlteredHitbox()[i].getY());
            glVertex2f(m->getAlteredHitbox()[j].getX(), m->getAlteredHitbox()[j].getY());
        glEnd();
    }
}