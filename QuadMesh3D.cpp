//
//  QuadMesh.cpp
//  Week 10 - 3D Objects
//
//  Created by Jean-Yves Hervé on 2023-11-02.
//

#include "QuadMesh3D.h"

using namespace graphics3d;
using namespace std;

QuadMesh3D::QuadMesh3D(float width, float height, unsigned int numRows, unsigned int numCols,
					   const Pose& pose, const Motion& motion)
	:	GraphicObject3D(pose, motion),
		width_(width),
		height_(height),
		numRows_(numRows),
		numCols_(numCols),
		xyz_(new GLfloat**[numRows])
{
	for (unsigned int i=0; i<numRows; i++)
	{
		xyz_[i] = new GLfloat*[numCols];
		for (unsigned int j=0; j<numCols; j++)
		{
			xyz_[i][j] = new GLfloat[3];
		}
	}
	
	//	My indices (0, 0) start from bottom left of the mesh
	const GLfloat stepX = width / (numCols-1);
	const GLfloat stepY = height / (numRows-1);
	for (unsigned int i=0; i<numRows; i++)
	{
		const GLfloat y = -0.5f*height + i*stepY;
		for (unsigned int j=0; j<numCols; j++)
		{
			//	X
			xyz_[i][j][0] = -0.5f*width + j*stepX;
			// Y same for all row
			xyz_[i][j][1] = y;
			//	Z is zero all over the mesh
			xyz_[i][j][2] = 0.f;
		}
	}
	
}

QuadMesh3D::~QuadMesh3D()
{
	for (unsigned int i=0; i<numRows_; i++)
	{
		for (unsigned int j=0; j<numCols_; j++)
		{
			delete []xyz_[i][j];
		}
		delete []xyz_[i];
	}
	delete []xyz_;
}

void QuadMesh3D::draw() const
{
	glPushMatrix();
	applyPose();

	drawReferenceFrame();
	
	setCurrentMaterial(getMaterial());
	for (unsigned int i=0; i<numRows_-1; i++)
	{
		glBegin(GL_QUAD_STRIP);
		for (unsigned int j=0; j<numCols_; j++)
		{
			glVertex3fv(xyz_[i][j]);
			glVertex3fv(xyz_[i+1][j]);
		
		}
		glEnd();
	}
	glPopMatrix();
}
	
void QuadMesh3D::displaceVertex(unsigned int row, unsigned int col, float dZ)
{
	if ((row < numRows_) && (col < numCols_))
		xyz_[row][col][2] += dZ;
		
}
