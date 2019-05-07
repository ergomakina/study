#!/usr/bin/env python
# coding: utf-8

# In[1]:


import json
import pandas as pd
import folium


# In[2]:


csv_in = 'crime2006_2016-utf8.csv'
html_out = 'crime2006_2016-utf8.html'
geo = 'japan.json'
csv_pref = 'pref_roman-utf8.csv'

pd.options.display.max_rows = 999
pd.options.display.max_columns = 999


# In[7]:


df_pop = pd.read_csv(csv_in,delimiter=',',skiprows=0,header=0)
df_pref = pd.read_csv(csv_pref,delimiter=',',skiprows=0,header=0)
df_merged = pd.merge(df_pop,df_pref,on='都道府県',how='left')
display(df_merged.head())


# In[9]:


print(df_merged.loc[df_merged['検挙人数'].idxmin()])
print(df_merged.loc[df_merged['検挙人数'].idxmax()])


# In[12]:


csv_in2 = 'h3010pref_pos_utf8.csv'
df_pos = pd.read_csv(csv_in2, delimiter=',', skiprows=0, header=0)
df_merged2 = pd.merge(df_merged, df_pos, left_on='都道府県', right_on='name', how='left')
print(df_merged2.shape)
display(df_merged2.head())


# In[13]:


df_heat = df_merged2[['lat', 'lon', '検挙人数']]
print(df_heat.shape)
display(df_heat.head())


# In[14]:


ar_heat = []
for i,r in df_heat.iterrows():
    ar_heat.append(r)
print(ar_heat[:3])


# In[29]:


from folium.plugins import HeatMap
import branca.colormap as cm

m = folium.Map(location=[38, 140], zoom_start=4)
m.add_child(HeatMap(ar_heat, radius=9,
                    gradient={0:'blue', 0.5:'lime', 1:'red'}))

min = df_heat['検挙人数'].min()
max = df_heat['検挙人数'].max()
colors = ['blue', 'lime', 'red']
colormap = cm.LinearColormap(colors, vmin=min, vmax=max).to_step(10000)
colormap.caption = '検挙人数'
m.add_child(colormap)

display(m)
m.save(outfile='dm-03-assign2.html')

