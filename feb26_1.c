/*Write a code simulating ARP /RARP protocols.
Devices communicate in a network simulation to resolve IP addresses to MAC addresses (ARP) or MAC 
addresses to IP addresses (RARP) using the address resolution protocol (ARP) and the reverse address 
resolution protocol (RARP). 
Here we are performing implementations of ARP and RARP protocols in C programming.
ARP Simulation (Address Resolution Protocol):- ARP is used to resolve IP addresses to MAC addresses on a 
local network.
Program Code*/
#include <stdio.h>
#include <string.h>
// Define a structure for ARP table entry
struct ARPEntry {
 char ip_address[16]; // IPv4 address in string format (xxx.xxx.xxx.xxx)
 char mac_address[18]; // MAC address in string format (xx:xx:xx:xx:xx:xx)
};
// Sample ARP table (can be expanded with more entries)
struct ARPEntry arp_table[] = {
 {"192.168.1.1", "00:11:22:33:44:55"},
 {"192.168.1.2", "11:22:33:44:55:66"},
 {"192.168.1.3", "22:33:44:55:66:77"},
 // Add more entries as needed
};
// Function to perform ARP resolution
void arp_resolve(const char* ip_address) {
 int i;
 int num_entry = sizeof(arp_table) / sizeof(struct ARPEntry);
int found = 0;
// Search the ARP table for the given IP address
 for (i = 0; i < num_entry; i++) {
 if (strcmp(arp_table[i].ip_address, ip_address) == 0) {
 printf("ARP=> IP Address %s -> MAC Address %s\n", ip_address, arp_table[i].mac_address);
 found = 1;
 break;
 }
 }
 if (!found) {
 printf("ARP=> IP Address %s is not found in ARP table\n", ip_address);
 }
}
int main() {
 // Simulating ARP requests
 arp_resolve("192.168.1.1");
 arp_resolve("192.168.1.2");
 arp_resolve("192.168.1.5"); // IP address not in ARP table
 return 0;
}
