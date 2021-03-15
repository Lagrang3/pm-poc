#include <ParticleMesh.hpp>
#include <c_ParticleMesh.h>

extern "C" {


ParticleMesh* pm_new(handler_t* H)
{
    return new ParticleMesh(H);
}
void pm_free(ParticleMesh* pm)
{
    delete pm;
}
void pm_change(ParticleMesh* pm)
{
    pm->change();
}
int pm_sum(ParticleMesh* pm)
{
    return pm->sum();
}

}
