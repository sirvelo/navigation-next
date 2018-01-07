#ifndef LOG_TYPES_RIM_H_
#define LOG_TYPES_RIM_H_

#include <forensics.h>
#include <log_types.h>

/*
 * Define vendor-specific log types used for forensics logging.
 * These are in addition to the
 */
typedef enum
{
    LOG_TRACELOG = LOG_OEM_START,   // Start of vendor logs
    LOG_AIR_LOGS,
    LOG_ANDROID_LOGS,
    LOG_CORE_INFO,
    LOG_FLASH_INFO,
    LOG_LAUNCHER_LOGS,
    LOG_NAVIGATOR_INFO,
    LOG_PIDIN_LOGS,
    LOG_PROCESS_REPORT,
    LOG_SCREENSHOT,
    LOG_SLOGGER_RESET_PRESERVED,
    LOG_USB_INFO,
    LOG_VAR_LOGS,
    LOG_VAR_PPS,
    LOG_WIFI_INFO,
    LOG_QCT_RAMDUMP,
    LOG_HOGS,
    LOG_ANDROID_TRACES,
    LOG_SYSTEM_INFO,
    LOG_QCT_MODEMCRASH,
    LOG_KRINGBUFFER,
    LOG_GPS_LOGS,
    LOG_CELLULAR_QCT_CALL_DROP,
    LOG_CELLULAR_QCT_MODEM,
    LOG_CELLULAR_QCT_MODEM_CONTROLLED,
    LOG_CELLULAR_QCT_F3LOG,
    LOG_CELLULAR_STE_MODEM,
    LOG_CELLULAR_STE_CALIB_DATA,
    LOG_CELLULAR_STE_GDFS_DATA,
    LOG_CELLULAR_NETWORK_INFO,
    LOG_CELLULAR_STE_MODEM_CRASH_DUMP,
    LOG_GRAPHICS_QCT_GPU_POSTMORTEM,
    LOG_QUIP_LOGS,
    LOG_NATIVE_APP_LOGS,
    LOG_GRAPHICS_QCT_GPU_KGSL_LOG,
    LOG_SMMU_QCT_FAULT_LOG,
    LOG_BATTERY_DRAIN,
    LOG_SLOGGER2,
    LOG_SLOGGER2_RESET_PRESERVED,
    LOG_FUEL_GAUGE_LOGS,
    LOG_CPU_PPS_LOGS,
    LOG_POWER_RM_LOGS,
    LOG_TEMPERATURE_LOGS,
    LOG_AUDIO_PCM_LOGS,
    LOG_VPN_LOGS,
    LOG_BBIO_LOGS,
    LOG_CORE_NETWORKING_LOGS,
    LOG_WIFI_LOGS,
    LOG_FUEL_GAUGE_REDUCED_LOGS,
    LOG_DISPLAY_SURFACE_RGB1,
    LOG_DISPLAY_SURFACE_RGB2,
    LOG_DISPLAY_SURFACE_VG1,
    LOG_DISPLAY_SURFACE_VG2,
    LOG_DISPLAY_SURFACE_CURSOR1,
    LOG_DISPLAY_SURFACE_CURSOR2,
    LOG_CELLULAR_STE_MODEM_CRASH_HEADER,
    LOG_CELLULAR_STE_CHANGED_GDFS,
    LOG_CELLULAR_STE_VERSION_MAP,
    LOG_CELLULAR_STE_SW_VERSION,
    LOG_CELLULAR_STE_MODEM_DRIVER,
    LOG_CELLULAR_STE_SPEECH_LOG_TX,
    LOG_CELLULAR_STE_SPEECH_LOG_RX,
    LOG_BMETRICS,
    LOG_SMMU_QCT_FAULT_2D0_LOG,
    LOG_SMMU_QCT_FAULT_2D1_LOG,
    LOG_SMMU_QCT_FAULT_GFX3D_LOG,
    LOG_SMMU_QCT_FAULT_JPEG_LOG,
    LOG_SMMU_QCT_FAULT_JPEGD_LOG,
    LOG_SMMU_QCT_FAULT_MDP4_0_LOG,
    LOG_SMMU_QCT_FAULT_MDP4_1_LOG,
    LOG_SMMU_QCT_FAULT_ROTATOR_LOG,
    LOG_SMMU_QCT_FAULT_SS1080P_0_LOG,
    LOG_SMMU_QCT_FAULT_SS1080P_1_LOG,
    LOG_SMMU_QCT_FAULT_VFE_LOG,
    LOG_SMMU_QCT_FAULT_VPE_LOG,
    LOG_SMMU_QCT_FAULT_DEBUG_LOG,
    LOG_ANDROID_EXTRA_LOGS,
    LOG_DISPLAY_QCT_POSTMORTEM,
    LOG_FULL_AP_RAMDUMP,
    LOG_CORE_CRITICAL,
    LOG_CORES_ALL,
    LOG_CELLULAR_QCT_MODEM_CRASH_DUMP,
    LOG_CELLULAR_QCT_MODEM_CRASH_LOG,
    LOG_CELLULAR_QCT_LPASS_CRASH_LOG,
    LOG_CELLULAR_QCT_NETWORK_REJECT,
    LOG_SLOGGER_RESET_PERSISTED,
    LOG_SLOGGER2_RESET_PERSISTED,
    LOG_CELLULAR_STE_MODEM_SNAPSHOT,
    LOG_CELLULAR_RCT_MODEM,
    LOG_CELLULAR_QCT_CSIM_MLPL,
    LOG_CELLULAR_QCT_CSIM_MSPL,
    LOG_SANITY_LOGS,
    LOG_TRACE_LOG_RESET_PRESERVED,
    LOG_PIDIN_RESET_PRESERVED,
    LOG_CELLULAR_RCT_MODEM_SNAPSHOT,
    LOG_RAW_SLOG2_BUFFERS,
    LOG_SETTINGS_APP_LOGS,
    LOG_TRACE_LOG_RESET_PERSISTED,
    LOG_PIDIN_RESET_PERSISTED,
    LOG_SLOGGER2_SENSORS,
    LOG_WLAN_ALL,
    LOG_RESET_DIRECTORY_LISTING,
    LOG_THERMAL_FLIGHT_RECORDER,
    LOG_KRINGBUFFER_RESET_PRESERVED,
    LOG_OMAP_CLOCK_TREE,
    LOG_PIM_PYTHON_LOG,
    LOG_PIM_BBIO_LOG,
    LOG_CELLULAR_QCT_ONDEVICE_QXDM,
    LOG_MINIDUMP_LOG,
    LOG_BBIO_HRT,
    LOG_ACCOUNT_SYNC_LOGS,
    LOG_APP_SUMMARY_LOGS,
    LOG_BACKGROUND_THREAD_LOGS,
    LOG_NETWORK_TRAFFIC_SAMPLE,
    LOG_QCT_RADIO_STATS,
    LOG_GRAPHICS_QCT_GPU_POSTMORTEM_BIN,
    LOG_USB_DEBUG_INFO,
    LOG_SCREEN_LOGS,
    LOG_SCREEN_PID_MAPPINGS,
    LOG_DEVICE_WIPE_LOGS,
    LOG_BOOT_SLOGS,
    LOG_VDM_LOGS,
    LOG_SMMU_QCT_FAULT_GFX3D1_LOG,
    LOG_NAVIGATOR_PRE_EXIT,
    LOG_BOOT_LOGS,
    LOG_BOOTROM_LOGS,
    LOG_PPS_WIRELESS,
    LOG_PPS_DEVICE_INFO,
// ...New vendor specific logs go here
//  Must come last
    LOG_OEM_END
} _forensics_log_vendor_t;
typedef uint16_t forensics_log_vendor_t;

#endif
