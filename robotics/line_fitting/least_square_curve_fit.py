# Curve fitting with non-linear least square method
# Note: Must know the fitting function in advance
# Reference: https://docs.scipy.org/doc/scipy/reference/generated/scipy.optimize.curve_fit.html

import numpy as np
from scipy.optimize import curve_fit

# Assumes ydata = f(xdata, *params) + eps
# Num of points
num = 100

# Create data points
xdata = np.linspace(-1,1,num)
ydata = 1/(1+25*xdata**2) + + 0.2 * np.random.normal(size=len(xdata))

def func(x, a, b):
    return 1/(a+b*x**2)

popt, pcov = curve_fit(func, xdata, ydata)
# Optimal values for the parameters
print popt
# Estimated covariance of popt
print pcov