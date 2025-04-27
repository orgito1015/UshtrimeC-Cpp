#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>
#include <signal.h>

pcap_t *handle = NULL;

void sigintHandler(int sig_num) {
    printf("\nStopping network capture...\n");
    pcap_breakloop(handle);
}

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet) {
    struct ip *ip_header = (struct ip*)(packet + 14);
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];

    inet_ntop(AF_INET, &(ip_header->ip_src), src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(ip_header->ip_dst), dst_ip, INET_ADDRSTRLEN);

    struct tcphdr *tcp_header = (struct tcphdr*)(packet + 14 + (ip_header->ip_hl * 4));
    
    printf("Packet: %s:%d -> %s:%d | Protocol: %d | Size: %d bytes\n",
           src_ip, ntohs(tcp_header->source),
           dst_ip, ntohs(tcp_header->dest),
           ip_header->ip_p, header->len);
}

int main(int argc, char *argv[]) {
    pcap_if_t *alldevs;
    char errbuf[PCAP_ERRBUF_SIZE];

    // Find all network interfaces
    if(pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error finding devices: %s\n", errbuf);
        exit(1);
    }

    // Open the first interface
    handle = pcap_open_live(alldevs->name, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Error opening device: %s\n", errbuf);
        pcap_freealldevs(alldevs);
        return 1;
    }

    printf("Monitoring network traffic on device: %s\n", alldevs->name);

    // Register CTRL+C handler
    signal(SIGINT, sigintHandler);

    // Start continuous packet capture
    pcap_loop(handle, -1, packet_handler, NULL);

    // Cleanup
    pcap_close(handle);
    pcap_freealldevs(alldevs);

    return 0;
}
