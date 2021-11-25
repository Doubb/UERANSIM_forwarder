/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r16.4.0/38413-g40.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER`
 */

#include "NGAP_PDUSessionResourceModifyItemModCfm.h"

#include "NGAP_ProtocolExtensionContainer.h"
static int
memb_NGAP_pDUSessionResourceModifyConfirmTransfer_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const OCTET_STRING_t *st = (const OCTET_STRING_t *)sptr;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	
	if(1 /* No applicable constraints whatsoever */) {
		(void)st; /* Unused variable */
		/* Nothing is here. See below */
	}
	
	return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
}

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_memb_NGAP_pDUSessionResourceModifyConfirmTransfer_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_SEMI_CONSTRAINED,	-1, -1,  0,  0 }	/* (SIZE(0..MAX)) */,
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
asn_TYPE_member_t asn_MBR_NGAP_PDUSessionResourceModifyItemModCfm_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_PDUSessionResourceModifyItemModCfm, pDUSessionID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_PDUSessionID,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"pDUSessionID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_PDUSessionResourceModifyItemModCfm, pDUSessionResourceModifyConfirmTransfer),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			&asn_PER_memb_NGAP_pDUSessionResourceModifyConfirmTransfer_constr_3,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			memb_NGAP_pDUSessionResourceModifyConfirmTransfer_constraint_1
		},
		0, 0, /* No default value */
		"pDUSessionResourceModifyConfirmTransfer"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_PDUSessionResourceModifyItemModCfm, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_9571P168,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_NGAP_PDUSessionResourceModifyItemModCfm_oms_1[] = { 2 };
static const ber_tlv_tag_t asn_DEF_NGAP_PDUSessionResourceModifyItemModCfm_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_PDUSessionResourceModifyItemModCfm_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* pDUSessionID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* pDUSessionResourceModifyConfirmTransfer */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_NGAP_PDUSessionResourceModifyItemModCfm_specs_1 = {
	sizeof(struct NGAP_PDUSessionResourceModifyItemModCfm),
	offsetof(struct NGAP_PDUSessionResourceModifyItemModCfm, _asn_ctx),
	asn_MAP_NGAP_PDUSessionResourceModifyItemModCfm_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_NGAP_PDUSessionResourceModifyItemModCfm_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_PDUSessionResourceModifyItemModCfm = {
	"PDUSessionResourceModifyItemModCfm",
	"PDUSessionResourceModifyItemModCfm",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_PDUSessionResourceModifyItemModCfm_tags_1,
	sizeof(asn_DEF_NGAP_PDUSessionResourceModifyItemModCfm_tags_1)
		/sizeof(asn_DEF_NGAP_PDUSessionResourceModifyItemModCfm_tags_1[0]), /* 1 */
	asn_DEF_NGAP_PDUSessionResourceModifyItemModCfm_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_PDUSessionResourceModifyItemModCfm_tags_1)
		/sizeof(asn_DEF_NGAP_PDUSessionResourceModifyItemModCfm_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_NGAP_PDUSessionResourceModifyItemModCfm_1,
	3,	/* Elements count */
	&asn_SPC_NGAP_PDUSessionResourceModifyItemModCfm_specs_1	/* Additional specs */
};

