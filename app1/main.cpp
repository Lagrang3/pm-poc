#include <iostream>
#include <vector>
#include <array>
#include <ParticleMesh.hpp>

struct my_particle_data
{
    int Pos[3];
};

struct my_handler : handler_t
{
    std::vector< my_particle_data >& P;
    size_t N{};
    size_t size()const override
    {
        return N;
    }
    my_handler( std::vector< my_particle_data >& simP):
        P{simP}, N{P.size()}
    {
        
    }
    std::array<int,3> get_position(int i)const override
    {
        return std::array<int,3>{P[i].Pos[0],P[i].Pos[1],P[i].Pos[2]};
    }
    void set_position(int i, std::array<int,3> p)const override
    {
        for(int j=0;j<3;++j)
            P[i].Pos[j] = p[j];
    }
};

int main()
{
    
    std::vector< my_particle_data  > P;
    P.push_back({1,1,1});
    P.push_back({2,3,4});
    
    my_handler H(P);
    
    ParticleMesh pm(H);
    
    std::cout << "pm.sum() = " << pm.sum() << '\n';
    pm.change();
    std::cout << "pm.sum() = " << pm.sum() << '\n';
    
    return 0;
}
