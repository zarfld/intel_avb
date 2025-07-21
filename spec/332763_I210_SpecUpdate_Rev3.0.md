## Revision 3.

# Intel

## ®

# Ethernet Controller I

## Specification Update

## Ethernet Products Group (EPG)

## January 2022


```
Revision History
```
#### Revision History

```
Revision Date Comments
3.0 January 25, 202 2 Miscellaneous Updates
```
- Updated Table 1-3, “MM Numbers”.
2.9 November 17, 2020 **Software Clarifications added or updated:**
- 1. While in TCP Segmentation Offload, Each Buffer is Limited to 64 KB (Updated)
2.8 June 2, 2020 **Errata added or updated:**
- 39. PCIe: Premature Timeout in LTSSM Configuration State (Added)
2.7 January 17, 2020 **Specification Clarifications added or updated:**
- 8. PCIe Separate Reference Clock with Independent Spread (SRIS) Support (Added)
**Errata added or updated:**
- 38. Device ID and MAC Address Cannot be Changed (Added)
**Miscellaneous Updates**
- Updated Table 1-3, “MM Numbers”.
2.6 April 25, 2019 **Errata added or updated:**
- 37. I210 Occasional Malfunction of Wake on LAN/Wake on Link when Transitioning from
S4 on Windows 10 (Added)
2.5 June 20, 2018 **Miscellaneous Updates**
- Updated Table 1-1, “Markings”.
2.4 January 8, 2018 **Miscellaneous Updates**
- Updated Table 1-1, “Markings”.
- Updated Table 1-2, “Device IDs”.
- Updated Table 1-3, “MM Numbers”.
- Added Figure 1-6, “I210 Production Top Marking Example (Automotive Industrial
Temperature Fiber <20 DPM)”.
- Removed documentation updates from Table 2-3 and Section 2.3. All changes are
incorporated in the latest revision of the _Intel® Ethernet Controller I210 Datasheet_.
2.3 May 9, 2017 **Miscellaneous Updates**
- Updated Table 1-3, “MM Numbers”.
2.2 April 28, 2017 **Errata added or updated:**
- 36. Internal Clock Malfunction (Added)
**Miscellaneous Updates**
- Updated Table 1-1, “Markings”.
- Added Section 1.1.1, “Identifying the A3 Stepping”.
2.1 December 1, 2016 **Errata added or updated:**
- 35. NC-SI Get Link Status Command Not Supported when Using SGMII (Added)
2.0 July 15, 2016 **Errata added or updated:**
- 34. PCIe Throughput with Few Credits (Added)
**Miscellaneous Updates**
- Updated erroneous Device ID numbers in Table 1-2, “Device IDs”.
- Updated Table 1-2, “Device IDs” to include footnote on Device ID 0x1538.
1.9 June 15, 2016 **Errata added or updated:**
- 33. PCIe Advanced Error Reporting: First Error Pointer (Added)
**Miscellaneous Updates**
- Updated Table 1-2, “Device IDs”.
- Updated Figure 1-3, “I210 Production Top Marking Example (Industrial Temperature
Copper)”
1.8 August 24, 2015 **Errata added or updated:**
- 31. Certain Malformed IPv6 Extension Headers are Not Processed Correctly by the
Device (Added)
- 32. NC-SI Output Signals Have Indeterminate Value After Power Up (Added)


**_Revision History_**

```
1.7 July 1, 2015 Specification Clarifications added or updated:
```
- 7. WGI210CS Automotive Industrial Temperature Fiber Schematic (Added)
**Miscellaneous Updates**
- Added automotive industrial temperature fiber product information (WGI210CS).
1.6 April 1, 2015 **Miscellaneous Updates**
- Revised Table 1-2, “Device IDs”.
1.5 February 10, 2015 **Specification Changes added or updated:**
- 6. Revision ID of A2 Stepping (Added)
**Errata added or updated:**
- 25. Slow System Clock (Updated)
- 30. NC-SI Hardware Arbitration Hang
**Miscellaneous Updates**
- Revised Table 1-2, “Device IDs”.
1.4 June 20, 2014 **Errata added or updated:**
- 29. SMBus: Interference with Get UDID Directed to Another Device (Added)
1.3 December 20, 2013 **Specification Clarifications added or updated:**
- 5. No Match Firmware Proxying Configuration (Added)
- 6. WUFC/PROXYFC NS Bits (Added)
**Specification Changes added or updated:**
- 3. PCIe Timing Parameter Update (Added)
- 4. Static Device Off Using PCIe Hot Reset (Added)
- 5. Multicast Listener Discovery (MLD) Protocol Offload is Not Supported (Added)
**Documentation Updates added or updated**
- 2. Ethernet Controller I210 Supported Flash Parts (Added)
**Errata added or updated:**
- 18. Failure to Establish PCIe Link After Power Up (Added)
- 19. Proxy: Neighbor Solicitation with Multicast Target Address is Not Dropped (Added)
- 20. Proxy: Missing Target Link-Layer Address in Neighbor Advertisement (Added)
- 21. NC-SI: Hardware Arbitration Disable is Not Preserved Across Firmware Reset
(Added)
- 22. NC-SI: Count of Dropped Control Packets Could be Incorrect (Added)
- 23. Transmit Halt After a D3-to-D0 Power State Transition (Added)
- 24. Failure of Flash Update from Shadow RAM (Added)
- 25. Slow System Clock (Added)
- 26. NC-SI: SerDes Link Bit is Clear in Link Status Structure in 1000BASE-KX Link Mode
(Added)
- 27. Dynamic Device Off is Not Functional (Added)
- 28. SMBus: Set Common Filters Command Does Not Set MNGONLY Bit in Shared MAC
Address Mode (Added)
**Miscellaneous Updates**
- Added Flash-less device IDs to Table 1-2, “Device IDs”.
1.2 July 8, 2013 **Specification Clarifications added or updated:**
- 4. Flash Update Integrity Firmware Enhancements (Added)
**Specification Changes added or updated:**
- 1. Proxy: Wake Up on Link Down/Up with MDNS Offload (Added)
- 2. No Firmware Reset via HICR in Secure Mode (Added)
**Documentation Updates added or updated**
- 1. Port Identification LED Blinking (Word 0x04) (Added)
**Errata added or updated:**
- 12. VPD Access During Shadow RAM Load to Flash Causes Firmware Reset and VPD
Hang (Added)
- 13. NC-SI: Repeated Pause Time After Receiving XOFF (Added)
- 14. NC-SI: Set Link Command Failure in Low Power State in SerDes Modes (Added)
- 15. NC-SI: Maximum XOFF Renewal Interval Might be Exceeded (Added)
- 16. NC-SI: Set Link and Get Link Status Commands Not Supported in 1000BASE-KX
Link Mode (Added)
- 17. Proxy: Invalid Neighbor Advertisement Packet with VLAN Tag and SNAP Header
(Added)

```
Revision Date Comments
```

```
Revision History
```
```
1.1 January 31, 2013 Errata added or updated:
```
- 8. Protocol Offload: Incorrect Response to MLDv2 Queries (Added)
- 9. Writes to the VPD RW Area are Not Reliable (Added)
- 10. NC-SI: Get NC-SI Pass-Through Statistics Response Might Contain Incorrect Packet
    Counts (Added)
