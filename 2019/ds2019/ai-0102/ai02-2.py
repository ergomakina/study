#!/usr/bin/env python
# coding: utf-8

# In[1]:


import numpy as np
import pandas as pd


# In[6]:


csv_in = '1393_2017-utf8.csv'
csv_in2 = '2045_2017-utf8.csv'
df = pd.read_csv(csv_in,delimiter=',',skiprows=9, header=0)
df1 = pd.read_csv(csv_in2,delimiter=',',skiprows=9, header=0)


# In[7]:


print(df.shape)
display(df.head())
print(df1.shape)
display(df1.head())


# In[10]:


df2 = pd.merge(df,df1,on='Date',how='inner')
display(df2.head())


# In[12]:


corr3=df2['High_x'].corr(df2['High_y'])
print(corr3)

