/*RARP Simulation (Reverse Address Resolution Protocol): RARP is used to resolve MAC addresses 
to IP addresses.
Program Code*/
#include <stdio.h>
#include <string.h>
// Structure of RARP table entry
struct RARPEntry {
 char mac_address[18]; // MAC address
 char ip_address[16]; // IPv4 address
};
// RARP table
struct RARPEntry rarp_table[] = {
 {"00:11:22:33:44:55", "192.168.1.1"},
 {"11:22:33:44:55:66", "192.168.1.2"},
 {"22:33:44:55:66:77", "192.168.1.3"},
 
};
// Function to perform RARP resolution
void rarp_resolve(const char* mac_address) {
 int i;
 int num_entry = sizeof(rarp_table) / sizeof(struct RARPEntry);
 int found = 0;
 // Search the RARP table for the given MAC address
 for (i = 0; i < num_entry; i++) {
 if (strcmp(rarp_table[i].mac_address, mac_address) == 0) {
 printf("RARP=> MAC Address %s -> IP Address %s\n", mac_address, rarp_table[i].ip_address);
 found = 1;
break;
 }
 }
 if (!found) {
 printf("RARP=> MAC Address %s is not exist in RARP table\n", mac_address);
 }
}
int main() {
 // RARP requests
 rarp_resolve("00:11:22:33:44:55");
 rarp_resolve("11:22:33:44:55:66");
 rarp_resolve("00:00:00:00:00:00"); // MAC address not in RARP table
 return 0;
}
