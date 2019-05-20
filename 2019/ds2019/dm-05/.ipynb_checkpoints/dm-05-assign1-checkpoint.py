#!/usr/bin/env python
# coding: utf-8

# ##### 1

# In[23]:


# 罹患率
affected_rate = 1 / 1000
# 非罹患率
unaffected_rate = 999 / 1000
# 罹患者の陽性or陰性確率
affected_positive_reliability = 95 / 100
affected_negative_reliability = 5 / 100
# 非罹患者の陽性or陰性確率
unaffected_positive_reliability = 10 / 100
unaffected_negative_reliability = 90 / 100


# 検査で陽性: A1
# 
# 検査で陰性: A2
# 
# 実際に罹患: B1
# 
# 実際に罹患じゃない: B2
# 
# P(B1|A1) = P(A1|B1)P(B1) / P(A1)
# 
#          = P(A1|B1)P(B1) / {P(A1|B1) P(B1) + P(A1|B2)P(B2) }
# 
# P(検査して罹患) = P(罹患者が検査して陽性)P(実際に罹患) / P(検査して陽性)
# 
#                = P(罹患者が検査して陽性)P(実際に罹患) / { P(罹患者が検査して罹患)P(罹患者) + P(非罹患者が検査して陽性)P(非罹患者) }

# In[24]:


result = affected_rate * affected_positive_reliability / ( affected_rate * affected_positive_reliability + unaffected_rate * unaffected_positive_reliability )
print('実際に罹患している確率:', result * 100,'%')


# ##### 2

# In[30]:


# 事前確率(罹患率)
pre_affected_rate = result
# 非罹患率
pre_unaffected_rate = 1 - result
# 陽性だった罹患者の陽性or陰性確率
re_affected_positive_reliability = 98 / 100
re_affected_negative_reliability = 2 / 100
# 陽性だった非罹患者の陽性or陰性確率
re_unaffected_positive_reliability = 5 / 100
re_unaffected_negative_reliability = 95 / 100


# 再検査して陽性: A
# 
# 1回目が陽性: B1
# 
# P(陽性が再検査して罹患) = 
# 
# P(A|B1) = P(B1|A)P(A)/ P(B1)

# In[31]:


result = pre_affected_rate * re_affected_positive_reliability / ( pre_affected_rate * re_affected_positive_reliability + pre_unaffected_rate * re_unaffected_positive_reliability )
print('実際に罹患している確率:', result * 100,'%')

