#!/usr/bin/env python
# coding: utf-8

# ## Graph with Pandas

# ### Import libraries

# In[25]:


import pandas as pd


# ### Parameters

# In[26]:


csv_in1 = '../ai-0102/2045_2017-utf8.csv'


# ### Read CSV files

# In[27]:


df1 = pd.read_csv(csv_in1, delimiter=',', skiprows=9, header=0)
df1['Date']=pd.to_datetime(df1['Date'], format="%Y/%m/%d")
print(df1.shape)
print(df1.info())
display(df1.head())


# ### Add 25days moving average line  

# In[28]:


df1['25d_mov_ave'] = df1['AdjClose'].rolling(window=25).mean()
display(df1.head(30))


# ### Line plot  

# In[29]:


df1.plot.line('Date', ['AdjClose', '25d_mov_ave'])


# ### Scatter plot  

# In[30]:


df1.plot.scatter('High', 'Low')


# In[31]:


csv_in2 = '../ai-0102/1393_2017-utf8.csv'
df2 = pd.read_csv(csv_in2, delimiter=',', skiprows=9, header=0)
df2['Date'] = pd.to_datetime(df2['Date'], format="%Y/%m/%d")


# In[32]:


df1_2 = df1.drop(columns='25d_mov_ave')
df1_2['Date'] = pd.to_datetime(df1_2['Date'], format="%Y/%m/%d")
df12 = pd.merge(df1_2, df2, on='Date', how='inner')
display(df12)


# In[34]:


df12.plot.scatter('AdjClose_x','AdjClose_y')


# In[ ]:




