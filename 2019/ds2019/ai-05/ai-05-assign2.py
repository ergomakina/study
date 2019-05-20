#!/usr/bin/env python
# coding: utf-8

# In[6]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


# In[7]:


csv_in = 'vibration.csv'


# In[8]:


df = pd.read_csv(csv_in, delimiter=',', skiprows=0, header=0)
print(df.shape)
print(df.info())
print(df.head())


# In[41]:


X = df['x']
Y = df['y']
plt.plot(X, Y)
plt.xlabel('X')
plt.ylabel('Y')
plt.show()


# In[69]:


def f(x,a,b,c):
    # f(x) = a * e ^ b*x * sin(2 * pi * x + c)
    return a * np.exp(b * x) * np.sin(2 * np.pi * x * c)


# In[89]:


dt=0.01
X2 = np.arange(-1.5, 1.5, dt)
a = -1.5
b = 1
c = -1.1
Y2 = [f(i,a,b,c) for i in X2]
plt.plot(X2, Y2)
plt.xlabel('X')
plt.ylabel('f(X)')
plt.show()


# In[ ]:




