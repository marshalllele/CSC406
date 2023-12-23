//
//  House.cpp
//  Prog04
//
//  Created by Nick Marshall on 11/16/23.
//

#include "House.hpp"

using namespace std;
using namespace graphics3d;

House::House(const Pose& pose, const Motion& motion) :
    GraphicObject3D(pose, motion)
{
    addVertices();
}
House::~House(){}

void House::addVertices() {
    vertices.push_back({-1.0, -1.0, 1.0});  //  1
    vertices.push_back({1.0, -1.0, 1.0});   //  2
    vertices.push_back({1.0, 1.0, 1.0});    //  3
    vertices.push_back({-1.0, 1.0, 1.0});   //  4
    vertices.push_back({-1.0, -1.0, -1.0}); //  5
    vertices.push_back({1.0, -1.0, -1.0});  //  6
    vertices.push_back({1.0, 1.0, -1.0});   //  7
    vertices.push_back({-1.0, 1.0, -1.0});  //  8
    vertices.push_back({0.0, -1.0, 1.5});   //  9
    vertices.push_back({0.0, 1.0, 1.5});    //  10
}

void House::draw() const {
    
    glPushMatrix();
    applyPose();
    
    //setCurrentMaterial(getMaterial());
    
    glScalef(.2f, .2f, .2f);
    glTranslatef(0.f, 0.f, 2.f);
    
    //  Left Face
    glBegin(GL_QUADS);
    glVertex3f(vertices[0][0], vertices[0][1], vertices[0][2]);
    glVertex3f(vertices[3][0], vertices[3][1], vertices[3][2]);
    glVertex3f(vertices[7][0], vertices[7][1], vertices[7][2]);
    glVertex3f(vertices[4][0], vertices[4][1], vertices[4][2]);
    glEnd();
    
    //  Right Face
    glBegin(GL_QUADS);
    glVertex3f(vertices[1][0], vertices[1][1], vertices[1][2]);
    glVertex3f(vertices[3][0], vertices[3][1], vertices[3][2]);
    glVertex3f(vertices[7][0], vertices[7][1], vertices[7][2]);
    glVertex3f(vertices[4][0], vertices[4][1], vertices[4][2]);
    glEnd();
    
    //  Front Face
    glBegin(GL_QUADS);
    glVertex3f(vertices[0][0], vertices[0][1], vertices[0][2]);
    glVertex3f(vertices[4][0], vertices[4][1], vertices[4][2]);
    glVertex3f(vertices[5][0], vertices[5][1], vertices[5][2]);
    glVertex3f(vertices[1][0], vertices[1][1], vertices[1][2]);
    glEnd();
    
    //  Back Face
    glBegin(GL_QUADS);
    glVertex3f(vertices[3][0], vertices[3][1], vertices[3][2]);
    glVertex3f(vertices[2][0], vertices[2][1], vertices[2][2]);
    glVertex3f(vertices[6][0], vertices[6][1], vertices[6][2]);
    glVertex3f(vertices[7][0], vertices[7][1], vertices[7][2]);
    glEnd();
    
    //  Bottom Face
    glBegin(GL_QUADS);
    glVertex3f(vertices[4][0], vertices[4][1], vertices[4][2]);
    glVertex3f(vertices[7][0], vertices[7][1], vertices[7][2]);
    glVertex3f(vertices[6][0], vertices[6][1], vertices[6][2]);
    glVertex3f(vertices[5][0], vertices[5][1], vertices[5][2]);
    glEnd();
    
    //  Front Roof Face
    glBegin(GL_TRIANGLES);
    glVertex3f(vertices[0][0], vertices[0][1], vertices[0][2]);
    glVertex3f(vertices[1][0], vertices[1][1], vertices[1][2]);
    glVertex3f(vertices[8][0], vertices[8][1], vertices[8][2]);
    glEnd();
    
    //  Back Roof Face
    glBegin(GL_TRIANGLES);
    glVertex3f(vertices[2][0], vertices[2][1], vertices[2][2]);
    glVertex3f(vertices[3][0], vertices[3][1], vertices[3][2]);
    glVertex3f(vertices[9][0], vertices[9][1], vertices[9][2]);
    glEnd();
    
    //  Roof Side 1
    glBegin(GL_QUADS);
    glVertex3f(vertices[0][0], vertices[0][1], vertices[0][2]);
    glVertex3f(vertices[8][0], vertices[8][1], vertices[8][2]);
    glVertex3f(vertices[9][0], vertices[9][1], vertices[9][2]);
    glVertex3f(vertices[3][0], vertices[3][1], vertices[3][2]);
    glEnd();
    
    //  Roof Side 2
    glBegin(GL_QUADS);
    glVertex3f(vertices[1][0], vertices[1][1], vertices[1][2]);
    glVertex3f(vertices[2][0], vertices[2][1], vertices[2][2]);
    glVertex3f(vertices[9][0], vertices[9][1], vertices[9][2]);
    glVertex3f(vertices[8][0], vertices[8][1], vertices[8][2]);
    glEnd();
    
    glPopMatrix();
}
