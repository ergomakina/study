/*
 *	micro T-Kernel system call (extern) for IAR Assembler
 *
 */

#if defined(__GNUC__)
#define _SVC_EXTERN(name)
#elif defined(__IASMARM__) || defined(__CC_ARM)
#define _SVC_EXTERN(name)	EXTERN name##_impl
#endif

#ifdef USE_FUNC_TK_CRE_TSK
	_SVC_EXTERN(tk_cre_tsk)
#endif
#ifdef USE_FUNC_TK_DEL_TSK
	_SVC_EXTERN(tk_del_tsk)
#endif
#ifdef USE_FUNC_TK_STA_TSK
	_SVC_EXTERN(tk_sta_tsk)
#endif
#ifdef USE_FUNC_TK_EXT_TSK
	_SVC_EXTERN(tk_ext_tsk)
#endif
#ifdef USE_FUNC_TK_EXD_TSK
	_SVC_EXTERN(tk_exd_tsk)
#endif
#ifdef USE_FUNC_TK_TER_TSK
	_SVC_EXTERN(tk_ter_tsk)
#endif
#ifdef USE_FUNC_TK_DIS_DSP
	_SVC_EXTERN(tk_dis_dsp)
#endif
#ifdef USE_FUNC_TK_ENA_DSP
	_SVC_EXTERN(tk_ena_dsp)
#endif
#ifdef USE_FUNC_TK_CHG_PRI
	_SVC_EXTERN(tk_chg_pri)
#endif
#ifdef USE_FUNC_TK_ROT_RDQ
	_SVC_EXTERN(tk_rot_rdq)
#endif
#ifdef USE_FUNC_TK_REL_WAI
	_SVC_EXTERN(tk_rel_wai)
#endif
#ifdef USE_FUNC_TK_GET_TID
	_SVC_EXTERN(tk_get_tid)
#endif
#ifdef USE_FUNC_TK_GET_REG
	_SVC_EXTERN(tk_get_reg)
#endif
#ifdef USE_FUNC_TK_SET_REG
	_SVC_EXTERN(tk_set_reg)
#endif
#ifdef USE_FUNC_TK_REF_TSK
	_SVC_EXTERN(tk_ref_tsk)
#endif
#ifdef USE_FUNC_TK_SUS_TSK
	_SVC_EXTERN(tk_sus_tsk)
#endif
#ifdef USE_FUNC_TK_RSM_TSK
	_SVC_EXTERN(tk_rsm_tsk)
#endif
#ifdef USE_FUNC_TK_FRSM_TSK
	_SVC_EXTERN(tk_frsm_tsk)
#endif
#ifdef USE_FUNC_TK_SLP_TSK
	_SVC_EXTERN(tk_slp_tsk)
#endif
#ifdef USE_FUNC_TK_WUP_TSK
	_SVC_EXTERN(tk_wup_tsk)
#endif
#ifdef USE_FUNC_TK_CAN_WUP
	_SVC_EXTERN(tk_can_wup)
#endif
#ifdef USE_FUNC_TK_CRE_SEM
	_SVC_EXTERN(tk_cre_sem)
#endif
#ifdef USE_FUNC_TK_DEL_SEM
	_SVC_EXTERN(tk_del_sem)
#endif
#ifdef USE_FUNC_TK_SIG_SEM
	_SVC_EXTERN(tk_sig_sem)
#endif
#ifdef USE_FUNC_TK_WAI_SEM
	_SVC_EXTERN(tk_wai_sem)
#endif
#ifdef USE_FUNC_TK_REF_SEM
	_SVC_EXTERN(tk_ref_sem)
#endif
#ifdef USE_FUNC_TK_CRE_MTX
	_SVC_EXTERN(tk_cre_mtx)
#endif
#ifdef USE_FUNC_TK_DEL_MTX
	_SVC_EXTERN(tk_del_mtx)
#endif
#ifdef USE_FUNC_TK_LOC_MTX
	_SVC_EXTERN(tk_loc_mtx)
#endif
#ifdef USE_FUNC_TK_UNL_MTX
	_SVC_EXTERN(tk_unl_mtx)
#endif
#ifdef USE_FUNC_TK_REF_MTX
	_SVC_EXTERN(tk_ref_mtx)
