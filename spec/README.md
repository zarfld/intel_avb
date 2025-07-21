# Intel AVB Specifications and Documentation

This directory contains Intel-specific documentation related to the Intel AVB implementation, including official Intel datasheets, specification updates, and technical documentation for supported Intel Ethernet controllers.

## Documentation Index

### Intel I210 Family
- **332763_I210_SpecUpdate_Rev3.0** - Official Intel I210 specification update (Rev 3.0)
- **333016 - I210_Datasheet_v_3_7** - Complete Intel I210 datasheet (v3.7)
- **335761 - I210_CS_CL_Datasheet_v_1_8** - Intel I210-CS/CL automotive variants datasheet (v1.8)

### Intel I217 Family
- **i217-ethernet-controller-datasheet-2** - Intel I217 Ethernet Controller datasheet (v2.x)

### Intel I219 Family  
- **ethernet-connection-i219-datasheet** - Intel I219 Ethernet Connection datasheet

### Intel I225/I226 Family
- **621661-Intel® Ethernet Controller I225-Public External Specification Update-v1.2** - I225 specification update
- **621753-Intel® Ethernet Controller I225-I226-Product Brief** - I225/I226 product brief

### Intel-Altera Integration
- **2407151103_Intel-Altera-KTI226V-S-RKTU_C26159200** - Intel-Altera KTI226V integration documentation

## Device Support Matrix

| Controller | Implementation Status | Documentation |
|------------|----------------------|---------------|
| **I210**   | Basic Implementation | Complete official specs |
| **I217**   | Not Implemented      | Complete official specs |
| **I219**   | Ready                | Complete official specs |
| **I225**   | Production Ready     | Complete official specs + updates |
| **I226**   | Production Ready     | Complete official specs |

## Usage Notes

These specifications are the authoritative source for:
- Register definitions and memory maps
- Hardware capabilities and limitations
- Programming interfaces and sequences
- Timing requirements and electrical specifications
- Compliance and certification information

**Important**: All implementations in `../lib/` should reference these official specifications for accuracy and compliance.

## Document Status

All documents are official Intel publications and should be considered authoritative for implementation decisions. When implementing new features or debugging hardware issues, always consult the relevant specification first.

Last updated: July 2025
