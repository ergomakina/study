#!/usr/bin/env python
# coding: utf-8

# In[52]:


import numpy as np
import pandas as pd


# In[53]:


csv_in = 'baseball_shop.csv'
df = pd.read_csv(csv_in, delimiter=',', skiprows=0, header=0)
print(df.shape)
print(df.info())
display(df.head())


# In[54]:


df2a=df['ShopID'].nunique()
df2b=df['Pref'].nunique()
df2c=df['Product'].nunique()
print(df2a)
print(df2b)
print(df2c)


# In[55]:


df3a=df['Pref'].value_counts()
df3b=df['Product'].value_counts()
print(df3a)
print(df3b)


# In[56]:


df['Product']=df['Product'].str.lower()


# In[57]:


df['Sales']=df['Price']*df['Amount']


# In[58]:


df6=df.drop(columns='Price')
df6=df6.groupby(['Pref','ShopID']).sum()
display(df6.head())


# In[59]:


df7=df6.groupby('Pref').mean()
display(df7.head())


# In[61]:


df7['Shops']=df['Pref'].value_counts()
display(df7.head())

