/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/properties.h>
#include <android-base/logging.h>

#include "property_service.h"
#include "vendor_init.h"

using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;
    
    pi = (prop_info*) __system_property_find(prop);
    if (pi)
    __system_property_update(pi, value, strlen(value));
    else
    __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    std::string platform;
    char bootmid[PROP_VALUE_MAX];
    char bootcid[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    int rc;

    platform = GetProperty("ro.board.platform", "");
    if (platform != ANDROID_TARGET)
        return;

    GetProperty("ro.boot.mid", bootmid);
    GetProperty("ro.boot.cid", bootcid);

    if (strstr(bootmid, "2PZF10000")) {
        /* Europe (OCE_UHL) */
        property_override("ro.build.product", "htc_oceuhl");
        property_override("ro.product.model", "HTC U Ultra");
        property_set("ro.ril.enable.pre_r8fd", "1");
        property_set("ro.ril.hsxpa", "4");
        property_set("ro.ril.hsdpa.category", "24");
        property_set("ro.ril.hsupa.category", "6");
        property_set("ro.ril.disable.cpc", "0");
        property_set("persist.rild.nitz_plmn", "");
        property_set("persist.rild.nitz_long_ons_0", "");
        property_set("persist.rild.nitz_long_ons_1", "");
        property_set("persist.rild.nitz_long_ons_2", "");
        property_set("persist.rild.nitz_long_ons_3", "");
        property_set("persist.rild.nitz_short_ons_0", "");
        property_set("persist.rild.nitz_short_ons_1", "");
        property_set("persist.rild.nitz_short_ons_2", "");
        property_set("persist.rild.nitz_short_ons_3", "");
        property_set("ril.subscription.types", "NV,RUIM");
        property_set("telephony.lteOnCdmaDevice", "1");
    } else if (strstr(bootmid, "2PZF20000")) {
        /* Dual SIM Dual Netcom UHL Europe Africa Asia (OCE_DUGL) */
        property_override("ro.build.product", "htc_ocedugl");
        property_override("ro.product.model", "HTC_U-1u");
        property_set("ro.ril.enable.pre_r8fd", "1");
        property_set("ro.ril.hsxpa", "5");
        property_set("ro.ril.hsdpa.category", "24");
        property_set("ro.ril.hsupa.category", "6");
        property_set("ro.ril.disable.cpc", "0");
        property_set("persist.rild.nitz_plmn", "");
        property_set("persist.rild.nitz_long_ons_0", "");
        property_set("persist.rild.nitz_long_ons_1", "");
        property_set("persist.rild.nitz_long_ons_2", "");
        property_set("persist.rild.nitz_long_ons_3", "");
        property_set("persist.rild.nitz_short_ons_0", "");
        property_set("persist.rild.nitz_short_ons_1", "");
        property_set("persist.rild.nitz_short_ons_2", "");
        property_set("persist.rild.nitz_short_ons_3", "");
        property_set("ril.subscription.types", "NV,RUIM");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ril.htc.multisim.cfg", "dsds");
    } else if (strstr(bootmid, "2PZF30000")) {
        /* Dual card full Netcom UHL China (OCE_DUGL) */
        property_override("ro.build.product", "htc_ocedugl");
        property_override("ro.product.model", "HTC_U-1w");
		property_set("ro.ril.enable.pre_r8fd", "1");
		property_set("ro.ril.hsxpa", "5");
		property_set("ro.ril.hsdpa.category", "24");
		property_set("ro.ril.hsupa.category", "6");
		property_set("ro.ril.disable.cpc", "0");
		property_set("persist.rild.nitz_plmn", "");
		property_set("persist.rild.nitz_long_ons_0", "");
		property_set("persist.rild.nitz_long_ons_1", "");
		property_set("persist.rild.nitz_long_ons_2", "");
		property_set("persist.rild.nitz_long_ons_3", "");
		property_set("persist.rild.nitz_short_ons_0", "");
		property_set("persist.rild.nitz_short_ons_1", "");
		property_set("persist.rild.nitz_short_ons_2", "");
		property_set("persist.rild.nitz_short_ons_3", "");
		property_set("ril.subscription.types", "NV,RUIM");
		property_set("telephony.lteOnCdmaDevice", "1");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("ril.htc.multisim.cfg", "dsds");
    } else {
        /* GSM (OCE_UL) */
        property_override("ro.build.product", "htc_oceul");
        property_override("ro.product.model", "HTC U Ultra");
    }

    //set_props_from_build();

    GetProperty("ro.product.device", device);
    LOG(ERROR) << "Found bootmid %s setting build properties for %s device\n" << bootmid << device;
}
