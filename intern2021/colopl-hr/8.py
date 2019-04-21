import sys, hashlib, pickle

def main(argv):
    # このコードは引数と標準出力を用いたサンプルコードです。
    # このコードは好きなように編集・削除してもらって構いません。
    # ---
    # This is a sample code to use arguments and outputs.
    # Edit and remove this code as you like.

    a, b, c = [int(i) for i in argv] #リスト内の文字列をintに変換

    result = rec(a,b,c)
    print(result)
    hash_key = hash(a,b,c)
    if hash_key not in memo:
      add_memo(hash_key,result)

def rec(x,y,z): # n,n-1,n-2のときエラー
    hash_key = hash(x,y,z)
    if hash_key in memo: # 計算済みならそれを返す
        return memo[hash_key]
    else:
        if x <= y:
            add_memo(hash_key,y)
            return y
        else:
            rec(
                rec(x - 1, y, z),
                rec(y - 1, z, x),
                rec(z - 1, x, y)
            )

def hash(x,y,z): #ハッシュ化してキーに使う
    # plain = str(x) + ',' + str(y) + ',' + str(z)
    plain = str(x) + ',' + str(y)
    return hashlib.md5(plain.encode()).hexdigest()

def add_memo(hash_key,y): #メモに追加する
    if y >= 0:
      memo[hash_key] = y

if __name__ == '__main__':
    # 保存したデータの読み込み
    try:
        with open('memo.text', 'rb') as handle:
            memo = pickle.load(handle)
    except:
        memo = {}

    
    main(sys.argv[1:])

    # 計算結果の保存
    with open('memo.text', 'wb') as handle:
        pickle.dump(memo, handle, protocol=pickle.HIGHEST_PROTOCOL)