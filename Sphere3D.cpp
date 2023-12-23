//
//  Sphere3D.cpp
//  Prog04
//
//  Created by Nick Marshall on 11/26/23.
//

#include "Sphere3D.hpp"

using namespace graphics3d;
using namespace std;

Sphere3D::Sphere3D(float rad, const Pose& pose, const Motion& motion)
    : GraphicObject3D(pose, motion),
    //
    radius(rad),
    vertices(nullptr),
    normals(nullptr)
{
    initMeshAndNormals();
}
Sphere3D::~Sphere3D()
{}

void Sphere3D::initMeshAndNormals() {
    vertices = new GLfloat**[ringCount+1];
    for (unsigned int i=0; i<=ringCount; i++)
    {
        vertices[i] = new GLfloat*[squareCount];
        for (unsigned int j=0; j<squareCount; j++)
        {
            vertices[i][j] = new GLfloat[3];
        }
    }
    normals = new GLfloat*[squareCount];
    for (unsigned int j=0; j<squareCount; j++)
    {
        normals[j] = new GLfloat[3];
    }

    
    for (int i = 0; i < ringCount; i++) {
        ringAngle = PI / 2 - i * ringStep;
        xyCoord = radius * cosf(ringAngle);
        zCoord = radius * sinf(ringAngle);
        
        for (int j = 0; j < squareCount; j++) {
            
            squareAngle = j * squareStep;
            
            //  (x, y, z)
            xCoord = xyCoord * cosf(squareAngle);
            yCoord = xyCoord * sinf(squareAngle);
            vertices[i][j][0] = xCoord;
            vertices[i][j][1] = yCoord;
            vertices[i][j][2] = zCoord;
            
            xNorm = xCoord * lengthInv;
            yNorm = yCoord * lengthInv;
            zNorm = zCoord * lengthInv;
            normals[j][0] = xNorm;
            normals[j][1] = yNorm;
            normals[j][2] = zNorm;
            
        }
    }
}



void Sphere3D::draw() const {
    
    glPushMatrix();
    applyPose();

    setCurrentMaterial(getMaterial());
    
    glScalef(.2, .2, .2);
    glTranslatef(-1.f, 0.f, 0.f);
    
    for (int i = 0; i < ringCount; i++) {
        
        glBegin(GL_TRIANGLES);
        for (int j = 0; j < squareCount; j++) {
            glNormal3fv(normals[j]);
            glVertex3fv(vertices[i][j]);
            glNormal3fv(normals[j]);
            glVertex3fv(vertices[i+1][j]);
        }
        
        // close the ring
        glNormal3fv(normals[0]);
        glVertex3fv(vertices[i][0]);
        glNormal3fv(normals[0]);
        glVertex3fv(vertices[i+1][0]);
        
        glEnd();
    }
    
    glPopMatrix();
}
