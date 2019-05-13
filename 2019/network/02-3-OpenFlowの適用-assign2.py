# global_ipaddr = '172.16.1.0/24'

released_ipaddr = ['172.16.1.1'~'172.16.1.124']
using_addr = {}

while True:
    client = input()
    if using_addr[client]:
        clt_ipaddr = using_addr[client].clt_ipaddr
        using_addr[client].lst_time = time.time()
    else:
        clt_ipaddr = released_ipaddr.pop(0)
        using_addr[client].clt_ipaddr = clt_ipaddr
        using_addr[client].lst_time = time.time()
    # パケット処理- start
    # パケット処理- end


while True:
    for i in using_addr:
        if i.lst_time - time.time() > T_inactive:
            rm_obj = using_addr.pop(i)
            released_ipaddr.append(rm_obj.clt_ipaddr)