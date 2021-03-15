#include "my_handler.h"
#include "my_particle_data.h"
#include <ParticleMesh.hpp>
#include <cmath>



struct my_handler : handler_t
{
    my_particle_data* P;
    size_t N{};
    double L;
    static constexpr int Nmax = 100;
    size_t size()const override
    {
        return N;
    }
    my_handler( my_particle_data* simP,size_t n , double l):
        P{simP}, N{n}, L{l}
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

extern "C"
{
my_handler* handler_new(my_particle_data* P, size_t n, double l)
{
    return new my_handler(P,n,l);
}
// void handler_free(my_handler* h){delete h;}
}
