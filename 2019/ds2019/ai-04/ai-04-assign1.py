#!/usr/bin/env python
# coding: utf-8

# In[2]:


import pandas as pd
import numpy as np
import scipy.stats as ss
import matplotlib.pyplot as plt

from pandas.plotting import scatter_matrix
import statsmodels.api as sm


# In[3]:


csv_in = 'winequality-red_modified-utf8.txt'


# In[5]:


df = pd.read_csv(csv_in,delimiter='  ',skiprows=13,header=0,engine='python')
#print(df.info)
df2 = df.dropna(axis=0).reset_index(drop=True)
#print(df2.info)
#display(df2.head())


# In[6]:


X_all_org = df2.loc[:, 'fixed_acidity':'alcohol']  # explanatory variables
y = df2['quality']  # objective variable
print('X_all_org:', X_all_org.shape)
display(X_all_org.head())
print('y:', y.shape)
print(y.head())


# In[7]:


X_all = pd.get_dummies(X_all_org, drop_first=True)
print('X_all:', X_all.shape)
display(X_all.head())


# In[8]:


corr_all = df2.corr(method='pearson')
display(corr_all)


# In[9]:


X_all_c = sm.add_constant(X_all)
model = sm.OLS(y, X_all_c)
results = model.fit()
print(results.summary())


# In[10]:


print('R2:', results.rsquared)#決定係数
print('Adj R2:', results.rsquared_adj)


# In[17]:


from sklearn import preprocessing
X_scaled = preprocessing.scale(X_all)
y_scaled = preprocessing.scale(y)
model = sm.OLS(y_scaled, X_scaled)
results = model.fit()
print(results.summary())


# In[23]:


import sys
my_libs_dir = '../'
if not my_libs_dir in sys.path:
    sys.path.append(my_libs_dir)  # add the path to my_lib directory 

# The following lines are needed to auto-reload my library file
# Without these lines, my library file is read only once and
# modifications of my library file are not reflected.
get_ipython().run_line_magic('load_ext', 'autoreload')
get_ipython().run_line_magic('autoreload', '1')
get_ipython().run_line_magic('aimport', 'my_libs.linear_reg')
# import from my library file
from my_libs.linear_reg import step_aic_forward, calc_vifs


# In[25]:


import statsmodels.formula.api as smf
dfX_scaled = pd.DataFrame(X_scaled, columns=X_all.columns)
dfy_scaled = pd.Series(y_scaled, name=y.name)
exog = list(dfX_scaled.columns)  # Initial set = all explanatory variables
endog = [dfy_scaled.name]  # Objective variables
df_scaled = pd.concat([dfX_scaled, dfy_scaled], axis=1)

results_aic=step_aic_forward(smf.ols, exog, endog, data=df_scaled)#変数増加法変数選択

print(results_aic.aic)
print(results_aic.model.exog_names)
print(results_aic.model.endog_names)


# In[26]:


endogs = results_aic.model.endog_names
exogs = results_aic.model.exog_names.copy()
exogs.remove('Intercept')
print(exogs)  # debug
X_c = sm.add_constant(X_all[exogs])
vifs = calc_vifs(X_c, y)
display(vifs)


# In[28]:


X_final_scaled = dfX_scaled[exogs]
model_final_scaled = sm.OLS(y_scaled, X_final_scaled)
results_final_scaled = model_final_scaled.fit()
print(results_final_scaled.summary())


# In[29]:


print(results_final_scaled.params)


# In[30]:


X_final_c = sm.add_constant(X_all[exogs])
model_final = sm.OLS(y, X_final_c)
results_final = model_final.fit()
print(results_final.summary())


# In[31]:


print('R2:', results_final.rsquared)#最終 決定係数
print('Adj R2:', results_final.rsquared_adj)#自由度調整済み


# In[33]:


print(results_final.params)


# quality ~ 4.426 + 0.289401 * alcohol + 0.884003 * sulphates + 0.005091 * free_sulfur_dioxide + (-1.009819) * volatile_acidity + (-0.003487) * total_sulfur_dioxide + (-2.01832) * chlorides + (-0.482495) * pH