- 11. MCTP Commands from SMBus are Dropped (Added)
1.0 October 26, 2012 Initial release (Intel Public)

**Revision Date Comments**


**_Introduction_**

## 1. Introduction

This document applies to the Intel® Ethernet Controller I210.

This document is an update to a published specification, the _Intel® Ethernet Controller I210 Datasheet_.
It is intended for use by system manufacturers and software developers. All product documents are
subject to frequent revision, and new order numbers will apply. New documents may be added. Be sure
you have the latest information before finalizing your design.

#### 1.1 Product Code and Device Identification

**Product Codes:** WGI210AT (Commercial Temperature Range)
WGI210IT/WGI210IS (Industrial Temperature Range)
WGI210CS (Automotive Industrial Temperature Range)
WGI210CL (Automotive Industrial Temperature Range <20DPM)

The following tables and drawings describe the various identifying markings on each device package:

**Table 1-1. Markings**

```
Device Stepping Top Marking Description
```
```
I210 A2 WGI210AT Production (Commercial Copper)
```
```
I210 A2 WGI210AT
Production (Industrial Temperature Copper)
Designation “I” on the 4th line of the package indicates industrial temperature).
```
```
I210 A2/A3 WGI210AS
Production (Industrial Temperature Fiber)
Designation “I” on the 4th line of the package indicates industrial temperature).
```
```
I210 A2/A3 WGI210CS
Production (Automotive Industrial Temperature Fiber)
Designation “I” on the 4th line of the package indicates industrial temperature).
```
```
I210 A3 WGI210CL
Production (Automotive Industrial Temperature Fiber <20DPM)
Designation “I” on the 4th line of the package indicates industrial temperature).
```
**Table 1-2. Device IDs**

```
I210 Device ID Code Vendor ID Device ID Revision ID^1
```
1. See Specification Change #6 for more details.

```
Not programmed/factory default 0x8086 0x1531 0x2/0x
WGI210AT/WGI210IT (copper only) 0x8086 0x1533 0x2/0x
WGI210IS (fiber, industrial temperature) 0x8086 0x1536 0x2/0x
WGI210IS (1000BASE-KX/BX backplane) 0x8086 0x1537 0x2/0x
WGI210IS (external SGMII, industrial temperature) 0x8086 0x1538 0x2/0x
WGI210AT/WGI210IT (Flash-less copper only) 0x8086 0x157B 0x2/0x
WGI210IS/WGI210CS (Flash-less 1000BASE-KX/BX backplane) 0x8086 0x157C 0x2/0x
WGI210CS/WGI210CL (Flash-less SGMII) 0x8086 0x15F6 0x2/0x
```

```
Introduction
```
##### 1.1.1 Identifying the A3 Stepping

The A3 stepping only applies to the Fiber (IS/CS/CL) products. The A3 stepping can be identified by the
Fab Lot Trace Code marking on the package or by the iNVM contents.

- Fab Lot Trace Codes starting with 1638 or greater are A3 devices.
- Bit 1 of INVM_DATA[61] (0x12214) is 1b on A3 devices.

Figure1-1 shows an example:

**Table 1-3. MM Numbers**

```
Product MM Number Spec Media
```
```
WGI210AT - Production (Commercial Copper)
```
```
925131 SLJXQ Tape and Reel
925132 SLJXR Tray
```
```
WGI210IT - Production (Copper and Industrial Temperature Range)
```
```
925133 SLJXS Tape and Reel
925138 SLJXT Tray
```
```
WGI210IS - Production (Fiber and Industrial Temperature Range)
```
```
925142 SLJXW Tape and Reel
925143 SLJXX Tray
```
```
WGI210CS - Production (Automotive, Fiber and Industrial Temperature Range)
```
```
937549 SLKKM Tape and Reel
937548 SLKKL Tray
```
```
WGI210CL - Production (Automotive, Fiber and Industrial Temperature Range
<20 DPM)
```
```
958497 SLM8V Tape and Reel
958496 SLM8U Tray
```
**Figure 1-1. Explanation of Top Markings for A3 Stepping**

```
Lot Code greater than 1638 indicates A3 silicon.
```
```
Industrial product
has an “AS” marking.
```
```
Presence of “I” indicates IS part.
```

**_Introduction_**

#### 1.2 Marking Diagrams

**Figure 1-2. I210 Production Top Marking Example (Commercial Temperature Copper)**

**Figure 1-3. I210 Production Top Marking Example (Industrial Temperature Copper)**

**Figure 1-4. I210 Production Top Marking Example (Industrial Temperature Fiber)**

**Figure 1-5. I210 Production Top Marking Example (Automotive Industrial Temperature
Fiber)**

###### i

###### 01234567.

###### WGI210AT

```
C 12
```
```
e
```
###### i

###### 01234567.

###### I

```
C 12
```
###### WGI210ATe

###### i

###### 01234567.

###### I

```
C 12
```
###### WGI210ASe

###### i

###### 01234567.

###### I

```
C 12
```
###### WGI210CSe


```
Introduction
```
**Notes:**

- Line 1: With no spaces, “i”©YY
- Line 2: Fab Lot Trace Code 0123456.78 (10-char max)
- Line 3: S-Spec Code and Pb-free mark (e3 or e1)
- Line 4: “I” in lower-right corner for industrial temperature rated devices

**Figure 1-6. I210 Production Top Marking Example (Automotive Industrial Temperature
Fiber <20DPM)**

###### i

###### 01234567.

###### I

```
C 12
```
###### WGI210CLe


**_Introduction_**

#### 1.3 Nomenclature Used in This Document

This document uses specific terms, codes, and abbreviations to describe changes, errata, and/or
clarifications that apply to silicon/steppings. See Table 1-4 for a description.

**Table 1-4. Nomenclature**

```
Name Description
```
```
Specification Clarifications Greater detail or further highlights concerning a specification’s impact to a complex design situation. These clarifications will be incorporated in the next release of the specifications.
```
```
Specification Changes Modifications to the current published specifications. These changes will be incorporated in the next release of the specifications.
```
```
Errata
```
```
Design defects or errors. Errata may cause device behavior to deviate from published specifications.
Hardware and software designed to be used with any given stepping must assume that all errata
documented for that stepping are present on all devices.
```
```
Documentation Updates Typos, errors, or omissions from the current published specifications. These changes will be incorporated in the next release of the specifications.
```
```
Doc Document change or update that will be implemented.
Fixed This erratum has been fixed.
Fix Planned This erratum is intended to be fixed in a future stepping of the component.
NoFix There are no plans to fix this erratum.
Fixed in NVM This erratum has been fixed in NVM X.XX.
Fix Planned in NVM This erratum is intended to be fixed in a future NVM version.
Eval Plans to fix this erratum are under evaluation.
(No mark) or (Blank box) This erratum is fixed in listed stepping or specification change does not apply to listed stepping.
DS Datasheet
DG Design Guide
SDM Software Developer’s Manual
EDS External Data Specification
AP Application Note
```

```
Hardware Clarifications, Changes, Updates and Errata
```
## 2. Hardware Clarifications, Changes,

## Updates and Errata

See Section1.3 for an explanation of terms, codes, and abbreviations.

**Table 2-1. Summary of Specification Clarifications**

