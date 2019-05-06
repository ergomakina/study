import numpy as np
import pandas as pd
import scipy.stats as ss

csv_in = 'network020-2.csv'

df = pd.read_csv(csv_in, delimiter=',', skiprows=0, header=0)
print(df.shape)
print(df.head())
print(df.info())

df2 = df[['Destination']]
print(df2['Destination'].value_counts())