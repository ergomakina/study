#%% Change working directory from the workspace root to the ipynb file location. Turn this addition off with the DataScience.changeDirOnImportExport setting
import os
try:
	os.chdir(os.path.join(os.getcwd(), '2019\ds2019\dm-04'))
	print(os.getcwd())
except:
	pass

#%%
import numpy as np
import pandas as pd
import scipy.stats as ss


#%%
csv_in = 'shop_sales.csv'


#%%
df = pd.read_csv(csv_in, delimiter=',', skiprows=0, header=0)
print(df.shape)
display(df.head())
print(df.info())


#%%
t, p = ss.ttest_1samp(df['Sales2']-df['Sales1'], 0.0)
print(t, p/2)

#%% [markdown]
# (結論) セールの販売数は増加したと言えない

#%%
df_Tokyo = df[ df['Pref'] == 'Tokyo' ]
df_Saitama = df[ df['Pref'] == 'Saitama' ]
display(df_Tokyo.head())


#%%
t, p = ss.ttest_ind(df_Tokyo['Sales2'], df_Saitama['Sales2'], equal_var=False)
print(t, p)

#%% [markdown]
# (結論) 販売数の増加に地域差があるとはいえない。