```
Specification Clarification Status
```
1. PCIe Completion Timeout Mechanism Compliance N/A
2. Padding on Transmitted SCTP Packets N/A
3. Dynamic LED Modes Can Only be Used in an Active Low Configuration N/A
4. Flash Update Integrity Firmware Enhancements N/A
5. No Match Firmware Proxying Configuration N/A
6. WUFC/PROXYFC NS Bits N/A
7. WGI210CS Automotive Industrial Temperature Fiber Schematic N/A
8. PCIe Separate Reference Clock with Independent Spread (SRIS) Support N/A

**Table 2-2. Summary of Specification Changes**

```
Specification Change Status
```
1. Proxy: Wake Up on Link Down/Up with MDNS Offload N/A
2. No Firmware Reset via HICR in Secure Mode N/A
3. PCIe Timing Parameter Update N/A
4. Static Device Off Using PCIe Hot Reset N/A
5. Multicast Listener Discovery (MLD) Protocol Offload is Not Supported N/A
6. Revision ID of A2 Stepping N/A

**Table 2-3. Summary of Documentation Updates**

```
Documentation Update Status
```
```
None. N/A
```
**Table 2-4. Summary of Errata; Errata Include Steppings**

```
Erratum Status
```
1. I^2 C Data Out Hold Time Violation A2=Yes, A3=Yes; NoFix
2. NC-SI Hardware Arbitration Issues A2=Yes, A3=Yes; NoFix
3. SGMII: Counters Incorrectly Increment on Collision A2=Yes, A3=Yes; NoFix
4. BMC-Only Packets Not Counted as Host Sent/Received Packets A2=Yes, A3=Yes; NoFix
5. Device Off Deadlock A2=Yes, A3=Yes; NoFix


**_Hardware Clarifications, Changes, Updates and Errata_**

6. Marginal Low 10 Mb Amplitude A2=Yes, A3=Yes; NoFix
7. Non-Monotonic Integrated SVR Ramp A2=Yes, A3=Yes; NoFix
8. Protocol Offload: Incorrect Response to MLDv2 Queries N/A
9. Writes to the VPD RW Area are Not Reliable A2=Yes, A3=Yes; Fixed in NVM 3.
10. NC-SI: Get NC-SI Pass-Through Statistics Response Might Contain
    Incorrect Packet Counts A2=Yes, A3=Yes; NoFix
11. MCTP Commands from SMBus are Dropped A2=Yes, A3=Yes; Fixed in NVM 3.
12. VPD Access During Shadow RAM Load to Flash Causes Firmware Reset and
    VPD Hang A2=Yes, A3=Yes; Fixed in NVM 3.
13. NC-SI: Repeated Pause Time After Receiving XOFF A2=Yes, A3=Yes; NoFix
14. NC-SI: Set Link Command Failure in Low Power State in SerDes Modes A2=Yes, A3=Yes; Fixed in NVM 3.
15. NC-SI: Maximum XOFF Renewal Interval Might be Exceeded A2=Yes, A3=Yes; Fixed in NVM 3.
16. NC-SI: Set Link and Get Link Status Commands Not Supported in
    1000BASE-KX Link Mode A2=Yes, A3=Yes; Fixed in NVM 3.
17. Proxy: Invalid Neighbor Advertisement Packet with VLAN Tag and SNAP
    Header A2=Yes, A3=Yes; Fixed in NVM 3.
18. Failure to Establish PCIe Link After Power Up A2=Yes, A3=Yes; NoFix
19. Proxy: Neighbor Solicitation with Multicast Target Address is Not Dropped A2=Yes, A3=Yes; Fixed in NVM 3.
20. Proxy: Missing Target Link-Layer Address in Neighbor Advertisement A2=Yes, A3=Yes; Fixed in NVM 3.
21. NC-SI: Hardware Arbitration Disable is Not Preserved Across Firmware
    Reset A2=Yes, A3=Yes; Fixed in NVM 3.
22. NC-SI: Count of Dropped Control Packets Could be Incorrect A2=Yes, A3=Yes; Fixed in NVM 3.
23. Transmit Halt After a D3-to-D0 Power State Transition A2=Yes, A3=Yes; NoFix
24. Failure of Flash Update from Shadow RAM A2=Yes, A3=Yes; Fixed in NVM 3.
25. Slow System Clock A2=Yes, A3=Yes; NoFix
26. NC-SI: SerDes Link Bit is Clear in Link Status Structure in 1000BASE-KX
    Link Mode A2=Yes, A3=Yes; Fixed in NVM 3.
27. Dynamic Device Off is Not Functional A2=Yes, A3=Yes; NoFix
28. SMBus: Set Common Filters Command Does Not Set MNGONLY Bit in
    Shared MAC Address Mode A2=Yes, A3=Yes; NoFix
29. SMBus: Interference with Get UDID Directed to Another Device A2=Yes, A3=Yes; NoFix
30. NC-SI Hardware Arbitration Hang A2=Yes, A3=Yes; NoFix
31. Certain Malformed IPv6 Extension Headers are Not Processed Correctly by
    the Device A2=Yes, A3=Yes; NoFix
32. NC-SI Output Signals Have Indeterminate Value After Power Up A2=Yes, A3=Yes; NoFix
33. PCIe Advanced Error Reporting: First Error Pointer A2=Yes, A3=Yes; NoFix
34. PCIe Throughput with Few Credits A2=Yes, A3=Yes; NoFix

**Table 2-4. Summary of Errata; Errata Include Steppings (Continued)**

```
Erratum Status
```

```
Hardware Clarifications, Changes, Updates and Errata
```
#### 2.1 Specification Clarifications

##### 1. PCIe Completion Timeout Mechanism Compliance

The I210 Completion Timeout Value[3:0] must be properly set by the system BIOS in the I210 PCIe
Configuration Space Device Control 2 register (0xC8; W). Failure to do so can cause unexpected
completion timeouts.

The I210 complies with the PCIe 2.0 specification for the completion timeout mechanism and
programmable timeout values. The PCIe 2.0 specification provides programmable timeout ranges
between 50 s to 64 s with a default time range of 50 s to 50 ms. The I210 defaults to a range of
16 ms to 32 ms.

###### Workaround:

The completion timeout value must be programmed correctly in PCIe configuration space (in Device
Control 2 register); the value must be set above the expected maximum latency for completions in the
system in which the I210 is installed. This ensures that the I210 receives the completions for the
requests it sends out, avoiding a completion timeout scenario. Failure to properly set the completion
timeout value can result in the device timing out prior to a completion returning.

The I210 can be programmed to resend a completion request after a completion timeout (the original
completion request is assumed to be lost). But if the original completion arrives after a resend request,
two completions may arrive for the same request; this can cause unpredictable behavior. Intel NVM
images set the resend feature to off. Intel recommends that you do not change this setting.

##### 2. Padding on Transmitted SCTP Packets

When using the I210 to offload the CRC calculation for transmitted SCTP packets, software should not
add Ethernet padding bytes to short packets (less than 64 bytes). Instead, the TCTL.PSP bit should be
set so that the I210 pads the packets after performing the CRC calculation.

