#include "ParticleMesh.hpp"

    int ParticleMesh::sum() const 
    {
        int s=0;
        for(size_t i=0;i<H.size();++i)
        {
            for(auto x : H.get_position(i))
                s+=x; 
        }
        return s;
    }
    void ParticleMesh::change()const
    {
        for(size_t i=0;i<H.size();++i)
            H.set_position(i,{1,1,1});
          
    }
