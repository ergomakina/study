/*
 *	micro T-Kernel system call branch table (Debugger Support)
 *
 *	   created from /usr/local/te/include/tk/dbgspt.h
 */

#if defined(__GNUC__)
#define _TDSC_EXTERN(name)
#elif defined(__IASMARM__) || defined(__CC_ARM)
#define _TDSC_EXTERN(name)	EXTERN name##_impl
#endif

#ifdef USE_FUNC_TD_LST_TSK
	_TDSC_EXTERN(td_lst_tsk)
#endif
#ifdef USE_FUNC_TD_LST_SEM
	_TDSC_EXTERN(td_lst_sem)
#endif
#ifdef USE_FUNC_TD_LST_FLG
	_TDSC_EXTERN(td_lst_flg)
#endif
#ifdef USE_FUNC_TD_LST_MBX
	_TDSC_EXTERN(td_lst_mbx)
#endif
#ifdef USE_FUNC_TD_LST_MTX
	_TDSC_EXTERN(td_lst_mtx)
#endif
#ifdef USE_FUNC_TD_LST_MBF
	_TDSC_EXTERN(td_lst_mbf)
#endif
#ifdef USE_FUNC_TD_LST_POR
	_TDSC_EXTERN(td_lst_por)
#endif
#ifdef USE_FUNC_TD_LST_MPF
	_TDSC_EXTERN(td_lst_mpf)
#endif
#ifdef USE_FUNC_TD_LST_MPL
	_TDSC_EXTERN(td_lst_mpl)
#endif
#ifdef USE_FUNC_TD_LST_CYC
	_TDSC_EXTERN(td_lst_cyc)
#endif
#ifdef USE_FUNC_TD_LST_ALM
	_TDSC_EXTERN(td_lst_alm)
#endif
#ifdef USE_FUNC_TD_LST_SSY
	_TDSC_EXTERN(td_lst_ssy)
#endif
#ifdef USE_FUNC_TD_REF_SEM
	_TDSC_EXTERN(td_ref_sem)
#endif
#ifdef USE_FUNC_TD_REF_FLG
	_TDSC_EXTERN(td_ref_flg)
#endif
#ifdef USE_FUNC_TD_REF_MBX
	_TDSC_EXTERN(td_ref_mbx)
#endif
#ifdef USE_FUNC_TD_REF_MTX
	_TDSC_EXTERN(td_ref_mtx)
#endif
#ifdef USE_FUNC_TD_REF_MBF
	_TDSC_EXTERN(td_ref_mbf)
#endif
#ifdef USE_FUNC_TD_REF_POR
	_TDSC_EXTERN(td_ref_por)
#endif
#ifdef USE_FUNC_TD_REF_MPF
	_TDSC_EXTERN(td_ref_mpf)
#endif
#ifdef USE_FUNC_TD_REF_MPL
	_TDSC_EXTERN(td_ref_mpl)
#endif
#ifdef USE_FUNC_TD_REF_CYC
	_TDSC_EXTERN(td_ref_cyc)
#endif
#ifdef USE_FUNC_TD_REF_ALM
	_TDSC_EXTERN(td_ref_alm)
#endif
#ifdef USE_FUNC_TD_REF_SSY
	_TDSC_EXTERN(td_ref_ssy)
#endif
#ifdef USE_FUNC_TD_REF_TSK
	_TDSC_EXTERN(td_ref_tsk)
#endif
#ifdef USE_FUNC_TD_INF_TSK
	_TDSC_EXTERN(td_inf_tsk)
#endif
#ifdef USE_FUNC_TD_GET_REG
	_TDSC_EXTERN(td_get_reg)
#endif
#ifdef USE_FUNC_TD_SET_REG
	_TDSC_EXTERN(td_set_reg)
#endif
#ifdef USE_FUNC_TD_REF_SYS
	_TDSC_EXTERN(td_ref_sys)
#endif
#ifdef USE_FUNC_TD_GET_TIM
	_TDSC_EXTERN(td_get_tim)
#endif
#ifdef USE_FUNC_TD_GET_OTM
	_TDSC_EXTERN(td_get_otm)
#endif
#ifdef USE_FUNC_TD_RDY_QUE
	_TDSC_EXTERN(td_rdy_que)
#endif
#ifdef USE_FUNC_TD_SEM_QUE
	_TDSC_EXTERN(td_sem_que)
#endif
#ifdef USE_FUNC_TD_FLG_QUE
	_TDSC_EXTERN(td_flg_que)
#endif
#ifdef USE_FUNC_TD_MBX_QUE
	_TDSC_EXTERN(td_mbx_que)
#endif
#ifdef USE_FUNC_TD_MTX_QUE
	_TDSC_EXTERN(td_mtx_que)
#endif
#ifdef USE_FUNC_TD_SMBF_QUE
	_TDSC_EXTERN(td_smbf_que)
#endif
#ifdef USE_FUNC_TD_RMBF_QUE
	_TDSC_EXTERN(td_rmbf_que)
#endif
#ifdef USE_FUNC_TD_CAL_QUE
	_TDSC_EXTERN(td_cal_que)
#endif
#ifdef USE_FUNC_TD_ACP_QUE
	_TDSC_EXTERN(td_acp_que)
#endif
#ifdef USE_FUNC_TD_MPF_QUE
	_TDSC_EXTERN(td_mpf_que)
#endif
#ifdef USE_FUNC_TD_MPL_QUE
	_TDSC_EXTERN(td_mpl_que)
#endif

#if	USE_HOOK_TRACE
#ifdef USE_FUNC_TD_HOK_SVC
	_TDSC_EXTERN(td_hok_svc)
#endif
#ifdef USE_FUNC_TD_HOK_DSP
	_TDSC_EXTERN(td_hok_dsp)
#endif
#ifdef USE_FUNC_TD_HOK_INT
	_TDSC_EXTERN(td_hok_int)
#endif
#endif
	
#ifdef USE_FUNC_TD_REF_DSNAME
	_TDSC_EXTERN(td_ref_dsname)
#endif
#ifdef USE_FUNC_TD_SET_DSNAME
	_TDSC_EXTERN(td_set_dsname)
#endif
