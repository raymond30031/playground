# Polynomial fitting with Least Square
# Reference: https://docs.scipy.org/doc/numpy/reference/generated/numpy.polyfit.html

import numpy as np
import matplotlib.pyplot as plt
import random

# Num of points
num = 100

# Create data points
xdata = np.linspace(-1,1,num)
ydata = 1/(1+25*xdata**2)

# Create measurements with noise
ymeas = np.zeros(num)
for i in range(num):
    ymeas[i] =ydata[i]+random.gauss(0,0.05)

# Polynomial fitting
degree = 15
fit = np.polyfit(xdata, ymeas,degree)
# poly1d is a one dimensional polynomial class
p = np.poly1d (fit)

plt.figure(1)
plt.plot(xdata, ydata)
plt.plot(xdata, ymeas, 'ro')
plt.plot(xdata,p(xdata), '--')
plt.show()