35. NC-SI Get Link Status Command Not Supported when Using SGMII A2=Yes, A3=Yes; NoFix
36. Internal Clock Malfunction A2=Yes, A3=No; Fixed
37. I210 Occasional Malfunction of Wake on LAN/Wake on Link when
    Transitioning from S4 on Windows 10 A2=Yes, A3=Yes; NoFix
38. Device ID and MAC Address Cannot be Changed A2=Yes, A3=Yes; NoFix
39. PCIe: Premature Timeout in LTSSM Configuration State A2=Yes, A3=Yes; NoFix

**Table 2-4. Summary of Errata; Errata Include Steppings (Continued)**

```
Erratum Status
```

**_Hardware Clarifications, Changes, Updates and Errata_**

##### 3. Dynamic LED Modes Can Only be Used in an Active Low Configuration

In any of the dynamic LED modes (FILTER_ACTIVITY, LINK/ACTIVITY, COLLISION, ACTIVITY, PAUSED),
LED blinking should only be enabled if the LED signal is configured as an active low output.

##### 4. Flash Update Integrity Firmware Enhancements

The I210 Flash Update integrity feature (Section 3.3.10 of the _Intel® Ethernet Controller I
Datasheet_ ) ensures only Intel digitally signed updates can be applied to I210 products post
manufacturing. This is achieved by a combination of hardware and firmware capabilities. NVM image
release 3.20 includes firmware enhancements to improve the resilience of this feature.

##### 5. No Match Firmware Proxying Configuration

When the Set Firmware Proxying Configuration command is used and the No Match Data field is 0x01,
any packet that passes the hardware proxy filters and cannot be processed by the firmware causes a
wake up event. Care should be taken when using this setting to prevent the possibility of unintended
wake-ups.

##### 6. WUFC/PROXYFC NS Bits

The NS and NS Directed bits in both the WUFC and PROXYFC registers enable filters that pass Neighbor
Solicitation packets. These filters do not check the ICMPv6 Type field, so they actually pass any ICMPv
packet that meets all the other requirements. For example, ICMP Echo Request packets can pass these
filters. Care should be exercised when setting these bits in WUFC to avoid unintentional system wake-
ups.


```
Hardware Clarifications, Changes, Updates and Errata
```
##### 7. WGI210CS Automotive Industrial Temperature Fiber Schematic

**Note:** The I210 CS has four no-connect corner pads for added solder joint reliability (as shown in
Detail C).

##### 8. PCIe Separate Reference Clock with Independent Spread (SRIS)

##### Support

PCIe Separate Reference Clock with Independent Spread (SRIS) is NOT supported. The device requires
a common PCIe reference clock and should be configured with “Common Clock: Mode in BIOS. SRIS
mode causes PCI bus enumeration to fail.

### DUAL PORT 1000/10GBASE-T

### KX/KR/IXFI X 2 FOR USE WITH BDX-DE


**_Hardware Clarifications, Changes, Updates and Errata_**

#### 2.2 Specification Changes

##### 1. Proxy: Wake Up on Link Down/Up with MDNS Offload

As described in the _Intel® Ethernet Controller I210 Datasheet_ , when mDNS proxy offload is active, the
I210 wakes the system if the LAN link is lost and then re-established. Starting from NVM image release
3.20, the wake-up does not occur unless the link was down for at least 120 seconds. This prevents a
spurious wake up triggered by the power state change from D0a to D3 or Dr.

##### 2. No Firmware Reset via HICR in Secure Mode

When the I210 is operating in Secure Mode, the value of the Enable Firmware Reset NVM bit is ignored
and firmware reset via the Host Interface Control Register (HICR) is disabled.

This change is implemented starting from NVM image release 3.20.

##### 3. PCIe Timing Parameter Update

In Section 5.5.6 of the _Intel® Ethernet Controller I210 Datasheet_ , the maximum value of timing
parameter tppg-clkint (PCIe PE_RST de -assertion to internal PLL lock) has been updated to 5 ms.

##### 4. Static Device Off Using PCIe Hot Reset

Starting with NVM image release 3.25, the sequence for entering the static device off state can use a
PCIe Hot Reset instead of an assertion of the PE_RST_N pin. This change removes the implicit
requirement to have a dedicated signal connected to the PE_RST_N pin to toggle the pin without
resetting the system.

In Section 4.4.4.1 of the _Intel® Ethernet Controller I210 Datasheet_ , Step 3 should read, “BIOS issues a
PCIe reset, either by asserting and de -asserting the PE_RST_N pin or by generating a PCIe Hot Reset.”

**Notes:** The sequence for returning from the static device off state cannot use a PCIe Hot Reset
since the PCIe link is down in the static device off state.

This change does not apply to flash-less applications.

##### 5. Multicast Listener Discovery (MLD) Protocol Offload is Not Supported

IPv6 Multicast Listener Discovery (MLD) protocol offload is not supported.

The Set Firmware Proxying Configuration host interface command must contain 0 in the Enable MLD
field.


```
Hardware Clarifications, Changes, Updates and Errata
```
##### 6. Revision ID of A2 Stepping

The Revision ID of the A2 stepping is either 0x02 or 0x03. The value of the least-significant bit is
indeterminate.

This affects the following fields that can be read from the I210:

- Step Rev ID field in the Mirrored Revision ID (MREVID) CSR.
- Revision ID register in the PCIe configuration space.
- Version field read by the IDCODE and USERCODE JTAG instructions.
- Silicon Revision ID field in the SMBus ARP UDID.
- Silicon Revision field returned by the Get Controller Information SMBus command.
- LS-Byte of the Firmware Version field returned by the Get Version ID NC-SI command.
- Rev ID field returned by the Get Controller Information NC-SI OEM command.

#### 2.3 Documentation Updates

None.


**_Hardware Clarifications, Changes, Updates and Errata_**

#### 2.4 Errata

##### 1. I

###### 2

##### C Data Out Hold Time Violation

###### Problem:

The I210 should provide a data out hold time of 50 ns on the SFP_I2C_Data pin. The actual hold time is
about 16 ns.

###### Implication:

Timing specification violation. There have been no reports of failures resulting from this timing.

**Note:** The data input hold time required is zero, so the provided output hold time should be more
than enough as long as the I^2 C CLK and DATA signals are reasonably matched on the
board.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix

##### 2. NC-SI Hardware Arbitration Issues

###### Problem:

1. During normal operation, the I210 might get FLUSH commands with a smaller ID than the device
    ID. The I210 should pass on the received FLUSH, but it sends its own ID for ~2 s and then passes
    on the lower ID FLUSHes.
2. The time from received-idle (while in a wait idle state) until the I210 sends IDLE on ARB_OUT is
    1.7s. The maximum time allowed (by the specification) is T9 = 640 ns.\
3. If a token timeout occurs while the I210 waits to send an XON packet, the internal state machine is
    reset and the XON is never sent.
4. Hardware arbitration timeout mechanism stops upon receiving pause packets from the MC. The
    timer stops counting until the pause indication drops.
5. The I210 sends XON opcode after the end of the Master Assignment process, even if the XOFF time
    (~300 ms) has expired.

```
If the I210 exits the congested mode during the Master Assignment process, it sends XON opcode
at the end of the Master Assignment process even if the XOFF has expired.
```
The I210 does not consider the Master Assignment duration in the XOFF expiration time.

