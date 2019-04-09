#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float per_hop_delay(float proc_delay, float queue_delay, float link_distance, float propagation_speed, float pkt_len, float transmission_rate)
{
    float transmission_dalay;
    float propagation_delay;
    transmission_dalay = pkt_len / transmission_rate;      //伝送遅延
    propagation_delay = link_distance / propagation_speed; //伝播遅延
    return proc_delay + queue_delay + propagation_delay + transmission_dalay;
}

void main(int argc, char *argv[])
{
    float proc_delay = atoi(argv[1]);
    float queue_delay = atoi(argv[2]);
    float link_distance = atoi(argv[3]);
    float propagation_speed = atoi(argv[4]);
    float pkt_len = atoi(argv[5]);
    float transmission_rate = atoi(argv[6]);
    printf("per_hop_delay= %f ms\n", per_hop_delay(proc_delay, queue_delay, link_distance, propagation_speed, pkt_len, transmission_rate));
}

// 処理遅延 （Processing delay） = 0.1 ms
// 渋滞遅延 （Queueing delay）= 20 ms
// リンクの距離（Link distance）= 200 km
// リンクの伝播スピード（Propagation speed）= 3・10 ＾ 8 m/s
// パケットサイズ（Packet size） = 1500 bytes
// 10 Mbps Ethernet Link (リンクの伝送速度（Transmission rate）= 100 Mbps)
// > ./a.out 0.1 20 1000000 300000000 1500 10000000
// > ./a.out 0.1 1 300000 300000000 1500 10000000
// per_hop_delay= 20.003485 ms