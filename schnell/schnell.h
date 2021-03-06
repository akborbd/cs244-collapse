#ifndef SCHNELL_H
#define SCHNELL_H

#include <pcap.h>

typedef u_int8_t u8;
typedef u_int16_t u16;
typedef u_int32_t u32;

extern int gotFINorRST;
extern int MSS;
volatile extern unsigned int victimSequence;
extern unsigned int localSequence;
extern unsigned long usRTT;
extern pcap_t * PcapHandle;
extern unsigned int Window;
extern unsigned long TargetBandwidth;
extern long LocalBandwidth;
extern double MaxNoise;
extern struct timeval StartTime;
extern int Verbose;
extern double Efficency;
extern int AdaptiveDelay;
extern int WindowMax;
extern double MaxNoise;
extern int AdaptiveDelay;
extern long DelayIncrement;
extern int SignalRestart;
extern char victimFQHN[];
extern char URL[];
extern int FileSize;
extern unsigned short victimPort;
extern unsigned short localPort;

#define MIN(x,y) (((x)<(y))?(x):(y))
#define MAX(x,y) (((x)>(y))?(x):(y))


// ripped from nmap
typedef struct pseudohdr {
/*for computing TCP checksum, see TCP/IP Illustrated p. 145 */
	u32 s_addr;
	u32 d_addr;
	u8 zero;
	u8 proto;
	u16 length;
} pseudohdr;


#define BUFLEN 4096
#define MYSNAPLEN 256

void parseArgs(int, char *[]);
int sendSYN(int);
int sendACK(int);
int ACK(int,unsigned int);
int getSYNACK(int);
int sendHTMLGET(int);
unsigned int getLocalIP();
unsigned short checksum(unsigned char *,int);
unsigned short in_cksum(u16 *ptr,int nbytes) ;
u16 tcp_sum_calc(u16 len_tcp, u16 src_addr[],u16 dest_addr[],
		                int padding, u16 buff[]);
void usage(char *,char *);
void broadcast_socket(int sd) ;
void * packetGrabber2(void *);
void * packetGrabber3(void *);
void * packetGrabber5(void *);
void heartbeat(char *);

int do_fast_resend_attack(int );
int do_schnell_attack(int );
int do_schnell2_attack(int );
int do_schnell3_attack(int );
int do_schnell4_attack(int );
int do_schnell5_attack(int );
int do_schnell6_attack(int );
int do_schnell7_attack(int );
int do_schnell8_attack(int );
int do_schnell9_attack(int );

int myusSleep(int us);

void packetHandler(unsigned char *user, const struct pcap_pkthdr * pcap_hdr,
		const unsigned char * packet);

pcap_t * init_pcap();



#endif
