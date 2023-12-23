//
//  House.hpp
//  Prog04
//
//  Created by Nick Marshall on 11/16/23.
//

#ifndef House_hpp
#define House_hpp

#include <memory>
#include <vector>
//
#include "GraphicObject3D.h"

namespace graphics3d {

    class House : public GraphicObject3D {
        
    private:
        
        std::vector<std::vector<float> > vertices;
        
    public:
        
        House(const Pose& pose, const Motion& motion);
        ~House();
        
        void addVertices();
        void draw() const;
    };
}

#endif /* House_hpp */
