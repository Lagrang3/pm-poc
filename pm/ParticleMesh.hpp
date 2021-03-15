#pragma once

#include <cstdlib>
#include <array>

struct handler_t
{
    virtual size_t size() const = 0;
    virtual std::array<int,3> get_position(int i)const =0;
    virtual void set_position(int i,std::array<int,3> p)const =0;
    virtual ~handler_t(){}
};

struct ParticleMesh
{
    const handler_t& H;
    ParticleMesh(const handler_t& ph) : H(ph)
    {}
    
    int sum() const ;
    void change() const;
};
