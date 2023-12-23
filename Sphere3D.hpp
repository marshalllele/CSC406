//
//  Sphere3D.hpp
//  Prog04
//
//  Created by Nick Marshall on 11/26/23.
//

#ifndef Sphere3D_hpp
#define Sphere3D_hpp

#include <stdio.h>
#include <vector>
#include <memory>
//
#include "GraphicObject3D.h"

namespace graphics3d {

    class Sphere3D : public GraphicObject3D {
        
    private:
        
        float radius;
        float xCoord, yCoord, zCoord, xyCoord;  //  Vertex coordinates
        float xNorm, yNorm, zNorm, lengthInv = 1.f / radius;   //  Vertex Normals
        float squareAngle, ringAngle;
        GLfloat*** vertices;
        GLfloat** normals;
        std::vector<unsigned int> indices;
        std::vector<unsigned int> lineIndices;
        
        // interleaved
        std::vector<float> interleavedVertices;
        int interleavedStride;                  // # of bytes to hop to the next vertex (should be 32 bytes)
        
        //  Constants
        int ringCount = 18;
        int squareCount = 36;
        float squareStep = 2 * PI / ringCount;
        float ringStep = PI / ringCount;
    
    public:
        
        Sphere3D(float rad, const Pose& pose, const Motion& motion = Motion::NULL_MOTION);
        ~Sphere3D();
        
        Sphere3D(const Sphere3D& obj) = delete;
        Sphere3D operator =(const Sphere3D& obj) = delete;
        Sphere3D(Sphere3D&& obj) = delete;
        Sphere3D& operator =(Sphere3D&& obj) = delete;
        Sphere3D() = delete;
        
        void initMeshAndNormals();
        void draw() const;
        
    };

}
#endif /* Sphere3D_hpp */
