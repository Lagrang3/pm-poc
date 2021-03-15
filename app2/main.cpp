#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <ParticleMesh.hpp>

struct my_particle_data
{
    double Pos[3];
};

struct my_handler : handler_t
{
    std::vector< my_particle_data >& P;
    size_t N{};
    double L;
    static constexpr int Nmax = 100;
    size_t size()const override
    {
        return N;
    }
    my_handler( std::vector< my_particle_data >& simP,double l):
        P{simP}, N{P.size()}, L{l}
    {
        
    }
    inline int float_to_int(double x)const
    {
        return std::floor ( Nmax * x / L );
    }
    inline double int_to_float(int x) const
    {
        return (L * x )/Nmax;
    }
    std::array<int,3> get_position(int i)const override
    {
        return std::array<int,3>{
            float_to_int(P[i].Pos[0]) ,
            float_to_int(P[i].Pos[1]) ,
            float_to_int(P[i].Pos[2])};
    }
    void set_position(int i, std::array<int,3> p)const override
    {
        for(int j=0;j<3;++j)
            P[i].Pos[j] = int_to_float( p[j] );
    }
};

int main()
{
    
    std::vector< my_particle_data  > P;
    P.push_back({1.5,1.,1.});
    P.push_back({2.,3.,4.7});
    
    ParticleMesh pm(new my_handler(P,10.0));
    
    std::cout << "pm.sum() = " << pm.sum() << '\n';
    pm.change();
    std::cout << "pm.sum() = " << pm.sum() << '\n';
    
    return 0;
}