6. When the I210 enters congestion mode, it sends XOFF opcode and also makes a request for TOKEN
    to send an XOFF frame.

```
When the I210 enters congestion mode, it should send a XOFF frame if it has the TOKEN or XOFF
opcode even if it has not received the TOKEN.
```
The I210 should not send both of them (opcode and frame) in any case.


```
Hardware Clarifications, Changes, Updates and Errata
```
###### Implication:

1. No implication in actual operation. Eventually, the lower IDs pass and arbitration succeeds.
    2. The issue is not expected to cause problems because the timeout period is longer. Minor NC-SI
       compliance violation related to hardware arbitration.
    3. The MC is released by the XOFF timer expiration. Minor NC-SI compliance violation related to
       hardware arbitration.
    4. Longer than expected timeout (no specification violation).
    5. No implication.
    6. Slight delay in traffic coming from the MC but no platform implication.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix

##### 3. SGMII: Counters Incorrectly Increment on Collision

###### Problem:

In SGMII mode/half duplex, the following statistics counters incorrectly increment when a collision
occurs:

###### Implication:

Error counters might not be accurate.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix

##### 4. BMC-Only Packets Not Counted as Host Sent/Received Packets

###### Problem:

When OS2BMC is enabled, packets that do not reach the LAN are not counted as packets sent by the
host (HGPTC register). Similarly, packets received from the MC are not counted as packets received by
the host (RPTHC register).

###### Implication:

HGPTC and RPTHC counts are not accurate.

```
Name Definition Location
```
```
RLEC Length error counter 0x
CRCERRS CRC error counter 0x
RFC Receive frame counter 0x40A
```

**_Hardware Clarifications, Changes, Updates and Errata_**

###### Workaround:

Add the O2BGPTC count to the HGPTC count to get the accurate number of packets sent by the host.
Add the B2OGPRC count to the RPTHC count to get the accurate number of packets received by the
host.

###### Status: A2=Yes, A3=Yes; NoFix

##### 5. Device Off Deadlock

###### Problem:

If firmware resets (such as due to a parity error) after entering device off, the I210 does not detect the
error and should enter device off but not shut the device down.

This happens only after a firmware reset.

###### Implication:

The chances of such an event happening while moving to device off are minimal.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix

##### 6. Marginal Low 10 Mb Amplitude

###### Problem:

1. 10BASE-T amplitude.

```
On some designs, the I210 might not meet the IEEE specification that states that the 10 Mb peak
differential amplitude be between 2.2 V and 2.8 V for all data sequences.
```
2. 10BASE-T TP_IDLE mask failures.

Some designs might have mask failures on the 10BASE-T TP_IDLE with TPM load.

3. 10 BASE-Te (802.3az section 14.10) amplitude.

```
On some designs, the I210 might not meet the IEEE specification that states that when 10BASE-Te
is enabled the 10 Mb peak differential amplitude be between 1.54 V and 1.96 V for all data
sequences.
```
4. 10BASE-Te TP_IDLE and link test pulse waveform mask failures.

```
Some designs might have mask failures on the 10BASE-Te TP_IDLE and link test pulse with and
without TPM load.
```
###### Implication:

No implication on system level performance or interoperability, conformance test only impact.


```
Hardware Clarifications, Changes, Updates and Errata
```
###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix

##### 7. Non-Monotonic Integrated SVR Ramp

###### Problem:

On some designs, both the 0.9 V and 1.5 V SVR show a non-monotonic start up.

###### Implication:

No functional impact for systems using an internal SVR, because the system is not vulnerable at the
specific time that this non-monotonicity occurs.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix

##### 8. Protocol Offload: Incorrect Response to MLDv2 Queries

Superseded by Specification Change #5.

##### 9. Writes to the VPD RW Area are Not Reliable

###### Problem:

VPD write accesses via the PCIe VPD Capability Structure are not always stored in the Flash.

###### Implication:

VPD writes are not reliable.

###### Workaround:

Do not use a RW area in the VPD structure. RO areas function correctly.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.

##### 10. NC-SI: Get NC-SI Pass-Through Statistics Response Might Contain

##### Incorrect Packet Counts

###### Problem:

The I210 maintains packet counters that are used in the Get NC-SI Pass-Through Statistics Response.
These counters are cleared by any reset of the port, including the port reset generated by a PCIe reset.


**_Hardware Clarifications, Changes, Updates and Errata_**

###### Implication:

If a PCIe reset or port reset has occurred since the previous Get NC-SI Pass-Through Statistics
Response, the packet count values could be lower than the actual packet counts because the counters
were cleared.

###### Workaround:

The packet counts in the Get NC-SI Pass-Through Statistics Response can be used for debug purposes,
but they should not be used for maintaining reliable statistics.

###### Status: A2=Yes, A3=Yes; NoFix

##### 11. MCTP Commands from SMBus are Dropped

###### Problem:

The DMTF MCTP SMBus/I^2 C Transport Binding Specification requires that the LSB of the 4th byte of an
MCTP over SMBus packet be 1b. Such a packet is dropped by the I210.

###### Implication:

MCTP over SMBus is not functional since all commands are dropped.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.16

##### 12. VPD Access During Shadow RAM Load to Flash Causes Firmware Reset

##### and VPD Hang

###### Problem:

If a VPD read or write access is performed while the firmware is in the process of loading the shadow
RAM to the Flash, the firmware hangs. After the firmware watchdog timer expires, the firmware is reset
and the VPD access is never completed.

###### Implication:

- Any manageability configuration from the Manageability Controller (MC) is lost due to the firmware
    reset.
- No more VPD read or write accesses can be performed until a PCIe reset occurs.

###### Workaround:

To prevent this scenario, check that EEC. _Shadow_modified_ is 0b before performing a VPD read or write
access. If less than 10 ms have passed since the previous VPD write access, it is OK to ignore this bit.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.20


```
Hardware Clarifications, Changes, Updates and Errata
```
##### 13. NC-SI: Repeated Pause Time After Receiving XOFF

###### Problem:

If the I210 receives an XOFF packet from the Manageability Controller (MC) and the next packet is an
NC-SI command, the pause timer is restarted when the command is received.

###### Implication:

The response to the command is delayed until the pause timer expires, which could cause the MC to
detect a timeout of the command.

###### Workaround:

The MC should send an XON packet to explicitly re-enable transmission from the I210 at the end of
each congestion event and should not rely on expiration of the pause time in the XOFF packet.

###### Status: A2=Yes, A3=Yes; NoFix

##### 14. NC-SI: Set Link Command Failure in Low Power State in SerDes Modes

###### Problem:

The I210 checks the Disable 1000 in non-D0a and Disable 100 in non-D0a bits of the PHPM register
when determining if the speed(s) requested in a Set Link command are valid in the non-D0a states. If
there is a conflict, the command fails with a Set Link Power Mode Conflict status.

This behavior is correct when using the internal PHY, but it is incorrect when using the other link modes.

###### Implication:

Set Link command is improperly rejected in SerDes modes in low-power states.

###### Workaround:

Clear the Disable 1000/100 in non-D0a NVM bits in non-copper modes.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.20

##### 15. NC-SI: Maximum XOFF Renewal Interval Might be Exceeded

###### Problem:

