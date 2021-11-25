/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r16.4.0/38413-g40.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER`
 */

#ifndef	_NGAP_ENB_ID_H_
#define	_NGAP_ENB_ID_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_ENB_ID_PR {
	NGAP_ENB_ID_PR_NOTHING,	/* No components present */
	NGAP_ENB_ID_PR_macroENB_ID,
	NGAP_ENB_ID_PR_homeENB_ID,
	NGAP_ENB_ID_PR_short_macroENB_ID,
	NGAP_ENB_ID_PR_long_macroENB_ID,
	NGAP_ENB_ID_PR_choice_Extensions
} NGAP_ENB_ID_PR;

/* Forward declarations */
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_ENB-ID */
typedef struct NGAP_ENB_ID {
	NGAP_ENB_ID_PR present;
	union NGAP_ENB_ID_u {
		BIT_STRING_t	 macroENB_ID;
		BIT_STRING_t	 homeENB_ID;
		BIT_STRING_t	 short_macroENB_ID;
		BIT_STRING_t	 long_macroENB_ID;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_ENB_ID_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ENB_ID;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_ENB_ID_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_ENB_ID_1[5];
extern asn_per_constraints_t asn_PER_type_NGAP_ENB_ID_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_ENB_ID_H_ */
#include <asn_internal.h>
