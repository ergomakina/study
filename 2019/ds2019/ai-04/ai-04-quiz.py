#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
import scipy.stats as ss
import matplotlib.pyplot as plt


# In[2]:


csv_in = '../ai-03/running.csv'


# In[11]:


df = pd.read_csv(csv_in,delimiter=',',skiprows=0,header=0)
display(df.head())
display(df.info())


# In[14]:


df2 = df.dropna(how='any')
display(df2.head())


# In[16]:


ct = pd.crosstab(index=df2['Univ'],columns=df2['Grade'])
display(ct.head())


# In[ ]:




