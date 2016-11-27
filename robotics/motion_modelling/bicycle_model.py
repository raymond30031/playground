### Bicycle model

import numpy as np
from numpy import linalg as LA
import matplotlib.pyplot as plt

## time
dt = 0.1
Tf = 20
t = np.linspace(0,Tf,Tf/dt)

## Robot parameters
L = 0.3
str_max = np.radians(30)
str_min = np.radians(-30)

# Motion model disturbances
# Std deviation: x: 0.02 m; y: 0.02 m; theta: 1 deg
R = np.array([[0.02**2,       0,                0],
              [0,       0.02**2,                0],
              [0,             0, np.radians(1)**2]])

Rv, RV = LA.eig(R) # Rv: Eigen value; RV: Eigen Vector

def get_disturbance():
    # returns a disturbance vector with random number ranging from -1 to 1
    return (RV*np.sqrt(Rv)).dot(np.random.rand(3,1)*2-1).flatten()
    
def motion_model(x_tm1, u):
    # inputs:
    # x_tm1: states (x,y,theta) at t minus 1
    # u: input (velocity_cmd, str_angle) at t
    # returns a vector that represents B*u
    
    B = u[0]*np.array([np.cos(x_tm1[2]),
                       np.sin(x_tm1[2]),
                       np.tan(u[1])/L])
    
    x = x_tm1 + B*dt + get_disturbance()
    return x

## Simulation Initialization

# input
u = np.zeros((1,2)) #[m/s, rad]

# generates steering input
for i in range(1,len(t)):
    #print i
    u_new = np.array([3.0, np.radians(10-t[i])])
    # steering saturation
    if  u_new[1] > str_max:
        u_new[1] = str_max
    elif  u_new[1] < str_min:
        u_new[1] = str_min
    u = np.vstack((u,u_new))

# initial state
x_tm1 = np.zeros(3)
x_data = x_tm1 # for plotting

# Loop
# Note: time starts at 1 not 0
for i in range(1,len(t)):
    x = motion_model(x_tm1, u[i])
    x_data = np.vstack((x_data,x))
    x_tm1 = x

## Plotting
plt.figure(1)
plt.plot(x_data[:,0], x_data[:,1], 'ro')
plt.show()