#endif
#ifdef USE_FUNC_TK_CRE_FLG
	_SVC_EXTERN(tk_cre_flg)
#endif
#ifdef USE_FUNC_TK_DEL_FLG
	_SVC_EXTERN(tk_del_flg)
#endif
#ifdef USE_FUNC_TK_SET_FLG
	_SVC_EXTERN(tk_set_flg)
#endif
#ifdef USE_FUNC_TK_CLR_FLG
	_SVC_EXTERN(tk_clr_flg)
#endif
#ifdef USE_FUNC_TK_WAI_FLG
	_SVC_EXTERN(tk_wai_flg)
#endif
#ifdef USE_FUNC_TK_REF_FLG
	_SVC_EXTERN(tk_ref_flg)
#endif
#ifdef USE_FUNC_TK_CRE_MBX
	_SVC_EXTERN(tk_cre_mbx)
#endif
#ifdef USE_FUNC_TK_DEL_MBX
	_SVC_EXTERN(tk_del_mbx)
#endif
#ifdef USE_FUNC_TK_SND_MBX
	_SVC_EXTERN(tk_snd_mbx)
#endif
#ifdef USE_FUNC_TK_RCV_MBX
	_SVC_EXTERN(tk_rcv_mbx)
#endif
#ifdef USE_FUNC_TK_REF_MBX
	_SVC_EXTERN(tk_ref_mbx)
#endif
#ifdef USE_FUNC_TK_CRE_MBF
	_SVC_EXTERN(tk_cre_mbf)
#endif
#ifdef USE_FUNC_TK_DEL_MBF
	_SVC_EXTERN(tk_del_mbf)
#endif
#ifdef USE_FUNC_TK_SND_MBF
	_SVC_EXTERN(tk_snd_mbf)
#endif
#ifdef USE_FUNC_TK_RCV_MBF
	_SVC_EXTERN(tk_rcv_mbf)
#endif
#ifdef USE_FUNC_TK_REF_MBF
	_SVC_EXTERN(tk_ref_mbf)
#endif
#ifdef USE_FUNC_TK_CRE_POR
	_SVC_EXTERN(tk_cre_por)
#endif
#ifdef USE_FUNC_TK_DEL_POR
	_SVC_EXTERN(tk_del_por)
#endif
#ifdef USE_FUNC_TK_CAL_POR
	_SVC_EXTERN(tk_cal_por)
#endif
#ifdef USE_FUNC_TK_ACP_POR
	_SVC_EXTERN(tk_acp_por)
#endif
#ifdef USE_FUNC_TK_FWD_POR
	_SVC_EXTERN(tk_fwd_por)
#endif
#ifdef USE_FUNC_TK_RPL_RDV
	_SVC_EXTERN(tk_rpl_rdv)
#endif
#ifdef USE_FUNC_TK_REF_POR
	_SVC_EXTERN(tk_ref_por)
#endif
#ifdef USE_FUNC_TK_DEF_INT
	_SVC_EXTERN(tk_def_int)
#endif
#ifdef USE_FUNC_TK_RET_INT
//	_SVC_EXTERN(tk_ret_int)
#endif
#ifdef USE_FUNC_TK_CRE_MPL
	_SVC_EXTERN(tk_cre_mpl)
#endif
#ifdef USE_FUNC_TK_DEL_MPL
	_SVC_EXTERN(tk_del_mpl)
#endif
#ifdef USE_FUNC_TK_GET_MPL
	_SVC_EXTERN(tk_get_mpl)
#endif
#ifdef USE_FUNC_TK_REL_MPL
	_SVC_EXTERN(tk_rel_mpl)
#endif
#ifdef USE_FUNC_TK_REF_MPL
	_SVC_EXTERN(tk_ref_mpl)
#endif
#ifdef USE_FUNC_TK_CRE_MPF
	_SVC_EXTERN(tk_cre_mpf)
#endif
#ifdef USE_FUNC_TK_DEL_MPF
	_SVC_EXTERN(tk_del_mpf)
#endif
#ifdef USE_FUNC_TK_GET_MPF
	_SVC_EXTERN(tk_get_mpf)
#endif
#ifdef USE_FUNC_TK_REL_MPF
	_SVC_EXTERN(tk_rel_mpf)
