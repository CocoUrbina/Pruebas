#!/usr/bin/env python 3

import numpy as np

#-----------funcion que calcula los puntos de muestreo y los pesos

def gaussxw(N):
    x, w = np.polynomial.legendre.leggauss(N)
    return x, w

#------------funcion que escala al intervalo en cuestion

def gaussxwab (a, b, x, w):
    return 0.5 * (b - a) * x + 0.5 * (b + a), 0.5 * (b - a) * w

#----calculo de los puntos de muestreo y los pesos segun el orden de interes

n2 = gaussxw(2)
print(n2)

n3 = gaussxw(3)
print(n3)

n4 = gaussxw(4)
print(n4)

n5 = gaussxw(5)
print(n5)

#------------escalado al intervalo de interes
# [1, 3] en nuestro caso

escalado_n2 = gaussxwab(1.0, 3.0, n2[0], n2[1])
print(escalado_n2)

escalado_n3 = gaussxwab(1.0, 3.0, n3[0], n3[1])
print(escalado_n3)

escalado_n4 = gaussxwab(1.0, 3.0, n4[0], n4[1])
print(escalado_n4)

escalado_n5 = gaussxwab(1.0, 3.0, n5[0], n5[1])
print(escalado_n5)

#-----------integrando de interes

def integrando(x):
    funcEval = x**6 - x**2 * np.sin(2*x)
    return funcEval

#----------Aproximacion del integrando con cuadraturas Gaussianas

Int_n2 = np.sum(escalado_n2[1] * integrando(escalado_n2[0]))
print(Int_n2)

Int_n3 = np.sum(escalado_n3[1] * integrando(escalado_n3[0]))
print(Int_n3)

Int_n4 = np.sum(escalado_n4[1] * integrando(escalado_n4[0]))
print(Int_n4)

Int_n5 = np.sum(escalado_n5[1] * integrando(escalado_n5[0]))
print(Int_n5)

