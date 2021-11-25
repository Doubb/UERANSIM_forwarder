/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r16.4.0/38413-g40.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER`
 */

#ifndef	_NGAP_UEHistoryInformationFromTheUE_H_
#define	_NGAP_UEHistoryInformationFromTheUE_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_NRMobilityHistoryReport.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_UEHistoryInformationFromTheUE_PR {
	NGAP_UEHistoryInformationFromTheUE_PR_NOTHING,	/* No components present */
	NGAP_UEHistoryInformationFromTheUE_PR_nR,
	NGAP_UEHistoryInformationFromTheUE_PR_choice_Extensions
} NGAP_UEHistoryInformationFromTheUE_PR;

/* Forward declarations */
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_UEHistoryInformationFromTheUE */
typedef struct NGAP_UEHistoryInformationFromTheUE {
	NGAP_UEHistoryInformationFromTheUE_PR present;
	union NGAP_UEHistoryInformationFromTheUE_u {
		NGAP_NRMobilityHistoryReport_t	 nR;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_UEHistoryInformationFromTheUE_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_UEHistoryInformationFromTheUE;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_UEHistoryInformationFromTheUE_H_ */
#include <asn_internal.h>
