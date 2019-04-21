import sys, requests

def main(argv):
    # このコードは引数と標準出力を用いたサンプルコードです。
    # このコードは好きなように編集・削除してもらって構いません。
    # ---
    # This is a sample code to use arguments and outputs.
    # Edit and remove this code as you like.
    query = argv[0]
    response = requests.get(
        'http://challenge-server.code-check.io/api/hash',
        params={'q': query})
    hash_data = response.json()
    print(hash_data['hash'])

if __name__ == '__main__':
    main(sys.argv[1:])
