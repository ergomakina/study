#!/usr/bin/env python
# coding: utf-8

# dm-03-assign1.ipynb
# Import libraries

# In[8]:


import json
import pandas as pd
import folium


# Parameters

# In[15]:


csv_in = 'crime2006_2016-utf8.csv'
html_out = 'crime2006_2016-utf8.html'
geo = 'japan.json'
csv_pref = 'pref_roman-utf8.csv'

pd.options.display.max_rows = 999
pd.options.display.max_columns = 999


# In[19]:


df_pop = pd.read_csv(csv_in,delimiter=',',skiprows=0,header=0)
print(df_pop.shape)
display(df_pop.head())
print(df_pop.info())


# In[23]:


df_pref = pd.read_csv(csv_pref,delimiter=',',skiprows=0,header=0)
print(df_pref.shape)
display(df_pref.head())


# In[24]:


df_merged = pd.merge(df_pop,df_pref,on='都道府県',how='left')
display(df_merged.head())


# In[21]:


m = folium.Map(location=[38,135],zoom_start=5)
#display(m)


# In[26]:


folium.Choropleth(geo_data=geo,key_on='feature.properties.name',data=df_merged,columns=['Roman','検挙人数'],
                 fill_color='BuPu',legend_name='Crimed Area').add_to(m)
display(m)


# In[27]:


m.save(outfile=html_out)

