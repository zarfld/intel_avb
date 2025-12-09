#pragma once

/*
 * FORWARDING HEADER - DO NOT EDIT
 * 
 * This header forwards to the Single Source of Truth (SSOT) for AVB IOCTLs.
 * The SSOT is maintained in the IntelAvbFilter driver: include/avb_ioctl.h
 * 
 * Why: The external intel_avb library is a CONSUMER of the IntelAvbFilter driver.
 * The driver defines the IOCTL interface, and consumers must use the driver's definitions.
 * 
 * DO NOT duplicate IOCTL definitions here - they will become outdated.
 * Always reference the driver's include/avb_ioctl.h instead.
 */

/* Forward to the SSOT (3 levels up, then into include/) */
#include "../../../include/avb_ioctl.h"