When NC-SI flow control is enabled and the MC-to-LAN buffer is congested, the I210 sends XOFF
packets to the MC. The NC-SI Specification defines a Max XOFF Renewal Interval after which the XOFF
condition must be removed. The I210 violates this specification by continuing to send XOFF packets as
long as the congestion condition remains.

###### Implication:

Unusual congestion on the LAN interface could prevent the MC from communicating with the I210 for
extended periods of time.


**_Hardware Clarifications, Changes, Updates and Errata_**

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.20

##### 16. NC-SI: Set Link and Get Link Status Commands Not Supported in

##### 1000BASE-KX Link Mode

###### Problem:

When the CTRL_EXT. _LINK_MODE_ is set to 01b (1000BASE-KX), the NC-SI Set Link and Get Link Status
commands do not function correctly.

###### Implication:

The MC cannot properly control the link in 1000BASE-KX link mode.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.20

##### 17. Proxy: Invalid Neighbor Advertisement Packet with VLAN Tag and SNAP

##### Header

###### Problem:

If a Neighbor Solicitation packet is received with a VLAN tag and a SNAP header, the Neighbor
Advertisement (NA) response also contains a VLAN tag and a SNAP header. However, the length field in
the SNAP header of the NA packet returned by the I210 contains an incorrect value.

###### Implication:

Neighbor Solicitation proxy offload failure.

###### Workaround:

Do not use both VLAN tag and SNAP header in a Neighbor Solicitation packet.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.20

I210 with Flash: Fixed in NVM image release 3.20.

I210 Flash-less: NoFix.

##### 18. Failure to Establish PCIe Link After Power Up

###### Problem:

If the first de-assertion of PE_RST_N following power-up lasts less than 5 ms, the PCIe PLL might be
calibrated incorrectly. When this occurs, the PLL does not lock and the PCIe logic remains in reset until
the next power cycle.


```
Hardware Clarifications, Changes, Updates and Errata
```
###### Implication:

Failure to establish PCIe link.

###### Workaround:

Ensure that the duration of the first de-assertion of PE_RST_N after power-up is at least 5 ms.

A firmware workaround for this issue is included in NVM image release 3.25.

###### Status: A2=Yes, A3=Yes; NoFix

##### 19. Proxy: Neighbor Solicitation with Multicast Target Address is Not

##### Dropped

###### Problem:

According to Section 7.1.1 of RFC 4861, a Neighbor Solicitation packet with a multicast Target Address
field should be silently dropped. The I210 accepts and responds to such a packet if the Target Address
corresponds to the Solicited Node address provided by the host.

###### Implication:

No implication when the network is functioning correctly since this is not a valid packet. Reduced
immunity to invalid inputs.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.25

I210 with Flash: Fixed in NVM image release 3.25.

I210 Flash-less: NoFix.

##### 20. Proxy: Missing Target Link-Layer Address in Neighbor Advertisement

###### Problem:

If a Neighbor Solicitation packet does not include a source link-layer address option, the Neighbor
Advertisement packet sent by the I210 in response does not include a target link-layer address option.

###### Implication:

If the link partner is performing Duplicate Address Detection, the Neighbor Advertisement packet
generated by the I210 is dropped by the receiver since the target link-layer address is missing. As a
result, there could be undetected duplicate addresses on the network.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.25

I210 with Flash: Fixed in NVM image release 3.25.
I210 Flash-less: NoFix.


**_Hardware Clarifications, Changes, Updates and Errata_**

##### 21. NC-SI: Hardware Arbitration Disable is Not Preserved Across Firmware

##### Reset

###### Problem:

If NC-SI hardware arbitration is enabled from the NVM and it is disabled by the Select Package
command, the hardware arbitration is enabled after a firmware reset.

###### Implication:

NC-SI interface hang in this situation.

###### Workaround:

Hardware arbitration should be disabled in the NVM if it is not required. The Select Package command
should not be used to disable hardware arbitration.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.25

##### 22. NC-SI: Count of Dropped Control Packets Could be Incorrect

###### Problem:

The NC-SI Control Packets Dropped counter in the Get NC-SI Statistics Response packet does not
include control packets that were dropped due to a checksum error.

###### Implication:

Misleading statistics when debugging.

###### Workaround:

Add the value of the NC-SI Command Checksum Errors counter to the value of the NC-SI Control
Packets Dropped counter when processing a Get NC-SI Statistics Response packet.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.25

##### 23. Transmit Halt After a D3-to-D0 Power State Transition

###### Problem:

If EEE is active on a port's transmit path and MANC. _KEEP_PHY_LINK_UP_ is 1b, data transmission from
the MAC might halt following a D3-to-D0 power state transmission.

###### Implication:

Loss of communication over the LAN.

###### Workaround:

Clear EEER. _TX_LPI_EN_ to disable EEE in the transmit path when going to the D3 state if
_KEEP_PHY_LINK_UP_ is 1b.

This workaround is implemented in firmware in NVM image release 3.25.

###### Status: A2=Yes, A3=Yes; NoFix


```
Hardware Clarifications, Changes, Updates and Errata
```
##### 24. Failure of Flash Update from Shadow RAM

###### Problem:

If a Flash update from a shadow RAM procedure is performed while there is a management command
or proxy packet pending, the Flash update fails and no further updates are performed. This failure is
indicated by the value 0x05 in FWSM. _Ext_Err_Ind_.

During typical operation, this is a low-probability scenario since Flash updates from the shadow RAM
are rarely performed and management commands and proxy packets also do not arrive at a high rate.

However, when the Restore MAC Address feature is enabled in the NVM, a Flash update from the
shadow RAM is triggered after power-up. If the MC is also polling for the presence of the device at this
time, this failure can occur with high probability.

###### Implication:

Flash updates (by writing EEC. _FLUPD_ ) cannot be performed. In Non-Secure Mode the flash can instead
be updated directly by software, using the FLSWCTL and FLSWDATA registers.

###### Workaround:

If the Restore MAC Address feature is enabled in the NVM, the MC should wait 500 ms after power is
applied to the I210 before sending commands to the I210.

If this failure is observed, as indicated by FWSM. _Ext_Err_Ind_ , contact your Intel representative.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.25

##### 25. Slow System Clock

###### Problem:

On some devices, the internal PLL circuit occasionally provides the wrong clock frequency after power
up. The probability of failure is typically less than one failure per 1000 power cycles. When the failure
occurs, the internal clock frequency is in the range of 1/10 to 1/20 of the correct frequency.

The failure can be observed on the NVM_SK output, which will be running at a frequency below 5 MHz.

The failure can be detected from software by either of the following:

- Read internal PHY register 14 from page 252 as detailed in Step 3 of the workaround. The failing
    state is indicated by a value of 0xFF in bits 7:0.
- Read the FRTIMER register twice at a known time interval and see if the difference in the two values
    matches the interval.

###### Implication:

No link can be established until the next power cycle.

###### Workaround:

NVM image release 3.25 contains a workaround in firmware. If the APM Enable bit is set in NVM Word
0x24, the minimum time from power up until PE_RST de-assertion (Tm-per) must be increased to
250 ms to ensure that the workaround is executed.

For flash-less applications, the following workaround can be performed in software.


**_Hardware Clarifications, Changes, Updates and Errata_**

**Note:** If a failure occurs, there is no link before the software runs, so APM WoL is not totally
reliable in these applications.