#endif
#ifdef USE_FUNC_TK_REF_MPF
	_SVC_EXTERN(tk_ref_mpf)
#endif
#ifdef USE_FUNC_TK_SET_TIM
	_SVC_EXTERN(tk_set_tim)
#endif
#ifdef USE_FUNC_TK_GET_TIM
	_SVC_EXTERN(tk_get_tim)
#endif
#ifdef USE_FUNC_TK_GET_OTM
	_SVC_EXTERN(tk_get_otm)
#endif
#ifdef USE_FUNC_TK_DLY_TSK
	_SVC_EXTERN(tk_dly_tsk)
#endif
#ifdef USE_FUNC_TK_CRE_CYC
	_SVC_EXTERN(tk_cre_cyc)
#endif
#ifdef USE_FUNC_TK_DEL_CYC
	_SVC_EXTERN(tk_del_cyc)
#endif
#ifdef USE_FUNC_TK_STA_CYC
	_SVC_EXTERN(tk_sta_cyc)
#endif
#ifdef USE_FUNC_TK_STP_CYC
	_SVC_EXTERN(tk_stp_cyc)
#endif
#ifdef USE_FUNC_TK_REF_CYC
	_SVC_EXTERN(tk_ref_cyc)
#endif
#ifdef USE_FUNC_TK_CRE_ALM
	_SVC_EXTERN(tk_cre_alm)
#endif
#ifdef USE_FUNC_TK_DEL_ALM
	_SVC_EXTERN(tk_del_alm)
#endif
#ifdef USE_FUNC_TK_STA_ALM
	_SVC_EXTERN(tk_sta_alm)
#endif
#ifdef USE_FUNC_TK_STP_ALM
	_SVC_EXTERN(tk_stp_alm)
#endif
#ifdef USE_FUNC_TK_REF_ALM
	_SVC_EXTERN(tk_ref_alm)
#endif
#ifdef USE_FUNC_TK_REF_VER
	_SVC_EXTERN(tk_ref_ver)
#endif
#ifdef USE_FUNC_TK_REF_SYS
	_SVC_EXTERN(tk_ref_sys)
#endif
#ifdef USE_FUNC_TK_DEF_SSY
	_SVC_EXTERN(tk_def_ssy)
#endif
#ifdef USE_FUNC_TK_REF_SSY
	_SVC_EXTERN(tk_ref_ssy)
#endif
#ifdef USE_FUNC_TK_OPN_DEV
	_SVC_EXTERN(tk_opn_dev)
#endif
#ifdef USE_FUNC_TK_CLS_DEV
	_SVC_EXTERN(tk_cls_dev)
#endif
#ifdef USE_FUNC_TK_REA_DEV
	_SVC_EXTERN(tk_rea_dev)
#endif
#ifdef USE_FUNC_TK_SREA_DEV
	_SVC_EXTERN(tk_srea_dev)
#endif
#ifdef USE_FUNC_TK_WRI_DEV
	_SVC_EXTERN(tk_wri_dev)
#endif
#ifdef USE_FUNC_TK_SWRI_DEV
	_SVC_EXTERN(tk_swri_dev)
#endif
#ifdef USE_FUNC_TK_WAI_DEV
	_SVC_EXTERN(tk_wai_dev)
#endif
#ifdef USE_FUNC_TK_SUS_DEV
	_SVC_EXTERN(tk_sus_dev)
#endif
#ifdef USE_FUNC_TK_GET_DEV
	_SVC_EXTERN(tk_get_dev)
#endif
#ifdef USE_FUNC_TK_REF_DEV
	_SVC_EXTERN(tk_ref_dev)
#endif
#ifdef USE_FUNC_TK_OREF_DEV
	_SVC_EXTERN(tk_oref_dev)
#endif
#ifdef USE_FUNC_TK_LST_DEV
	_SVC_EXTERN(tk_lst_dev)
#endif
#ifdef USE_FUNC_TK_EVT_DEV
	_SVC_EXTERN(tk_evt_dev)
#endif
#ifdef USE_FUNC_TK_DEF_DEV
	_SVC_EXTERN(tk_def_dev)
#endif
#ifdef USE_FUNC_TK_REF_IDV
	_SVC_EXTERN(tk_ref_idv)
#endif
