App3
===

This is a C application that uses PM library.
Particle's positions are stored in `double`'s.

App3 must implement a `handler_t` class to communicate with the `ParticleMesh`.
That implementation takes care of the conversion from `double` coordinates to
`int` and viceversa.

In addition, a C interface must be written for the `handler_t`: 

```
extern "C"
{
my_handler* handler_new(my_particle_data* P, size_t n, double l)
{
    return new my_handler(P,n,l);
}
}
```
