## Intel

### ®

## Ethernet Controller I

##### Specification Update, Revision 1. 2

##### Intel Corporation

###### November 2020


#### Revision History

```
Revision Date Comments
```
**1. 2 November 2 2 , 2020 Update I225 Part Identification Summary for I225V**

```
1.1 November 2nd, 2020 Update I225 Part Identification Summary
```
```
1.0 March 27th, 2020 Initial Release
```

### 1. Introduction

```
This document applies to the Intel® Ethernet Controller I225. It covers product level details, and an
erratum related to IEEE behavior in 2.5Gbps mode.
```
#### 1.1 Product Code and Device Identification

```
Product Codes: I225.
```
```
The following tables and drawings describe the various identifying markings on each device package:
```
```
Table 1 - 1 I225 Part Identification Summary
```
```
Part # Version Intel MM # Spec Code Type Network Driver Branding String^
I225-LM V1 999JW1 SLN9B T&R Intel(R) Ethernet Controller I225-LM^
I225-LM V1 999JW0 SLN9A Tray Intel(R) Ethernet Controller I225-LM
I225-V V1 999JW7 SLN9D T&R Intel(R) Ethernet Controller I225-V^
I225-V V1 999JW5 SLN9C Tray Intel(R) Ethernet Controller I225-V^
I225-LM V2 99A1TL SLNJW T&R Intel(R) Ethernet Controller (2) I225-LM
I225-LM V2 99A1T7 SLNJV Tray Intel(R) Ethernet Controller (2) I225-LM^
I225-V V2 99A1VF SLNJY T&R Intel(R) Ethernet Controller (2) I225-V^
I225-V V2 99A1V1 SLNJX Tray Intel(R) Ethernet Controller (2) I225-V
I225-LM V3 99A57P SLNNJ T&R Intel(R) Ethernet Controller (^3 ) I225-LM^
I225-LM V3 99A57N SLNNH Tray Intel(R) Ethernet Controller ( 3 ) I225-LM
I225-V V3 99A3W6 SLNMH T&R Intel(R) Ethernet Controller ( 3 ) I225-V
I225-V V3^ 99A3W5 SLMNG Tray Intel(R) Ethernet Controller (^3 ) I225-V^
I225-IT V3 99A57T SLNNL T&R Intel(R) Ethernet Controller (3) I225-IT
I225-IT V3 99A57R SLNNK Tray Intel(R) Ethernet Controller (3) I225-IT
```
Figure 1- 1 shows a snapshot of the I225 device:

```
Figure 1 - 1 Snapshot of I
```

#### 1.2 Marking Diagrams

**Figure 1 - 2 I225 Marking Pattern**

**Notes:**

- LINE1: Logo - Intel Swirl Logo
- LINE2: FPO# - Assembly lot marking, 8 characters
- LINE3: Spec#
- LINE4: e# - Pb-free symbol
- LINES OF TEXT ARE CENTERED ON THE PACKAGE AND LEFT JUSTIFIED
- Zero should have a slash ”/” in the middle.
    -^ Pb-^ free symbols


### 2. Erratum

#### 2.1 I225 v1 Minimum Supported Receive Inter-Packet

#### Gap (IPG) is 8 bytes instead of 5 bytes

Problem Summary:

The minimum received inter packet gap (IPG) in the GMII interface between the PHY and the MAC is 8
bytes. This minimum gap is specified through 1 Gpbs operation. For a controller to operate at 2.5Gpbs,
the IEEE standard requires that the MAC be able to tolerate a minimum IPG of 5 bytes.

The I225 v1 silicon supports an IPG down to 8 bytes, but not down to 5 bytes in 2.5Gpbs operation.

Implications:

Packets received by the I225 v1 product link partner (the switch, router, or back-to-back
controller it is connected to) that are received with a smaller IPG than 8 bytes on the MAC/PHY
interface are dropped. When this occurs, the network connectivity is reduced from 2.5Gpbs to
below 1Gpbs operation. In some scenarios with certain link partners, the operation can be as
low as 1-10Mbps.

Workaround:

The impact of this IPG issue can be mitigated when connected through a switch/router by setting the
link speed in the driver (Windows or Linux) to 1Gpbs operation to enable a 1 Gpbs line rate.

Also, the latest Windows drivers and I225 firmware available for download (driver version 1.0.0.30 or
later NVM version 1.38 or later) can detect when the IPG packet drops occur and will automatically
reset the link speed to 1Gpbs. Please see downloads here:
https://downloadcenter.intel.com/product/184686/intel-ethernet-controller-i225-series

Known Compatible 2.5Gpbs Link Partners:

Below is a list of link partners with which Intel has tested I225 v1 to enable 2.5Gpbs operation.

```
Brand* 2.5Gbps Router/Switch or Controller Model(s)
Aruba 2930m, 3810m (Switches)
Asus Rapture GT-AX11000 (Router)
Buffalo BS-MP2012, BS-MP2008 (Switches)
Cisco Catalyst 3850-24XU & 9300-24X UPOE (Switches)
D-Link DMS- 1100 - 10TP (Switches)
Huawei S6720-32C-SI (Switches)
Netgear Nighthawk AX12/RAX120 (Router)
Trendnet TEG-7080ES, TEG-30102WS (Switches)
```
Status:

Intel has resolved this issue with I225 v2, which is now in production.


# LEGAL

No license (express or implied, by estoppel or otherwise) to any intellectual property rights is granted
by this document.

Intel disclaims all express and implied warranties, including without limitation, the implied warranties of
merchantability, fitness for a particular purpose, and non-infringement, as well as any warranty arising
from course of performance, course of dealing, or usage in trade.

This document contains information on products, services and/or processes in development. All
information provided here is subject to change without notice. Contact your Intel representative to
obtain the latest forecast, schedule, specifications and roadmaps.

The products and services described might contain defects or errors which might cause deviations from
published specifications. No product or component can be absolutely secure.

Software and workloads used in performance tests may have been optimized for performance only on
Intel microprocessors. Performance tests, such as SYSmark and MobileMark, are measured using
specific computer systems, components, software, operations and functions. Any change to any of
those factors may cause the results to vary. You should consult other information and performance
tests to assist you in fully evaluating your contemplated purchases, including the performance of that
product when combined with other products. For more complete information visit
[http://www.intel.com/benchmarks.](http://www.intel.com/benchmarks.)

Copies of documents which have an order number and are referenced in this document might be
obtained by calling 1 - 800 - 548 - 4725 or by visiting [http://www.intel.com/design/literature.htm.](http://www.intel.com/design/literature.htm.)

Intel and the Intel logo are trademarks of Intel Corporation in the U.S. and/or other countries.

* Other names and brands might be claimed as the property of others.

© Intel Corporation.