1. Acquire the PHY semaphore.
2. Set MDICNFG. _Destination_ to 0b.
3. Read PHY register 14 from page 252:

a. Write 0xFC to PHY register 22 (dec) using MDIC.

b. Wait at least 20 s.

c. Read from PHY register 14 (dec) using MDIC.

d. Wait at least 20 s.

e. Write 0b to PHY register 22 (dec) using MDIC.

If bits 7:0 of the PHY register read in sub-step (c)! = 0xFF, go to Step 15.

```
If the value is 0xFF after several (5) attempts to fix it (loops through Step 14), exit with a fatal
error.
```
4. Set CTRL. _PHY_RST_ to 1b.
5. Set both CTRL_EXT. _PHY_Power_Down_Enable_ and CTRL_EXT. _SerDes_Low_Power_Enable_ to 1b.
6. Clear WUC.
7. Determine the value of auto-load word 0x0A. If this word exists in the iNVM, use that value.
    Otherwise, use the hardware default value, 0x202F.
8. Perform a bitwise OR of 0x0010 with the value from the Step 6 and write it as an auto-load of 0x0A
    using EEARBC.
9. Set PCIe configuration space register PMCSR bits 1:0 to 11b. (D3 state).
10. Wait 1 ms.
11. Set PCIe configuration space register PMCSR bits 1:0 to 00b. (D0 state).
12. Write the value from Step 6 as an auto-load of 0x0A using EEARBC.
13. Restore WUC to its original value, if necessary.
14. Go to Step 2.
15. Restore MDICNFG. _Destination_ to its original value, if necessary.
16. Release the PHY semaphore

This workaround has been implemented in Intel software device driver 19.1.

###### Status: A2=Yes, A3=Yes; NoFix

##### 26. NC-SI: SerDes Link Bit is Clear in Link Status Structure in

##### 1000BASE-KX Link Mode

###### Problem:

The response to a Get Link Status command in 1000BASE-KX link mode (CTRL_EXT. _Link_Mode_ = 01b)
has the SerDes Link bit set to 0b when it should be set to 1b. The same applies to a Link Status Change
AEN.


```
Hardware Clarifications, Changes, Updates and Errata
```
###### Implication:

Incorrect indication of link mode. Other fields in the response might be interpreted incorrectly as a
result.

###### Workaround:

The MC should use another method to determine the link mode.

###### Status: A2=Yes, A3=Yes; Fixed in NVM 3.25

##### 27. Dynamic Device Off is Not Functional

###### Problem:

The I210 does not actually enter the Dynamic Device Off state even if all the necessary conditions are
satisfied.

This does not apply to flash-less applications.

###### Implication:

Power consumption is higher than expected.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix

##### 28. SMBus: Set Common Filters Command Does Not Set MNGONLY Bit in

##### Shared MAC Address Mode

###### Problem:

When executing a Set Common Filters command with the CBDM bit set to 0b (Shared MAC Address),
the I210 uses the MDEF7 register to enable the IP address and/or port number filters specified in the
command, but it does not set bit 7 of the MNGONLY register.

###### Implication:

Management traffic is duplicated and forwarded to the host in addition to the MC.

###### Workaround:

After sending the Set Common Filters command, the MC should send an Update Management Receive
Filter Parameters command (Parameter Number 0xF) to set bit 7 of the MNGONLY register.

###### Status: A2=Yes, A3=Yes; NoFix


**_Hardware Clarifications, Changes, Updates and Errata_**

##### 29. SMBus: Interference with Get UDID Directed to Another Device

###### Problem:

If the I210 shares an SMBus connection with other slave devices, it interferes with Get UDID commands
directed to the other devices.

###### Implication:

Failure of Get UDID (directed) commands on a shared SMBus.

###### Workaround:

Do not use Get UDID (directed) commands when the I210 is on a shared SMBus. The standard SMBus
ARP flow does not require the Get UDID (directed) command, so this restriction should not interfere
with the ability to perform SMBus ARP.

###### Status: A2=Yes, A3=Yes; NoFix

##### 30. NC-SI Hardware Arbitration Hang

###### Problem:

When using NC-SI hardware arbitration, the arbitration state machine of the device with the lowest
Package ID could hang. This can only occur during PCIe reset following power-up of the device and only
with the following NVM settings:

- _APM Enable_ = 0b (Word 0x24)
- _EN_PHY_IN_D3_ = 0b (Common Firmware Parameters 2 word)

###### Implication:

No transmission to the BMC from any of the devices.

###### Workaround:

Set the _EN_PHY_IN_D3_ NVM bit (Bit 9 of Common Firmware Parameters 2) to 1b if NC-SI hardware
arbitration is enabled.

###### Status: A2=Yes, A3=Yes; NoFix

##### 31. Certain Malformed IPv6 Extension Headers are Not Processed Correctly

##### by the Device

###### Problem:

Certain malformed IPv6 extension headers are not processed correctly by the device.

###### Implication:

If a packet containing such malformed IPv6 extension headers is received, the device might behave
unpredictably.


```
Hardware Clarifications, Changes, Updates and Errata
```
###### Workaround:

Set bit 16 ( _IPv6_ExDis_ ) in the RFCTL register to disable the processing of received IPv6 extension
headers.

**Note:** With this bit set, checksum calculation and RSS are disabled for IPv6 packets containing
extension headers.

This workaround has been implemented in Intel drivers starting from Release 20.2.

###### Status: A2=Yes, A3=Yes; NoFix

##### 32. NC-SI Output Signals Have Indeterminate Value After Power Up

###### Problem:

The NC-SI output signals have an indeterminate value after power up until the first rising edge of the
NC-SI input clock. The signals could be tri-stated or driven high or low.

###### Implication:

Current leakage through the NC-SI I/O buffers.

###### Workaround:

If the NC-SI input clock is not driven after power up, connect the NC-SI clock input pin so that there is
a rising edge after power has stabilized. For example, it could be connected via a resistor to a power-
good indication on the board.

###### Status: A2=Yes, A3=Yes; NoFix

##### 33. PCIe Advanced Error Reporting: First Error Pointer

###### Problem:

The First Error Pointer in the Advanced Error Capabilities and Control Register (PCIe register 0x118 bits
4:0) is a field that identifies the bit position of the first error reported in the Uncorrectable Error Status
register. In the I210 implementation, the following bits of the Uncorrectable Status Register are not
covered by this field:

- Bit 4 -Data Link Protocol Error Status.
- Bit 13 - Flow Control Protocol Error Status.
- Bit 14 - Completion Timeout Status.

###### Implication:

PCIe specification compliance issue.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix


**_Hardware Clarifications, Changes, Updates and Errata_**

##### 34. PCIe Throughput with Few Credits

###### Problem:

A received Update FC DLLP is not always processed immediately. It sometimes stalls in the I210 until
the next TLP or DLLP is received.

###### Implication:

Reduced PCIe throughput when the number of credits provided by the PCIe port to which the I210 is
connected is too small for continuous PCIe traffic.

###### Workaround:

Connect the I210 to a PCIe port that provides enough PCIe credits for continuous PCIe traffic.

###### Status: A2=Yes, A3=Yes; NoFix

##### 35. NC-SI Get Link Status Command Not Supported when Using SGMII

