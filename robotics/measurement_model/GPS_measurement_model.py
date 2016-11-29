""" 2D GPS Measurement Model Class
    Input: Covariance Matrix, needs to be square
    
    @todo: Should extend to 3D

"""
import numpy as np
from numpy import linalg as LA

class GPSMeasurement:
    
    def __init__(self, cov):
        self.__cov = cov # covariance matrix
        
    def get_measurement(self, pos, add_noise):
        """ 
            Inputs:
                pos: position, should be a n x 1 vector
                add_noise: if true, add guassian noise specified by covariance
                           matrix        
            Return:
            returns a position measurement with the option of additive noise
            in n x 1 vector
        """
        
        """ Rv: Eigen value; RV: Eigen Vector """
        Rv, RV = LA.eig(self.__cov)
        
        """ noise is a n x 1 vector"""
        numrows = len(RV)
        noise = (RV*np.sqrt(Rv)).dot(np.random.rand(numrows,1)*2-1).flatten()
        if add_noise:
            pos = pos + noise
        
        return pos
            
        