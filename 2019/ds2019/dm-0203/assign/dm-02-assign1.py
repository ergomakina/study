#!/usr/bin/env python
# coding: utf-8

# In[2]:


import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from pandas.plotting import register_matplotlib_converters
register_matplotlib_converters()


# In[3]:


csv_in = '../ai-0102/pandas_training-utf8.csv'
df = pd.read_csv(csv_in, delimiter=',', skiprows=13, header=0 )
print(df.shape)
print(df.info())
display(df.head())


# In[4]:


df2 = df[df['FRESH']>=3000]
print(df2.shape)
print(df2.info())
display(df2.head())


# In[6]:


df2_num = df2.loc[:,'FRESH':]
plt.boxplot(np.array(df2_num))
plt.xticks(range(1, df2_num.shape[1]+1), df2_num.columns)
plt.xlabel('categories')
plt.ylabel('cnnual spending')
plt.show()


# In[7]:


df2_ave = df2.mean()
plt.bar(df2_ave.index, df2_ave, label='average')
plt.xlabel('categories')
plt.ylabel('annual spending (m.u.)')
plt.xticks(rotation=90)
plt.legend()
plt.show()


# In[ ]:




