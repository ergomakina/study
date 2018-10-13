#include <stdio.h>
#include <string.h>
#include <apr_hash.h>

#define MAX_KEY_LENGTH 512
#define MAX_VAL_LENGTH 512

static apr_pool_t *pool;
static apr_hash_t *hash;

main()
{
    //おまじない
    apr_initialize();
    apr_pool_create(&pool, NULL);
    hash = apr_hash_make(pool);

    //ハッシュに値をセット
    char *key, *val;
    int i;
    for (i = 0; i < 20; i++)
    {
        key = apr_palloc(pool, MAX_KEY_LENGTH);
        val = apr_palloc(pool, MAX_VAL_LENGTH);
        sprintf(key, "KEY_%d", i);
        sprintf(val, "VAL_%d", i);
        apr_hash_set(hash, key, APR_HASH_KEY_STRING, val);
    }

    //キーを指定して値を取り出す
    val = apr_hash_get(hash, key, APR_HASH_KEY_STRING);
    printf("key=%s, val=%s\n\n", key, val);

    //ハッシュに入っているキーと値をすべて取り出す
    apr_hash_index_t *hi;
    apr_ssize_t klen;
    for (hi = apr_hash_first(pool, hash); hi; hi = apr_hash_next(hi))
    {
        apr_hash_this(hi, (const void **)&key, &klen, (void **)&val);
        printf("key=%s, val=%s,  key_length=%d\n", key, val, (int)klen);
    }
}