###### Problem:

When CTRL_EXT. _LINK_MODE_ is 10b (SGMII), the NC-SI Get Link Status command is not supported.

###### Implication:

The I210 connecting via SGMII to an external PHY does not pass link status to the MC.

###### Workaround:

Use keep-alive packets to determine connectivity.

###### Status: A2=Yes, A3=Yes; NoFix

##### 36. Internal Clock Malfunction

###### Problem:

Some I210 units fail to generate an internal clock after power-up. This has been observed more often
when powering up at high temperature.

This failure only occurs on Fiber (SerDes) SKUs. This erratum does not apply to Copper SKUs.

###### Implication:

The I210 cannot be enumerated on the PCIe bus and does not establish an Ethernet link.

###### Workaround:

A power cycle at a lower temperature can restore functionality.

###### Status: A2=Yes, A3=No; Fixed

Fixed in the A3 revision.


```
Hardware Clarifications, Changes, Updates and Errata
```
##### 37. I210 Occasional Malfunction of Wake on LAN/Wake on Link when

##### Transitioning from S4 on Windows 10

###### Problem:

While host initiates L2/L3 low-power entering request (PME_Turn_Off), the device replies with the
PME_TO_ACK as expected. However, sometimes a PM Enter L1 is followed while the spec requirement is
to send PM_Enter_L23 when the device is ready to go into low power. It was shown that the 8th Gen
Intel® Core™ processors with additional PCIe device (for example, graphics card) is connected, the
host waits the TO timer value as defined, and goes to recovery state (instead of low power since the
PME_Turn_Off handshake sequence not complete) and suddenly goes to electrical Idle mode.

This behavior caused I210 LTSSM to move to polling and detect states, since there is no signal detected
on its receiver. At this state there is an internal reset and it also caused NVM to auto-load, thus the APM
bits are updated from the NVM even when previously disabled. At this stage the APM disable setting by
software is not valid, as a new value being read by the NVM. This why if APM is enabled by NVM, the
device Wakes on LAN although this feature was unchecked before.

###### Implication:

8 th Gen Intel® Core™ processors (Desktop S-series) system might have unexpected wake-up events
even though Wake on LAN is disabled from the software/driver in Windows 10.

###### Workaround:

The PCIe specification defines a mechanism when endpoints do not enter the L2 state. To avoid
deadlock where one or more devices do not respond with a PME_TO_Ack Message and then put Links
into the L2/L3 Ready state, the power manager must implement a timeout after waiting for a certain
amount of time, after which it proceeds as if the Message had been received and all Links are put into
the L2/L3 Ready state. The recommended limit for this timer is in the range of 1 ms to 10 ms.

The power delivery manager must wait a minimum of 100 ns after observing all Links corresponding to
the point of origin of the PME_Turn_Off Message enter L2/L3 Ready before removing the components’
reference clock and main power. This requirement does not apply in the case where the above
mentioned timer triggers. From the failure symptom we tried the delay of PME timeout from 1ms
(default) to 10ms, but it takes longer than defined in the specification. Therefore, disable the timeout
timer as a workaround.

The workaround is to disable the timeout timer, as follows:

Set Dxx:Fn + 320h[21:20] = 11b.

**Note:** The workaround only applies to I210 adapter plugged.

###### Status: A2=Yes, A3=Yes; NoFix


**_Hardware Clarifications, Changes, Updates and Errata_**

##### 38. Device ID and MAC Address Cannot be Changed

###### Problem:

As part of the implementation of _Recovery Mode for Intel® Ethernet Products_ , starting firmware version
3.30, the device will not change Device ID fields (VID, DID, SVID and SSID) and MAC Address fields
after the original factory programming.

###### Implication:

After the original factory NVM programming, Device IDs and MAC Address cannot be changed starting
NVM version 3.30.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix

##### 39. PCIe: Premature Timeout in LTSSM Configuration State

###### Problem:

In the process of establishing a PCIe link, while in the _Configuration.Lanenum.Wait_ state, the I210 Link
Training and Status State Machine (LTSSM) is supposed to wait up to 2 ms to receive two consecutive
TS2 Ordered Sets from the upstream port. In some cases, the LTSSM times out after a much shorter
time, thereby aborting the link establishment.

###### Implication:

If early timeout occurs, LTSSM is reset back to Detect state. Generally this reset results in a short delay
(<100 ms) in establishing the PCIe link.

###### Workaround:

None.

###### Status: A2=Yes, A3=Yes; NoFix


```
Software Clarifications
```
## 3. Software Clarifications

##### 1. While in TCP Segmentation Offload, Each Buffer is Limited to 64 KB

The I210 supports 256 KB TCP packets. However, each buffer is limited to 64 KB since the data length
field in the transmit descriptor is only 16 bits. This restriction increases driver implementation
complexity if the operating system passes down a scatter/gather element greater than 64 KB in length.
This can be avoided by limiting the offload size to 64 KB.

Investigation has concluded that the increase in data transfer size does not provide any noticeable
improvements in LAN performance. As a result, Intel network software drivers limit the data transfer
size in all drivers to 64 KB.

Please note that Linux operating systems only support 64 KB data transfers.

##### 2. Serial Interfaces Programmed by Bit Banging

When bit-banging on a serial interface (such as SPI, I^2 C, or MDIO), it is often necessary to perform
consecutive register writes with a minimum delay between them. However, simply inserting a software
delay between the writes can be unreliable due to hardware delays on the CPU and PCIe interfaces. The
delay at the final hardware interface might be less than intended if the first write is delayed by
hardware more than the second write. To prevent such problems, a register read should be inserted
between the first register write and the software delay, i.e. “write”, “read”, “software delay”, “write”.

**Table 3-1. Summary of Software Clarifications**

```
Software Clarification Status
```
1. While in TCP Segmentation Offload, Each Buffer is Limited to 64 KB N/A
2. Serial Interfaces Programmed by Bit Banging N/A


**_Software Clarifications_**

**_NOTE: This page intentionally left blank._**


#### LEGAL

No license (express or implied, by estoppel or otherwise) to any intellectual property rights is granted by this document.

This document (and any related software) is Intel copyrighted material, and your use is governed by the express license under which
it is provided to you. Unless the license provides otherwise, you may not use, modify, copy, publish, distribute, disclose or transmit
this document (and related materials) without Intel's prior written permission. This document (and related materials) is provided as
is, with no express or implied warranties, other than those that are expressly stated in the license.

Intel disclaims all express and implied warranties, including without limitation, the implied warranties of merchantability, fitness for a
particular purpose, and non-infringement, as well as any warranty arising from course of performance, course of dealing, or usage in
trade.

This document contains information on products, services and/or processes in development. All information provided here is subject
to change without notice. Contact your Intel representative to obtain the latest forecast, schedule, specifications and roadmaps.

The products and services described might contain defects or errors which might cause deviations from published specifications.

Copies of documents which have an order number and are referenced in this document might be obtained by calling 1-800-548-4725
or by visiting [http://www.intel.com/design/literature.htm.](http://www.intel.com/design/literature.htm.)

Intel and the Intel logo are trademarks of Intel Corporation in the U.S. and/or other countries.

Other names and brands might be claimed as the property of others.

© 2012 -2022 Intel Corporation.


