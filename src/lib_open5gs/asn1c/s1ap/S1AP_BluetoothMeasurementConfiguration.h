/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../support/s1ap-r16.4.0/36413-g40.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER`
 */

#ifndef	_S1AP_BluetoothMeasurementConfiguration_H_
#define	_S1AP_BluetoothMeasurementConfiguration_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1AP_BluetoothMeasConfig.h"
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_BluetoothMeasurementConfiguration__bt_rssi {
	S1AP_BluetoothMeasurementConfiguration__bt_rssi_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_S1AP_BluetoothMeasurementConfiguration__bt_rssi;

/* Forward declarations */
struct S1AP_BluetoothMeasConfigNameList;
struct S1AP_ProtocolExtensionContainer;

/* S1AP_BluetoothMeasurementConfiguration */
typedef struct S1AP_BluetoothMeasurementConfiguration {
	S1AP_BluetoothMeasConfig_t	 bluetoothMeasConfig;
	struct S1AP_BluetoothMeasConfigNameList	*bluetoothMeasConfigNameList;	/* OPTIONAL */
	long	*bt_rssi;	/* OPTIONAL */
	struct S1AP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_BluetoothMeasurementConfiguration_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_S1AP_bt_rssi_4;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_BluetoothMeasurementConfiguration;

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_BluetoothMeasurementConfiguration_H_ */
#include <asn_internal.h>