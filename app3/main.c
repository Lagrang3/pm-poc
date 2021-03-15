#include <stdio.h>
#include <stdlib.h>
#include <c_ParticleMesh.h>
#include "my_particle_data.h"
#include "my_handler.h"


int main()
{
    int N = 2;
    my_particle_data* P;
    P = (my_particle_data*) malloc(sizeof(my_particle_data)*N);
    
    P[0].Pos[0] = 1.5;
    P[0].Pos[1] = 1.0;
    P[0].Pos[2] = 1.0;
    
    P[1].Pos[0] = 2.0;
    P[1].Pos[1] = 3.0;
    P[1].Pos[2] = 4.7;
    
    my_handler * H = handler_new(P,2,10.0); 
    ParticleMesh* pm = pm_new(H);
    printf("pm.sum() = %d\n",pm_sum(pm));
    pm_change(pm);
    printf("pm.sum() = %d\n",pm_sum(pm));
    
    pm_free(pm);
    handler_free(H);
    free(P);
    return 0;
}
