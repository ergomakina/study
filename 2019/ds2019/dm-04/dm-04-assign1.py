#!/usr/bin/env python
# coding: utf-8

# In[6]:


import numpy as np
import pandas as pd
import scipy.stats as ss


# In[7]:


csv_in = 'shop_sales.csv'


# In[8]:


df = pd.read_csv(csv_in, delimiter=',', skiprows=0, header=0)
print(df.shape)
display(df.head())
print(df.info())


# In[15]:


t, p = ss.ttest_1samp(df['Sales2']-df['Sales1'], 0.0)
print(t, p/2)


# (結論) セールの販売数は増加したと言えない

# In[19]:


df_Tokyo = df[ df['Pref'] == 'Tokyo' ]
df_Saitama = df[ df['Pref'] == 'Saitama' ]
display(df_Tokyo.head())


# In[21]:


t, p = ss.ttest_ind(df_Tokyo['Sales2'], df_Saitama['Sales2'], equal_var=False)
print(t, p)


# (結論) 販売数の増加に地域差があるとはいえない。
