#!/usr/bin/env python
# coding: utf-8

# f(x,y) = 10 + (1.5 - x + x*y)^2 + (2.25 - x + x*y^2)^2
#         + (2.625 - x + x*y^3)^2

# In[3]:


import numpy as np
import pandas as pd
from random import uniform
from scipy.optimize import dual_annealing
import matplotlib.pyplot as plt


# In[11]:


def func(tmp):
    x = tmp[0]
    y = tmp[1]
    result = 10 + (1.5 - x + x*y)**2 + (2.25 - x + x*y**2)**2 + (2.625 - x + x*y**3)**2
    return result


# In[12]:


bounds = [(-30.0, 32.0), (-31.0, 30.0)]


# In[13]:


n_trial = 3


# In[14]:


x = np.zeros(2)
for i in range(n_trial):
    # Initial value
    x[0] = uniform(-30.0, 32.0)
    x[1] = uniform(-31.0, 31.0)
    print(x)  # debug
    
    # Dual annealing optimization
    ret = dual_annealing(func, bounds, x0=x, maxiter=500)
    print('x:', ret.x)
    print('f(x):', ret.fun)

