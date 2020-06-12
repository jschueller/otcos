#!/usr/bin/env python

from __future__ import print_function
import openturns.testing as ott
import otcos
import math as m

scale = [1.0]
amplitude = [1.0]
alpha = 1.36
cosine = otcos.CosineCovarianceModel(scale, amplitude, alpha)
print(cosine)

tau = 0.1
c = cosine([tau])[0,0]
print("tau=", tau)
print("c=", c)
c_ref = m.cos(4*tau)*m.cosh((tau-m.pi)/alpha)/m.cosh(m.pi/alpha)
ott.assert_almost_equal(c, c_ref)
