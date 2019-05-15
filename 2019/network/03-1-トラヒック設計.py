# 1
# 単位時間当たりのパケット数：1000[pps]
# 平均パケット長：500[bytes]
# リンク容量：5[Mbps]
# λ = 1000 = 平均トラヒック量[bps] / 8 * 500[bytes]
# 1/μ = 平均サービス時間[s] = 8 * 500[bytes] / 5000000[bps]
s = 8 * 500 / 5000000
print('平均サービス時間[s]=',s)
print('μ=', 1/s)