## Revision 2.

## May 2015

# Intel

## ®

# Ethernet Connection I

## Datasheet

## Client Connectivity Division (CCD)

##### PRODUCT FEATURES

```
General
 10 BASE-T IEEE 802.3 specification compliance
 100 BASE-TX IEEE 802.3 specification compliance
 1000 BASE-T IEEE 802.3 specification compliance
 Energy Efficient Ethernet (EEE)
 IEEE 802.3az support [Low Power Idle (LPI) mode]
 IEEE 802.3u auto-negotiation conformance
 Supports carrier extension (half duplex)
 Loopback modes for diagnostics
 Advanced digital baseline wander correction
 Automatic MDI/MDIX crossover at all speeds of operation
 Automatic polarity correction
 MDC/MDIO management interface
 Flexible filters in PHY to reduce integrated LAN controller
power
 Smart speed operation for automatic speed reduction on
faulty cable plants
 PMA loopback capable (no echo cancel)
 802.1as/1588 conformance
 Power Optimizer Support
 Intel® Stable Image Platform Program (SIPP)
 Network proxy/ARP Offload support
 Up to 32 programmable filters
 No support for Gb/s half-duplex operation
```
```
Security & Manageability
 Intel® vPro support with appropriate Intel chipset
components
```
```
Performance
 Jumbo Frames (up to 9 kB)
 802.1Q & 802.1p
 Receive Side Scaling (RSS)
 Two Queues (Tx & Rx)
```
```
Power
 Ultra Low Power at cable disconnect (<1 mW) enables
platform support for connected standby
 Reduced power consumption during normal operation and
power down modes
 Integrated Intel® Auto Connect Battery Saver (ACBS)
 Single-pin LAN Disable for easier BIOS implementation
 Fully integrated Switching Voltage Regulator (iSVR)
 Low Power Link-Up (LPLU)
```
```
MAC/PHY Interconnect
 PCIe-based interface for active state operation (S0 state)
 SMBus-based interface for host and management traffic (Sx
low power state)
```
```
Package/Design
 48-pin package, 6 x 6 mm with a 0.4 mm lead pitch and an
Exposed Pad* for ground
 Three configurable LED outputs
 Integrated MDI interface termination resistors to reduce
BOM costs
 Reduced BOM cost by sharing SPI flash with PCH
```

LEGAL

No license (express or implied, by estoppel or otherwise) to any intellectual property rights is granted by this document.

Intel disclaims all express and implied warranties, including without limitation, the implied warranties of merchantability, fitness for a
particular purpose, and non-infringement, as well as any warranty arising from course of performance, course of dealing, or usage in
trade.

This document contains information on products, services and/or processes in development. All information provided here is subject
to change without notice. Contact your Intel representative to obtain the latest forecast, schedule, specifications and roadmaps.

The products and services described may contain defects or errors which may cause deviations from published specifications.

Copies of documents which have an order number and are referenced in this document may be obtained by calling 1-800-548-
or by visiting [http://www.intel.com/design/literature.htm.](http://www.intel.com/design/literature.htm.)

Intel and the Intel logo are trademarks of Intel Corporation in the U.S. and/or other countries.

* Other names and brands may be claimed as the property of others.

© 2015 Intel Corporation.


Revision History—Intel® Ethernet Connection I

Revision History

```
Revision Date Comments
```
```
2.02 May 2015 Updated title page.
```
```
2.01 April 2015
```
```
Revised sections:
```
- 10.3.1.
- 10.3.1.
Revised table 12-12, 12-13, 13-14, and 13-15.

```
2.0 February 2015 • Initial Release (Intel Public).^1
```
1. There have been no releases between revision 0.9 and revision 2.0.

```
0.9 January 2015
```
- Updated Title Page (General Product Features).
- Flexible Filters changed from 16 to 32 (Section 7.4.1.4.1.8).
- Added Non-Volatile Memory (NVM) map (Section 10.0).

```
0.7 July 2014
```
```
Revised sections:
```
- 11.2.
- 11.2.1.
- 11.
- 11.20.
- 11.20.
- 11.
- 11.
- 12.
- 12.
- 12.2.1.
- 12.21.
- 12.21.
- 12.

```
0.5 March 3, 2014 Initial release (Intel Confidential)
```

```
Intel® Ethernet Connection I219—Revision History
```
NOTE: This page intentionally left blank.


## Contents





- Contents—Intel® Ethernet Connection I
- 1.0 Introduction
   - 1.1 Overview .......................................................................................................................
   - 1.2 Main Flows .....................................................................................................................
   - 1.3 References .....................................................................................................................
- 2.0 Interconnects
   - 2.1 Introduction ...................................................................................................................
   - 2.2 PCIe-Based ....................................................................................................................
      - 2.2.1 PCIe Interface Signals .......................................................................................
      - 2.2.2 PCIe Operation and Channel Behavior ..................................................................
   - 2.3 SMBus ...........................................................................................................................
      - 2.3.1 Overview .........................................................................................................
      - 2.3.2 SMBus Pass Trough (PT) ....................................................................................
      - 2.3.3 Slave Transactions ............................................................................................
      - 2.3.4 Master Transactions ..........................................................................................
   - 2.4 Transitions Between SMBus and PCIe interfaces ..................................................................
      - 2.4.1 Switching from SMBus to PCIe ............................................................................
      - 2.4.2 Switching from PCIe to SMBus ............................................................................
- 3.0 Pin Interface
   - 3.1 Pin Assignment ...............................................................................................................
      - 3.1.1 Signal Type Definitions ......................................................................................
      - 3.1.2 PCIe Interface Pins (8).......................................................................................
      - 3.1.3 SMBus Interface Pins (2)....................................................................................
      - 3.1.4 Miscellaneous Pins (3) .......................................................................................
      - 3.1.5 PHY Pins (14) ...................................................................................................
      - 3.1.6 Testability Pins (5) ............................................................................................
      - 3.1.7 Power and Power Control Pins (16) ......................................................................
   - 3.2 Pinout ............................................................................................................................
- 4.0 Package
   - 4.1 Package Type and Mechanical ...........................................................................................
   - 4.2 Package Electrical and Thermal Characteristics ....................................................................
   - 4.3 Power and Ground Requirements .......................................................................................
   - 4.4 Ball Mapping ...................................................................................................................
- 5.0 Initialization
   - 5.1 Power Up .......................................................................................................................
   - 5.2 Reset Operation ..............................................................................................................
   - 5.3 Timing Parameters ..........................................................................................................
      - 5.3.1 Timing Requirements.........................................................................................
      - 5.3.2 Timing Guarantees ............................................................................................
- 6.0 Power Management and Delivery
   - 6.1 Power Information ...........................................................................................................
   - 6.2 Power Delivery ................................................................................................................
      - 6.2.1 Core Vdc Supply ...............................................................................................
   - 6.3 Power Management .........................................................................................................5
      - 6.3.1 Global Power States ..........................................................................................
   - 6.4 I219 Ultra Low Power (ULP) ..............................................................................................
   - 6.5 Off Board LAN Connected Device (OBLCD) ..........................................................................
      - 6.5.1 Indicating /Sensing OBLCD Disconnect Event ........................................................ Intel® Ethernet Connection I219—Contents
      - 6.5.2 Indicating/Sensing OBLCD Connection .................................................................
- 7.0 Device Functionality
   - 7.1 Tx Flow ..........................................................................................................................
   - 7.2 Rx Flow .........................................................................................................................
   - 7.3 Flow Control ...................................................................................................................
      - 7.3.1 MAC Control Frames and Reception of Flow Control Packets ....................................
      - 7.3.2 Transmitting PAUSE Frames ...............................................................................
   - 7.4 Wake Up ........................................................................................................................
      - 7.4.1 Host Wake Up...................................................................................................
      - 7.4.2 Management Engine (ME) Wake Up .....................................................................
   - 7.5 Network Proxy Functionality .............................................................................................
      - 7.5.1 Introduction .....................................................................................................
      - 7.5.2 Network Proxy Activation ...................................................................................
      - 7.5.3 IPv4 Proxy - ARP...............................................................................................
      - 7.5.4 IPv6 Proxy - Neighbor Discovery .........................................................................
      - 7.5.5 Multicast Listener Discovery Support....................................................................
   - 7.6 Loopback .......................................................................................................................
- 8.0 PHY Functionality
   - 8.1 Reverse Auto-Negotiation .................................................................................................8
- 9.0 Programmer’s Visible State
   - 9.1 Terminology ...................................................................................................................
   - 9.2 MDIO Access ..................................................................................................................
   - 9.3 Addressing .....................................................................................................................
   - 9.4 Registers Byte Ordering
   - 9.5 Register Definitions .........................................................................................................
      - 9.5.1 Address Map ....................................................................................................
      - 9.5.2 PHY Registers ...................................................................................................
      - 9.5.3 Port Control Registers......................................................................................
      - 9.5.4 Statistics Registers..........................................................................................
      - 9.5.5 PCIe Registers
      - 9.5.6 LPI Registers
      - 9.5.7 ULP Registers
      - 9.5.8 General Registers............................................................................................
      - 9.5.9 Wake Up Registers
      - 9.5.10 Proxy Controller uCode
      - 9.5.11 Host WoL Packet
      - 9.5.12 LPI MMD PHY Registers
- 10.0 Non-Volatile Memory (NVM) ..................................................................................
   - 10.1 Introduction
   - 10.2 NVM Programming Procedure Overview
   - 10.3 LAN NVM Format and Contents
      - 10.3.1 Hardware Accessed Words................................................................................
      - 10.3.2 Software Accessed Words.................................................................................
      - 10.3.3 Basic Configuration Software Words
- 11.0 Electrical and Timing Specifications ......................................................................
   - 11.1 Introduction
   - 11.2 Operating Conditions
      - 11.2.1 Absolute Maximum Ratings...............................................................................
- Contents—Intel® Ethernet Connection I
      - 11.2.2 Recommended Operating Conditions..................................................................
   - 11.3 Power Delivery
      - 11.3.1 Voltage Regulator Power Supply Specifications
      - 11.3.2 SVR Specification (Internal)..............................................................................
      - 11.3.3 Power On/Off Sequence
      - 11.3.4 Power Delivery Schematic Drawing
   - 11.4 I/O DC Parameter
      - 11.4.1 3.3 Vdc I/O (Open Drain)
      - 11.4.2 3.3 Vdc I/O
      - 11.4.3 Input Buffer Only
      - 11.4.4 PCIe DC/AC Specifications
   - 11.5 Discrete/Integrated Magnetics Specifications
   - 11.6 Mechanical
   - 11.7 Oscillator/Crystal Specifications
- 12.0 Mobile Design Considerations and Guidelines ........................................................
   - 12.1 I219 Overview
      - 12.1.1 I219 Interconnects..........................................................................................
      - 12.1.2 PCIe-Based Interface.......................................................................................
      - 12.1.3 SMBus Interface
      - 12.1.4 PCIe and SMBus Modes....................................................................................
      - 12.1.5 Transitions Between PCIe and SMBus Interfaces..................................................
   - 12.2 Platform LAN Design Guidelines
      - 12.2.1 General Design Considerations for the Intel® Ethernet Connection I219
      - 12.2.2 NVM for PHY Implementations
      - 12.2.3 LED...............................................................................................................
      - 12.2.4 Exposed Pad* (e-Pad) Design and SMT Assembly Guide
   - 12.3 PCH-SMBus/PCIe LOM Design Guidelines
   - 12.4 SMBus Design Considerations
   - 12.5 General Layout Guidelines
   - 12.6 Layout Considerations
   - 12.7 Guidelines for Component Placement
      - 12.7.1 PHY Placement Recommendations
   - 12.8 MDI Differential-Pair Trace Routing for LAN Design
   - 12.9 Signal Trace Geometry
   - 12.10 Trace Length and Symmetry
   - 12.11 Impedance Discontinuities
   - 12.12 Reducing Circuit Inductance
   - 12.13 Signal Isolation
   - 12.14 Power and Ground Planes
   - 12.15 Traces for Decoupling Capacitors
   - 12.16 Ground Planes Under a Magnetics Module
   - 12.17 Light Emitting Diodes
   - 12.18 Considerations for Layout
   - 12.19 Frequency Control Device Design Considerations
   - 12.20 Crystals and Oscillators
      - 12.20.1 Quartz Crystal
      - 12.20.2 Fixed Crystal Oscillator
      - 12.20.3 Crystal Selection Parameters
      - 12.20.4 Vibrational Mode
      - 12.20.5 Nominal Frequency..........................................................................................
      - 12.20.6 Frequency Tolerance Intel® Ethernet Connection I219—Contents
      - 12.20.7 Temperature Stability and Environmental Requirements
      - 12.20.8 Calibration Mode
      - 12.20.9 Load Capacitance
      - 12.20.10 Shunt Capacitance
      - 12.20.11 Equivalent Series Resistance
      - 12.20.12 Drive Level.....................................................................................................
      - 12.20.13 Aging
      - 12.20.14 Reference Crystal............................................................................................
      - 12.20.15 Oscillator Support
      - 12.20.16 Oscillator Placement and Layout Recommendations
   - 12.21 LAN Switch
   - 12.22 Troubleshooting Common Physical Layout Issues
   - 12.23 Power Delivery
   - 12.24 I219 Power Sequencing
- 13.0 Non-Mobile Design Considerations and Guidelines ................................................
   - 13.1 PHY Overview
      - 13.1.1 PHY Interconnects...........................................................................................
      - 13.1.2 PCIe-Based Interface.......................................................................................
      - 13.1.3 SMBus Interface
      - 13.1.4 PCIe and SMBus Modes....................................................................................
      - 13.1.5 Transitions Between PCIe and SMBus Interfaces..................................................
   - 13.2 Platform LAN Design Guidelines
      - 13.2.1 General Design Considerations for PHYs
      - 13.2.2 NVM for PHY Implementations
   - 13.3 LAN Switch
      - 13.3.1 LED...............................................................................................................
      - 13.3.2 Exposed Pad* (e-Pad) Design and SMT Assembly Guide
   - 13.4 PCH-SMBus/PCIe LOM Design Guidelines
   - 13.5 SMBus Design Considerations
   - 13.6 General Layout Guidelines
   - 13.7 Layout Considerations
   - 13.8 Guidelines for Component Placement
      - 13.8.1 PHY Placement Recommendations
   - 13.9 MDI Differential-Pair Trace Routing for LAN Design
   - 13.10 Signal Trace Geometry
   - 13.11 Trace Length and Symmetry
   - 13.12 Impedance Discontinuities
   - 13.13 Reducing Circuit Inductance
   - 13.14 Signal Isolation
   - 13.15 Power and Ground Planes
   - 13.16 Traces for Decoupling Capacitors
   - 13.17 Ground Planes Under a Magnetics Module
   - 13.18 Light Emitting Diodes
   - 13.19 Considerations for Layout
   - 13.20 Frequency Control Device Design Considerations
   - 13.21 Crystals and Oscillators
      - 13.21.1 Quartz Crystal
      - 13.21.2 Fixed Crystal Oscillator
      - 13.21.3 Crystal Selection Parameters
- Contents—Intel® Ethernet Connection I
      - 13.21.4 Vibrational Mode
      - 13.21.5 Nominal Frequency..........................................................................................
      - 13.21.6 Frequency Tolerance
      - 13.21.7 Temperature Stability and Environmental Requirements
      - 13.21.8 Calibration Mode
      - 13.21.9 Load Capacitance
      - 13.21.10 Shunt Capacitance
      - 13.21.11 Equivalent Series Resistance.............................................................................
      - 13.21.12 Drive Level.....................................................................................................
      - 13.21.13 Aging
      - 13.21.14 Reference Crystal............................................................................................
      - 13.21.15 Oscillator Support
      - 13.21.16 Oscillator Placement and Layout Recommendations
   - 13.22 Troubleshooting Common Physical Layout Issues
   - 13.23 Power Delivery
   - 13.24 I219 Power Sequencing


```
Intel® Ethernet Connection I219—Contents
```
NOTE: This page intentionally left blank.


Introduction—Intel® Ethernet Connection I

## 1.0 Introduction

### 1.1 Overview .......................................................................................................................

The Intel

##### ®

Ethernet Connect I219 (I219) is a single-port Gigabit Ethernet Physical Layer Transceiver

(PHY). It connects to an integrated Media Access Controller (MAC) through a dedicated interconnect.

The I219 supports operation at 10/100/1000 Mb/s data rates. The PHY circuitry provides a standard

IEEE 802.3 Ethernet interface for 10BASE-T, 100BASE-TX, and 1000BASE-T applications (802.3,

802.3u, and 802.3ab). The I219 also supports the Energy Efficient Ethernet (EEE) 802.az specification.

The I219 is packaged in a small footprint QFN package. Package size is 6 x 6 mm with a 0.4 mm lead

pitch and a height of 0.85 mm, making it very attractive for small form-factor platforms.

The I219 interfaces with its MAC through two interfaces: PCIe-based and SMBus. The PCIe (main)

interface is used for all link speeds when the system is in an active state (S0) while the SMBus is used

only when the system is in a low power state (Sx). In SMBus mode, the link speed is reduced to 10 Mb/

s (dependent on low power options). The PCIe interface incorporates two aspects: a PCIe SerDes

(electrically) and a custom logic protocol.

Note: The I219 PCIe interface is not PCIe compliant. It operates at half of the PCI Express*

```
(PCIe*) Specification v1.1 (2.5 GT/s) speed. In this datasheet the term PCIe-based is
interchangeable with PCIe. There is no design layout differences between normal PCIe and
the I219’s PCIe-based interface.
```
Figure 1-1 I219 Block Diagram

I


```
Intel® Ethernet Connection I219—Introduction
```
### 1.2 Main Flows .....................................................................................................................

The I219 main interfaces are PCIe and SMBus on the host side and the MDI interface on the link side.

Transmit traffic is received from the MAC device through either PCIe or SMBus on the host interconnect

and then transmitted on the MDI link. Receive traffic arrives on the MDI link and transferred to the

integrated LAN controller through either the PCIe or SMBus interconnects.

The integrated LAN controller and system software control I219 functionality through two mechanisms:

- The I219 configuration registers are mapped into the MDIO space and can be accessed by the
    integrated LAN controller through the PCIe or SMBus interconnects.
- The MDIO traffic is embedded in specific fields in SMBus packets or carried by special packets over
    the PCIe encoded interconnect as defined by the custom protocol.

Specific flows are described in other sections of this document:

- The power-up flow is described in Section 5.1.
- Reset flows are described in Section 5.2.
- Power delivery options are described in Section 6.2.
- Power management is described in Section 6.3.

### 1.3 References .....................................................................................................................

- Information Technology - Telecommunication & Information Exchange Between Systems - LAN/MAN
    - Specific Requirements - Part 3: Carrier Sense Multiple Access with Collision Detection (CSMA/CD)
    Access Method and Physical Layer Specifications, IEEE Standard No.: 802.3-2008.
- Intel

##### ®

Ethernet Controllers Loopback Modes, Intel Corporation

- Energy Efficient Ethernet (EEE) 802.az specification.
- SMBus specification revision 2.0.


Interconnects—Intel® Ethernet Connection I

## 2.0 Interconnects

### 2.1 Introduction ...................................................................................................................

The I219 implements two interconnects to the integrated LAN controller:

- PCIe — A high-speed SerDes interface using PCIe electrical signaling at half speed while keeping
    the custom logical protocol for active state operation mode.
- System Management Bus (SMBus) — A very low speed connection for low power state mode for
    manageability communication only. At this low power state mode the Ethernet link speed is reduced
    to 10 Mb/s.

The I219 automatically switches the in-band traffic between PCIe and SMBus based on the system

power state.

### 2.2 PCIe-Based ....................................................................................................................

Note: The I219 PCIe interface is not PCIe compliant. It operates at half of the PCI Express*

```
(PCIe*) Specification v1.1 (2.5 GT/s) speed. In this document the term PCIe-based is
interchangeable with PCIe. There are no design layout differences between normal PCIe
and the LAN-connected device’s (LCD) PCIe-based interface. Standard PCIe validation tools
cannot be used to validate this interface. Refer to Section 11.4.4 for PCIe-based
specifications.
```
Table 2-1 I219 Interconnect Modes

```
System
```
```
LAN Connected Device
```
```
SMBus PCIe
```
```
S0 and PHY Power Down Not Used Idle
```
```
S0 and Idle or Link Discovery Not Used Idle
```
```
S0 and Link in Low Power Idle (LPI) Not Used Idle
```
```
S0 and active Not Used Active
```
```
Sx Active Power-down
```
```
Sx and DMoff Active Power-down
```

```
Intel® Ethernet Connection I219—Interconnects
```
#### 2.2.1 PCIe Interface Signals .......................................................................................

The signals used to connect between the integrated LAN Controller and the PHY in this mode are:

- Serial differential pair running at 1.25 Gb/s for Rx.
- Serial differential pair running at 1.25 Gb/s for Tx.
- 100 MHz differential clock input to the PHY running at 100 MHz.
- Power and clock good indication to the PHY PE_RSTn.
- Clock control through CLKREQn.

#### 2.2.2 PCIe Operation and Channel Behavior ..................................................................

The I219 only runs at 1250 Mb/s KX (PCIe-based) speed, which is half of the gen1 2.5 Gb/s PCIe

frequency. To operate with KX only devices, each of the PCIe root ports in the PCH-integrated MAC have

the ability to run at the KX rate. There is no need to implement a mechanism to detect that a KX only

device is attached. The port configuration (if any), attached to a KX only device, is pre-loaded from

NVM. The selected port adjusts the transmitter to run at the KX rate and does not need to be PCIe

compliant.

Packets transmitted and received over the PCIe interface are full Ethernet packets and not PCIe

transaction/link/physical layer packets.

After the PCIe power-up sequence completes, each transmitter starts transmitting idle symbols and the

receiver acquires synchronization as specified in 802.3z.

2.2.2.1 PCIe In-Band Messages

In-band messages are used to transfer control information between the I219 and the integrated LAN

Controller. The I219 only initiates PHY status in-bands and then waits for an acknowledgment. For each

in-band message on PCIe, there is an equivalent message on the SMBus. As a result, if an interface

switch took place before an acknowledgment was received, the equivalent message is sent on the other

interface.


Interconnects—Intel® Ethernet Connection I

2.2.2.1.1 MDIO Access Packet Transmitted by Integrated LAN

Controller

This in-band message is equivalent to the MtP Configuration command on the SMBus.

2.2.2.1.2 MDIO Access Acknowledge/Response Packet

Transmitted by PHY

This in-band message is equivalent to the PtM Configuration Acknowledge command on the SMBus.

```
Byte Description
```
```
Special MDIO Symbol /K28.1/
```
```
Register Address and Controls Bits 4:0 = Register address
Bit 5:
0b = Read access
1b = Write access
Bit 6:
0b = Command
Bit 7:
0b = MDIO register
```
```
1st Data Byte MSB data byte if write. Must be 0b if read.
```
```
2nd Data Byte LSB data byte if write. Must be 0b if read.
```
```
PHY Address Bits 4:0 = PHY address
Bits 7:5 = Reserved (0b)
```
```
CRC-8 Byte CRC of in-band packet excluding the K28.1 special symbol.
```
```
Byte Description
```
```
Special MDIO Symbol /K28.1/
```
```
Register Address and Controls Bits 4:0 = Register address
Bit 5:
0b = Read access
1b = Write access
Bit 6:
1b = Acknowledge
Bit 7:
0b = MDIO register
```
```
1st Data Byte Data MSB.
```
```
2nd Data Byte Data LSB.
```
```
Reserved Byte Reserved byte (must be 0b).
```
```
CRC-8 Byte CRC of in-band packet excluding the K28.1 special symbol.
```

```
Intel® Ethernet Connection I219—Interconnects
```
2.2.2.1.3 Status Packet from PHY

This in-band message is equivalent to the PtM PHY Status command on the SMBus. The status

command is sent by the I219 on every status change at the PHY side or when a timeout defined in the

In-Band Control register has expired. The I219 re-transmits the Status command if no acknowledge

arrived after a time out defined in the PCIe Diagnostic register has expired.

```
Byte Description
```
```
Special MDIO Symbol /K28.1/
```
```
Register Address and Controls Bits 5:0 = Reserved (must be 0x0)
Bit 6 = 0b
Bit 7:
1b = Status
```
```
1st Data Byte Bit 0 = K1 entry request
Bit 1 = TX Off (MAC back pressure required)
Bit 2 = EI entry request
Bit 3 = Reserved (must be 0b)
Bit 4 = Reserved
Bit 5 = Inband Host WoL indication
Bits 7:6 = Reserved (must be 0x0)
```
```
2nd Data Byte Bits 1:0 = Speed:
00b = 10 Mb/s
01b = 100 Mb/s
10b = 1000 Mb/s
11b = Reserved
Bit 2 = Duplex mode:
0b = Half duplex
1b = Full duplex
Bit 3 = PHY Link status:
0b = Link down
1b = Link up
Bit 4 = PHY cable disconnected
Bit 5 = GLCI link status:
0b = Link down
1b = Link up
Bit 6 = Interrupt request (Not used)
Bit 7 = Reset complete
```
```
Reserved Byte Reserved byte (must be 0b).
```
```
CRC-8 Byte CRC of in-band packet excluding the K28.1 special symbol.
```

Interconnects—Intel® Ethernet Connection I

2.2.2.1.4 Acknowledge Packet from the Integrated LAN

Controller

This in-band message is equivalent to the MtP PHY Status Acknowledge command on the SMBus.

```
Byte Description
```
```
Special MDIO Symbol /K28.1/
```
```
Register Address and Controls Bits 5:0 = Reserved (must be 0x0)
Bit 6:
1b = Acknowledge
Bit 7:
1b = Status
```
```
1st Data Byte Bit 0 = K1 entry request
Bit 1 = TX Off (MAC back pressure required)
Bit 2 = EI entry request
Bit 3 = Reserved (must be 0b)
Bit 4 = Reserved
Bit 5 = Inband Host WoL indication
Bits 7:6 = Reserved (must be 0x0)
```
```
2nd Data Byte Bits 1:0 =Speed:
00b = 10 Mb/s
01b = 100 Mb/s
10b = 1000 Mb/s
11b = Reserved
Bit 2 = Duplex mode:
0b = Half duplex
1b = Full duplex
Bit 3 = PHY Link status:
0b = Link down
1b = Link up
Bit 4 = PHY cable disconnected
Bit 5 = GLCI link status:
0b = Link down
1b = Link up
Bit 6 = Interrupt request (Not used)
Bit 7 = Reset complete
```
```
Reserved Byte Reserved byte (must be 0b).
```
```
CRC-8 Byte CRC of in-band packet excluding the K28.1 special symbol.
```

```
Intel® Ethernet Connection I219—Interconnects
```
2.2.2.1.5 Status Packet from the Integrated LAN Controller

This in-band message is equivalent to the MtP Control command on the SMBus.

2.2.2.1.6 Acknowledge Packet from the PHY

```
Byte Description
```
```
Special MDIO Symbol /K28.1/
```
```
Register Address and Controls Bits 5:0 = Reserved (must be 0x0)
Bit 6 = 0b
Bit 7:
1b = Status
```
```
1st Data Byte Bit 0 = K1 entry request
Bit 1 = XOFF request
Bit 2 = EI entry request
Bit 3 = XON request
Bits 5:4 = Reserved
Bits 7:6 = Reserved (must be 0x0)
```
```
2nd Data Byte Bits 3:0 = MAC LED Status (not used).
Bits 5:4 = Power saving D-states.
Bit 6 = Power down.
Bit 7 = Port Reset.
```
```
Reserved Byte Reserved byte (must be 0b).
```
```
CRC-8 Byte CRC of in-band packet excluding the K28.1 special symbol.
```
```
Byte Description
```
```
Special MDIO Symbol /K28.1/
```
```
Register Address and Controls Bits 5:0 = Reserved (must be 0x0)
Bit 6:
1b = Acknowledge
Bit 7:
1b = Status
```
```
1st Data Byte Bit 7:0 = Reserved (must be 0x0)
```
```
2nd Data Byte Bit 7:0 = Reserved (must be 0x0)
```
```
Reserved Byte Reserved byte (must be 0b).
```
```
CRC-8 Byte CRC of in-band packet excluding the K28.1 special symbol.
```

Interconnects—Intel® Ethernet Connection I

### 2.3 SMBus ...........................................................................................................................

#### 2.3.1 Overview .........................................................................................................

SMBus is a low speed (100 kHz/400 kHz/1000 kHz) serial bus used to connect various components in a

system. SMBus is used as an interface to pass traffic between the I219 and the integrated LAN

Controller when the system is in a low power Sx state. The interface is also used to enable the

integrated LAN Controller to configure the I219 as well as passing in-band information between them.

The SMBus uses two primary signals to communicate: SMBCLK and SMBDAT. Both of these signals are

open drain with board-level pull-ups.

The SMBus protocol includes various types of message protocols composed of individual bytes. The

message protocols supported by the I219 are described in the relevant sections.

For further details on SMBus behavior, refer to the SMBus specification.

2.3.1.1 SMBus Channel Behavior

The SMBus specification defines the maximum frequency of the SMBus as 100 kHz or 1000 kHz. When

operating at 1000 kHz, the SMBus specification parameters are defined by the I

##### 2

C specification.

To change the I219’s SMBus frequency to 1000 kHz, bit 12,8 in the SMBus Address register (register

26, address 01, page 0) should be set to 10b. For details, refer to Section 9.5.8.3.

2.3.1.2 SMBus Addressing

The I219’s address is assigned using SMBus ARP protocol. The default SMBus address is 0xC8.

2.3.1.3 Bus Time Outs

The I219 can detect (as a master or a slave) an SMBCLK time out on the main SMBus. If the SMBus

clock line is held low for less than 25 ms, the I219 does not abort the transaction. If the SMBus clock

line is held low for 25 ms or longer, the I219 aborts the transaction.

As a slave, the I219 detects the time out and goes into an idle state. In idle, the slave releases the

SMB_CLK and SMB_DATA lines. Any data that was received before the time out might have been

processed depending on the transaction.

As a master, the I219 detects a time out and issues a STOP on the SMBus at the next convenient

opportunity and then brings the SMBus back to idle (releases SMB_CLK and SMB_DATA). Any master

transaction that the I219 detects a time out on, is aborted.


```
Intel® Ethernet Connection I219—Interconnects
```
2.3.1.4 Bus Hangs

Although uncommon, SMBus bus hangs can happen in a system. The catalyst for the hang is typically

an unexpected, asynchronous reset or noise coupled onto the SMBus. Slaves can contribute to SMBus

hangs by not implementing the SMBus time outs as specified in SMBus 2.0 specification. Masters or

host masters can contribute to SMBus hangs by not detecting the failures and by not attempting to

correct the bus hangs.

Because of the potential bus hang scenario, the I219 has the capability of detecting a hung bus. If

SMB_CLK or SMB_DATA are stuck low for more than 35 ms, the I219 forces the bus to idle (both

SMB_CLK and SMB_DATA set), if it is the cause of the bus hang.

2.3.1.5 Packet Error Code (PEC) Support

PEC is defined in the SMBus 2.0 specification. It is an extra byte at the end of the SMBus transaction,

which is a CRC-8 calculated on all of the preceding bytes (not including ACKs, NACKs, STARTs, or

STOPs) in the SMBus transaction. The polynomial for this CRC-8 is:

x8 + x2 + x + 1

The PEC calculation is reset when any of the following occurs:

- A STOP condition is detected on the host SMBus.
- An SMBus hang is detected on the host SMBus.
- The SMBCLK is detected high for ~50 s.

2.3.1.6 SMBus ARP Functionality

The I219 supports the SMBus ARP protocol as defined in the SMBus 2.0 specification. The I219 is a

persistent slave address device, meaning its SMBus address is valid after power up (constant 0xC8).

The I219 supports all SMBus ARP commands defined in the SMBus specification, both general and

directed.

2.3.1.6.1 SMBus ARP Flow

SMBus ARP flow is based on the status of two flags:

- AV (Address Valid) — This flag is set when the I219 has a valid SMBus address.\
- AR (Address Resolved) — This flag is set when the I219 SMBus address is resolved (SMBus address
    was assigned by the SMBus ARP process).

Note: These flags are internal I219 flags and are not shown to external SMBus devices.

Since the I219 is a Persistent SMBus Address (PSA) device, the AV flag is always set, while the AR flag

is cleared after power up until the SMBus ARP process completes. Since AV is always set, it means that

the I219 always has a valid SMBus address.

When the SMBus master wants to start a SMBus ARP process, it resets (in terms of ARP functionality)

all the devices on the SMBus by issuing either Prepare to ARP or Reset Device commands. When the

I219 accepts one of these commands, it clears its AR flag (if set from previous SMBus ARP process), but

not its AV flag; the current SMBus address remains valid until the end of the SMBus ARP process.


Interconnects—Intel® Ethernet Connection I219

With the AR flag cleared, the I219 answers the following SMBus ARP transactions that are issued by the

master. The SMBus master then issues a Get UDID command (General or Directed) to identify the

devices on the SMBus. The I219 responds to the Directed command every time and to the General

command only if its AR flag is not set. After a Get UDID command, the master assigns the I219 an

SMBus address by issuing an Assign Address command. The I219 checks whether the UDID matches its

own UDID and if matched, switches its SMBus address to the address assigned by the command (byte

17). After accepting the Assign Address command, the AR flag is set, and from this point on (as long as

the AR flag is set) the I219 does not respond to the Get UDID General command, while all other

commands should be processed even if the AR flag is set. Figure 2 shows the SMBus ARP behavior of

the I219.

Figure 2-1 SMBus ARP Flow


```
Intel® Ethernet Connection I219—Interconnects
```
2.3.1.6.2 SMBus ARP UDID Content

The Unique Device Identifier (UDID) provides a mechanism to isolate each device for the purpose of

address assignment. Each device has a unique identifier. The 128-bit number is comprised of the

following fields:

Where:

- Vendor ID — The device manufacturer's ID as assigned by the SBS Implementer’s' Forum or the
    PCI SIG. Constant value: 0x8086.
- Device ID — The device ID as assigned by the device manufacturer (identified by the Vendor ID
    field). value for the LAN Connected device is constant: 0x10D4.
- Interface — Identifies the protocol layer interfaces supported over the SMBus connection by the
    device (in this case, SMBus Version 2.0). Constant value: 0x0004.
- Subsystem Fields — These fields are not supported and return zeros.
- Device Capabilities — Dynamic and persistent address, PEC support bit:
- Version/Revision — UDID Version 1, Silicon Revision:
- Silicon Revision ID:

```
1 Byte 1 Byte 2 Bytes 2 Bytes 2 Bytes 2 Bytes 2 Bytes 4 Bytes
```
```
Device
Capabilities
```
```
Version/
Revision
Vendor ID Device ID Interface
Subsystem
Vendor ID
```
```
Subsystem
Device ID
```
```
Vendor
Specific ID
```
```
See below See below 0x8086 0x10D4 0x0004 0x0000 0x0000 See below
```
```
MSB LSB
```
##### 76543210

```
Address Type Reserved Reserved Reserved Reserved Reserved
```
##### PEC

```
Supported
```
```
0b 1b 0b 0b 0b 0b 0b 1b
```
```
MSB LSB
```
##### 76543210

```
Reserved Reserved UDID Version Silicon Revision ID
```
```
0b 0b 001b See below
```
```
MSB LSB
```
```
Silicon Version Revision ID
```
```
A0 000b
```

Interconnects—Intel® Ethernet Connection I219

- Vendor Specific ID — Four bytes - constant 0x44332211:

2.3.1.7 SMBus ARP Transactions

All SMBus ARP transactions include a PEC byte. For the layout of these transactions refer to the SMBus

2.0 specification.

Supported SMBus ARP transactions:

- Prepare to ARP
- Reset Device (General and Directed)
- Assign Address
- Get UDID (General and Directed)

#### 2.3.2 SMBus Pass Trough (PT) ....................................................................................

This section describes the SMBus transactions supported as PT between the integrated LAN Controller

and the I219. All traffic between the I219 and the integrated LAN Controller is in network order (the

MSB is sent first).

2.3.2.1 Receive Flow

The maximum SMBus fragment length is configurable and can either be 32 bytes or 64 bytes. The

default value is 32 bytes. The incoming packets are divided into fragments, where the I219 uses the

maximum fragment size allowed in each fragment. The data of the packet is transferred using the

Receive TCO packet transaction as described in Section 2.3.4.1.1.

Any time out on the SMBus results in discarding the entire packet. Any NACK by the integrated LAN

Controller on one of the I219 receive bytes causes the packet to be retransmitted up to four times. If

after four times the packet fails to be transmitted, it is silently discarded.

The maximum size of the received packet is limited by the I219 hardware to 1522 bytes. Packets larger

then 1522 bytes are silently discarded.

```
1 Byte 1 Byte 1 Byte 1 Byte
```
```
44 33 22 1x^1
```
1. Bit 0 value is defined by the value sampled at reset on GPIO[0]

##### MSB LSB


```
Intel® Ethernet Connection I219—Interconnects
```
2.3.2.2 Transmit Flow

The I219 is used as a channel for transmitting packets from the integrated LAN Controller to the

network link. The network packet is transferred from the integrated LAN Controller over the SMBus

(starting with a preamble), and then, when fully received by the I219, it is transmitted over the

network link.

The I219 supports packets up to an Ethernet packet length of 1522 bytes. SMBus transactions are

configurable up to a 64-byte length, which means that packets can be transferred over the SMBus in

more than one fragment. Fragments within a packet are marked with the F and L flags. The I219 does

not change any field in the transmitted packet. A packet bigger than 1522 bytes is silently discarded by

the integrated LAN Controller and not sent to the I219.

If the network link is down when the I219 is receiving SMBus fragments of the packet, it silently

discards the packet. The transmit SMBus transaction is described in Section 2.3.3.1.1.

2.3.2.2.1 Transmit Errors in Sequence Handling

Once a packet is transferred over the SMBus from the integrated LAN Controller to the I219, the F and

L flag should follow specific rules. The F flag defines that this is the first fragment of the packet, and the

L flag defines that the transaction contains the last fragment of the packet.

Note: Since every other Block Write command in the messaging protocol has both first and last

```
flags off, they cause flushing any pending transmit fragments that were previously
received. In other words, when running the transmit flow, no other Block Write transactions
are allowed in between the fragments.
```
2.3.2.3 Concurrent SMBus Transactions

Concurrent SMBus transactions (receive, transmit and configuration read/write) on opposite directions

are allowed and there is no limitation for it. Transmit fragments can be sent between receive fragments

and configuration Read/Write commands. Acknowledges can also be issued between receive and

transmit fragments in the opposite direction.

Table 2-2 Flag Options in Transmit Packet Transactions

```
Previous Current Action/Notes
```
```
Last First Accept both.
```
```
Last Not First
```
```
Error for current transaction.
All fragments, until one with the F flag set, are discarded, unless the current fragment is a
Single.
```
```
Not Last First
```
```
Error for the previous transaction.
Previous packet is sent with a bad CRC. No abort status is asserted, unless the previous
fragment is a Single.
```
```
Not Last Not First
```
```
Process the current transaction.
In case of Single after Middle error for the previous transaction and process the current
transaction.
```

Interconnects—Intel® Ethernet Connection I219

#### 2.3.3 Slave Transactions ............................................................................................

2.3.3.1 SMBus Transactions (Integrated LAN Controller

to the I219)

Table 2-3 lists the slave SMBus transactions supported by the I219.

2.3.3.1.1 Transmit Packet Command

The transmit packet fragments have the following format:

If the overall packet length is bigger than 1522 bytes, the packet is silently discarded by the integrated

LAN Controller.

Table 2-3 SMBus Slave Transactions

```
Command Transaction Command Fragmentation Section
```
```
Transmit Packet Block Write
```
```
First
Middle
Last
Single
```
```
0x84
0x04
0x44
0xC4
```
```
Multiple
Multiple
Multiple
Single
```
```
Table 2.3.3.1.1
```
```
MtP Control Block Write Single 0xC3 Single Table 2.3.3.1.2
```
```
MtP Status Acknowledge Block Write Single 0xC3 Single Table 2.3.3.1.3
```
```
MtP Configuration Block Write Single 0xC3 Single Table 2.3.3.1.4
```
```
Function Command Byte Count Data 1 ... Data N
```
```
Transmit first fragment 0x84
```
```
N Packet Data MSB ... Packet Data LSB
```
```
Transmit middle fragment 0x04
```
```
Transmit last fragment 0x44
```
```
Transmit single fragment 0xC4
```

```
Intel® Ethernet Connection I219—Interconnects
```
2.3.3.1.2 MtP Control Command

The MtP Control command is a single fragment command enabling the integrated LAN Controller to

send messages to the I219 informing status changes or sending directed control commands (not

through registers).

MtP Control Command Format:

Address and Control:

Command 1st Byte:

Command 2nd Byte:

```
Function Command Byte Count Data 1 Data 2 Data 3 Data 4
```
```
Control 0xC3 4
Address and
Control
```
```
Command
1st Byte
```
```
Command
2nd Byte
Reserved
```
```
Field Bit(s) Description
```
```
Reserved 5:0 Reserved.
Must be set to 0x0.
```
```
CMD_ACK 6 Command/acknowledge indication.
This bit should be set to 0b indicating command.
```
```
CFG_CTL 7 Configuration/control indication.
This bit should be set to 1b indicating control/status.
```
```
Field Bit(s) Description
```
```
Reserved 7:0 Reserved.
```
```
Field Bit(s) Description
```
```
PINSTOP 0 Clear the LANWAKE# pin indication.
```
```
Reserved 5:1 Reserved.
```
```
PWDN 6 Power down.
```
```
RST 7 Port reset.
```

Interconnects—Intel® Ethernet Connection I219

2.3.3.1.3 MtP PHY Status Acknowledge Command

The MtP PHY Status Acknowledge command is a single fragment command sent by the integrated LAN

Controller as an acknowledge to the I219’s PtM Status Command.

MtP Status Command Format:

Address and Control:

PHY Status 1st Byte:

PHY Status 2nd Byte:

```
Function Command Byte Count Data 1 Data 2 Data 3 Data 4
```
```
Status 0xC3 4
Address and
Control
```
```
PHY Status
1st Byte
```
```
PHY Status
2nd Byte
Reserved
```
```
Field Bit(s) Description
```
```
Reserved 5:0 Reserved.
Must be set to 0x0.
```
```
CMD_ACK 6 Command/acknowledge indication.
This bit should be set to 1b indicating acknowledge.
```
```
CFG_CTL 7 Configuration/control indication.
This bit should be set to 1b indicating control/status.
```
```
Field Bit(s) Description
```
```
Reserved 4:0 Reserved.
```
```
Host WoL 5 Inband Host WoL indication.
```
```
Reserved 7:6 Reserved.
```
```
Field Bit(s) Description
```
```
SPD 1:0 Ethernet Link Speed:
00b = 10 Mb/s
01b = 100 Mb/s
10b = 1000 Mb/s
11b = Reserved
```
```
DPX 2 Duplex Mode:
0b = Half duplex
1b = Full Duplex
```
```
ELINK 3 Ethernet Link Status:
0b = Link down
1b = Link up
```

```
Intel® Ethernet Connection I219—Interconnects
```
2.3.3.1.4 MtP Configuration Command

The Configuration command is a single fragment command enabling the integrated LAN Controller

access to all I219 registers over the SMBus link.

MtP Configuration Command Format:

Address and Control:

```
CDIS 4 Ethernet cable disconnected.
```
```
Reserved (KLINK) 5 PCIe link status (not used).
```
```
Reserved (INT) 6 Interrupt request (not used).
```
```
RSTC 7 Reset complete.
```
```
Function Command Byte Count Data 1 Data 2 Data 3 Data 4
```
```
Configuration 0xC3 4
Address and
Control
MSB Data LSB Data Reserved^1
```
1. Bits 7:5

```
PHY Address
```
```
Field Bit(s) Description
```
```
Add 4:0 Register address.
```
```
RW 5 Read/Write indication:
0b = Indicates read access.
1b = Indicates write access.
```
```
CMD_ACK 6 Command/acknowledge indication.
This bit should be set to 0b indicating Command.
```
```
CFG_CTL 7 Configuration/control indication.
This bit should be set to 0b indicating configuration.
```
```
Field Bit(s) Description
```

Interconnects—Intel® Ethernet Connection I219

#### 2.3.4 Master Transactions ..........................................................................................

2.3.4.1 SMBus Transactions (I219 to the integrated

LAN Controller)

To avoid starvation on the SMBus in the opposite direction, the I219 adds a byte-time idle between any

two fragments it sends.

Table 2-4 lists the master SMBus transactions supported by the I219.

2.3.4.1.1 Receive Packet Transaction

When the I219 has a packet to deliver to the integrated LAN Controller, it should begin issuing Receive

packet transaction commands using the Block Write protocol. The packet can be delivered in more than

one SMBus fragment, and the integrated LAN Controller should follow the fragments order.

The opcode can have these values:

- 0x90 - First fragment
- 0x10 - Middle fragment
- 0x50 - Last fragment of the packet
- 0xD0 - Single fragment packet

The receive packet fragments have the following format:

Table 2-4 SMBus Master Transactions

```
Command Transaction Command Fragmentation Section
```
```
Receive Packet Block Write
```
```
First
Middle
Last
Single
```
```
0x90
0x10
0x50
0xD0
```
```
Multiple
Multiple
Multiple
Single
```
```
Table 2.3.4.1.1
```
```
PtM Status Block Write Single 0xD3 Single Table 2.3.4.1.2
```
```
PtM Configuration Acknowledge Block Write Single 0xD3 Single Table 2.3.4.1.3
```
```
PtM WU Block Write Single 0xD5 Single Table 2.3.4.1.4
```
```
Function Byte Count Data 1 (Op-Code) Data 12 ... Data N
```
```
Receive TCO first fragment
```
##### N

##### 90

```
Packet Data Byte ... Packet Data Byte
```
```
Receive TCO middle fragment 10
```
```
Receive TCO last fragment 50
```
```
Receive TCO single fragment D0
```

```
Intel® Ethernet Connection I219—Interconnects
```
2.3.4.1.2 PtM Status Command

The PtM Status command is a single fragment command sent by the I219 on every status change at the

PHY side, or when a time out defined in the In-Band Control register has expired. The I219 re-transmits

the Status command if no acknowledge arrived after a time out defined in the PCIe Diagnostic register

has expired. If after 32 retries no acknowledge arrived, the I219 aborts this command and continues

with the next operation.

PtM Control Command Format:

Address and Control:

PHY Status 1st Byte:

```
Function Command Byte Count Data 1 Data 2 Data 3 Data 4
```
```
Status 0xD3 4
Address and
Control
```
```
PHY Status
1st Byte
```
```
PHY Status
2nd Byte
Reserved
```
```
Field Bit(s) Description
```
```
Reserved 5:0 Reserved.
Must be set to 0x0.
```
```
CMD_ACK 6 Command/acknowledge indication.
This bit should be set to 0b indicating command.
```
```
CFG_CTL 7 Configuration/control indication.
This bit should be set to 1b indicating control/status.
```
```
Field Bit(s) Description
```
```
Reserved 0 Reserved.
Must be st to 0b.
```
```
Reserved 1 Reserved.
```
```
Reserved 3:2 Reserved.
Must be set to 0x0.
```
```
Reserved 4 Reserved.
```
```
Host WoL 5 Host WoL indication.
```
```
Reserved Reserved.
Must be set to 0x0.
```

Interconnects—Intel® Ethernet Connection I219

PHY Status 2nd Byte:

```
Field Bit(s) Description
```
```
SPD 1:0 Ethernet Link Speed:
00b = 10 Mb/s
01b = 100 Mb/s
10b = 1000 Mb/s
11b = Reserved
```
```
DPX 2 Duplex Mode:
0b = Half duplex
1b = Full Duplex
```
```
ELINK 3 Ethernet Link Status:
0b = Link down
1b = Link up
```
```
CDIS 4 Ethernet cable disconnected.
```
```
Reserved (KLINK) 5 PCIe link status (not used).
```
```
Reserved (INT) 6 Interrupt request (not used).
```
```
RSTC 7 Reset complete.
```

```
Intel® Ethernet Connection I219—Interconnects
```
2.3.4.1.3 PtM Configuration Acknowledge Command

The Configuration Acknowledge command is a single fragment command enabling the I219 to

acknowledge the integrated LAN Controller access to I219 registers over the SMBus link.

MtP Configuration Command Format:

Address and Control:

2.3.4.1.4 PtM Wake Up Message

The host and Manageability Engine (ME) wake up message is a single fragment message indicating to

the integrated LAN Controller that the PHY received a wake up packet/event that should cause both the

host and ME to wake up.

Host and ME Wake Up Message Format:

Wake Up Control:

```
Function Command Byte Count Data 1 Data 2 Data 3 Data 4
```
```
Configuration 0xD3 4
Address and
Control
MSB Data LSB Data Reserved^1
```
1. Bits 7:5

```
PHY Address
```
```
Field Bit(s) Description
```
```
Add 4:0 Register address.
```
```
RW 5 Read/Write indication:
0b = Indicates read acknowledge.
1b = Indicates write acknowledge.
```
```
CMD_ACK 6 Command/acknowledge indication.
This bit should be set to 1b indicating Acknowledge.
```
```
CFG_CTL 7 Configuration/control indication.
This bit should be set to 0b indicating configuration.
```
```
Function Command Byte Count Data 1
```
```
Wake Up 0xD5 1 Wake Up Control
```
```
Field Bit(s) Description
```
```
Host Wake Up 0 Host wakeup indication.
```
```
ME Wake Up 1 ME wakeup indication.
```
```
Reserved 7:2 Reserved.
```

Interconnects—Intel® Ethernet Connection I219

### 2.4 Transitions Between SMBus and PCIe interfaces ..................................................................

#### 2.4.1 Switching from SMBus to PCIe ............................................................................

Communication between the integrated LAN Controller and the I219 is done through the SMBus each

time the system is in a low power state (Sx); PE_RST_N signal is low. The integrated LAN Controller/

PHY interface is needed while the ME is still active or to enable host wake up from the I219.

Possible states for activity over the SMBus:

- After power on (G3 to S5).
- On system standby (Sx).

While in this state, the SMBus is used to transfer traffic, configuration, control and status between the

ME through the integrated LAN Controller and the I219.

The switching from the SMBus to PCIe is done when the PE_RSTn signal is high.

- Any transmit/receive packet that is not completed when PE_RSTn is asserted is discarded.
- Any in-band message that was sent over the SMBus and was not acknowledged is re-transmitted
    over PCIe.

#### 2.4.2 Switching from PCIe to SMBus ............................................................................

The communication between the integrated LAN Controller and the I219 is done through PCIe each

time the system is in active power state (S0); PE_RSTn signal is high. Switching the communication to

SMBus is only needed for ME activity or to enable host wake up in low power states and is controlled by

the ME/PMC.

The switching from PCIe to SMBus is done when the PE_RSTn signal is low.

- Any transmit/receive packet that is not completed when PE_RSTn goes to 0b is discarded.
- Any in-band message that was sent over PCIe and was not acknowledged is retransmitted over
    SMBus.


```
Intel® Ethernet Connection I219—Interconnects
```
```
Notes:
```
1. Not all PCH PCIe ports can be used for the I219. Refer to the SkyLake/Greenlow/Purley EDS documentation for the specific
    ports that can be used with the I219.
2. Any CLKOUT_PCIE and PCIECLKRQ ports can be used to connect to the I219. These can be selected using the FITC tool.
3. PETp/n, PERp/n, PE_CLKp/n should be routed as a differential pair as indicated in the PCIe specification.
4. Refer to the I219 reference schematics and design checklists for more details.

Figure 2-2 PCIe/SMBus Interface


Pin Interface—Intel® Ethernet Connection I219

## 3.0 Pin Interface

### 3.1 Pin Assignment ...............................................................................................................

The I219 is packaged in a 48-pin package, 6 x 6 mm with a 0.4 mm lead pitch. There are 48 pins on the

periphery and a die pad (Exposed Pad*) for ground.

#### 3.1.1 Signal Type Definitions ......................................................................................

```
Signal Type Definition
```
```
In Input is a standard input-only signal.
```
```
I A standard input-only signal.
```
```
Out (O) Totem pole output is a standard active driver.
```
```
T/s Tri-state is a bi-directional, tri-state input/output pin.
```
```
S/t/s Sustained tri-state is an active low tri-state signal owned and driven by one and only one agent at a time.
The agent that drives an s/t/s pin low must drive it high for at least one clock before letting it float. A new
agent cannot start driving an s/t/s signal any sooner than one clock after the previous owner tri-states it.
```
```
O/d Open drain enables multiple devices to share as a wire-OR.
```
```
Analog Analog input/output signal.
```
```
A-in Analog input signal.
```
```
A-out Analog output signal.
```
```
B Input bias.
```

```
Intel® Ethernet Connection I219—Pin Interface
```
#### 3.1.2 PCIe Interface Pins (8).......................................................................................

#### 3.1.3 SMBus Interface Pins (2)....................................................................................

#### 3.1.4 Miscellaneous Pins (3) .......................................................................................

```
Pin Name Pin # Type Op Mode Name and Function
```
```
PE_RST_N 36 I Input PCIe reset.
```
```
PETp
PETn
```
##### 38

##### 39

```
A-out Output PCIe Tx.
```
```
PERp
PERn
```
##### 41

##### 42

```
A-in Input PCIe Rx.
```
##### PE_CLKP

##### PE_CLKN

##### 44

##### 45

```
A-in Input PCIe clock.
```
```
CLK_REQ_N 48 O/d Clock request.
```
```
Pin Name Pin # Type Op Mode Name and Function
```
```
SMB_CLK 28 O/d Bi-dir
```
```
SMBus clock.
Pull this signal up to 3.3 Vdc (auxiliary supply) through a 499
resistor (while in Sx mode).
```
```
SMB_DATA 31 O/d Bi-dir
```
```
SMBus data.
Pull this signal up to 3.3 Vdc (auxiliary supply) through a 499
resistor (while in Sx mode).
```
```
Pin Name Pin # Type Op Mode Name and Function
```
```
RSVD1_VCC3P3 1 T/s
```
```
LANWAKE_N 2 O/d
```
```
LAN_DISABLE_N 3 I When this pin is set to 0b, the I219 is disabled.
```

Pin Interface—Intel® Ethernet Connection I219

#### 3.1.5 PHY Pins (14) ...................................................................................................

3.1.5.1 LEDs (3)

3.1.5.2 Analog Pins (11)

```
Pin Name Pin # Type Op Mode Name and Function
```
```
LED0 26 O Output This signal is used for the programmable LED.
```
```
LED1 27 O Output This signal is used for the programmable LED.
```
```
LED2 25 O Output This signal is used for the programmable LED.
```
```
Pin Name Pin # Type Op Mode Name and Function
```
##### MDI_PLUS[0]

##### MDI_MINUS[0]

##### 13

##### 14

```
Analog Bi-dir
```
```
Media Dependent Interface[0]:
1000BASE-T: In MDI configuration, MDI[0]+/- corresponds to
BI_DA+/- and in MDI-X configuration MDI[0]+/-
corresponds to BI_DB+/-.
100BASE-TX: In MDI configuration, MDI[0]+/- is used for the
transmit pair and in MDI-X configuration
MDI[0]+/- is used for the receive pair.
10BASE-T: In MDI configuration, MDI[0]+/- is used for the
transmit pair and in MDI-X configuration
MDI[0]+/- is used for the receive pair.
```
##### MDI_PLUS[1]

##### MDI_MINUS[1]

##### 17

##### 18

```
Analog Bi-dir
```
```
Media Dependent Interface[1]:
1000BASE-T: In MDI configuration, MDI[1]+/- corresponds to
BI_DB+/- and in MDI-X configuration MDI[1]+/-
corresponds to BI_DA+/-.
100BASE-TX: In MDI configuration, MDI[1]+/- is used for the
receive pair and in MDI-X configuration MDI[1]+/-
is used for the transmit pair.
10BASE-T: In MDI configuration, MDI[1]+/- is used for the
receive pair and in MDI-X configuration MDI[1]+/-
is used for the transmit pair.
```
##### MDI_PLUS[2]

##### MDI_MINUS[2]

##### MDI_PLUS[3]

##### MDI_MINUS[3]

##### 20

##### 21

##### 23

##### 24

```
Analog Bi-dir
```
```
Media Dependent Interface[3:2]:
1000BASE-T: In MDI configuration, MDI[3:2]+/- corresponds to
BI_DA+/- and in MDI-X configuration MDI[3:2]+/-
corresponds to BI_DB+/-.
100BASE-TX: Unused.
10BASE-T: Unused.
```
```
XTAL_OUT 9 O Output crystal.
```
```
XTAL_IN 10 I Input crystal.
```
```
RBIAS 12 Analog Connect to ground through a 3.01 K +/-1%.
```

```
Intel® Ethernet Connection I219—Pin Interface
```
#### 3.1.6 Testability Pins (5) ............................................................................................

Note: The I219 uses the JTAG interface to support XOR files for manufacturing test. BSDL is not

supported.

#### 3.1.7 Power and Power Control Pins (16) ......................................................................

```
Pin Name Pin # Type Op Mode Name and Function
```
```
JTAG_TCK 35 In Input JTAG clock input.
```
##### JTAG_TDI 32

```
In
PU
```
```
Input JTAG TDI input.
```
```
JTAG_TDO 34 T/s Output JTAG TDO output.
```
##### JTAG_TMS 33

```
In
PU
```
```
Input JTAG TMS input.
```
```
TEST_EN 30 In Input
Should be connected to ground through a 1 k resistor, when
connected to logic 1b and test mode is enabled.
```
```
Pin Name Pin # Type Name and Function
```
```
VDD3P3 4 Power 3.3 Vdc out.
```
```
VDD3P3_IN 5 Power 3.3 Vdc supply.
```
```
SVR_EN_N 6 Input
```
```
SVR Enable pin.
Connect to GND for internal SVR use. Connect to VDD3P3_IN when using
external power.
```
```
CTRL0P9 7 Analog
```
```
Internal SVR control pin.
Connect to a 4.7 H inductor and to the core rail.
```
##### VDD0P9

##### 8

##### 11

##### 16

##### 22

##### 37

##### 40

##### 43

##### 46

##### 47

```
Power Core Vdc supply.
```
##### VDD3P3

##### 15

##### 19

##### 29

```
Power 3.3 Vdc supply.
```

Pin Interface—Intel® Ethernet Connection I219

### 3.2 Pinout ............................................................................................................................

Figure 3-1 I219 Pinout

##### 569'B9663

##### LANWAKE_N

##### LAN_',6$%/(B1

##### VDD3

##### VDD33B,1

##### SVR_EN_N

##### CTRL3

##### 9''3

##### XTALB287

##### XTALB,1

##### 9''3B

##### 5%,$6

##### 1

##### 9''3

##### 3(7Q3(7S

##### 9''3

##### 3(5Q3(5S

##### 9''3

##### PE_CLK

##### 3

##### PE_CLK

##### 1

##### 9''39''3

##### CLK_REQ

##### B1

##### PE_RST_N

##### JTAG_TCK

##### JTAG_TDO

##### JTAG_TMS

##### JTAG_TDI

##### SMB_DAT$

##### TEST_EN

##### 9''3

##### SMB_CLK

##### LED1

##### LED0

##### LED2

##### MDI_PLUS[0]MDI_MINUS[0]9''39''3MDI_PLUS[1]MDI_MINUS[1]9''3MDI_PLUS[2]MDI_MINUS[2]9''3MDI_PLUS[3]MDI_MINUS[3]

##### 12

(^1324)

##### 25

##### 36

##### 48 37


```
Intel® Ethernet Connection I219—Pin Interface
```
NOTE: This page intentionally left blank.


Package—Intel® Ethernet Connection I219

## 4.0 Package

### 4.1 Package Type and Mechanical ...........................................................................................

The I219 package is a 6 mm x 6 mm, 48-pin QFN Halogen Free and Pb Free package with Epad size of

3 mm x 3 mm.

Figure 4-1 Package Illustration


```
Intel® Ethernet Connection I219—Package
```
### 4.2 Package Electrical and Thermal Characteristics ....................................................................

The thermal resistance from junction to case, qJC, is 15.1 ×C/Watt. The thermal resistance from

junction to ambient, qJA, is as follows, 4-layer PCB, 85 °Cambient.

No heat sink is required.

### 4.3 Power and Ground Requirements .......................................................................................

All the grounds for the package is down-bonded to an Exposed Pad* E-pad*.

```
Air Flow (m/s) Maximum Tj qJA (x C/Watt)
```
##### 0 119 34

##### 1 118 33

##### 2 116 31


Package—Intel® Ethernet Connection I219

### 4.4 Ball Mapping ...................................................................................................................

```
Pin Name Pin Number Side Pin Name Pin Number Side
```
```
RSVD1_VCC3P3 1 Left LED2 25 Right
```
```
LANWAKE_N 2 Left LED0 26 Right
```
```
LAN_DISABLE_N 3 Left LED1 27 Right
```
```
VDD3P3 4 Left SMB_CLK 28 Right
```
```
VDD3P3_IN 5 Left VDD3P3 29 Right
```
```
SVR_EN_N 6 Left TEST_EN 30 Right
```
```
CTRL0P9 7 Left SMB_DATA 31 Right
```
```
VDD0P9 8 Left JTAG_TDI 32 Right
```
```
XTAL_OUT 9 Left JTAG_TMS 33 Right
```
```
XTAL_IN 10 Left JTAG_TDO 34 Right
```
```
VDD0P9 11 Left JTAG_TCK 35 Right
```
```
RBIAS 12 Left PE_RST_N 36 Right
```
```
MDI_PLUS[0] 13 Bottom VDD0P9 37 Top
```
```
MDI_MINUS[0] 14 Bottom PETp 38 Top
```
```
VDD3P3 15 Bottom PETn 39 Top
```
```
VDD0P9 16 Bottom VDD0P9 40 Top
```
```
MDI_PLUS[1] 17 Bottom PERp 41 Top
```
```
MDI_MINUS[1] 18 Bottom PERn 42 Top
```
```
VDD3P3 19 Bottom VDD0P9 43 Top
```
```
MDI_PLUS[2] 20 Bottom PE_CLKP 44 Top
```
```
MDI_MINUS[2] 21 Bottom PE_CLKN 45 Top
```
```
VDD0P9 22 Bottom VDD0P9 46 Top
```
```
MDI_PLUS[3] 23 Bottom VDD0P9 47 Top
```
```
MDI_MINUS[3] 24 Bottom CLK_REQ_N 48 Top
```
```
GND 49 Epad (Center)
```

```
Intel® Ethernet Connection I219—Package
```
NOTE: This page intentionally left blank.


Initialization—Intel® Ethernet Connection I219

## 5.0 Initialization

### 5.1 Power Up .......................................................................................................................

Initialization begins with power up.

Figure 5-1 Power-Up Sequence


```
Intel® Ethernet Connection I219—Initialization
```
Note: Internal Power On Reset is an active low signal.

Power requirements during the power-up sequence are described in Section 6.3.1.1.

### 5.2 Reset Operation ..............................................................................................................

The reset sources for the I219 are as follows:

- Internal Power On Reset (POR) — The I219 has an internal mechanism for sensing the power
    pins. Until power is up and stable, the I219 generates an internal active low reset. This reset acts as
    a master reset for the I219. While the internal reset is 0b, all registers in the I219 are reset to their
    default values. Strapping values are latched after Internal POR is de-asserted.
- PHY Soft Reset — A PHY reset caused by writing to bit 15 in MDIO register 0. Setting the bit
    resets the PHY, but does not reset non-PHY parts. The PHY registers are reset, but other I219
    registers are not.

```
Note: The integrated LAN controller configures the LCD registers. Other I219 GbE LCD
registers do not need to be configured.
```
- PCIe Reset from pin — After asserting a PCIe reset, the I219 stops the SerDes and if in the middle
    of transmitting a packet it should be dropped. De-asserting PCIe reset resets the internal FIFO
    unless wake-up is activated and causes a switch from SMBus to PCIe.
- In-Band Reset — An in-band message causing complete reset of the I219 except the wake up
    filters content.

```
Note: LAN_DISABLE_N is the only external signal that can reset the PHY. Refer to
Section 6.3.1 for more details.
```
Some of the bonding option registers are writable and can be loaded from the NVM or written by the

integrated LAN Controller (SKU register). The effect of the various reset options on these and other

registers is listed in Table 6-1 on page 49.

Table 5-1 lists the impact of each I219 reset.

```
Note
```
```
1 Platform power ramps up (3.3 Vdc/Core Vdc).
```
```
2 XTAL is stable after TXTAL seconds.
```
```
3 Internal Power On Reset triggers TPOR after XTAL is stable. Strapping options are latched.
```
```
4 PCIe training if PE reset is de-asserted.
```
```
5 SMBus ARP if initiated.
```
```
6 Wait for the integrated LAN Controller SMBus address valid.
```
```
7 Send Link Status message.
```
```
8 MAC configures the I219.
```
```
9 PHY goes through auto-negotiation to acquire link.
```

Initialization—Intel® Ethernet Connection I219

### 5.3 Timing Parameters ..........................................................................................................

#### 5.3.1 Timing Requirements.........................................................................................

The I219 requires the following start-up and power-state transitions.

#### 5.3.2 Timing Guarantees ............................................................................................

The I219 guarantees the following start-up and power state transition related timing parameters.

Note: For platform power sequencing requirements for the Cougar Point/Patsburg integrated LAN

controller, refer to the Cougar Point/Patsburg EDS.

Table 5-1 I219 Resets

```
Effects/Sources
```
```
PCIe-
Based
Interface
```
```
Non-PHY
Registers
and State
```
##### PHY

```
Registers
and State
```
```
Reset
Complete
Indication^1
```
1. Once the PHY completes its internal reset a reset complete indication is sent to the integrated LAN controller over the interconnect.
    The integrated LAN controller then configures the PHY.

```
Strapping
Options
```
```
Fuse
Registers
```
```
Move Out
of Power
Down
Mode
```
```
Wake Up
Register
```
```
Internal POR^2
```
2. Asserting a 3.3 Vdc power on reset should move the PHY out of power down mode.

##### XXXXXX X

```
PHY Soft Reset^3
```
3. PHY registers (page 0 in MDIO space and any aliases to page 0) are reset during a PHY soft reset. The rest of the I219’s MDIO
    space is not reset.

##### XX

```
PCIe Reset X
```
```
In-Band Reset X X X X X X
```
Table 5-2 Timing Requirements

```
Parameter Description Min Max Notes
```
```
Tr2init Completing a PHY configuration following a
reset complete indication.
```
```
0.5 s
```
Table 5-3 Timing Requirements

```
Parameter Description Min Max Notes
```
```
TPHY_Reset Reset de-assertion to PHY reset complete. 10 ms PHY configuration should be delayed
until PHY completes its reset.
```
```
Tc2an Cable connect at start of auto-negotiation. 1.2 s 1.3 s Per 802.3 specification.
```
```
TXTAL XTAL frequency stable after platform
power ramp up.
```
```
45 ms
```
```
TPOR Internal POR trigger after XTAL stable/ 40 ms
```

```
Intel® Ethernet Connection I219—Initialization
```
NOTE: This page intentionally left blank.


Power Management and Delivery—Intel® Ethernet Connection I219

## 6.0 Power Management and Delivery

This section describes power management in the I219.

### 6.1 Power Information ...........................................................................................................

The following sections describe requirements in specific power states.

Table 6-1 I219 Power Consumption Target

```
System State Link State Device Power Using Internal SVR (mW)
```
```
S0 (Max) Thermal Design Power (TDP) 542
```
```
S0 (Typ)
```
```
1000 Mb/s Active 542
```
```
1000 Mb/s Idle 439
```
```
1000 Mb/s LPI
(EEE link partner only)
```
##### 55

```
100 Mb/s Active 264
```
```
100 Mb/s Idle 177
```
```
100 Mb/s LPI
(EEE link partner only)
```
##### 51

```
10 Mb/s Active 306
```
```
10 Mb/s Idle 84
```
```
Cable Disconnect ULP Mode 0.13
```
```
Sx
```
```
WoL Enabled
```
```
100 Mb/s WOL enabled 169
```
```
10 Mb/s WOL enabled 76
```
```
Cable Disconnect ULP Mode 0.13
```
```
WoL Disabled LAN disabled using BIOS 0
```
```
Note: Measured power could be higher or lower based on lab setup.
```

```
Intel® Ethernet Connection I219—Power Management and Delivery
```
### 6.2 Power Delivery ................................................................................................................

The I219 operates from a 3.3 Vdc external power rail.

#### 6.2.1 Core Vdc Supply ...............................................................................................

The Core Vdc rail can be supplied by integrated SVR solution with external inductor and capacitor.

### 6.3 Power Management .........................................................................................................5

#### 6.3.1 Global Power States ..........................................................................................

The I219 transitions between power states based on a status packet received over the interconnect and

based on the Ethernet link state. The following power states are defined:

- Power-Up — Defined as the period from the time power is applied to the I219 and until the I219
    powers up its PHY. The I219 needs to consume less than 40 mA during this period.
- Active 10/100/1000 Mb/s — Ethernet link is established with a link partner at any of 10/100/
    1000 Mb/s speed. The I219 is either transmitting/receiving data or is capable of doing so without
    delay (for example, no clock gating that requires lengthy wake).
- Idle 10/100/1000 Mb/s — Ethernet link is established with a link partner at any of 10/100/1000
    Mb/s speed. The I219 is not actively transmitting or receiving data and might enter a lower power
    state (for example, an interface can be in electrical idle).
- Cable Disconnect — The PHY identified that a cable is not connected. The I219 signals the
    integrated LAN controller that the link is down. The PHY might enter energy detect mode or the
    integrated LAN controller might initiate a move into active power down mode (sD3).
- Power-Down (LAN Disable) — Entry into power down is initiated by the integrated LAN controller
    through an in-band message or by setting the LAN_DISABLE_N pin to zero. The I219 loses all
    functionality in this mode other than the ability to power up again.
- IEEE Power-Down — The standard IEEE power-down initiated by the Host setting the
    POWER_DOWN bit (bit 11) of the PHY Control Register to 1b (refer to Section 9.5.2.18).
- LPI — IEEE802.3az [Energy Efficient Ethernet (EEE)] defines an optional Low Power Idle (LPI)
    mode for 1000BASE-T, 100BASE-TX and other interfaces. LPI enables power saving by switching off
    part of the I219 functionality when no data needs to be transmitted or/and received. When LPI
    support is enabled, the I219 will shut off RX circuitry and send an in-band RX LPI Indication on
    detection that link the partner’s TX moved into LPI state. The I219 PHY will move TX into LPI state
    and power-down transmit circuitry when receiving an Inband TX LPI request from the integrated
    LAN controller.


Power Management and Delivery—Intel® Ethernet Connection I219

6.3.1.1 Power-Up

Defined as the period from the time power is applied to the I219 and until the I219 powers up its PHY.

The I219 should consume less than ~40 mA during this period. Following the I219 LCD entering reset,

the power-up sequence is considered done and the requirement is removed. Refer to Section 5.1 for a

description of the power-up sequence.

6.3.1.2 Cable Disconnect State

The I219 enters a cable disconnect state if it detects a cable disconnect condition on the Ethernet link.

Power is reduced during cable disconnect mode by several means:

- The PHY enters energy detect mode.
- The PCIe link enters power down.

An exit from cable disconnect happens when the I219 detects energy on the MDI link, and starts the

following exit sequence:

- The I219 signals the integrated LAN controller that link energy was detected by clearing the Cable
    Disconnect bit in the PCIe or SMBus interface.
- The PHY waits until the auto-negotiation break link timer expires (Tc2an time) and then starts to
    advertise data on the line.

6.3.1.3 Power-Down State

The I219 enters a power-down state when the LAN_DISABLE_N pin is set to zero. Exiting this mode

requires setting the LAN_DISABLE_N pin to a logic one.

Note: Following a power up or reset, the power-down bit must not be set until the configuration

cycle completes.

The Device Power Down Mode field in the MDIO register space defines the response to

a power-down command. The I219 takes one of two possible actions:

- Device stays active — No change in functionality and no power reduction.
- Device power down — The PHY enters power down, clocks are gated, PCIe enters Electrical Idle
    (EI).

Figure 6-1 shows the power-down sequence in the two later cases.

Figure 6-1 Power-Down Sequence


```
Intel® Ethernet Connection I219—Power Management and Delivery
```
Notes: In cases where the LAN_DISABLE_N pin cannot be used a power down in-band can be

```
used. When used the power savings are lower since not all logic can be turned off at this
mode.
```
6.3.1.4 EEE LPI State

EEE (Energy Efficient Ethernet) Low Power Idle (LPI) mode defined in IEEE802.3az optionally allows

power saving by switching off part of the integrated LAN controller and I219 functionality when no data

needs to be transmitted or/and received. Decision on whether the I219 transmit path should enter Low

Power Idle mode or exit Low Power Idle mode is done on the integrated LAN controller level and

communicated to the I219 to allow power saving in the transmit circuitry. Information on whether Link

Partner has entered Low Power Idle mode is detected by the I219 and communicated to the integrated

LAN controller to allow for power saving in the receive circuitry.

Figure 6-2 illustrates general principles of an EEE LPI operation on the Ethernet Link.

Table 6-2 Power-Down Notes

```
Note
```
```
1 The LAN_DISABLE_N pin is set to zero
```
```
2 Once the I219 detects the LAN_DISABLE_N transitions to a logic zero, the PHY enters a power-down state.
```
```
3 The PCIe link (if enabled) enters electrical idle state.
```
```
4 PCIe/SMBus exits a reset state and performs link initialization.
```
```
5 The integrated LAN controller configures the I219 through the MDIO interface.
```
```
6 PHY goes through auto-negotiation to acquire link.
```
Figure 6-2 EEE LPI Compliant Operation

Table 6-3 LPI Parameters

```
Parameter Description
```
```
Sleep Time (Ts) Duration PHY sends Sleep symbols before going Quiet.
```
```
Quiet Duration (Tq) Duration PHY remains Quiet before it must wake for Refresh period.
```
```
Refresh Duration (Tr) Duration PHY sends Refresh symbols for timing recovery and coefficient synchronization.
```
```
PHY Wake Time (Tw_PHY) Minimum duration PHY takes to resume to Active state after decision to Wake.
```
```
Receive System Wake Time
(Tw_System_rx)
```
```
Wait period where no data is expected to be received to give the local receiving system time to
wake up.
```
```
Transmit System Wake Time
(Tw_System_tx)
Wait period where no data is transmitted to give the remote receiving system time to wake up.
```

Power Management and Delivery—Intel® Ethernet Connection I219

In the transmit direction, entrance to Low Power Idle mode of operation is triggered by the reception of

LPI TX Request from the integrated LAN controller. Following reception of the LPI TX in band Request,

PHY transmits special Sleep symbols to communicate to the link partner that the local system is

entering Low Power Idle mode.

In 100BASE-TX LPI mode PHY enters low power operation in an asymmetric manner. After Sleep

symbols transmission, the transmit function of the local PHY immediately enters a low power quiet

mode. In 1000BASE-T LPI mode, PHY entry into low power mode is symmetric. Only after the local PHY

transmits and receives sleep symbols from the remote PHY does the transmit function of the local PHY

enter the quiet mode.

Periodically the local PHY transmits Refresh symbols that are used by the link partner to update

adaptive filters and timing circuits in order to maintain link integrity. This quiet-refresh cycle continues

until the local integrated LAN controller sends an in-band message with a clear (0) LPI TX Request,

which signals to the I219 that Low Power Idle mode should end. The I219 communicates this to the link

partner by sending special Wake symbols for a pre-defined period of time. Then the PHY enters Active

state and resumes normal operation. Data can be transmitted after a Tw_System_tx duration.

6.3.1.4.1 EEE Capabilities Auto-Negotiation

EEE support is advertised during Auto-Negotiation stage. Auto-Negotiation provides the capability to

detect the abilities supported by the device at the other end of the link, determine common abilities,

and configure for joint operation. Auto-Negotiation is performed at power up, on command from

integrated LAN controller, upon detection of a PHY error, or following Ethernet cable re-connection.

During the link establishment process, both link partners indicate their EEE capabilities. If EEE is

supported by both link partners for the negotiated PHY type then the EEE function may be used

independently in either direction. The Auto-Negotiation process uses next page messages as defined in

IEEE802.3az clauses 28C.12 and 28C.13.

6.3.1.4.2 EEE LPI Unsupported Features

EEE LPI does not support:

- Half-duplex operation
- 10 Mb/s speed

Note: These features should not be enabled while EEE is enabled.

6.3.1.5 Intel

```
®
Auto-Connect Battery Saver (ACBS)
```
Intel

##### ®

Auto Connect Battery Saver for the I219 is a hardware-only feature that automatically reduces

the LCD to a lower power state when the power cable is disconnected. When the power cable is

reconnected, it renegotiates the line speed following IEEE specifications for auto negotiation. By

default, auto negotiation starts at 1 Gb/s, then 100 Mb/s full duplex/half duplex, then 10 Mb/s full

duplex/half duplex.

- ACBS is only supported during auto negotiation. If link is forced, the I219 does not enter ACBS
    mode.


```
Intel® Ethernet Connection I219—Power Management and Delivery
```
The I219 ACBS works in both S0 and Sx states. Since the I219 ACBS has no driver control, the feature

is always enabled, allowing power savings by default.

- The crystal clock drivers are intermittently disabled when the network cable is unplugged and the
    I219 is in ACBS mode.

6.3.1.6 Automatic Link Down-Shift

Automatic link down-shift is a collection of power saving features that enable a link down-shift from

1000 Mb/s to a lower speed to save power under different conditions like the AC cable plugged in,

monitor idle, or entering Sx states.

6.3.1.7 Link Speed Battery Saver

Link speed battery saver is a power saving feature that negotiates to the lowest speed possible when

the I219 operates in battery mode to save power. When in AC mode, where performance is more

important than power, it negotiates to the highest speed possible. The Windows NDIS drivers (Windows

XP and later) monitor the AC-to-battery transition on the system to make the LCD negotiate to the

lowest connection speed supported by the link partner (usually 10 Mb/s) when the power cable is

unplugged (switches from AC to battery power). When the AC cable is plugged in, the speed negotiates

back to the fastest LAN speed. This feature can be enabled/disabled directly from DMiX or through the

advanced settings of the Window's driver.

When transferring packets at 1000/100 Mb/s speed, if there is an AC-to-battery mode transition, the

speed renegotiates to the lower speed. Any packet that was in process is re-transmitted by the protocol

layer. If the link partner is hard-set to only advertise a certain speed, then the driver negotiates to the

advertised speed. Note that since the feature is driver based, it is available in S0 state only.

Link speed battery saver handles duplex mismatches/errors on link seamlessly by re-initiating auto

negotiation while changing speed. Link speed battery saver also supports spanning tree protocol.

Note: Packets are re-transmitted for any protocol other than TCP as well.

6.3.1.8 System Idle Power Saver (SIPS)

SIPS is a software-based power saving feature that is enabled only with Microsoft* Windows* Vista* or

Windows* 7. This feature is only supported in the S0 state and can be enabled/disabled using the

advanced tab of the Windows driver or through DMiX. The power savings from this feature is dependent

on the link speed.


Power Management and Delivery—Intel® Ethernet Connection I219

### 6.4 I219 Ultra Low Power (ULP) ..............................................................................................

To reduce the power consumption of the I219 during link disconnect, the I219 introduces a new Ultra

Low Power (ULP) mode. In ULP mode the I219 will power gate most of its functionality and only

maintain a small portion of the die powered sensing for future cable connection (energy on the Ethernet

link). Once energy is detected the I219 will exit ULP mode and either send an in-band message (link

connect status) or assert LANWAKE# according to configuration.

The I219 functionality in ULP mode (In-band/WoL exit, SMBus/PCIe exit etc.) is controlled by the host

driver (on non ME systems) or the ME FW. The SW will configure I219 registers for proper entry and exit

conditions.

The I219 can be configured to enter ULP on future link disconnect while the link is still connected so

that during entry to Sx future link disconnects will benefit from the ULP mode.

For proper functionality and power consumption during ULP mode the board design of the I219 should

be such that:

- LANWAKE_N, SMB_CLK,SMB_DATA, CLK_REQ_N are pulled up on board.
- TEST_EN is driven low or pulled down on board.
- LAN_DISABLE_N, PE_RST_N can be driven either low or high.
- PE_CLKP/N are both either driven low or tri-stated in ULP mode.
- LED0, LED1, LED2 are in tri-state mode during ULP

### 6.5 Off Board LAN Connected Device (OBLCD) ..........................................................................

To enable OBLCD for platforms where the LAN Connected Device is not located on the motherboard

(either located on a docking station or on a dongle) additional communication is required between the

LAN Controller and the LAN Connected Device so that the LAN Controller would be aware of OBLCD

connect and disconnect events.

#### 6.5.1 Indicating /Sensing OBLCD Disconnect

#### Event

During K0, CLKREQ# is asserted by the LAN Connected Device. On OBLCD disconnect the CLKREQ#

would de-assert (board controlled) not as part of the K1 entry flow. The LAN Controller would refer to

such event as an indication of OBLCD disconnect.

During K1, CLKREQ# is de-asserted. To indicate presence, the LAN Connected Device will send an

in-band beacon message once every BCN_INTER for BCN_DUR to indicate that the LAN Controller that

the dongle is still connected. The LAN Controller would not exit K1 when sensing these squelch pulses.

K1 exit will only start after sensing a beacon pulse longer than LC.OFFSET+BCN_DUR. At this state the

LAN Controller should enable the PLL and start the K1 exit flow.


```
Intel® Ethernet Connection I219—Power Management and Delivery
```
If the LAN Controller misses these beacon pulse indications for LC.MISS_BCN*BCN_INTER it should

refer to such event as an indication of dongle disconnect. In addition the LAN Controller will implement

a mode to exit K1 on CLKREQ# assertion to avoid the additional latency in the K1 exit sequence.

While in SMBus the LAN Connected Device should be configured to send periodic status in-bands and

RX packets. If the LAN Controller doesn't sense RX activity (packets or statuses) for

NO_RX_ON_SMBUS time it should refer to such event as an indication of OBLCD disconnect.

While in ULP the LAN Connected Device is power gated so no notification on disconnect, the LAN

Controller will not be notified of such event until:

- It will try to take the LAN Connected Device out of ULP without success.
- OBLCD will be reconnected (in S0) and the LAN Connected Device will assert CLKREQ#, indicating
    the LAN Controller to move to PCIe.

Note: When the LAN Connected Device is in WoL mode the LAN Controller is powered off, OBLCD

disconnection will have no indication.

#### 6.5.2 Indicating/Sensing OBLCD Connection .................................................................

OBLCD connection will be detected by using CLKREQ# assertion on connection. The default interface of

the OBLCD will be PCIe. Connection can be made on the following flows:

- In PCIe, the LAN Connected Device will cause K1 exit by asserting the CLKREQ# and then sending
    status in-bands over PCIe
- While the interface is defined as SMB, OBLCD connection will not be reflected up while the interface
    is SMB (and PERST# is asserted)


Device Functionality—Intel® Ethernet Connection I219

## 7.0 Device Functionality

### 7.1 Tx Flow ..........................................................................................................................

When packets are ready for transmission in the integrated LAN controller it transfers them to the I219

through the PCIe or the SMBus (depends on system state). The I219 starts transmitting the arrived

packet over the wire after it gathers 8 bytes of data if the PCIe interface is active or after all packet

data is received if it was transferred over the SMBus; this behavior has no dependency on the link

speed. The I219 design is based on the assumption that the integrated LAN controller has the full

packet ready for transmission.

In several cases the I219 has to stop transmission over the wire while still accepting data from the

upper connection (PCIe or SMBus). For those cases, the I219 maintains a 3 KB FIFO. The cases where

the I219 needs to stop Tx are:

- PAUSE packet was received on the Rx side while flow control is enabled. For full support of flow
    control, the Receive Flow Control Enable (RFCE) bit (bit 7) in the LCD Receive Control register
    should be set in addition to the configuration in the integrated LAN controller.
- In half-duplex mode while the I219 is in the middle of a receive (DEFER).
- In half-duplex mode while a collision was detected on the wire.

In addition to stop transmission, the I219 sends an in-band message to the integrated LAN controller

with the Tx OFF bit set. This in-band message must be sent at the first gap between received packets if

(at the same time) the event caused the stop transmit is not valid and transmission over the wire is

activated, the I219 might avoid sending the in-band message. An in-band message with the Tx OFF bit

cleared is sent when the collided packet was successfully transmitted or dropped after 16 retries (refer

to Section 7.3.1).

In-band messages from the integrated LAN controller to the I219 always come in between packets

during the IPG. The I219 does not accept in-band messages in the middle of a packet.


```
Intel® Ethernet Connection I219—Device Functionality
```
### 7.2 Rx Flow .........................................................................................................................

The I219 maintains a 3 KB FIFO on the receive side in order not to lose packets when PCIe is active but

at K1 power save mode. In this case, the I219 initiates recovery of the PCIe when a reception has

started. If the link is at 1 Gb/s, the transmission of the packet over the PCIe bus starts immediately

after recovery. if the link speed is lower, the I219 starts the transmission after the entire packet is

received. The I219 assumes maximum recovery time (from the K1 state) of 10 s on both sides of the

PCIe side. Higher recovery time causes a packet drop on the receive side.

The I219 identifies PAUSE packets, stop transmission, and a send in-band message as described in

Section 7.1.

In-band messages from the I219 to the integrated LAN controller always come in between packets

during the IPG.

When the PCIe is not active, packet drop is not avoidable due to the big difference in line rate between

the MDI and the SMBus.

### 7.3 Flow Control ...................................................................................................................

Flow control as defined in 802.3x, as well as the specific operation of asymmetrical flow control defined

by 802.3z, is supported in the integrated LAN controller during PCIe mode and in the LAN Connected

Device during SMBus mode. Some of the flow control functionality has moved to the I219. The following

registers are duplicated to the I219 for the implementation of flow control:

- Flow Control Address — 0x01, 0x80, 0xC2, 0x00, 0x00, 0x01; where 01 is the first byte on the
    wire, 0x80 is the second, etc.
- Flow Control Type (FCT) — 16-bit field to indicate flow control type.
- Flow Control Transmit Timer Value (FCTTV) — 16-bit timer value to include in transmitted PAUSE
    frame.
- Flow Control Refresh Threshold Value (FCRTV) — 16 bit PAUSE refresh threshold value.

Flow control is implemented as a mean of reducing the possibility of receive buffer overflows, which

result in the dropping of received packets, and allows for local controlling of network congestion levels.

This can be accomplished by sending an indication to a transmitting station of a nearly full receive

buffer condition at a receiving station. The implementation of asymmetric flow control allows for one

link partner to send flow control packets while being allowed to ignore their reception. For example, not

required to respond to PAUSE frames.


Device Functionality—Intel® Ethernet Connection I219

#### 7.3.1 MAC Control Frames and Reception of Flow Control Packets ....................................

Three comparisons are used to determine the validity of a flow control frame:

1. A match on the six-byte multicast address for MAC control frames or to the station address of the
    device (Receive Address Register 0).
2. A match on the type field
3. A comparison of the MAC Control Opcode field.

The 802.3x standard defines the MAC control frame multicast address as 01-80-C2-00-00-01. The Flow

Control Packet’s Type field is checked to determine if it is a valid flow control packet: XON or XOFF.

802.3x reserves this as 0x8808. The final check for a valid PAUSE frame is the MAC Control Opcode

field. At this time only the PAUSE control frame opcode is defined. It has a value of 0x0001. Frame

based flow control differentiates XOFF from XON based on the value of the PAUSE Timer field. Non-zero

values constitute XOFF frames while a value of zero constitutes an XON frame. Values in the Timer field

are in units of slot time. A slot time is hard wired to 64 byte times.

Note: An XON frame signals canceling the pause from being initiated by an XOFF frame (Pause for

zero slot times).

Where S is the start-of-packet delimiter and T is the first part of the end-of-packet delimiter for 802.3z

encapsulation. The receiver is enabled to receive flow control frames if flow control is enabled via the

RFCE bit in the Device Control (CTRL) register.

Note: Flow control capability must be negotiated between link partners via the autonegotiation

```
process. The auto-negotiation process might modify the value of these bits based on the
resolved capability between the local device and the link partner.
```
Figure 7-1 802.3x MAC Control Frame Format


```
Intel® Ethernet Connection I219—Device Functionality
```
Once the I219 has validated the reception of an XOFF, or PAUSE frame, it performs the following:

- Initializes the pause timer based on the packet’s PAUSE Timer field.
- Disables packet transmission or schedules the disabling of transmission after the current packet
    completes.
- Sends an in-band status command with the TX OFF bit set.
- Forward the XOFF or PAUSE frame to integrated LAN controller.

Resuming transmission might occur under the following conditions:

- Expiration of the PAUSE timer.
- Reception of an XON frame (a frame with its PAUSE timer set to zero).

##### 1

Once the I219 has validated the reception of an XON frame, it performs the following:

- Enables packet transmission.
- Sends an in-band status command with the Tx OFF bit cleared.
- Forwards the XON frame to the integrated LAN controller.

#### 7.3.2 Transmitting PAUSE Frames ...............................................................................

During PCIe mode transmitting PAUSE frames is done as a result of an In-Band Control command from

the integrated LAN controller. The integrated LAN controller initiates an in-band message if it is enabled

by software by writing a 1b to the TFCE bit in the Device Control register.

Note: Similar to receiving flow control packets previously mentioned, XOFF packets can be

```
transmitted only if this configuration has been negotiated between the link partners via the
auto-negotiation process. In other words, the setting of this bit indicates the desired
configuration.
```
When the in-band message from the integrated LAN controller is received, the I219 sends a PAUSE

frame with its PAUSE Timer field equal to FCTTV. Once the receive buffer fullness reaches the low water

mark, the integrated LAN controller sends an in-band message indicating to send an XON message (a

PAUSE frame with a timer value of zero).

During SMBus mode transmitting PAUSE frames is done as a result of the I219 receive and transmit

FIFO status. If the sum of data in both FIFOs is greater than the configured FCTH.HTHRSH, the I219

sends a PAUSE frame with its PAUSE Timer field equal to FCTTV. Once the sum of data in the receive

and transmit FIFOs is lower than FCTH.LTHRSH, the I219 sends a PAUSE frame with a timer value of

zero (XON). The I219 will send an XOFF refresh message with the PAUSE Timer set to FCTTV if after

FCRTV time from the previous XOFF message the transmit and receive buffer fullness is still above the

low threshold value.

Note: Transmitting flow control frames should only be enabled in full-duplex mode per the IEEE

```
802.3 standard. Software should make sure that the transmission of flow control packets is
disabled when the I219 is operating in half-duplex mode.
```
1. The XON frame is also forwarded to integrated LAN controller.


Device Functionality—Intel® Ethernet Connection I219

### 7.4 Wake Up ........................................................................................................................

The I219 supports host wake up. The host can enable host wake up from the I219 by setting the

Host_WU_Active bit.

To set the I219’s wake up:

1. Verify Host_WU_Active bit (bit 4) in the Port General Configuration register (page 769, register 17)
    is clear, this is needed to allow the configuration of the filters to wake up mode.
2. Set MACPD_enable bit (bit 2) of the Port Control register (page 769, register 17) to enable the I219
    wake up capability and software accesses to page 800.
3. Set the Slave Access Enable bit (bit 2) in the Receive Control register (page 800, register 0) to
    enable access to the Flex Filter register, if setting those bits is needed in the next stage. The
    registers affected are:
       - Flexible Filter Value Table LSB — FFVT_L (filters 01)
       - Flexible Filter Value Table MSBs — FFVT_H (filters 23)
       - Flexible Filter Value Table — FFVT_45 (filters 45)
       - Flexible Filter Value Table — FFVT_67 (filters 67)
       - Flexible TCO Filter Value/Mask Table LSBs — FTFT_L
       - Flexible TCO Filter Value/Mask Table MSBs — FTFT_H
       - Extended Flexible Filter Value Table — EFFVT (Filters 8-15)
4. Configure the I219’s wake up registers per ACPI/APM wake up needs.
5. Clear the Slave Access Enable bit (bit 2) in the Receive Control register (page 800, register 0) to
    enable the flex filters.
6. Set the Host_WU_Active bit (bit 4) in the Port General Configuration register (page 769, register
    17) to activate the I219’s wake up functionality.

On a detection of Host wake up event, the I219 will:

1. Assert the LANWAKE# pin indicating wake to PMC.
2. If in DeepSx, PMC will power up the SUS well.
3. PMC will send a PINSTOP message to the I219 through SMBus
4. On a reception of a PINSTOP message, the I219 will stop asserting the LANWAKE# pin and send a
    WU message over SMBus indicating the WU source.
       - The I219 will send a WU message on every PINSTOP message reception.
5. The I219 will not assert the LANWAKE# pin again until a WU message was sent and acknowledged.
    The In case of host wake up the integrated LAN controller wakes the host.
6. Host should issue a LCD reset to the I219 before clearing the Host_WU_Active bit.
7. Host reads the Wake Up Status register (WUS); wake up status from the I219.

When a wake up packet is identified, the wake up in-band message is sent and the host should clear the

Host_WU_Active bit (bit 4) in the Port General Configuration register (page 769, register 17) up to the

LAN Controller, and clears the PME_Status bit in the WUC register.


```
Intel® Ethernet Connection I219—Device Functionality
```
While in wake up active mode new wake up packets received will not overwrite the packet in the FIFO.

The I219 re-transmits the wake up in-band message after 50 ms if no change in the Host_WU_Active

bits occurred.

#### 7.4.1 Host Wake Up...................................................................................................

The I219 supports two types of wake up mechanisms:

- Advanced Power Management (APM) wake up
- ACPI Power Management wake up

7.4.1.1 Advanced Power Management Wake Up

Advanced Power Management Wakeup or APM Wakeup was previously known as Wake on LAN (WoL).

The basic premise is to receive a broadcast or unicast packet with an explicit data pattern, and then to

assert a signal to wake up the system or issue an in-band PM_PME message (if configured to).

At power up, if the I219’s wake up functionality is enabled, the APM Enable bits from the NVM are

written to the I219 by the integrated LAN controller to the APM Enable (APME) bits of the Wakeup

Control (WUC) register. These bits control the enabling of APM wake up.

When APM wake up is enabled, the I219 checks all incoming packets for Magic Packets. Refer to

Section 7.4.1.4.1.4 for a definition of Magic Packets.

To enable APM wake up, programmers should write a 1b to bit 10 in register 26 on page 0 PHY address

01, and then the station address to registers 27, 28, 29 at page 0 PHY address 01. The order is

mandatory since registers RAL0[31:0] and RAH0[15:0] are updated with a corresponding value from

registers 27, 28, 29, if the APM WoL Enable bit is set in register 26. The Address Valid bit (bit 31 in

RAH0) is automatically set with a write to register 29, if the APM WoL Enable bit is set in register 26.

The APM Enable bit (bit 0 in the WUC) is automatically set with a write to register 29, if the APM WoL

Enable bit is set in register 26.

Once the I219 receives a matching magic packet, it:

- Sets the Magic Packet Received bit in the WUS register.
- Initiates the integrated LAN controller wake up event through an in-band message.

APM wake up is supported in all power states and only disabled if a subsequent NVM read results in the

APM Wake Up bit being cleared or software explicitly writes a 0b to the APM Wake Up (APM) bit of the

WUC register.

7.4.1.1.1 Link Status Change

When the LSCWO bit (bit 5 in the WUC register) is set, wake up is generated if all of the following

conditions are met:

- APM wake up is enabled (APME bit is set in the WUC register)
- The LSCWE bit (bit 4) is set in the WUC register
- Link status change is detected


Device Functionality—Intel® Ethernet Connection I219

When the I219 detects a link status change it:

- Sets the Link Status Changed (LNKC) bit (bit 0) in the WUS register.
- Initiates the integrated LAN controller wake up event.

When the LSCWO bit is set, wake up is never generated on link status change if either APM wake up is

disabled or the LSCWE bit is cleared. In this case, the LNKC bit (bit 0) in the Wake up Filter Control

(WUFC) register is read as zero, independent of the value written to it.

7.4.1.2 ACPI Power Management Wake Up

The I219 supports ACPI Power Management based wake ups and can generate system wake up events

from three sources:

- Reception of a Magic Packet.
- Reception of a ACPI wake up packet.
- Detection of a link change of state.

Activating ACPI Power Management wake up requires the following steps:

1. Programming of the WUFC register to indicate the packets it needs to wake up and supplies the
    necessary data to the IPv4 Address Table (IP4AT) and the Flexible Filter Mask Table (FFMT), Flexible
    Filter Length Table (FFLT), and the Flexible Filter Value Table (FFVT). It can also set the Link Status
    Change Wake up Enable (LNKC) bit (bit 0) in the WUFC register to cause wake up when the link
    changes state.
2. Setting bit 2 (MACPD_enable) of the Port Control register (page 769, register 17) to put the I219 in
    wake up mode.

Once wake up is enabled, the I219 monitors incoming packets by first filtering them according to its

standard address filtering method and then by filtering them with all enabled wake up filters. If a

packet passes both the standard address filtering and at least one of the enabled wake up filters, the

I219:

- Initiates an integrated LAN controller wake up event.
- Sets one or more of the Received bits in the WUS register. Note that more than one bit is set if a
    packet matches more than one filter.

If enabled, a link state change wake up causes similar results.

7.4.1.3 Wake Up Packet Storage

A packet initiating Host wake up can be stored in the I219 by setting 776.19[0] prior to WoL entry.

Post wakeup, the once the driver is ready to get the wake up packet (post LAN Controller

configurations) the driver should set 776.19[1] and the wake up packet would be sent through the LC-

LCD interface as an incoming packet.


```
Intel® Ethernet Connection I219—Device Functionality
```
7.4.1.4 Wake Up Packets

The I219 supports various wake up packets using two types of filters:

- Pre-defined filters
- Flexible filters

Each of these filters are enabled if the corresponding bit in the WUFC register is set to1b. If the wake up

packet passes one of the manageability filters enabled in the Management Control (MANC) register,

then system wake up is also depends on the NoTCO bit (11) in the WUFC register being inactive or the

MANC.NoHostWoLonMEtraffic bit that enable Host WoL only if a packet passed ME filter but was also

directed to the Host using the MANC2H and MANC2H2 registers.

7.4.1.4.1 Pre-Defined Filters

The following packets are supported by the I219’s pre-defined filters:

- Directed Packet (including exact, multicast indexed, and broadcast)
- Magic Packet
- ARP/IPv4 Request Packet
- Directed IPv4 Packet
- Directed IPv6 Packet
- Flexible UDP/TCP and IP filters packets

Each of the filters are enabled if the corresponding bit in the WUFC register is set to 1b.

The explanation of each filter includes a table showing which bytes at which offsets are compared to

determine if the packet passes the filter. Note that both VLAN frames and LLC/Snap can increase the

given offsets if they are present.

7.4.1.4.1.1 Directed Exact Packet

The I219 generates a wake up event after receiving any packet whose destination address matches one

of the seven valid programmed receive addresses if the Directed Exact Wake Up Enable bit (bit 2) is set

in the WUFC register.

```
Offset
# of
Bytes
Field Value Action Comment
```
```
0 6 Destination Address Compare
Match any pre-programmed address as defined in the
receive address.
```

Device Functionality—Intel® Ethernet Connection I219

7.4.1.4.1.2 Directed Multicast Packet

For multicast packets, the upper bits of the incoming packet’s destination address indexes a bit vector

and the Multicast Table Array indicates whether to accept the packet. If the Directed Multicast Wake Up

Enable bit (bit 3) is set in the WUFC register and the indexed bit in the vector is one, the I219 generates

a wake up event. The exact bits used in the comparison are programmed by software in the Multicast

Offset field (bits 4:3) of the RCTL register.

7.4.1.4.1.3 Broadcast Packet

If the Broadcast Wake Up Enable bit (bit 4) in the WUFC register is set, the I219 generates a wake up

event when it receives a broadcast packet.

7.4.1.4.1.4 Magic Packet

Magic Packet Technology Details:

```
Once the I219 has been put into Magic Packet mode, it scans all incoming frames addressed to the
node for a specific data sequence, which indicates to the MAC that this is a Magic Packet frame. A
Magic Packet frame must also meet the basic requirements for the LAN technology chosen, such as
Source address, Destination Address (which might be the receiving station’s IEEE address or a
Multicast address that includes the Broadcast address) and CRC. The specific data sequence
consists of 16 duplications of the IEEE address of this node with no breaks or interruptions. This
sequence can be located anywhere within the packet, but must be preceded by a synchronization
stream. The synchronization stream enables the scanning state machine to be much simpler. The
synchronization stream is defined as 6 bytes of 0xFF. The device also accepts a Broadcast frame, as
long as the 16 duplications of the IEEE address match the address of the system that needs to wake
up.
```
The I219 expects the destination address to either:

1. Be the broadcast address (FF.FF.FF.FF.FF.FF)
2. Match the value in Receive Address (RAH0/RAL0) register 0. This is initially loaded from the NVM
    but can be changed by the software device driver.
3. Match any other address filtering enabled by the software device driver.

If the packet destination address met one of the three criteria previously listed, the I219 searches for

16 repetitions of the same destination address in the packet's data field. Those 16 repetitions must be

preceded by (in the data field) at least 6 bytes of 0xFF, which act as a synchronization stream. If the

destination address is NOT the broadcast address (FF.FF.FF.FF.FF.FF), the I219 assumes that the first

non-0xFF byte following at least 6 0xFF bytes is the first byte of the possible matching destination

address. If the 96 bytes following the last 0xFF are 16 repetitions of the destination address, the I219

accepts the packet as a valid wake up Magic Packet. Note that this definition precludes the first byte of

the destination address from being 0xFF.

```
Offset
# of
Bytes
Field Value Action Comment
```
```
0 6 Destination Address Compare See above paragraph.
```
```
Offset
# of
Bytes
Field Value Action Comment
```
```
0 6 Destination Address FF*6 Compare
```

```
Intel® Ethernet Connection I219—Device Functionality
```
A Magic Packet’s destination address must match the address filtering enabled in the configuration

registers with the exception that broadcast packets are considered to match even if the Broadcast

Accept bit (bit 5) of the RCTL register is 0b. If APM wake up is enabled in the NVM, the I219 starts up

with the RAH0/RAL0 register 0 loaded from the NVM. This enables the I219 to accept packets with the

matching IEEE address before the software device driver comes up.

7.4.1.4.1.5 ARP/IPv4 Request Packet

The I219 supports receiving ARP Request packets for wake up if the ARP bit (bit 5) is set in the WUFC

register. Three IPv4 addresses are supported, which are programmed in the IPv4 Address Table

(IP4AT). A successfully matched packet must contain a broadcast MAC address, a protocol type of

0x0806, an ARP opcode of 0x01, and one of the three host programmed IPv4 addresses. The I219 also

handles ARP Request packets that have VLAN tagging on both Ethernet II and Ethernet SNAP types.

To enable broadcast ARP wakeup RCTL.BAM should be set to accept broadcast packets.

```
Offset # of Bytes Field Value Action Comment
```
```
0 6 Destination Address Compare
```
```
MAC Header.
Processed by main address filter.
```
```
6 6 Source Address Skip
```
```
12 S = (0/4) Possible VLAN Tag Skip
```
```
12 + S D = (0/8) Len/LLC/SNAP Header Skip
```
```
12 + S + D 2 Type Skip
```
```
Any 6 Synchronizing Stream FF*6+ Compare
```
```
any+6 96 16 copies of Node Address A*16 Compare Compared to RAH0/RAL0 register.
```
```
Offset # of Bytes Field Value Action Comment
```
```
0 6 Destination Address Compare
```
```
MAC Header.
Processed by main address filter.
```
```
6 6 Source Address Skip
```
```
12 S = (0/4) Possible VLAN Tag Skip
```
```
12 + S D = (0/8) Possible Len/LLC/SNAP Header Skip
```
```
12 + S + D 2 Type 0x0806 Compare ARP
```
```
14 + S + D 2 Hardware Type 0x0001 Compare
```
```
16 + S + D 2 Protocol Type 0x0800 Compare
```
```
18 + S + D 1 Hardware Size 0x06 Compare
```
```
19 + S + D 1 Protocol Address Length 0x04 Compare
```
```
20 + S + D 2 Operation 0x0001 Compare
```
```
22 + S + D 6 Sender Hardware Address - Ignore
```
```
28 + S + D 4 Sender IP Address - Ignore
```
```
32 + S + D 6 Target Hardware Address - Ignore
```
```
38 + S + D 4 Target IP Address IP4AT Compare
Might match any of three host values in
IP4AT.
```

Device Functionality—Intel® Ethernet Connection I219

7.4.1.4.1.6 Directed IPv4 Packet

The I219 supports receiving Directed IPv4 packets for wake up if the IPV4 bit (bit 6) is set in the WUFC

register. Three IPv4 addresses are supported, which are programmed in the IPv4 Address Table

(IP4AT). A successfully matched packet must contain the station’s MAC address, a Protocol Type of

0x0800, and one of the three host programmed Ipv4 addresses. The I219 also handles Directed IPv4

packets that have VLAN tagging on both Ethernet II and Ethernet SNAP types.

7.4.1.4.1.7 Directed IPv6 Packet

The I219 supports receiving Directed IPv6 packets for wake up if the IPV6 bit (bit 7) is set in the WUFC

register. One IPv6 address is supported, which is programmed in the IPv6 Address Table (IP6AT). A

successfully matched packet must contain the station’s MAC address, a protocol type of 0x0800, and

the programmed IPv6 address. The I219 also handles Directed IPv6 packets that have VLAN tagging on

both Ethernet II and Ethernet SNAP types.

```
Offset # of Bytes Field Value Action Comment
```
```
0 6 Destination Address Compare
```
```
MAC Header.
Processed by main address filter.
```
```
6 6 Source Address Skip
```
```
12 S = (0/4) Possible VLAN Tag Skip
```
```
12 + S D = (0/8) Possible Len/LLC/SNAP Header Skip
```
```
12 + S + D 2 Type 0x0800 Compare IP
```
```
14 + S + D 1 Version/ HDR length 0x4X Compare Check IPv4.
```
```
15 + S + D 1 Type of Service - Ignore
```
```
16 + S + D 2 Packet Length - Ignore
```
```
18 + S + D 2 Identification - Ignore
```
```
20 + S + D 2 Fragment Info - Ignore
```
```
22 + S + D 1 Time to live - Ignore
```
```
23 + S + D 1 Protocol - Ignore
```
```
24 + S + D 2 Header Checksum - Ignore
```
```
26 + S + D 4 Source IP Address - Ignore
```
```
30 + S + D 4 Destination IP Address IP4AT Compare
Might match any of three host values in
IP4AT.
```
```
Offset # of Bytes Field Value Action Comment
```
```
0 6 Destination Address Compare
```
```
MAC Header.
Processed by main address filter.
```
```
6 6 Source Address Skip
```
```
12 S = (0/4) Possible VLAN Tag Skip
```
```
12 + S D = (0/8) Possible Len/LLC/SNAP Header Skip
```
```
12 + S + D 2 Type 0x0800 Compare IP
```
```
14 + S + D 1 Version/ Priority 0x6X Compare Check IPv6.
```
```
15 + S + D 3 Flow Label - Ignore
```
```
18 + S + D 2 Payload Length - Ignore
```
```
20 + S + D 1 Next Header - Ignore
```

```
Intel® Ethernet Connection I219—Device Functionality
```
7.4.1.4.1.8 Flexible Filter

The I219 supports a total of 32 flexible filters. Each filter can be configured to recognize any arbitrary

pattern within the first 128 bytes of the packet. To configure the flexible filter, software programs the

mask values into the Flexible Filter Mask Table (FFMT) and the required values into the Flexible Filter

Value Table (FFVT), and the minimum packet length into the Flexible Filter Length Table (FFLT). These

contain separate values for each filter. Software must also enable the filter in the WUFC register, and

enable the overall wake up functionality must be enabled by setting PME_En in the Power Management

Control Status Register (PMCSR) or the WUC register.

Once enabled, the flexible filters scan incoming packets for a match. If the filter encounters any byte in

the packet where the mask bit is one and the byte doesn’t match the byte programmed in the Flexible

Filter Value Table (FFVT) then the filter fails that packet. If the filter reaches the required length without

failing the packet, it passes the packet and generates a wake up event. It ignores any mask bits set to

one beyond the required length.

7.4.1.4.1.9 IPv6 Neighbor Solicitation Message Filter

In IPv6, a Neighbor Solicitation Message packet (type 135) is used for address resolution. A flexible

filter can be used to check for a Neighborhood Solicitation Message packet (type 135).

Note: The fields checked for detection of a Neighbor Solicitation Message packet (type 135) are

type, code and target addresses.

#### 7.4.2 Management Engine (ME) Wake Up .....................................................................

The I219 can also wake up the ME. Any packet that should be routed to the ME during normal operation

should wake up the ME when it is in the Moff state. The ME firmware should configure the MANC

register and the relevant manageability packet filters before setting the integrated LAN controller to the

DMoff state.

The integrated LAN controller can also wake up the ME by a link status change in the same manner as

host wake up. Wake up the ME on link status change is enabled by the WoLS bit (bit 12) in the MANC

register.

7.4.2.1 Manageability Wake Up Receive Filter

The I219 has the ability to wake up the ME. Any packet that can cause ME wake up must first match the

MAC address filtering this includes Exact Unicast/Multicast filtering; hash based Multicast filtering any

unicast MAC address if Promiscuous is enabled and Broadcast packets if enabled. Other filters can be

enabled based on the MANC register setting.

Figure 7-2 shows a top level diagram of the ME wake up filters. The following sections describe these

filters.

```
21 + S + D 1 Hop Limit - Ignore
```
```
22 + S + D 16 Source IP Address - Ignore
```
```
38 + S + D 16 Destination IP Address IP6AT Compare Match value in IP6AT.
```
```
Offset # of Bytes Field Value Action Comment
```

Device Functionality—Intel® Ethernet Connection I219

Figure 7-2 ME Receive Wake Up Filters Top Level


```
Intel® Ethernet Connection I219—Device Functionality
```
7.4.2.1.1 Manageability Registers

The Manageability filtering configuration is done by the manageability firmware. The following is a list of

registers in the I219 ME control space that are used to setup the manageability filtering:

- Management VLAN filters — MAVTV[x], x=03
- Flexible TCO filters — FTFT table
- Flexible UDP/TCP and IP filters — MFUTP[11:0], MIP4AT, L24IPV6
- Management Filter control registers — MANC, MANC2, MANC3
- Shared MAC filters control — SHRAFER
- IP Binding Control registers — IPV4MBC, IPV4HBC, IPV6BC

These registers are only reset on an Internal Power On Reset.

7.4.2.1.2 Manageability Packets Types

This section describes the different types of packets that can be configured in the receive filters.

Packets cause an ME wake up if they match a specific filter that it is enabled in the MANC register and

the RCV_TCO_EN bit (bit 17) is set.

A Unicast packet causes an ME wake up if (1) it matches a unicast MAC filter or (2) unicast promiscuous

mode is enabled (these are L2 conditions), and it passes any of the enabled manageability filters as

defined in the MANC register.

A Multicast packet causes an ME wake up if (1) it passes the L2 multicast filter or (2) multicast

promiscuous mode is enabled (these are L2 conditions), and it passes any of the enabled manageability

filters as defined in the MANC register.

A Broadcast packet cause an ME wake up if it passes any of the enabled manageability filters as defined

in the MANC register.

In addition, unicast or multicast packets that match any of the previous conditions with a VLAN header

causes an ME wake up if it passes one of the VLAN filters as defined by the MAVTV(x) registers.

7.4.2.1.3 ARP Packets Filtering

The I219 has the ability to wake the ME on ARP Request packets, ARP Response packets or both. ARP

Request packets wake up the ME if the ARP_REQ_EN bit (bit 13) is set in the MANC register. ARP

Response packets wake up the ME if ARP_RES_EN bit (bit 15) is set in the MANC register. Note that the

hardware filter does not check the IP address for ARP Response packets.

There is also a support in Neighbor Solicitation Message packet (type 135) filtering. If the

NEIGHBOR_EN bit (bit 14) is set in the MANC register, then Neighbor Solicitation Message packets (type

135) wake up the ME.


Device Functionality—Intel® Ethernet Connection I219

7.4.2.2 Flexible TCP UDP Port and IP Address Filtering

The I219 has the ability to direct packets to the ME if their L4 (TCP/UDP) destination port matches a

specific value. There are 12 flexible TCP or UDP port numbers depending on the FLEXPORT(x) bits in the

MANC/MANC2 registers and the corresponding MFUTP(x) registers.

The flexible port filters may be further dependent on IP address filtering as defined by the MIP4AT and

IP6AT if the EN_IPFLEX(x) bits in the MANC register are set.

Six of the 12 flexible port filters can be configured to filter source port instead of destination port

numbers.

To enhance the IPv6 filters four L3 filters were added each filter can be configured to match the 24 LSB

of the L3 address and can also be combined to match one of the UDP/TCP flexible ports or ICMPv6 next

header.

Note: For incoming tunneled packets TCP/UDP port filtering is done only for IPv6 packets in an

IPv4 tunnel.

7.4.2.3 Dedicated TCP UDP Port and IP Address

Filtering

The I219 has the ability to direct packets to the ME if their L4 (TCP/UDP) destination port matches a

specific value. There are two constant port numbers (0x26F -depends on the RMCP_EN bit in the MANC

register, 0x298 - depends on the EN_0298 bit in the MANC register). Additional dedicated TCP or UDP

port filters are controlled by the MANC3 register.

The first two constant L4 filters may be further dependent on IP address filtering as defined by the

MIP4AT and IP6AT if the EN_IP_ADDRFILTER bit in the MANC register is set.

Some of the dedicated port filters introduced in MANC3 have the ability to be further dependent on a

specific IP address and to pass filtering the packet must pass IP filtering as well as port and protocol

filtering.

7.4.2.3.1 L2 Filtering

The I219 has the ability to wake up the ME according to the packet L2 parameters:

- Broadcast Filtering — If bit BR_EN (bit 24) is set in the MANC register then all broadcast packets
    wake up the ME.
- Unicast Filtering — There are up to eleven MAC addresses that can be allocated to manageability
    MAC address filtering defined by the Shared Receive Address Low (SHRAL) register and the Shared
    Receive Address High (SHRAH) register. The MAC address filtering to manageability is controlled by
    the MNG MAC Must Match bit (bit 25) in the MANC register. Packets that match the MAC address
    filtering must match any of the manageability filters as defined in the SHRAFER register to wake up
    the ME.
- VLAN Filtering — There are four dedicated filters for VLAN addresses, which can be configured in
    registers MAVTV(x). Each register has a 12-bit field that represents the VID field of the incoming
    VLAN header and an enable bit. If the enable bit is set, HW compares the VID field to the VID field
    of the incoming packets. If it matches, the I219 wakes up the ME (the packet must pass any of the
    MAC filters as well).


```
Intel® Ethernet Connection I219—Device Functionality
```
7.4.2.3.2 Flexible TCO Filtering

The I219 includes two flexible filters as defined by the Flexible TCO Filter Table (FTFT). These filters

compare an exact pattern match within the 1st 128 bytes of the packet. Enabling these filters is done

by setting FLEX_TCO1/0_FILTER_EN bits (bits 6 and 7) in the MANC register.

7.4.2.4 Accessing the I219’s Wake Up Register Using

MDIC

When software needs to configure the wake up state (either read or write to these registers) the MDIO

page should be set to 800 (for host accesses) or 801 (for ME accesses) until the page is not changed to

a different value wake up register access is enabled. For more details on wake up configuration using

MDIC, refer to Section 9.5.9.1.

### 7.5 Network Proxy Functionality .............................................................................................

#### 7.5.1 Introduction .....................................................................................................

In prior operating system releases, ARP and IPv6 neighbor discovery messages were one of the

possible wakeup types for the platform. ARP and IPv6 neighbor discovery packets are required to

enable other network devices to discover the link layer address used by the PC. Supporting these

protocols while the host is in low power state is fundamental to maintain remote network accessibility

to the sleeping host. If the host does not respond, other devices in the network will eventually not be

able to send routable network traffic (such as IPV4 and IPV6) to the sleeping host.

Prior to network proxy, devices the wanted to maintain their network presence would have configured

the ARP and neighbor discovery messages as wake up patterns to the system. Analysis show that many

of these ARP wake-ups are unnecessary as they are generated by automated processes whose sole

purpose is to verify that the system is alive on the network (Microsoft* has stated in their testing 95%

of the wake-ups are due entirely to ARP wake-ups).

Ethernet devices that implement ARP offload must implement it as defined in the Power Management

specification on the NDIS Program Connect site. Specifically, the offload must respond to an ARP

Request (operation = 1) by responding with an ARP Reply (operation = 2) as defined in RFC 826.

Ethernet devices that implement IPv6 NS offload must implement it as defined in Power Management

specification on the NDIS Program, Connect site. Specifically, the offload must respond to an Neighbor

Solicitation (operation = 135) by responding with an NS Advertisement (operation = 136) as defined in

RFC 2461. Devices must support at least 2 NS offloads, each with up to 2 target IPv6 addresses.

#### 7.5.2 Network Proxy Activation ...................................................................................

As part of the system sleep flow and after receiving from the OS the network proxy and WoL patterns

the SW driver should follow the following steps to activate network proxy in the I219:

1. Program the WoL patterns according to the WoL flow with the addition of the network proxy specific
    configuration as described in the following steps.


Device Functionality—Intel® Ethernet Connection I219

2. Program the appropriate IPv4/IPv6 addresses in IP4AT and IP6AT registers.
3. Program the relevant L2 MAC addresses or broadcast reception.
4. Enable ARP/NS proxy through PRXC[6:5].

Note: A packet that matches both a proxy filter and a WoL filter should only cause WoL.

Note: The I219 should not respond to illegal network proxy packets with CRC or checksum errors.

#### 7.5.3 IPv4 Proxy - ARP...............................................................................................

In IPv4 networks, ARP provides the address mapping of the IP address to a corresponding MAC

address. ARP is a key protocol for remaining responsive on the network.

The delay time between repeated packets is undefined but may be relatively short. As a consequence it

is possible for the transition between the proxy and host to miss packets and for a brief time appear off

the network (no ARP response). Since ARP is an unreliable protocol there are no specific requirements

for proxies.

The sending node generates an ARP Request as a MAC broadcast datagram. The endpoint with the

requested IP address must generate a MAC unicast or MAC broadcast datagram ARP Response

informing the sending node of its presence. In order to be fully responsive on the network, the Proxy of

a sleeping host must respond to ARP requests by generating the necessary responses. Response packet

timings and ARP cache timeout values are undefined in the RFCs 826 and 1122.

The I219 supports responding to ARP Request packets (proxy) if enabled through PRXC register. Three

IPv4 addresses are supported, which are programmed in the IPv4 Address Table (IP4AT). A successfully

matched packet must contain a broadcast MAC address or one of the pre programed unicast MAC

addresses, a protocol type of 0x0806, an ARP opcode of 0x01, and one of the three programmed IPv4

addresses. The I219 also handles ARP Request packets that have VLAN tagging on both Ethernet II and

Ethernet SNAP types.

7.5.3.1 ARP Request Packet

```
Offset # of Bytes Field Value Action Comment
```
```
0 6 Destination Address Compare
```
```
MAC Header.
Processed by main address filter
```
```
6 6 Source Address Skip
```
```
12 S = (0/4) Possible VLAN Tag Skip
```
```
12 + S D = (0/8) Possible LEN/LLC/SNAP Header Skip
```
```
12 + S + D 2 Type 0x0806 Compare ARP
```
```
14 + S + D 2 Hardware Type 0x0001 Compare
```
```
16 + S + D 2 Protocol Type 0x0800 Compare
```
```
18 + S + D 1 Hardware Size 0x06 Compare
```
```
19 + S + D 1 Protocol Address Length 0x04 Compare
```
```
20 + S + D 2 Operation 0x0001 Compare
```
```
22 + S + D 6 Sender Hardware Address - Ignore
```
```
28 + S + D 4 Sender IP Address - Ignore
```

```
Intel® Ethernet Connection I219—Device Functionality
```
7.5.3.2 ARP Response Packet

#### 7.5.4 IPv6 Proxy - Neighbor Discovery .........................................................................

In IPv6 networks, ICMPv6 Neighbor solicitation and Neighbor advertisement provides the address

mapping of the IP address to a corresponding MAC address.

Neighbor Discovery is a set of 5 message types that are implemented on ICMPv6. The message types

are:

- Router Solicitation
- Router Advertisement
- Neighbor Solicitation
- Neighbor Advertisement
- Redirect

```
32 + S + D 6 Target Hardware Address - Ignore
```
```
38 + S + D 4 Target IP Address IP4AT Compare match IP4AT values or zero
```
```
42 + S + D 18 - S - D Padding 0x00 Ignore Padding to 64bytes
```
```
60 4 CRC Check
```
```
Offset # of Bytes Field Value Action
```
```
0 6 Destination Address Copy from ARP Request Source Address
```
```
6 6 Source Address Station address
```
```
12 S = (0/4) Possible VLAN Tag Copy from ARP Request
```
```
12 + S D = (0/8) Possible LLC/SNAP Header Copy from ARP Request
```
```
12 + S + D 2 Type 0x0806 Constant (Copy from ARP Request)
```
```
14 + S + D 2 Hardware Type 0x0001 Constant (Copy from ARP Request)
```
```
16 + S + D 2 Protocol Type 0x0800 Constant (Copy from ARP Request)
```
```
18 + S + D 1 Hardware Size 0x06 Constant (Copy from ARP Request)
```
```
19 + S + D 1 Protocol Address Length 0x04 Constant (Copy from ARP Request)
```
```
20 + S + D 2 Operation 0x0002 Constant
```
```
22 + S + D 6 Sender Hardware Address Station Address
```
```
28 + S + D 4 Sender IP Address
Target IP address from ARP Request or valid IP
address if Target IP was zero
```
```
32 + S + D 6 Target Hardware Address Sender MAC address from ARP Request
```
```
38 + S + D 4 Target IP Address Sender IP address from ARP Request
```
```
42 + S + D 18 - S - D Padding 0x00 Padding to 64 bytes
```
```
60 4 CRC Calculate
```
```
Offset # of Bytes Field Value Action Comment
```

Device Functionality—Intel® Ethernet Connection I219

Only two of these messages that are significant for resolving IPv6 addresses to the MAC address

Neighbor Solicitation and Neighbor Advertisement.

Machines that operate in IPv6 networks are sent an ICMPv6 Neighbor Solicitation and must respond

with their link-layer (MAC) address in their ICMPv6 Neighbor Advertisement response. The solicitation

may be for either the link-local, global, or a temporary IPv6 addresses.

Neighbor discovery messages have both an IPv6 header and the ICMPv6 header. The IPv6 header is a

standard one, including the source and destination IP addresses. The Network proxy offload does not

support IPv6 Neighbor discovery messages that also have IPv6 header extensions these packets will be

silently discarded with no reply.

Figure 7-3 Neighbor Discovery


```
Intel® Ethernet Connection I219—Device Functionality
```
7.5.4.1 Ipv6 Neighbor Solicitation Packet

```
Offset # of bytes Field
Value
(hex)
Action Comment
```
```
0 6 Destination Address Compare
```
```
MAC Header.
Processed by main address filter
```
```
6 6 Source Address Skip
```
```
12 S=(0/4) Possible VLAN Tag Skip
```
```
12+S D=(0/8) Possible LLC/SNAP Header Skip
```
```
IPv6 header
```
```
12+D+S 2 Type 0x86DD Compare IPv6
```
```
14+D+S 1 Version/ Traffic Class 0x6 Compare Check IPv6
```
```
15+D+S 3 Traffic Class/Flow Label Ignore
```
```
18+D+S 2 Payload Length Ignore
```
```
20+D+S 1 Next Header 0x3A Check ICMPv6
```
```
21+D+S 1 Hop Limit 0xFF Compare
```
```
22+D+S 16 Source Address Ignore Check if source address is undefined
```
```
38+D+S 16 Destination Address Ignore
```
```
ICMPv6 header
```
```
54+D+S 1 Type 0x87 Compare Neighbor Solicitation
```
```
55+D+S 1 Code 0x0 Compare
```
```
56+D+S 2 Checksum Check
```
```
58+D+S 4 Reserved 0x0000 Ignore
```
```
62+D+S 16 Target IP Address IP6AT Compare
```
```
78+D+S 1 Type 0x1 Compare
Possible Source Link Layer Address
option (Should not appear if source
address is undefined)
```
```
79+D+S 1 Length 0x1 Compare
```
```
80+D+S 6 Link Layer Address Skip
```
```
86+D+S 4 CRC Check
```

Device Functionality—Intel® Ethernet Connection I219

7.5.4.2 Ipv6 Neighbor Advertisement Packet

```
Offset # of bytes Field
Value
(hex)
Action
```
```
0 6 Destination Address Copy from ND packet
```
```
6 6 Source Address Station Address
```
```
12 S=(0/4) Possible VLAN Tag Copy from ND packet
```
```
12+S D=(0/8) Possible LLC/SNAP Header Copy from ND packet
```
```
IPv6 header
```
```
12+D+S 2 Type 0x86DD Constant (Copy from ND packet)
```
```
14+D+S 1 Version/ Traffic Class 0x6 Constant (Copy from ND packet)
```
```
15+D+S 3 Traffic Class/Flow Label Constant (Copy from ND packet)
```
```
18+D+S 2 Payload Length
```
```
20+D+S 1 Next Header 0x3A Constant
```
```
21+D+S 1 Hop Limit 0xFF Constant
```
```
22+D+S 16 Source Address relevant IPv6AT entry (ND target address)
```
```
38+D+S 16 Destination Address
```
```
Copy from ND packet Source address
If source address was undefined - send to All Nodes
Multicast (FF02::1)
```
```
ICMPv6 header
```
```
54+D+S 1 Type 0x88 Constant
```
```
55+D+S 1 Code 0x0
```
```
56+D+S 2 Checksum Calculate
```
```
58+D+S 4 Flags
```
```
0x60000
000
```
```
Constant (Solicited, Override) if the source address
was defined
```
```
0x20000
000
```
```
Constant (Override) if the source address was
undefined
```
```
62+D+S 16 Target IP Address IP6AT Same as source address
```
```
78+D+S 1 Type 0x2
```
```
79+D+S 1 Length 0x1 Target Link Layer Address option
```
```
80+D+S 6 Link Layer Address From ND
```
```
86+D+S 4 CRC Calculate
```

```
Intel® Ethernet Connection I219—Device Functionality
```
#### 7.5.5 Multicast Listener Discovery Support....................................................................

Microsoft requires that any device that claims support of NS (IPv6 Neighbor Solicitation) Proxying will

also support protocol offload of the Multicast Listener Discovery (MLD) protocol for the solicited node

addresses of the device IPv6 addresses.

The purpose of Multicast Listener Discovery (MLD) is to enable each IPv6 router to discover the

presence of multicast listeners (that is, nodes wishing to receive multicast packets) on its directly

attached links, and to discover specifically which multicast addresses are of interest to those

neighboring nodes. This information is then provided to whichever IPv6 multicast routing protocol such

as Neighbor Solicitation (NS) is being used by the router, in order to ensure that multicast packets are

delivered to all links where there are interested receivers. If no responses are received on a specific link

where MLD queries for a specific multicast address then a packet with this multicast address will not be

forwarded to this Link.

MLD is a sub-protocol of ICMPv6, MLD message types are a subset of the set of ICMPv6 messages, and

MLD messages are identified in IPv6 packets by a preceding Next Header value of 58 (i.e. the ICMPv6

Next Header value).

Two versions of MLD messaging (MLDv1 and MLDv2) are defined in:

- RFC 2710, Multicast Listener Discovery (MLDv1) for IPv6, 1999
- RFC 3810, Multicast Listener Discovery Version 2 (MLDv2) for IPv6, 2004

MLDv2 is designed to be inter-operable with MLDv1.

MLD messages supported by the I219

As a Receiver:

- Multicast Listener Query (ICMPv6 Type = decimal 130).

There are two subtypes of Multicast Listener Query messages supported by the I219:

— General Query used to learn which multicast addresses have listeners on an attached link.

```
— Multicast-Address-Specific Query, used to learn if a particular multicast address has any
listeners on an attached link.
```
As a Transmitter:

- Multicast Listener Report (ICMPv6 Type = decimal 131).


Device Functionality—Intel® Ethernet Connection I219

7.5.5.1 MLD Query Packet

```
Offset # of bytes Field
Value
(hex)
Action Comment
```
```
0 6 Destination Address Compare
```
```
MAC Header.
Processed by main address filter
```
```
6 6 Source Address Skip
```
```
12 S=(0/4) Possible VLAN Tag Skip
```
```
12+S D=(0/8) Possible LLC/SNAP Header Skip
```
```
IPv6 header
```
```
12+D+S 2 Type 0x86DD Compare IPv6
```
```
14+D+S 1 Version/ Traffic Class 0x6 Compare Check IPv6
```
```
15+D+S 3 Traffic Class/Flow Label Ignore
```
```
18+D+S 2 Payload Length Ignore
```
```
20+D+S 1 Next Header 0x00 Compare Hop by Hop
```
```
21+D+S 1 Hop Limit 0x01 Compare
```
```
22+D+S 16 Source Address Ignore
```
```
38+D+S 16 Destination Address Compare
```
```
Hop by Hop header
```
```
54+D+S 1 Next Header 0x3A Compare ICMPv6
```
```
55+D+S 1 Header Extended Length 0x00 Compare
```
```
56+D+S 1 Type 0x05 Ignore Router Alert
```
```
57+D+S 1 Length 0x02 Ignore
```
```
58+D+S 2 MLD 0x0000 Ignore MLD packet
```
```
60+D+S 1 PadN Option 0x01 Ignore
```
```
61+D+S 1 PadN Length 0x00 Ignore
```
```
ICMPv6 header
```
```
62+D+S 1 Type 0x82 Compare MLD Query
```
```
63+D+S 1 Code 0x0 Ignore
```
```
64+D+S 2 Checksum Check
```
```
66+D+S 2 Maximum Respond Delay 0x0000 Ignore
```
```
68+D+S 2 Reserved 0x0000 Ignore
```
```
70+D+S 16 Multicast IP Address Compare
104 MSB FF02::0001:FFxx:xxxx
assume lower 24 bits match
```

```
Intel® Ethernet Connection I219—Device Functionality
```
7.5.5.2 MLD Report Packet

```
Offset # of bytes Field
Value
(hex)
Action
```
```
0 6 Destination Address Copy from MLD query packet
```
```
6 6 Source Address Station Address
```
```
12 S=(0/4) Possible VLAN Tag Copy from MLD packet
```
```
12+S D=(0/8) Possible LLC/SNAP Header Copy from MLD packet
```
```
IPv6 header
```
```
12+D+S 2 Type 0x86DD Constant (Copy from MLD packet)
```
```
14+D+S 1 Version/ Traffic Class 0x6 Constant (Copy from MLD packet)
```
```
15+D+S 3 Traffic Class/Flow Label Constant (Copy from MLD packet)
```
```
18+D+S 2 Payload Length
```
```
20+D+S 1 Next Header 0x00 Constant (Copy from MLD packet)
```
```
21+D+S 1 Hop Limit 0x01 Constant (Copy from MLD packet)
```
```
22+D+S 16 Source Address Link Local Address
```
```
38+D+S 16 Destination Address Multicast Address being reported
```
```
Hop by Hop header
```
```
54+D+S 1 Next Header 0x3A Constant (Copy from MLD packet)
```
```
55+D+S 1 Header Extended Length 0x00 Constant (Copy from MLD packet)
```
```
56+D+S 1 Type 0x05 Constant (Copy from MLD packet)
```
```
57+D+S 1 Length 0x02 Constant (Copy from MLD packet)
```
```
58+D+S 2 MLD 0x0000 Constant (Copy from MLD packet)
```
```
60+D+S 1 PadN Option 0x01 Constant (Copy from MLD packet)
```
```
61+D+S 1 PadN Length 0x00 Constant (Copy from MLD packet)
```
```
ICMPv6 header
```
```
62+D+S 1 Type 0x83 Constant
```
```
63+D+S 1 Code 0x00 Constant
```
```
64+D+S 2 Checksum Calculate
```
```
66+D+S 2 Maximum Respond Delay 0x0000
```
```
68+D+S 2 Reserved 0x0000
```
```
70+D+S 16 Multicast Address
Copy from MLD query packet, if undefined send a
single packet for each of Product Name IP addresses
```

Device Functionality—Intel® Ethernet Connection I219

### 7.6 Loopback .......................................................................................................................

PHY loopback is supported in the LAN Connect Device. Software or Firmware should set the LAN

Connected Device to the loopback mode via MDIC register writing to the PHY Control Register (Page 0

Register 00). The PHY supports a number of loopback modes configured through the Loopback Control

Register (Page 0 Register 19).

For more information on the different loopback modes, refer to Section 9.5.2.14.1.

The LAN Controller must be in forced link and in full duplex mode for PHY loopback to operate. The

following bits must be configured in the LAN Controller to enable PHY loopback:

- CTRL.FRCDPLX = 1b: // Force duplex mode by the integrated LAN controller
- CTRL.FD = 1b: // Set Full Duplex mode

Note: Host driver needs to disable energy detect prior to configuring the LAN Connected Device

into loopback mode.


```
Intel® Ethernet Connection I219—Device Functionality
```
NOTE: This page intentionally left blank.


PHY Functionality—Intel® Ethernet Connection I219

## 8.0 PHY Functionality

### 8.1 Reverse Auto-Negotiation .................................................................................................8

When reverse auto-negotiation (LPLU) is enabled, the auto-negotiation process proceeds as usual

except the priority resolution is resolved in the order shown in Table 8-1. The IEEE registers 4.8:5 and

9.9:8 are used to advertise the capability just like in normal auto-negotiation. Fullchip register 25_0.6

(PHY address 1, page 0, register 25, it 6) controls whether GbE mode should be advertised regardless

of the values in registers 9.9:8.

Full-chip registers 25_0.2 (PHY address 1, page 0, register 25, bit 1) and 25_0.6 (PHY address 1, page

0, register 25, bit 6) controls the auto-negotiation behavior as listed in Table 8-1. Note that the LPLU

and 1000dis signals can toggle respectively. A 1b to 0b transition sets the register to zero, and a 0b to

1b transition set the register to one.

Since these registers can be changed via signal toggling or via MDIO write access, the latest occurring

event (signal toggling or register write) will determine the values in the registers.

Registers 25_0.2 (PHY address 1, page 0, register 25, bit 2) and 25_0.6 (PHY address 1, page 0,

register 25, bit 6) will not take effect unless one of the following occurs.

- Software reset is asserted (Register 0.15)
- Restart Auto-Negotiation-Now is asserted (Register 25_0.10)

The enabling of reverse auto-negotiation and the disabling of 1000BASE-T creates some conflicts.

Table 8-2 clarifies the behavior.

Table 8-1 Reverse Auto-Negotiation Priority Resolution

```
Priority Speed/Duplex
```
```
1 (highest) 10 full-duplex
```
```
2 10 half-duplex
```
```
3 100 full-duplex
```
```
4 100 half-duplex
```
```
5 (lowest) 1000 full-duplex
```

```
Intel® Ethernet Connection I219—PHY Functionality
```
The reverse auto-negotiation mechanism works by temporarily stalling the base page exchange until

the link partners 10/100 capabilities is learned. Once the PHY learns the link partner's capability it

advertises only the desired capability, in this case the lowest speed with the highest duplex. Figure 8-1

illustrates the process in more detail.

Each time auto-negotiation is restarted all advertised capabilities are advertised to the link partner. If

reverse auto negotiation is enabled then the pause bits for every other FLP burst is inverted. Since the

link partner never sees 3 consecutive FLP burst having the same bit pattern its auto-negotiation is

stalled. At the same time the link partner advertises its capabilities. Once the PHY learns the link

partner's capabilities it determines the lowest common speed/duplex. It then no longer advertises any

higher capabilities in the FLP burst. This new set of advertisement is used and the remainder of the

auto-negotiation process continues. for example, the FLP burst pause bits are no longer toggling so the

link partner's auto-negotiation process is no longer stalled.)

Note: If two PHYs with reverse auto-negotiation enabled are connected to each other, the process

```
described above will still work. Since all advertised capabilities are initially sent to the link
partner and the speed/duplex bits are not toggling it is possible for the PHY to determine
each other's capabilities.
```
Table 8-2 Reverse Auto-Negotiation, Disable 1000BASE-T, and Down-Shift Behavior

```
Reverse/ Normal
Auto-Negotiation
Disable 1000BASE-T Action
```
```
Reverse Disable Negotiates to the lowest of 10/100/1000.
```
```
Reverse Enable Negotiates to the lowest of 10/100.
```
```
Normal Disable Negotiates to the highest of 10/100/1000.
```
```
Normal Enable Negotiates to the highest of 10/100.
```

PHY Functionality—Intel® Ethernet Connection I219

Figure 8-1 Reverse Auto-Negotiation Add-On State Machine


```
Intel® Ethernet Connection I219—PHY Functionality
```
NOTE: This page intentionally left blank.


Programmer’s Visible State—Intel® Ethernet Connection I219

## 9.0 Programmer’s Visible State

### 9.1 Terminology ...................................................................................................................

```
Shorthand Description
```
##### RW

```
Read/Write.
A register with this attribute can be read and written. If written since reset, the value read reflects the value
written.
```
##### RWS

```
Read/Write Status.
A register with this attribute can be read and written. This bit represents status of some sort, so the value read
might not reflect the value written.
```
##### RO

```
Read Only. I
f a register is read only, writes to this register have no effect.
```
##### WO

```
Write Only.
Reading this register might not return a meaningful value.
```
##### RWC

```
Read/Write Clear.
A register bit with this attribute can be read and written. However, a write of 1b clears (sets to 0b) the
corresponding bit and a write of 0b has no effect.
```
##### RW/SC

```
Read/Write Self Clearing.
When written to 1b the bit causes an action to be initiated. Once the action is complete the bit return to 0b.
```
##### RO/LH

```
Read Only, Latch High.
The bit records an event or the occurrence of a condition to be recorded. When the event occurs the bit is set to
1b. After the bit is read, it returns to 0b unless the event is still occurring.
```
##### RO/LL

```
Read Only, Latch Low.
The bit records an event. When the event occurs the bit is set to 0b. After the bit is read, it reflects the current
status.
```
##### RO/SC

```
Read Only, Self Clear.
Writes to this register have no effect. Reading the register clears (set to 0b) the corresponding bits.
```
##### RW0

```
Ignore Read, Write Zero.
The bit is a reserved bit. Any values read should be ignored. When writing to this bit always write as 0b.
```
##### RWP

```
Ignore Read, Write Preserving.
This bit is a reserved bit. Any values read should be ignored. However, they must be saved. When writing the
register the value read out must be written back. (There are currently no bits that have this definition.)
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
This document names registers as follows.

- By register number

— Registers 0-15 are independent of the page and can be designated by their register number.

— When a register number is used for registers 16-21, or 23-28, it refers to the register in page 0.

```
— Register 31 in PHY address 01, is the page register itself and doesn’t belong to any page. It is
always written as register 31.
```
- By page and register number

— This can be written out as page x, register y, but is often abbreviated x.y

- By name

— Most functional registers also have a name.

Register bits are designated by a dot followed by a number after the register address. Thus, bit 4.16.2

is page 4, register 16 and bit 2. Multi-bit fields follow the MSB, colon, LSB convention and so bits

4.16.5:4 is page 4, register 16, bits 5:4. All fields in a register have a name.

Register bits with default values marked with an asterisk * are loaded by the integrated LAN controller

during I219 power up and following reset. Other fields in the same 16-bit register must be loaded with

their default values.

### 9.2 MDIO Access ..................................................................................................................

After LCD reset to the I219 a delay of 10 ms is required before attempting to access MDIO registers.

Access using MDIO should be done only when bit 10 in page 769 register 16 is set.

### 9.3 Addressing .....................................................................................................................

Addressing is based on the IEEE 802.3 MII Management Interface specification defined in clause 22 of

802.3, particularly section 22.2.4.

The I219 registers are spread over two PHY addresses 01, 02, where general registers are located

under PHY address 01 and the PHY specific registers are at PHY address 02. The IEEE specification

allows five bits for the register access. Registers 0 to 15 are defined by the specification, while registers

16 to 31 are left available to the vendor. The PHY implements many registers for diagnostic purposes.

In addition, the I219 contains registers controlling the custom interface as well as other I219 functions.

The total number of registers implemented far exceeds the 16 registers available to the vendor. When

this occurs, a common technique is to use paging. The I219 registers in PHY address 01, are divided

into pages. Each page has 32 registers. Registers 0-15 are identical in all the pages and are the IEEE

defined registers. Register 31 is the page register in all pages of PHY address 01. All other registers are

page-specific.

In order to read or write a register software should define the appropriate PHY address. For PHY

address 01, in order to access registers other than 0-15, software should first set the page register to

map to the appropriate page. Software can then read or write any register in that page. Setting the

page is done by writing page_num x 32 to Register 31. This is because only the 11 MSB’s of register 31

are used for defining the page. During write to the page register, the five LSB’s are ignored.


Programmer’s Visible State—Intel® Ethernet Connection I219

In pages 800 and 801, the register address space is more than 32. Refer to Section 9.5.9 for a

description of registers addressing in these pages.

Accessing more than 32 registers in PHY address 02, is done without using pages. Instead, two

registers from register address 16 to 31 are used as Address Offset port and Data port for extended set

of registers. Refer to Section 9.5.2 for details about these registers.

### 9.4 Registers Byte Ordering

This section defines the structure of registers that contain fields carried over the network. Some

examples are L2, L3, L4 fields.

The following example is used to describe byte ordering over the wire (hex notation):

Last First

...,06, 05, 04, 03, 02, 01, 00

where each byte is sent with the LSbit first. That is, the bit order over the wire for this example is

Last First

..., 0000 0011, 0000 0010, 0000 0001, 0000 0000

The general rule for register ordering is to use Host Ordering (also called little endian). Using the

above example, a 6-byte fields (e.g. MAC address) is stored in a CSR in the following manner:

Byte 1 Byte0

DW address (N) 0x01 0x00

DW address (N+1) 0x03 0x02

DW address (N+2) 0x05 0x04

The exceptions listed below use network ordering (also called big endian). Using the above example, a

16-bit field (e.g. EtherType) is stored in a register in the following manner:

Byte 1 Byte0

(Word aligned) 0x00 0x01

The following exceptions use network ordering:

- All ETherType fields

Note: The “normal” notation as it appears in text books, etc. is to use network ordering. Example:

```
Suppose a MAC address of 00-A0-C9-00-00-00. The order on the network is 00, then A0,
then C9, etc. However, the host ordering presentation would be
```
Byte 1 Byte0

DW address (N) A0 00

DW address (N+1) 00 C9

DW address (N+2) 00 00


```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
### 9.5 Register Definitions .........................................................................................................

#### 9.5.1 Address Map ....................................................................................................

Table 9-1 Address Map

##### PHY

```
Address
```
```
Page Register Name Link
```
```
PHY Registers
```
```
02 Any 0 Control 95
```
```
02 Any 1 Status 96
```
```
02 Any 2 PHY Identifier 1 97
```
```
02 Any 3 PHY Identifier 2 97
```
```
02 Any 4 Auto-Negotiation Advertisement 98
```
```
02 Any 5 Auto-Negotiation Link Partner Ability 99
```
```
02 Any 6 Auto-Negotiation Expansion 100
```
```
02 Any 7 Auto-Negotiation Next Page Transmit 100
```
```
02 Any 8 Link Partner Next Page 101
```
```
02 Any 9 1000BASE-T Control 101
```
```
02 Any 10 1000BASE-T Status 102
```
```
02 Any 11 - 14 Reserved
```
```
02 Any 15 Extended Status 103
```
```
02 0 16 - 17 Reserved
```
```
02 0 18 PHY Control 2 103
```
```
02 0 19 Loopback Control 105
```
```
02 0 20 Rx Error Counter 106
```
```
02 0 21 Management Interface (MI) 106
```
```
02 0 22 PHY Configuration 106
```
```
02 0 23 PHY Control 107
```
```
02 0 24 Interrupt Mask 108
```
```
02 0 25 Interrupt Status 109
```
```
02 0 26 PHY Status 110
```
```
02 0 27 LED Control 1 111
```
```
02 0 28 LED Control 2 112
```
```
02 0 29 LED Control 3 113
```
```
02 0 30 Late Collision Counter 113
```
```
02 0 31 Link Polarity and Length Status 114
```

Programmer’s Visible State—Intel® Ethernet Connection I219

```
Port Control Registers
```
```
01 769 16 Custom Mode Control 115
```
```
01 769 17 Port General Configuration 115
```
```
01 769 21 Power Management Control 116
```
```
01 769 23 SMBus Control 116
```
```
01 769 25 Rate Adaptation Control 116
```
```
01 769 27 Flow Control Transmit Timer Value 117
```
```
01 769 28 System Low Power Control – SxCTRL 117
```
```
01 764 23 - 24 SERDES MDI Control Register – SMDIC 117
```
```
Statistics Registers
```
```
01 778 16 - 17 Single Collision Count – SCC 119
```
```
01 778 18 - 19 Excessive Collisions Count – ECOL 119
```
```
01 778 20 - 21 Multiple Collisions Count – MCC 119
```
```
01 778 23 - 24 Late Collision Count – LATECOL 120
```
```
01 778 25 - 26 Collision Count – COLC 120
```
```
01 778 27 - 28 Defer Count – DC 120
```
```
01 778 29 - 30 Transmit with No CRS – TNCRS 121
```
```
PCIe Registers
```
```
01 770 16 PCIe FIFOs Control/Status 122
```
```
01 770 17 PCIe Power Management Control 122
```
```
01 770 18 In-Band Control 123
```
```
01 770 20 PCIe Diagnostics 123
```
```
01 770 21 Timeouts 123
```
```
01 770 23 PCIe K-State Minimum Duration Timeout 124
```
```
LPI Registers
```
```
01 772 18 Low Power Idle GPIO Control 125
```
```
01 772 20 Low Power Idle Control 125
```
```
01 772 23 Flow Control Refresh Threshold Value – FCRTV 126
```
```
01 772 24 Flow Control Thresholds – FCTH 126
```
```
01 772 25 LANWAKE# Control – LANWAKEC 126
```
```
01 772 26 Memories Power 127
```
```
01 772 29 Configuration 127
```
Table 9-1 Address Map (Continued)

##### PHY

```
Address
```
```
Page Register Name Link
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
```
ULP Registers
```
```
01 779 16 ULP Configuration 1 128
```
```
01 779 17 ULP Configuration 2 128
```
```
01 779 18 ULP SW Control 129
```
```
01 779 19 SW Control 129
```
```
01 779 20 Off Board LAN Connected Device Control 130
```
```
General Registers
```
```
01 776 19 I219 Capability 131
```
```
01 0 25 OEM Bits 131
```
```
01 0 26 SMBus Address 132
```
```
01 0 27 - 28 Shadow Receive Address Low0 – SRAL0 133
```
```
01 0 29 Shadow Receive Address High0 – SRAH0 133
```
```
01 0 30 LED Configuration 133
```
```
Wake Up Registers
```
```
01 800 0 Receive Control – RCTL 137
```
```
01 800 1 Wake Up Control – WUC 138
```
```
01 800 2 Wake Up Filter Control – WUFC 138
```
```
01 800 3 Wake Up Status – WC 139
```
```
01 800 16 - 17 Receive Address Low – RAL 140
```
```
01 800 18 - 19 Receive Address High – RAH 140
```
```
01 800 20-21 + 4*n (n=0...10) Shared Receive Address Low – SHRAL 140
```
```
01 800 22-23 + 4*n (n=0...8,10) Shared Receive Address High – SHRAH 141
```
```
01 800 58 - 59 Shared Receive Address High 9 – SHRAH[9] 141
```
```
01 800 64 IP Address Valid – IPAV 141
```
```
01 800 70 Proxy Control – PRXC 142
```
```
01 800 71 Proxy Code Checksum – PRCC 143
```
```
01 800 72 Proxy Control 2 – PRXC2 143
```
```
01 800 75 Flex Filters Proxy Control – FFPRXC 143
```
```
01 800 76 Wake Up Filter Control 2 – WUFC2 144
```
```
01 800 77 Wake Up Filter Status 2 – WUS2 144
```
```
01 800 78 Wake Up Filter Control 3 – WUFC3 144
```
```
01 800 79 Wake Up Filter Status 3 – WUS3 145
```
```
01 800 80 Wake Up Filter Control 4 – WUFC4 145
```
```
01 800 81 Wake Up Filter Status 4 – WUS4 145
```
```
01 800 82-83 + 2*n (n=0, 1, 2) IPv4 Address Table – IP4AT 145
```
```
01 800 88-89 + 2*n (n=0...3) IPv6 Address Table – IP6AT[3:0] 145
```
Table 9-1 Address Map (Continued)

##### PHY

```
Address
```
```
Page Register Name Link
```

Programmer’s Visible State—Intel® Ethernet Connection I219

```
01 800 128 - 191 Multicast Table Array – MTA[31:0] 146
```
```
01 800 256 + 2*n (n=0...127) Flexible Filter Value Table LSB – FFVT_01 147
```
```
01 800 257 + 2*n (n=0...127) Flexible Filter Value Table MSBs – FFVT_23 147
```
```
01 800 512 + 2*n (n=0...127) Flexible Filter Value Table – FFVT_45 147
```
```
01 800 1024 + 2*n (n=0...127) Flexible Filter Value Table – FFVT_67 148
```
```
01 800 768 + n (n=0...127) Flexible Filter Mask Table – FFMT 148
```
```
01 800 896 + n (n=0...3) Flexible Filter Length Table – FFLT03 149
```
```
01 800 904 + n (n=0...1) Flexible Filter Length Table – FFLT45 149
```
```
01 800 908 + n (n=0...1) Flexible Filter Length Table – FFLT67 149
```
```
01 800 2304 + 2*n (n=0...127) Flexible Filter Value Table 89 – FFVT_89 150
```
```
01 800 2305 + 2*n (n=0...127) Flexible Filter Value Table 1011 – EFFVT_1011 150
```
```
01 800 2560 + 2*n (n=0...127) Flexible Filter Value Table 1213 – FFVT_1213 150
```
```
01 800 2816 + n (n=0...127) Flexible Filter Mask Table 2 – FFMT2 151
```
```
01 800 2944 + n (n=0...3) Flexible Filter Length Table 891011 – FFLT891011 151
```
```
01 800 2952 + n (n=0...1) Flexible Filter Length Table 1213 – FFLT1213 151
```
```
01 800 2956 + n (n=0...1) Flexible Filter Length Table 1415 – FFLT1415 152
```
```
01 800 3072 + 2*n (n=0...127) Flexible Filter Value Table 1415 – FFVT_1415 152
```
```
01 800 4352 + 2*n (n=0...127) Flexible Filter Value Table 1617 – FFVT_1617 152
```
```
01 800 4353 + 2*n (n=0...127) Flexible Filter Value Table 1819 – FFVT_1819 152
```
```
01 800 4608 + 2*n (n=0...127) Flexible Filter Value Table 2021 – FFVT_2021 152
```
```
01 800 4609 + 2*n (n=0...127) Flexible Filter Value Table 2223 – FFVT_2223 152
```
```
01 800 4864 + n (n=0...127) Flexible Filter Mask Table 3 – FFMT3 153
```
```
01 800 4992 + n (n=0...3) Flexible Filter Length Table 1619 – FFLT1619 153
```
```
01 800 5000 + n (n=0...1) Flexible Filter Length Table 2021 – FFLT2021 153
```
```
01 800 5004 + n (n=0...1) Flexible Filter Length Table 2223 – FFLT2223 153
```
```
01 800 6400 + 2*n (n=0...127) Flexible Filter Value Table 2425 – FFVT_2425 153
```
```
01 800 6401 + 2*n (n=0...127) Flexible Filter Value Table 2627 – FFVT_2627 153
```
```
01 800 6656 + 2*n (n=0...127) Flexible Filter Value Table 2829 – FFVT_2829 153
```
```
01 800 6657 + 2*n (n=0...127) Flexible Filter Value Table 3031 – FFVT_3031 153
```
```
01 800 6912 + n (n=0...127) Flexible Filter Mask Table 4 – FFMT4 154
```
```
01 800 7040 + n (n=0...3) Flexible Filter Length Table 2427 – FFLT2427 154
```
```
01 800 7048 + n (n=0...1) Flexible Filter Length Table 2829 – FFLT2829 154
```
```
01 800 7052 + n (n=0...1) Flexible Filter Length Table 3031 – FFLT3031 154
```
```
01 801 30 - 31 Management 2 Host Control Register – MANC2H 154
```
```
01 801 32 - 33 Management 2 Host Control Register 2 – MANC2H2 157
```
```
01 801 40 - 41 IPv4 ME Binding Control – IPV4MBC 158
```
```
01 801 42 - 43 IPv4 Host Binding Control – IPV4HBC 161
```
Table 9-1 Address Map (Continued)

##### PHY

```
Address
```
```
Page Register Name Link
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
```
01 801 50 - 51 IPv6 Binding Control – IPV6BC 163
```
```
01 801 52 SHRA Filter Enable Register – SHRAFER 165
```
```
Proxy Controller uCode
```
```
01 802 0 - 1536 Proxy Micro Code 166
```
```
Host WoL Packet
```
```
01 803 0 - 63 Host WoL Packet Data 167
```
```
01 803 64 Host WoL Packet Length 167
```
```
01 803 66 Host WoL Packet Indication Clear 167
```
```
LPI MMD PHY Registers
```
```
02 0 16-17 I219 EMI Registers 168
```
Table 9-1 Address Map (Continued)

##### PHY

```
Address
```
```
Page Register Name Link
```

Programmer’s Visible State—Intel® Ethernet Connection I219

#### 9.5.2 PHY Registers ...................................................................................................

Note: The PHY registers where directly copied from the PHY vendor document.

9.5.2.1 Control Register - Address 0

```
Field Name Bit(s) Type Default Description
```
```
Reserved 5:0 RO 0x0 Reserved. Always set to 0x0.
```
```
Speed Selection (MSB) 6 RW 1b The speed selection address 0 (bits 13 and 6) are used to
configure the link manually. Setting these bits has no effect
unless bit 12 (AN En) is cleared.
00b = 10 Mb/s
01b = 100 Mb/s
10b = 1000 Mb/s
11b = Reserved
```
```
Collision Test 7 RW 0b Enables IEEE 22.2.4.1.9 collision test.
0b = Disable collision test.
1b = Enable collision test.
```
```
Duplex Mode 8 RW 1b This bit is used to configure the link manually. Setting this bit has
no effect unless bit 12 (AN En) is cleared.
0b = Half-duplex
1b = Full-duplex
```
```
Restart Auto-Negotiation 9 RW/SC 0b 0b = Normal operation.
1b = Restarts auto-negotiation process.
```
```
Isolate 10 RW 0b Setting this bit isolates the PHY from the MII or GMII interfaces.
0b = Normal operation.
1b = Isolates the PHY from MII.
```
```
Power Down 11 RW 0b 0b = Normal operation.
1b = Power down.
```
```
Auto-Negotiation Enable 12 RW 1b When this bit is cleared, the link configuration is determined
manually.
0b = Disables auto-negotiation process.
1b = Enables auto-negotiation process.
```
```
Speed Select (LSB) 13 RW 0b The speed selection address 0 (bits 13 and 6) are used to
configure the link manually. Setting these bits has no effect
unless bit 12 (AN En) is cleared.
00b = 10 Mb/s
01b = 100 Mb/s
10b = 1000 Mb/s
11b = Reserved
```
```
Loopback 14 RW 0b This is the master enable for digital and analog loopback as
defined by the IEEE standard. The exact type of loopback is
determined by the Loopback Control register (19).
0b = Disables loopback.
1b = Enables loopback.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.2 Status Register - Address 1

```
Reset 15 RW/SC 0b Writing a 1b to this bit causes immediate PHY reset. Once the
operation completes, this bit clears to 0b automatically
0b = Normal operation.
1b = PHY reset.
```
```
Field Name Bit(s) Type Default Description
```
```
Extended Capability 0 RO 1b Indicates that the PHY provides an extended set of capabilities
that might be accessed through the extended register set.
For a PHY that incorporates a GMII/RGMII, the extended
register set consists of all management registers except
registers 0, 1, and 15.
1b = Extended register capabilities.
```
```
Jabber Detect 1 RO/LH 0b 0b = Jabber condition not detected.
1b = Jabber condition detected.
```
```
Link Status 2 RO/LL 0b This bit indicates that a valid link has been established. Once
cleared, due to link failure, this bit remains cleared until
register 1 is read via the management interface.
0b = Link is down.
1b = Link is up.
```
```
Auto-Negotiation Ability 3 RO 1b 0b = PHY not able to perform auto-negotiation.
1b = PHY able to perform auto-negotiation.
```
```
Remote Fault 4 RO/LH 0b This bit indicates that a remote fault has been detected. Once
set, it remains set until it is cleared by reading register 1 via
the management interface or by PHY reset.
0b = Remote fault condition not detected.
1b = Remote fault condition detected.
```
```
Auto-Negotiation Complete 5 RO 0b This bit is set after auto-negotiation completes.
0b = Auto-negotiation process not complete.
1b = Auto-negotiation process complete.
```
```
MF Preamble Suppression 6 RO 1b 1b = PHY accepts management frames with preamble
suppressed.
```
```
Reserved 7 RO 0b Reserved. Must always be set to 0b.
```
```
Extended Status 8 RO 1b Extended status information in the register Extended Status
(0xF).
```
```
100BASE-T2 Half-Duplex 9 RO 0b Not able to perform 100BASE-T2.
```
```
100BASE-T2 Full-Duplex 10 RO 0b Not able to perform 100BASE-T2.
```
```
10 Mb/s Half-Duplex 11 RO 1b 0b = Not 10BASE-T half duplex capable.
1b = 10BASE-T half duplex capable.
```
```
10 Mb/s Full-Duplex 12 RO 1b 0b = Not 10BASE-T full duplex capable.
1b = 10BASE-T full duplex capable.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.3 PHY Identifier Register 1 - Address 2

9.5.2.4 PHY Identifier Register 2 - Address 3

```
100BASE-TX Half-Duplex 13 RO 1b 0b = Not 100BASE-TX half duplex capable.
1b = 100BASE-TX half duplex capable.
```
```
100BASE-TX Full-Duplex 14 RO 1b 0b = Not 100BASE-TX full duplex capable.
1b = 100BASE-TX full duplex capable.
```
```
100BASE-T4 15 RO 0b 100BASE-T4.
This protocol is not supported. This register bit is always set to
0b.
0b = Not 100BASE-T4 capable.
```
```
Field Name Bit(s) Type Default Description
```
```
PHY ID Number1^1
```
1. PHY ID Number based on Intel assigned OUI number of 00-AA-00 following bit reversal.

```
15:0 RO 0x0154 The PHY identifier composed of bits 3 through 18 of the Organizationally
Unique Identifier (OUI).
```
```
Field Name Bit(s) Type Default Description
```
```
Revision Number 3:0 RO 0x1 The value is part of the PHY identifier and represents the Device
Revision Number.
```
```
Model Number 9:4 RO 0xA The value is part of the PHY identifier and represents the Device Model
Number.
```
```
PHY ID Number^1
```
1. PHY ID Number based on Intel assigned OUI number of 00-AA-00 following bit reversal.

```
15:10 RO 0x0 The PHY identifier composed of bits 19 through 24 of the OUI.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.5 Auto-Negotiation Advertisement Register -

Address 4

Note: Any write to the Auto-Negotiation Advertisement register, prior to auto-negotiation

```
completion, is followed by a restart of auto-negotiation. Also note that this register is not
updated following auto-negotiation.
```
```
Field Name Bit(s) Type Default Description
```
```
Selector Field 4:0 RW 00001b 00001b = IEEE 802.3 CSMA/CD.
```
```
10BASE-TX Half-Duplex
Capable
```
```
5 RW 1b 0b = Not 10BASE-TX half duplex capable.
1b = 10BASE-TX half duplex capable.
```
```
10BASE-TX Full-Duplex
Capable
```
```
6 RW 1b 0b = Not 10BASE-TX full duplex capable.
1b = 10BASE-TX full duplex capable.
```
```
100BASE-TX Half-Duplex
Capable
```
```
7 RW 1b 0b = Not 100BASE-TX half duplex capable.
1b = 100BASE-TX half duplex capable.
```
```
100BASE-TX Full-Duplex
Capable
```
```
8 RW 1b 0b = Not 100BASE-TX full duplex capable.
1b = 100BASE-TX full duplex capable.
```
```
100BASE-T4 Capability 9 RO 0b The PHY does not support 100BASE-T4. The default value of this
register bit is 0b.
0b = Not 100BASE-T4 capable.
1b = 100BASE-T4 capable.
```
```
Pause Capable 10 RW 0b 0b = Not capable of pause operation.
1b = Capable of full duplex pause operation.
```
```
Asymmetric Pause 11 RW 0b 0b = Advertises no asymmetric pause ability.
1b = Advertises asymmetric pause ability.
```
```
Reserved 12 RO 0b Reserved.
```
```
Remote Fault 13 RW 0b 0b = Advertises no remote fault detected.
1b = Advertises remote fault detected.
```
```
Reserved 14 RO 0b Reserved. Must always be set to 0b.
```
```
Next Page 15 RW 0b 0b = Advertises next page ability not supported.
1b = Advertises next page ability supported.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.6 Auto-Negotiation Link Partner Ability Register -

Address 5

```
Field Name Bit(s) Type Default Description
```
```
Protocol Selector Field 4:0 RO 0x00 Link partner protocol selector field.
```
```
10BASE-T Half-Duplex
Capability
```
```
5 RO 0b 0b = Link partner is not 10BASE-T half-duplex capable.
1b = Link partner is 10BASE-T half-duplex capable.
```
```
10BASE-T Full-Duplex
Capability
```
```
6 RO 0b 0b = Link partner is not 10BASE-T full-duplex capable.
1b = Link partner is 10BASE-T full-duplex capable.
```
```
100BASE-TX Half-Duplex
Capability
```
```
7 RO 0b 0b = Link partner is not 100BASE-TX half-duplex capable.
1b = Link partner is 100BASE-TX half-duplex capable.
```
```
100BASE-TX Full-Duplex
Capability
```
```
8 RO 0b 0b = Link partner is not 100BASE-TX full-duplex capable.
1b = Link partner is 100BASE-TX full-duplex capable.
```
```
100BASE-T4 Capability 9 RO 0b 0b = Link partner is not 100BASE-T4 capable.
1b = Link partner is 100BASE-T4 capable.
```
```
Pause Capable 10 RO 0b 0b = Link partner is not capable of pause operation.
1b = Link partner is capable of full duplex pause operation.
```
```
Asymmetric Pause 11 RO 0b 0b = Link partner does not request asymmetric pause.
1b = Link partner requests asymmetric pause.
```
```
Reserved 12 RO 0b Reserved.
```
```
Remote Fault 13 RO 0b 0b = Link partner has not detected remote fault.
1b = Link partner has detected remote fault.
```
```
Acknowledge 14 RO 0b 0b = Link partner has not received link code word.
1b = Link partner has received link code word.
```
```
Next Page 15 RO 0b 0b = Link partner does not have next page ability.
1b = Link partner has next page ability.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.7 Auto-Negotiation Expansion Register - Address

6

9.5.2.8 Auto-Negotiation Next Page Transmit Register -

Address 7

```
Field Name Bit(s) Type Default Description
```
```
Link Partner Auto-Negotiation
Ability
```
```
0 RO 0b 0b = Link partner does not have auto-negotiation capability.
1b = Link partner has auto-negotiation capability.
```
```
Page Received 1 RO/LH 0b 0b = A new page has not been received from a link partner.
1b = A new page has been received from a link partner.
```
```
Next Page Capability 2 RO/LH 1b 0b = Local device does not have next page capability.
1b = Local device has next page capability.
```
```
Link Partner Next Page Ability 3 RO 0b 0b = Link partner does not have next page capability.
1b = Link partner has next page capability.
```
```
Parallel Detection Fault 4 RO/LH 0b 0b = Parallel link fault not detected.
1b = Parallel link fault detected.
```
```
Reserved 15:5 RO 0x00 Reserved. Must always be st to 0x00.
```
```
Field Name Bit(s) Type Default Description
```
```
Message/Unformatted
Field
```
```
10:0 RW 0x3FF Next page message code or unformatted data.
```
```
Toggle 11 RO 0b 0b = Previous value of transmitted link code word was a logic one.
1b = Previous value of transmitted link code word was a logic zero.
```
```
Acknowledge 2 12 RW 0b 0b = Cannot comply with message.
1b = Complies with message.
```
```
Message Page 13 RW 1b 0b = Unformatted page.
1b = Formatted page.
```
```
Reserved 14 RO 0b Reserved.
```
```
Next Page 15 RW 0b 0b = Sending last next page.
1b = Additional next pages to follow.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.9 Link Partner Next Page Register - Address 8

9.5.2.10 1000BASE-T Control PHY Register - Address 9

```
Field Name Bit(s) Type Default Description
```
```
Message/Unformatted
Code Field
```
```
10:0 RO 0x00 Next page message code or unformatted data.
```
```
Toggle 11 RO 0b 0b = Previous value of transmitted link code word was a logic one.
1b = Previous value of transmitted link code word was a logic zero.
```
```
Acknowledge2 12 RO 0b 0b = Cannot comply with message.
1b = Complies with message.
```
```
Message Page 13 RO 0b 0b = Unformatted page.
1b = Formatted page.
```
```
Acknowledge 14 RO 0b 0b = No acknowledge.
1b = Acknowledge.
```
```
Next Page 15 RO 0b 0b = Sending last next page.
1b = Additional next pages to follow.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 7:0 RO 0x00 Reserved. Set these bits to 0x00.
```
```
Advertise 1000BASE-T
Half-Duplex Capability
```
```
8 RW 0b 0b = Advertises no 1000BASE-T half-duplex capability.
1b = Advertises 1000BASE-T half-duplex capability.
Note: 1000BASE-T half-duplex not supported.
```
```
Advertise 1000BASE-T
Full- Duplex Capability
```
```
9 RW 0b 0b = Advertises no 1000BASE-T full-duplex capability.
1b = Advertises 1000BASE-T full-duplex capability.
```
```
Port Type 10 RW 0b 0b = Single port device (prefer slave).
1b = Multi-port device (prefer master).
```
```
Master/Slave
Configuration Value
```
```
11 RW 0b Setting this bit has no effect unless address 9, bit 12 is set.
0b = Configures PHY as a salve.
1b = Configures PHY as a master.
```
```
Master/Slave Manual
Configuration Enable
```
```
12 RW 0b 0b = Automatic master/slave configuration.
1b = Enables master/slave configuration.
```
```
Test Mode 15:13 RW 000b 000b = Normal mode.
001b = Test Mode 1 - Transmit waveform test.
010b = Test Mode 2 - Master transmit jitter test.
011b = Test Mode 3 - Slave transmit jitter test.
100b = Test Mode 4 - Transmit distortion test.
101b, 110b, 111b = Reserved.
```
```
Note: Logically, bits 12:8 can be regarded as an extension of the Technology Ability field in Register 4.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.11 1000BASE-T Status Register - Address 10

```
Field Name Bit(s) Type Default Description
```
```
Idle Error Count 7:0 RO 0x00 These bits contain a cumulative count of the errors detected
when the receiver is receiving idles and both local and remote
receiver status are operating correctly. The count is held at
255 in the event of overflow and is reset to zero by reading
Register 10 via the management interface or by reset.
MSB of idle error count.
```
```
Reserved 9:8 RO 00b Reserved.
```
```
Link Partner 1000BASE-T
Half-Duplex Capability
```
```
10 RO 0b 0b = Link partner not 1000BASE-T half-duplex capable.
1b = Link partner 1000BASE-T half-duplex capable.
Note: Logically, bits 11:10 might be regarded as an
extension of the Technology Ability field in Register 5.
```
```
Link Partner 1000BASE-T
Full-Duplex Capability
```
```
11 RO 0b 0b = Link partner not 1000BASE-T full-duplex capable.
1b = Link partner 1000BASE-T full-duplex capable.
Note: Logically, bits 11:10 might be regarded as an
extension of the Technology Ability field in Register 5.
```
```
Remote Receiver Status 12 RO 0b 0b = Remote receiver is incorrect.
1b = Remote receiver is correct.
```
```
Local Receiver Status 13 RO 0b 0b = Local receiver is incorrect.
1b = Local receiver is correct.
```
```
Master/Slave
Configuration Resolution
```
```
14 RO 0b Master/Slave Configuration Resolution:
0b = Local PHY resolved to slave.
1b = Local PHY resolved to master.
This bit is not valid when bit 15 is set.
```
```
Master/Slave
Configuration Fault
```
```
15 RO/LH/SC 0b Master/Slave Configuration Fault:
0b = No master/slave configuration fault detected.
1b = Master/slave configuration fault detected.
Once set, this bit remains set until cleared by the following
actions:
```
- Read of Register 10 via the management interface.
- Reset.
- Auto-negotiation completed.
- Auto-negotiation enabled.


Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.12 Extended Status Register - Address 15

9.5.2.13 PHY Control Register 2 - Address 18

```
Field Name Bit(s) Type Default Description
```
```
Reserved 11:0 RO 0x00 Reserved.
```
```
1000BASE-T Half-Duplex 12 RO 1b 0b = Not 1000BASE-T half-duplex capable.
1b = 1000BASE-T half-duplex capable.
```
```
1000BASE-T Full-Duplex 13 RO 1b 0b = Not 1000BASE-T full-duplex capable.
1b = 1000BASE-T full-duplex capable.
```
```
1000BASE-X Half-Duplex 14 RO 0b 0b = Not 1000BASE-X half-duplex capable.
```
```
1000BASE-X Full-Duplex 15 RO 0b 0b = Not 1000BASE-X full-duplex capable.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 1:0 0x0 Reserved.
```
```
Enable Diagnostics 2 RW 0b This bit enables PHY diagnostics, which include IP phone detection
and TDR cable diagnostics. It is not recommended to enable this bit
in normal operation (when the link is active). This bit does not need
to be set for link analysis cable diagnostics.
0b = Disables diagnostics.
1b = Enables diagnostics.
```
```
Reserved 8:3 0x0 Reserved.
```
##### MDI/MDI-X

```
Configuration
```
```
9 RW 0b MDI/MDI-X Configuration:
0b = Manual MDI configuration.
1b = Manual MDI-X configuration.
See Table 9-2 for further information.
```
```
Automatic MDI/MDI-X 10 RW 1b 0b = Disables automatic MDI/MDI-X configuration.
1b = Enables automatic MDI/MDI-X configuration.
```
```
Reserved 12:11 Reserved.
```
```
Count Symbol Errors 13 RW 0b Count Symbol Errors (bit 13) and Count False Carrier Events (bit
14) control the type of errors that the Rx error counter (Register 20,
bits 15:0) counts (see Table 9-3).
The default is to count CRC errors.
0b = Rx error counter counts CRC errors.
1b = Rx error counter counts symbol errors.
```
```
Count False Carrier
Events
```
```
14 RW 0b Count Symbol Errors (bit 13) and Count False Carrier Events (bit
14) control the type of errors that the Rx error counter (Register 20,
bits 15:0) counts (see Table 9-3).
The default is to count CRC errors.
0b = Rx error counter does not count false carrier events.
1b = Rx error counter counts false carrier events.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
Bit 9 of the PHY Control register manually sets the MDI/MDI-X configuration if automatic MDI-X is

disabled (see Table 9-2).

The mapping of the transmitter and receiver to pins for MDI and MDI-X configuration for 10BASE-T,

100BASE-TX, and 1000BASE-T is listed in Table 9-4. Note that even in manual MDI/MDI-X

configuration, the PHY automatically detects and corrects for C and D pair swaps.

```
Resolve MDI/MDIX
Before Forced Speed
```
```
15 RW 1b 0b = Does not resolve MDI/MDI-X configuration before forcing
speed.
1b = Resolves MDI/MDI-X configuration before forcing speed.
```
Table 9-2 MDI/MDI-X Configuration Parameters

```
Automatic
MDI/MDI-X
```
##### MDI/MDI-X

```
Configuration
MDI/MDI-X Mode
```
```
1 X Automatic MDI/MDI-X detection.
```
```
0 0 MDI configuration (NIC/DTE).
```
```
0 1 MDI-X configuration (switch).
```
Table 9-3 Rx Error Counter Characteristics

```
Count False
Carrier Events
```
```
Count Symbol
Errors
Rx Error Counter
```
```
1 1 Counts symbol errors and false carrier events.
```
```
1 0 Counts CRC errors and false carrier events.
```
```
0 1 Counts symbol errors.
```
```
0 0 Counts CRC errors.
```
Table 9-4 MDI/MDI-X Pin Mapping

```
Pin
```
```
MDI Pin Mapping MDI-X Pin Mapping
```
##### 10BASE-T 100BASE-TX 1000BASE-T 10BASE-T 100BASE-TX 1000BASE-T

```
TRD[0]+/- Tx +/- Tx +/-
Tx A+/-
Rx B+/-
Rx +/- Rx +/-
Tx B+/-
Rx A+/-
```
```
TRD[1]+/- Rx +/- Rx +/-
Tx B+/-
Rx A+/-
Tx +/- Tx +/-
Tx A+/-
Rx B+/-
```
##### TRD[2]+/-

```
Tx C+/-
Rx D+/-
```
```
Tx D+/-
Rx C+/-
```
##### TRD[3]+/-

```
Tx D+/-
Rx C+/-
```
```
Tx C+/-
Rx D+/-
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.14 Loopback Control Register - Address 19

9.5.2.14.1 Loopback Mode Settings

Table 9-5 lists how the loopback bit (Register 0, bit 14) and the Link Enable bit (Register 23, bit 13)

should be set for each loopback mode. It also indicates whether the loopback mode sets the Link Status

bit and when the PHY is ready to receive data.

```
Field Name Bit(s) Type Default Description
```
```
Force Link Status 0 RW 1b This bit can be used to force link status operational during MII loopback.
In MII loopback, the link status bit is not set unless force link status is
used. In all other loopback mode, the link status bit is set when the link
comes up.
0b = Forces link status not operational in MII loopback.
1b = Forces link status operational in MII loopback.
```
```
Reserved 5:1 Reserved.
```
```
Tx Suppression 6 RW 1b 0b = Do not suppress Tx during all digital loopback.
1b = Suppress Tx during all digital loopback.
```
```
External Cable 7 RW 0b 0b = External cable loopback disabled.
1b = External cable loopback enabled.
```
```
Reserved 8 RW Reserved.
```
```
Remote 9 RW 0b 0b = Remote loopback disabled.
1b = Remote loopback enabled.
```
```
Line Driver 10 RW 0b 0b = Line driver loopback disabled.
1b = Line driver loopback enabled.
```
```
Reserved 11 Reserved.
```
```
All Digital 12 RW 1b 0b = All digital loopback disabled.
1b = All digital loopback enabled.
```
```
Reserved 14:13 Reserved.
```
```
MII 15 RW 0b 0b = MII loopback not selected.
1b = MII loopback selected.
```
Table 9-5 Loopback Bit (Register 0, Bit 14) Settings for Loopback Mode

```
Loopback
Register 0,
Bit 14 = 1b
```
```
Register 26, Bit 6
(Link Status Set)
PHY Ready for Data
```
```
MII Yes Register 19, bit 0 After a few ms
```
```
All Digital Yes Yes Link Status
```
```
Line Driver Yes Yes Link Status
```
```
Ext Cable No Yes Link Status
```
```
Remote No Yes Never
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.15 Rx Error Counter Register - Address 20

9.5.2.16 Management Interface (MI) Register - Address

21

9.5.2.17 PHY Configuration Register - Address 22

```
Field Name Bit(s) Type Default Description
```
```
Rx Error Counter 15:0 RO/SC 0x00 16-bit Rx error counter.
Note: For error type descriptions, see Register 18, bits 13 and 14
(Section 9.5.2.13).
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 1:0 0x0 Reserved.
```
```
Energy-Detect Power-Down
Mode Transmit Enable
```
```
2 RW 1b 0b = Disables NLP transmission during energy-detect power-
down.
1b = Enables NLP transmission during energy-detect power-
down.
```
```
Energy Detect Power-Down
Enable
```
```
3 RW 1b 0b = Disables energy detect power-down.
1b = Enables energy detect power-down.
```
```
Reserved 0x0 Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 4:0 0x0 Reserved.
```
```
Transmit Clock Enable 5 RW 0b When this bit is set, the transmit test clock is available on pin
TX_TCLK.
0b = Disables output.
1b = Enables output of mixer clock (transmit clock in
1000BASE-T).
```
```
Group MDIO Mode
Enable
```
```
6 RW 0b 0b = Disables group MDIO mode.
1b = Enables group MDIO mode.
```
```
Alternate Next Page 7 RO 0b 0b = Normal operation of 1000BASE-T next page exchange.
1b = Enables manual control of 1000BASE-T next pages only.
```
```
Reserved 9:8 Reserved.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.18 PHY Control Register - Address 23

```
Automatic Speed
Down-Shift Mode
```
```
11:10 RW 11b If automatic down-shift is enabled and the PHY fails to auto-
negotiate at 1000BASE-T, the PHY falls back to attempt connection
at 100BASE-TX and, subsequently, 10BASE-T. This cycle repeats. If
the link is broken at any speed, the PHY restarts this process by
reattempting connection at the highest possible speed
(1000BASE-T).
00b = Automatic speed down-shift disabled.
01b = 10BASE-T down-shift enabled.
10b = 100BASE-TX down-shift enabled.
11b = 100BASE-TX and 10BASE-T enabled.
```
```
Reserved 14:12 RO 0x0 Reserved.
```
```
CRS Transmit Enable 15 RW 0b 0b = Disables CRS on transmit.
1b = Enables CRS on transmit in half-duplex mode.
```
```
Field Name Bit(s) Type Default Description
```
```
Force Interrupt 0 RW 0b 0b = De-asserts MDINT_N pin.
1b = Asserts MDINT_N pin.
```
```
Reserved 1 0b Reserved.
```
```
10BASE-T Preamble
Length
```
```
3:2 RW 10b 00b = 10BASE-T preamble length of zero bytes sent.
01b = 10BASE-T preamble length of one byte sent.
10b = 10BASE-T preamble length of two bytes sent.
11b = 10BASE-T preamble length of seven bytes sent.
```
##### TP_LOOPBACK

##### (10BASE-T)

```
4 RW 0b 0b = Normal operation.
1b = Disables TP loopback during half duplex.
```
```
SQE (10BASE-T) 5 RW 0b 0b = Disables heartbeat.
1b = Enables heartbeat.
```
```
Jabber (10BASE-T) 6 RW 1b 0b = Normal operation.
1b = Disables jabber.
```
```
Link Partner Detected 7 RO/LH 0b When linking is disabled, the PHY automatically monitors for the
appearance of a link partner and sets this bit if detected. Linking is
disabled when LNK_EN is cleared (bit 13 = 0b).
0b = Link partner not detected.
1b = Link partner detected.
```
```
Reserved 9:8 0x0 Reserved.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.19 Interrupt Mask Register - Address 24

```
Automatic Speed
Down-Shift Attempts
Before Down-Shift
```
```
12:10 RW 100b 000b = 1
001b = 2
010b = 3
011b = 4
100b = 5
101b = 6
110b = 7
111b = 8
```
```
LNK_EN (Link Enable) 13 RW 1b If LNK_EN is set, the PHY attempts to bring up a link with a
remote partner and monitors the MDI for link pulses. If LNK_EN is
cleared, the PHY takes down any active link, goes into stand-by,
and does not respond to link pulses from a remote link partner. In
standby, IP phone detect and TDR functions are available.
0b = Disables linking.
1b = Enables linking.
```
```
Reserved 15:14 RO 0x0 Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
MDINT_N Enable 0 RW 0b 0b = MDINT_N disabled.
1b = MDINT_N enabled.^1
```
```
Automatic Speed Down-Shift 1 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
Link Status Change 2 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
Receive Status Change 3 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
FIFO Overflow/Underflow 4 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
Error Count Full 5 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
Next Page Received 6 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
CRC Errors 7 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
Auto-Negotiation Status Change 8 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
MDIO Sync Lost 9 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.20 Interrupt Status Register - Address 25

```
TDR/IP Phone 10 RW 0b 0b = Interrupt disabled.
1b = Interrupt enabled.
```
```
Reserved 15:11 0x0 Reserved.
```
1. MDINT_N is asserted (active low) if MII interrupt pending = 1b.

```
Field Name Bit(s) Type Default Description
```
```
MII Interrupt Pending 0 RO/LH 0b An event has occurred and the corresponding interrupt
mask bit is enabled (set to 1b).
0b = No interrupt pending.
1b = Interrupt pending.
```
```
Automatic Speed Down-Shift 1 RO/LH 0b 0b = Event has not occurred.
1b = Event has occurred.
```
```
Link Status Change 2 RO/LH 0b 0b = Event has not occurred.
1b = Event has occurred.
```
```
Receive Status Change 3 RO/LH 0b 0b = Event has not occurred.
1b = Event has occurred.
```
```
FIFO Overflow/Underflow 4 RO/LH 0b 0b = Event has not occurred.
1b = Event has occurred.
```
```
Error Count Full 5 RO/LH 0b 0b = Event has not occurred.
1b = Event has occurred.
```
```
Next Page Received 6 RO/LH 0b 0b = Event has not occurred.
1b = Event has occurred.
```
```
CRC Errors 7 RO/LH 0b 0b = Event has not occurred.
1b = Event has occurred.
```
```
Auto-Negotiation Status Change 8 RO/LH 0b 0b = Event has not occurred.
1b = Event has occurred.
```
```
MDIO Sync Lost 9 RO/LH 0b If the management frame preamble is suppressed (MF
preamble suppression, Register 0, bit 6), it is possible for
the PHY to lose synchronization if there is a glitch at the
interface. The PHY can recover if a single frame with a
preamble is sent to the PHY. The MDIO sync lost interrupt
can be used to detect loss of synchronization and, thus,
enable recovery.
0b = Event has not occurred.
1b = Event has occurred.
```
```
TDR/IP Phone 10 RO/LH 0b 0b = Event has not completed.
1b = Event completed.
```
```
Reserved 15:11 0x0 Reserved.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.21 PHY Status Register - Address 26

```
Field Name Bit(s) Type Default Description
```
```
Link Partner Advertised
Asymmetric PAUSE
```
```
0 RO 0b 0b = Link partner did not advertise asymmetric PAUSE.
1b = Link partner advertised asymmetric PAUSE.
```
```
Link Partner Advertised
PAUSE
```
```
1 RO 0b 0b = Link partner did not advertise PAUSE.
1b = Link partner advertised PAUSE.
```
```
Auto-Negotiation
Enabled
```
```
2 RO 0b 0b = Both partners do not have autonegotiation enabled.
1b = Both partners have auto-negotiation enabled.
```
```
Collision Status 3 RO 0b 0b = Collision not occurring.
1b = Collision occurring.
```
```
Receive Status 4 RO 0b 0b = PHY not receiving a packet.
1b = PHY receiving a packet.
```
```
Transmit Status 5 RO 0b 0b = PHY not transmitting a packet.
1b = PHY transmitting a packet.
```
```
Link Status 6 RO 0b 0b = Link down.
1b = Link up.
```
```
Duplex Status 7 RO 0b 0b = Half duplex.
1b = Full duplex.
```
```
Speed Status 9:8 RO 11b 00b = 10BASE-T
01b = 100BASE-TX.
10b = 1000BASE-T.
11b = Undetermined.
```
```
Polarity Status 10 RO 1b 0b = Polarity normal (10BASE-T only).
1b = Polarity inverted (10BASE-T only).
```
```
Pair Swap on Pairs A
and B
```
```
11 RO 0b 0b = Pairs A and B not swapped.
1b = Pairs A and B swapped.
```
```
Auto-Negotiation Status 12 RO 0b 0b = Auto-negotiation not complete.
1b = Auto-negotiation complete.
```
```
Auto-Negotiation Fault
Status
```
```
14:13 RO 00b 00b = No auto-negotiation fault.
01b = Parallel detect auto-negotiation fault.
10b = Master/slave auto-negotiation fault.
11b = Reserved.
```
```
PHY in Standby 15 RO 0b This bit indicates that the PHY is in standby mode and is ready to
perform IP phone detection or TDR cable diagnostics. The PHY
enters standby mode when LNK_EN is cleared (Register 23,
bit 13 = 0b) and exits standby mode and attempts to auto-
negotiate a link when LNK-EN is set (Register 23, bit 13 = 1b).
0b = PHY not in standby mode.
1b = PHY in standby mode.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.22 LED Control Register 1 - Address 27

```
Field Name Bit(s) Type Default Description
```
```
Pulse Stretch 0 0 RW 1b 0b = Disables pulse stretching of LED functions: transmit
activity, receive activity, and collision.
1b = Enables pulse stretching of LED functions: transmit
activity, receive activity, and collision.
```
```
LED Output Disable 1 RW 0b The default value of this bit is set by the LED_CFG pin at reset.
0b = Enables LED outputs.
1b = Disables LED outputs.
```
```
LED Pause Duration 3:2 RW 00b The pulse duration for the setting, Register 27, bits 3:2 = 11b,
can be programmed in the range 0 ms to 2 s, in steps of 4 ms
using the extended register set.
00b = Stretch LED events to 32 ms.
01b = Stretch LED events to 64 ms.
10b = Stretch LED events to 104 ms.
11b = Reserved.
```
```
LED Blink Pattern Pause 7:4 RW 0x0 LED blink pattern pause cycles.
```
```
Reserved 9:8 0x0 Reserved.
```
```
LED_LNK/ACT Extended
Modes
```
```
10 RW 0b The LED function is programmed using this bit and Register 28.
0b = Standard modes for LED_LNK/ACT.
1b = Extended modes for LED_LNK/ACT.
```
```
LED_1000 Extended Modes 11 RW 0b The LED function is programmed using this bit and Register 28.
0b = Standard modes for LED_1000.
1b = Extended modes for LED_1000.
```
```
LED_100 Extended Modes 12 RW 0b The LED function is programmed using this bit and Register 28.
0b = Standard modes for LED_100.
1b = Extended modes for LED_100.
```
```
LED_10 Extended Modes 13 RW 0b The LED function is programmed using this bit and Register 28.
The default value of this bit is set by the LED_CFG pin at reset.
0b = Standard modes for LED_10.
1b = Extended modes for LED_10.
```
```
Two-Color Mode
LED_LNK/ACT/LED_1000
```
```
14 RW 0b If two-color mode is enabled for pair LED_LNK/ACT and
LED_1000, the signal output for LED_LNK/ACT is equal to
LED_LNK/ACT and LED_1000. When LED_LNK/ACT and
LED_1000 are not mutually exclusive (such as duplex and
collision), this mode can simplify the external circuitry because
it ensures either LED_LNK/ACT and LED_1000 is on, and not
both at the same time. The same rule applies to pair LED_100
and LED_10.
0b = Normal mode for LED_LNK/ACT and LED_1000.
1b = Two-color mode for LED_LNK/ACT and LED_1000.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.23 LED Control Register 2 - Address 28

```
Two-Color Mode
LED_100/LED_10
```
```
15 RW 0b If two-color mode is enabled for pair LED_LNK/ACT and
LED_1000, the signal output for LED_LNK/ACT is equal to
LED_LNK/ACT and LED_1000. When LED_LNK/ACT and
LED_1000 are not mutually exclusive (such as duplex and
collision), this mode can simplify the external circuitry because
it ensures either LED_LNK/ACT and LED_1000 is on, and not
both at the same time. The same rule applies to pair LED_100
and LED_10.
0b = Normal mode for LED_100 and LED_10.
1b = Two-color mode for LED_100 and LED_10.
```
```
Field Name Bit(s) Type Default Description
```
```
LED_LNK/ACT 3:0 R/W LED_CFG Standard Modes:
0000 = 1000BASE-T.
0001 = 100BASE-TX.
0010 = 10BASE-T.
0011 = 1000BASE-T on; 100BASE-TX blink.
0100 = Link established.
0101 = Transmit.
0110 = Receive.
0111 = Transmit or receive activity.
1000 = Full duplex.
1001 = Collision.
1010 = Link established (on) and activity (blink).
1011 = Link established (on) and receive (blink).
1100 = Full duplex (on) and collision (blink).
1101 = Blink.
1110 = On.
1111 = Off.
Extended modes:
0000 = 10BASE-T or 100BASE-TX.
0001 = 100BASE-TX or 1000BASE-T.
0010 = 10BASE-T (on) and activity (blink).
0011 = 100BASE-TX (on) and activity (blink).
0100 = 1000BASE-T (on) and activity (blink).
0101 = 10BASE-T or 100BASE-TX on and activity (blink).
0110 = 100BASE-TX or 1000BASE-T on and activity (blink).
0111 = 10BASE-T or 1000BASE-T.
1000 = 10BASE-T or 1000BASE-T on and activity (blink).
All other values are reserved.
```
```
LED_100 7:4 R/W LED_CFG See description for bits 3:0.
```
```
LED_100 11:8 R/W LED_CFG See description for bits 3:0
```
```
LED_10 15:12 R/W LED_CFG See description for bits 3:0
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.2.24 LED Control Register 3 - Address 29

9.5.2.25 Late Collision Counter - Address 30

```
Field Name Bit(s) Type Default Description
```
```
LED Blink Pattern 7:0 RW 0x55 LED Blink Pattern
The default pattern is 512 ms blink.
```
```
LED Blink Pattern Frequency 13:8 RW 0x1F LED Blink Pattern clock frequency divide ratio.
The default pattern is 512 ms blink.
```
```
LED Blink Pattern Address 15:14 RW 00b Select LED blink pattern register set:
00b = Select register set for LED_LNK/ACT.
01b = Select register set for LED_1000.
10b = Select register set for LED_100.
11b = Select register set for LED_10.
```
```
Field Name Bit(s) Type Default Description
```
```
LateColCnt02 7:0 RO/SC 0x00 When the PHY is operating in half duplex mode collisions may occur during
bytes 0 to 63 of a transmit frame. Collisions occurring after that are
counted by the late collision counters as follows:
Late col cnt 0: Collisions during bytes 64 - 95
Late col cnt 1: Collisions during bytes 96 - 127
Late col cnt 2: Collisions during bytes 128 - 191
Late col cnt 3: Collisions during bytes 192 - 319
If any counter saturates then all of the counters stop incrementing.
To use the late collision counters the LateColCntEn register in the indirect
access address map must be set.
```
```
LateColCnt13 15:8 RO/SC 0x00 Each of the late collision counters is 8 bits. They can be read two at a time.
The LateColCnt02 field corresponds either to counter 0 or 2 and the
LateColCnt13 field corresponds either to counter 1 or 3 depending on the
value of LateColCnt23Sel.
When LateColCnt23Sel is clear counters 0 and 1 may be read. After
reading counters 0 and 1 all of the counters stop incrementing and
LateColCnt23Sel is set so as to allow counters 2 and 3 to be read. After
reading counters 2 and 3 all of the counters are cleared and start
incrementing once again and LateColCnt23Sel is cleared.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.2.26 Link Polarity and Length Status - Address 31

```
Field Name Bit(s) Type Default Description
```
```
B1000DscrAcqErr 0 RO 0b The 1000BASE-T descrambler acquisition error bit indicates that
1000BASE-T link establishment failed at the descrambler acquisition
stage. The most likely explanation for this failure is excessive pair skew.
Once this bit goes high it latches high until it is cleared by a subsequent
successful 1000BASE-T descrambler acquisition
```
```
Reserved 1 RO 0b Reserved.
```
```
DspCblLen 9:2 RO 0xFF This field allows the cable length estimate determined by the DSP
engine to be observed. This estimate is computed during establishment
of a 100BASE-TX or 1000BASE-T link.
The reported cable length is in meters with the value 8'd255 indicating
indeterminate.
```
```
Pair0PolInv 10 RO 0b The pair 0 polarity inverted bit indicates that the PHY has detected that
the polarity of the signal that it is receiving on pair 0 is inverted. The
PHY can detect this condition in the case of a 10BASE-T link when the
Pair01Swap bit is set or in the case of a 1000BASE-T link.
```
```
Pair1PolInv 11 RO 0b The pair 1 polarity inverted bit indicates that the PHY has detected that
the polarity of the signal that it is receiving on pair 1 is inverted. The
PHY can detect this condition in the case of a 10BASE-T link when the
Pair01Swap bit is clear or in the case of a 1000BASE-T link.
```
```
Pair2PolInv 12 RO 0b The pair 2 polarity inverted bit indicates that the PHY has detected that
the polarity of the signal that it is receiving on pair 2 is inverted. The
PHY can only detect this condition in the case of a 1000BASE-T link.
```
```
Pair3PolInv 13 RO 0b The pair 3 polarity inverted bit indicates that the PHY has detected that
the polarity of the signal that it is receiving on pair 3 is inverted. The
PHY can only detect this condition in the case of a 1000BASE-T link.
```
```
Pair23Swap 14 RO 0b The pairs 2 and 3 swapped bit indicates that the PHY has detected that
dimensions 2 and 3 are swapped.
This bit is asserted when the PHY determines that it is receiving on pair
2 the signal that is being transmitted by the link partner on pair 2
whereas this signal is expected to be received on pair 3.
```
```
LateColCnt23Sel 15 RO 0b This bit indicates that late collision counters 2 and 3 are selected for
read. See LateColCnt02 and LateColCnt13 for more information.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

#### 9.5.3 Port Control Registers......................................................................................

9.5.3.1 Custom Mode Control PHY Address 01, Page

769, Register 16

9.5.3.2 Port General Configuration PHY Address 01,

Page 769, Register 17

```
Field Name Bit(s) Type Default Description
```
```
Reserved 9:0 RW 0x180 Reserved.
```
```
MDIO frequency access 10 RW 0b 0b = normal MDIO frequency access
1b = reduced MDIO frequency access
(required for read during cable disconnect)
```
```
Reserved 15:11 RW 0x04 Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 1:0 RO 00b Reserved.
```
```
MACPD_enable 2 Written as 1b when the integrated LAN controller needs to globally
enable the MAC power down feature while the I219 supports WoL.
When set to 1b, pages 800 and 801 are enabled for configuration and
Host_WU_Active is not blocked for writes.
```
```
Wakeup clocks stop 3 Wake-up clocks are stopped while wake up is disabled.
```
```
Host_WU_Active 4 Enables host wake up from the I219. This bit is reset by power on
reset only.
```
```
Reserved 5 RW 1b Reserved.
```
```
Active_PD_enable 6 Active Power Down Enable (sD3 Enable)
When set to 1b, The MAC needs to enter integrated LAN controller
power down mode.
```
```
Reserved 7 RW 0b Reserved.
```
```
BP extension Wait 10:8 RW 000b Additional waiting byte times after TX Gate Wait IPG expires until the
Back Pressure In-band bit is cleared.
```
```
Tx Gate Wait IFS 15:11 RW 00111b Determines the size (in nibbles) of non-deferring window from CRS
de-assertion.
```
```
Note: Register resets on Power Good only.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.3.3 Power Management Control Register PHY

Address 01, Page 769, Register 21

9.5.3.4 SMBus Control Register PHY Address 01, Page

769, Register 23

9.5.3.5 Rate Adaptation Control Register PHY Address

01, Page 769, Register 25

```
Field Name Bit(s) Type Default Description
```
```
Retry late collision 0 RW 0b Retry late collision.
```
```
Collision threshold 8:1 RW 0x0F Number of retries for a collided packet.
```
```
Reserved 15:9 RO 0x00 Reserved. Write to 0x00
```
```
Field Name Bit(s) Type Default Description
```
```
Force SMBus 0 RW 0b Force SMBus, reset on PCI reset de-assertion.
```
```
dis_SMB_filtering 1 RW 0b When set, disables filtering of RX packets for the SMBus.
In wake up mode, this configuration is ignored and the filters are
enabled.
```
```
Reserved 3:2 RW 0b Reserved.
```
```
Use LANWAKE# 4 RW 0b Use LANWAKE#, reset on power good.
```
```
Reserved 15:5 RO 0x400 Reserved
```
```
Field Name Bit(s) Type Default Description
```
```
read_delay_fd 4:0 RWP 10001b Reserved. Write as read.
```
```
rx_flip_bad_sfd 5 RW 1b Align the packet’s start of frame delimiter to a byte boundary in the
receive path.
```
```
Reserved 6 RW 0b Reserved. Write as read.
```
```
rx_en_crs_preamble 7 RW 0b Enable generation of early preamble based on CRS in the receive
path.
```
```
rx_en_rxdv_preamble 8 RW 1b Enable generation of early preamble based on RX_DV in the receive
path.
```
```
Reserved 15:9 Reserved. Write as read.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.3.6 Flow Control Transmit Timer Value PHY Address

01, Page 769, Register 27

9.5.3.7 System Low Power Control – SxCTRL PHY

Address 01, Page 769, Register 28

9.5.3.8 SERDES MDI Control Register – SMDIC PHY

Address 01, Page 774, Registers 23-24

This register is used by software to access the SERDES registers in the LAN Connected Device.

```
Field Name Bit(s) Type Default Description
```
```
Flow Control Transmit
Timer Value
```
```
15:0 RW 0x0000 The TTV field is inserted into a transmitted frame (either XOFF frames
or any pause frame value in any software transmitted packets). It
counts in units of slot time. If software needs to send an XON frame,
it must set TTV to 0x0000 prior to initiating the pause frame.
```
```
Note: Register resets on Power Good only.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 1:0 RO 0b Reserved
```
```
2 RW 0b Enable ICMPv6 filtering to proxy controller.
```
```
3 RW 0b Enable Flow Control in SMBus.
```
```
4 RW 0b Enable new indication for Flow Control.
```
```
Reserved 11:5 RO 1100000b Reserved
```
```
12 RW 0b Enable LPI enable to reset only on power good.
```
```
Reserved 15:13 RO 111b Reserved
```
```
Note: Register resets on Power Good only.
```
```
Field Name Bit(s) Type Default Description
```
```
DATA 15:0 RW X Data (DATA)
In a Write command, software places the data bits and the MAC shifts them
out to the LAN Connected Device.
In a Read command, the MAC reads these bits serially from the LAN
Connected Device and software can read them from this location.
```
```
REGADD 20:16 RW 00000b LAN Connected Device Register Address (REGADD)
Reg 0, 1, 2, ... 31.
```
```
PHYADD 25:21 RW 00000b LAN Connected Device Address (PHYADD)
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
OP 27:26 RW 00b Op-Code (OP)

```
00b = Reserved.
01b = MDI Write.
10b = MDI Read.
11b = Reserved.
```
R 28 RW 1b Ready Bit (R).

```
Set to 1 by LAN Controller at the end of the MDI transaction (i.e., indicates a
Read or Write has been completed). It should be reset to 0 by software at the
same time the command is written.
```
ST 30:29 RW 00b Start of Frame for the MDIO access (ST)

```
00b = MDIO access compliant to IEEE 802.3 clause 45.
01b = MDIO access compliant to IEEE 802.3 clause 22.
10b = Reserved.
11b = Reserved.
```
Reserved 31 RO 0b Reserved.

```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

#### 9.5.4 Statistics Registers..........................................................................................

Note: Each statistics register is constructed out of a pairs of two 16 bit registers.The lower 16 bits

```
of the register are mapped to the higher numbered register and the higher 16 bits of the
register are mapped to the lower numbered register.
```
9.5.4.1 Single Collision Count – SCC PHY Address 01,

Page 778, Registers 16-17

This register counts the number of times that a successfully transmitted packet encountered a single

collision. This register only increments if transmits are enabled and the I219 is in half-duplex mode.

9.5.4.2 Excessive Collisions Count – ECOL PHY Address

01, Page 778, Register 18-19

When 16 or more collisions have occurred on a packet, this register increments, regardless of the value

of collision threshold. If collision threshold is set below 16, this counter won’t increment. This register

only increments if transmits are enabled and the I219 is in half-duplex mode.

9.5.4.3 Multiple Collision Count – MCC PHY Address 01,

Page 778, Register 20-21

This register counts the number of times that a transmit encountered more than one collision but less

than 16. This register only increments if transmits are enabled and the I219 is in half-duplex mode.

```
Field Name Bit(s) Type Default Description
```
```
SCC 31:0 RO/V 0x00 Number of times a transmit encountered a single collision.
```
```
Field Name Bit(s) Type Default Description
```
```
ECC 31:0 RO/V 0x00 Number of packets with more than 16 collisions.
```
```
Field Name Bit(s) Type Default Description
```
```
MCC 31:0 RO/V 0x00 Number of times a successful transmit encountered multiple collisions.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.4.4 Late Collisions Count – LATECOL PHY Address

01, Page 778, Register 23-24

Late collisions are collisions that occur after one slot time. This register only increments if transmits are

enabled and the I219 is in half-duplex mode.

9.5.4.5 Collision Count – COLC PHY Address 01, Page

778, Register 25-26

This register counts the total number of collisions seen by the transmitter. This register only increments

if transmits are enabled and the I219 is in half-duplex mode. This register applies to clear as well as

secure traffic.

9.5.4.6 Defer Count – DC PHY Address 01, Page 778,

Register 27-28

This register counts defer events. A defer event occurs when the transmitter cannot immediately send a

packet due to the medium busy either because another device is transmitting, the IPG timer has not

expired, half-duplex deferral events, reception of XOFF frames, or the link is not up. This register only

increment if transmits are enabled. The behavior of this counter is slightly different in the I219 relative

to the 82542. For the I219, this counter does not increment for streaming transmits that are deferred

due to TX IPG.

```
Field Name Bit(s) Type Default Description
```
```
LCC 31:0 RO/V 0x00 Number of packets with late collisions.
```
```
Field Name Bit(s) Type Default Description
```
```
COLC 31:0 RO/V 0x00 Total number of collisions experienced by the transmitter.
```
```
Field Name Bit(s) Type Default Description
```
```
CDC 31:0 RO/V 0x00 Number of defer events.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.4.7 Transmit with No CRS – TNCRS PHY Address 01,

Page 778, Register 29-30

This register counts the number of successful packet transmission in which the CRS input from the I219

was not asserted within one slot time of start of transmission from the integrated LAN controller. Start

of transmission is defined as the assertion of TX_EN to the I219.

The I219 should assert CRS during every transmission. Failure to do so might indicate that the link has

failed, or the I219 has an incorrect link configuration. This register only increments if transmits are

enabled. This register is only valid when the I219 is operating at half duplex.

```
Field Name Bit(s) Type Default Description
```
```
TNCRS 31:0 RO/V 0x00 Number of transmissions without a CRS assertion from the I219.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
#### 9.5.5 PCIe Registers

9.5.5.1 PCIe FIFOs Control/Status PHY Address 01,

Page 770, Register 16

9.5.5.2 PCIe Power Management Control PHY Address

01, Page 770, Register 17

```
Field Name Bit(s) Type Default Description
```
```
Reserved 5:0 RO 000000b Reserved.
```
```
Tx FIFO Overflow 6 RO/SC 0b Tx FIFO overflow occurred.
```
```
Reserved 7 RO 0b Reserved.
```
```
Rx FIFO Overflow 8 RO/SC 0b Rx FIFO overflow occurred.
```
```
Reserved 9:15 RO 0000001b Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
Enable Electrical Idle
in Cable Disconnect
```
```
0 RW 0b Consider reserved (no entry to Electrical Idle due to Cable
Disconnect).
```
```
Reserved 4:1 RW 0010b Reserved.
```
```
Reserved 6:5 RW 00b Reserved.
```
```
PLL stop in K1 7 RW 1b Enables stopping SerDes PLL in K1 state (in 10 Mb/s and 100 Mb/s).
0b = Enable
1b = Disable
```
```
PLL stop in K1 giga 8 RW 0b Enables stopping the SERDES PLL in K1 state (in 1 Gbps)
0b = Disable
1b = Enable
```
```
Request a PCIE clock
in K1
```
```
9 RW 1b Use CLK_REQ to request PCIE clock in K1.
```
```
Reserved 12:10 RO 100b Reserved.
```
```
Giga_K1_disable 13 RW 0b When set, the I219 does not enter K1 while link speed at 1000 Mb/s.
```
```
K1 enable^1
```
1. While in SMBus mode, this bit is cleared. To re-enable K1 after switching back to PCIe, this register needs to be re-configured.

```
14 RW 0b Enable K1 Power Save Mode:
0b = Disable
1b = Enable
```
```
Reserved 15 RO 1b Reserved.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.5.3 In-Band Control PHY Address 01, Page 770,

Register 18

9.5.5.4 PCIe Diagnostic PHY Address 01, Page 770,

Register 20

9.5.5.5 Timeouts PHY Address 01, Page 770, Register

21

```
Field Name Bit(s) Type Default Description
```
```
Max retries 6:0 RW 0x7 Maximum retries when not receiving an acknowledge to an in-band
message.
```
```
kum_pad_use_dis 7 RW 0b Disables 1000 Mb/s in-band messages during packets in 10/100 Mb/s
mode.
```
```
Link status
transmit timeout
```
```
13:8 RW 0x5 Link status retransmission period in tens of microseconds.
```
```
Reserved 15:14 RW 0x0 Reserved.
```
```
Note: All in-band timeouts are multiplied by 1000 while in SMBus mode.
```
```
Field Name Bit(s) Type Default Description
```
```
In-band status
acknowledge timeout
```
```
5:0 RW 0x04 Timeout in microseconds for receiving an acknowledge for an in-band
status message.
```
```
Reserved 7:6 RW 0x0 Reserved.
```
```
Inband MDIO
acknowledge timeout
```
```
15:8 RW 0x55 Timeout in microseconds for receiving acknowledge for an in-band
MDIO message.
```
```
Note: All in-band timeouts are multiplied by 1000 while in SMBus mode.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 5:0 RW 0101000b Reserved.
```
```
K1 exit timeout 11:6 RW 0101000b These bits define how much time IDLE symbols are sent on the TX pair
after exiting from K1 state before the I219 starts sending data to the
integrated LAN controller (each bit represents 80 ns).
```
```
Reserved 15:12 RWP 0000b Reserved. Write as read.
```
```
Note: All in-band timeouts are multiplied by 1000 while in SMBus mode.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.5.6 PCIe Kstate Minimum Duration Timeout PHY

Address 01, Page 770, Register 23

```
Field Name Bit(s) Type Default Description
```
```
EI_min_dur timeout 4:0 RW 0x10 These bits define the minimum time the I219 stays in electrical idle
state once entered (each bit represents 80 ns).
```
```
Reserved 15:5 RWP 0x00 Reserved. Write as read
```
```
Note: All in-band timeouts are multiplied by 1000 while in SMBus mode.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

#### 9.5.6 LPI Registers

9.5.6.1 Low Power Idle GPIO Control PHY Address 01,

Page 772, Register 18

9.5.6.2 Low Power Idle Control PHY Address 01, Page

772, Register 20

```
Field Name Bit(s) Type Default Description
```
```
Reserved 9:0 RW 0xC9 Reserved.
```
```
TX_LPI_GPIO0 10 RW 0x0 Route Tx LPI indication to GPIO 0.
```
```
Auto EN LPI 11 RW 0x0 Auto Enable LPI after link up.
When set to 0x1 772.20[14:13] will be automatically set by HW after link
up.
```
```
Reserved 15:12 RW 0x40 Reserved.
```
```
Note: Register resets on Power Good only.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 3:0 RO 0x0 Reserved.
```
```
PllLockCnt 6:4 RW 0x2 PLL Lock Counter ¡V when LPI 100Enable or 1000Enable is asserted, this
counter forces the PLL Lock count to be in the range of 10.02 s to 81.88 s
in steps of 10.02 s.
```
```
Reserved 8:7 RW 0x0 Reserved.
```
```
PostLPICount 11:9 RW 0x1 Post LPI Counter.
When in LPI active and an Ethernet packet of an in-band XOFF message is
received from the LC count:
000b = 8 s
001b = 1 6 s
010b = 24 s
011b = 32 s
100b = 40 s
101b = 48 s
110b = 56 s
111b = 64 s
Before transmitting XOFF or a valid packet.
```
```
ForceLPI 12 RW 0x0 Force LPI Entry
When set to 1b by software the PHY enters LPI mode even when not in K1.
```
```
100Enable 13 RW 0x0 100Enable
Enable EEE on 100 Mb/s link speed.
This bit auto clears on link down.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.6.3 Flow Control Refresh Threshold Value – FCRTV

PHY Address 01, Page 772, Register 23

9.5.6.4 Flow Control Thresholds – FCTH PHY Address

01, Page 772, Register 24

9.5.6.5 LANWAKE# Control – LANWAKEC PHY Address

01, Page 772, Register 25

```
1000Enable 14 RW 0x0 1000Enable
Enable EEE on 1 Gb/s link speed.
This bit auto clears on link down.
```
```
Reserved 15 RW 0x0 Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
FCRTV 15:0 RW 0x0000 Flow Control Refresh Threshold Value (FCRTV)
This value indicates the threshold value of the flow control shadow counter.
When the counter reaches this value, and the transmit and receive buffer
fullness is still above the low threshold value), a pause (XOFF) frame is sent
to the link partner.
The FCRTV timer count interval counts at slot times of 64 byte times. If this
field is set to zero, Flow Control Refresh feature is disabled.
```
```
Note: Register resets on Power Good only.
```
```
Field Name Bit(s) Type Default Description
```
```
HTHRSH 7:0 RW 0x00 High threshold for sending XOFF (in units of 32 bytes).
```
```
LTHRSH 15:8 RW 0x00 Low threshold for sending XON (in units of 32 bytes).
```
```
Note: Register resets on Power Good only.
```
```
Field Name Bit(s) Type Default Description
```
```
Rx FIFO empty threshold 3:0 RW 0xA For flow control in SMB.
```
```
Store Host WoL packet 4 RW 0x1 Store the Host WoL packet in the Proxy RAM.
```
```
Use LANWAKE pin 5 RW 0x1 Always use LANWAKE pin to indicate WoL.
```
```
Clear LANWAKE pin 6 RW 0x0 1b = Clear the LANWAKE pin.
This bit is auto cleared to 0b.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.6.6 Memories Power PHY Address 01, Page 772,

Register 26

9.5.6.7 Configuration Register PHY Address 01, Page

772, Register 29

```
Use Legacy wake 7 RW 0x0 1b = Use 82679 WoL flows.
```
```
Reserved 8 RW 0x0 Reserved.
```
```
Filter on 1Gbps 9 RW 0x0 Filter packets in 1G for jumbo fix.
```
```
Crop ANM DA Jumbo 10 RW 0x0 Crop ANM DA in Jumbo fix.
```
```
Crop BCST DA in Jumbo 11 RW 0x0 Crop BCST DA in Jumbo fix.
```
```
Enable WoL if no packet
capture
```
```
12 RW 0x1 0b = No capture means no WoL.
1b = WoL is enabled, even if the WoL packet is not captured.
```
```
Reserved 15:13 RW 0x6 Reserved.
```
```
Note: Register resets on Power Good only.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 3:0 RW 0xF Reserved.
```
```
DIS_SMB_REL_ON_LCD 4 RW 1b Disable the SMB release on LCD reset.
```
```
Reserved 11:15 RW 0x7F Reserved.
```
```
MOEM 12 RW 0b Mask OEM bits/Gig Disable/restart AN bits impact.
```
```
Reserved 15:13 RW 0x1 Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 0 RW 0b Reserved.
```
```
ENMTAONPWRGD 1 RW 0b Enable MTA to reset only on power good.
```
```
Reserved 15:2 RW 0x3FC0 Reserved.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
#### 9.5.7 ULP Registers

9.5.7.1 ULP Configuration 1 PHY Address 01, Page 779,

Register 16

9.5.7.2 ULP Configuration 2 PHY Address 01, Page 779,

Register 17

```
Field Name Bit(s) Type Default Description
```
```
START 0 RW 0b Start
When set the HW will start the auto ULP configuration. Bit is auto
cleared once configuration is done.
```
```
SW_ACCESS 1 RW 0b Internal
If this bit is set the software can access direct to the ULP 3P3 block.
```
```
ULP_IND 2 RW 0b Power Up from ULP indication.
```
```
Reserved 3 RW 0b Reserved.
```
```
STICKY_ULP 4 RW 0b Sticky ULP
Enter ULP on Link disconnect and wake on ULP exit if WoL ME/Host on
ULP is set.
```
```
INBAND_EXIT 5 RW 0b In-band on ULP exit.
```
```
WOL_HOST 6 RW 0b WoL host on ULP exit.
```
```
WOL_ME 7 RW 0b WoL ME on ULP exit.
```
```
RESER_TO_SMBUS 8 RW 0b Reset to SMBus by default (on power on or on ULP exit, functional only
if power is supplied to the device).
```
```
EN_1G_SMBUS 9 RW 0b Enable 1 GbE in SMB mode.
```
```
EN_ULP_LANPHYPC 10 RW 0b Enable ULP on LAN disable (LANPHYPC).
```
```
Reserved 13:11 RW 0x0 Reserved.
```
```
FORCE_ULP 14 RW 0b Internal
Force PHY to energy power down.
```
```
RESET_ULP_IND 15 RW 0b Reset the ULP indication.
```
```
Field Name Bit(s) Type Default Description
```
```
MESHADOW 4:0 RW 0x0 ME 3.3v Shadow configuration.
```
```
Reserved 15:5 RW 0x00 Reserved.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.7.3 ULP SW Control PHY Address 01, Page 779,

Register 18

9.5.7.4 SW Control PHY Address 01, Page 779, Register

19

```
Field Name Bit(s) Type Default Description
```
```
SW BUS SELECTOR 3:0 RW 0x0 Select the bus address from the ULP bus table.
```
```
SW GEN WRITE ENABLE 4 RW 0b Cleared by HW after implement the current write enable by
software_write_en_to_ulp signal.
```
##### ULP SW WRITE FROM

##### REGISTER

```
5 RW 0b Select if the write will be from default ulp_bus or from bits [15:8]
on this register.
If set, this bit will choose bit [15:8] on this register.
Cleared by HW after implement the current write by
software_write_en_to_ulp signal.
```
##### ULP SW READ TO

##### REGISTER

```
6 RW 0x0 Set this bit for write the data on the selected ulp_bus on bits
[15:8] on this register.
Cleared by HW after implement the current read.
```
```
Reserved 7 RW 0b Reserved.
```
```
ULP MAILBOX 15:8 RW 0x00 This register is write-able and readable. Can be used by the
software by read modify write.
```
```
Field Name Bit(s) Type Default Description
```
```
str_wol_pkt_feautre_en 0 RW 0b Store WoL packet - Feature Enable
Cleared on smb_sel (PCIe Reset).
Note: RX gating would occur from receiving the
WoL packet until Driver reads the WoL
packet (unless gating timeout expired or
stop gate bit is set).
```
```
sw_rd_pkt 1 RW 0b Write indication from SW: Driver is ready to read
the WoL packet.
This bit is cleared upon one of following:
```
1. Reading of WoL packet from FIFO is done.
2. Gating timeout is expired.
3. stop_gate_rx_due2flex is set.

```
str_wol_pkt_no_ind_from_fltr_timeout 5:2 RW 0x3 How Many cycles after write to FIFO ends, last EOP
address would be sampled as candidate for the
WoL packet start address.
Granularity of 8 cycles.
Note: If the packet arrives without SFD, there is
no indication from the filters. This timeout
is needed to determine whether to sample
the EOP address.
Note: Cycles in wr-clk.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.7.5 Off Board LAN Connected Device Control PHY

Address 01, Page 779, Register 20

```
str_wol_pkt_gating_timeout 9:6 RW 0x2 Timeout for RX gating.
Granularity of 300 ms.
```
```
Reserved 13:10 RO 0x0 Reserved.
```
```
stop_gate_rx_due2flex 14 W1S 0b When set, gating RX due2flex WoL packet stops.
This bit is cleared by HW after gating ends.
Note: Driver can only set this bit.
```
```
gating_status 14 RO 0b Asserted while RX gating-due-to-flex-WoL-pkt is
ongoing.
```
```
Field Name Bit(s) Type Default Description
```
```
BCN_DUR 3:0 RW 0x2 Beacon Duration (BCN_DUR)
Defines the time of a single beacon cycle. Granularity in 0.5 s.
0x0 is not a valid setting.
```
```
BCN_INTER 7:4 RW 0x4 Beacon Interval (BCN_INTER)
Defines the time interval between beacons. Granularity in 50 ms.
0x0 is not a valid setting.
```
```
REF_DLY 11:8 RW 0x1 Reference Clock Delay (REF_DLY)
Defines the time K1 exit is delayed, waiting for reference clock. Granularity in
1 s.
```
```
Reserved 14:12 RW 0x0 Reserved.
```
```
OBLCD_En 15 RW 0b OBLDC Enable (OBLCD_En)
Enables the beacon feature for OBLCD connection indication.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

#### 9.5.8 General Registers............................................................................................

9.5.8.1 I219 Capability PHY Address 01, Page 776,

Register 19

9.5.8.2 OEM Bits PHY Address 01, Page 0, Register 25

```
Field Name Bit(s) Type Default Description
```
```
Ability to initiate a team 0 RO 0b Ability to initiate a team; enables teaming capability.
```
```
WfM 1 RO 0b Wired-for-Manageability (WfM)
Enables WfM, including ACPI, WoL, and PXE.
```
```
ASF 2 RO 0b Alert Standard Format (ASF)
Enables ASF support.
```
```
Reserved 3 RO 0b Reserved.
```
```
AC/DC Auto Link Speed
Connect
```
```
4 RO 0b AC/DC Auto Link Speed Connect
Enables different power management policy in AC and battery
modes.
```
```
Energy Detect 5 RO 0b Energy Detect
Enables energy detect capability.
```
```
2 Tx and 2 Rx Queues 6 RO 0b Two Tx and Two Rx Queues
0b = A single receive and a single transmit queue are
enabled.
1b = Enables dual transmit and dual receive queues.
```
```
Receive Side Scaling 7 RO 0b Receive Side Scaling (RSS)
Enables RSS.
```
```
802.1Q & 802.1p 8 RO 0b 802.1Q & 802.1p
Enables support for VLAN per 802.1Q & 802.1p.
```
```
Intel® Active Management
Technology (Intel® AMT)
and Circuit Breaker
```
```
9 RO 0b Intel® AMT and Circuit Breaker
Enables Intel® AMT and circuit breaker capability.
```
```
Reserved 15:10 RO 000000b Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 1:0 RW 00b Reserved.
```
```
rev_aneg 2 RW 0b Low Power Link Up Mechanism
Enables a link to come up at the lowest possible speed in cases where power
is more important than performance.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.8.3 SMBus Address PHY Address 01, Page 0,

Register 26

```
Reserved 5:3 RW Reserved.
```
```
a1000_dis 6 RW 0b^1 When set to 1b, 1000 Mb/s speed is disabled.
```
```
Reserved 9:7 RW 000b Reserved.
```
```
Aneg_now 10 RW 0b Restart auto-negotiation.
This bit is self clearing.
```
```
Reserved 15:11 RW 00000b Reserved.
```
1. 0b is the default value after power on reset. When PE_RST_N goes low (switches to SMBus), its value becomes 1b.

```
Field Name Bit(s) Type Default Description
```
```
SMBus Address 6:0 RW 0x00 This is the integrated LAN controller SMBus address. The I219
uses it for master functionality.
```
```
SMBus Address Valid 7 RW 0b This bit is written by the integrated LAN controller when the
SMBus Address field is updated. The I219 cannot send SMBus
transactions to the integrated LAN controller unless this bit is set.
0b = Address not valid.
1b = SMBus address valid.
```
```
SMBus Frequency Low 8 RW 0b SMBus Frequency Low
Together with SMBus Frequency High (bit 12) defines the SMBus
frequency:
High Low Frequency
0b 0b 100 KHz
0b 1b 400 KHz
1b 0b 1000 KHz
1b 1b Reserved
```
```
PEC Enable 9 RW 1b Defines if the I219 supports PEC on the SMBus.
```
```
APM Enable 10 RW 0b APM WoL enable.
```
```
SMB fragments size 11 RW 0b Select SMBus Fragments Size:
0b = Fragment size is 32 bytes.
1b = Fragment size is 64 bytes.
```
```
SMBus Frequency High 12 RW 0b SMBus Frequency High
See description for SMBus Frequency Low (bit 8)
```
```
Reserved 15:13 RO 000b Reserved.
```
```
Note: This register is reset only on internal power on reset.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.8.4 Shadow Receive Address Low0 – SRAL0 PHY

Address 01, Page 0, Registers 27-28

9.5.8.5 Shadow Receive Address High0 – SRAH0 PHY

Address 01, Page 0, Registers 29

9.5.8.6 LED Configuration PHY Address 01, Page 0,

Register 30

```
Field Name Bit(s) Type Default Description
```
```
RAL 31:0 R/W X Receive Address Low (RAL)
The lower 32 bits of the 48-bit Ethernet address n (n=0, 1...6). RAL 0 is
loaded from words 0x0 and 0x1 in the NVM.
```
```
Field Name Bit(s) Type Default Description
```
```
RAH 15:0 R/W X Shadow Receive Address High (RAH)
The upper 16 bits of the 48-bit Ethernet address n (n=0, 1...6). RAH 0 is
loaded from word 0x2 in the NVM.
```
```
Field Name Bit(s) Type Default Description
```
```
LED0 Mode 2:0 RW 100b Mode specifying what event/state/pattern is displayed on LED0.
```
```
LED0 Invert 3 RW 0b LED0_IVRT Field:
0b = Active low output.
1b = Active high output.
```
```
LED0 Blink 4 RW 1b LED0_BLINK Field:
0b = No blinking.
1b = Blinking.
```
```
LED1 Mode 7:5 RW 111b Mode specifying what event/state/pattern is displayed on LED1.
```
```
LED1 Invert 8 RW 0b LED1_IVRT Field:
0b = Active low output.
1b = Active high output.
```
```
LED1 Blink 9 RW 0b LED1_BLINK Field:
0b = No blinking.
1b = Blinking.
```
```
LED2 Mode 12:10 RW 110b Mode specifying what event/state/pattern is displayed on LED2.
```
```
LED2 Invert 13 RW 0b LED2_IVRT Field:
0b = Active low output.
1b = Active high output.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.8.7 Interrupts

The I219 maintains status bits (per interrupt cause) to reflect the source of the interrupt request.

System software is expected to clear these status bits once the interrupt is being handled.

```
LED2 Blink 14 RW 0b LED2_BLINK Field:
0b = No blinking.
1b = Blinking.
```
```
Blink rate 15 RW 0b Specifies the blink mode of the LEDs.
0b = Blinks at 200 ms on and 200 ms off.
1b = Blinks at 83 ms on and 83 ms off.
```
```
Notes:
```
1. When LED Blink mode is enabled the appropriate Led Invert bit should be set to zero.
2. The dynamic LED's modes (LINK/ACTIVITY and ACTIVITY) should be used with LED Blink mode enabled.

Table 9-6 LED Modes

```
Mode Selected Mode Source Indication
```
```
000 Link 10/1000 Asserted when either 10 or 1000 Mb/s link is established and maintained.
```
```
001 Link 100/1000 Asserted when either 100 or 1000 Mb/s link is established and maintained.
```
```
010 Link Up Asserted when any speed link is established and maintained.
```
```
011 Activity Asserted when link is established and packets are being transmitted or received.
```
```
100 Link/Activity Asserted when link is established AND when there is NO transmit or receive activity.
```
```
101 Link 10 Asserted when a 10 Mb/s link is established and maintained.
```
```
110 Link 100 Asserted when a 100 Mb/s link is established and maintained.
```
```
111 Link 1000 Asserted when a 1000 Mb/s link is established and maintained.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

#### 9.5.9 Wake Up Registers

9.5.9.1 Accessing Wake Up Registers Using MDIC

When software needs to configure the wake up state (either read or write to these registers) the MDIO

page should be set to 800 (for host accesses) until the page is not changed to a different value wake up

register access is enabled. After the page was set to the wake up page, the address field is no longer

translated as reg_addr (register address) but as an instruction. If the given address is in the [0..15]

range, meaning PHY registers, the functionality remains unchanged. There are two valid instructions:

1. Address Set – 0x11 – Wake up space address is set for either reading or writing.
2. Data cycle – 0x12 – Wake up space accesses read or write cycle.

9.5.9.1.1 Wake Area Read Cycle

For the I219 the wake area read cycle sequence of events is as follows:

1. Setting page 800 The software device driver performs a write cycle to the MDI register with:

a. Ready = 0b

b. Op-Code = 01b (write)

c. PHYADD = The I219’s address from the MDI register

d. REGADD = Page setting

e. DATA = 800 (wake up page)

2. Address setting; the software device driver performs a write cycle to the MDI register with:

a. Ready = 0b

b. Op-Code = 01b (write)

c. PHYADD = The I219’s address from the MDI register

d. REGADD = 0x11 (address set)

e. DATA = XXXX (address of the register to be read)

3. Reading a register; the software device driver performs a write cycle to the MDI register with:

a. Ready = 0b

b. Op-Code = 10b (read)

c. PHYADD = The I219’s address from the MDI register

d. REGADD = 0x12 (data cycle for read)

e. DATA = YYYY (data is valid when the ready bit is set)


```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.1.2 Wake Area Write Cycle

For the I219, the wake area write cycle sequence of events is as follows:

1. Setting page 800; the software device driver performs a write cycle to the MDI register with:

a. Ready = 0b

b. Op-Code = 01b (write)

c. PHYADD = The I219’s address from the MDI register

d. REGADD = Page setting

e. DATA = 800 (wake up page)

2. Address setting; The software device driver performs a write cycle to the MDI register with:

a. Ready = 0b

b. Op-Code = 01b (write)

c. PHYADD = The I219’s address from the MDI register

d. REGADD = 0x11 (address set)

e. DATA = XXXX (address of the register to be read)

3. Writing a register; the software device driver performs a write cycle to the MDI register with:

a. Ready = 0b

b. Op-Code = 01b (write)

c. PHYADD = The I219’s address from the MDI register

d. REGADD = 0x12 (data cycle for write)

e. DATA = YYYY (data to be written to the register)


Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2 Host Wake Up Control Status Register

Descriptions

Note: All Wake-Up registers (Pg. 800-801) are not cleared when PHY reset is asserted. These

```
registers are only cleared when internal power on reset is de-asserted or when cleared by
the software device driver.
```
9.5.9.2.1 Receive Control – RCTL PHY Address 01, Page 800,

Register 0

```
Field Name Bit(s) Type Default Description
```
```
UPE 0 RW 0b Unicast Promiscuous Enable (UPE):
0b = Disabled
1b = Enabled
```
```
MPE 1 RW 0b Multicast Promiscuous Enable (MPE):
0b = Disabled.
1b = Enabled.
```
```
SAE 2 RW 1b Slave Access Enable (SAE):
0b = Access disabled, the filters are active.
1b = Access enabled, the filters are not active.
```
```
MO 4:3 RW 00b Multicast Offset (MO)
This determines which bits of the incoming multicast address are used in
looking up the bit vector.
00b = [47:38]
01b = [46:37]
10b = [45:36]
11b = [43:34]
```
```
BAM 5 RW 0b Broadcast Accept Mode (BAM):
0b = Ignore broadcast (unless it matches through exact or imperfect filters)
1b = Accept broadcast packets.
```
##### PMCF^1

1. PMCF controls the usage of MAC control frames (including flow control). A MAC control frame in this context must be addressed to
    the flow control multicast address 0x0100_00C2_8001 and match the type field (0x8808). If PMCF=1b, then frames meeting this
    criteria participate in wake up filtering.

```
6 RW 0b Pass MAC Control Frames (PMCF)
0b = Do not (specially) pass iMAC control frames.
1b = Pass any iMAC control frame (type field value of 0x8808).
```
```
RFCE 7 RW 0b Receive Flow Control Enable (RFCE)
Indicates that the I219 responds to the reception of flow control packets. If
auto-negotiation is enabled, this bit is set to the negotiated duplex value.
```
```
Reserved 15:8 RO 0x00 Reserved.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.2 Wake Up Control – WUC PHY Address 01, Page 800,

Register 1

9.5.9.2.3 Wake Up Filter Control – WUFC PHY Address 01, Page

800, Register 2

This register is used to enable each of the pre-defined and flexible filters for wake up support. A value

of 1b means the filter is turned on, and a value of 0b means the filter is turned off.

```
Field Name Bit(s) Type Default Description
```
```
APME 0 RW/SN Advance Power Management Enable (APME)
If set to 1b, APM wake up is enabled.
```
```
PME_En 1 RW/V PME_En
If set to 1b, ACPI wake up is enabled.
```
```
PME_Status 2 RWC PME_Status
This bit is set when the I219 receives a wake up event.
This bit is cleared by writing 1b to clear or by clearing the Host_WU_Active/
ME_WU_Active bits.
```
```
LSCED 3 RW 0b Link Status Change on Energy Detect (LSCED)
When this bit set enable wake in energy on the lines (instead of actual link
status change). By default this bit is set to 0b.
```
```
LSCWE 4 RW/SN 0b Link Status Change Wake Enable (LSCWE)
Enables wake on link status change as part of APM wake capabilities.
```
```
LSCWO 5 RW/SN 0b Link Status Change Wake Override (LSCWO)
If set to 1b, wake on link status change does not depend on the LNKC bit in
the WUFC register. Instead, it is determined by the APM settings in the WUC
register.
```
```
Reserved 13:6 RO 0x00 Reserved.
```
```
FLX6 14 RW 0b Flexible filter 6 enable.
```
```
FLX7 15 RW 0b Flexible filter 7 enable
```
```
Field Name Bit(s) Type Default Description
```
```
LNKC 0 RW 0b Link status change wake up enable.
```
```
MAG 1 RW 0b Magic packet wake up enable.
```
```
EX 2 RW 0b Directed exact wake up enable.
```
```
MC 3 RW 0b Directed multicast wake up enable.
```
```
BC 4 RW 0b Broadcast wake up enable.
```
```
ARP 5 RW 0b ARP/IPv4 request packet wake up enable.
IPv4 filtering applies only to the 3 host IPv4 addresses in IP4AT.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.4 Wake Up Status – WUS PHY Address 01, Page 800,

Register 3

This register is used to record statistics about all wake up packets received. Note that packets that

match multiple criteria might set multiple bits. Writing a 1b to any bit clears that bit.

This register is not cleared when PHY reset is asserted. It is only cleared when internal power on reset

is de-asserted or when cleared by the software device driver.

```
IPV4 6 RW 0b Directed IPv4 packet wake up enable.
IPv4 filtering applies only to the 3 host IPv4 addresses in IP4AT.
```
```
IPV6 7 RW 0b Directed IPv6 packet wake up enable.
```
```
Reserved 8 RO 0b Reserved.
```
```
FLX4 9 RW 0b Flexible filter 4 enable.
```
```
FLX5 10 RW 0b Flexible filter 5 enable.
```
```
NoTCO 11 RW 0b Ignore TCO packets for host wake up.
If the NoTCO bit is set, then any packet that passes the manageability packet
filtering does not cause a host wake up event even if it passes one of the host
wake up filters.
```
```
FLX0 12 RW 0b Flexible filter 0 enable.
```
```
FLX1 13 RW 0b Flexible filter 1 enable.
```
```
FLX2 14 RW 0b Flexible filter 2 enable.
```
```
FLX3 15 RW 0b Flexible filter 3 enable.
```
```
Field Name Bit(s) Type Default Description
```
```
LNKC 0 RWC 0b Link status changed.
```
```
MAG 1 RWC 0b Magic packet received.
```
```
EX 2 RWC 0b Directed exact packet received. The packet’s address matched one of the 7
pre-programmed exact values in the Receive Address registers.
```
```
MC 3 RWC 0b Directed multicast packet received. The packet was a multicast packet that
was hashed to a value that corresponded to a 1-bit in the multicast table
array.
```
```
BC 4 RWC 0b Broadcast packet received.
```
```
ARP 5 RWC 0b ARP/IPv4 request packet received.
```
```
IPV4 6 RWC 0b Directed IPv4 packet received.
```
```
IPV6 7 RWC 0b Directed IPv6 packet received.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.5 Receive Address Low – RAL PHY Address 01, Page 800,

Registers 16-17

9.5.9.2.6 Receive Address High – RAH PHY Address 01, Page 800,

Registers 18-19

9.5.9.2.7 Shared Receive Address Low – SHRAL PHY Address 01,

Page 800, Registers 20-21 + 4*n (n=0...10)

```
FLX4 8 RWC 0b Flexible filter 4 match.
```
```
FLX5 9 RWC 0b Flexible filter 5 match.
```
```
FLX6 10 RWC 0b Flexible filter 6 match.
```
```
FLX7 11 RWC 0b Flexible filter 7 match.
```
```
FLX0 12 RWC 0b Flexible filter 0 match.
```
```
FLX1 13 RWC 0b Flexible filter 1 match.
```
```
FLX2 14 RWC 0b Flexible filter 2 match.
```
```
FLX3 15 RWC 0b Flexible filter 3 match.
```
```
Field Name Bit(s) Type Default Description
```
```
RAL 31:0 RW 0 Receive Address Low (RAL)
The lower 32 bits of the 48-bit Ethernet address.
```
```
Field Name Bit(s) Type Default Description
```
```
RAH 15:0 RW X Receive Address High (RAH)
The upper 16 bits of the 48-bit Ethernet address.
```
```
Reserved 17:16 RW 0x0 Reserved.
```
```
Reserved 30:18 RO 0x00 Reserved. Reads as 0b and is ignored on writes.
```
```
AV 31 RW 0b Address valid (AV)
When this bit is set, the relevant RAL and RAH are valid (compared against
the incoming packet).
```
```
Field Name Bit(s) Type Default Description
```
```
RAL 31:0 RW X Receive Address Low (RAL)
The lower 32 bits of the 48-bit Ethernet address n (n=0...10).
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.8 Shared Receive Address High – SHRAH PHY Address 01,

Page 800, Registers 22-23 + 4*n (n=0...8,10)

9.5.9.2.9 Shared Receive Address High 9 – SHRAH[9] PHY

Address 01, Page 800, Registers 58-59

9.5.9.2.10 IP Address Valid – IPAV PHY Address 01, Page 800,

Register 64

```
Field Name Bit(s) Type Default Description
```
```
RAH 15:0 RW X Receive Address High (RAH)
The upper 16 bits of the 48-bit Ethernet address n (n=0...8,10).
```
```
Reserved 17:16 RW 0x0 Reserved.
```
```
Reserved 30:18 RO 0x00 Reserved. Reads as 0b and is ignored on writes.
```
```
AV 31 RW 0b Address valid (AV)
When this bit is set, the relevant RAL and RAH are valid (compared against
the incoming packet).
```
```
Field Name Bit(s) Type Default Description
```
```
RAH 15:0 RW X Receive Address High (RAH)
The upper 16 bits of the 48-bit Ethernet address 9.
```
```
Reserved 17:16 RW 0x0 Reserved.
```
```
Reserved 29:18 RO 0x00 Reserved. Reads as 0x00 and is ignored on writes.
```
```
MAV 30 RW 0b All Nodes Multicast Address valid (MAV)
The all nodes multicast address (33:33:00:00:00:01) is valid when this bit is
set. Note that 0x33 is the first byte on the wire.
```
```
AV 31 RW 0b Address valid (AV)
When this bit is set, the relevant address 3 is valid (compared against the
incoming packet).
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 0 RO 0b Reserved.
```
```
IP4AT1 address valid 1 RW 0b IPv4 address 1 valid.
```
```
IP4AT2 address valid 2 RW 0b IPv4 address 2 valid.
```
```
IP4AT3 address valid 3 RW 0b IPv4 address 3 valid.
```
```
IP6AT3 address valid 4 RW 0b IPv6 address 3 valid.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.11 Proxy Control – PRXC PHY Address 01, Page 800,

Register 70

```
IP6AT2 address valid 5 RW 0b IPv6 address 2 valid.
```
```
IP6AT1 address valid 6 RW 0b IPv6 address 1 valid.
```
```
IP6AT0 address valid 7 RW 0b IPv6 address 0 valid (Duplicate of bit 15).
```
```
8 RW 0b Enable L2 for IPv6 multicast according to IP6AT0.
```
```
9 RW 0b Enable L2 for IPv6 multicast according to IP6AT1
```
```
10 RW 0b Enable L2 for IPv6 multicast according to IP6AT2
```
```
11 RW 0b Enable L2 for IPv6 multicast according to IP6AT3
```
```
Reserved 14:12 RO 0x0 Reserved.
```
```
15 RW 0b V60 IPv6 address valid.
```
```
The IP address valid indicates whether the IP addresses in the IP address table are valid.
```
```
Field Name Bit(s) Type Default Description
```
```
Proxy_mode 0 RW 0b Should be set in the end of Proxy configuration. That's the last MDIO
access to PHY, unless we put arbitration on MDIO accesses between
Proxy uCtl and regular MDIO accesses through MAC). As long as this bit
is clear, Proxy logic is under reset.
```
```
Code_loaded 1 RW 0b Set either by software after loading the uCode through MDIO, or by
hardware after reception of the Code packet from MAC (the first packet
after setting PRXC.Nxt_pkt_is_code).
```
```
Code_from_MDIO 2 RW 0b Should be set by software before it starts loading the instruction code
memory through MDIO accesses to page 802.
```
```
Nxt_pkt_is_code 3 RW 0b Should be set by software before it transmits uCode packet.
```
```
4 RW 0b Auto disable proxying after link-down deactivation period.
```
```
ARP PRoxy Enable 5 RW 0b ARP PRoxy Enable.
```
```
ND Proxy Enable 6 RW 0b ND Proxy Enable.
```
```
Reserved 7 RW 0b Reserved.
```
```
13:8 RW 0b Link Down deactivation period in 1 seconds granularity.
```
```
Reserved 14 RW 0b Reserved.
```
```
Ready_for_Code 15 RW 0b This bit is set by HW post setting of Code_from_MDIO or
Nxt_pkt_is_code indicating software is ready for the code load.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.12 Proxy Code Checksum – PRCC PHY Address 01, Page

800, Register 71

9.5.9.2.13 Proxy Control 2 – PRXC2 PHY Address 01, Page 800,

Register 72

9.5.9.2.14 Flex Filters Proxy Control – FFPRXC PHY Address 01,

Page 800, Register 75

```
Field Name Bit(s) Type Default Description
```
```
Proxy Code Checksum 15:0 RO 0x0000 This register holds the checksum calculation for the proxy code
loaded to the transmit FIFO as a packet starting from the start of
frame till the end of frame.
```
```
Field Name Bit(s) Type Default Description
```
```
Reserved 13:0 RO 0b Reserved.
```
```
MLD Proxy Enable 14 RW 0b MLD Proxy Enable
```
```
Reserved 15 RO 0b Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
0 RW 0b Route Flex filter 0 to the proxy uController.
```
```
1 RW 0b Route Flex filter 1 to the proxy uController.
```
```
2 RW 0b Route Flex filter 2 to the proxy uController.
```
```
3 RW 0b Route Flex filter 3 to the proxy uController.
```
```
4 RW 0b Route Flex filter 4 to the proxy uController.
```
```
5 RW 0b Route Flex filter 5 to the proxy uController.
```
```
6 RW 0b Route Flex filter 6 to the proxy uController.
```
```
7 RW 0b Route Flex filter 7 to the proxy uController.
```
```
Flex Filter Match Status 15:8 RWC 0x00 An incoming packet matching one of the flex filters will set a bit in
this status. The bits are cleared on write of 1.
Bit 8 = Flex filter 0 match
Bit 9 = Flex filter 1 match
Bit 10 = Flex filter 2 match
Bit 11 = Flex filter 3 match
Bit 12 = Flex filter 4 match
Bit 13 = Flex filter 5 match
Bit 14 = Flex filter 6 match
Bit 15 = Flex filter 7 match
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.15 Wake Up Filter Control 2 – WUFC2 PHY Address 01,

Page 800, Register 76

9.5.9.2.16 Wake Up Filter Status 2 – WUS2 PHY Address 01, Page

800, Register 77

9.5.9.2.17 Wake Up Filter Control 3 – WUFC3 PHY Address 01,

Page 800, Register 78

Content TBD

```
Field Name Bit(s) Type Default Description
```
```
FLX8 0 RW 0b Flexible filter 8 enable.
```
```
FLX9 1 RW 0b Flexible filter 9 enable.
```
```
FLX10 2 RW 0b Flexible filter 10 enable.
```
```
FLX11 3 RW 0b Flexible filter 11 enable.
```
```
FLX12 4 RW 0b Flexible filter 12 enable.
```
```
FLX13 5 RW 0b Flexible filter 13 enable.
```
```
FLX14 6 RW 0b Flexible filter 14 enable.
```
```
FLX15 7 RW 0b Flexible filter 15 enable.
```
```
Reserved 15:8 RO 0x00 Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
FLX8 0 RW 0b Flexible filter 8 matched.
```
```
FLX9 1 RW 0b Flexible filter 9 matched.
```
```
FLX10 2 RW 0b Flexible filter 10 matched.
```
```
FLX11 3 RW 0b Flexible filter 11 matched.
```
```
FLX12 4 RW 0b Flexible filter 12 matched.
```
```
FLX13 5 RW 0b Flexible filter 13 matched.
```
```
FLX14 6 RW 0b Flexible filter 14 matched.
```
```
FLX15 7 RW 0b Flexible filter 15 matched.
```
```
Reserved 15:8 RO 0x00 Reserved.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.18 Wake Up Filter Status 3 – WUS3 PHY Address 01, Page

800, Register 79

Content TBD

9.5.9.2.19 Wake Up Filter Control 4 – WUFC4 PHY Address 01,

Page 800, Register 80

Content TBD

9.5.9.2.20 Wake Up Filter Status 4 – WUS4 PHY Address 01, Page

800, Register 81

Content TBD

9.5.9.2.21 IPv4 Address Table – IP4AT PHY Address 01, Page 800,

Registers 82-83 + 2*n (n=0, 1, 2)

9.5.9.2.22 IPv6 Address Table – IP6AT[3:0] PHY Address 01, Page

800, Registers 88-89 + 2*n (n=0...3)

The IPv6 address table is used to store the IPv6 addresses for directed IPv6 packet wake up (only using

the first IPv6 address) and network proxy filtering.

Configuration example for IPv6 address: fe80:0:0:0:200:1ff:fe30:100

```
01.800.88 - 0x80fe
01.800.89 - 0x0000
01.800.90 - 0x0000
01.800.91 - 0x0000
01.800.92 - 0x0002
01.800.93 - 0xff01
01.800.94 - 0x30fe
01.800.95 - 0x0001
```
```
Field Name Bit(s) Type Default Description
```
```
IPADD 31:0 RW X IP address n (n= 0, 1, 2).
```
```
Note: The IPv4 address table is used to store the three IPv4 addresses for ARP/IPv4 request packets and directed IPv4 packet
wake ups.
```
```
Field Name Bit(s) Type Default Description
```
```
IPV6 Address 31:0 RW 0x0 IPv6 address bytes n*4...n*4+3 (n=0, 1, 2, 3) while byte 0 is first on the
wire and byte 15 is last.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.23 Multicast Table Array – MTA[31:0] PHY Address 01,

Page 800, Registers 128-191

There is one register per 32 bits of the multicast address table for a total of 32 registers (thus the

MTA[31:0] designation). The size of the word array depends on the number of bits implemented in the

multicast address table. Software must mask to the desired bit on reads and supply a 32-bit word on

writes.

Note: All accesses to this table must be 32-bit.

Figure 9-1 shows the multicast lookup algorithm.

The destination address shown represents the internally stored ordering of the received destination

address. Note that Byte 1 bit 0 shown in Figure 9-1 is the first on the wire. The bits that are directed to

the multicast table array in this diagram match a multicast offset in the CTRL register equals 00b. The

complete multicast offset options are:

```
Field Name Bit(s) Type Default Description
```
```
Bit Vector RW 31:0 X Word-wide bit vector specifying 32 bits in the multicast address filter table.
```
Figure 9-1 Multicast Table Array Algorithm

```
Multicast
Offset
Bits Directed to the Multicast Table Array
```
```
00b DA[47:38] = Byte 6 bits 7:0, Byte 5 bits 1:0
```
```
01b DA[46:37] = Byte 6 bits 6:0, Byte 5 bits 2:0
```
```
10b DA[45:36] = Byte 6 bits 5:0, Byte 5 bits 3:0
```
```
11b DA[43:34] = Byte 6 bits 3:0, Byte 5 bits 5:0
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.24 Flexible Filter Value Table LSB – FFVT_01 PHY Address

01, Page 800, Registers 256 + 2*n (n=0...127)

There are 128 filter values. The flexible filter value is used to store the one value for each byte location

in a packet for each flexible filter. If the corresponding mask bit is one, then the flexible filter compares

the incoming data byte to the values stored in this table.

In the I219 since each address contains 16 bits, only the least significant bytes are stored in those

addresses.

9.5.9.2.25 Flexible Filter Value Table MSBs – FFVT_23 PHY

Address 01, Page 800, Registers 257 + 2*n (n=0...127)

There are 128 filter values. The flexible filter value is used to store the one value for each byte location

in a packet for each flexible filter. If the corresponding mask bit is one, then the flexible filter compares

the incoming data byte to the values stored in this table.

In the I219 since each address contains 16 bits, only the most significant bytes are stored in those

addresses.

Note: Before writing to the flexible filter value table the software device driver must first disable

```
the flexible filters by writing zeros to the Flexible Filter Enable bits of the WUFC register
(WUFC.FLXn).
```
9.5.9.2.26 Flexible Filter Value Table – FFVT_45 PHY Address 01,

Page 800, Registers 512 + 2*n (n=0...127)

```
Field Name Bit(s) Type Default Description
```
```
Value 0 RW 7:0 X Value of filter 0 byte n (n=0, 1... 127).
```
```
Value 1 RW 15:0 X Value of filter 1 byte n (n=0, 1... 127).
```
```
Field Name Bit(s) Type Default Description
```
```
Value 2 7:0 RW X Value of filter 2 byte n (n=0, 1... 127).
```
```
Value 3 15:8 RW X Value of filter 3 byte n (n=0, 1... 127).
```
```
Field Name Bit(s) Type Default Description
```
```
Value 4 7:0 RW X Value of filter 4 byte n (n=0, 1... 127).
```
```
Value 5 15:8 RW X Value of filter 5 byte n (n=0, 1... 127).
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.27 Flexible Filter Value Table – FFVT_67 PHY Address 01,

Page 800, Registers 1024 + 2*n (n=0...127)

9.5.9.2.28 Flexible Filter Mask Table – FFMT PHY Address 01, Page

800, Registers 768 + n (n=0...127)

There are 128 mask entries. The flexible filter mask and table is used to store the four 1-bit masks for

each of the first 128 data bytes in a packet, one for each flexible filter. If the mask bit is one, the

corresponding flexible filter compares the incoming data byte at the index of the mask bit to the data

byte stored in the flexible filter value table.

Note: Before writing to the flexible filter mask table the software device driver must first disable

```
the flexible filters by writing zeros to the Flexible Filter Enable bits of the WUFC register
(WUFC.FLXn).
```
```
Field Name Bit(s) Type Default Description
```
```
Value 6 7:0 RW X Value of filter 6 byte n (n=0, 1... 127).
```
```
Value 7 15:8 RW X Value of filter 7 byte n (n=0, 1... 127).
```
```
Field Name Bit(s) Type Default Description
```
```
Mask 0 0 RW X Mask for filter 0 byte n (n=0, 1... 127).
```
```
Mask 1 1 RW X Mask for filter 1 byte n (n=0, 1... 127).
```
```
Mask 2 2 RW X Mask for filter 2 byte n (n=0, 1... 127).
```
```
Mask 3 3 RW X Mask for filter 3 byte n (n=0, 1... 127).
```
```
Mask 4 4 RW X Mask for filter 4 byte n (n=0, 1... 127).
```
```
Mask 5 5 RW X Mask for filter 5 byte n (n=0, 1... 127).
```
```
Mask 6 6 RW X Mask for filter 6 byte n (n=0, 1... 127).
```
```
Mask 7 7 RW X Mask for filter 7 byte n (n=0, 1... 127).
```
```
Reserved 15:8 RO X Reserved.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.29 Flexible Filter Length Table – FFLT03 PHY Address 01,

Page 800, Registers 896 + n (n=0...3)

All reserved fields read as zeros and are ignored on writes.

There are eight flexible filters lengths covered by FFLT03, FFLT45, FFLT67 registers. The flexible filter

length table stores the minimum packet lengths required to pass each of the flexible filters. Any packets

that are shorter than the programmed length won’t pass that filter. Each flexible filter considers a

packet that doesn’t have any mismatches up to that point to have passed the flexible filter when it

reaches the required length. It does not check any bytes past that point.

Note: Before writing to the flexible filter length table the software device driver must first disable

```
the flexible filters by writing zeros to the Flexible Filter Enable bits of the WUFC register
(WUFC.FLXn).
```
9.5.9.2.30 Flexible Filter Length Table – FFLT45 PHY Address 01,

Page 800, Registers 904 + n (n=0...1)

9.5.9.2.31 Flexible Filter Length Table – FFLT67 PHY Address 01,

Page 800, Registers 908 + n (n=0...1)

```
Field Name Bit(s) Type Default Description
```
```
LEN 10:0 RW X Minimum length for flexible filter n (n=0, 1... 3).
```
```
Reserved RO 15:11 X Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
LEN 10:0 RW X Minimum length for flexible filter n (n=0, 1).
```
```
Reserved 15:11 RO X Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
LEN 10:0 RW X Minimum length for flexible filter n (n=0, 1).
```
```
Reserved 15:11 RO X Reserved.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.32 Flexible Filter Value Table 89 – FFVT_89 PHY Address

01, Page 800, Registers 2304 + 2*n (n=0...127)

There are 128 filter values. The flexible filter value is used to store the one value for each byte location

in a packet for each flexible filter. If the corresponding mask bit is one, then the flexible filter compares

the incoming data byte to the values stored in this table.

9.5.9.2.33 Flexible Filter Value Table 1011 – EFFVT_1011 PHY

Address 01, Page 800, Registers 2305 + 2*n

(n=0...127)

There are 128 filter values. The flexible filter value is used to store the one value for each byte location

in a packet for each flexible filter. If the corresponding mask bit is one, then the flexible filter compares

the incoming data byte to the values stored in this table.

9.5.9.2.34 Flexible Filter Value Table 1213 – FFVT_1213 PHY

Address 01, Page 800, Registers 2560 + 2*n

(n=0...127)

```
Field Name Bit(s) Type Default Description
```
```
7:0 RW X Value of filter 8 byte n (n=0, 1... 127).
```
```
15:8 RW X Value of filter 9 byte n (n=0, 1... 127).
```
```
Field Name Bit(s) Type Default Description
```
```
7:0 RW X Value of filter 10 byte n (n=0, 1... 127).
```
```
15:8 RW X Value of filter 11 byte n (n=0, 1... 127).
```
```
Field Name Bit(s) Type Default Description
```
```
7:0 RW X Value of filter 12 byte n (n=0, 1... 127).
```
```
15:8 RW X Value of filter 13 byte n (n=0, 1... 127).
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.35 Flexible Filter Mask Table 2 – FFMT2 PHY Address 01,

Page 800, Registers 2816 + n (n=0...127)

There are 128 mask entries. The flexible filter mask and table is used to store the four 1-bit masks for

each of the first 128 data bytes in a packet, one for each flexible filter. If the mask bit is one, the

corresponding flexible filter compares the incoming data byte at the index of the mask bit to the data

byte stored in the flexible filter value table.

9.5.9.2.36 Flexible Filter Length Table 891011 – FFLT891011 PHY

Address 01, Page 800, Registers 2944 + n (n=0...3)

9.5.9.2.37 Flexible Filter Length Table 1213 – FFLT1213 PHY

Address 01, Page 800, Registers 2952 + n (n=0...1)

```
Field Name Bit(s) Type Default Description
```
```
Mask 8 0 RW X Mask for filter 8 byte n (n=0, 1... 127).
```
```
Mask 9 1 RW X Mask for filter 9 byte n (n=0, 1... 127).
```
```
Mask 10 2 RW X Mask for filter 10 byte n (n=0, 1... 127).
```
```
Mask 11 3 RW X Mask for filter 11 byte n (n=0, 1... 127).
```
```
Mask 12 4 RW X Mask for filter 12 byte n (n=0, 1... 127).
```
```
Mask 13 5 RW X Mask for filter 13 byte n (n=0, 1... 127).
```
```
Mask 14 6 RW X Mask for filter 14 byte n (n=0, 1... 127).
```
```
Mask 15 7 RW X Mask for filter 15 byte n (n=0, 1... 127).
```
```
Reserved 15:8 RO X Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
LEN 10:0 RW X Minimum length for flexible filter n (n=0, 1... 3). For filters 8, 9, 10 and 11.
```
```
Reserved 15:11 RO X Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
LEN 10:0 RW X Minimum length for flexible filter n (n=0, 1). For filters 12 and 13.
```
```
Reserved 15:11 RO X Reserved.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.38 Flexible Filter Length Table 1415 – FFLT1415 PHY

Address 01, Page 800, Registers 2956 + n (n=0...1)

9.5.9.2.39 Flexible Filter Value Table 1415 – FFVT_1415 PHY

Address 01, Page 800, Registers 3072 + 2*n

(n=0...127)

9.5.9.2.40 Flexible Filter Value Table 1617 – FFVT_1617 PHY

Address 01, Page 800, Registers 4352 + 2*n

(n=0...127)

Content TBD.

9.5.9.2.41 Flexible Filter Value Table 1819 – FFVT_1819 PHY

Address 01, Page 800, Registers 4353 + 2*n

(n=0...127)

Content TBD.

9.5.9.2.42 Flexible Filter Value Table 2021 – FFVT_2021 PHY

Address 01, Page 800, Registers 4608 + 2*n

(n=0...127)

Content TBD.

9.5.9.2.43 Flexible Filter Value Table 2223 – FFVT_2223 PHY

Address 01, Page 800, Registers 4609 + 2*n

(n=0...127)

Content TBD.

```
Field Name Bit(s) Type Default Description
```
```
LEN 10:0 RW X Minimum length for flexible filter n (n=0, 1). For filters 14 and 15.
```
```
Reserved 15:11 RO X Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
7:0 RW X Value of filter 14 byte n (n=0, 1... 127).
```
```
15:8 RW X Value of filter 15 byte n (n=0, 1... 127).
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.44 Flexible Filter Mask Table 3 – FFMT3 PHY Address 01,

Page 800, Registers 4864 + n (n=0...127)

Content TBD.

9.5.9.2.45 Flexible Filter Length Table 1619 – FFLT1619 PHY

Address 01, Page 800, Registers 4992 + n (n=0...3)

Content TBD.

9.5.9.2.46 Flexible Filter Length Table 2021 – FFLT2021 PHY

Address 01, Page 800, Registers 5000 + n (n=0...1)

Content TBD.

9.5.9.2.47 Flexible Filter Length Table 2223 – FFLT2223 PHY

Address 01, Page 800, Registers 5004 + n (n=0...1)

Content TBD.

9.5.9.2.48 Flexible Filter Value Table 2425 – FFVT_2425 PHY

Address 01, Page 800, Registers 6400 + 2*n

(n=0...127)

Content TBD.

9.5.9.2.49 Flexible Filter Value Table 2627 – FFVT_2627 PHY

Address 01, Page 800, Registers 6401 + 2*n

(n=0...127)

Content TBD.

9.5.9.2.50 Flexible Filter Value Table 2829 – FFVT_2829 PHY

Address 01, Page 800, Registers 6656 + 2*n

(n=0...127)

Content TBD.

9.5.9.2.51 Flexible Filter Value Table 3031 – FFVT_3031 PHY

Address 01, Page 800, Registers 6657 + 2*n

(n=0...127)

Content TBD.


```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.52 Flexible Filter Mask Table 4 – FFMT4 PHY Address 01,

Page 800, Registers 6912 + n (n=0...127)

Content TBD.

9.5.9.2.53 Flexible Filter Length Table 2427 – FFLT2427 PHY

Address 01, Page 800, Registers 7040 + n (n=0...3)

Content TBD.

9.5.9.2.54 Flexible Filter Length Table 2829 – FFLT2829 PHY

Address 01, Page 800, Registers 7048 + n (n=0...1)

Content TBD.

9.5.9.2.55 Flexible Filter Length Table 3031 – FFLT3031 PHY

Address 01, Page 800, Registers 7052 + n (n=0...1)

Content TBD.

9.5.9.2.56 Management 2 Host Control Register – MANC2H PHY

Address 01, Page 801, Registers 30-31

```
Field Name Bit(s) Type Default Description
```
```
FP0 0 RW 0b Flex Port 0 (FP0)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
FP1 1 RW 0b Flex Port 1 (FP1)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
FP2 2 RW 0b Flex Port 2 (FP2)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
FT0 3 RW 0b Flex TCO 0 (FT0)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
FT1 4 RW 0b Flex TCO 1 (FT1)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
FLT_026F 5 RW 0b 026F (FLT_026F)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```

Programmer’s Visible State—Intel® Ethernet Connection I219

```
FLT_0298 6 RW 0b 0298 (FLT_0298)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
ARP_REQ 7 RW 0b ARP_REQuest (ARP_REQ)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
ARP_RES 8 RW 0b ARP_RESponse (ARP_RES)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
BR 9 RW 0b Broadcast (BR)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
NE 10 RW 0b Neighbor (NE)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
VLAN0 11 RW 0b VLAN 0 (VLAN0)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
VLAN1 12 RW 0b VLAN 1 (VLAN1)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
VLAN2 13 RW 0b VLAN 2 (VLAN2)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
VLAN3 14 RW 0b VLAN 3 (VLAN3)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
MNG_MAC 15 RW 0b Manageability MAC (MNG_MAC)
When set indicates that packets that are routed to the ME due to a match of
the destination MAC address to any of the Shared Receive Addresses, are sent
to the HOST as well.
```
```
FP3 16 RW 0b Flex Port 3 (FP3)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
MNG_ANM 17 RW 0b Manageability All Nodes Multicast MAC (MNG_ANM).
When set to ‘1’ packets that are routed to the ME due to a match of the
destination MAC address to 33:33:00:00:00:01 are sent to the HOST as well.
```
```
L24IPV60 18 RW 0b Low IPv6 address 0 (L24IPV60)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
L24IPV61 19 RW 0b Low IPv6 address 1 (L24IPV61)
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
L24IPV62 20 RW 0b Low IPv6 address 2 (L24IPV62)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
L24IPV63 21 RW 0b Low IPv6 address 3 (L24IPV63)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
FP4 22 RW 0b Flex Port 4 (FP4)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
FP5 23 RW 0b Flex Port 5 (FP5)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
ICMP_IPV4 24 RW 0b ICMP_IPV4

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
IPV4 25 RW 0b IPV4

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
FP6 26 RW 0b Flex Port 6 (FP6)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
FP7 27 RW 0b Flex Port 7 (FP7)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
FP8 28 RW 0b Flex Port 8 (FP8)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
FP9 29 RW 0b Flex Port 9 (FP9)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
FP10 30 RW 0b Flex Port 10 (FP10)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
FP11 31 RW 0b Flex Port 11 (FP11)

```
When set indicates that packets that are routed to the ME due to this filter will
be sent to the HOST as well.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.57 Management 2 Host Control Register 2 – MANC2H2 PHY

Address 01, Page 801, Registers 32-33

```
Field Name Bit(s) Type Default Description
```
```
TCPPORT0 0 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT1 1 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT2 2 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT3 3 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT4 4 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT5 5 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT6 6 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT7 7 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT8 8 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT9 9 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
TCPPORT10 10 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
Reserved 11 RO 0b Reserved.
```
```
UDPPORT0 12 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
DHCPv6 13 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
EAPoUDP 14 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
DNS 15 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
UDPIPPORT0 16 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
Reserved 17 RO 0b Reserved.
```
```
UDPIPPORT1 18 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
9.5.9.2.58 IPv4 ME Binding Control – IPV4MBC PHY Address 01,

Page 801, Registers 40-41

```
Reserved 19 RO 0b Reserved.
```
```
UDPIPPORT2 20 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
Reserved 21 RO 0b Reserved.
```
```
UDPIPPORT3 22 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
Reserved 23 RO 0b Reserved.
```
```
MRFUTPF 24 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
Host MTA 25 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
ICMPv6 26 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
Reserved 27 RO 0b Reserved.
```
```
ETHERTYPE0 28 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
ETHERTYPE1 29 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
ETHERTYPE2 30 RW 0b When set indicates that packets that are routed to the ME due to this filter
will be sent to the HOST as well.
```
```
Reserved 31 RO 0b Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
EN_IPTCPPORT0 0 RW 0b Enable IP filter for TCPPORT0 (EN_IPTCPPORT0)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT0 filtering.
```
```
EN_IPTCPPORT1 1 RW 0b Enable IP filter for TCPPORT1 (EN_IPTCPPORT1)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT1 filtering.
```
```
EN_IPTCPPORT2 2 RW 0b Enable IP filter for TCPPORT2 (EN_IPTCPPORT2)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT2 filtering.
```
```
EN_IPTCPPORT3 3 RW 0b Enable IP filter for TCPPORT3 (EN_IPTCPPORT3)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT3 filtering.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

```
EN_IPTCPPORT4 4 RW 0b Enable IP filter for TCPPORT4 (EN_IPTCPPORT4)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT4 filtering.
```
```
EN_IPTCPPORT5 5 RW 0b Enable IP filter for TCPPORT5 (EN_IPTCPPORT5)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT5 filtering.
```
```
EN_IPTCPPORT6 6 RW 0b Enable IP filter for TCPPORT6 (EN_IPTCPPORT6)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT6 filtering.
```
```
EN_IPTCPPORT7 7 RW 0b Enable IP filter for TCPPORT7 (EN_IPTCPPORT7)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT7 filtering.
```
```
EN_IPTCPPORT8 8 RW 0b Enable IP filter for TCPPORT8 (EN_IPTCPPORT8)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT8 filtering.
```
```
EN_IPTCPPORT9 9 RW 0b Enable IP filter for TCPPORT9 (EN_IPTCPPORT9)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT9 filtering.
```
```
EN_IPTCPPORT10 10 RW 0b Enable IP filter for TCPPORT10 (EN_IPTCPPORT10)
When set, only packets that match the ME IPv4 filter may pass
TCPPORT10 filtering.
```
```
Reserved 11 RO 0b Reserved
```
```
EN_IPUDPPORT0 12 RW 0b Enable IP filter for UDPPORT0 (EN_IPUDPPORT0)
When set, only packets that match the ME IPv4 filter may pass
UDPPORT0 filtering.
```
```
Reserved 13 RO 0b Reserved
```
```
EN_IPEAPoUDP 14 RW 0b Enable IP filter for EAPoUDP (EN_IPEAPoUDP)
When set, only packets that match the ME IPv4 filter may pass EAPoUDP
filtering.
```
```
EN_IPDNS 15 RW 0b Enable IP filter for DNS (EN_IPDNS)
When set, only packets that match the ME IPv4 filter may pass DNS
filtering.
```
```
EN_IPFLEX0 16 RW 0b Enable IP filter for Flex port 0 (EN_IPFLEX0)
When set, only packets that match the ME IPv4 filter may pass flex port
0 filtering.
```
```
EN_IPFLEX1 17 RW 0b Enable IP filter for Flex port 1 (EN_IPFLEX1)
When set, only packets that match the ME IPv4 filter may pass flex port
1 filtering.
```
```
EN_IPFLEX2 18 RW 0b Enable IP filter for Flex port 2 (EN_IPFLEX2)
When set, only packets that match the ME IPv4 filter may pass flex port
2 filtering.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
EN_IPFLEX3 19 RW 0b Enable IP filter for Flex port 3 (EN_IPFLEX3)

```
When set, only packets that match the ME IPv4 filter may pass flex port
3 filtering.
```
EN_IPFLEX4 20 RW 0b Enable IP filter for Flex port 4 (EN_IPFLEX4)

```
When set, only packets that match the ME IPv4 filter may pass flex port
4 filtering.
```
EN_IPFLEX5 21 RW 0b Enable IP filter for Flex port 5 (EN_IPFLEX5)

```
When set, only packets that match the ME IPv4 filter may pass flex port
5 filtering.
```
EN_IPFLEX6 22 RW 0b Enable IP filter for Flex port 6 (EN_IPFLEX6)

```
When set, only packets that match the ME IPv4 filter may pass flex port
6 filtering.
```
EN_IPFLEX7 23 RW 0b Enable IP filter for Flex port 7 (EN_IPFLEX7)

```
When set, only packets that match the ME IPv4 filter may pass flex port
7 filtering.
```
EN_IPFLEX8 24 RW 0b Enable IP filter for Flex port 8 (EN_IPFLEX8)

```
When set, only packets that match the ME IPv4 filter may pass flex port
8 filtering.
```
EN_IPFLEX9 25 RW 0b Enable IP filter for Flex port 9 (EN_IPFLEX9)

```
When set, only packets that match the ME IPv4 filter may pass flex port
9 filtering.
```
EN_IPFLEX10 26 RW 0b Enable IP filter for Flex port 10 (EN_IPFLEX10)

```
When set, only packets that match the ME IPv4 filter may pass flex port
10 filtering.
```
EN_IPFLEX11 27 RW 0b Enable IP filter for Flex port 11 (EN_IPFLEX11)

```
When set, only packets that match the ME IPv4 filter may pass flex port
11 filtering.
```
EN_IPMRFUTPF 28 RW 0b Enable IP filter for MRFUTPF (EN_IPMRFUTPF)

```
When set, only packets that match the ME IPv4 filter may pass MRFUTPF
range port filtering.
```
EN_IPICMPv4 29 RW 0b Enable IP filter for ICMPv4 (EN_IPICMPv4)

```
When set, only packets that match the ME IPv4 filter may pass ICMPv4
filtering.
```
EN_IPARP 30 RW 0b Enable IP filter for ARP (EN_IPARP)

```
When set, only packets that match the ME IPv4 filter may pass ARP
request filtering.
```
EN_IPRMCP 31 RW 0b Enable IP filter for RMCP (EN_IPRMCP)

```
When set, only packets that match the ME IPv4 filter may pass RMCP
filtering
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.59 IPv4 Host Binding Control – IPV4HBC PHY Address 01,

Page 801, Registers 42-43

```
Field Name Bit(s) Type Default Description
```
```
EN_IPTCPPORT0 0 RW 0b Enable IP filter for TCPPORT0 (EN_IPTCPPORT0)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT0 filtering.
```
```
EN_IPTCPPORT1 1 RW 0b Enable IP filter for TCPPORT1 (EN_IPTCPPORT1)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT1 filtering.
```
```
EN_IPTCPPORT2 2 RW 0b Enable IP filter for TCPPORT2 (EN_IPTCPPORT2)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT2 filtering.
```
```
EN_IPTCPPORT3 3 RW 0b Enable IP filter for TCPPORT3 (EN_IPTCPPORT3)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT3 filtering.
```
```
EN_IPTCPPORT4 4 RW 0b Enable IP filter for TCPPORT4 (EN_IPTCPPORT4)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT4 filtering.
```
```
EN_IPTCPPORT5 5 RW 0b Enable IP filter for TCPPORT5 (EN_IPTCPPORT5)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT5 filtering.
```
```
EN_IPTCPPORT6 6 RW 0b Enable IP filter for TCPPORT6 (EN_IPTCPPORT6)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT6 filtering.
```
```
EN_IPTCPPORT7 7 RW 0b Enable IP filter for TCPPORT7 (EN_IPTCPPORT7)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT7 filtering.
```
```
EN_IPTCPPORT8 8 RW 0b Enable IP filter for TCPPORT8 (EN_IPTCPPORT8)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT8 filtering.
```
```
EN_IPTCPPORT9 9 RW 0b Enable IP filter for TCPPORT9 (EN_IPTCPPORT9)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT9 filtering.
```
```
EN_IPTCPPORT10 10 RW 0b Enable IP filter for TCPPORT10 (EN_IPTCPPORT10)
When set, only packets that match the Host IPv4 filters may pass
TCPPORT10 filtering.
```
```
Reserved 11 RO 0b Reserved
```
```
EN_IPUDPPORT0 12 RW 0b Enable IP filter for UDPPORT0 (EN_IPUDPPORT0)
When set, only packets that match the Host IPv4 filters may pass
UDPPORT0 filtering.
```
```
Reserved 13 RO 0b Reserved
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
EN_IPEAPoUDP 14 RW 0b Enable IP filter for EAPoUDP (EN_IPEAPoUDP)

```
When set, only packets that match the Host IPv4 filters may pass
EAPoUDP filtering.
```
EN_IPDNS 15 RW 0b Enable IP filter for DNS (EN_IPDNS)

```
When set, only packets that match the Host IPv4 filters may pass DNS
filtering.
```
EN_IPFLEX0 16 RW 0b Enable IP filter for Flex port 0 (EN_IPFLEX0)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 0 filtering.
```
EN_IPFLEX1 17 RW 0b Enable IP filter for Flex port 1 (EN_IPFLEX1)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 1 filtering.
```
EN_IPFLEX2 18 RW 0b Enable IP filter for Flex port 2 (EN_IPFLEX2)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 2 filtering.
```
EN_IPFLEX3 19 RW 0b Enable IP filter for Flex port 3 (EN_IPFLEX3)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 3 filtering.
```
EN_IPFLEX4 20 RW 0b Enable IP filter for Flex port 4 (EN_IPFLEX4)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 4 filtering.
```
EN_IPFLEX5 21 RW 0b Enable IP filter for Flex port 5 (EN_IPFLEX5)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 5 filtering.
```
EN_IPFLEX6 22 RW 0b Enable IP filter for Flex port 6 (EN_IPFLEX6)

```
When set, only packets that match the Host IPv4 filter may pass flex
port 6 filtering.
```
EN_IPFLEX7 23 RW 0b Enable IP filter for Flex port 7 (EN_IPFLEX7)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 7 filtering.
```
EN_IPFLEX8 24 RW 0b Enable IP filter for Flex port 8 (EN_IPFLEX8)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 8 filtering.
```
EN_IPFLEX9 25 RW 0b Enable IP filter for Flex port 9 (EN_IPFLEX9)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 9 filtering.
```
EN_IPFLEX10 26 RW 0b Enable IP filter for Flex port 10 (EN_IPFLEX10)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 10 filtering.
```
EN_IPFLEX11 27 RW 0b Enable IP filter for Flex port 11 (EN_IPFLEX11)

```
When set, only packets that match the Host IPv4 filters may pass flex
port 11 filtering.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.60 IPv6 Binding Control – IPV6BC PHY Address 01, Page

801, Registers 50-51

```
EN_IPMRFUTPF 28 RW 0b Enable IP filter for MRFUTPF (EN_IPMRFUTPF)
When set, only packets that match the Host IPv4 filters may pass
MRFUTPF range port filtering.
```
```
EN_IPICMPv4 29 RW 0b Enable IP filter for ICMPv4 (EN_IPICMPv4)
When set, only packets that match the Host IPv4 filters may pass
ICMPv4 filtering.
```
```
EN_IPARP 30 RW 0b Enable IP filter for ARP (EN_IPARP)
When set, only packets that match the Host IPv4 filters may pass ARP
request filtering.
```
```
EN_IPRMCP 31 RW 0b Enable IP filter for RMCP (EN_IPRMCP)
When set, only packets that match the Host IPv4 filters may pass RMCP
filtering
```
```
Field Name Bit(s) Type Default Description
```
```
EN_IPTCPPORT0 0 RW 0b Enable IP filter for TCPPORT0 (EN_IPTCPPORT0)
When set, only packets that match the L24IPV6 filters may pass
TCPPORT0 filtering.
```
```
EN_IPTCPPORT1 1 RW 0b Enable IP filter for TCPPORT1 (EN_IPTCPPORT1)
When set, only packets that match the L24IPV6 filters may pass
TCPPORT1 filtering.
```
```
EN_IPTCPPORT2 2 RW 0b Enable IP filter for TCPPORT2 (EN_IPTCPPORT2)
When set, only packets that match the L24IPV6 filters may pass
TCPPORT2 filtering.
```
```
EN_IPTCPPORT3 3 RW 0b Enable IP filter for TCPPORT3 (EN_IPTCPPORT3)
When set, only packets that match the L24IPV6 filters may pass
TCPPORT3 filtering.
```
```
EN_IPTCPPORT4 4 RW 0b Enable IP filter for TCPPORT4 (EN_IPTCPPORT4)
When set, only packets that match the L24IPV6 filters may pass
TCPPORT4 filtering.
```
```
EN_IPTCPPORT5 5 RW 0b Enable IP filter for TCPPORT5 (EN_IPTCPPORT5)
When set, only packets that match the L24IPV6 filters may pass
TCPPORT5 filtering.
```
```
EN_IPTCPPORT6 6 RW 0b Enable IP filter for TCPPORT6 (EN_IPTCPPORT6)
When set, only packets that match the L24IPV6 filters may pass
TCPPORT6 filtering.
```
```
EN_IPTCPPORT7 7 RW 0b Enable IP filter for TCPPORT7 (EN_IPTCPPORT7)
When set, only packets that match the L24IPV6 filters may pass
TCPPORT7 filtering.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
EN_IPTCPPORT8 8 RW 0b Enable IP filter for TCPPORT8 (EN_IPTCPPORT8)

```
When set, only packets that match the L24IPV6 filters may pass
TCPPORT8 filtering.
```
EN_IPTCPPORT9 9 RW 0b Enable IP filter for TCPPORT9 (EN_IPTCPPORT9)

```
When set, only packets that match the L24IPV6 filters may pass
TCPPORT9 filtering.
```
EN_IPTCPPORT10 10 RW 0b Enable IP filter for TCPPORT10 (EN_IPTCPPORT10)

```
When set, only packets that match the L24IPV6 filters may pass
TCPPORT10 filtering.
```
Reserved 11 RO 0b Reserved

EN_IPUDPPORT0 12 RW 0b Enable IP filter for UDPPORT0 (EN_IPUDPPORT0)

```
When set, only packets that match the L24IPV6 filters may pass
UDPPORT0 filtering.
```
EN_IPDHCPv6 13 RW 0b Enable IP filter for DHCPv6 (EN_IPDHCPv6)

```
When set, only packets that match the L24IPV6 filters may pass
DHCPv6 filtering.
```
EN_IPEAPoUDP 14 RW 0b Enable IP filter for EAPoUDP (EN_IPEAPoUDP)

```
When set, only packets that match the L24IPV6 filters may pass
EAPoUDP filtering.
```
EN_IPDNS 15 RW 0b Enable IP filter for DNS (EN_IPDNS)

```
When set, only packets that match the L24IPV6 filters may pass DNS
filtering.
```
EN_IPFLEX0 16 RW 0b Enable IP filter for Flex port 0 (EN_IPFLEX0)

```
When set, only packets that match the L24IPV6 filters may pass flex
port 0 filtering.
```
EN_IPFLEX1 17 RW 0b Enable IP filter for Flex port 1 (EN_IPFLEX1)

```
When set, only packets that match the L24IPV6 filters may pass flex
port 1 filtering.
```
EN_IPFLEX2 18 RW 0b Enable IP filter for Flex port 2 (EN_IPFLEX2)

```
When set, only packets that match the L24IPV6 filters may pass flex
port 2 filtering.
```
EN_IPFLEX3 19 RW 0b Enable IP filter for Flex port 3 (EN_IPFLEX3)

```
When set, only packets that match the L24IPV6 filters may pass flex
port 3 filtering.
```
EN_IPFLEX4 20 RW 0b Enable IP filter for Flex port 4 (EN_IPFLEX4)

```
When set, only packets that match the L24IPV6 filters may pass flex
port 4 filtering.
```
EN_IPFLEX5 21 RW 0b Enable IP filter for Flex port 5 (EN_IPFLEX5)

```
When set, only packets that match the L24IPV6 filters may pass flex
port 5 filtering.
```
EN_IPFLEX6 22 RW 0b Enable IP filter for Flex port 6 (EN_IPFLEX6)

```
When set, only packets that match the L24IPV6 filter may pass flex port
6 filtering.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

9.5.9.2.61 SHRA Filter Enable Register – SHRAFER PHY Address

01, Page 801, Register 52

```
EN_IPFLEX7 23 RW 0b Enable IP filter for Flex port 7 (EN_IPFLEX7)
When set, only packets that match the L24IPV6 filters may pass flex
port 7 filtering.
```
```
EN_IPFLEX8 24 RW 0b Enable IP filter for Flex port 8 (EN_IPFLEX8)
When set, only packets that match the L24IPV6 filters may pass flex
port 8 filtering.
```
```
EN_IPFLEX9 25 RW 0b Enable IP filter for Flex port 9 (EN_IPFLEX9)
When set, only packets that match the L24IPV6 filters may pass flex
port 9 filtering.
```
```
EN_IPFLEX10 26 RW 0b Enable IP filter for Flex port 10 (EN_IPFLEX10)
When set, only packets that match the L24IPV6 filters may pass flex
port 10 filtering.
```
```
EN_IPFLEX11 27 RW 0b Enable IP filter for Flex port 11 (EN_IPFLEX11)
When set, only packets that match the L24IPV6 filters may pass flex
port 11 filtering.
```
```
EN_IPMRFUTPF 28 RW 0b Enable IP filter for MRFUTPF (EN_IPMRFUTPF)
When set, only packets that match the L24IPV6 filters may pass
MRFUTPF range port filtering.
```
```
EN_IPICMPv4 29 RW 0b Enable IP filter for ICMPv4 (EN_IPICMPv4)
When set, only packets that match the L24IPV6 filters may pass ICMPv4
filtering.
```
```
Reserved 30 RO 0b Reserved.
```
```
EN_IPRMCP 31 RW 0b Enable IP filter for RMCP (EN_IPRMCP)
When set, only packets that match the L24IPV6 filters may pass RMCP
filtering
```
```
Field Name Bit(s) Type Default Description
```
```
EN_SHRA0_FILTER 0 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[0] register and
the Rx packet matches SHRA[0] the packet will be routed to the ME.
```
```
EN_SHRA1_FILTER 1 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[1] register and
the Rx packet matches SHRA[1] the packet will be routed to the ME.
```
```
EN_SHRA2_FILTER 2 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[2] register and
the Rx packet matches SHRA[2] the packet will be routed to the ME.
```
```
EN_SHRA3_FILTER 3 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[3] register and
the Rx packet matches SHRA[3] the packet will be routed to the ME.
```
```
Field Name Bit(s) Type Default Description
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
#### 9.5.10 Proxy Controller uCode

9.5.10.1 Proxy Micro Code – PMC PHY Address 01, Page

802, Register 0-1536

```
EN_SHRA4_FILTER 4 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[4] register and
the Rx packet matches SHRA[4] the packet will be routed to the ME.
```
```
EN_SHRA5_FILTER 5 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[5] register and
the Rx packet matches SHRA[5] the packet will be routed to the ME.
```
```
EN_SHRA6_FILTER 6 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[6] register and
the Rx packet matches SHRA[6] the packet will be routed to the ME.
```
```
EN_SHRA7_FILTER 7 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[7] register and
the Rx packet matches SHRA[7] the packet will be routed to the ME.
```
```
EN_SHRA8_FILTER 8 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[8] register and
the Rx packet matches SHRA[8] the packet will be routed to the ME.
```
```
EN_SHRA9_FILTER 9 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[9] register and
the Rx packet matches SHRA[9] the packet will be routed to the ME.
```
```
EN_SHRA10_FILTER 10 RW 0b Enables Shared MAC address filtering.
When this bit set and the AV bit is set in the SHRAH[10] register and
the Rx packet matches SHRA[10] the packet will be routed to the ME.
```
```
Reserved 15:11 RO 0x0 Reserved.
```
```
Field Name Bit(s) Type Default Description
```
```
Micro Code 15:0 RW 0x00 Micro code.
```
```
Field Name Bit(s) Type Default Description
```

Programmer’s Visible State—Intel® Ethernet Connection I219

#### 9.5.11 Host WoL Packet

9.5.11.1 Host WoL Packet Data – HWPD PHY Address 01,

Page 803, Register 0-63

9.5.11.2 Host WoL Packet Length – HWPL PHY Address

01, Page 803, Register 64

9.5.11.3 Host WoL Packet Clear – HWPC PHY Address 01,

Page 803, Register 66

```
Field Name Bit(s) Type Default Description
```
```
15:0 RO 0x00 Host WoL captured packet data.
```
```
Field Name Bit(s) Type Default Description
```
```
15:0 RO 0x00 Host WoL captured packet Length.
A value of 0x00 means no packet was captured.
```
```
Field Name Bit(s) Type Default Description
```
```
15:0 RO 0x00 Host WoL packet Indication clear.
Register accessed by read/write to clear the WoL packet indication. Reads
always return 0x0000.
```

```
Intel® Ethernet Connection I219—Programmer’s Visible State
```
#### 9.5.12 LPI MMD PHY Registers

LPI MMD PHY registers are part of the I219’s EMI registers. These registers are accessed via MDIO by

programing the EMI address to register MI16 and reading/writing the data from/to register MI17.

9.5.12.1 I219 EMI Registers PHY Address 02, Page 0,

Registers 16-17

##### IEEE

##### MMD

##### MMD

```
Bits
```
##### EMI

```
Address
```
##### EMI

```
Bits
Type Description
```
```
3.0 10 9400 10 Clock stoppable.
```
```
3.1 11 9401 11 Tx LP idle received.
```
```
3.1 10 9401 10 Rx LP idle received
```
```
3.1 9 9401 9 Tx LP idle indication
```
```
3.1 8 9401 8 RX LP idle indication
```
```
3.20 15:0 8000 15:0 EEE capability register
```
```
3.22 15:0 A000 15:0 EEE wake error counter in 100BASE-TX mode
```
```
3.22 15:0 A000 15:0 EEE wake error counter in 1000BASE-T mode
```
```
7.60 15:0 8001 15:0 EEE advertisement
```
```
7.61 15:0 8002 15:0 EEE LP advertisement
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

## 10.0 Non-Volatile Memory (NVM) ..................................................................................

### 10.1 Introduction

This section is intended for designs using a 10/100/1000 Mb/s Intel® C220 Series Chipset integrated

LAN controller in conjunction with the Intel

##### ®

Ethernet Connection I219.

There are several LAN clients that might access the NVM such as hardware, LAN driver, and BIOS. Refer

to the Intel® C220 Series Chipset External Design Specification (Intel® C220 Series Chipset EDS) and

the Intel® C220 Series Chipset SPI Programming Guide for more details.

Unless otherwise specified, all numbers in this section use the following numbering convention:

- Numbers that do not have a suffix are decimal (base 10).
- Numbers with a prefix of “0x” are hexadecimal (base 16).
- Numbers with a suffix of “b” are binary (base 2).

### 10.2 NVM Programming Procedure Overview

The LAN NVM shares space on an SPI Flash device (or devices) along with the BIOS, Manageability

Firmware, and a Flash Descriptor Region. It is programmed through the Intel® C220 Series Chipset.

This combined image is shown in Figure 10-1. The Flash Descriptor Region is used to define vendor

specific information and the location, allocated space, and read and write permissions for each region.

The Manageability (ME) Region contains the code and configuration data for ME functions such as Intel

##### ®

Active Management Technology. The system BIOS is contained in the BIOS Region. The ME Region and

BIOS Region are beyond the scope of this document and a more detailed explanation of these areas can

be found in the Intel® C220 Series Chipset Family External Design Specification (Intel® C220 Series

Chipset EDS). This document describes the LAN image contained in the Gigabit Ethernet (GbE) region.


```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
Figure 10-1. LAN NVM Regions

To access the NVM, it is essential to correctly setup the following:

1. A valid Flash Descriptor Region must be present. Details for the Flash Descriptor Region are
    contained in the Intel® C220 Series Chipset EDS. This process is described in detail in the Intel®
    Active Management Technology OEM Bring-Up Guide.

```
The Intel® Active Management Technology OEM Bring-Up Guide can be obtained by contacting your
local Intel Field Service Representative.
```
2. The GbE region must be part of the original image flashed onto the part.
3. For Intel LAN tools and drivers to work correctly, the BIOS must set the VSCC register(s) correctly.
    There are two sets of VSCC registers, the upper (UVSCC) and lower (LVSCC). Note that the LVSCC
    register is only used if the NVM attributes change. For example, the use of a second flash
    component, a change in erase size between segments, etc. Due to the architecture of the Intel®
    C220 Series Chipset, if these registers are not set correctly, the LAN tools might not report an error
    message even though the NVM contents remain unchanged. Refer to the Intel® C220 Series
    Chipset EDS for more information


Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

4. The GbE region of the NVM must be accessible. To keep this region accessible, the Protected Range
    register of the GbE LAN Memory Mapped Configuration registers must be set to their default value
    of 0x0000 0000. (The GbE Protected Range registers are described in the Intel® C220 Series
    Chipset EDS).
5. The sector size of the NVM must equal 256 bytes, 4 KB, or 64 KB. When a Flash device that uses a
    64 KB sector erase is used, the GbE region size must equal
    128 KB. If the Flash part uses a 4 KB or 256-byte sector erase, then the GbE region size must be
    set to 8 KB.

The NVM image contains both static and dynamic data. The static data is the basic platform

configuration, and includes OEM specific configuration bits as well as the unique Printed Circuit Board

Assembly (PBA). The dynamic data holds the product’s Ethernet Individual Address (IA) and Checksum.

This file can be created using a text editor.

### 10.3 LAN NVM Format and Contents

Table 10-1 lists the NVM maps for the LAN region. Each word listed is described in detail in the following

sections.

Table 10-1 LAN NVM Address Map

##### LAN

```
Word
Offset
```
##### NVM

```
Byte
Offset
```
```
Used
By
```
```
15 0 Image Value
```
```
0x00 0x00 HW-
Shared
```
```
Ethernet Address Byte 2, 1 IA (2, 1) 0x8888
```
```
0x01 0x02 HW-
Shared
```
```
Ethernet Address Byte 4, 3 IA (4, 3) 0x8888
```
```
0x02 0x04 HW-
Shared
```
```
Ethernet Address Byte 6, 5 IA (6, 5) 0x8887
```
```
0x03 0x06 SW Reserved 0x0800
```
```
0x04 0x08 SW Reserved 0xFFFF
```
```
0x05 0x0A SW Image Version Information 1 Example: 0x0083 = minor
revision 0x08 and image ID 0x3
```
```
0x06 0x0C SW EEPROM Track ID (Low) 0xFFFF: Example: 0x0048 in
Intel -LP PCH NVM Rev 0.8
```
```
0x07 0x0E SW EEPROM Track ID (High) 0xFFFF: Example: 0x8000 in
Intel -LP PCH NVM Rev 0.8
```
```
0x08 0x10 SW PBA Low 0xFFFF
```
```
0x09 0x12 SW PBA High 0xFFFF
```
```
0x0A 0x14 HW-PCI PCI Init Control Word 0x10C3
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
Table notes:

- SW = Software: This is access from the network configuration tools and drivers.
- PXE = PXE Boot Agent: This is access from the PXE option ROM code in BIOS.
- HW-Shared = Hardware-Shared: This is read when the shared configuration is reset.
- HW-PCI = Hardware-PCI: This is read when the PCI Configuration is reset.

##### LAN

```
Word
Offset
```
##### NVM

```
Byte
Offset
```
```
Used
By
```
```
15 0 Image Value
```
```
0x0B 0x16 HW-PCI Subsystem ID 0x0000
```
```
0x0C 0x18 HW-PCI Subsystem Vendor ID 0x8086
```
```
0x0D 0x1A HW-PCI Device ID 0x156F for LM SKU (-LP PCH)
or 0x15B7 for LM SKU (-H PCH)
```
```
0x0E 0x1C HW-PCI Reserved 0x0000
```
```
0x0F 0x1E HW-PCI Reserved 0x0000
```
```
0x10 0x20 HW-PCI LAN Power Consumption 0x0000
```
```
0x11 0x22 HW Reserved 0x0000
```
```
0x12 0x24 Reserved 0x8000
```
```
0x13 0x26 HW-
Shared
```
```
Shared Init Control Word 0xA705
```
```
0x14 0x28 HW-
Shared
```
```
Extended Configuration Word 1 0x302C
```
```
0x15 0x2A HW-
Shared
```
```
Extended Configuration Word 2 0x1000 (LAN Switch)
0x1600 (No-LAN Switch)
```
```
0x16 0x2C HW-
Shared
```
```
Extended Configuration Word 3 0x0000
```
```
0x17 0x2E HW-
Shared
```
```
LEDCTL 1OEM Configuration Default 0x0000
```
```
0x18 0x30 (See
note below.)
```
##### HW-

```
Shared
```
```
LEDCTL 0 2 0 - 2 0x18F4 (Intel) or custom OEM
setting
```
```
0x19:0x2F 0x32:0x5E HW-
Shared
```
```
Reserved 0xA000
```
```
0x30:0x3E 0x60:0x7C PXE PXE Software Region 0x0100
```
```
0x3F 0x7E SW Software Checksum (Bytes 0x00 through
0x7D)
```
```
0xFFFF
```
```
0x40:0x4A 0x80:0x94 HW G3 -> S5 PHY Configuration 0x0000
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

- Word 0x30: For more information, see Intel® iSCSI Remote Boot Application Notes for BIOS
    Engineers, Reference Number 322328.

#### 10.3.1 Hardware Accessed Words................................................................................

This section describes the NVM words that are loaded by the integrated LAN controller hardware.

10.3.1.1 Ethernet Address (Words 0x00-0x02)

The Ethernet Individual Address (IA) is a 6-byte field that must be unique for each Network Interface

Card (NIC) or LAN on Motherboard (LOM), and thus unique for each copy of the NVM image. The first

three bytes are vendor specific—for example, the IA is equal to [00 AA 00] or [00 A0 C9] for Intel

products. The value from this field is loaded into the Receive Address Register 0 (RAL0/RAH0).

For the purpose of this section, the IA byte numbering convention is indicated as follows; byte 1, bit 0

is first on the wire and byte 6, bit 7 is last. Note that byte 1, bit 0 is the unicast/multicast address

indication while zero means unicast address. Byte 1, bit 1 identifies the global/local indication while

zero means a global address.

10.3.1.2 PCI Init Control Word (Word 0x0A)

This word contains initialization values that:

- Set defaults for some internal registers
- Enable/disable specific features
- Determines which PCI configuration space values are loaded from the NVM

```
IA Byte/Value
```
```
Vendor 123456
```
```
Intel Original 00 AA 00 variable variable variable
```
```
Intel New 00 A0 C9 variable variable variable
```
```
Bit Name Default Description
```
```
15:14 Reserved 00b Reserved
```
```
13:12 Reserved 01b Reserved
```
```
11:8 Reserved 0x0 Reserved
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
10.3.1.3 Subsystem ID (Word 0x0B)

If the Load Subsystem ID in word 0x0A is set, this word is read-in to initialize the Subsystem ID.

Default value is 0x0000.

10.3.1.4 Subsystem Vendor ID (Word 0x0C)

If the Load Subsystem ID in word 0x0A is set, this word is read-in to initialize the Subsystem Vendor

ID. Default value is 0x8086.

10.3.1.5 Device ID (Word 0x0D)

If the Load Device ID in word 0x0A is set, this word is read-in to initialize the Device ID of the I219LM

PHY. Default value is 0x156F.

Note: When the I219V SKU is used in combination with certain chipset SKUs, the default value for

this word is 0x15B7.

```
Bit Name Default Description
```
```
7 AUX PWR 1b Auxiliary Power Indication
If set and if PM Ena is set, D3cold wake-up is advertised in the PCH
register of the PCI function.
0b = No AUX power.
1b = AUX power.
```
```
6 PM Enable 1b Power Management Enable (PME-WoL)
Enables asserting PME in the PCI function at any power state. This
bit affects the advertised PME_Support indication in the PCH
register of the PCI function.
0b = Disable.
1b = Enable.
```
```
5:4 Reserved 0x0 These bits are reserved and must be set to 0x0.
```
##### 3 ENABLE_

##### SSID_UP

```
0b Enable SSID write once by the host
```
```
20bReserved
```
```
1 Load
Subsystem
IDs
```
```
1b Load Subsystem IDs from NVM
When set to 1b, indicates that the device is to load its PCI
Subsystem ID and Subsystem Vendor ID from the NVM (words
0x0B and 0x0C).
```
```
0 Load Device
IDs
```
```
1b Load Device ID from NVM
When set to 1b, indicates that the device is to load its PCI Device ID
from the NVM (word 0x0D).
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

10.3.1.6 Words 0x0E and 0x0F Are Reserved

Default value is 0x0.

Note: In some OEM custom images these words are used for adding the track ID.

10.3.1.7 LAN Power Consumption (Word 0x10)

This word is meaningful only if the power management is enabled. The default value is 0x0702.

10.3.1.8 Word 0x11 and Word 0x12 Are Reserved

```
Bits Name Default Description
```
```
15:8 Reserved 0x00 Reserved, must be set to 0x00.
```
```
7:0 DEVREVID 0x00 Device Rev ID. The actual device revision ID is the NVM value
XORed with the default value of I219.
```
```
Bits Name Default Description
```
##### 15:8 LAN D0

```
Power
```
```
0x7 The value in this field is reflected in the PCI Power Management
Data register for D0 power consumption and dissipation
(Data_Select = 0 or 4). Power is defined in 100 mW units. The
power also includes the external logic required for the LAN
function.
```
```
7:5 Reserved 000b Reserved, set to 000b.
```
##### 4:0 LAN D3

```
Power
```
```
0x1 The value in this field is reflected in the PCI Power Management
Data register for D3 power consumption and dissipation
(Data_Select = 3 or 7). Power is defined in 100 mW units. The
power also includes the external logic required for the LAN
function. The most significant bits in the Data register that
reflects the power values are padded with zeros.
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x0000 Reserved, set to 0x0000.
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
10.3.1.9 Shared Init Control Word (Word 0x13)

This word controls general initialization values.

```
Bits Name Default Description
```
```
15:14 Sign 10b Valid Indication
A 2-bit valid indication field indicates to the device that there is a
valid NVM present. If the valid field does not equal 10b the
integrated LAN controller does not read the rest of the NVM data
and default values are used for the device configuration.
```
```
13:11 Reserved 0x0 Reserved.
```
```
10 Reserved 1b Reserved, set to 1b.
```
```
9 PHY PD Ena 01 Enable PHY Power Down
When set, enables PHY power down at DMoff/D3 or Dr and no
WoL. This bit is loaded to the PHY Power Down Enable bit in the
Extended Device Control (CTRL_EXT) register.
1b = Enable PHY power down.
0b = PHY always powered up.
```
```
8 Reserved 1b Reserved, should be set to 1b.
```
```
7:6 PHYT 00b PHY Device Type
Indicates that the PHY is connected to the integrated LAN
controller and resulted mode of operation of the integrated LAN
controller/PHY link buses.
00b = I219
01b = Reserved.
10b = Reserved.
11b = Reserved.
```
```
5 Reserved 0b Reserved, should be set to 0b.
```
```
4 FRCSPD 0b Default setting for the Force Speed bit in the Device Control
register (CTRL[11]).
```
```
3 FD 0b Default setting for the Full Duplex bit in the Device Control
register (CTRL[0]). The hardware default value is 1b.
```
```
2 Reserved 1b Reserved, set to 1b.
```
```
1 CLK_CNT_1_4 0b When set, automatically reduces DMA frequency. Mapped to the
Device Status register (STATUS[31]).
```
```
0 Dynamic Clock
Gating
```
```
1b When set, enables dynamic clock gating of the DMA and
integrated LAN controller units. This bit is loaded to the DynCK
bit in the CTRL_EXT register.
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

10.3.1.10 Extended Configuration Word 1 (Word 0x14)

10.3.1.11 Extended Configuration Word 2 (Word 0x15)

Note: This field is dependent upon the length of the extended configuration area. The default

```
value above is for mobile images to be used on platforms with a LAN switch. Refer to the
image relevant to the platform for the appropriate default value.
```
10.3.1.12 Extended Configuration Word 3 (Word 0x16)

```
Bits Name Default Description
```
```
15:14 Reserved 00b Reserved, set to 00b.
```
```
13 PHY Write
Enable
```
```
1b When set, enables loading of the extended PHY configuration area
in the Lan Controller. When disabled, the extended PHY
configuration area is ignored. Loaded to the EXTCNF_CTRL
register.
```
```
12 OEM Write
Enable
```
```
1b When set, enables auto load of the OEM bits from the PHY_CTRL
register to the PHY. Loaded to the Extended Configuration Control
register (EXTCNF_CTRL[3]).
1b = OEM bits written to the Lan Controller
0b = No OEM bits configuration.
```
```
11:0 Extended
Configuration
Pointer
```
```
0x30 Defines the base address (in Dwords) of the Extended
Configuration area in the NVM. The base address defines an offset
value relative to the beginning of the LAN space in the NVM. A
value of 0x00 is not supported when operating with the Lan
Controller. Loaded to the Extended Configuration Control register
(EXTCNF_CTRL[27:16]).
```
```
Bits Name Default Description
```
```
15:8 Extended PHY
Length
```
```
0x0 Size (in Dwords) of the Extended PHY configuration area loaded to
the Extended Configuration Size register (EXTCNF_SIZE[23:16]).
If an extended configuration area is disabled by bit 13 in word
0x14, its length must be set to zero.
```
```
7:0 Reserved 0x0 Reserved, must be set to 0x00.
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x00 Reserved, set to 0x00.
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
10.3.1.13 OEM Configuration Defaults (Word 0x17)

This word defines the OEM fields for the PHY power management parameters loaded to the PHY Control

(PHY_CTRL) register.

10.3.1.14 LED 0—2 Configuration Defaults (Word 0x18)

This NVM word specifies the hardware defaults for the LED Control (LEDCTL) register fields controlling

the LED1 (LINK_1000), LED0 (LINK/ACTIVITY) and LED2 (LINK_100) output behaviors. Refer to the

Intel® C220 Series Chipset Family PDG and the I219 Reference Schematics for LED connection details.

Mode encodings for LED outputs follow that.

Note: In all system states, the LEDs function as defined in Word 0x18 of the GbE region of the

NVM after the software driver loads.

```
Bits Name Default Description
```
```
15 B2B Enable 1b Enable SPD in Back-to-Back Link setup
```
```
14 GbE Disable 0b When set, GbE operation is disabled in all power states (including
D0a).
```
```
13:12 Reserved 00b Reserved, set to 00b.
```
```
11 GbE Disable
in non-D0a
```
```
1b Disables GbE operation in non-D0a states. This bit must be set if
GbE Disable (bit 14) is set.
```
```
10 LPLU Enable
in non-D0a
```
```
1b Low Power Link Up
Enables a reduction in link speed in non-D0a states when power
policy and power management states are set to do so. This bit
must be set if LPLU Enable in D0a bit is set.
```
```
9 LPLU Enable
in D0a
```
```
0b Low Power Link Up
Enables a reduction in link speed in all power states.
```
```
8 SPD Enable 1 When set, enables PHY Smart Power Down mode.
```
```
7:0 Reserved 0x0 Reserved, set to 0x0.
```
```
Bits Name Default Description
```
```
15 Blink Rate 0b Blink Rate
0b = Blink at 200 ms on and 200 ms off.
1b = Blink at 83 ms on and 83 ms off.
```
```
14 LED2 Blink 0b Initial Value of LED2_BLINK Field
0b = Non-blinking.
1b = Blinking.
```
```
13 LED2 Invert 0b Initial Value of LED2_IVRT Field
0b = Active-low output.
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

```
Bits Name Default Description
```
```
12:10 LED2 Mode 110b LED2 Mode
Specifies what event/state/pattern is displayed on the LED2 output.
0110b = 100 Mb/s link_up.
```
```
9 LED1 Blink 0b Initial Value of LED1_BLINK Field
0b = Non-blinking.
1b = Blinking.
```
```
8 LED1 Invert 0b Initial Value of LED1_IVRT Field
0b = Active-low output.
```
```
7:5 LED1 Mode 111b LED1 Mode
Specifies what event/state/pattern is displayed on the LED1 output.
0111b = 1000 Mb/s link_up.
```
```
4 LED0 Blink 1b Initial Value of LED0_BLINK Field
0b = Non-blinking.
1b = Blinking.
```
```
3 LED0 Invert 0b Initial Value of LED0_IVRT Field
0b = Active-low output.
```
```
2:0 LED0 Mode 100b LED0 Mode
Specifies what event/state/pattern is displayed on the LED0 output.
100b = Filter activity on.
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
Table 10-2 Mode Encodings for LED Outputs

10.3.1.15 Reserved (Word 0x19)

10.3.1.16 Reserved (Word 0x1A)

```
Mode Mnemonic State / Event Indicated
```
```
000b LINK_10/1000 Asserted when either 10 or 1000 Mb/s link is
established and maintained.
```
```
001b LINK_100/1000 Asserted when either 100 or 1000 Mb/s link is
established and maintained.
```
```
010b LINK_UP Asserted when any speed link is established and
maintained.
```
```
011b ACTIVITY Asserted when link is established and packets are
being transmitted or received.
```
```
100b LINK/ACTIVITY Asserted when link is established and when there is
no transmit or receive activity.
```
```
101b LINK_10 Asserted when a 10 Mb/s link is established and
maintained.
```
```
110b LINK_100 Asserted when a 100 Mb/s link is established and
maintained.
```
```
111b LINK_1000 Asserted when a 1000 Mb/s link is established and
maintained.
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x0A00 Reserved, set to 0x0A00.
```
```
Bits Name Default Description
```
```
15:1 Reserved 0x0 Reserved, set to 0x0.
```
```
0 APM Enable 1b APM Enable
Initial value of Advanced Power Management Wake Up Enable in
the Wake Up Control (WUC.APME) register.
1b = Advanced power management enabled.
0b = Advanced power management disabled.
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

10.3.1.17 Reserved (Word 0x1B)

10.3.1.18 Reserved (Word 0x1C)

10.3.1.19 Reserved (Word 0x1D)

10.3.1.20 Reserved (Word 0x1E)

10.3.1.21 Reserved (Word 0x1F)

10.3.1.22 Reserved (Word 0x20)

```
Bits Name Default Description
```
```
15:0 Reserved 0x0113 Reserved, set to 0x0113.
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x0 Reserved
```
```
Bits Name Default Description
```
```
15:0 Reserved 0xBAAD Reserved
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x0 Reserved
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x0 Reserved
```
```
Bits Name Default Description
```
```
15:0 Reserved 0xBAAD Reserved
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
10.3.1.23 Reserved (Word 0x21)

10.3.1.24 Reserved (Word 0x22)

10.3.1.25 Reserved (Word 0x23)

10.3.1.26 Reserved (Word 0x24)

10.3.1.27 Reserved (Word 0x25)

10.3.1.28 Reserved (Word 0x26)

```
Bits Name Default Description
```
```
15:0 Reserved 0x0 Reserved
```
```
Bits Name Default Description
```
```
15:0 Reserved 0xBAAD Reserved
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x0 Reserved
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x0 Reserved, set to 0x0.
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x8080 Reserved, set to 0x8080
```
```
Bits Name Default Description
```
```
15:0 Reserved 0x4E00 Reserved, set to 0x4E00
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

10.3.1.29 Reserved (Word 0x27)

#### 10.3.2 Software Accessed Words.................................................................................

10.3.2.1 PXE Words (Words 0x30 Through 0x3E)

Words 0x30 through 0x3E (bytes 0x60 through 0x7D) have been reserved for configuration and version

values to be used by PXE code.

10.3.2.1.1 Boot Agent Main Setup Options (Word 0x30)

The boot agent software configuration is controlled by the NVM with the main setup options stored in

word 0x30. These options are those that can be changed by using the Control-S setup menu or by using

the IBA Intel Boot Agent utility. Note that these settings only apply to Boot Agent software.

```
Bits Name Default Description
```
```
15:0 Reserved 0x0886 Reserved
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
Table 10-1 Boot Agent Main Setup Options

```
Bit Name Default Description
```
```
15:14 Reserved 00b Reserved, set to 00b.
```
```
13 Reserved 0b Reserved, must be set to 0b.
```
```
12 FDP 0b Force Full Duplex.
Set this bit to 0b for half duplex and 1b for full
duplex.
Note that this bit is a don’t care unless bits 10 and 11
are set.
```
```
11:10 FSP 00b Force Speed.
These bits determine speed.
01b = 10 Mb/s.
10b = 100 Mb/s.
11b = Not allowed.
All zeros indicate auto-negotiate (the current bit
state).
Note that bit 12 is a don’t care unless these bits are
set.
```
```
9 Reserved 0b Reserved
Set this bit to 0b.
```
```
8 DSM 1b Display Setup Message.
If this bit is set to 1b, the “Press Control-S” message
appears after the title message.
The default for this bit is 1b.
```
```
7:6 PT 00b Prompt Time. These bits control how long the “Press
Control-S” setup prompt message appears, if
enabled by DIM.
00b = 2 seconds (default).
01b = 3 seconds.
10b = 5 seconds.
11b = 0 seconds.
Note that the Ctrl-S message does not appear if 0
seconds prompt time is selected.
```
```
5 Reserved 0b Reserved
```
```
4:3 DBS 00b Default Boot Selection. These bits select which device
is the default boot device. These bits are only used if
the agent detects that the BIOS does not support
boot order selection or if the MODE field of word
0x31 is set to MODE_LEGACY.
00b = Network boot, then local boot.
01b = Local boot, then network boot.
10b = Network boot only.
11b = Local boot only.
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

10.3.2.1.2 Boot Agent Configuration Customization Options (Word

0x31)

Word 0x31 contains settings that can be programmed by an OEM or network administrator to customize

the operation of the software. These settings cannot be changed from within the Control-S setup menu

or the IBA Intel Boot Agent utility. The lower byte contains settings that would typically be configured

by a network administrator using the Intel Boot Agent utility; these settings generally control which

setup menu options are changeable. The upper byte are generally settings that would be used by an

OEM to control the operation of the agent in a LOM environment, although there is nothing in the agent

to prevent their use on a NIC implementation.

```
2 Reserved 0b Reserved
```
```
1:0 PS 00b Protocol Select. These bits select the boot protocol.
00b = PXE (default value).
01b = Reserved.
Other values are undefined.
```
```
Bit Name Default Description
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
Table 10-1 Boot Agent Configuration Customization Options (Word 0x31)

```
Bit Name Default Description
```
```
15:14 SIG 01b Signature
Set these bits to 11b to indicate valid data.
```
```
13:12 Reserved 00b Reserved, must be set to 00b.
```
```
11 0b Continuous Retry Disabled (0b default).
```
```
10:8 MODE 0x0 Selects the agent's boot order setup mode. This field
changes the agent's default behavior in order to make
it compatible with systems that do not completely
support the BBS and PnP Expansion ROM standards.
Valid values and their meanings are:
000b = Normal behavior. The agent attempts to detect
BBS and PnP Expansion ROM support as it normally
does.
001b = Force Legacy mode. The agent does not
attempt to detect BBS or PnP Expansion ROM supports
in the BIOS and assumes the BIOS is not compliant.
The BIOS boot order can be changed in the Setup
Menu.
010b = Force BBS mode. The agent assumes the BIOS
is BBS-compliant, even though it might not be
detected as such by the agent's detection code. The
BIOS boot order CANNOT be changed in the Setup
Menu.
011b = Force PnP Int18 mode. The agent assumes the
BIOS allows boot order setup for PnP Expansion ROMs
and hooks interrupt 18h (to inform the BIOS that the
agent is a bootable device) in addition to registering as
a BBS IPL device. The BIOS boot order CANNOT be
changed in the Setup Menu.
100b = Force PnP Int19 mode. The agent assumes the
BIOS allows boot order setup for PnP Expansion ROMs
and hooks interrupt 0x19 (to inform the BIOS that the
agent is a bootable device) in addition to registering as
a BBS IPL device. The BIOS boot order CANNOT be
changed in the Setup Menu.
101b = Reserved for future use. If specified, treated
as value 000b.
110b = Reserved for future use. If specified, treated
as value 000b.
111b = Reserved for future use. If specified, treated
as value 000b.
```
```
7:6 Reserved 00b Reserved, must be set to 00b.
```
```
5 DFU 0b Disable Flash Update
If set to 1b, no updates to the Flash image using
PROSet is allowed.
The default for this bit is 0b; allow Flash image
updates using PROSet.
```
```
4 DLWS 0b Disable Legacy Wakeup Support
If set to 1b, no changes to the Legacy OS Wakeup
Support menu option is allowed.
The default for this bit is 0b; allow Legacy OS Wakeup
Support menu option changes.
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

10.3.2.1.3 Boot Agent Configuration Customization Options (Word

0x32)

Word 0x32 is used to store the version of the boot agent that is stored in the Flash image. When the

Boot Agent loads, it can check this value to determine if any first-time configuration needs to be

performed. The agent then updates this word with its version. Some diagnostic tools to report the

version of the Boot Agent in the Flash also read this word. This word is only valid if the PPB is set to 0b.

Otherwise the contents might be undefined.

```
3 DBS 0b Disable Boot Selection
If set to 1b, no changes to the boot order menu option
is allowed.
The default for this bit is 0b; allow boot order menu
option changes.
```
```
2 DPS 0b Disable Protocol Select
If set to 1b, no changes to the boot protocol is
allowed.
The default for this bit is 0b; allow changes to the boot
protocol.
```
```
1 DTM 0b Disable Title Message
If set to 1b, the title message displaying the version of
the boot agent is suppressed; the Control-S message
is also suppressed. This is for OEMs who do not want
the boot agent to display any messages at system
boot.
The default for this bit is 0b; allow the title message
that displays the version of the boot agent and the
Control-S message.
```
```
0 DSM 0b Disable Setup Menu
If set to 1b, no invoking the setup menu by pressing
Control-S is allowed. In this case, the EEPROM can
only be changed via an external program.
The default for this bit is 0b; allow invoking the setup
menu by pressing Control-S.
```
```
Bit Name Default Description
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
Table 10-1 Boot Agent Configuration Customization Options (Word 0x32)

10.3.2.1.4 IBA Capabilities (Word 0x33)

Word 0x33 is used to enumerate the boot technologies that have been programmed into the Flash. It is

updated by IBA configuration tools and is not updated or read by IBA.

Table 10-1 IBA Capabilities

```
Bit Name Default Description
```
```
15:12 MAJOR 0x1 PXE boot agent major version. The default for these
bits is 0x1.
```
```
11:8 MINOR 0x2 PXE boot agent minor version. The default for these
bits is 0x2
```
```
7:0 BUILD 0x28 PXE boot agent build number. The default for these bits
is 0x28.
```
```
Bit Name Default Description
```
```
15:14 SIG 01b Signature
These bits must be set to 01b to indicate that this word
has been programmed by the agent or other
configuration software.
```
```
13:5 Reserved 0x00 Reserved, must be set to 0x00.
```
```
4 iSCSI Boot Capability
not present
```
```
0b iSCSI boot capability not present (0b default).
```
```
3 EFI 0b EFI EBC capability is present in Flash.
0b = The EFI code is not present (default).
1b = The EFI code is present.
```
```
2 Reserved 1b Reserved, set to 1b.
```
```
1 UNDI 1b PXE/UNDI capability is present in Flash.
1b = The PXE base code is present (default).
0b = The PXE base code is not present.
```
```
0 BC 1b PXE base code is present in Flash.
0b = The PXE base code is not present.
1b = The PXE base code is present (default).
```

Non-Volatile Memory (NVM)—Intel® Ethernet Connection I219

10.3.2.2 Checksum Word Calculation (Word 0x3F)

The Checksum word (Word 0x3F, NVM bytes 0x7E and 0x7F) is used to ensure that the base NVM image

is a valid image. The value of this word should be calculated such that after adding all the words (0x00-

0x3F) / bytes (0x00-0x7F), including the Checksum word itself, the sum should be 0xBABA. The initial

value in the 16 bit summing register should be 0x0000 and the carry bit should be ignored after each

addition.

Note: Hardware does not calculate the word 0x3F checksum during NVM write; it must be

```
calculated by software independently and included in the NVM write data. Hardware does
not compute a checksum over words 0x00-0x3F during NVM reads in order to determine
validity of the NVM image; this field is provided strictly for software verification of NVM
validity. All hardware configuration based on word 0x00-0x3F content is based on the
validity of the Signature field of the NVM.
```
#### 10.3.3 Basic Configuration Software Words

This section describes the meaningful NVM words in the basic configuration space that are used by

software at word addresses 0x03-0x09.

10.3.3.1 Reserved (Word 0x03)

Note: When software calculates the checksum, bit 1 of this word is set to 1b to indicate that the

checksum is valid after the image is successfully programmed.

10.3.3.2 Reserved (Word 0x04)

```
Bits Name Default Description
```
```
15:12 Reserved 0x03 Reserved, set to 0x0.
```
```
11 LOM 1b LOM
Set to 1b.
```
```
10:0 Reserved 0x00 Reserved, set to 0x00.
```
```
Bits Name Default Description
```
```
15:0 Reserved 0xFFFF Reserved
```

```
Intel® Ethernet Connection I219—Non-Volatile Memory (NVM)
```
10.3.3.3 Image Version Information (Word 0x05)

0x03 denotes tuning to support a design that includes a LAN switch. 0x04 denotes tuning for all other

designs.

10.3.3.4 PBA Low and PBA High (Words 0x08 and 0x09)

The nine-digit Printed Board Assembly (PBA) number used for Intel manufactured Network Interface

Cards (NICs) and LAN on Motherboard (LOMs) are stored in a four-byte field. The dash itself is not

stored, neither is the first digit of the 3-digit suffix, as it is always zero for the affected products. Note

that through the course of hardware ECOs, the suffix field (byte 4) is incremented. The purpose of this

information is to allow customer support (or any user) to identify the exact revision level of a product.

Note: Network driver software should not rely on this field to identify the product or its

capabilities.

Example: PBA number = 123456-003 to Word 0x08 = 0x1234; Word 0x09 = 0x5603.

§ §

```
Bits Word Default Description
```
```
15:0 0x08 0xFFFF PBA low.
```
```
15:0 0x09 0xFFFF PBA high.
```

Electrical and Timing Specifications—Intel® Ethernet Connection I219

## 11.0 Electrical and Timing Specifications ......................................................................

### 11.1 Introduction

This section describes the I219’s recommended operating conditions, power delivery, DC electrical

characteristics, power sequencing and reset requirements, PCIe specifications, reference clock, and

packaging information.

### 11.2 Operating Conditions

#### 11.2.1 Absolute Maximum Ratings...............................................................................

#### 11.2.2 Recommended Operating Conditions..................................................................

```
Symbol Parameter Min Max Units
```
```
Tcase Case Temperature Under Bias 0 106 °C
```
```
Tstorage Storage Temperature Range -40 125 °C
```
```
Vi/Vo 3.3 Vdc I/O Voltage -0.3 3.7 Vdc
```
```
VCC 3.3 Vdc Periphery DC Supply Voltage -0.3 3.7 Vdc
```
```
VCC0P9 Core Vdc Supply Voltage -0.3 1.2 Vdc
```
```
Notes:
```
1. Ratings in this table are those beyond which permanent device damage is likely to occur. These values should not be used as
    the limits for normal device operation. Exposure to absolute maximum rating conditions for extended periods might affect
    device reliability.
2. Recommended operation conditions require accuracy of power supply of +/-5% relative to the nominal voltage.
3. Maximum ratings are referenced to ground (VSS).

```
Symbol Parameter Min Max Units
```
```
Ta
Operating Temperature Range Commercial
(Ambient; 0 CFS airflow)
```
##### 0851

1. For normal device operation, adhere to the limits in this table. Sustained operations of a device at conditions exceeding these
    values, even if they are within the absolute maximum rating limits, can result in permanent device damage or impaired device
    reliability. Device functionality to stated Vdc and Vac limits is not guaranteed if conditions exceed recommended operating
    conditions.

##### °C


```
Intel® Ethernet Connection I219—Electrical and Timing Specifications
```
### 11.3 Power Delivery

#### 11.3.1 Voltage Regulator Power Supply Specifications

11.3.1.1 3.3 Vdc Rail

11.3.1.2 Core Vdc Rail (External/Shared)

```
Title Description Min Max Units
```
```
Rise Time Time from 10% to 90% mark 0.1 100 ms
```
```
Monotonicity Voltage dip allowed in ramp N/A 0 mV
```
```
Slope
```
```
Ramp rate at any given time between 10% and 90%
Min: 0.8*V(min)/Rise time (max)
Max: 0.8*V(max)/Rise time (min)
```
```
24 28800 V/s
```
```
Operational Range Voltage range for normal operating conditions 3.13 3.46 V
```
```
Ripple Maximum voltage ripple (peak to peak) N/A 70 mV
```
```
Overshoot Maximum overshoot allowed N/A 100 mV
```
```
Title Description Min Max Units
```
```
Rise Time Time from 10% to 90% mark 0.5 40 ms
```
```
Monotonicity Voltage dip allowed in ramp N/A 0 mV
```
```
Slope
```
```
Ramp rate at any given time between 10% and 90%
Min: 0.8*V(min)/Rise time (max)
Max: 0.8*V(max)/Rise time (min)
```
```
7.6 8400 V/s
```
```
Operational Range Voltage range for normal operating conditions 0.87 1.115 Vdc
```
```
Ripple Maximum voltage ripple (peak to peak) N/A 50 mV
```
```
Overshoot Maximum overshoot allowed N/A 100 mV
```
```
Decoupling Capacitance Capacitance range 20 30 μF
```
```
Capacitance ESR Equivalent series resistance of output capacitance 5 50 m
```

Electrical and Timing Specifications—Intel® Ethernet Connection I219

#### 11.3.2 SVR Specification (Internal)..............................................................................

#### 11.3.3 Power On/Off Sequence

There is no power sequencing requirement for the I219.

```
Parameter
```
```
Specifications
Units Comments
Min Typ Max
```
```
Regulator Output Voltage (“Core” voltage) 0.8 1.2 Vdc The default voltage is set to 0.93 Vdc
```
```
Output Voltage Accuracy -3 +3 %
Not including line and load regulation
errors.
```
```
Input Voltage Range 2.9 3.3 3.7 Vdc Supply voltage range.
```
```
Load Current 0.01 0.3 0.5 A Average value.
```
```
Output Voltage Under/Over Shoot -10 +10 %
For min-to-max average load current
change.
```
```
Transient Settling Time 100 μs Duration of overshoot or undershoot.
```
```
Conversion Efficiency 80 85 90 %
```
```
Switching Frequency 1.5625 MHz
```
```
Output Filter Inductor 3.9 4.7 μH
```
```
Output Filter Inductor DCR 0.1 0.318 
```
```
+/-20%, values higher than the
typical DCR value will lower the SVR
conversion efficiency.
```
```
Output Filter Capacitor 20 μF
```
```
Output Filter Capacitor ESR 5 50 m
```
```
Input Capacitor 22 μF
```

```
Intel® Ethernet Connection I219—Electrical and Timing Specifications
```
#### 11.3.4 Power Delivery Schematic Drawing

Figure 11-1 shows the power delivery schematic:

Figure 11-1 Power Delivery Schematic

Table 11-1 Power Detection Threshold

```
Symbol Parameter
```
```
Specifications
Units
Min Typ Max
```
```
V1a High-threshold for 3.3 Vdc supply 2.35 2.45 2.6 Vdc
```
```
V2a Low-threshold for 3.3 Vdc supply 2.1 2.45 2.6 Vdc
```
```
V1b High-threshold for Core Vdc supply 0.6 0.75 0.85 Vdc
```
```
V2b Low-threshold for Core Vdc supply 0.45 0.65 0.75 Vdc
```

Electrical and Timing Specifications—Intel® Ethernet Connection I219

### 11.4 I/O DC Parameter

#### 11.4.1 3.3 Vdc I/O (Open Drain)

Note: SMBus leakage current when the I219 is off is <10 μA.

#### 11.4.2 3.3 Vdc I/O

```
Parameter Minimum Typical Maximum Unit
```
```
VIL -0.4 0 0.8 Vdc
```
```
VIH 2 3.3 3.6 Vdc
```
```
VOL -0.4 0 0.4 Vdc
```
```
VOH 2.4 3.3 3.6 Vdc
```
```
Ipullup 30 50 75 μA
```
```
Ileakage 10 μA
```
```
Ci 2 4 pF
```
```
Pin Name Bus Size Description
```
```
CLK_REQ_N 1 Open-drain I/O.
```
```
SMB_CLK 1 Open-drain I(H)/O with snap back NMOS ESD cell.
```
```
SMB_DATA 1 Open-drain I(H)/O with snap back NMOS ESD cell.
```
```
Parameter Conditions Minimum Typical Maximum Units
```
```
VIL -0.3 0 0.4 Vdc
```
```
VIH 2 3.3 3.6 Vdc
```
##### VOL

```
IOL = 9 mA
VCC = Min
-0.4 0 0.4 Vdc
```
##### VOH

```
IOH = -9 mA
VCC = Min
2 2.6 2.8 Vdc
```
```
Ipullup 30 50 75 μA
```
```
Ileakage 15 (pull-down) 25 (pull-down) 35 (pull-down) μA
```
```
Ci 24pF
```
```
PU 50 K
```
```
PD 50 K
```

```
Intel® Ethernet Connection I219—Electrical and Timing Specifications
```
#### 11.4.3 Input Buffer Only

#### 11.4.4 PCIe DC/AC Specifications

11.4.4.1 PCIe Specifications (Transmitter)

Note: Refer to the I219 PCIe-Based Test Procedure for more details.

```
Pin Name Bus Size Description
```
##### RSVD1_VCC3P3

##### RSVD2_VCC3P3

##### 2 I/O, PU

##### LED0

##### LED1

##### LED2

##### 3 I/O, PU

##### JTAG_TDI 1 I/O, PU

##### JTAG_TMS 1 I/O, PU

##### JTAG_TDO 1 I/O, PU

##### JTAG_TCK 1 I/O, PU

```
Parameter Conditions Minimum Typical Maximum Units
```
```
VIL -0.3 0 0.8 Vdc
```
```
VIH 2 3.3 3.6 Vdc
```
```
Ipullup 30 50 75 μA
```
```
Ileakage 10 μA
```
```
Ci 24pF
```
```
Pin Name Bus Size Description
```
##### LAN_DISABLE_N 1 I(H), PU

```
TEST_EN 1 I (no PU, no PD)
```
```
PE_RST_N 1 I(H), PU
```
```
Symbol Parameter
```
```
1.25 GT/s
Units Comments
Min Max
```
```
UI Unit interval. 799.92 800.08 ps
Each UI is 800 ps +/-
100 ppm.
```
```
Vtx-diff-pp Differential peak-to-peak Tx voltage swing. 0.8 1.2 Vdc
```
```
Ttx-eye Transmitter eye including all jitter sources. 0.75 UI
```
```
Ttx-eye-median-to -max-jitter
Maximum time between the jitter median
and maximum deviation from the median.
```
##### 0.125 UI


Electrical and Timing Specifications—Intel® Ethernet Connection I219

Note: Figure 11-2 is for informational purposes only. Do not use for actual eye comparisons.

```
RLtx-diff
Tx package plus silicon differential return
loss.
7db
```
```
RLtx-cm
Tx package plus silicon common mode
return loss.
6db
```
```
Ztx-diff-dc DC differential Tx impedance. 75 120 
```
```
Vtx-cm-ac-p Tx V ac common mode voltage (2.5 GT/s). 20 mV
```
```
Itx-short Transmitter short-circuit current limit. 90 mA
```
```
Vtx-dc-cm Transmitter DC common mode voltage. 0 3.6 Vdc
```
```
Vtx-cm-dc-active- idle-delta
Absolute delta of DC common mode voltage
during L0 and electrical idle.
0 100 mV
```
```
Vtx-cm-dc-line-delta
Absolute delta of DC common mode voltage
between D+ and D-.
025mV
```
```
Vtx-idle-diff-ac-p
Electrical idle differential peak output
voltage.
020mV
```
```
Ttx-idle-set-to-idle
Maximum time to transition to a valid
electrical idle after sending an EIOS.
35 ns
```
```
Ttx-idle-to-diff-data
```
```
Maximum time to transition to valid
differential signaling after leaving electrical
idle.
```
```
35 ns
```
Figure 11-2 Transmitter Eye Diagram

```
Symbol Parameter
```
```
1.25 GT/s
Units Comments
Min Max
```

```
Intel® Ethernet Connection I219—Electrical and Timing Specifications
```
11.4.4.2 PCIe Specifications (Receiver)

Note: The I219 has integrated PCIe termination that results in attenuating the voltage swing of

```
the PCIe clock supplied by Cougar Point. This is in compliance with the PCIe CEM 1.1
specification. More detail is available in the Cougar Point PDG.
```
Note: Figure 11-3 is intended to show the difference between the PCIe 1.0 and PCIe-based

receiver sensitivity templates. It is for informational purposes only.

```
Symbol Parameter
```
```
1.25 GT/s
Units Comments
Min Max
```
```
UI Unit interval. 799.92 800.08 ps
Each UI is 800 ps +/-
100 ppm
```
```
Vrx-diff-pp-cc
Differential peak-to-peak Rx voltage swing
for common clock.
0.175 1.2 Vdc
```
```
Vrx-diff-pp-dc
Differential peak-to-peak Rx voltage swing
for data clock.
0.175 1.2 Vdc
```
```
Trx-eye Receiver minimum eye time opening. 0.4 N/A UI
```
```
Trx-eye-median2maxjitter
Maximum time delta between median and
deviation from median.
```
##### N/A 0.3 UI

```
RLrx-diff Rx differential return loss. 6 N/A dB
```
```
RLrx-cm Rx CM return loss. 5 N/A dB
```
```
Zrx-diff-dc Rx differential Vdc impedance. 80 120 
```
```
Vrx-cm-ac-p Rx Vac CM voltage. N/A 150 mVp
```
```
Zrx-high-imp-dc-pos DC input CM impedance for V>0. 50 K N/A 
```
```
Zrx-high-imp-dc-neg DC input CM impedance for V<0. 1 K N/A 
```
```
Vrx-idle-det-diffp-p Electrical idle detect threshold. 65 175 mV
```
Figure 11-3 Receiver Eye Diagram


Electrical and Timing Specifications—Intel® Ethernet Connection I219

11.4.4.3 PCIe Clock Specifications

The PCIe clock specification can be found in the PCI Express Card Electromechanical Specification 1.1,

section 2.1.

### 11.5 Discrete/Integrated Magnetics Specifications

### 11.6 Mechanical

```
Criteria Condition Values (Min/Max)
```
```
Voltage Isolation
```
```
At 50 to 60 Hz for 60 seconds 1500 Vrms (min)
```
```
For 60 seconds 2250 Vdc (min)
```
```
Open Circuit Inductance
(OCL) or OCL (alternate)
```
```
With 8 mA DC bias at 25 °C 400 H (min)
```
```
With 8 mA DC bias at 0 °C to 70 °C 350 H (min)
```
```
Insertion Loss
```
```
100 kHz through 999 kHz
1.0 MHz through 60 MHz
60.1 MHz through 80 MHz
80.1 MHz through 100 MHz
100.1 MHz through 125 MHz
```
```
1 dB (max)
0.6 dB (max)
0.8 dB (max)
1.0 dB (max)
2.4 dB (max)
```
```
Return Loss
```
```
1.0 MHz through 40 MHz
40.1 MHz through 100 MHz
When reference impedance is 85 , 100 , and
115 .
Note that return loss values might vary with MDI
trace lengths. The LAN magnetics might need to
be measured in the platform where it is used.
```
```
18 dB (min)
12 to 20 * LOG (frequency in MHz / 80) dB (min)
```
```
Crosstalk Isolation
Discrete Modules
```
```
1.0 MHz through 29.9 MHz
30 MHz through 250 MHz
250.1 MHz through 375 MHz
```
```
-50.3+(8.8*(freq in MHz / 30)) dB (max)
-26-(16.8*(LOG(freq in MHz / 250)))) dB (max)
-26 dB (max)
```
```
Crosstalk Isolation
Integrated Modules
```
```
1.0 MHz through 10 MHz
10.1 MHz through 100 MHz
100.1 MHz through 375 MHz
```
```
-50.8+(8.8*(freq in MHz / 10)) dB (max)
-26-(16.8*(LOG(freq in MHz / 100)))) dB (max)
-26 dB (max)
```
```
Diff to CMR
1.0 MHz through 29.9 MHz
30 MHz through 500 MHz
```
```
-40.2+(5.3*((freq in MHz / 30)) dB (max)
-22-(14*(LOG((freq in MHz / 250)))) dB (max)
```
```
CM to CMR
```
```
1.0 MHz through 270 MHz
270.1 MHz through 300 MHz
300.1 MHz through 500 MHz
```
```
-57+(38*((freq in MHz / 270)) dB (max)
-17-2*((300-(freq in MHz) / 30) dB (max)
-17 dB (max)
```
```
Body Size (mm) Ball Count Ball Pitch Ball Matrix Center Matrix Substrate
```
```
6x6 mm 48 0.4 mm N/A, Peripheral N/A, Exposed Pad N/A Lead Frame-Based Package
```

```
Intel® Ethernet Connection I219—Electrical and Timing Specifications
```
### 11.7 Oscillator/Crystal Specifications

Table 11-2 lists required parameters.

Crystal must meet or exceed the specified drive Level (DL). Refer to the crystal design guidelines in the

Intel

##### ®

5 Series Family PDG.

Table 11-2 External Crystal Specifications

```
Parameter Name Symbol
Recommended
Value
Max/Min Range Conditions
```
```
Frequency fo 25 [MHz] @25 [°C]
```
```
Vibration Mode Fundamental
```
```
Frequency Tolerance @25 °C Df/fo @25 °C ±30 [ppm] @25 [°C]
```
```
Temperature Tolerance Df/fo ±30 [ppm] 0 to +70 [°C]
```
```
Series Resistance (ESR) Rs 50 [] max @25 [MHz]
```
```
Crystal Load Capacitance Cload 18 [pF]
```
```
Shunt Capacitance Co 6 [pF] max
```
```
Drive Level DL 200 [W] max
```
```
Aging Df/fo ±5 ppm per year ±5 ppm per year max
```
```
Calibration Mode Parallel
```
```
Insulation Resistance 500 [M] min @ 100 Vdc
```
Table 11-3 Clock Oscillator Specifications

```
Parameter Name Symbol/Parameter Conditions Min Typ Max Unit
```
```
Frequency fo @25 [°C] 25.0 MHz
```
```
Clock Amplitude Vmax 0.8 1.8 Vdc
```
```
Clock Amplitude Vmin 0 Vdc
```
```
Frequency Tolerance f/fo 20 to +70 ±50 [ppm]
```
```
Operating Temperature Topr -20 to +70 °C
```
```
Aging f/fo
±5 ppm per
year
[ppm]
```
```
TH_XTAL_IN XTAL_IN High Time 13 20 ns
```
```
TL_XTAL_IN XTAL_IN Low Time 13 20 ns
```
```
TR_XTAL_IN XTAL_IN Rise 10% to 90% 5 ns
```
```
TF_XTAL_IN XTAL_IN Fall 10% to 90% 5 ns
```
```
TJ_XTAL_IN XTAL_IN Total Jitter 2001
```
1. Broadband peak-to-peak = 200 ps, Broadband rms = 3 ps, 12 KHz to 20 MHz rms = 1 ps

```
ps
```

Electrical and Timing Specifications—Intel® Ethernet Connection I219

Figure 11-4 XTAL Timing Diagram


```
Intel® Ethernet Connection I219—Electrical and Timing Specifications
```
NOTE: This page intentionally left blank.


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

## 12.0 Mobile Design Considerations and Guidelines ........................................................

The PCH incorporates an integrated 10/100/1000 Mb/s MAC controller that can be used with an

external Intel

##### ®

Ethernet Connection I219 (PHY) shown in Figure 12-1. Its bus master capabilities

enable the component to process high-level commands and perform multiple operations, which lowers

processor use by offloading communication tasks from the processor.

The PCH, which hereinafter refers to the integrated MAC within the PCH, supports the SMBus interface

for manageability while in an Sx state and PCI Express* (PCIe*) for 10/100/1000 Mb/s traffic in an S0

state.

Note: The PCIe interface is not PCIe-compliant. It operates at half of the PCI Express* (PCIe*)

```
Specification v1.0 (2.5 GT/s) speed. In this section, the term “PCIe-based” is
interchangeable with “PCIe.” There are no design layout differences between normal PCIe
and the PCIe-based interface.
```
The PHY interfaces with the integrated MAC through two interfaces: PCIe and SMBus. In SMBus mode,

the link speed is reduced to 10 Mb/s. The PCIe interface incorporates two aspects: a PCIe-based SerDes

(electrically) and a custom logic protocol for messaging between the integrated MAC and the PHY.

Note: Gigabit Ethernet requires an SPI Flash to host firmware and does not work without an SPI

Flash on board.

The integrated MAC supports multi-speed operation (10/100/1000 Mb/s). The integrated MAC also

operates in full-duplex at all supported speeds or half-duplex at 10/100 Mb/s as well as adhering to the

IEEE 802.3x Flow Control Specification.

Note: References to the AUX power rail means the power rail is available in all power states

```
including G3 to S5 transitions and Sx states with Wake on LAN (WoL) enabled. For
example, V3P3_AUX in this section refers to a rail that is powered under the conditions
previously mentioned.
```
Figure 12-1 PCH/PHY Interface Connections


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
### 12.1 I219 Overview

The Intel

##### ®

Ethernet Connection I219 is a single port compact component designed for 10/100/1000

Mb/s operation. It enables a single port Gigabit Ethernet (GbE) implementation in a very small area,

easing routing constraints from the PCH chipset to the PHY.

The PHY provides a standard IEEE 802.3 Ethernet interface for 1000BASE-T, 100BASETX, and 10BASE-

T applications (802.3ab, 802.3u, and 802.3i, respectively).

#### 12.1.1 I219 Interconnects..........................................................................................

The main interfaces for the I219 are PCIe and SMBus on the host side and Media Dependent Interface

(MDI) on the link side. Transmit traffic is received from the PCH as either PCIe or SMBus packets on the

host interconnect and transmitted as Ethernet packets on the MDI link. Receive traffic arrives as

Ethernet packets on the MDI link and is transferred to the PCH through either the PCIe or SMBus

interconnects.

The PHY switches the in-band traffic automatically between PCIe and SMBus based on platform reset.

The transition protocol is done through SMBus. The PCIe interface is powered down when the Ethernet

link is running in an Sx state.

Table 12-1 SMBus Data Signals on the PCH

```
Group PHY Signal Name PCH Signal Name Description
```
```
Data SMB_DATA SMLINK0_DATA SMBus data
```
Table 12-2 PCIe Data Signals on the PCH

```
Group PHY Signal Name PCH Signal Name Description
```
```
Data
PETp
PETn
```
```
PETp
PETn
PCIe transmit pair
```
```
Data
PERp
PERn
```
```
PERp
PERn
PCIe receive pair
```
```
Note: The appropriate NVM descriptor soft strap (PCHSTRP9) should define which PCIe port is configured as GbE LAN. Refer to
the PCH EDS document for the specific ports that can be used for GbE LAN.
```
Table 12-3 PCIe Data Signals on the PCH

```
Group PHY Signal Name PCH Signal Name Description
```
```
Clock SMB_CLK SML0_CLK SMBus clock.
```
```
Clock
```
##### PE_CLKP

##### PE_CLKN

##### CLKOUT_PCIE[7:0]_P^1

##### CLKOUT_PCIE[7:0]_N^1

1. These signals come from the PCH and drive the PHY.

```
PCIe clock.
```
```
Clock CLK_REQ_N PCIECLKRQ[7:0]# PCIe clock request.
```
```
Reset PE_RST_N PLTRST# PCIe reset.
```

Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 12.1.2 PCIe-Based Interface.......................................................................................

A high-speed SerDes interface uses PCIe electrical signaling at half speed while utilizing a custom

logical protocol for active state operation mode.

Note: PCIe validation tools cannot be used for electrical validation of this interface. However, PCIe

layout rules apply for on-board routing.

12.1.2.1 PCIe Interface Signals

The signals used to connect between the PCH and the PHY in this mode are:

- Serial differential pair running at 1.25 Gb/s for Rx.
- Serial differential pair running at 1.25 Gb/s for Tx.
- 100-MHz differential clock input to the PHY is generated by the PCH.
- Power and clock good indication to the PHY PE_RST_N.
- Clock control through CLK_REQ_N (see Table 12-3). This PHY output should be tied to the PCH
    input and pulled up with a 10 K resistor connected to 3.3 V DC AUX power (present in G3 to S5).

12.1.2.2 PCIe Operation and Channel Behavior

The I219 runs only at 1250 Mb/s speed; 1/2 the Gen 1, 2.5 Gb/s PCIe frequency. Each PCIe root port in

the PCH has the ability to run at 1250 Mb/s. The configuration for a PCH PCIe port attached to a PCIe

Intel PHY device is preloaded from the GbE region of the NVM. The selected port adjusts the transmitter

to run at 1/2 the Gen 1 PCIe speed, and does not need to be PCIe compliant.

Packets transmitted and received over the PCIe interface are full Ethernet packets and not PCIe

transaction/link/physical layer packets.

12.1.2.3 PCIe Connectivity

The PHY transmit/receive pins are output/input signals and are connected to the PCH as listed in

Table 12-1 through Table 12-3.

12.1.2.4 PCIe Reference Clock

The PCIe Interface uses a 100-MHz differential reference clock, denoted PE_CLKP and PE_CLKN. This

signal is typically generated on the platform and routed to the PCIe port.

The frequency tolerance for the PCIe reference clock is ±300 ppm.


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
#### 12.1.3 SMBus Interface

SMBus is a low speed (100/400/1000 KHz) serial bus used to connect various components in a system.

SMBus is used as an interface to pass traffic between the PHY and the PCH when the platform is in a low

power state (Sx). The interface is also used to enable the PCH to configure the PHY as well as pass

in-band information between them.

The SMBus uses two primary signals to communicate: SMBCLK and SMBDATA. Both of these signals

float high with board-level 499  ±5% pull-up resistors.

12.1.3.1 SMBus Connectivity

Table 12-1 through Table 12-3 list the relationship between PHY SMBus pins to the PCH LAN SMBus

pins.

Note: The SMBus signals (SMB_DATA and SMB_CLK) cannot be connected to any other devices

```
other than the integrated MAC. Connect the SMB_DATA and SMB_CLK pins to the
integrated MAC SML0DATA and SML0CLK pins, respectively.
```
#### 12.1.4 PCIe and SMBus Modes....................................................................................

In GbE operation, PCIe is used to transmit and receive data and for MDIO status and control. The PHY

automatically switches the in-band traffic between PCIe and SMBus based on the platform power state.

Table 12-4 lists the operating modes of PCIe and SMBus.

The I219 automatically switches the in-band traffic between PCIe and SMBus based on the system

power state.

Table 12-4 PCIe and SMBus Operating Modes

```
System/Intel Management Engine State
```
##### PHY

```
SMBus PCIe
```
```
S0 and PHY Power Down Not used Electrical Idle (EI)
```
```
S0 and Idle or Link Disconnect Not used EI
```
```
S0 and Link in Low Power Idle (LPI) Not used EI
```
```
S0 and active Not used Active
```
```
Sx Active Power down
```
```
Sx and DMoff Active Power down
```

Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 12.1.5 Transitions Between PCIe and SMBus Interfaces..................................................

12.1.5.1 Switching from SMBus to PCIe

Communication between the integrated MAC and the PHY is done through the SMBus each time the

system is in a low power state (Sx). The integrated MAC/PHY interface is needed while the

Manageability Engine (ME) is still active to transfer traffic, configuration, control and status or to enable

host wake up from the PHY.

Possible states for activity over the SMBus:

1. After power on (G3 to S5).
2. On system standby (Sx).

The switching from the SMBus to PCIe is done when the PE_RST_N signal goes high.

- Any transmit/receive packet that is not completed when PE_RST_N is asserted is discarded.
- Any in-band message that was sent over the SMBus and was not acknowledged is re-transmitted
    over PCIe.

12.1.5.2 Switching from PCIe to SMBus

The communication between the integrated MAC and the PHY is done through PCIe each time the

platform is in active power state (S0). Switching the communication to SMBus is only needed for ME

activity or to enable host wake up in low power states and is controlled by the ME.

The switching from PCIe to SMBus is done when the PE_RST_N signal goes low.

- Any transmit/receive packet that is not completed when PE_RST_N goes to 0b is discarded.
- Any in-band message that was sent over PCIe and was not acknowledged is re-transmitted over
    SMBus.

### 12.2 Platform LAN Design Guidelines

These sections provide recommendations for selecting components and connecting special pins. For

GbE designs, the main elements are:

- The PCH chipset.
- The Intel

##### ®

Ethernet Connection I219.

- A magnetics module and RJ-45 connector
- A GbE region NVM (Non Volatile Memory) image
- A clock source.


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
#### 12.2.1 General Design Considerations for the Intel® Ethernet Connection I219

Sound engineering practices must be followed with respect to unused inputs by terminating them with

pull-up or pull-down resistors, unless otherwise specified in a datasheet, design guide or reference

schematic. Pull-up or pull-down resistors must not be attached to any balls identified as “No Connect.”

These devices might have special test modes that could be entered unintentionally.

Note: The suggested parts recommended in this section (magnetics, crystals, oscillators, etc.) are

```
either in evaluation or have been used successfully in previous designs with good results.
Intel recommends that all selected parts must be validated on each production design.
```
12.2.1.1 Clock Source

All designs require a 25-MHz clock source. The PHY uses the 25-MHz source to generate clocks up to

125 MHz and 1.25 GHz for both the PHY circuits and the PCIe interface. For optimum results with lowest

cost, a 25-MHz parallel resonant crystal can be used along with the appropriate load capacitors at the

XTAL_OUT (X2) and XTAL_IN (X1) leads. The frequency tolerance of the timing device should equal

30 ppm or better. Further detail is found in Section 12.19 and Section 12.20.15.

Note: XTAL_OUT and XTAL_IN are the signal names for the PHY.

There are three steps to crystal qualification:

1. Verify that the vendor’s published specifications in the component datasheet meet the required
    conditions for frequency, frequency tolerance, temperature, oscillation mode and load capacitance
    as specified in the respective datasheet.
2. Perform physical layer conformance testing and EMC (FCC and EN) testing in real systems.
3. Independently measure the component’s electrical parameters in real systems. Measure frequency
    at a test output to avoid test probe loading effects at the PHY. Check that the measured behavior is
    consistent from sample to sample and that measurements meet the published specifications. For
    crystals, it is also important to examine startup behavior while varying system voltage and
    temperature.

12.2.1.2 Magnetics Module

The magnetics module has a critical effect on overall IEEE and emissions conformance. The device

should meet the performance required for a design with reasonable margin to allow for manufacturing

variation. Carefully qualifying new magnetics modules prevents problems that might arise because of

interactions with other components or the printed circuit board itself.

The steps involved in magnetics module qualification are similar to those for crystal qualification:

1. Verify that the vendor’s published specifications in the component datasheet meet or exceed the
    required IEEE specifications.
2. Independently measure the component’s electrical parameters on the test bench, checking samples
    from multiple lots. Check that the measured behavior is consistent from sample to sample and that
    measurements meet the published specifications.
3. Perform physical layer conformance testing and EMC (FCC and EN) testing in real systems. Vary
    temperature and voltage while performing system-level tests.


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

Magnetics modules for 1000BASE-T Ethernet as used by the PHY only are similar to those designed

solely for 10/100 Mb/s, except that there are four differential signal pairs instead of two. The following

magnetics modules are not recommended, however, they have been used successfully in previous

designs:

12.2.1.3 Criteria for Integrated Magnetics Electrical

Qualification

Table 12-7 gives the criteria used to qualify integrated magnetics.

Table 12-5 Discrete Magnetics Modules: Manufacturers and Part Numbers

```
Manufacturer Part Number Notes
```
```
Pulse* H5120 16.51 x 9.65 x 2.08 mm, 8 core
```
```
Bothhand* GST5009LF 15.10 x 10 x 4 mm, 8 core
```
```
Delta* LFE9249-R-IN 15.10 x 10 x 4 mm, 8 core
```
Table 12-6 Discrete RJ45

```
Manufacturer Part Number Notes
```
```
Lotes* AJKM0007-P001A01 Thinnest solution, 5.2 mm height
```
```
Foxconn JM3611-NS420013-7H Low profile, 10 mm height
```
```
Pulse E6688-001-01-L Low profile, 10 mm height
```
Table 12-7 Integrated Magnetics Recommended Qualification Criteria

```
Open Circuit
Inductance (OCL)
```
```
w/8 mA DC bias; at 25 °C 400 H Min
```
```
w/8 mA DC bias; at 0 °C to 70 °C 350 H Min
```
```
Insertion Loss
```
```
100 KHz through 999 KHz
1.0 MHz through 60.0 MHz
60.1 MHz through 80.0 MHz
80.1 MHz through 100.0 MHz
100.1 MHz through 125.0 MHz
```
```
1dB Max
0.6dB Max
0.8dB Max
1.0dB Max
2.4dB Max
```
```
Return Loss
```
```
1.0 MHz through 40.0 MHz
40.1 MHz through 100.0 MHz
When reference impedance is 85 Ohms,
100 Ohms, and 115 Ohms. Note that
R.L. values may vary with MDI trace
lengths. The LAN magnetics may need
to be measured in the platform where it
will be used.
```
```
18.0 dB Min
12 – 20 * LOG (Freq in MHz / 80) dB Min
```
```
Crosstalk Isolation
Discrete Modules
```
```
1.0 MHz through 29.9 MHz
30.0 MHz through 250.0 MHz
250.1 MHz through 375.0 MHz
```
```
-50.3+(8.8*(Freq in MHz / 30)) dB Max
-(26 -(16.8*(LOG(Freq in MHz / 250 MHz)))) dB Max
-26.0 dB Max
```
```
Crosstalk Isolation
Integrated Modules
(Proposed)
```
```
1.0 MHz through 10 MHz
10.0 MHz through 100.0 MHz
100 MHz through 375.0 MHz
```
```
-50.8+(8.8*(Freq in MHz / 10)) dB Max
-(26 -(16.8*(LOG(Freq in MHz / 100 MHz)))) dB Max
-26.0 dB Max
```

```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
#### 12.2.2 NVM for PHY Implementations

The LAN only supports an SPI Flash, which is connected to the PCH. Several words of the NVM are

accessed automatically by the device after reset to provide pre-boot configuration data before it is

accessed by host software. The remainder of the NVM space is available to software for storing the MAC

address, serial numbers, and additional information. More details may be obtained from the Datasheet.

Intel has an MS-DOS* software utility called EEupdate that is used to program the SPI Flash images in

development or production line environments. A copy of this program can be obtained through your

Intel Field Service representative.

#### 12.2.3 LED...............................................................................................................

The PHY has three LED outputs that can be configured via the NVM. The hardware configuration is

shown in Figure 12-2.

Note: Intel recommends that the LED pins only be used to drive LEDs. These pins tri-state in ULP

mode and might not drive valid logic levels.

Refer to the Intel® Ethernet Connection I219 Reference Schematic for default LED color based on

reference design.

```
Diff to CMR
```
```
1 MHz through 29.9 MHz
30.0 MHz through 500 MHz
```
```
-40.2+(5.3*((Freq in MHz / 30)) dB Max
-(22-(14*(LOG((Freq in MHz / 250)))) dB Max
```
```
CM to CMR
```
```
1 MHz through 270 MHz
270.1 MHz through 300 MHz
300.1 MHz through 500 MHz
```
```
-57+(38*((Freq in MHz / 270)) dB Max
-17-2*((300-(Freq in MHz) / 30) dB Max
-17 dB Max
```
```
Hi-Voltage Isolation
```
```
1500 Vrms at 50 or 60 Hz for 60 sec.
or: 2250 Vdc for 60 seconds
```
```
Minimum
```
Figure 12-2 LED Hardware Configuration

Table 12-7 Integrated Magnetics Recommended Qualification Criteria


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

Refer to Section 9.0 of this datasheet for details regarding the programming of the LED’s and the

various modes. The default values for the PHY (based on the LED NVM setting--word 0x18 of the LAN

region) are listed in the Table 12-8.

12.2.3.1 RBIAS

RBIAS requires external resistor connection to bias the internal analog section of the device. The input

is sensitive to the resistor value. Resistors of 1% tolerance must be used. Connect RBIAS through a

3.01 K 1% pull-down resistor to ground, then place it no more than one half inch (0.5”) away from the

PHY.

12.2.3.2 LAN Disable

The PHY enters a power-down state when the LAN_DISABLE_N pin is asserted low. Exiting this mode

requires setting the LAN_DISABLE_N pin to a logic one. Connect LAN_DISABLE_N to

LAN_PHY_PWR_CTRL / GPIO12 on the PCH.

#### 12.2.4 Exposed Pad* (e-Pad) Design and SMT Assembly Guide

12.2.4.1 Overview

This section provides general information about ePAD and SMT assemblies. Chip packages have

exposed die pads on the bottom of each package to provide electrical interconnections with the printed

circuit board. These ePADs also provide excellent thermal performance through efficient heat paths to

the PCB.

Packages with ePADs are very popular due to their low cost. Note that this section provides only basic

information and references in regards to the ePAD. It is recommended that each customer consult their

fab and assembly house to obtain more details on how to implement the ePAD package design. Each

fab and assembly house might need to tune the land pattern/stencil and create a solution that best

suits their methodology and process.

Table 12-8 LED Default Values

```
LED Mode Color Blink Polarity
```
```
LED0 Link Up/Activity Green 200 ms on/200 ms off Active low
```
```
LED1 Link 1000 Yellow No Active low
```
```
LED2 Link 100 Green No Active low
```

```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
12.2.4.2 PCB Design Requirements

To maximize both heat removal and electrical performance, a land pattern must be incorporated on the

PCB within the footprint of the package corresponding to the exposed metal pad or exposed heat slug of

the package as shown in the following figures. Refer to the specific product datasheet for actual

dimensions.

Note: Due to the package size, a via-in-pad configuration must be used. Figure 12-3 and

```
Figure 12-4 are general guidelines. See Figure 12-5 for specific via-in-pad thermal pattern
recommendations.
```
Note: Encroached and uncapped via configurations have voids less than the maximum allowable

```
void percentage. Uncapped via provides a path for trapped air to escape during the reflow
soldering process.
```
Figure 12-3 Typical ePAD Land Pattern

Figure 12-4 Typical Thermal Pad and Via Recommendations


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

Note: Secondary side solder bumps might be seen in an uncapped via design. This needs to be

considered when placing components on the opposite side of the PHY.

12.2.4.3 Board Mounting Guidelines

The following are general recommendations for mounting a QFN-48 device on the PCB. This should

serve as the starting point in assembly process development and it is recommended that the process

should be developed based on past experience in mounting standard, non-thermally/electrically

enhanced packages.

12.2.4.4 Stencil Design

For maximum thermal/electrical performance, it is required that the exposed pad/slug on the package

be soldered to the land pattern on the PCB. This can be achieved by applying solder paste on both the

pattern for lead attachment as well as on the land pattern for the exposed pad. While for standard

(non-thermally/non-electrically enhanced) lead-frame based packages the stencil thickness depends on

the lead pitch and package co-planarity, the package standoff must also be considered for the

thermally/electrically enhanced packages to determine the stencil thickness. In this case, a stencil foil

thickness in the range of 5-6 mils (or 0.127—0.152 mm) is recommended; likely or practically, a choice

of either 5 mils or 6 mils. Tolerance-wise, it should not be worse than ±0.5 mil.

Note: Industry specialists typically use ±0.1 mil tolerance on stencil for its feasible precision.

The aperture openings should be the same as the solder mask openings on the land pattern. Since a

large stencil opening may result in poor release, the aperture opening should be subdivided into an

array of smaller openings, similar to the thermal land pattern shown in Figure 12-6.

Note: Refer to the specific product datasheet for actual dimensions.

Figure 12-5 Recommended Thermal Via Patterns


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
Important General Guidelines:

- The Stencil Aperture Openings of the e-PAD must not go outside of the exposed landing area
    (solder mask opening).
- The Stencil Aperture Openings of the e-PAD should be about 80% of the exposed landing area
    (solder mask opening).

The I219 e-PAD has D2=E2=3 mm. Therefore, the Stencil Design can only have four aperture openings

for the e-PAD. This can be achieved by setting R=S=1.35 mm and T=0.3. Using this arrangement, the

Aperture’s/e-PAD area is 81% of the exposed landing area (solder mask opening).

Note: This information is intended only as general guidance. Consult with the manufacturer to

confirm the final design meets requirements.

12.2.4.5 Assembly Process Flow

Figure 12-7 below shows the typical process flow for mounting packages to the PCB.

Figure 12-6 Stencil Design Recommendation

Figure 12-7 Assembly Flow


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

12.2.4.6 Reflow Guidelines

The typical reflow profile consists of four sections. In the preheat section, the PCB assembly should be

preheated at the rate of 1 to 2 °C/sec to start the solvent evaporation and to avoid thermal shock. The

assembly should then be thermally soaked for 60 to 120 seconds to remove solder paste volatiles and

for activation of flux. The reflow section of the profile, the time above liquidus should be between 45 to

60 seconds with a peak temperature in the range of 245 to 250 °C, and the duration at the peak should

not exceed 30 seconds. Finally, the assembly should undergo cool down in the fourth section of the

profile. A typical profile band is provided in Figure 12-8, in which 220 °C is referred to as an

approximation of the liquidus point. The actual profile parameters depend upon the solder paste used

and specific recommendations from the solder paste manufacturers should be followed.

Note: Contact your Intel Field Service Representative for any designs unable to meet the

recommended guidance for E-pad implementation.

```
Notes:
```
1. Preheat: 125 °C -220 °C, 150 - 210 s at 0.4 k/s to 1.0 k/s
2. Time at T > 220 °C: 60 - 90 s
3. Peak Temperature: 245-250 °C
4. Peak time: 10 - 30 s
5. Cooling rate: <= 6 k/s
6. Time from 25 °C to Peak: 240 – 360 s
7. Intel recommends a maximum solder void of 50% after reflow.

Figure 12-8 Typical Profile Band


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
### 12.3 PCH-SMBus/PCIe LOM Design Guidelines

This section contains guidelines on how to implement a PCH/PHY single solution on a system

motherboard. It should not be treated as a specification, and the system designer must ensure through

simulations or other techniques that the system meets the specified timings. The following are

guidelines for both PCH SMBus and PCIe interfaces. Note that PCIe is only applicable to the PHY.

The SMBus/PCIe Interface between the PCH and PHY is shown at high level in Figure 12-9. For

complete design details, always refer to the Intel

##### ®

Ethernet Connection I219 Reference Schematic.

Note: Board designers MUST select the available PCIe lane based on a specific platform PCH

```
External Design Specification (EDS). Not all PCIe lanes on a PCH are available to connect
the I219 GbE PHY to the PCIe interface. For example, The SKL U/Y PCH EDS requires the
I219 to only connect to PCIe ports 3, 4, 5, 9, and 10. Contact your local Intel
representative for more details.
```
Refer to Section 12.6 for PCI Express Routing Guidelines.

```
Notes:
```
1. Not all PCH PCIe ports can be used for the I219. Refer to the SkyLake/Greenlow/Purley EDS documentation for the
    specific ports that can be used with the I219.
2. Any CLKOUT_PCIE and PCIECLKRQ ports can be used to connect to the I219. These can be selected using the FITC
    tool.
3. PETp/n, PERp/n, PE_CLKp/n should be routed as a differential pair as indicated in the PCIe specification.
4. Refer to the I219 reference schematics and design checklists for more details.

Figure 12-9 Single Solution Interconnect


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 12.4 SMBus Design Considerations

No single SMBus design solution works for all platforms. Designers must consider the total bus

capacitance and device capabilities when designing SMBus segments. Routing SMBus to the PCI slots

makes the design process even more challenging since they add so much capacitance to the bus. This

extra capacitance has a large affect on the bus time constant which in turn affects the bus rise and fall

times.

Primary considerations in the design process are:

- Amount of VCC_SUS3_3 current available, that is, minimizing load of VCC_SUS3_3.
- The pull-up resistor size for the SMBus data and clock signals is dependent on the bus load (this
    includes all device leakage currents). Generally the SMBus device that can sink the least amount of
    current is the limiting agent on how small the resistor can be. The pull-up resistor cannot be made
    so large that the bus time constant (Resistance X Capacitance) does not meet the SMBus rise and
    time specification.
- The maximum bus capacitance that a physical segment can reach is 400 pF.
- SMBus devices that can operate in STR must be powered by the VCC_SUS3_3 supply.
- It is recommended that I

##### 2

```
C (Inter-Integrated Circuit) devices be powered by the VCC_core supply.
During an SMBus transaction in which the device is sending information to the integrated MAC, the
device may not release the SMBus if the integrated MAC receives an asynchronous reset. VCC_core is
used to enable the BIOS to reset the device if necessary. SMBus 2.0-compliant devices have a
timeout capability that makes them in-susceptible to this I
```
##### 2

```
C issue, enabling flexibility in choosing a
voltage supply.
```
- No other devices (except the integrated MAC and pull-up resistors) should be connected to the
    SMBus that connects to the PHY.
- For system LAN on motherboard (LOM) designs: The traces should be less than 70 inches for
    stripline and less than 100 inches for Microstrip. These numbers depend on the stackup, dielectric
    layer thickness, and trace width. The total capacitance on the trace and input buffers should be
    under 400 pF.
- For system LAN on daughterboard designs: Being conservative, the traces should be less than
    7 inches for stripline designs and less than 10 inches for Microstrip designs. The lengths depend on
    the stackup, dielectric layer thickness, and trace width. Longer traces can be used as long as the
    total capacitance on the trace and input buffers is under 30 pF.

Note: Refer to Section 12.1.3 for additional SMBus design considerations.

### 12.5 General Layout Guidelines

PHY interface signals must be carefully routed on the motherboard to meet the timing and signal quality

requirements of their respective interface specifications. The following are some general guidelines that

should be followed in designing a LAN solution. It is recommended that the board designer simulate the

board routing to verify that the specifications are met for flight times and skews due to trace mismatch

and crosstalk.


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
### 12.6 Layout Considerations

Critical signal traces should be kept as short as possible to decrease the likelihood of effects by high

frequency noise of other signals, including noise carried on power and ground planes. This can also

reduce capacitive loading.

Since the transmission line medium extends onto the printed circuit board, layout and routing of

differential signal pairs must be done carefully.

Designing for GbE (1000BASE-T) operation is very similar to designing for 10/100 Mb/s. For the PHY,

system level tests should be performed at all three speeds.

### 12.7 Guidelines for Component Placement

Component placement can affect signal quality, emissions, and component operating temperature.

Careful component placement can:

- Decrease potential problems directly related to electromagnetic interference (EMI), which could
    cause failure to meet applicable government test specifications. In this case, place the PHY more
    than one inch from the edge of the board.
- Simplify the task of routing traces. To some extent, component orientation affects the complexity of
    trace routing. The overall objective is to minimize turns and crossovers between traces.

#### 12.7.1 PHY Placement Recommendations

Minimizing the amount of space needed for the PHY is important because other interfaces compete for

physical space on a motherboard near the connector. The PHY circuits need to be as close as possible to

the connector.

Figure 12-10 illustrates some basic placement distance guidelines. To simplify the diagram, it shows

only two differential pairs, but the layout can be generalized for a GbE system with four analog pairs.

The ideal placement for the PHY (LAN silicon) is approximately one inch behind the magnetics module.

While it is generally a good idea to minimize lengths and distances, Figure 12-10 also illustrates the

need to keep the PHY away from the edge of the board and the magnetics module for best EMI

performance.


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

The PHY, referred to as “LAN Device” in Figure 12-10, must be at least one inch from any chassis

openings. To help reduce EMI, the following recommendations should be followed:

- Minimize the length of the MDI interface. See detail in Table 12-9 on page 221.
- Place the MDI traces no closer than 0.5 inch (1.3 cm) from the board edge.
- The I219 must be placed greater than 1" away from any hole to the outside of the chassis larger
    than 0.125 inches (125 mils) The larger the hole the higher the probability the EMI and ESD
    immunity will be negatively affected.
- The I219 should be placed greater than 250 mils from the board edge.
- If the connector or integrated magnetics module is not shielded, the I219 should be placed at least
    one inch from the magnetics (if a LAN switch is not used).
- Placing the I219 closer than one inch to unshielded magnetics or connectors increases the
    probability of failed EMI and common mode noise. If the LAN switch is too far away, it negatively
    affects IEEE return loss performance.
- The RBIAS trace length must be less than one inch.
- Place the crystal less than one inch (2.54 cm) from the PHY.

```
* This distance is variable and follows the general guidelines.
```
Figure 12-10 LAN Device Placement: At Least One Inch from Chassis Openings or Unshielded

Connectors—Mobile


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
### 12.8 MDI Differential-Pair Trace Routing for LAN Design

Trace routing considerations are important to minimize the effects of crosstalk and propagation delays

on sections of the board where high-speed signals exist. Signal traces should be kept as short as

possible to decrease interference from other signals, including those propagated through power and

ground planes.

### 12.9 Signal Trace Geometry

One of the key factors in controlling trace EMI radiation are the trace length and the ratio of trace-width

to trace-height above the reference plane. To minimize trace inductance, high-speed signals and signal

layers that are close to a reference or power plane should be as short and wide as practical. Ideally, the

trace-width to trace-height above the ground plane ratio is between 1:1 and 3:1. To maintain trace

impedance, the width of the trace should be modified when changing from one board layer to another if

the two layers are not equidistant from the neighboring planes.

Each pair of signals should have a differential impedance of 100  ±15%.

A set of trace length calculation tools are available from Intel to aid with MDI topology design. For

access to documentation contact your Intel representative.

Figure 12-11 PLC Placement: At Least One Inch from I/O Backplane

Figure 12-12 Effect of LAN Device Placed Too Close to an Rj-45 Connector or Chassis

Opening


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

When performing a board layout, the automatic router feature of the CAD tool must not route the

differential pairs without intervention. In most cases, the differential pairs will require manual routing.

Note: Measuring trace impedance for layout designs targeting 100  often results in lower actual

```
impedance due to over-etching. Designers should verify actual trace impedance and adjust
the layout accordingly. If the actual impedance is consistently low, a target of 105  to
110  should compensate for over-etching.
```
It is necessary to compensate for trace-to-trace edge coupling, which can lower the differential

impedance by up to 10 , when the traces within a pair are closer than 30 mils (edge-to-edge).

Table 12-9 MDI Routing Summary

```
Parameter Main Route Guidelines
Breakout
Guidelines^1
Notes
```
```
Signal group
```
##### MDI_PLUS[0:3]

##### MDI_MINUS[0:3]

```
Microstrip/stripline uncoupled single-ended
impedance specification
```
##### 50  ±10%

```
Microstrip/stripline uncoupled differential
impedance specification
```
##### 100  ±15% 2, 3

```
Microstrip nominal trace width Design dependent Design dependent 4
```
```
Microstrip nominal trace space Design dependent Design dependent 3, 5
```
```
Microstrip/stripline trace length 8 in (203 mm) maximum 6, 7
```
```
Microstrip pair-to-pair space (edge-to-edge)
 7 times the thickness of the thinnest
adjacent dielectric layer
Figure 12-13
```
```
Stripline pair-to-pair space (edge-to-edge)
 6 times the thickness of the thinnest
adjacent dielectric layer
```
```
Microstrip bus-to-bus spacing
 7 times the thickness of the thinnest
adjacent dielectric layer
```
```
Stripline bus-to-bus spacing
 6 times the thickness of the thinnest
adjacent dielectric layer
```
```
Notes:
```
1. Pair-to-pair spacing 3 times the dielectric thickness for a maximum distance of 500 mils from the pin.
2. Board designers should ideally target 100  ±15%. If it’s not feasible (due to board stack-up) it is recommended that board
    designers use a 95  ±10% target differential impedance for MDI with the expectation that the center of the impedance is
    always targeted at 95 . The ±10% tolerance is provided to allow for board manufacturing process variations and not lower
    target impedances. The minimum value of impedance cannot be lower than 85 .
3. Simulation shows 80  differential trace impedances degrade MDI return loss measurements by approximately 1 dB from that
    of 90 .
4. Stripline is NOT recommended due to thinner more resistive signal layers.
5. Use a minimum of 21 mil (0.533 mm) pair-to-pair spacing for board designs that use the CRB design stack-up. Using
    dielectrics that are thicker than the CRB stack-up might require larger pair-to-pair spacing.
6. For applications that require a longer MDI trace length of more than 8 inches (20.32 mm), it is recommended that thicker
    dielectric or lower Er materials be used. This permits higher differential trace impedance and wider, lower loss traces. Refer to
    Table 12-10 for examples of microstrip trace geometries for common circuit board materials.
7. If a LAN switch is not used, the maximum trace length is 4 inches (102 mm). Mobile designs without LAN switch can range up
    to ~8 inches. Refer to Table 12-10 for trace length information.


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
Note: Use the MDI Differential Trace Calculator to determine the maximum MDI trace length for

```
your trace geometry and board stack-up. Contact your Intel Field Service Representative
for access.
```
The following factors can limit the maximum MDI differential trace lengths for IEEE conformance:

- Dielectric thickness.
- Dielectric constant.
- Nominal differential trace impedance.
- Trace impedance tolerance.
- Copper trace losses.
- Additional devices, such as switches, in the MDI path may impact IEEE conformance.

Board geometry should also be factored in when setting trace length.

Table 12-10 Maximum Trace Lengths Based on Trace Geometry and Board Stack-Up

```
Dielectric
Thickness
(mils)
```
```
Dielectric
Constant (DK)
at
1 MHz
```
```
Width /
Space/ Width
(mils)
```
```
Pair-to-Pair
Space (mils)
```
```
Nominal
Impedance
(Ohms)
```
```
Impedance
Tolerance
(±%)
```
```
Maximum
Trace Length
(inches)^1
```
1. Longer MDI trace lengths may be achievable, but may make it more difficult to achieve IEEE conformance. Simulations have shown
    deviations are possible if traces are kept short. Longer traces are possible; use cost considerations and stack-up tolerance for
    differential pairs to determine length requirements.

##### 2.7 4.05 4/10/4 19 952 172 3.5

##### 2.7 4.05 4/10/4 19 952 152 4

##### 2.7 4.05 4/10/4 19 95 10 5

##### 3.3 4.1 4.2/9/4.2 23 1002

2. Deviations from 100  nominal and/or tolerances greater than 15% decrease the maximum length for IEEE conformance.

##### 172 4

##### 3.3 4.1 4.2/9/4.2 23 100 15 4.6

##### 3.3 4.1 4.2/9/4.2 23 100 10 6

##### 4 4.2 5/9/5 28 1002 172 4.5

##### 4 4.2 5/9/5 28 100 15 5.3

##### 4 4.2 5/9/5 28 100 10 7


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 12.10 Trace Length and Symmetry

The differential traces should be equal in total length to within 10 mils (0.254 mm) per segment within

each pair and as symmetrical as possible. Asymmetrical and unequal length traces in the differential

pairs contribute to common mode noise. If a choice has to be made between matching lengths and

fixing symmetry, more emphasis should be placed on fixing symmetry. Common mode noise can

degrade the receive circuit’s performance and contribute to radiated emissions.

The intra-pair length matching on the pairs must be within 10 mils on a segment by segment basis. An

MDI segment is defined as any trace within the same layer. For example, transitioning from one layer to

another through a via is considered as two separate MDI segments.

The end to end total trace lengths within each differential pair must match as shown in Figure 12-13.

The end to end trace length is defined as the total MDI length from one component to another

regardless of layer transitions.

The pair to pair length matching is not as critical as the intra-pair length matching but it should be

within 2 inches.

When using Microstrip, the MDI traces should be at least 7x the thinnest adjacent dielectric away from

the edge of an adjacent reference plane. When using stripline, the MDI traces should be at least 6x the

thinnest adjacent dielectric away from the edge of an adjacent reference plane.

Figure 12-13 MDI Trace Geometry


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
Note: Similar topology applies to MDI routing from the I219 to the dock RJ45 connector.

### 12.11 Impedance Discontinuities

Impedance discontinuities cause unwanted signal reflections. Vias (signal through holes) and other

transmission line irregularities should be minimized. If vias must be used, a reasonable budget is four

or less per differential trace. Unused pads and stub traces should also be avoided.

### 12.12 Reducing Circuit Inductance

Traces should be routed over a continuous reference plane with no interruptions. If there are vacant

areas on a reference or power plane, the signal conductors should not cross the vacant area. This

causes impedance mismatches and associated radiated noise levels.

### 12.13 Signal Isolation

Also, keep the MDI traces away from the edge of an adjacent reference plane by a distance that is at

least 7x the thickness of the thinnest adjacent dielectric layer (7x when using Microstrip; 6x when using

stripline). If digital signals on other board layers cannot be separated by a ground plane, they should be

routed perpendicular to the differential pairs. If there is another LAN controller on the board, the

differential pairs from that circuit must be kept away.

Figure 12-14 MDI Differential Trace Geometry


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

Other rules to follow for signal isolation include:

- Separate and group signals by function on separate layers if possible. If possible, maintain at least
    a gap of 30 mils between all differential pairs (Ethernet) and other nets, but group associated
    differential pairs together.
- Physically group together all components associated with one clock trace to reduce trace length and
    radiation.
- Isolate I/O signals from high-speed signals to minimize crosstalk, which can increase EMI emission
    and susceptibility to EMI from other signals.
- Avoid routing high-speed LAN traces near other high-frequency signals associated with a video
    controller, cache controller, processor, switching power supplies, or other similar devices.

### 12.14 Power and Ground Planes

Good grounding requires minimizing inductance levels in the interconnections and keeping ground

returns short, signal loop areas small, and power inputs bypassed to signal return. This will significantly

reduce EMI radiation.

The following guidelines help reduce circuit inductance in both backplanes and motherboards:

- Route traces over a continuous plane with no interruptions. Do not route over a split power or
    ground plane. If there are vacant areas on a ground or power plane, avoid routing signals over the
    vacant area. This will increase inductance and EMI radiation levels.
- All ground vias should be connected to every ground plane; and every power via, to all power
    planes at equal potential. This helps reduce circuit inductance.
- Physically locate grounds between a signal path and its return. This will minimize the loop area.
- Split the ground plane beneath a magnetics module. The RJ-45 connector side of the transformer
    module should have chassis ground beneath it.

Caution: DO NOT do this if the RJ-45 connector has integrated USB.

Note: All impedance-controlled signals should be routed in reference to a solid plane. If there are

```
plane splits on a reference layer and the signal traces cross those splits, stitching capacitors
should be used within 40 mils of where the crossing occurs. See Figure 12-15.
```
If signals transition from one reference layer to another reference layer then stitching capacitors or

connecting vias should be used based on the following:

- If the transition is from power-referenced layer to a ground-referenced layer or from one voltage-
    power referenced layer to a different voltage-power referenced layer, then stitching capacitors
    should be used within 40 mils of the transition.
- If the transition is from one ground-referenced layer to another ground-referenced layer or is from
    a power-referenced layer to the same net power-referenced layer, then connecting vias should be
    used within 40 mils of the transition.


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
Figure 12-15 Trace Transitioning Layers and Crossing Plane Splits

Figure 12-16 Via Connecting GND to GND


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 12.15 Traces for Decoupling Capacitors

Traces between decoupling and I/O filter capacitors should be as short and wide as practical. Long and

thin traces are more inductive and reduce the intended effect of decoupling capacitors. Also, for similar

reasons, traces to I/O signals and signal terminations should be as short as possible. Vias to the

decoupling capacitors should be sufficiently large in diameter to decrease series inductance. Refer to

the Power Delivery section for the PHY in regards to actual placement requirements of the capacitors.

### 12.16 Ground Planes Under a Magnetics Module

The magnetics module chassis or output ground (secondary side of transformer) should be separated

from the digital or input ground (primary side) by a physical separation of 100 mils minimum. Splitting

the ground planes beneath the transformer minimizes noise coupling between the primary and

secondary sides of the transformer and between the adjacent coils in the magnetics. This arrangement

also improves the common mode choke functionality of magnetics module.

Caution: DO NOT do this if the RJ-45 connector has integrated USB.

Figure 12-18 shows the preferred method for implementing a ground split under an integrated

magnetics module/RJ-45 connector.

Figure 12-17 Stitching Capacitor Between Vias Connecting GND to GND


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
The placement of C1 through C6 may also differ for each board design (in other words, not all of the

capacitors may need to be populated). Also, the capacitors may not be needed on both sides of the

magnetics module.

Note: If using an integrated magnetics module without USB, provide a separate chassis ground

```
“island” to ground around the RJ-45 connector. The split in the ground plane should be at
least 20 mils wide.
```
Some integrated magnetics modules/RJ-45 connectors have recently incorporated the USB into the

device. For this type of magnetics module, a chassis ground moat may not be feasible due to the digital

ground required for the USB pins and their placement relative to the magnetics pins. Thus, a

continuous digital ground without any moats or splits must be used. Figure 12-19 provides an example

of this.

Figure 12-18 Ideal Ground Split Implementation

Table 12-11 Capacitor Stuffing Option Recommended Values

```
Capacitors Value
```
```
C3, C4 4.7 μF or 10 μF
```
```
C1, C2, C5, C6 470 pF to 0.1 μF
```

Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 12.17 Light Emitting Diodes

The device has three high-current outputs to directly drive LEDs for link, activity and speed indication.

Since LEDs are likely to be integral to a magnetics module, take care to route the LED traces away from

potential sources of EMI noise. In some cases, it may be desirable to attach filter capacitors.

LAN LED traces should be placed at least 6x (side by side separation) the dielectric height from sources

of noise (ex: signaling traces) and susceptible signal traces (ex: reset signals) on the same or adjacent

layers.

LAN LED traces should be placed at least 7x (broadside coupling) the dielectric height from sources of

noise (ex: signaling traces) and susceptible signal traces (ex: reset signals) on the same or adjacent

layers.

### 12.18 Considerations for Layout

The PHY MDI routing using microstrip requires a differential impedance of 100 ±15%. A 35-mil

(0.889 mm) separation is required between pairs. The 35-mil separation can be reduced for 24 mils

(0.61 mm) in breakout routing. All MDI traces must be referenced to ground.

Figure 12-19 Ground Layout with USB


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
### 12.19 Frequency Control Device Design Considerations

This section provides information regarding frequency control devices, including crystals and oscillators,

for use with all Intel Ethernet controllers. Several suitable frequency control devices are available; none

of which present any unusual challenges in selection. The concepts documented within this section are

applicable to other data communication circuits, including the PHY.

The PHY contains amplifiers that form the basis for feedback oscillators when they are used with the

specific external components. These oscillator circuits, which are both economical and reliable, are

described in more detail in Section 12.20.3.

The chosen frequency control device vendor should be consulted early in the design cycle. Crystal and

oscillator manufacturers familiar with networking equipment clock requirements may provide assistance

in selecting an optimum, low-cost solution.

Several types of third-party frequency reference components are currently available. Descriptions of

each type follow in subsequent sections. They are also listed in order of preference.

### 12.20 Crystals and Oscillators

Clock sources should not be placed near I/O ports or board edges. Radiation from these devices may be

coupled onto the I/O ports or out of the system chassis. Crystals should also be kept away from the

Ethernet magnetics module to prevent interference.

Crystal and load capacitors should be placed on the printed circuit boards as close to the PHY as

possible, which is within 1.0 inch. Traces from XTAL_IN (X1) and XTAL_OUT (X2) should be routed as

symmetrically as possible. Do not route X1 and X2 as a differential trace. Doing so increases jitter and

degrades LAN performance.

- The crystal trace lengths should be less than 1 inch.
- The crystal load capacitors should be placed less than 1" from the crystal.
- The clock lines must be at least 5 times the height of the thinnest adjacent dielectric layer away
    from other from other digital traces (especially reset signals), I/O ports, board edge, transformers
    and differential pairs.
- The clock lines must not cross any plane cuts on adjacent power or ground reference layers unless
    there are decoupling capacitors or connecting vias near the transition.
- The clock lines should not cross or run in parallel (within 3x the dielectric thickness of the closest
    dielectric layer) with any trace (100 MHz signal or higher) on an adjacent layer.

#### 12.20.1 Quartz Crystal

Quartz crystals are generally considered to be the mainstay of frequency control components due to

their low cost and ease of implementation. They are available from numerous vendors in many package

types and with various specification options.


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 12.20.2 Fixed Crystal Oscillator

A packaged fixed crystal oscillator comprises of an inverter, a quartz crystal, and passive components

conveniently packaged together. The device renders a strong, consistent square wave output.

Oscillators used with microprocessors are supplied in many configurations and tolerances.

Crystal oscillators should be restricted for use in special situations, such as shared clocking among

devices or multiple controllers. Since clock routing can be difficult to accomplish, it is preferable to

provide a separate crystal for each device.

Note: Contact your Intel Field Service Representative to obtain the most current device

documentation prior to implementing this solution.

#### 12.20.3 Crystal Selection Parameters

All crystals used with Intel Ethernet controllers are described as “AT-cut,” which refers to the angle at

which the unit is sliced with respect to the long axis of the quartz stone.

Table 12-12 lists crystals which have been used successfully in past designs. (No particular product is

recommended.)

The datasheet for the PHY lists the crystal electrical parameters and provides suggested values for

typical designs. Designers should refer to criteria outlined in their respective PHY datasheet. The

parameters are described in the following subsections.

#### 12.20.4 Vibrational Mode

Crystals in the frequency range referenced above are available in both fundamental and third overtone.

Unless there is a special need for third overtone, fundamental mode crystals should be used.

Table 12-12 Crystal Manufacturers and Part Numbers

```
Manufacturer Part Number Notes
```
```
Epson* Q22FA1280021400
```
```
2.0 x 1.6 x 0.5mm
Small part. Loading capacitors = 10 pF.
```
```
TXC Corporation, USA* 8Y25000010
```
```
2.0 x 1.6 x 0.5mm
Small part. Loading capacitors = 10 pF.
```
```
TXC Corporation, USA 7M25020011 3.2 x 2.5 x 0.7 mm
```
```
TXC Corporation, USA 9C25000008 HC-49S type, SMD (low profile 3 mm)
```
```
NDK America, Inc.* EXS00A-CH00387 3.2 x 2.5 x 0.8 mm
```
```
NDK America, Inc. 41CD25.0F1303018 HC-49S type, SMD
```

```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
#### 12.20.5 Nominal Frequency..........................................................................................

Intel Ethernet controllers use a crystal frequency of 25.000 MHz. The 25 MHz input is used to generate

a 125-MHz transmit clock for 100BASE-TX and 1000BASE-TX operation, and 10-MHz and 20-MHz

transmit clocks, for 10BASE-T operation.

#### 12.20.6 Frequency Tolerance

The frequency tolerance for an Ethernet Platform LAN Connect device is dictated by the IEEE 802.3

specification as ±50 parts per million (ppm). This measurement is referenced to a standard

temperature of 25 °C. Intel recommends a frequency tolerance of ±30 ppm to ensure for any frequency

variance contributed by the PCB.

#### 12.20.7 Temperature Stability and Environmental Requirements

Temperature stability is a standard measure of how the oscillation frequency varies over the full

operational temperature range (and beyond). Several optional temperature ranges are currently

available, including -40 °C to +85 °C for industrial environments. Some vendors separate operating

temperatures from temperature stability. Manufacturers may also list temperature stability as 50 ppm

in their data sheets.

Note: Crystals also carry other specifications for storage temperature, shock resistance, and

```
reflow solder conditions. Crystal vendors should be consulted early in the design cycle to
discuss its application and environmental requirements.
```
#### 12.20.8 Calibration Mode

The terms “series-resonant” and “parallel-resonant” are often used to describe crystal oscillator

circuits. Specifying parallel mode is critical to determining how the crystal frequency is calibrated at the

factory.

A crystal specified and tested as series resonant oscillates without problem in a parallel-resonant

circuit, but the frequency is higher than nominal by several hundred parts per million. The purpose of

adding load capacitors to a crystal oscillator circuit is to establish resonance at a frequency higher than

the crystal’s inherent series resonant frequency.

Figure 12-20 illustrates a simplified schematic of the internal oscillator circuit. Pin X1 and X2 refers to

XTAL_IN and XTAL_OUT in the Ethernet device, respectively. The crystal and the capacitors form a

feedback element for the internal inverting amplifier. This combination is called parallel-resonant,

because it has positive reactance at the selected frequency. In other words, the crystal behaves like an

inductor in a parallel LC circuit. Oscillators with piezoelectric feedback elements are also known as

“Pierce” oscillators.


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 12.20.9 Load Capacitance

The formula for crystal load capacitance is as follows:

where C1 = C2 = 22 pF (as suggested in most Intel reference designs), and Cstray = allowance for

additional capacitance in pads, traces and the chip carrier within the Ethernet device package and

C_damp.

#### 12.20.10 Shunt Capacitance

The shunt capacitance parameter is relatively unimportant compared to load capacitance. Shunt

capacitance represents the effect of the crystal’s mechanical holder and contacts. The shunt

capacitance should be a maximum of 6 pF.

Figure 12-20 Thermal Oscillator Circuit


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
#### 12.20.11 Equivalent Series Resistance

Equivalent Series Resistance (ESR) is the real component of the crystal’s impedance at the calibration

frequency, which the inverting amplifier’s loop gain must overcome. ESR varies inversely with frequency

for a given crystal family. The lower the ESR, the faster the crystal starts up. Crystals with an ESR value

of 50  or better should be used.

#### 12.20.12 Drive Level.....................................................................................................

Drive level refers to power dissipation in use. The allowable drive level for a Surface Mounted

Technology (SMT) crystal is less than its through-hole counterpart. This is due to the fact that surface

mount crystals are typically made from narrow, rectangular AT strips, rather than circular AT quartz

blanks.

When selecting a crystal, board designers must ensure that the crystal specification meets at least the

drive level specified. For example, if the crystal drive level specification states that the drive level is 200

W maximum, then the crystal drive level must be at least 200 W. So, a 500 W crystal is sufficient,

but a 100 W crystal is not.

#### 12.20.13 Aging

Aging is a permanent change in frequency (and resistance) occurring over time. This parameter is most

important in its first year because new crystals age faster than old crystals. Crystals with a maximum

value of ±5 ppm per year aging should be used.

#### 12.20.14 Reference Crystal............................................................................................

The normal tolerances of the discrete crystal components can contribute to small frequency offsets with

respect to the target center frequency. To minimize the risk of tolerance-caused frequency offsets

causing a small percentage of production line units to be outside of the acceptable frequency range, it is

important to account for those shifts while empirically determining the proper values for the discrete

loading capacitors, C1 and C2.

Even with a perfect support circuit, most crystals will oscillate slightly higher or lower than the exact

center of the target frequency. Therefore, frequency measurements, which determine the correct value

for C1 and C2, should be performed with an ideal reference crystal. When the capacitive load is exactly

equal to the crystal’s load rating, an ideal reference crystal will be perfectly centered at the desired

target frequency.


Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

12.20.14.1 Reference Crystal Selection

There are several methods available for choosing the appropriate reference crystal:

- If a Saunders and Associates (S&A) crystal network analyzer is available, then discrete crystal
    components can be tested until one is found with zero or nearly zero ppm deviation (with the
    appropriate capacitive load). A crystal with zero or near zero ppm deviation will be a good reference
    crystal to use in subsequent frequency tests to determine the best values for C1 and C2.
- If a crystal analyzer is not available, then the selection of a reference crystal can be done by
    measuring a statistically valid sample population of crystals, which has units from multiple lots and
    approved vendors. The crystal, which has an oscillation frequency closest to the center of the
    distribution, should be the reference crystal used during testing to determine the best values for C1
    and C2.
- It may also be possible to ask the approved crystal vendors or manufacturers to provide a reference
    crystal with zero or nearly zero deviation from the specified frequency when it has the specified
    CLoad capacitance.

When choosing a crystal, customers must keep in mind that to comply with IEEE specifications for

10/100 Mb/s operation and 10/100/1000 Mb/s operation if applicable, the transmitter reference

frequency must be precise within ±50 ppm. Intel recommends customers use a transmitter reference

frequency that is accurate to within ±30 ppm to account for variations in crystal accuracy due to crystal

manufacturing tolerance.

12.20.14.2 Circuit Board

Since the dielectric layers of the circuit board are allowed some reasonable variation in thickness, the

stray capacitance from the printed board (to the crystal circuit) will also vary. If the thickness tolerance

for the outer layers of dielectric are controlled within ±15% of nominal, then the circuit board should

not cause more than ±2 pF variation to the stray capacitance at the crystal. When tuning crystal

frequency, it is recommended that at least three circuit boards are tested for frequency. These boards

should be from different production lots of bare circuit boards.

Alternatively, a larger sample population of circuit boards can be used. A larger population will increase

the probability of obtaining the full range of possible variations in dielectric thickness and the full range

of variation in stray capacitance.

Next, the exact same crystal and discrete load capacitors (C1 and C2) must be soldered onto each

board, and the LAN reference frequency should be measured on each circuit board.

The circuit board, which has a LAN reference frequency closest to the center of the frequency

distribution, should be used while performing the frequency measurements to select the appropriate

value for C1 and C2.

12.20.14.3 Temperature Changes

Temperature changes can cause the crystal frequency to shift. Therefore, frequency measurements

should be done in the final system chassis across the system’s rated operating temperature range.


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
#### 12.20.15 Oscillator Support

The PHY clock input circuit is optimized for use with an external crystal. However, an oscillator can also

be used in place of the crystal with the proper design considerations (refer to the PHY Datasheet for

detailed clock oscillator specifications):

- The clock oscillator has an internal voltage regulator to isolate it from the external noise of other
    circuits to minimize jitter. If an external clock is used, this imposes a maximum input clock
    amplitude. For example, if a 3.3 V DC oscillator is used, its output signal should be attenuated to a
    maximum value with a resistive divider circuit.
- The input capacitance introduced by the PHY (approximately 11 to 13 pF) is greater than the
    capacitance specified by a typical oscillator (approximately 15 pF).
- The input clock jitter from the oscillator can impact the PHY clock and its performance.

Note: The power consumption of additional circuitry equals about 1.5 mW.

Table 12-13 lists oscillators that can be used with the PHY. Note that no particular oscillator is

recommended.

#### 12.20.16 Oscillator Placement and Layout Recommendations

Oscillator clock sources should not be placed near I/O ports or board edges. Radiation from these

devices can be coupled into the I/O ports and radiate beyond the system chassis. Oscillators should also

be kept away from the Ethernet magnetics module to prevent interference.

The oscillator must have it's own decoupling capacitors and they must be placed within 0.25 inches. If a

power trace is used (not power plane), the trace from the capacitor to the oscillator must not exceed

0.25 inches in length. The decoupling capacitors help to improve the oscillator stability. The oscillator

clock trace should be less than two inches from the PHY. If it is greater than 2 inches, then verify the

signal quality, jitter, and clock frequency measurements at the PHY.

The clock lines should also target 5  ±15% and should have 10  series back termination placed close

to the series oscillator. To help reduce EMI, the clock lines must be a distance of at least five times the

height of the thinnest adjacent dielectric layer away from other digital traces (especially reset signals),

I/O ports, the board edge, transformers and differential pairs.

The clock lines must not cross any plane cuts on adjacent power or ground reference layers unless

there are decoupling capacitors or connecting vias near the transition. The clock lines should not cross

or run in parallel with any trace (100 MHz signal or higher) on an adjacent layer.

Table 12-13 Oscillator Manufacturers and Part Numbers

```
Manufacturer Part Number Notes
```
```
TXC Corporation - USA 8W25080004 2.5 x 2.0 x 0.8mm.
```
```
TXC Corporation - USA 7X25080001 3.2 x 2.5 x 1.0 mm.
```

Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

There should be a ferrite bead within 250 mils of the oscillator power pin and there must be a 1 F or

greater capacitor within 250 mils of the oscillator, connected to the power trace between the oscillator

input and ferrite bead. With a ferrite bead on the power trace for the oscillator, there should be a power

pour (or fat trace) to supply power to the oscillator.

Note: For the latest PHY schematic connection recommendations, refer to the Intel

##### ®

```
Ethernet
Connection I219 Reference Schematic and the Intel
```
##### ®

```
Ethernet Connection I219 Schematic
and Layout Checklist, available through your Intel representative.
```
### 12.21 LAN Switch

Table 12-14 lists LAN switches that can be used with the I219. Note that no particular LAN switch is

recommended.

### 12.22 Troubleshooting Common Physical Layout Issues

The following lists common physical layer design and layout mistakes in LAN on Motherboard (LOM)

designs.

1. Lack of symmetry between the two traces within a differential pair. Asymmetry can create common-
    mode noise and distort the waveforms. For each component and via that one trace encounters, the
    other trace should encounter the same component or a via at the same distance from the Ethernet
    silicon.
2. Unequal length of the two traces within a differential pair. Inequalities create common-mode noise
    and will distort the transmit or receive waveforms.
3. Excessive distance between the Ethernet silicon and the magnetics. Long traces on FR4 fiberglass
    epoxy substrate will attenuate the analog signals. In addition, any impedance mismatch in the
    traces will be aggravated if they are longer than the four-inch guideline.
4. Routing any other trace parallel to and close to one of the differential traces. Crosstalk getting onto
    the receive channel will cause degraded long cable BER. Crosstalk getting onto the transmit channel
    can cause excessive EMI emissions and can cause poor transmit BER on long cables. At a minimum,
    for stripline other signals should be kept at least 6x the height of the thinnest adjacent dielectric
    layer. For microsrip it is 7x. The only possible exceptions are in the vicinities where the traces enter
    or exit the magnetics, the RJ-45 connector, and the Ethernet silicon.
5. Using a low-quality magnetics module.

Table 12-14 LAN Switch Manufacturers and Part Numbers

```
Manufacturer Part Number Notes
```
```
Pericom* PI3L720 7.0 x 3.5 x 0.75 mm. Enhanced ESD.
```
```
Pericom PI3L500-AZ 11.0 x 5.0 x 0.75 mm. Enhanced ESD.
```
```
Texas Instruments* TS3L500AE 11.0 x 5.0 x 0.75 mm. Enhanced ESD.
```

```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
6. Reusing an out-of-date physical layer schematic in a Ethernet silicon design. The terminations and
    decoupling can be different from one PHY to another.
7. Incorrect differential trace impedances. It is important to have about a 100-impedance between
    the two traces within a differential pair. This becomes even more important as the differential traces
    become longer. To calculate differential impedance, many impedance calculators only multiply the
    single-ended impedance by two. This does not take into account edge-to-edge capacitive coupling
    between the two traces. When the two traces within a differential pair are kept close to each other,
    the edge coupling can lower the effective differential impedance by 5  to 20 . Short traces will
    have fewer problems if the differential impedance is slightly off target.

### 12.23 Power Delivery

The I219 requires a 3.3 V power rail and a 0.93 V (Core) power rail. The internal 3.3 V power rail is

brought out for decoupling. Figure 2-2 shows a typical power delivery configuration that can be

implemented. However, power delivery can be customized based on a specific OEM. In general planes

should be used to deliver 3.3 Vdc and the Core voltage. Not using planes can cause resistive voltage

drop and/or inductive voltage drop (due to transient or static currents). Some of the symptoms of these

voltage drops can include higher EMI, radiated immunity, radiated emissions, IEEE conformance issues,

and register corruption.

Decoupling capacitors (0.1 F and smaller) should be placed within 250 mils of the LAN device. They

also should be distributed around the PHY and some should be in close proximity to the power pins.

The bulk capacitors (1.0 F or greater) should be placed within 1 inch if using a trace (50 mils wide or

wider) or within 1.5 inches if using a plane.

The Core power rail for the I219 uses the integrated SVR (iSVR). When laying out the circuit the

inductor must be placed within 0.5" of the input pin to the PHY and connected with a trace wider than or

equal to 20 mil wide.

See the reference schematic for further details regarding the Core power rail.

While Intel does not endorse vendors or specific components, design compatibility has been verified for

the connectors in Table 12-15.

Note: For latest PHY schematic connection recommendations, refer to the Intel

##### ®

```
I219 GbE PHY
Reference Schematic or contact your Intel Field Service Representative.
```
Table 12-15 Inductors and Manufacturers

```
Manufacturer Part Number Notes
```
```
Taiyo Yuden* NRS2012T-4R7MGJ 2.0 x 2.0 x 1.2 mm
```
```
TDK* VLS2012ET-4R7M 2.0 x 2.0 x 1.2 mm
```
```
muRata* LQH32PN4R7NN0 3.2 x 2.5 x 1.55 mm
```
```
muRata LQH32CN4R7M53 3.2 x 2.5 x 1.55 mm
```

Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 12.24 I219 Power Sequencing

The Intel

##### ®

Ethernet Controller I219 does not require any power sequencing between the 3.3 V and Core

power rails. See the reference schematic for details.


```
Intel® Ethernet Connection I219—Mobile Design Considerations and Guidelines
```
NOTE: This page intentionally left blank.


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

## 13.0 Non-Mobile Design Considerations and Guidelines ................................................

The PCH incorporates an integrated 10/100/1000 Mb/s MAC controller that can be used with an

external Intel

##### ®

Ethernet Connection I219 (PHY) shown in Figure 13-1. Its bus master capabilities

enable the component to process high-level commands and perform multiple operations, which lowers

processor use by offloading communication tasks from the processor.

The PCH, which hereinafter refers to the integrated MAC within the PCH, supports the SMBus interface

for manageability while in an Sx state and PCI Express* (PCIe*) for 10/100/1000 Mb/s traffic in an S0

state.

Note: The PCIe interface is not PCIe-compliant. It operates at half of the PCI Express* (PCIe*)

```
Specification v1.0 (2.5 GT/s) speed. In this section, the term “PCIe-based” is
interchangeable with “PCIe.” There are no design layout differences between normal PCIe
and the PCIe-based interface.
```
The PHY interfaces with the integrated MAC through two interfaces: PCIe and SMBus. In SMBus mode,

the link speed is reduced to 10 Mb/s. The PCIe interface incorporates two aspects: a PCIe-based SerDes

(electrically) and a custom logic protocol for messaging between the integrated MAC and the PHY.

Note: Gigabit Ethernet requires an SPI Flash to host firmware and does not work without an SPI

Flash on board.

The integrated MAC supports multi-speed operation (10/100/1000 Mb/s). The integrated MAC also

operates in full-duplex at all supported speeds or half-duplex at 10/100 Mb/s as well as adhering to the

IEEE 802.3x Flow Control Specification.

Note: References to the AUX power rail means the power rail is available in all power states

```
including G3 to S5 transitions and Sx states with Wake on LAN (WoL) enabled. For
example, V3P3_AUX in this section refers to a rail that is powered under the conditions
previously mentioned.
```
Figure 13-1 PCH/PHY Interface Connections


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
### 13.1 PHY Overview

The PHY is a single port compact component designed for 10/100/1000 Mb/s operation. It enables a

single port Gigabit Ethernet (GbE) implementation in a very small area, easing routing constraints from

the PCH chipset to the PHY.

The PHY provides a standard IEEE 802.3 Ethernet interface for 1000BASE-T, 100BASETX, and

10BASE-T applications (802.3ab, 802.3u, and 802.3i, respectively).

#### 13.1.1 PHY Interconnects...........................................................................................

The main interfaces for either PHY are PCIe and SMBus on the host side and Media Dependent Interface

(MDI) on the link side. Transmit traffic is received from the PCH as either PCIe or SMBus packets on the

host interconnect and transmitted as Ethernet packets on the MDI link. Receive traffic arrives as

Ethernet packets on the MDI link and transferred to the PCH through either the PCIe or SMBus

interconnects.

The PHY switches the in-band traffic automatically between PCIe and SMBus based on platform reset.

The transition protocol is done through SMBus. The PCIe interface is powered down when the Ethernet

link is running in an Sx state.

Table 13-1 SMBus Data Signals on the PCH

```
Group PHY Signal Name PCH Signal Name Description
```
```
Data SMB_DATA SMLINK0_DATA SMBus data
```
Table 13-2 PCIe Data Signals on the PCH

```
Group PHY Signal Name PCH Signal Name Description
```
```
Data
PETp
PETn
```
```
PETp
PETn
PCIe transmit pair
```
```
Data
PERp
PERn
```
```
PERp
PERn
PCIe receive pair
```
```
Note: The appropriate NVM descriptor soft strap (PCHSTRP9) should define which PCIe port is configured as GbE LAN. Refer to
the PCH EDS document for the specific ports that can be used for GbE LAN.
```
Table 13-3 PCIe Data Signals on the PCH

```
Group PHY Signal Name PCH Signal Name Description
```
```
Clock SMB_CLK SML0_CLK SMBus clock.
```
```
Clock
```
##### PE_CLKP

##### PE_CLKN

##### CLKOUT_PCIE[7:0]_P^1

##### CLKOUT_PCIE[7:0]_N^1

1. These signals come from the PCH and drive the PHY.

```
PCIe clock.
```
```
Clock CLK_REQ_N PCIECLKRQ[7:0]# PCIe clock request.
```
```
Reset PE_RST_N PLTRST# PCIe reset.
```

Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 13.1.2 PCIe-Based Interface.......................................................................................

A high-speed SerDes interface uses PCIe electrical signaling at half speed while utilizing a custom

logical protocol for active state operation mode.

Note: PCIe validation tools cannot be used for electrical validation of this interface. However, PCIe

layout rules apply for on-board routing.

13.1.2.1 PCIe Interface Signals

The signals used to connect between the PCH and the PHY in this mode are:

- Serial differential pair running at 1.25 Gb/s for Rx.
- Serial differential pair running at 1.25 Gb/s for Tx.
- 100-MHz differential clock input to the PHY is generated by the PCH.
- Power and clock good indication to the PHY PE_RST_N.
- Clock control through CLK_REQ_N (see Table 13-3). This PHY output should be tied to the PCH
    input and pulled up with a 10 K resistor connected to 3.3 V DC AUX power (present in G3 to S5).

13.1.2.2 PCIe Operation and Channel Behavior

The PHY runs only at 1250 Mb/s speed; 1/2 the Gen 1, 2.5 Gb/s PCIe frequency. Each PCIe root port in

the PCH has the ability to run at 1250 Mb/s. The configuration for a PCH PCIe port attached to a PCIe

Intel PHY device is pre-loaded from the GbE region of the NVM. The selected port adjusts the

transmitter to run at 1/2 the Gen 1 PCIe speed and does not need to be PCIe compliant.

Packets transmitted and received over the PCIe interface are full Ethernet packets and not PCIe

transaction/link/physical layer packets.

13.1.2.3 PCIe Connectivity

The PHY transmit/receive pins are output/input signals and are connected to the PCH as listed in

Table 13-1 through Table 13-3.

13.1.2.4 PCIe Reference Clock

The PCIe Interface uses a 100-MHz differential reference clock, denoted PE_CLKP and PE_CLKN. This

signal is typically generated on the platform and routed to the PCIe port.

The frequency tolerance for the PCIe reference clock is ±300 ppm.


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
#### 13.1.3 SMBus Interface

SMBus is a low speed (100/400/1000 KHz) serial bus used to connect various components in a system.

SMBus is used as an interface to pass traffic between the PHY and the PCH when the platform is in a low

power state (Sx). The interface is also used to enable the PCH to configure the PHY as well as pass

in-band information between them.

The SMBus uses two primary signals to communicate: SMBCLK and SMBDATA. Both of these signals

float high with board-level 499  ±5% pull-up resistors.

13.1.3.1 SMBus Connectivity

Table 13-1 through Table 13-3 list the relationship between PHY SMBus pins to the PCH LAN SMBus

pins.

Note: The SMBus signals (SMB_DATA and SMB_CLK) cannot be connected to any other devices

```
other than the integrated MAC. Connect the SMB_DATA and SMB_CLK pins to the
integrated MAC SML0DATA and SML0CLK pins, respectively.
```
#### 13.1.4 PCIe and SMBus Modes....................................................................................

In GbE operation, PCIe is used to transmit and receive data and for MDIO status and control. The PHY

automatically switches the in-band traffic between PCIe and SMBus based on the platform power state.

Table 13-4 lists the operating modes of PCIe and SMBus.

The I219 GbE PHY automatically switches the in-band traffic between PCIe and SMBus based on the

system power state.

Table 13-4 PCIE and SMBus Operating Modes

```
System/Intel Management Engine State
```
##### PHY

```
SMBus PCIe
```
```
S0 and PHY Power Down Not used Electrical Idle (EI)
```
```
S0 and Idle or Link Disconnect Not used EI
```
```
S0 and Link in Low Power Idle (LPI) Not used EI
```
```
S0 and active Not used Active
```
```
Sx Active Power down
```
```
Sx and DMoff Active Power down
```

Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 13.1.5 Transitions Between PCIe and SMBus Interfaces..................................................

13.1.5.1 Switching from SMBus to PCIe

Communication between the integrated MAC and the PHY is done through the SMBus each time the

system is in a low power state (Sx). The integrated MAC/PHY interface is needed while the

Manageability Engine (ME) is still active to transfer traffic, configuration, control and status or to enable

host wake up from the PHY.

Possible states for activity over the SMBus:

1. After power on (G3 to S5).
2. On system standby (Sx).

The switching from the SMBus to PCIe is done when the PE_RST_N signal goes high.

- Any transmit/receive packet that is not completed when PE_RST_N is asserted is discarded.
- Any in-band message that was sent over the SMBus and was not acknowledged is re-transmitted
    over PCIe.

13.1.5.2 Switching from PCIe to SMBus

The communication between the integrated MAC and the PHY is done through PCIe each time the

platform is in active power state (S0). Switching the communication to SMBus is only needed for ME

activity or to enable host wake up in low power states and is controlled by the ME.

The switching from PCIe to SMBus is done when the PE_RST_N signal goes low.

- Any transmit/receive packet that is not completed when PE_RST_N goes to 0b is discarded.
- Any in-band message that was sent over PCIe and was not acknowledged is re-transmitted over
    SMBus.


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
### 13.2 Platform LAN Design Guidelines

These sections provide recommendations for selecting components and connecting special pins. For

GbE designs, the main elements are:

- The PCH chipset.
- The I219 GbE PHY.
- A magnetics module and RJ-45 connector
- A GbE region NVM (Non Volatile Memory) image
- A clock source.

Note: The suggested parts recommended in this section (magnetics, crystals, oscillators, etc.) are

```
either in evaluation or have been used successfully in previous designs with good results.
Intel recommends that all selected parts must be validated on each production design.
```
#### 13.2.1 General Design Considerations for PHYs

Sound engineering practices must be followed with respect to unused inputs by terminating them with

pull-up or pull-down resistors, unless otherwise specified in a datasheet, design guide or reference

schematic. Pull-up or pull-down resistors must not be attached to any balls identified as “No Connect.”

These devices might have special test modes that could be entered unintentionally.

13.2.1.1 Clock Source

All designs require a 25-MHz clock source. The PHY uses the 25-MHz source to generate clocks up to

125 MHz and 1.25 GHz for both the PHY circuits and the PCIe interface. For optimum results with lowest

cost, a 25-MHz parallel resonant crystal can be used along with the appropriate load capacitors at the

XTAL_OUT (X2) and XTAL_IN (X1) leads. The frequency tolerance of the timing device should equal

30 ppm or better. Further detail is found in Section 13.20 and Section 13.21.15.

Note: XTAL_OUT and XTAL_IN are the signal names for the PHY.

There are three steps to crystal qualification:

1. Verify that the vendor’s published specifications in the component datasheet meet the required
    conditions for frequency, frequency tolerance, temperature, oscillation mode and load capacitance
    as specified in the respective datasheet.
2. Perform physical layer conformance testing and EMC (FCC and EN) testing in real systems.
3. Independently measure the component’s electrical parameters in real systems. Measure frequency
    at a test output to avoid test probe loading effects at the PHY. Check that the measured behavior is
    consistent from sample to sample and that measurements meet the published specifications. For
    crystals, it is also important to examine startup behavior while varying system voltage and
    temperature.


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

13.2.1.2 Magnetics Module

The magnetics module has a critical effect on overall IEEE and emissions conformance. The device

should meet the performance required for a design with reasonable margin to allow for manufacturing

variation. Carefully qualifying new magnetics modules prevents problems that might arise because of

interactions with other components or the printed circuit board itself.

The steps involved in magnetics module qualification are similar to those for crystal qualification:

1. Verify that the vendor’s published specifications in the component datasheet meet or exceed the
    required IEEE specifications.
2. Independently measure the component’s electrical parameters on the test bench, checking samples
    from multiple lots. Check that the measured behavior is consistent from sample to sample and that
    measurements meet the published specifications.
3. Perform physical layer conformance testing and EMC (FCC and EN) testing in real systems. Vary
    temperature and voltage while performing system-level tests.

Magnetics modules for 1000BASE-T Ethernet as used by the PHY only are similar to those designed

solely for 10/100 Mb/s, except that there are four differential signal pairs instead of two. Refer to the

specifications section of this datasheet for specific electrical requirements that the magnetics need to

meet.

While Intel does not endorse vendors or specific components, design compatibility has been verified for

the connectors in Table 13-5.

Table 13-5 Integrated Magnetic Modules and Manufacturers (RJ45/USB)

```
Manufacturer Part Number Notes
```
```
Foxconn* JFM38U1M-7319-4F USB2.0+USB3.0 stack, 8 core
```
```
Foxconn JFM38U1A-21C7-4F USB2.0 stack, 8 core
```
```
Foxconn JFM38U1A-7126-4F USB2.0 stack, 8 core
```
```
SpeedTech* P25BFB4-RDW9 USB2.0 stack, 8core
```
```
SpeedTech P35-PB4-RDW9 USB2.0 stack, 12core
```
Table 13-6 Discrete Magnetics Modules: Manufacturers and Part Numbers

```
Manufacturer Part Number Notes
```
```
Pulse* H5120 16.51 x 9.65 x 2.08 mm, 8 core
```
```
Bothhand* GST5009LF 15.10 x 10 x 4 mm, 8 core
```
```
Delta* LFE9249-R-IN 15.10 x 10 x 4 mm, 8 core
```

```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
13.2.1.3 Criteria for Integrated Magnetics Electrical

Qualification

Table 13-8 gives the criteria used to qualify integrated magnetics.

Table 13-7 Discrete RJ45

```
Manufacturer Part Number Notes
```
```
Lotes* AJKM0007-P001A01 Thinnest solution, 5.2 mm height
```
```
Foxconn JM3611-NS420013-7H Low profile, 10 mm height
```
```
Pulse E6688-001-01-L Low profile, 10 mm height
```
Table 13-8 Integrated Magnetics Recommended Qualification Criteria

```
Open Circuit
Inductance (OCL)
```
```
w/8 mA DC bias; at 25 °C 400 H Min
```
```
w/8 mA DC bias; at 0 °C to 70 °C 350 H Min
```
```
Insertion Loss
```
```
100 KHz through 999 KHz
1.0 MHz through 60.0 MHz
60.1 MHz through 80.0 MHz
80.1 MHz through 100.0 MHz
100.1 MHz through 125.0 MHz
```
```
1dB Max
0.6dB Max
0.8dB Max
1.0dB Max
2.4dB Max
```
```
Return Loss
```
```
1.0 MHz through 40.0 MHz
40.1 MHz through 100.0 MHz
When reference impedance is 85 Ohms,
100 Ohms, and 115 Ohms. Note that
R.L. values may vary with MDI trace
lengths. The LAN magnetics may need
to be measured in the platform where it
will be used.
```
```
18.0 dB Min
12 – 20 * LOG (Freq in MHz / 80) dB Min
```
```
Crosstalk Isolation
Discrete Modules
```
```
1.0 MHz through 29.9 MHz
30.0 MHz through 250.0 MHz
250.1 MHz through 375.0 MHz
```
```
-50.3+(8.8*(Freq in MHz / 30)) dB Max
-(26 -(16.8*(LOG(Freq in MHz / 250 MHz)))) dB Max
-26.0 dB Max
```
```
Crosstalk Isolation
Integrated Modules
(Proposed)
```
```
1.0 MHz through 10 MHz
10.0 MHz through 100.0 MHz
100 MHz through 375.0 MHz
```
```
-50.8+(8.8*(Freq in MHz / 10)) dB Max
-(26 -(16.8*(LOG(Freq in MHz / 100 MHz)))) dB Max
-26.0 dB Max
```
```
Diff to CMR
```
```
1 MHz through 29.9 MHz
30.0 MHz through 500 MHz
```
```
-40.2+(5.3*((Freq in MHz / 30)) dB Max
-(22-(14*(LOG((Freq in MHz / 250)))) dB Max
```
```
CM to CMR
```
```
1 MHz through 270 MHz
270.1 MHz through 300 MHz
300.1 MHz through 500 MHz
```
```
-57+(38*((Freq in MHz / 270)) dB Max
-17-2*((300-(Freq in MHz) / 30) dB Max
-17 dB Max
```
```
Hi-Voltage Isolation
```
```
1500 Vrms at 50 or 60 Hz for 60 sec.
or: 2250 Vdc for 60 seconds
```
```
Minimum
```

Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 13.2.2 NVM for PHY Implementations

The LAN only supports an SPI Flash, which is connected to the PCH. Several words of the NVM are

accessed automatically by the device after reset to provide pre-boot configuration data before it is

accessed by host software. The remainder of the NVM space is available to software for storing the MAC

address, serial numbers, and additional information.

Intel has an MS-DOS* software utility called EEupdate that is used to program the SPI Flash images in

development or production line environments. A copy of this program can be obtained through your

Intel representative.

### 13.3 LAN Switch

To achieve IEEE conformance for applications that must operate both docked and undocked, a LAN

switch is recommended. Note that Intel does not recommend specific switches, but those in Table 13-8

have been used successfully in previous designs.

Table 13-9 LAN Switch Manufacturers and Part Numbers

```
Manufacturer Part Number Notes
```
```
Pericom* PI3L720 7.0 x 3.5 x 0.75 mm. Enhanced ESD.
```
```
Pericom PI3L500-AZ 11.0 x 5.0 x 0.75 mm. Enhanced ESD.
```
```
Texas Instruments* TS3L500AE 11.0 x 5.0 x 0.75 mm. Enhanced ESD.
```

```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
#### 13.3.1 LED...............................................................................................................

The PHY has three LED outputs that can be configured via the NVM. The hardware configuration is

shown in Figure 13-2.

Note: Intel recommends that the LED pins only be used to drive LEDs. These pins tri-state in ULP

mode and might not drive valid logic levels.

Refer to the Intel

##### ®

Ethernet Connection I219 Reference Schematic for default LED color based on

reference design.

Refer to Section 9.0 of this datasheet for details regarding the programming of the LED’s and the

various modes. The default values for the PHY (based on the LED NVM setting--word 0x18 of the LAN

region) are listed in the Table 13-10.

13.3.1.1 RBIAS

RBIAS requires external resistor connection to bias the internal analog section of the device. The input

is sensitive to the resistor value. Resistors of 1% tolerance must be used. Connect RBIAS through a

3.01 K 1% pull-down resistor to ground, then place it no more than one half inch (0.5”) away from the

PHY.

Figure 13-2 LED Hardware Configuration

Table 13-10 LED Default Values

```
LED Mode Color Blink Polarity
```
```
LED0 Link Up/Activity Green 200 ms on/200 ms off Active low
```
```
LED1 Link 1000 Yellow No Active low
```
```
LED2 Link 100 Green No Active low
```

Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

13.3.1.2 LAN Disable

The PHY enters a power-down state when the LAN_DISABLE_N pin is asserted low. Exiting this mode

requires setting the LAN_DISABLE_N pin to a logic one. Connect LAN_DISABLE_N to

LAN_PHY_PWR_CTRL GPIO12 on the PCHCougar Point-M.

#### 13.3.2 Exposed Pad* (e-Pad) Design and SMT Assembly Guide

13.3.2.1 Overview

This section provides general information about ePAD and SMT assemblies. Chip packages have

exposed die pads on the bottom of each package to provide electrical interconnections with the printed

circuit board. These ePADs also provide excellent thermal performance through efficient heat paths to

the PCB.

Packages with ePADs are very popular due to their low cost. Note that this section provides only basic

information and references in regards to the ePAD. It is recommended that each customer consult their

fab and assembly house to obtain more details on how to implement the ePAD package design. Each

fab and assembly house might need to tune the land pattern/stencil and create a solution that best

suits their methodology and process.


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
13.3.2.2 PCB Design Requirements

To maximize both heat removal and electrical performance, a land pattern must be incorporated on the

PCB within the footprint of the package corresponding to the exposed metal pad or exposed heat slug of

the package as shown in the following figures. Refer to the specific product datasheet for actual

dimensions.

Note: Due to the package size, a via-in-pad configuration must be used. Figure 13-3 and

```
Figure 13-4 are general guidelines. See Figure 13-5 for specific via-in-pad thermal pattern
recommendations.
```
Note: Encroached and uncapped via configurations have voids less than the maximum allowable

```
void percentage. Uncapped via provides a path for trapped air to escape during the reflow
soldering process.
```
Figure 13-3 Typical ePAD Land Pattern

Figure 13-4 Typical Thermal Pad and Via Recommendations


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

Note: Secondary side solder bumps might be seen in an uncapped via design. This needs to be

considered when placing components on the opposite side of the PHY.

13.3.2.3 Board Mounting Guidelines

The following are general recommendations for mounting a QFN-48 device on the PCB. This should

serve as the starting point in assembly process development and it is recommended that the process

should be developed based on past experience in mounting standard, non-thermally/electrically

enhanced packages.

13.3.2.4 Stencil Design

For maximum thermal/electrical performance, it is required that the exposed pad/slug on the package

be soldered to the land pattern on the PCB. This can be achieved by applying solder paste on both the

pattern for lead attachment as well as on the land pattern for the exposed pad. While for standard

(non-thermally/non-electrically enhanced) lead-frame based packages the stencil thickness depends on

the lead pitch and package co-planarity, the package standoff must also be considered for the

thermally/electrically enhanced packages to determine the stencil thickness. In this case, a stencil foil

thickness in the range of 5-6 mils (or 0.127—0.152 mm) is recommended; likely or practically, a choice

of either 5 mils or 6 mils. Tolerance-wise, it should not be worse than ±0.5 mil.

Note: Industry specialists typically use ±0.1 mil tolerance on stencil for its feasible precision.

The aperture openings should be the same as the solder mask openings on the land pattern. Since a

large stencil opening may result in poor release, the aperture opening should be subdivided into an

array of smaller openings, similar to the thermal land pattern shown in Figure 13-6.

Note: Refer to the specific product datasheet for actual dimensions.

Figure 13-5 Recommended Thermal Via Patterns


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
Important General Guidelines:

- The Stencil Aperture Openings of the e-PAD must not go outside of the exposed landing area
    (solder mask opening).
- The Stencil Aperture Openings of the e-PAD should be about 80% of the exposed landing area
    (solder mask opening).

The I219 e-PAD has D2=E2=3 mm. Therefore, the Stencil Design can only have four aperture openings

for the e-PAD. This can be achieved by setting R=S=1.35 mm and T=0.3. Using this arrangement, the

Aperture’s/e-PAD area is 81% of the exposed landing area (solder mask opening).

Note: This information is intended only as general guidance. Consult with the manufacturer to

confirm the final design meets requirements.

13.3.2.5 Assembly Process Flow

Figure 13-7 below shows the typical process flow for mounting packages to the PCB.

Figure 13-6 Stencil Design Recommendation

Figure 13-7 Assembly Flow


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

13.3.2.6 Reflow Guidelines

The typical reflow profile consists of four sections. In the preheat section, the PCB assembly should be

preheated at the rate of 1 to 2 °C/sec to start the solvent evaporation and to avoid thermal shock. The

assembly should then be thermally soaked for 60 to 120 seconds to remove solder paste volatiles and

for activation of flux. The reflow section of the profile, the time above liquidus should be between 45 to

60 seconds with a peak temperature in the range of 245 to 250 °C, and the duration at the peak should

not exceed 30 seconds. Finally, the assembly should undergo cool down in the fourth section of the

profile. A typical profile band is provided in Figure 13-8, in which 220 °C is referred to as an

approximation of the liquidus point. The actual profile parameters depend upon the solder paste used

and specific recommendations from the solder paste manufacturers should be followed.

Note: Contact your Intel Field Service Representative for any designs unable to meet the

recommended guidance for E-pad implementation.

```
Notes:
```
1. Preheat: 125 °C -220 °C, 150 - 210 s at 0.4 k/s to 1.0 k/s
2. Time at T > 220 °C: 60 - 90 s
3. Peak Temperature: 245-250 °C
4. Peak time: 10 - 30 s
5. Cooling rate: <= 6 k/s
6. Time from 25 °C to Peak: 240 – 360 s
7. Intel recommends a maximum solder void of 50% after reflow.

Figure 13-8 Typical Profile Band


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
### 13.4 PCH-SMBus/PCIe LOM Design Guidelines

This section contains guidelines on how to implement a PCH/PHY single solution on a system

motherboard. It should not be treated as a specification, and the system designer must ensure through

simulations or other techniques that the system meets the specified timings. The following are

guidelines for both PCH SMBus and PCIe interfaces. Note that PCIe is only applicable to the PHY.

The SMBus/PCIe Interface between the PCH and PHY is shown at high level in Figure 13-9. For

complete design details, always refer to the Intel

##### ®

Ethernet Connection I219 Reference Schematic.

Refer to Section 13.7 for PCI Express Routing Guidelines.

Note: Board designers MUST select the available PCIe lane based on a specific platform PCH

```
External Design Specification (EDS). Not all PCIe lanes on a PCH are available to connect
the I219 GbE PHY to the PCIe interface. For example, The SKL U/Y PCH EDS requires the
I219 to only connect to PCIe ports 3, 4, 5, 9, and 10. Contact your local Intel
representative for more details.
```
```
Notes:
```
1. Not all PCH PCIe ports can be used for the I219. Refer to the SkyLake/Greenlow/Purley EDS documentation for the
    specific ports that can be used with the I219.
2. Any CLKOUT_PCIE and PCIECLKRQ ports can be used to connect to the I219. These can be selected using the FITC
    tool.
3. PETp/n, PERp/n, PE_CLKp/n should be routed as a differential pair as indicated in the PCIe specification.
4. Refer to the I219 reference schematics and design checklists for more details.

Figure 13-9 Single Solution Interconnect


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 13.5 SMBus Design Considerations

No single SMBus design solution works for all platforms. Designers must consider the total bus

capacitance and device capabilities when designing SMBus segments. Routing SMBus to the PCI slots

makes the design process even more challenging since they add so much capacitance to the bus. This

extra capacitance has a large affect on the bus time constant which in turn affects the bus rise and fall

times.

Primary considerations in the design process are:

- Amount of VCC_SUS3_3 current available, that is, minimizing load of VCC_SUS3_3.
- The pull-up resistor size for the SMBus data and clock signals is dependent on the bus load (this
    includes all device leakage currents). Generally the SMBus device that can sink the least amount of
    current is the limiting agent on how small the resistor can be. The pull-up resistor cannot be made
    so large that the bus time constant (Resistance X Capacitance) does not meet the SMBus rise and
    time specification.
- The maximum bus capacitance that a physical segment can reach is 400 pF.
- SMBus devices that can operate in STR must be powered by the VCC_SUS3_3 supply.
- It is recommended that I

##### 2

```
C (Inter-Integrated Circuit) devices be powered by the VCC_core supply.
During an SMBus transaction in which the device is sending information to the integrated MAC, the
device may not release the SMBus if the integrated MAC receives an asynchronous reset. VCC_core is
used to enable the BIOS to reset the device if necessary. SMBus 2.0-compliant devices have a
timeout capability that makes them in-susceptible to this I
```
##### 2

```
C issue, enabling flexibility in choosing a
voltage supply.
```
- No other devices (except the integrated MAC and pull-up resistors) should be connected to the
    SMBus that connects to the PHY.
- For system LAN on motherboard (LOM) designs: The traces should be less than 70 inches for
    stripline and less than 100 inches for Microstrip. These numbers depend on the stackup, dielectric
    layer thickness, and trace width. The total capacitance on the trace and input buffers should be
    under 400 pF.
- For system LAN on daughterboard designs: Being conservative, the traces should be less than
    7 inches for stripline designs and less than 10 inches for Microstrip designs. The lengths depend on
    the stackup, dielectric layer thickness, and trace width. Longer traces can be used as long as the
    total capacitance on the trace and input buffers is under 30 pF.

Note: Refer to Section 13.1.3 for additional SMBus design considerations.

### 13.6 General Layout Guidelines

PHY interface signals must be carefully routed on the motherboard to meet the timing and signal quality

requirements of their respective interface specifications. The following are some general guidelines that

should be followed in designing a LAN solution. It is recommended that the board designer simulate the

board routing to verify that the specifications are met for flight times and skews due to trace mismatch

and crosstalk.


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
### 13.7 Layout Considerations

Critical signal traces should be kept as short as possible to decrease the likelihood of effects by high

frequency noise of other signals, including noise carried on power and ground planes. This can also

reduce capacitive loading.

Since the transmission line medium extends onto the printed circuit board, layout and routing of

differential signal pairs must be done carefully.

Designing for GbE (1000BASE-T) operation is very similar to designing for 10/100 Mb/s. For the PHY,

system level tests should be performed at all three speeds.

### 13.8 Guidelines for Component Placement

Component placement can affect signal quality, emissions, and component operating temperature.

Careful component placement can:

- Decrease potential problems directly related to electromagnetic interference (EMI), which could
    cause failure to meet applicable government test specifications. In this case, place the PHY more
    than one inch from the edge of the board.
- Simplify the task of routing traces. To some extent, component orientation affects the complexity of
    trace routing. The overall objective is to minimize turns and crossovers between traces.

#### 13.8.1 PHY Placement Recommendations

Minimizing the amount of space needed for the PHY is important because other interfaces compete for

physical space on a motherboard near the connector. The PHY circuits need to be as close as possible to

the connector.

Figure 13-10 illustrates some basic placement distance guidelines. To simplify the diagram, it shows

only two differential pairs, but the layout can be generalized for a GbE system with four analog pairs.

The ideal placement for the PHY (LAN silicon) is approximately one inch behind the magnetics module.

While it is generally a good idea to minimize lengths and distances, Figure 13-10 also illustrates the

need to keep the PHY away from the edge of the board and the magnetics module for best EMI

performance.


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

The PHY, referred to as “LAN Device” in Figure 13-10, must be at least one inch from any chassis

openings. To help reduce EMI, the following recommendations should be followed:

- Minimize the length of the MDI interface. See detail in Table 13-11 on page 261.
- Place the MDI traces no closer than 0.5 inch (1.3 cm) from the board edge.
- The Intel I219 GbE PHY must be placed greater than 1" away from any hole to the outside of the
    chassis larger than 0.125 inches (125 mils) The larger the hole the higher the probability the EMI
    and ESD immunity will be negatively affected.
- The I219 should be placed greater than 250 mils from the board edge.
- If the connector or integrated magnetics module is not shielded, the I219 GbE PHY should be placed
    at least one inch from the magnetics (if a LAN switch is not used).
- Placing the PHY closer than one inch to unshielded magnetics or connectors increases the
    probability of failed EMI and common mode noise. If the LAN switch is too far away, it negatively
    affects IEEE return loss performance.
- The RBIAS trace length must be less than one inch.
- Place the crystal less than one inch (2.54 cm) from the PHY.

```
* This distance is variable and follows the general guidelines.
```
Figure 13-10 LAN Device Placement: At Least One Inch from Chassis Openings or Unshielded

Connectors—Mobile


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
### 13.9 MDI Differential-Pair Trace Routing for LAN Design

Trace routing considerations are important to minimize the effects of crosstalk and propagation delays

on sections of the board where high-speed signals exist. Signal traces should be kept as short as

possible to decrease interference from other signals, including those propagated through power and

ground planes.

### 13.10 Signal Trace Geometry

One of the key factors in controlling trace EMI radiation are the trace length and the ratio of trace-width

to trace-height above the reference plane. To minimize trace inductance, high-speed signals and signal

layers that are close to a reference or power plane should be as short and wide as practical. Ideally, the

trace-width to trace-height above the ground plane ratio is between 1:1 and 3:1. To maintain trace

impedance, the width of the trace should be modified when changing from one board layer to another if

the two layers are not equidistant from the neighboring planes.

Each pair of signals should have a differential impedance of 100  ±15%.

A set of trace length calculation tools are available from Intel to aid with MDI topology design. For

access to documentation contact your Intel representative.

Figure 13-11 PLC Placement: At Least One Inch from I/O Backplane

Figure 13-12 Effect of LAN Device Placed Too Close to an Rj-45 Connector or Chassis

Opening


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

When performing a board layout, the automatic router feature of the CAD tool must not route the

differential pairs without intervention. In most cases, the differential pairs will require manual routing.

Note: Measuring trace impedance for layout designs targeting 100  often results in lower actual

```
impedance due to over-etching. Designers should verify actual trace impedance and adjust
the layout accordingly. If the actual impedance is consistently low, a target of 105  to
110  should compensate for over-etching.
```
It is necessary to compensate for trace-to-trace edge coupling, which can lower the differential

impedance by up to 10 , when the traces within a pair are closer than 30 mils (edge-to-edge).

Table 13-11 MDI Routing Summary

```
Parameter Main Route Guidelines
Breakout
Guidelines^1
Notes
```
```
Signal group
```
##### MDI_PLUS[0:3]

##### MDI_MINUS[0:3]

```
Microstrip/stripline uncoupled single-ended
impedance specification
```
##### 50  ±10%

```
Microstrip/stripline uncoupled differential
impedance specification
```
##### 100  ±15% 2, 3

```
Microstrip nominal trace width Design dependent Design dependent 4
```
```
Microstrip nominal trace space Design dependent Design dependent 3, 5
```
```
Microstrip/stripline trace length 8 in (203 mm) maximum 6, 7
```
```
Microstrip pair-to-pair space (edge-to-edge)
 7 times the thickness of the thinnest
adjacent dielectric layer
Figure 13-13
```
```
Stripline pair-to-pair space (edge-to-edge)
 6 times the thickness of the thinnest
adjacent dielectric layer
```
```
Microstrip bus-to-bus spacing
 7 times the thickness of the thinnest
adjacent dielectric layer
```
```
Stripline bus-to-bus spacing
 6 times the thickness of the thinnest
adjacent dielectric layer
```
```
Notes:
```
1. Pair-to-pair spacing 3 times the dielectric thickness for a maximum distance of 500 mils from the pin.
2. Board designers should ideally target 100  ±15%. If it’s not feasible (due to board stack-up) it is recommended that board
    designers use a 95  ±10% target differential impedance for MDI with the expectation that the center of the impedance is
    always targeted at 95 . The ±10% tolerance is provided to allow for board manufacturing process variations and not lower
    target impedances. The minimum value of impedance cannot be lower than 85 .
3. Simulation shows 80  differential trace impedances degrade MDI return loss measurements by approximately 1 dB from that
    of 90 .
4. Stripline is NOT recommended due to thinner more resistive signal layers.
5. Use a minimum of 21 mil (0.533 mm) pair-to-pair spacing for board designs that use the CRB design stack-up. Using
    dielectrics that are thicker than the CRB stack-up might require larger pair-to-pair spacing.
6. Mobile designs without LAN switch can range up to ~8 inches. Refer to Table 13-12 for trace length information.
7. For applications that require a longer MDI trace length of more than 8 inches (20.32 mm), it is recommended that thicker
    dielectric or lower Er materials be used. This permits higher differential trace impedance and wider, lower loss traces. Refer to
    Table 13-12 for examples of microstrip trace geometries for common circuit board materials.
8. If a LAN switch is not used, the maximum trace length is 4 inches (102 mm).


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
Note: Use the MDI Differential Trace Calculator to determine the maximum MDI trace length for

```
your trace geometry and board stack-up. Contact your Intel Field Service Representative
for access.
```
The following factors can limit the maximum MDI differential trace lengths for IEEE conformance:

- Dielectric thickness.
- Dielectric constant.
- Nominal differential trace impedance.
- Trace impedance tolerance.
- Copper trace losses.
- Additional devices, such as switches, in the MDI path may impact IEEE conformance.

Board geometry should also be factored in when setting trace length.

Table 13-12 Maximum Trace Lengths Based on Trace Geometry and Board Stack-Up

```
Dielectric
Thickness
(mils)
```
```
Dielectric
Constant (DK)
at
1 MHz
```
```
Width /
Space/ Width
(mils)
```
```
Pair-to-Pair
Space (mils)
```
```
Nominal
Impedance
(Ohms)
```
```
Impedance
Tolerance
(±%)
```
```
Maximum
Trace Length
(inches)^1
```
1. Longer MDI trace lengths may be achievable, but may make it more difficult to achieve IEEE conformance. Simulations have shown
    deviations are possible if traces are kept short. Longer traces are possible; use cost considerations and stack-up tolerance for
    differential pairs to determine length requirements.

##### 2.7 4.05 4/10/4 19 952 172 3.5

##### 2.7 4.05 4/10/4 19 952 152 4

##### 2.7 4.05 4/10/4 19 95 10 5

##### 3.3 4.1 4.2/9/4.2 23 1002

2. Deviations from 100  nominal and/or tolerances greater than 15% decrease the maximum length for IEEE conformance.

##### 172 4

##### 3.3 4.1 4.2/9/4.2 23 100 15 4.6

##### 3.3 4.1 4.2/9/4.2 23 100 10 6

##### 4 4.2 5/9/5 28 1002 172 4.5

##### 4 4.2 5/9/5 28 100 15 5.3

##### 4 4.2 5/9/5 28 100 10 7


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 13.11 Trace Length and Symmetry

The differential traces should be equal in total length to within 10 mils (0.254 mm) per segment within

each pair and as symmetrical as possible. Asymmetrical and unequal length traces in the differential

pairs contribute to common mode noise. If a choice has to be made between matching lengths and

fixing symmetry, more emphasis should be placed on fixing symmetry. Common mode noise can

degrade the receive circuit’s performance and contribute to radiated emissions.

The intra-pair length matching on the pairs must be within 10 mils on a segment by segment basis. An

MDI segment is defined as any trace within the same layer. For example, transitioning from one layer to

another through a via is considered as two separate MDI segments.

The end to end total trace lengths within each differential pair must match as shown in Figure 13-13.

The end to end trace length is defined as the total MDI length from one component to another

regardless of layer transitions.

The pair to pair length matching is not as critical as the intra-pair length matching but it should be

within 2 inches.

When using Microstrip, the MDI traces should be at least 7x the thinnest adjacent dielectric away from

the edge of an adjacent reference plane. When using stripline, the MDI traces should be at least 6x the

thinnest adjacent dielectric away from the edge of an adjacent reference plane.

Figure 13-13 MDI Trace Geometry


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
Note: Similar topology applies to MDI routing from the I219 to the dock RJ45 connector.

### 13.12 Impedance Discontinuities

Impedance discontinuities cause unwanted signal reflections. Vias (signal through holes) and other

transmission line irregularities should be minimized. If vias must be used, a reasonable budget is four

or less per differential trace. Unused pads and stub traces should also be avoided.

### 13.13 Reducing Circuit Inductance

Traces should be routed over a continuous reference plane with no interruptions. If there are vacant

areas on a reference or power plane, the signal conductors should not cross the vacant area. This

causes impedance mismatches and associated radiated noise levels.

### 13.14 Signal Isolation

Also, keep the MDI traces away from the edge of an adjacent reference plane by a distance that is at

least 7x the thickness of the thinnest adjacent dielectric layer (7x when using Microstrip; 6x when using

stripline). If digital signals on other board layers cannot be separated by a ground plane, they should be

routed perpendicular to the differential pairs. If there is another LAN controller on the board, the

differential pairs from that circuit must be kept away.

Figure 13-14 MDI Differential Trace Geometry


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

Other rules to follow for signal isolation include:

- Separate and group signals by function on separate layers if possible. If possible, maintain at least
    a gap of 30 mils between all differential pairs (Ethernet) and other nets, but group associated
    differential pairs together.
- Physically group together all components associated with one clock trace to reduce trace length and
    radiation.
- Isolate I/O signals from high-speed signals to minimize crosstalk, which can increase EMI emission
    and susceptibility to EMI from other signals.
- Avoid routing high-speed LAN traces near other high-frequency signals associated with a video
    controller, cache controller, processor, switching power supplies, or other similar devices.

### 13.15 Power and Ground Planes

Good grounding requires minimizing inductance levels in the interconnections and keeping ground

returns short, signal loop areas small, and power inputs bypassed to signal return. This will significantly

reduce EMI radiation.

The following guidelines help reduce circuit inductance in both backplanes and motherboards:

- Route traces over a continuous plane with no interruptions. Do not route over a split power or
    ground plane. If there are vacant areas on a ground or power plane, avoid routing signals over the
    vacant area. This will increase inductance and EMI radiation levels.
- All ground vias should be connected to every ground plane; and every power via, to all power
    planes at equal potential. This helps reduce circuit inductance.
- Physically locate grounds between a signal path and its return. This will minimize the loop area.
- Split the ground plane beneath a magnetics module. The RJ-45 connector side of the transformer
    module should have chassis ground beneath it.

Caution: DO NOT do this if the RJ-45 connector has integrated USB.

Note: All impedance-controlled signals should be routed in reference to a solid plane. If there are

```
plane splits on a reference layer and the signal traces cross those splits, stitching capacitors
should be used within 40 mils of where the crossing occurs. See Figure 13-15.
```
If signals transition from one reference layer to another reference layer then stitching capacitors or

connecting vias should be used based on the following:

- If the transition is from power-referenced layer to a ground-referenced layer or from one voltage-
    power referenced layer to a different voltage-power referenced layer, then stitching capacitors
    should be used within 40 mils of the transition.
- If the transition is from one ground-referenced layer to another ground-referenced layer or is from
    a power-referenced layer to the same net power-referenced layer, then connecting vias should be
    used within 40 mils of the transition.


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
Figure 13-15 Trace Transitioning Layers and Crossing Plane Splits

Figure 13-16 Via Connecting GND to GND


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 13.16 Traces for Decoupling Capacitors

Traces between decoupling and I/O filter capacitors should be as short and wide as practical. Long and

thin traces are more inductive and reduce the intended effect of decoupling capacitors. Also, for similar

reasons, traces to I/O signals and signal terminations should be as short as possible. Vias to the

decoupling capacitors should be sufficiently large in diameter to decrease series inductance. Refer to

the Power Delivery section for the PHY in regards to actual placement requirements of the capacitors.

### 13.17 Ground Planes Under a Magnetics Module

The magnetics module chassis or output ground (secondary side of transformer) should be separated

from the digital or input ground (primary side) by a physical separation of 100 mils minimum. Splitting

the ground planes beneath the transformer minimizes noise coupling between the primary and

secondary sides of the transformer and between the adjacent coils in the magnetics. This arrangement

also improves the common mode choke functionality of magnetics module.

Caution: DO NOT do this if the RJ-45 connector has integrated USB.

Figure 13-18 shows the preferred method for implementing a ground split under an integrated

magnetics module/RJ-45 connector.

Figure 13-17 Stitching Capacitor Between Vias Connecting GND to GND


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
The placement of C1 through C6 may also differ for each board design (in other words, not all of the

capacitors may need to be populated). Also, the capacitors may not be needed on both sides of the

magnetics module.

Note: If using an integrated magnetics module without USB, provide a separate chassis ground

```
“island” to ground around the RJ-45 connector. The split in the ground plane should be at
least 20 mils wide.
```
Some integrated magnetics modules/RJ-45 connectors have recently incorporated the USB into the

device. For this type of magnetics module, a chassis ground moat may not be feasible due to the digital

ground required for the USB pins and their placement relative to the magnetics pins. Thus, a

continuous digital ground without any moats or splits must be used. Figure 13-19 provides an example

of this.

Figure 13-18 Ideal Ground Split Implementation

Table 13-13 Capacitor Stuffing Option Recommended Values

```
Capacitors Value
```
```
C3, C4 4.7 μF or 10 μF
```
```
C1, C2, C5, C6 470 pF to 0.1 μF
```

Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

### 13.18 Light Emitting Diodes

The device has three high-current outputs to directly drive LEDs for link, activity and speed indication.

Since LEDs are likely to be integral to a magnetics module, take care to route the LED traces away from

potential sources of EMI noise. In some cases, it may be desirable to attach filter capacitors.

LAN LED traces should be placed at least 6x (side by side separation) the dielectric height from sources

of noise (ex: signaling traces) and susceptible signal traces (ex: reset signals) on the same or adjacent

layers.

LAN LED traces should be placed at least 7x (broadside coupling) the dielectric height from sources of

noise (ex: signaling traces) and susceptible signal traces (ex: reset signals) on the same or adjacent

layers.

### 13.19 Considerations for Layout

The PHY MDI routing using microstrip requires a differential impedance of 100 ±15%. A 35-mil

(0.889 mm) separation is required between pairs. The 35-mil separation can be reduced for 24 mils

(0.61 mm) in breakout routing. All MDI traces must be referenced to ground.

Figure 13-19 Ground Layout with USB


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
### 13.20 Frequency Control Device Design Considerations

This section provides information regarding frequency control devices, including crystals and oscillators,

for use with all Intel Ethernet controllers. Several suitable frequency control devices are available; none

of which present any unusual challenges in selection. The concepts documented within this section are

applicable to other data communication circuits, including the PHY.

The PHY contains amplifiers that form the basis for feedback oscillators when they are used with the

specific external components. These oscillator circuits, which are both economical and reliable, are

described in more detail in Section 13.21.3.

The chosen frequency control device vendor should be consulted early in the design cycle. Crystal and

oscillator manufacturers familiar with networking equipment clock requirements may provide assistance

in selecting an optimum, low-cost solution.

Several types of third-party frequency reference components are currently available. Descriptions of

each type follow in subsequent sections. They are also listed in order of preference.

### 13.21 Crystals and Oscillators

Clock sources should not be placed near I/O ports or board edges. Radiation from these devices may be

coupled onto the I/O ports or out of the system chassis. Crystals should also be kept away from the

Ethernet magnetics module to prevent interference.

Crystal and load capacitors should be placed on the printed circuit boards as close to the PHY as

possible, which is within 1.0 inch. Traces from XTAL_IN (X1) and XTAL_OUT (X2) should be routed as

symmetrically as possible. Do not route X1 and X2 as a differential trace. Doing so increases jitter and

degrades LAN performance.

- The crystal trace lengths should be less than 1 inch.
- The crystal load capacitors should be placed less than 1" from the crystal.
- The clock lines must be at least 5 times the height of the thinnest adjacent dielectric layer away
    from other from other digital traces (especially reset signals), I/O ports, board edge, transformers
    and differential pairs.
- The clock lines must not cross any plane cuts on adjacent power or ground reference layers unless
    there are decoupling capacitors or connecting vias near the transition.
- The clock lines should not cross or run in parallel (within 3x the dielectric thickness of the closest
    dielectric layer) with any trace (100 MHz signal or higher) on an adjacent layer.

#### 13.21.1 Quartz Crystal

Quartz crystals are generally considered to be the mainstay of frequency control components due to

their low cost and ease of implementation. They are available from numerous vendors in many package

types and with various specification options.


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 13.21.2 Fixed Crystal Oscillator

A packaged fixed crystal oscillator comprises of an inverter, a quartz crystal, and passive components

conveniently packaged together. The device renders a strong, consistent square wave output.

Oscillators used with microprocessors are supplied in many configurations and tolerances.

Crystal oscillators should be restricted for use in special situations, such as shared clocking among

devices or multiple controllers. Since clock routing can be difficult to accomplish, it is preferable to

provide a separate crystal for each device.

Note: Contact your Intel Field Service Representative to obtain the most current device

documentation prior to implementing this solution.

#### 13.21.3 Crystal Selection Parameters

All crystals used with Intel Ethernet controllers are described as “AT-cut,” which refers to the angle at

which the unit is sliced with respect to the long axis of the quartz stone.

Table 13-14 lists crystals which have been used successfully in past designs. (No particular product is

recommended.)

The datasheet for the PHY lists the crystal electrical parameters and provides suggested values for

typical designs. Designers should refer to criteria outlined in their respective PHY datasheet. The

parameters are described in the following subsections.

#### 13.21.4 Vibrational Mode

Crystals in the frequency range referenced above are available in both fundamental and third overtone.

Unless there is a special need for third overtone, fundamental mode crystals should be used.

Table 13-14 Crystal Manufacturers and Part Numbers

```
Manufacturer Part Number Notes
```
```
Epson* Q22FA1280021400
```
```
2.0 x 1.6 x 0.5mm
Small part. Loading capacitors = 10 pF.
```
```
TXC Corporation, USA* 8Y25000010
```
```
2.0 x 1.6 x 0.5mm
Small part. Loading capacitors = 10 pF.
```
```
TXC Corporation, USA 7M25020011 3.2 x 2.5 x 0.7 mm
```
```
TXC Corporation, USA 9C25000008 HC-49S type, SMD (low profile 3 mm)
```
```
NDK America, Inc.* EXS00A-CH00387 3.2 x 2.5 x 0.8mm
```
```
NDK America, Inc. 41CD25.0F1303018 HC-49S type, SMD
```

```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
#### 13.21.5 Nominal Frequency..........................................................................................

Intel Ethernet controllers use a crystal frequency of 25.000 MHz. The 25 MHz input is used to generate

a 125-MHz transmit clock for 100BASE-TX and 1000BASE-TX operation, and 10-MHz and 20-MHz

transmit clocks, for 10BASE-T operation.

#### 13.21.6 Frequency Tolerance

The frequency tolerance for an Ethernet Platform LAN Connect device is dictated by the IEEE 802.3

specification as ±50 parts per million (ppm). This measurement is referenced to a standard

temperature of 25 °C. Intel recommends a frequency tolerance of ±30 ppm to ensure for any frequency

variance contributed by the PCB.

#### 13.21.7 Temperature Stability and Environmental Requirements

Temperature stability is a standard measure of how the oscillation frequency varies over the full

operational temperature range (and beyond). Several optional temperature ranges are currently

available, including -40 °C to +85 °C for industrial environments. Some vendors separate operating

temperatures from temperature stability. Manufacturers may also list temperature stability as 50 ppm

in their data sheets.

Note: Crystals also carry other specifications for storage temperature, shock resistance, and

```
reflow solder conditions. Crystal vendors should be consulted early in the design cycle to
discuss its application and environmental requirements.
```
#### 13.21.8 Calibration Mode

The terms “series-resonant” and “parallel-resonant” are often used to describe crystal oscillator

circuits. Specifying parallel mode is critical to determining how the crystal frequency is calibrated at the

factory.

A crystal specified and tested as series resonant oscillates without problem in a parallel-resonant

circuit, but the frequency is higher than nominal by several hundred parts per million. The purpose of

adding load capacitors to a crystal oscillator circuit is to establish resonance at a frequency higher than

the crystal’s inherent series resonant frequency.

Figure 13-20 illustrates a simplified schematic of the internal oscillator circuit. Pin X1 and X2 refers to

XTAL_IN and XTAL_OUT in the Ethernet device, respectively. The crystal and the capacitors form a

feedback element for the internal inverting amplifier. This combination is called parallel-resonant,

because it has positive reactance at the selected frequency. In other words, the crystal behaves like an

inductor in a parallel LC circuit. Oscillators with piezoelectric feedback elements are also known as

“Pierce” oscillators.


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

#### 13.21.9 Load Capacitance

The formula for crystal load capacitance is as follows:

where C1 = C2 = 22 pF (as suggested in most Intel reference designs), and Cstray = allowance for

additional capacitance in pads, traces and the chip carrier within the Ethernet device package and

C_damp.

#### 13.21.10 Shunt Capacitance

The shunt capacitance parameter is relatively unimportant compared to load capacitance. Shunt

capacitance represents the effect of the crystal’s mechanical holder and contacts. The shunt

capacitance should be a maximum of 6 pF.

Figure 13-20 Thermal Oscillator Circuit


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
#### 13.21.11 Equivalent Series Resistance.............................................................................

Equivalent Series Resistance (ESR) is the real component of the crystal’s impedance at the calibration

frequency, which the inverting amplifier’s loop gain must overcome. ESR varies inversely with frequency

for a given crystal family. The lower the ESR, the faster the crystal starts up. Crystals with an ESR value

of 50  or better should be used.

#### 13.21.12 Drive Level.....................................................................................................

Drive level refers to power dissipation in use. The allowable drive level for a Surface Mounted

Technology (SMT) crystal is less than its through-hole counterpart. This is due to the fact that surface

mount crystals are typically made from narrow, rectangular AT strips, rather than circular AT quartz

blanks.

When selecting a crystal, board designers must ensure that the crystal specification meets at least the

drive level specified. For example, if the crystal drive level specification states that the drive level is 200

W maximum, then the crystal drive level must be at least 200 W. So, a 500 W crystal is sufficient,

but a 100 W crystal is not.

#### 13.21.13 Aging

Aging is a permanent change in frequency (and resistance) occurring over time. This parameter is most

important in its first year because new crystals age faster than old crystals. Crystals with a maximum

value of ±5 ppm per year aging should be used.

#### 13.21.14 Reference Crystal............................................................................................

The normal tolerances of the discrete crystal components can contribute to small frequency offsets with

respect to the target center frequency. To minimize the risk of tolerance-caused frequency offsets

causing a small percentage of production line units to be outside of the acceptable frequency range, it is

important to account for those shifts while empirically determining the proper values for the discrete

loading capacitors, C1 and C2.

Even with a perfect support circuit, most crystals will oscillate slightly higher or lower than the exact

center of the target frequency. Therefore, frequency measurements, which determine the correct value

for C1 and C2, should be performed with an ideal reference crystal. When the capacitive load is exactly

equal to the crystal’s load rating, an ideal reference crystal will be perfectly centered at the desired

target frequency.


Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

13.21.14.1 Reference Crystal Selection

There are several methods available for choosing the appropriate reference crystal:

- If a Saunders and Associates (S&A) crystal network analyzer is available, then discrete crystal
    components can be tested until one is found with zero or nearly zero ppm deviation (with the
    appropriate capacitive load). A crystal with zero or near zero ppm deviation will be a good reference
    crystal to use in subsequent frequency tests to determine the best values for C1 and C2.
- If a crystal analyzer is not available, then the selection of a reference crystal can be done by
    measuring a statistically valid sample population of crystals, which has units from multiple lots and
    approved vendors. The crystal, which has an oscillation frequency closest to the center of the
    distribution, should be the reference crystal used during testing to determine the best values for C1
    and C2.
- It may also be possible to ask the approved crystal vendors or manufacturers to provide a reference
    crystal with zero or nearly zero deviation from the specified frequency when it has the specified
    CLoad capacitance.

When choosing a crystal, customers must keep in mind that to comply with IEEE specifications for

10/100 Mb/s operation and 10/100/1000 Mb/s operation if applicable, the transmitter reference

frequency must be precise within ±50 ppm. Intel recommends customers use a transmitter reference

frequency that is accurate to within ±30 ppm to account for variations in crystal accuracy due to crystal

manufacturing tolerance.

13.21.14.2 Circuit Board

Since the dielectric layers of the circuit board are allowed some reasonable variation in thickness, the

stray capacitance from the printed board (to the crystal circuit) will also vary. If the thickness tolerance

for the outer layers of dielectric are controlled within ±15% of nominal, then the circuit board should

not cause more than ±2 pF variation to the stray capacitance at the crystal. When tuning crystal

frequency, it is recommended that at least three circuit boards are tested for frequency. These boards

should be from different production lots of bare circuit boards.

Alternatively, a larger sample population of circuit boards can be used. A larger population will increase

the probability of obtaining the full range of possible variations in dielectric thickness and the full range

of variation in stray capacitance.

Next, the exact same crystal and discrete load capacitors (C1 and C2) must be soldered onto each

board, and the LAN reference frequency should be measured on each circuit board.

The circuit board, which has a LAN reference frequency closest to the center of the frequency

distribution, should be used while performing the frequency measurements to select the appropriate

value for C1 and C2.

13.21.14.3 Temperature Changes

Temperature changes can cause the crystal frequency to shift. Therefore, frequency measurements

should be done in the final system chassis across the system’s rated operating temperature range.


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
#### 13.21.15 Oscillator Support

The PHY clock input circuit is optimized for use with an external crystal. However, an oscillator can also

be used in place of the crystal with the proper design considerations (refer to the PHY Datasheet for

detailed clock oscillator specifications):

- The clock oscillator has an internal voltage regulator to isolate it from the external noise of other
    circuits to minimize jitter. If an external clock is used, this imposes a maximum input clock
    amplitude. For example, if a 3.3 V DC oscillator is used, its output signal should be attenuated to a
    maximum value with a resistive divider circuit.
- The input capacitance introduced by the PHY (approximately 11 to 13 pF) is greater than the
    capacitance specified by a typical oscillator (approximately 15 pF).
- The input clock jitter from the oscillator can impact the PHY clock and its performance.

Note: The power consumption of additional circuitry equals about 1.5 mW.

Table 13-15 lists oscillators that can be used with the PHY. Note that no particular oscillator is

recommended.

#### 13.21.16 Oscillator Placement and Layout Recommendations

Oscillator clock sources should not be placed near I/O ports or board edges. Radiation from these

devices can be coupled into the I/O ports and radiate beyond the system chassis. Oscillators should also

be kept away from the Ethernet magnetics module to prevent interference.

The oscillator must have it's own decoupling capacitors and they must be placed within 0.25 inches. If a

power trace is used (not power plane), the trace from the capacitor to the oscillator must not exceed

0.25 inches in length. The decoupling capacitors help to improve the oscillator stability. The oscillator

clock trace should be less than two inches from the PHY. If it is greater than 2 inches, then verify the

signal quality, jitter, and clock frequency measurements at the PHY.

The clock lines should also target 5  ±15% and should have 10  series back termination placed close

to the series oscillator. To help reduce EMI, the clock lines must be a distance of at least five times the

height of the thinnest adjacent dielectric layer away from other digital traces (especially reset signals),

I/O ports, the board edge, transformers and differential pairs.

The clock lines must not cross any plane cuts on adjacent power or ground reference layers unless

there are decoupling capacitors or connecting vias near the transition. The clock lines should not cross

or run in parallel with any trace (100 MHz signal or higher) on an adjacent layer.

Table 13-15 Oscillator Manufacturers and Part Numbers

```
Manufacturer Part Number Notes
```
```
TXC Corporation - USA 8W25080004 2.5 x 2.0 x 0.8mm.
```
```
TXC Corporation - USA 7X25080001 3.2 x 2.5 x 1.0 mm.
```

Non-Mobile Design Considerations and Guidelines—Intel® Ethernet Connection I219

There should be a ferrite bead within 250 mils of the oscillator power pin and there must be a 1 F or

greater capacitor within 250 mils of the oscillator, connected to the power trace between the oscillator

input and ferrite bead. With a ferrite bead on the power trace for the oscillator, there should be a power

pour (or fat trace) to supply power to the oscillator.

Note: For the latest PHY schematic connection recommendations, refer to the Intel

##### ®

```
I219 GbE
PHY Reference Schematic and the Intel
```
##### ®

```
I219 GbE PHY Schematic and Layout Checklist,
available through your Intel representative.
```
### 13.22 Troubleshooting Common Physical Layout Issues

The following lists common physical layer design and layout mistakes in LAN on Motherboard (LOM)

designs.

1. Lack of symmetry between the two traces within a differential pair. Asymmetry can create common-
    mode noise and distort the waveforms. For each component and via that one trace encounters, the
    other trace should encounter the same component or a via at the same distance from the Ethernet
    silicon.
2. Unequal length of the two traces within a differential pair. Inequalities create common-mode noise
    and will distort the transmit or receive waveforms.
3. Excessive distance between the Ethernet silicon and the magnetics. Long traces on FR4 fiberglass
    epoxy substrate will attenuate the analog signals. In addition, any impedance mismatch in the
    traces will be aggravated if they are longer than the four-inch guideline.
4. Routing any other trace parallel to and close to one of the differential traces. Crosstalk getting onto
    the receive channel will cause degraded long cable BER. Crosstalk getting onto the transmit channel
    can cause excessive EMI emissions and can cause poor transmit BER on long cables. At a minimum,
    for stripline other signals should be kept at least 6x the height of the thinnest adjacent dielectric
    layer. For microsrip it is 7x. The only possible exceptions are in the vicinities where the traces enter
    or exit the magnetics, the RJ-45 connector, and the Ethernet silicon.
5. Using a low-quality magnetics module.
6. Reusing an out-of-date physical layer schematic in a Ethernet silicon design. The terminations and
    decoupling can be different from one PHY to another.
7. Incorrect differential trace impedances. It is important to have about a 100-impedance between
    the two traces within a differential pair. This becomes even more important as the differential traces
    become longer. To calculate differential impedance, many impedance calculators only multiply the
    single-ended impedance by two. This does not take into account edge-to-edge capacitive coupling
    between the two traces. When the two traces within a differential pair are kept close to each other,
    the edge coupling can lower the effective differential impedance by 5  to 20 . Short traces will
    have fewer problems if the differential impedance is slightly off target.

### 13.23 Power Delivery

The I219 requires a 3.3 V power rail and a 0.93 V (Core) power rail. The internal 3.3 V power rail is

brought out for decoupling. Figure 2-2 shows a typical power delivery configuration that can be


```
Intel® Ethernet Connection I219—Non-Mobile Design Considerations and Guidelines
```
implemented. However, power delivery can be customized based on a specific OEM. In general planes

should be used to deliver 3.3 Vdc and the Core voltage. Not using planes can cause resistive voltage

drop and/or inductive voltage drop (due to transient or static currents). Some of the symptoms of these

voltage drops can include higher EMI, radiated immunity, radiated emissions, IEEE conformance issues,

and register corruption.

Decoupling capacitors (0.1 F and smaller) should be placed within 250 mils of the LAN device. They

also should be distributed around the PHY and some should be in close proximity to the power pins.

The bulk capacitors (1.0 F or greater) should be placed within 1 inch if using a trace (50 mils wide or

wider) or within 1.5 inches if using a plane.

The Core power rail for the I219 uses the integrated SVR (iSVR). When laying out the circuit the

inductor must be placed within 0.5" of the input pin to the PHY and connected with a trace wider than or

equal to 20 mil wide. (See the reference schematic for further details regarding the Core power rail.)

While Intel does not endorse vendors or specific components, design compatibility has been verified for

the connectors in Table 13-16.

Note: For latest PHY schematic connection recommendations, refer to the Intel

##### ®

```
I219 GbE PHY
Reference Schematic or contact your Intel Field Service Representative.
```
### 13.24 I219 Power Sequencing

The Intel

##### ®

Ethernet Controller I219 does not require any power sequencing between the 3.3 V and Core

power rails. See the reference schematic for details.

Table 13-16 Inductors and Manufacturers

```
Manufacturer Part Number Notes
```
```
Taiyo Yuden* NRS2012T-4R7MGJ 2.0 x 2.0 x 1.2 mm
```
```
TDK* VLS2012ET-4R7M 2.0 x 2.0 x 1.2 mm
```
```
muRata* LQH32PN4R7NN0 3.2 x 2.5 x 1.55 mm
```
```
muRata LQH32CN4R7M53 3.2 x 2.5 x 1.55 mm
```

