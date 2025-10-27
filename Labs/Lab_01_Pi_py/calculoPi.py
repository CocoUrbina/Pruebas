#!/usr/bin/env python3

#Riemann sum function
#The following function takes 4 parameters as follows:
#func: the function we want to sum over
#partitions: the number of segments the interval will be divided
#lower_lim: the lower limit for the interval we want to sum over
#upper_lim: the upper limit for the interval we want to sum over

#The mesh is computed
#The height for each rectangle is calculated. We use the middle point.
# height_i = mesh*i + mesh / 2
#Now the area for each rectangle can be calculate as:
# a_i = func(height_i) * mesh
# And the total area tA  can be calculated as:
# tA = sum a_i
#Since the mesh is common for each a_i, it can be factorized. So:
# tA = sum func(height_i) * mesh

def riemann(func, partitions, lower_lim, upper_lim):
    mesh = (upper_lim - lower_lim) / partitions
    tA = 0.0
    for i in range(partitions):
        #mesh_i = mesh * i + mesh / 2
        #height_i = func(mesh_i)
        #a_i = height_i * mesh
        #tA += a_i
        # The 4 above lines can be optimized  as follows:
        tA += func(mesh * i + mesh / 2) #sums up all the heights
    return tA * mesh

def integrand(x):
    return 4.0 / (1.0 + x*x) #our integrand to approximate Pi

print(riemann(integrand, 1000, 0.0, 1.0))
